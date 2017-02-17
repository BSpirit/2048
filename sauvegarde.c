#include "couleurs_terminal.h"
#include "grille.h"
#include "sauvegarde.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int sauvegardeJeu(jeu *p){
    FILE *f;
	char nomF[20];//Stock le nom du fichier à sauvegarder
	char saisie;

    //On demande à l'utilisateur de choisir un slot de sauvegarde
	printf("Veuillez choisir un slot de sauvegarde [a/b/c] \n");
	do{
		scanf("%c", &saisie);
	}while(saisie!= 'a' && saisie!='b' && saisie!='c' && saisie!='A' && saisie!='B' && saisie!='C');

    //Assigne un fichier à nomF en fonction du slot choisi
	if(saisie=='a' || saisie=='A')
			strcpy(nomF, "./Saves/SaveA.txt");
	if(saisie=='b'|| saisie=='B')
			strcpy(nomF, "./Saves/SaveB.txt");
	if(saisie=='c' || saisie=='C')
			strcpy(nomF, "./Saves/SaveC.txt");

    //On test l'existance du fichier, s'il existe on demande à l'utilisateur s'il souhaite l'écraser
    f = fopen(nomF, "rt");
	if(!(f==NULL)){
		printf("Une sauvegarde existe déjà, voulez vous l'écraser ?[o/n]\n");
		do{
			scanf("%c", &saisie);
		}while(saisie!='o' && saisie!='n' && saisie!='O' && saisie!='N');
        //S'il ne souhaite pas l'écraser, on ferme le fichier et retourne 0
		if(saisie=='n' || saisie=='N'){
			fclose(f);
			return 0;
		}
	}

    //Sinon on sauvegarde
	f = fopen(nomF, "wt");

    if(f==NULL){
        printf("Erreur de fopen \n");
        return 0;
    }

    fprintf(f, "%d ", p->n);
    fprintf(f, "%d ", p->valMax);
    fprintf(f, "%d ", p->nbCasesLibres);

    int i;
    for(i=0; i<p->n*p->n; i++)
        fprintf(f, "%d ", p->grille[i]);

    fclose(f);

    //Retourne 1 si sauvegarde effectuée
    return 1;
}


int chargementJeu(jeu *p){
    FILE *f;
	char nomF[20];
	char saisie;

    //On demande à l'utilisateur quelle sauvegarde il souhaite charger
	printf("Veuillez choisir un slot de sauvegarde à charger [a/b/c] \n");
	do{
		scanf("%c", &saisie);
	}while(saisie!= 'a' && saisie!='b' && saisie!='c' && saisie!='A' && saisie!='B' && saisie!='C');

    //Assigne un fichier à nomF en fonction du slot choisi
	if(saisie=='a' || saisie=='A')
			strcpy(nomF, "./Saves/SaveA.txt");
	if(saisie=='b'|| saisie=='B')
			strcpy(nomF, "./Saves/SaveB.txt");
	if(saisie=='c' || saisie=='C')
			strcpy(nomF, "./Saves/SaveC.txt");

    //On test l'existance du fichier, s'il n'existe pas on retourne 0
	f = fopen(nomF, "rt");
    if(f==NULL)
        return 0;

    //Sinon on charge la sauvegarde
    fscanf(f, "%d ", &p->n);
    fscanf(f, "%d ", &p->valMax);
    fscanf(f, "%d ", &p->nbCasesLibres);

    //On refait une allocation de la grille, dont la taille peut avoir changée
    p->grille = (int*)malloc((p->n*p->n)*sizeof(int));

    int i;
    for(i=0; i<p->n*p->n; i++)
        fscanf(f, "%d ", &p->grille[i]);

    fclose(f);

    //Retourne 1 si chargement effectué
    return 1;
}

int sauvegardeScore(int score){
    FILE *f;
    char nom[20];//Pour stocker le nom du jouer

    f = fopen("score.txt", "at");
    if(f==NULL)
        return 0;

    //L'utilisateur peut saisir son nom ou annuler l'enregistrement de son score 
    printf("Nom du joueur ? [0 pour annuler] \n");
    scanf("%s", nom);
    if(nom[0]=='0')
        return 0;

    //Sauvegarde de son score
    fprintf(f, "%s : %d\n", nom, score);

    fclose(f);

    //Retourne 1 si sauvegarde effectuée
    return 1;
}

int chargementScore(){
    FILE *f;
    char nom[20];//Pour afficher le nom
    int score;//Pour afficher le score

    f = fopen("score.txt", "rt");
    if(f==NULL)
        return 0;

    //On parcourt le fichier et affiche les noms et scores des joueurs
    printf("Scores : \n");
    while(!feof(f)){
        fscanf(f, "%s : %d\n", nom, &score);
        printf("%s : %d\n", nom, score);    
    }

    printf("\n");

    fclose(f);

    //Retourne 1 si score chargé
    return 1;
}


int menu(){
    int choix;

    printf("\n");
    printf("1 - Créer nouvelle partie \n");
    printf("2 - Jouer \n");
    printf("3 - Sauvegarder \n");
    printf("4 - Charger \n");
    printf("5 - Afficher scores \n");
    printf("6 - Quitter \n");
    printf("\n");

    do{
        scanf("%d", &choix);
    }while(choix!=1 && choix!=2 && choix!=3 && choix!=4 && choix!=5 && choix!=6);

    return choix;
}


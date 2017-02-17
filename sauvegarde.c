#include "couleurs_terminal.h"
#include "grille.h"
#include "sauvegarde.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int sauvegardeJeu(jeu *p){
    FILE *f;
	char nomF[20];
	char saisie;

		printf("Veuillez choisir un slot de sauvegarde [a/b/c] \n");
	do{
		scanf("%c", &saisie);
	}while(saisie!= 'a' && saisie!='b' && saisie!='c' && saisie!='A' && saisie!='B' && saisie!='C');

	if(saisie<='A' && saisie>='Z')
		saisie = saisie -'A' + 'a';

	if(saisie=='a')
			strcpy(nomF, "./Saves/SaveA.txt");
	if(saisie=='b')
			strcpy(nomF, "./Saves/SaveB.txt");
	if(saisie=='c')
			strcpy(nomF, "./Saves/SaveC.txt");

    f = fopen(nomF, "rt");
	if(!(f==NULL)){
		printf("Une sauvegarde existe déjà, voulez vous l'écraser ?[o/n]\n");
		do{
			scanf("%c", &saisie);
		}while(saisie!='o' && saisie!='n' && saisie!='O' && saisie!='N');
		if(saisie=='n' || saisie=='N'){
			fclose(f);
			return 0;
		}
	}

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

    return 1;
}


int chargementJeu(jeu *p){
    FILE *f;
	char nomF[10];
	char saisie;


		printf("Veuillez choisir un slot de sauvegarde à charger [a/b/c] \n");
	do{
		scanf("%c", &saisie);
	}while(saisie!= 'a' && saisie!='b' && saisie!='c' && saisie!='A' && saisie!='B' && saisie!='C');

	if(saisie<='A' && saisie>='Z')
		saisie = saisie -'A' + 'a';

	if(saisie=='a')
			strcpy(nomF, "./Saves/SaveA.txt");
	if(saisie=='b')
			strcpy(nomF, "./Saves/SaveB.txt");
	if(saisie=='c')
			strcpy(nomF, "./Saves/SaveC.txt");


	f = fopen(nomF, "rt");

    if(f==NULL){
        printf("La sauvegarde n'existe pas \n");
        return 0;
    }

    fscanf(f, "%d ", &p->n);
    fscanf(f, "%d ", &p->valMax);
    fscanf(f, "%d ", &p->nbCasesLibres);

    p->grille = (int*)malloc((p->n*p->n)*sizeof(int));
    
    int i;
    for(i=0; i<p->n*p->n; i++)
        fscanf(f, "%d ", &p->grille[i]);

    fclose(f);

    return 1;
}

int sauvegardeScore(int score){
    FILE *f;
    char nom[20];
    f = fopen("score.txt", "at");

    if(f==NULL)
        return 0;

    printf("Nom du joueur ? [0 pour annuler] \n");
    scanf("%s", nom);

    if(nom[0]=='0')
        return 0;

    fprintf(f, "%s : %d\n", nom, score);

    fclose(f);

    return 1;
}

int chargementScore(){
    FILE *f;
    char nom[20];
    int score;
    f = fopen("score.txt", "rt");

    if(f==NULL)
        return 0;

    printf("Scores : \n");
    while(!feof(f)){
        fscanf(f, "%s : %d\n", nom, &score);
        printf("%s : %d\n", nom, score);    
    }

    printf("\n");

    fclose(f);

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


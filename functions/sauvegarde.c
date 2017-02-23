/*******************************************************
Nom           : sauvegarde.c
Auteur        : Tony Clonier
Version       : V1
Date          : 15/02/2017
Informations  : Contient la définition des fonctions
                - sauvegardeJeu
                - chargementJeu
                - sauvegardeScore
                - chargementScore
                - menu
********************************************************/

#include "./headers/couleurs_terminal.h"
#include "./headers/grille.h"
#include "./headers/sauvegarde.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int sauvegardeJeu(jeu *p){
    FILE *f;
	char nomF[80];//Stock le nom du fichier à sauvegarder
	char saisie;
    if(p->valMax != 418){
        //On demande à l'utilisateur de choisir un slot de sauvegarde
        printf("Veuillez choisir un slot de sauvegarde [1/2/3] [0 pour annuler] \n");
        do{
            scanf("%c", &saisie);
        }while(saisie!= '1' && saisie!='2' && saisie!='3' && saisie!='0');

        if(saisie=='0')
            return 0;

        //Assigne un fichier à nomF en fonction du slot choisi
        if(saisie=='1')
                strcpy(nomF, "./Saves/Save1.bin");
        if(saisie=='2')
                strcpy(nomF, "./Saves/Save2.bin");
        if(saisie=='3')
                strcpy(nomF, "./Saves/Save3.bin");
    }else{
        strcpy(nomF ,"./Saves/test_Iam_a_teampot.bin");
    }
    //On test l'existance du fichier, s'il existe on demande à l'utilisateur s'il souhaite l'écraser
    f = fopen(nomF, "r");
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
	f = fopen(nomF, "wb");

    if(f==NULL){
        printf("Erreur de fopen \n");
        return 0;
    }

	fwrite( &p->n , sizeof(int) , 1 , f);
	fwrite( &p->valMax , sizeof(int) , 1 , f);
	fwrite( &p->nbCasesLibres , sizeof(int) , 1 , f);
    fwrite( &p->score, sizeof(int), 1, f);
	fwrite( p->grille, sizeof(int), p->n*p->n, f);

    fclose(f);

    //Retourne 1 si sauvegarde effectuée
    return 1;
}


int chargementJeu(jeu *p){
    FILE *f;
	char nomF[80];
	char saisie;
    if(p->valMax != 418){
    //On demande à l'utilisateur quelle sauvegarde il souhaite charger
	printf("Veuillez choisir un slot de sauvegarde à charger [1/2/3] [0 pour annuler] \n");
	do{
		scanf("%c", &saisie);
	}while(saisie!= '1' && saisie!='2' && saisie!='3' && saisie!='0');

    if(saisie=='0')
        return 0;

    //Assigne un fichier à nomF en fonction du slot choisi
	if(saisie=='1')
			strcpy(nomF, "./Saves/Save1.bin");
	if(saisie=='2')
			strcpy(nomF, "./Saves/Save2.bin");
	if(saisie=='3')
			strcpy(nomF, "./Saves/Save3.bin");
    }else{
        strcpy(nomF, "./Saves/test_Iam_a_teampot.bin");
    }
    //On test l'existance du fichier, s'il n'existe pas on retourne 0
	f = fopen(nomF, "rb");
    if(f==NULL)
        return 0;

    //Sinon on charge la sauvegarde
	fread( &p->n , sizeof(int) , 1 , f);
	fread( &p->valMax , sizeof(int) , 1 , f);
	fread( &p->nbCasesLibres , sizeof(int) , 1 , f);
    fread( &p->score, sizeof(int), 1, f);

    //On refait une allocation de la grille, dont la taille peut avoir changée
    p->grille = (int*)malloc((p->n*p->n)*sizeof(int));
    if(p->grille==NULL){
        printf("Erreur allocation ! \n");
        exit(-1);
    }

	fread(p->grille, sizeof(int), p->n*p->n, f);

    fclose(f);

    //Retourne 1 si chargement effectué
    return 1;
}

int sauvegardeScore(int score){
    FILE *f;
    char nom[20];//Pour stocker le nom du jouer

    f = fopen("./Saves/score.bin", "ab");
    if(f==NULL)
        return 0;

    //L'utilisateur peut saisir son nom ou annuler l'enregistrement de son score 
    printf("Nom du joueur ? [0 pour annuler] \n");
    scanf("%s", nom);
    if(nom[0]=='0')
        return 0;

    //Sauvegarde de son score
    fwrite(nom, sizeof(nom), 1, f);
    fwrite( &score, sizeof(int), 1, f);

    fclose(f);

    //Retourne 1 si sauvegarde effectuée
    return 1;
}

int chargementScore(){
    FILE *f;
    char nom[20];//Pour afficher le nom
    int score;//Pour afficher le score

    f = fopen("./Saves/score.bin", "rb");
    if(f==NULL)
        return 0;

    //On parcourt le fichier et affiche les noms et scores des joueurs
    printf("Scores : \n");
    while(fread( nom, sizeof(nom), 1, f)==1 && fread( &score, sizeof(int), 1, f)==1)
        printf("%s : %d\n", nom, score);    
    

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


#include "couleurs_terminal.h"
#include "grille.h"
#include "sauvegarde.h"
#include <stdio.h>
#include <stdlib.h>

int sauvegarde(jeu *p){
    FILE *f;

    f = fopen("test.dat", "wb");

    if(f==NULL){
        printf("Erreur de fopen \n");
        return 0;
    }

    fwrite(p->grille, sizeof(int), p->n, f);
    fclose(f);

    return 1;
}


int chargement(jeu *p){
    FILE *f;

    f = fopen("test.dat", "rb");

    if(f==NULL){
        printf("Erreur de fopen \n");
        return 0;
    }

    fread(p->grille, sizeof(int), p->n, f);
    fclose(f);

    return 1;
}


int menu(){
    int choix;

    printf("Bienvenue dans le jeu du 2048 : \n");
    printf("1 - Jouer \n");
    printf("2 - Sauvegarder \n");
    printf("3 - Charger \n");
    printf("4 - Quitter \n");
    printf("\n");

    do{
        scanf("%d", &choix);
    }while(choix!=1 && choix!=2 && choix!=3 && choix!=4);

    return choix;
}


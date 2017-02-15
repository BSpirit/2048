#include "couleurs_terminal.h"
#include "grille.h"
#include "sauvegarde.h"
#include <stdio.h>
#include <stdlib.h>

int sauvegarde(jeu *p){
    FILE *f;
    f = fopen("test.txt", "wt");

    if(f==NULL)
        return 0;

    fprintf(f, "%d ", p->n);
    fprintf(f, "%d ", p->valMax);
    fprintf(f, "%d ", p->nbCasesLibres);

    int i;
    for(i=0; i<p->n*p->n; i++)
        fprintf(f, "%d ", p->grille[i]);

    fclose(f);

    return 1;
}


int chargement(jeu *p){
    FILE *f;

    f = fopen("test.txt", "rt");

    if(f==NULL)
        return 0;

    fscanf(f, "%d ", &p->n);
    fscanf(f, "%d ", &p->valMax);
    fscanf(f, "%d ", &p->nbCasesLibres);

    initialiseJeu(p, p->n, p->valMax);

    int i;
    for(i=0; i<p->n*p->n; i++)
        fscanf(f, "%d ", &p->grille[i]);
        
    fclose(f);
    
    return 1;
}


int menu(){
    int choix;

    printf("\n");
    printf("1 - Créer nouvelle partie \n");
    printf("2 - Continuer \n");
    printf("3 - Sauvegarder \n");
    printf("4 - Charger \n");
    printf("5 - Quitter \n");
    printf("\n");

    do{
        scanf("%d", &choix);
    }while(choix!=1 && choix!=2 && choix!=3 && choix!=4 && choix!=5);

    return choix;
}


#include "couleurs_terminal.h"
#include "grille.h"
#include "sauvegarde.h"
#include <stdio.h>
#include <stdlib.h>

int sauvegardeJeu(jeu *p){
    FILE *f;
    f = fopen("test.txt", "wt");

    if(f==NULL)
        return 0;

    fprintf(f, "%d ", p->n);
    fprintf(f, "%d ", p->valMax);
    fprintf(f, "%d ", p->nbCasesLibres);
    fprintf(f, "%d ", p->score);

    int i;
    for(i=0; i<p->n*p->n; i++)
        fprintf(f, "%d ", p->grille[i]);

    fclose(f);

    return 1;
}


int chargementJeu(jeu *p){
    FILE *f;

    f = fopen("test.txt", "rt");

    if(f==NULL)
        return 0;

    fscanf(f, "%d ", &p->n);
    fscanf(f, "%d ", &p->valMax);
    fscanf(f, "%d ", &p->nbCasesLibres);
    fscanf(f, "%d ", &p->score);

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

    printf("Nom du joueur ? \n");
    scanf("%s", nom);

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
    printf("2 - Continuer \n");
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


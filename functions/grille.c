/*******************************************************
Nom           : grille.c
Auteur        : Tony Clonier
Version       : V1
Date          : 15/02/2017
Informations  : Contient la définition des fonctions
                - initialiseJeu
				- libereMemoire
				- indiceValide
				- getVal
				- caseVide
				- setVal
				- choixCouleur
				- affichage
********************************************************/

#include "./headers/couleurs_terminal.h"
#include "./headers/grille.h"
#include <stdio.h>
#include <stdlib.h>
#include "./headers/partie.h"

void initialiseJeu(jeu *p, int n, int valMax){
	//Initialisation des variables
	p->n = n;
	p->nbCasesLibres = n*n; 
	p->valMax = valMax;
	p->score = 0;

	//allocation dynamique de la taille de la grille
	p->grille = (int*) malloc(p->nbCasesLibres*sizeof(int));
	if(p->grille==NULL){
		printf("Erreur allocation ! \n");
		exit(-1);
	}

	//Initialisation des cases de la grille à 0
	int i;
	for(i=0;i<p->nbCasesLibres;i++)
		p->grille[i] = 0;
}


void libereMemoire(jeu *p){
	free(p->grille);
}


int indiceValide(jeu *p, int i, int j){
	//les indices i et j doivent être compris entre 0 (inclus) et p->n (exclus)
	return (i>=0 && i < p->n && j>=0 && j < p->n);
}


int getVal(jeu *p, int ligne, int colonne){
	if(indiceValide(p, ligne, colonne))
		return p->grille[p->n*ligne+colonne];
	
	return -1;
}


int caseVide(jeu *p, int i, int j){
	if(getVal(p, i, j)==0)
		return 1;

	return 0;
}


int setVal(jeu *p, int ligne, int colonne, int val){
	// On verifie que l'indice est valide
	if(indiceValide(p, ligne, colonne)){
		// si la valeur de la case est identique à val, on ne fait rien
		if(getVal(p, ligne, colonne) == val)
			return 0;
		//si une ajoute une valeur à une case vide, on décrémente le nombre de cases vides
		if(caseVide(p, ligne, colonne) && val > 0)
			p->nbCasesLibres--;
		//si on vide une case, on incrémente le nombre de cases vides
		if(!caseVide(p, ligne, colonne) && val == 0 )
			p->nbCasesLibres++;
		//modification de la valeur de la case
		p->grille[p->n*ligne+colonne] = val;
		return 1;
	}

	return 0;
}


COULEUR_TERMINAL choixCouleur(int n){
	COULEUR_TERMINAL couleur;

	switch(n){
		case 0 : couleur = BLACK;
			break;
		case 2 : couleur = CYAN;
			break;
		case 4 : couleur = GREEN;
			break;
		case 8 : couleur = YELLOW;
			break;
		case 16 : couleur = BLUE;
			break;
		case 32 : couleur = RED;
			break;
		case 64 : couleur = CYAN;
			break;
		case 128 : couleur = GREEN;
			break;
		case 256 : couleur = YELLOW;
			break;
		case 512 : couleur = BLUE;
			break;
		case 1024 : couleur = RED;
			break;
		case 2048 : couleur = WHITE;
			break;
		default : couleur = CYAN;
	}
	return couleur;
}


void affichage(jeu * p){
	clear_terminal();
	int val;

	//boucles imbriquées pour parcourir la grille
	int i;
	for(i=0;i<p->n;i++){
		//Retour chariot à la fin d'une ligne
		printf("\n");
		int j;
		for(j=0; j<p->n; j++){
			val = getVal(p, i, j);
			//Si la case est vide on l'affiche intégralement en noir
			if(val == 0)
				color_printf(BLACK, BLACK, "       ");
			//sinon on appelle la fonction choixCouleur pour lui assigner une couleur
			else
				color_printf(WHITE, choixCouleur(val), " %5d ", val);
		}
	}
	
	printf("\n");
	printf("Score : %d\n\n", p->score);
	/*printf("ValMax : %d\n\n", p->valMax);
	printf("N : %d\n\n", p->n);
	printf("nbCasesLibres : %d\n\n", p->nbCasesLibres);*/

	if(gagne(p))
		printf("Vous avez gagné ! \n\n");
	else if(perdu(p))
		printf("Vous avez perdu ! \n\n");
}

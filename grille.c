#include "grille.h"


void initialiseJeu(jeu *p, int n, int valMax){
	//Initialisation des variables
	p->n = n;
	p->nbCasesLibres = n*n; 
	p->valMax = valMax;

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
	if(indiceValide(p, ligne, colonne)){
		if(getVal(p, ligne, colonne) == val)
			return 0;
		if(caseVide(p, ligne, colonne) && val > 0)
			p->nbCasesLibres--;
		if(!caseVide(p, ligne, colonne) && val == 0 )
			p->nbCasesLibres++;
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

	int i;
	for(i=0;i<p->n;i++){
		printf("\n");
		int j;
		for(j=0; j<p->n; j++){
			val = getVal(p, i, j);
			if(val == 0)
				color_printf(BLACK, BLACK, "       ");
			else
				color_printf(WHITE, choixCouleur(val), " %5d ", val);
		}
	}
	printf("\n");
	printf("Valeur à atteindre : %d\n", p->valMax);
	printf("Nombre de cases libres : %d\n", p->nbCasesLibres);
}

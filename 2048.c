#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int n; //taille de la grille
	int valMax; // valeur à atteindre pour gagner
	int nbCasesLibres; //nbre de cases libres sur la grille
	int *grille;
}jeu;

/*!
	* Alloue la grille de la variable jeu passée par adresse
	* Initialise les cases de la grille avec des cases vides  (valeurs nulles)
	* Initialise les champs n et valmax avec les valeurs passées en paramètre
	*
	* \param p : pointeur sur une grille de 2018
	* \param n : taille de la grille
	* \param valMax : valeur à atteindre pour gagner
	*/

void initialiseJeu(jeu *p, int n, int valMax){

	p->grille = (int*) malloc(n*n*sizeof(int));
	if(p->grille==NULL){
		printf("Erreur allocation ! \n");
		exit(-1);
	}

	int i;
	for(i=0;i<n;i++)
		p->grille[i] = 0;

	p->n = n;
	p->valMax = valMax;
}

/*!
	* Libère la mémoire allouée pour la grille de jeu passée par adresse
	*
	* \param p : pointeur sur une partie de 2048
	*/

void libereMemoire(jeu *p){

	free(p->grille);
}

/*!
	* Fonction retournant 1 si la case (i,j) existe, 0 sinon
	* 
	* \param p : pointeur sur une partie de jeu 2048
	* \param i : indice de ligne
	* \param j : indice de colonne
	*/

int indiceValide(jeu *p, int i, int j){

	return(i>=0 && i < p->n && j>=0 && j < p->n);
}

int main(){

	jeu p;

	initialiseJeu(&p, 3, 2048 );
	printf("%d", indiceValide(&p, 2, 2));
	libereMemoire(&p);

	return 0;
}

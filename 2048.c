#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int n; //taille de la grille
	int valMax; // valeur à atteindre pour gagner
	int nbCasesLibres; //nbre de cases libres sur la grille
	int *grille;
}jeu;

/*! * void initialiseJeu(jeu *p, int n, int valMax)
	*
	* Alloue la grille de la variable jeu passée par adresse
	* Initialise les cases de la grille avec des cases vides  (valeurs nulles)
	* Initialise les champs n et valmax avec les valeurs passées en paramètre
	*
	* \param p : pointeur sur une grille de 2018
	* \param n : taille de la grille
	* \param valMax : valeur à atteindre pour gagner
	*/

void initialiseJeu(jeu *p, int n, int valMax){

	p->n = n*n;
	p->valMax = valMax;
	//Initialiser nbCasesLibres ?

	p->grille = (int*) malloc(p->n*sizeof(int));
	if(p->grille==NULL){
		printf("Erreur allocation ! \n");
		exit(-1);
	}

	int i;
	for(i=0;i<p->n;i++)
		p->grille[i] = 0;
}

/*! * void libereMemoire(jeu *p)
	*
	* Libère la mémoire allouée pour la grille de jeu passée par adresse
	*
	* \param p : pointeur sur une partie de 2048
	*/

void libereMemoire(jeu *p){

	free(p->grille);
}

/*! * int indiceValide(jeu *p, int i, int j)
	*
	* Fonction retournant 1 si la case (i,j) existe, 0 sinon
	*
	* \param p : pointeur sur une partie de jeu 2048
	* \param i : entier correspondant au numéro de "ligne"
	* \param j : entier correspondant au numéro de "colonne"
	*/

int indiceValide(jeu *p, int i, int j){

	return(i>=0 && i < p->n && j>=0 && j < p->n);
}

/*! * int getVal(jeu *p, int ligne, int colonne)
	*
	* Fonction retournant la valeur de la case (ligne, colonne) de la partie
	* ou -1 si la case n'existe pas
	* \param p : pointeur sur une partie de jeu 2048
	* \param ligne : entier correspondant au numéro de ligne
	* \param colonne : entier correspondant au numéro de colonne
	*/

int getVal(jeu *p, int ligne, int colonne){

	if(indiceValide(&p, ligne, colonne))
		return p->grille[p->n*ligne+colonne]; // à corriger 
	else
		return -1;
}

int main(){

	jeu p;

	initialiseJeu(&p, 3, 2048 );
	printf("%d", indiceValide(&p, 2, 2));
	libereMemoire(&p);

	return 0;
}

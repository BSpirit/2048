#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int n; //taille de la grille (n*n)
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

	p->n = n;
	p->nbCasesLibres = n*n; //La grille possède n*n cases
	p->valMax = valMax;

	p->grille = (int*) malloc(p->nbCasesLibres*sizeof(int));
	if(p->grille==NULL){
		printf("Erreur allocation ! \n");
		exit(-1);
	}

	int i;
	for(i=0;i<p->nbCasesLibres;i++)
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

/*! * int caseVide(jeu *p, int i, int j)
	*
	* Retourne 1 si la case (i,j) est vide
	* Retourne 0 sinon
	*
 	* \param p : pointeur sur la partie en cours
	* \param i : entier correspondant au numéro de ligne
	* \param j : entier correspondant au numéro de colonne
	*/
int caseVide(jeu *p, int i, int j){
	if(indiceValide(p, i, j)){
		if(getVal(p, i, j)==0)
			return 1;
	}

	return 0;
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

	if(indiceValide(p, ligne, colonne))
		return p->grille[p->n*ligne+colonne];
	else
		return -1;
}

/*! * void setVal(jeu *p, int ligne, int colonne, int val)
 	*
 	* Fonction modifiant la valeur de la case (ligne, colonne) de la partie p
 	* avec la valeur val
 	*
 	* \param p : pointeur sur la partie en cours
	* \param ligne : entier correspondant au numéro de ligne
	* \param colonne : entier correspondant au numéro de colonne
	* \param val : entier à mettre dans la case (i,j) (si elle existe)
	*/
void setVal(jeu *p, int ligne, int colonne, int val){


	if(indiceValide(p, ligne, colonne)){
		if(caseVide(p, i, j))
			p->nbCasesLibres-=1;
		p->grille[p->n*ligne+colonne] = val;
	}
}

/*! * void affichage(jeu * p)
	* Fonction de affichant la grille à l'écran.
	*
	* \param p : pointeur sur la partie que l'on souhaite afficher
	*
	*/
void affichage(jeu * p){

	int i;
	for(i=0;i<p->n;i++){
		printf("\n");
		int j;
		for(j=0; j<p->n; j++)
			printf("%d ", getVal(p, i, j));
	}
}

/*! * int gagne(jeu *p)
	* Retoune 1 si la partie est gagnée
	* retourne 0 sinon
	*
 	* \param p : pointeur sur la partie en cours
 	*/
int gagne(jeu *p){

	int test = 0;
	int i = 0;
	int j = 0;

	while(i<p->n && test==0){
		j = 0;
		while(j<p->n && test==0){
			if(getVal(p, i, j)==p->valMax)
				test = 1;
			j++;
		}
		i++;
	}

	return test;
}

/*! * int perdu(jeu *p)
	* Retoune 1 si la partie est perdue
	* retourne 0 sinon
	*
 	* \param p : pointeur sur la partie en cours
 	*/
int perdu(jeu *p){

	if(p->nbCasesLibres>0)
		return 0;

	int test = 1;
	int i = 0;
	int j = 0;

	while(i<p->n&& test==1){
		j = 0;
		while(j<p->n&& test==1){
			if(i==p->n-1 && j==p->n-1){
				break;
			}else if(i==p->n-1){
				if(getVal(p, i, j) == getVal(p, i, j+1))
					test = 0;
			}else if(j==p->n-1){
				if(getVal(p, i, j) == getVal(p, i+1, j))
					test = 0;
				}
			else {
				if(getVal(p, i, j)==getVal(p, i+1, j) || getVal(p, i, j)==getVal(p, i, j+1))
					test = 0;
			}
			j++;
		}
		i++;
	}

	return test;
}

int main(){

	jeu p;

	initialiseJeu(&p, 3, 2048 );
	setVal(&p, 0, 0, 2046);
	setVal(&p, 0, 1, 2045);
	setVal(&p, 0, 2, 512);
	setVal(&p, 1, 0, 1024);
	setVal(&p, 1, 1, 512);
	setVal(&p, 1, 2, 52);
	setVal(&p, 2, 0, 512);
 	setVal(&p, 2, 1, 52);
	setVal(&p, 2, 2, 512);

	affichage(&p);
	printf("%d \n", perdu(&p));
	libereMemoire(&p);

	return 0;
}

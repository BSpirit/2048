#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int n; //taille de la grille = n*n 
	int valMax; // valeur à atteindre pour gagner
	int nbCasesLibres; //nbre de cases libres sur la grille
	int *grille;
}jeu;

/*! * void initialiseJeu(jeu *p, int n, int valMax)
	*
	* Initialise les champs n et valmax avec les valeurs passées en paramètre, initialise nbCasesLibres
	* Alloue la grille de la variable jeu passée par adresse
	* Initialise les cases de la grille avec des cases vides  (valeurs nulles)
	*
	* \param p : pointeur sur une grille de 2018
	* \param n : taille de la grille
	* \param valMax : valeur à atteindre pour gagner
	*/
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
	return (i>=0 && i < p->n && j>=0 && j < p->n);
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
	
	return -1;
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
	if(getVal(p, i, j)==0)
		return 1;

	return 0;
}

/*! * int setVal(jeu *p, int ligne, int colonne, int val)
 	*
 	* Fonction modifiant la valeur de la case (ligne, colonne) de la partie p
 	* avec la valeur val
	* Retourne 1 si une valeur a été assignée à une case existante
	* Retourne 0 sinon
 	*
 	* \param p : pointeur sur la partie en cours
	* \param ligne : entier correspondant au numéro de ligne
	* \param colonne : entier correspondant au numéro de colonne
	* \param val : entier à mettre dans la case (i,j) (si elle existe)
	*/
int setVal(jeu *p, int ligne, int colonne, int val){
	if(indiceValide(p, ligne, colonne)){
		p->grille[p->n*ligne+colonne] = val;
		return 1;
	}

	return 0;
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
	int flag = 0;
	int i = 0;
	int j = 0;

	while(i<p->n && flag==0){
		j = 0;
		while(j<p->n && flag==0){
			if(getVal(p, i, j)==p->valMax)
				test = 1;
			j++;
		}
		i++;
	}//sortie : grille entièrement parcourue et/ou une case de la grille a pour valeur valMax (flag==1)

	return flag;
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

/*! * int finPartie(jeu *p)
	* Retoune 1 si la partie est terminée
	* retourne 0 sinon
	*
 	* \param p : pointeur sur la partie en cours
 	*/
int finPartie(jeu *p){
	return perdu(p) || gagne(p);
}

/*! * int mouvementLigne(jeu *p, int ligne, int direction)
	* Effectue les mouvements (à gauche et à droite) des cases d'une ligne.
	* Renvoie 1 si l'on a déplacé au moins une case, 0 sinon
	*
 	* \param p : pointeur sur la partie en cours
	* \param ligne : indice de ligne
	* \param direction : 1 pour déplacement vers la gauche, -1 pour déplacement vers la droite
 	*/
int mouvementLigne(jeu *p, int ligne, int direction){
	int colonne;
	int i;
	int nbrZero = 0;
	int compteur=0;

	for(colonne=0 ; colonne<p->n; colonne++){
		if(getVal(p, ligne, colonne)==0)
			nbrZero++;
	}

	if(direction == 1){
		if(nbrZero!=0){
			for(i=0 ; i<nbrZero; i++){
				for(colonne=0 ; colonne<p->n-1; colonne++){
					if(getVal(p, ligne, colonne) == 0 && getVal(p, ligne, colonne+1) != 0 ){
						setVal(p, ligne, colonne, getVal(p, ligne, colonne+1));
						setVal(p, ligne, colonne+1, 0);
						compteur++;
					}
				}
			}
		}
		for(colonne=0 ; colonne<p->n-1; colonne++){
			if(getVal(p, ligne, colonne) != 0 && getVal(p, ligne, colonne) == getVal(p, ligne, colonne+1)){
				setVal(p, ligne, colonne, 2*getVal(p, ligne, colonne));
				for(i=colonne+1; i<p->n-1; i++)
					setVal(p, ligne, i, getVal(p, ligne, i+1));
				compteur++;
			}
		}
	}

	if(direction == -1){
		if(nbrZero!=0){
			for(i=0 ; i<nbrZero; i++){
				for(colonne=p->n-1 ; colonne>0; colonne--){
					if(getVal(p, ligne, colonne) == 0 && getVal(p, ligne, colonne-1) != 0 ){
						setVal(p, ligne, colonne, getVal(p, ligne, colonne-1));
						setVal(p, ligne, colonne-1, 0);
						compteur++;
					}
				}
			}
		}
		for(colonne=p->n-1 ; colonne>0; colonne--){
			if(getVal(p, ligne, colonne) != 0 && getVal(p, ligne, colonne) == getVal(p, ligne, colonne-1)){
				setVal(p, ligne, colonne, 2*getVal(p, ligne, colonne));
				for(i=colonne-1; i>0; i--)
					setVal(p, ligne, i, getVal(p, ligne, i-1));
				compteur++;
			}
		}
	}

	if(compteur>0)
		return 1;

	return 0;
}

int main(){

	jeu p;

	initialiseJeu(&p, 6, 2048 );
	setVal(&p, 5, 6, 128);
	setVal(&p, 5, 5, 64);
	setVal(&p, 5, 4, 16);
	setVal(&p, 5, 3, 16);
	printf("%d \n", getVal(&p, 5, 5));
	affichage(&p);
	printf("%d\n", mouvementLigne(&p,5, 1));
	affichage(&p);

	libereMemoire(&p);

	return 0;
}

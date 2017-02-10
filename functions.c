
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Définition de la structure jeu
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
		if(getVal(p, ligne, colonne) == val)
			return 0;
		if(getVal(p, ligne, colonne) == 0 && val > 0)
			p->nbCasesLibres--;
		if(getVal(p, ligne, colonne) > 0 && val == 0)
			p->nbCasesLibres++;
		
		p->grille[p->n*ligne+colonne] = val;
		return 1;
	}

	return 0;
}

/*! * void ajouteValAlea(jeu *p)
	*
	* Ajoute une valeur (2 ou 4 choisi aléatoirement) sur une case vide
	* (elle aussi choisie aléatoirement)
	*
	* \param p : pointeur sur la partie en cours
	*/
void ajouteValAlea(jeu *p){
	int ligne;
	int colonne;

	do{
		ligne = rand()%p->n;
		colonne = rand()%p->n;
	}while(!caseVide(p, ligne, colonne));

	if(rand()%2)
		setVal(p, ligne, colonne, 2);
	else
		setVal(p, ligne, colonne, 4);
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
	int i = 0;// indice de ligne
	int j = 0;// indice de colonne

	//boucles imbriquées pour parcourir la grille
	while(i<p->n && flag==0){
		j = 0;
		while(j<p->n && flag==0){
			if(getVal(p, i, j)==p->valMax)
				flag = 1;
			j++;
		}
		i++;
	}//sortie : grille entièrement parcourue ou une case de la grille a pour valeur valMax (flag==1)

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

	int flag = 1;
	int i = 0; //indice de ligne
	int j = 0;// indice de colonne

	//Boucles imbriquées pour parcourir la grille, on commence à la case (0,0)
	while(i<p->n && flag==1){
		j = 0;
		while(j<p->n && flag==1){
			if(i==p->n-1 && j==p->n-1){ // si on arrive à la dernière case de la grille, c'est qu'on a perdu
				return flag;
			}else if(i==p->n-1){ //si on est placé à la dernière ligne on compare uniquement la case actuelle avec celle à droite
				if(getVal(p, i, j) == getVal(p, i, j+1)) 
					flag = 0;
			}else if(j==p->n-1){//si on est placé à la dernière colonne on compare uniquement la case actuelle avec celle en dessous
				if(getVal(p, i, j) == getVal(p, i+1, j))
					flag = 0;
				}
			else {// sinon on compare la case actuelle avec celle à droite et celle en dessous
				if(getVal(p, i, j)==getVal(p, i+1, j) || getVal(p, i, j)==getVal(p, i, j+1))
					flag = 0;
			}
			j++;
		}
		i++;
	}//sortie : grille entièrement parcourue (flag==1) ou deux cases adjacentes ont les mêmes valeurs (flag==0 i.e. on n'a pas encore perdu)

	return flag;
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
	int colonne; // pour parcourir la ligne
	int flag;
	int compteur = 0;

	// première boucle : tasser toutes les valeurs à droite ou à gauche
	do{ 
		flag = 0;
		for(colonne=0;colonne<p->n;colonne++){
			if(getVal(p, ligne, colonne) == 0 && getVal(p, ligne, colonne+direction) > 0 ){
				setVal(p, ligne, colonne, getVal(p, ligne, colonne+direction));
				setVal(p, ligne, colonne+direction, 0);
				flag = 1;
				compteur++;
			}
		}
	}while(flag==1); //sortie : Plus aucun de mouvements à faire

	//Deuxième boucle : "Fusionner" les valeurs en double + retasser à droite ou à gauche
	int i;
	for(colonne=0;colonne<p->n;colonne++){
		if(getVal(p, ligne, colonne) > 0 && getVal(p, ligne, colonne) == getVal(p, ligne, colonne+direction)){
			setVal(p, ligne, colonne, 2*getVal(p, ligne, colonne));
			for(i=colonne+direction;i<p->n-1 && i>0; i+=direction)
				setVal(p, ligne, i, getVal(p, ligne, i+direction));
			compteur++;
		}
	}

	if(compteur >0)
		return 1;

	return 0;
}

/*! * int mouvementLignes(jeu *p, int direction)
 	*
 	* Effectue les mouvements (à gauche et à droite) des cases sur toutes les lignes
	* Retoune 1 si l'on a déplacé au moins une case
	* Retourne 0 sinon
	* \param p : pointeur sur la partie en cours
	* \param direction : 1 pour déplacement vers la gauche, -1 pour déplacement vers la droite
	*/
int mouvementLignes(jeu *p, int direction){
	int compteur = 0;
	int ligne;
	
	for(ligne=0; ligne<p->n; ligne++)
		compteur = mouvementLigne(p, ligne, direction);

	if(compteur>0)
		return 1;

	return 0;
}

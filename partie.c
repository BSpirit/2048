#include "partie.h"


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
			// si on arrive à la dernière case de la grille, c'est qu'on a perdu
			if(i==p->n-1 && j==p->n-1)
				flag = 1;
			// sinon on compare la case actuelle avec celle à droite et celle en dessous	
			else if(getVal(p, i, j)==getVal(p, i+1, j) || getVal(p, i, j)==getVal(p, i, j+1))
				flag = 0;
			j++;
		}
		i++;
	}//sortie : grille entièrement parcourue (flag==1) ou deux cases adjacentes ont les mêmes valeurs (flag==0 i.e. on n'a pas encore perdu)

	return flag;
}


int finPartie(jeu *p){
	return perdu(p) || gagne(p);
}


int jouer(jeu *p){
	int saisie;
	int deplacement; // Test s'il y a eu un déplacement

	ajouteValAlea(p);
	affichage(p);
	
	do{

		saisie = saisieD();
		if(saisie>=0){
			deplacement = mouvement(p, saisie);
			if(deplacement)
				ajouteValAlea(p);
		affichage(p);
		}
	}while(saisie != -1 && !finPartie(p));

	if(saisie==-1)
		return 0;
	else
		return 1;
}



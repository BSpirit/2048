#include "couleurs_terminal.h"
#include "grille.h"
#include "mouvement.h"
#include "saisieM.h"


int mouvementLigne(jeu *p, int ligne, int direction){
	int colonne; 
	int flag;
	int compteur = 0;

	//Première boucle : tasser toutes les valeurs à droite ou à gauche
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
	}while(flag==1); //sortie : Plus aucun mouvements à faire i.e. (flag==0)

	//Deuxième boucle : "Fusionner" les valeurs en double + retasser si besoin
	int depBoucle;
	if(direction==1)
		depBoucle = 0;
	else
		depBoucle = p->n-1;
	
	for(colonne=depBoucle; colonne<p->n && colonne>=0; colonne+=direction){
		if(getVal(p, ligne, colonne) > 0 && getVal(p, ligne, colonne) == getVal(p, ligne, colonne+direction)){
			p->score+=getVal(p, ligne, colonne);
			setVal(p, ligne, colonne, 2*getVal(p, ligne, colonne));
			setVal(p, ligne, colonne+direction, 0);
			compteur++;
			int i;
			for(i=colonne; i<p->n && i>=0; i+=direction){
				if(getVal(p, ligne, i) == 0 && getVal(p, ligne, i+direction) > 0 ){
					setVal(p, ligne, i, getVal(p, ligne, i+direction));
					setVal(p, ligne, i+direction, 0);
				}
			}
		}
	}

	if(compteur > 0)
		return 1;

	return 0;
}


int mouvementLignes(jeu *p, int direction){
	int compteur = 0;
	int ligne;
	
	for(ligne=0; ligne<p->n; ligne++)
		compteur += mouvementLigne(p, ligne, direction);

	if(compteur>0)
		return 1;

	return 0;
}


int mouvementColonne(jeu *p, int colonne, int direction){
	int ligne; 
	int flag;
	int compteur = 0;

	//Première boucle : tasser toutes les valeurs en haut ou en bas
	do{ 
		flag = 0;
		for(ligne=0;ligne<p->n;ligne++){
			if(getVal(p, ligne, colonne) == 0 && getVal(p, ligne+direction, colonne) > 0 ){
				setVal(p, ligne, colonne, getVal(p, ligne+direction, colonne));
				setVal(p, ligne+direction, colonne, 0);
				flag = 1;
				compteur++;
			}
		}
	}while(flag==1); //sortie : Plus aucun mouvements à faire i.e. (flag==0)

	//Deuxième boucle : "Fusionner" les valeurs en double + retasser si besoin
	int depBoucle;
	if(direction==1)
		depBoucle = 0;
	else
		depBoucle = p->n-1;
	
	for(ligne=depBoucle; ligne<p->n && ligne>=0; ligne+=direction){
		if(getVal(p, ligne, colonne) > 0 && getVal(p, ligne, colonne) == getVal(p, ligne+direction, colonne)){
			p->score+=getVal(p, ligne, colonne);
			setVal(p, ligne, colonne, 2*getVal(p, ligne, colonne));
			setVal(p, ligne+direction, colonne, 0);
			compteur++;
			int i;
			for(i=ligne; i<p->n && i>=0; i+=direction){
				if(getVal(p, i, colonne) == 0 && getVal(p, i+direction, colonne) > 0 ){
					setVal(p, i, colonne, getVal(p, i+direction, colonne));
					setVal(p, i+direction, colonne, 0);
				}
			}
		}
	}

	if(compteur > 0)
		return 1;

	return 0;
}


int mouvementColonnes(jeu *p, int direction){
	int compteur = 0;
	int colonne;
	
	for(colonne=0; colonne<p->n; colonne++)
		compteur += mouvementColonne(p, colonne, direction);

	if(compteur>0)
		return 1;

	return 0;
}


int mouvement(jeu *p, int direction){
	int deplacement=0;

	if(direction==0)
		deplacement = mouvementColonnes(p, -1);
	else if(direction==1)
		deplacement = mouvementLignes(p, -1);
	else if(direction==2)
		deplacement = mouvementColonnes(p, 1);
	else if(direction==3)
		deplacement = mouvementLignes(p, 1);
	else
		return 0;

	return deplacement;
}


int saisieD(){
	debutTerminalSansR();
	Key touche;//Définition d'une touche
	int saisie;

	do{
	touche = lectureFleche(); //On lit une flèche (ou la touche echap)
	}while(touche == NO_KEY);


	if(touche==KEY_ESCAPE)
		saisie = -1;
	if(touche==KEY_DOWN)
		saisie = 0;
	if(touche==KEY_RIGHT)
		saisie = 1;
	if(touche==KEY_UP)
		saisie = 2;
	if(touche==KEY_LEFT)
		saisie = 3;

	finTerminalSansR();

	return saisie;
}



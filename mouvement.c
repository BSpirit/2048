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
			//Si la case actuelle est vide et la case adjacente (sur la ligne) a une valeur positive, on "tasse"
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
		//Si la case actuelle à la même valeur qu'une case adjacente (sur la ligne), on "fusionne" les cases
		if(getVal(p, ligne, colonne) > 0 && getVal(p, ligne, colonne) == getVal(p, ligne, colonne+direction)){
			p->score+=getVal(p, ligne, colonne);
			setVal(p, ligne, colonne, 2*getVal(p, ligne, colonne));
			setVal(p, ligne, colonne+direction, 0);
			compteur++;
			//Boucle interne permettant de retasser si "fusion" de cases
			int i;
			for(i=colonne; i<p->n && i>=0; i+=direction){
				if(getVal(p, ligne, i) == 0 && getVal(p, ligne, i+direction) > 0 ){
					setVal(p, ligne, i, getVal(p, ligne, i+direction));
					setVal(p, ligne, i+direction, 0);
				}
			}
		}
	}

	//Si on a fait un mouvement on retourne 1
	if(compteur > 0)
		return 1;

	return 0;
}


int mouvementLignes(jeu *p, int direction){
	int compteur = 0;
	int ligne;
	
	//Boucle pour parcourir toutes les lignes
	for(ligne=0; ligne<p->n; ligne++)
		compteur += mouvementLigne(p, ligne, direction);

	//Si on a fait un mouvement on retourne 1
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
		for(colonne=0;colonne<p->n;colonne++){
			//Si la case actuelle est vide et la case adjacente (sur la colonne) a une valeur positive, on "tasse"
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
		//Si la case actuelle à la même valeur qu'une case adjacente (sur la colonne), on "fusionne" les cases
		if(getVal(p, ligne, colonne) > 0 && getVal(p, ligne, colonne) == getVal(p, ligne+direction, colonne)){
			p->score+=getVal(p, ligne, colonne);
			setVal(p, ligne, colonne, 2*getVal(p, ligne, colonne));
			setVal(p, ligne+direction, colonne, 0);
			compteur++;
			//Boucle interne permettant de retasser si "fusion" de cases
			int i;
			for(i=ligne; i<p->n && i>=0; i+=direction){
				if(getVal(p, i, colonne) == 0 && getVal(p, i+direction, colonne) > 0 ){
					setVal(p, i, colonne, getVal(p, i+direction, colonne));
					setVal(p, i+direction, colonne, 0);
				}
			}
		}
	}

	//Si on a fait un mouvement on retourne 1
	if(compteur > 0)
		return 1;

	return 0;
}


int mouvementColonnes(jeu *p, int direction){
	int compteur = 0;
	int colonne;
	
	//Boucle permettant de parcourir les colonnes
	for(colonne=0; colonne<p->n; colonne++)
		compteur += mouvementColonne(p, colonne, direction);

	//Si on a fait un mouvement on retourne 1
	if(compteur>0)
		return 1;

	return 0;
}


int mouvement(jeu *p, int direction){
	//Pour tester s'il y a eu déplacement
	int deplacement=0; 

	//Si 0, mouvement vers le bas
	if(direction==0)
		deplacement = mouvementColonnes(p, -1);
	//Si 1, mouvement vers la droite
	else if(direction==1)
		deplacement = mouvementLignes(p, -1);
	//Si 2, mouvement vers le haut
	else if(direction==2)
		deplacement = mouvementColonnes(p, 1);
	//Si 3, mouvement vers la gauche
	else if(direction==3)
		deplacement = mouvementLignes(p, 1);

	//Retourne 1 s'il y a eu déplacement
	return deplacement;
}


int saisieD(){
	debutTerminalSansR();
	Key touche;//Définition d'une touche
	int saisie;

	//On lit une flèche (ou la touche echap)
	do{
	touche = lectureFleche(); 
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



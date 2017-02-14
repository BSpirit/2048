#ifndef MOUVEMENT_H
#define MOUVEMENT_H

#include "grille.h"
#include "saisieM.h"

/*! * Effectue les mouvements (à gauche et à droite) des cases d'une ligne.
	* Renvoie 1 si l'on a déplacé au moins une case, 0 sinon
	*
 	* \param p : pointeur sur la partie en cours
	* \param ligne : indice de ligne
	* \param direction : 1 pour déplacement vers la gauche, -1 pour déplacement vers la droite
 	*/
int mouvementLigne(jeu *p, int ligne, int direction);


/*! * Effectue les mouvements (à gauche et à droite) des cases sur toutes les lignes
	* Retoune 1 si l'on a déplacé au moins une case
	* Retourne 0 sinon
	*
	* \param p : pointeur sur la partie en cours
	* \param direction : 1 pour déplacement vers la gauche, -1 pour déplacement vers la droite
	*/
int mouvementLignes(jeu *p, int direction);


/*! * Effectue les mouvements (vers le haut ou vers le bas) des cases d'une colonne.
	* Renvoie 1 si l'on a déplacé au moins une case, 0 sinon
	*
 	* \param p : pointeur sur la partie en cours
	* \param colonne : indice de colonne
	* \param direction : 1 pour déplacement vers le haut, -1 pour déplacement vers le bas
 	*/
int mouvementColonne(jeu *p, int colonne, int direction);


/*! * Effectue les mouvements (vers le haut ou vers le bas) des cases sur toutes les colonnes
	* Retoune 1 si l'on a déplacé au moins une case
	* Retourne 0 sinon
	*
	* \param p : pointeur sur la partie en cours
	* \param direction : 1 pour déplacement vers le haut, -1 pour déplacement vers le bas
	*/
int mouvementColonnes(jeu *p, int direction);


/*! * Effectue le mouvement correspondant à la direction
	* Retourne 1 si on a déplacé au moins une case
	* Retourne 0 sinon
	* 
	* \param p : pointeur la partie en cours
	* \param direction : entier donnant la direction :
	* 0 : vers le bas
	* 1 : vers la droite
	* 2 : vers le haut
	* 3 : vers la gauche
	*/
int mouvement(jeu *p, int direction);


/*! * Fonction permettant la saisie d'une direction ou de l'arrêt du jeu
	* (saisie répétée pour les autres touches)
	*
	*Retourne :
	* -1 : Si l'utilisateur arrête le jeu
	* 0 : Si l'utilisateur souhaite déplacer vers le BAS
	* 1 : Si l'utilisateur souhaite déplacer vers le DROITE
	* 2 : Si l'utilisateur souhaite déplacer vers le HAUT
	* 3 : Si l'utilisateur souhaite déplacer vers le GAUCHE 
	*/
int saisieD();

#endif

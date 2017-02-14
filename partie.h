#ifndef PARTIE_H
#define PARTIE_H

#include "grille.h"
#include "mouvement.h"
#include <stdlib.h>

/*! * Ajoute une valeur (2 ou 4 choisi aléatoirement) sur une case vide
	* (elle aussi choisie aléatoirement)
	*
	* \param p : pointeur sur la partie en cours
	*/
void ajouteValAlea(jeu *p);


/*! * Retoune 1 si la partie est gagnée
	* retourne 0 sinon
	*
 	* \param p : pointeur sur la partie en cours
 	*/
int gagne(jeu *p);


/*! * Retoune 1 si la partie est perdue
	* retourne 0 sinon
	*
 	* \param p : pointeur sur la partie en cours
 	*/
int perdu(jeu *p);


/*! * Retoune 1 si la partie est terminée
	* retourne 0 sinon
	*
 	* \param p : pointeur sur la partie en cours
 	*/
int finPartie(jeu *p);


/*! * Fonction permettant de jouer la partie en cours
	* (On la suppose initialisée)
	* Retourne 1 si la partie est terminée (gagnée ou perdu)
	* Retourne 0 sinon (L'utilisateur a appuyé sur la touche echap ou la touche s)
	*
	* \param p : pointeur sur la partie en cours
	*/
int jouer(jeu *p);

#endif

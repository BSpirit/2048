#ifndef GRILLE_H
#define GRILLE_H

#include "couleurs_terminal.h"
#include <stdlib.h>
#include <stdio.h>

//Définition de la structure jeu
typedef struct{
	int n; //taille de la grille = n*n 
	int valMax; // valeur à atteindre pour gagner
	int nbCasesLibres; //nbre de cases libres sur la grille
	int *grille;
}jeu;


/*! * Initialise les champs n et valmax avec les valeurs passées en paramètre, initialise nbCasesLibres
	* Alloue la grille de la variable jeu passée par adresse
	* Initialise les cases de la grille avec des cases vides  (valeurs nulles)
	*
	* \param p : pointeur sur une grille de 2018
	* \param n : taille de la grille
	* \param valMax : valeur à atteindre pour gagner
	*/
void initialiseJeu(jeu *p, int n, int valMax);


/*! * Libère la mémoire allouée pour la grille de jeu passée par adresse
	*
	* \param p : pointeur sur une partie de 2048
	*/
void libereMemoire(jeu *p);


/*! * Fonction retournant 1 si la case (i,j) existe, 0 sinon
	*
	* \param p : pointeur sur une partie de jeu 2048
	* \param i : entier correspondant au numéro de "ligne"
	* \param j : entier correspondant au numéro de "colonne"
	*/
int indiceValide(jeu *p, int i, int j);


/*! * Retourne 1 si la case (i,j) est vide
	* Retourne 0 sinon
	*
 	* \param p : pointeur sur la partie en cours
	* \param i : entier correspondant au numéro de ligne
	* \param j : entier correspondant au numéro de colonne
	*/
int caseVide(jeu *p, int i, int j);


/*! * Fonction retournant la valeur de la case (ligne, colonne) de la partie
	* ou -1 si la case n'existe pas
	* 
	* \param p : pointeur sur une partie de jeu 2048
	* \param ligne : entier correspondant au numéro de ligne
	* \param colonne : entier correspondant au numéro de colonne
	*/
int getVal(jeu *p, int ligne, int colonne);


/*! * Fonction modifiant la valeur de la case (ligne, colonne) de la partie p
 	* avec la valeur val
	* Retourne 1 si une nouvelle valeur a été assignée à une case existante
	* Retourne 0 sinon
    * Modifie le nombre de cases libres de la grille si besoin
 	*
 	* \param p : pointeur sur la partie en cours
	* \param ligne : entier correspondant au numéro de ligne
	* \param colonne : entier correspondant au numéro de colonne
	* \param val : entier à mettre dans la case (i,j) (si elle existe)
	*/
int setVal(jeu *p, int ligne, int colonne, int val);


/*! * Assigne une couleur a une case en fonction de la valeur n
	* Retourne la couleur correspondante
	*
	* \param n : valeur de la case à colorer
	*/
COULEUR_TERMINAL choixCouleur(int n);


/*! * Fonction qui affiche la grille dans le terminal
	*
	* \param p : pointeur sur la partie que l'on souhaite afficher
	*/
void affichage(jeu * p);

#endif

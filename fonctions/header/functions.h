
/*!
 * \author Clonier Tony & Jerent Steeve
 * \Version 1.0.0
 *
 */
#ifndef __functions_2048__
#define __functions_2048__

typedef struct{
	int n;
	int valMax;
	int nbCasesLibres;
	int *grille;
} jeu;

/*! 
 * void initialiseJeu(jeu *p, int n, int valMax)
 *
 * Initialise les champs n et valmax avec les valeurs passées en paramètre, initialise nbCasesLibres
 * Alloue la grille de la variable jeu passée par adresse
 * Initialise les cases de la grille avec des cases vides  (valeurs nulles)
 *
 * \param p : pointeur sur une grille de 2018
 * \param n : taille de la grille
 * \param valMax : valeur à atteindre pour gagner
*/
void initialiseJeu(jeu *p, int n, int valMax);

/*! 
 * void libereMemoire(jeu *p)
 *
 * Libère la mémoire allouée pour la grille de jeu passée par adresse
 *
 * \param p : pointeur sur une partie de 2048
*/
void libereMemoire(jeu *p);

/*! 
 * int indiceValide(jeu *p, int i, int j)
 *
 * Fonction retournant 1 si la case (i,j) existe, 0 sinon
 *
 * \param p : pointeur sur une partie de jeu 2048
 * \param i : entier correspondant au numéro de "ligne"
 * \param j : entier correspondant au numéro de "colonne"
*/
int indiceValide(jeu *p, int i, int j);

/*! 
 * int getVal(jeu *p, int ligne, int colonne)
 *
 * Fonction retournant la valeur de la case (ligne, colonne) de la partie
 * ou -1 si la case n'existe pas
 * \param p : pointeur sur une partie de jeu 2048
 * \param ligne : entier correspondant au numéro de ligne
 * \param colonne : entier correspondant au numéro de colonne
*/
int getVal(jeu *p, int ligne, int colonne);

/*! 
 * int caseVide(jeu *p, int i, int j)
 *
 * Retourne 1 si la case (i,j) est vide
 * Retourne 0 sinon
 *
 * \param p : pointeur sur la partie en cours
 * \param i : entier correspondant au numéro de ligne
 * \param j : entier correspondant au numéro de colonne
*/
int caseVide(jeu *p, int i, int j);

/*! 
 * int setVal(jeu *p, int ligne, int colonne, int val)
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
int setVal(jeu *p, int ligne, int colonne, int val);

/*! 
 * void ajouteValAlea(jeu *p)
 *
 * Ajoute une valeur (2 ou 4 choisi aléatoirement) sur une case vide
 * (elle aussi choisie aléatoirement)
 *
 * \param p : pointeur sur la partie en cours
*/
void ajouteValAlea(jeu *p);

/*! 
 * void affichage(jeu * p)
 * Fonction de affichant la grille à l'écran.
 *
 * \param p : pointeur sur la partie que l'on souhaite afficher
 *
*/
void affichage(jeu * p);

/*! 
 * int gagne(jeu *p)
 * Retoune 1 si la partie est gagnée
 * retourne 0 sinon
 *
 * \param p : pointeur sur la partie en cours
*/
int gagne(jeu *p);

/*! 
 * int perdu(jeu *p)
 * Retoune 1 si la partie est perdue
 * retourne 0 sinon
 *
 * \param p : pointeur sur la partie en cours
*/
int perdu(jeu *p);

/*! 
 * int finPartie(jeu *p)
 * Retoune 1 si la partie est terminée
 * retourne 0 sinon
 *
 * \param p : pointeur sur la partie en cours
*/
int finPartie(jeu *p);

/*! 
 * int mouvementLigne(jeu *p, int ligne, int direction)
 * Effectue les mouvements (à gauche et à droite) des cases d'une ligne.
 * Renvoie 1 si l'on a déplacé au moins une case, 0 sinon
 *
 * \param p : pointeur sur la partie en cours
 * \param ligne : indice de ligne
 * \param direction : 1 pour déplacement vers la gauche, -1 pour déplacement vers la droite
*/
int mouvementLigne(jeu *p, int ligne, int direction);

/*! 
 * int mouvementLignes(jeu *p, int direction)
 *
 * Effectue les mouvements (à gauche et à droite) des cases sur toutes les lignes
 * Retoune 1 si l'on a déplacé au moins une case
 * Retourne 0 sinon
 * \param p : pointeur sur la partie en cours
 * \param direction : 1 pour déplacement vers la gauche, -1 pour déplacement vers la droite
*/
int mouvementLignes(jeu *p, int direction);

#endif
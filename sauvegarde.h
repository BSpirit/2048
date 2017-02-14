#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H



/*! * Fonction sauvegardant la partie en cours
    * Retourne 0 en cas de problème
    * Retourne 1 sinon
    *
    * \param p : pointeur sur la partie en cours
    */
int sauvegarde(jeu *p);


/*! * Fonction chargeant la dernière partie sauvegardée
    * Retourne 0 en cas de problème
    * Retourne 1 sinon
    *
    * \param p : pointeur sur la partie en cours
    */
int chargement(jeu *p);


/*! * Affiche le menu :
    * 1 - Jouer
    * 2 - Sauvegarder
    * 3 - Charger
    * 4 - Quitter
    * Retourne la valeur saisie par l'utilisateur
    */
int menu();

#endif

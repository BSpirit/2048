#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H



/*! * Fonction sauvegardant la partie en cours
    * Retourne 0 en cas de problème
    * Retourne 1 sinon
    *
    * \param p : pointeur sur la partie en cours
    */
int sauvegardeJeu(jeu *p);


/*! * Fonction chargeant la dernière partie sauvegardée
    * Retourne 0 en cas de problème
    * Retourne 1 sinon
    *
    * \param p : pointeur sur la partie en cours
    */
int chargementJeu(jeu *p);


/*! * Fonction sauvegardant un score
    * Retourne 0 en cas de problème
    * Retourne 1 sinon
    *
    * \param score : score à enregistrer
    */
int sauvegardeScore(int score);

/*! * Fonction chargeant la liste des scores
    * Retourne 0 en cas de problème
    * Retourne 1 sinon
    *
    * \param score : score à enregistrer
    */
int chargementScore();



/*! * Affiche le menu :
    * 1 - Créer nouvelle partie
    * 2 - Continuer
    * 3 - Sauvegarder
    * 4 - Charger
    * 5 _ Afficher scores
    * 6 - Quitter
    * Retourne la valeur saisie par l'utilisateur
    */
int menu();

#endif

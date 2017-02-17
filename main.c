#include "couleurs_terminal.h"
#include "grille.h"
#include "partie.h"
#include "sauvegarde.h"
#include <time.h>
#include <stdlib.h>

int main(){

	srand((unsigned int)time(NULL));
	jeu p;

	//On initialise dès le départ une grille
	initialiseJeu(&p, 3, 2048);
	ajouteValAlea(&p);
	affichage(&p);
	printf("Partie actuelle \n");
	printf("Bienvenue dans le jeu du 2048 : \n");

	//Affichage du menu
	int choix;
	do{
		choix = menu();
		switch(choix){
			// 1 : Créer une nouvelle partie, possibilité de choisir la taille de la grille ou d'annuler
			case 1 :
				clear_terminal();
				int taille;
				do{
					printf("Taille de la grille ? [3 = 3*3, etc.] [0 pour annuler] : \n");
					scanf("%d", &taille);
				}while(taille<0); //sortie : taille >= 0

				if(taille>0){ 
					//Création d'une nouvelle partie
					initialiseJeu(&p, taille, 2048);
					ajouteValAlea(&p);
					affichage(&p);
					printf("Grille créée, veuillez choisir une option\n");
				}else //taille==0 i.e annulation
					affichage(&p);
				break;
			// 2 : Jouer
			case 2 :
				//Si la partie est terminée, possibilité de sauvegarder son score
				if(jouer(&p))
					sauvegardeScore(p.score);
				affichage(&p);
				break;
			// 3 : Sauvegarder la partie, 3 slots disponibles
			case 3 :
				affichage(&p);
				if(sauvegardeJeu(&p)){
					affichage(&p);
					printf("Sauvegarde OK\n");
				}else{
					affichage(&p);
					printf("Sauvegarde annulée\n");
				}
				break;
			// 4 : Charger une partie, 3 slots disponibles
			case 4 : 
				clear_terminal();
				if(chargementJeu(&p)){
					affichage(&p);
					printf("Chargement OK\n");
				}else{
					affichage(&p);
					printf("Pas de partie à charger \n");
				}
				break;
			// 5 : Afficher la liste des scores
			case 5 :
				affichage(&p);
				if(!chargementScore())
					printf("Aucun score enregistré \n\n");
				break;
			// 6 : Quitter le jeu
			case 6 :
				break;
			default :
				break;
		}
	}while(choix!=6); //Sortie : l'utilisateur appuie sur 6

	libereMemoire(&p);

	return 0;
}

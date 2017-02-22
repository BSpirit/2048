/*******************************************************
Nom           : main.c
Auteur        : Tony Clonier
Version       : V1
Date          : 15/02/2017
Informations  : Programme principal du jeu 2048
********************************************************/

#include "./headers/couleurs_terminal.h"
#include "./headers/grille.h"
#include "./headers/partie.h"
#include "./headers/sauvegarde.h"
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
					printf("Veuillez saisir la taille de la grille ? [3 = 3*3, etc.] [0 pour annuler] : \n");
					printf("La taille de la grille doit être comprise entre 3*3 et 8*8 \n");
				do{
					scanf("%d", &taille);
				}while(taille!=0 && (taille<3 || taille>8)); //sortie : taille == 0 ou (taille>=3 et taille <= 8)

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

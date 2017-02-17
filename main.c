#include "couleurs_terminal.h"
#include "grille.h"
#include "partie.h"
#include "sauvegarde.h"
#include <time.h>
#include <stdlib.h>

int main(){

	srand((unsigned int)time(NULL));
	jeu p;

	initialiseJeu(&p, 3, 2048);
	ajouteValAlea(&p);
	affichage(&p);
	printf("Partie actuelle \n");
	printf("Bienvenue dans le jeu du 2048 : \n");

	int choix;
	do{
		choix = menu();
		switch(choix){
			case 1 :
				clear_terminal();
				int taille;
				do{
					printf("Taille de la grille ? [3 = 3*3, etc.] [0 pour annuler] : \n");
					scanf("%d", &taille);
				}while(taille<0);
				if(taille>0){
					initialiseJeu(&p, taille, 2048);
					ajouteValAlea(&p);
					affichage(&p);
					printf("Grille créée, veuillez choisir une option\n");
				}else
					affichage(&p);
				break;
			case 2 :
				if(jouer(&p))
					sauvegardeScore(p.score);
				affichage(&p);
				break;
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
			case 5 :
				affichage(&p);
				if(!chargementScore())
					printf("Aucun score enregistré \n\n");
				break;
			case 6 :
				break;
			default :
				break;
		}
	}while(choix!=6);

	libereMemoire(&p);

	return 0;
}

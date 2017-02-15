#include "couleurs_terminal.h"
#include "grille.h"
#include "partie.h"
#include "sauvegarde.h"
#include <time.h>
#include <stdlib.h>

int main(){

	srand((unsigned int)time(NULL));
	jeu p;
	int choix;
	int fin;

	if(!chargementJeu(&p)){
		initialiseJeu(&p, 3, 2048);
		ajouteValAlea(&p);
	}
	affichage(&p);

	do{
		printf("\nBienvenue dans le jeu du 2048 : \n");
		choix = menu();
		switch(choix){
			case 1 :
				clear_terminal();
				do{
					printf("Taille de la grille ? [3 = 3*3, etc.] [-1 pour annuler] : \n");
					scanf("%d", &p.n);
				}while(p.n<-1);
				if(p.n>0){
					initialiseJeu(&p, p.n, 2048);
					ajouteValAlea(&p);
					affichage(&p);
				}else
					affichage(&p);
				break;
			case 2 :
				fin = jouer(&p);
				if(fin)
					sauvegardeScore(p.score);
				affichage(&p);
				break;
			case 3 :
				affichage(&p);
				if(sauvegardeJeu(&p))
					printf("Sauvegarde OK\n");
				else
					printf("Erreur sauvegarde\n");
				break;
			case 4 : 
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

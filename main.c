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

	if(!chargement(&p)){
		initialiseJeu(&p, 3, 2048);
		ajouteValAlea(&p);
	}

	do{
		affichage(&p);
		printf("Partie actuelle\n\n");
		printf("Bienvenue dans le jeu du 2048 : \n");
		choix = menu();
		switch(choix){
			case 1 :
				printf("Taille de la grille ? [3 = 3*3, etc.] : \n");
				scanf("%d", &p.n);
				initialiseJeu(&p, p.n, 2048);
				ajouteValAlea(&p);
			case 2 :
				jouer(&p);
				break;
			case 3 :
				sauvegarde(&p);
				break;
			case 4 : 
				chargement(&p);
				break;
			case 5 :
				break;
			default :
				break;
		}
	}while(choix!=5);

	libereMemoire(&p);

	return 0;
}

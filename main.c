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


	if(chargement(&p)){
		affichage(&p);
		printf("Partie actuelle \n\n");
		printf("Bienvenue dans le jeu du 2048 : \n");
	}
	choix = menu();

	do{
		switch(choix){
			case 1 :
				printf("Taille de la grille ? [3 = 3*3, etc.] : \n");
				scanf("%d", &p.n);
				initialiseJeu(&p, p.n, 2048);
				ajouteValAlea(&p);
				affichage(&p);
				choix = menu();
			case 2 :
				affichage(&p);
				jouer(&p);
				affichage(&p);
				choix = menu();
				break;
			case 3 :
				affichage(&p);
				if(sauvegarde(&p))
					printf("Sauvegarde OK\n\n");
				else
					printf("Erreur de sauvegarde\n\n");
				choix = menu();
				break;
			case 4 : 
				chargement(&p);
				affichage(&p);
				choix = menu();
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

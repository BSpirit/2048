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

	initialiseJeu(&p, 3, 2048);
	ajouteValAlea(&p);
	affichage(&p);
	choix = menu();

	do{
		switch(choix){
			case 1 :
				affichage(&p);
				jouer(&p);
				affichage(&p);
				choix = menu();
				break;
			case 2 :
				affichage(&p);
				if(sauvegarde(&p))
					printf("Sauvegarde OK\n\n");
				else
					printf("Erreur de sauvegarde\n\n");
				choix = menu();
				break;
			case 3 : 
				if(chargement(&p))
					printf("Chargement OK\n\n");
				else
					printf("Erreur de chargement\n\n");
				affichage(&p);
				choix = menu();
				break;
			case 4 :
				break;
			default :
				break;
		}
	}while(choix!=4);

	libereMemoire(&p);

	return 0;
}

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

	do{
		choix = menu();
		switch(choix){
			case 1 :
				initialiseJeu(&p, 3, 2048);
				jouer(&p);
				affichage(&p);
				choix = menu();
				break;
			case 2 :
				printf("%d", sauvegarde(&p));
				break;
			case 3 : 
				initialiseJeu(&p, 3, 2048);
				printf("%d", chargement(&p));
				jouer(&p);
				affichage(&p);
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

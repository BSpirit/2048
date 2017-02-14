#include "couleurs_terminal.h"
#include "grille.h"
#include "partie.h"
#include <time.h>
#include <stdlib.h>

int main(){

	srand((unsigned int)time(NULL));
	jeu p;

	initialiseJeu(&p, 4, 2048);
	jouer(&p);
	affichage(&p);

	libereMemoire(&p);

	return 0;
}

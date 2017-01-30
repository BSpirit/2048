#include <stdio.h>
#include "saisieM.h"
#include "terminalCouleur.h"

int main()
{

	//Saisie normale :
	char c;
	printf("Saisir une lettre : ");
	scanf(" %c",&c);
	printf("Vous avez saisi : %c\n",c);


	//Début du mode saisie des flèches ou de la touche Echap sans appuyer sur entrée pour valider
	debutTerminalSansR();

	Key touche;//Définition d'une touche

	touche = lectureFleche();//On lit une flèche (ou la touche echap)

	while ( touche != KEY_ESCAPE)//Tant que l'on n'a pas appuyé sur la touche echap
	{
		//On affiche quelle flèche a été saisie
		if (touche == KEY_UP)
			color_printf(RED,BLUE,"FLECHE HAUT");
		else if (touche == KEY_DOWN)
			color_printf(MAGENTA,BLACK,"FLECHE BAS");
		else if (touche == KEY_LEFT)
			color_printf(CYAN,YELLOW,"FLECHE GAUCHE");
		else if (touche == KEY_RIGHT)
			color_printf(GREEN,WHITE,"FLECHE DROITE");
		else //touche vaut la valeur NO_KEY
			printf("Pas de flèche saisie");
		printf("\n");

		touche = lectureFleche();//On lit une flèche (ou la touche echap)

	}
	finTerminalSansR();

	return 0;
}

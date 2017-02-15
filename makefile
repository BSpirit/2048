compile:
	gcc -o 2048 couleurs_terminal.c grille.c sauvegarde.c saisieM.c mouvement.c partie.c main.c

clear:
	rm -rf 2048

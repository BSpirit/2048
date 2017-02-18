compile:
	gcc -o 2048 couleurs_terminal.c grille.c sauvegarde.c saisieM.c mouvement.c partie.c main.c

test: clearTest compileTest
	./test

compileTest:
	gcc -o test couleurs_terminal.c grille.c saisieM.c mouvement.c partie.c test_part1.c test_part2.c testUnitaire.c

clearGame:
	rm -rf 2048

clearTest:
	rm -rf test
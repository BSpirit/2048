all: run test

run: clearGame compile
	./2048

compile:
	gcc -o 2048 functions/couleurs_terminal.c functions/grille.c functions/sauvegarde.c functions/saisieM.c functions/mouvement.c functions/partie.c functions/main.c

test: clearTest compileTest
	./test

compileTest:
	gcc -o test functions/couleurs_terminal.c functions/grille.c functions/saisieM.c functions/mouvement.c functions/partie.c functions/test_part1.c functions/test_part2.c functions/test_part3.c functions/testUnitaire.c

clearGame:
	rm -rf 2048

clearTest:
	rm -rf test
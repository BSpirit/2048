#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include "couleurs_terminal.h"
#include "grille.h"
#include "mouvement.h"
#include "partie.h"
#include "test_part.h"


void test_partie4(){
    int somme = 0;
    somme += test_mouvementLigne();
    somme += test_mouvementLignes();
    somme += test_mouvementColonne();
    somme += test_mouvementColonnes();
    somme += test_mouvement();
    somme += test_saisieD();
    if(somme == 6)
        somme += test_jouer();

    if(somme != 7)
        termine("TOUS LES TESTS DE LA PARTIE 3 NE SONT PAS PASSES !");
    else{
        printf("\033[32;01m#########################\n");
        printf("#   TESTS PARTIE 3 OK   #\n");
        printf("######################### \033[00m\n");
    }
}
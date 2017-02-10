#include <string.h>
#include <stdio.h>
/*
 * Fonction permettant de lire les caractères saisis au clavier.
 * La fonction permet de lire même les espaces. La lecture s'arrête au 
 * caractère saut de ligne ('\n'). Les caractères lus sont stockés dans
 * le paramètre chaine.
 * 
 * Remarque : pour éviter des dépassements de tableaux, la fonction lit 
 * au plus n caractères. Les caractères restants (jusqu'au saut de ligne)
 * sont supprimés.
 */
void saisie_avec_espaces(char * chaine, int n);

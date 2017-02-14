#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include <unistd.h>


// couleurs du terminal
  typedef enum
  {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
  } COULEUR_TERMINAL;

/*
 * Fonction effaçant le terminal
 */
void clear_terminal();

/*
 * Printf en couleur. Les deux premiers paramètres sont les couleurs d'écriture et de fond (mettre une des valeurs parmi : 
 * BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN et WHITE).
 * Les parmètres suivants sont comme le printf "normal" : chaîne de format puis toutes les valeurs à afficher
 */
int color_printf(COULEUR_TERMINAL fg, COULEUR_TERMINAL bg, const char * format, ...);

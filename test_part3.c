#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include "couleurs_terminal.h"
#include "grille.h"
#include "mouvement.h"
#include "partie.h"
#include "test_part.h"

int test_mouvementLigne(){
    int n = 4;
    int vMax = 2048;
    jeu jeu_test;
    jeu * tmp = &jeu_test;
    initialiseJeu(tmp, n, vMax);

    setVal(tmp, 0, 3, 2);
    int res = mouvementLigne(tmp, 0, -1);

    if (res != 0)
        return termine("ml - Le mouvement vers la droite à été executer");
    
    res = mouvementLigne(tmp, 0, 1);
    if(getVal(tmp, 0, 0) == 0)
        return termine("ml - Le mouvement sur la ligne est incorrect.");
    
    if (res != 1)
        return termine ("ml - Le mouvement n'as pas été executer.");
    
    setVal(tmp, 0, 1, 32);
    setVal(tmp, 0, 2, 4);
    setVal(tmp, 0, 3, 2);
    res = mouvementLigne(tmp, 0, -1);
    if(res != 0)
        return termine("ml - Le mouvement vers la droite à été effectuer.");
    
    res = mouvementLigne(tmp, 0, 1);
    if(res != 0)
        return termine("ml - Le mouvement vers la gauche à été effectuer.");

    setVal(tmp, 0, 3, 4);
    res = mouvementLigne(tmp, 0, -1);

    if(getVal(tmp, 0, 3) != 8)
        return termine("ml - La dernier case [0, 3] n'est pas égale à 8");
    
    if(getVal(tmp, 0, 0) != 0)
        return termine("ml - La valeur de la case [0,0] n'est pas reinitialisé.");
    
    if(res != 1)
        return termine("ml - Le mouvement vers la droite n'a pas été effectuer.");
    
    setVal(tmp, 0, 0, 2);    
    res = mouvementLigne(tmp, 0, 1);
    
    if(getVal(tmp, 0, 0) != 4)
        return termine("ml - La valeur de la case [0,0] n'est pas égale à 4");
    
    if(getVal(tmp, 0, 3) != 0)
        return termine("ml - La valeur de la case [0,3] n'est pas réinitialisé.");
    
    setVal(tmp, 0, 2, 32);
    setVal(tmp, 0, 3, 64);
    res = mouvementLigne(tmp, 0, -1);

    if(getVal(tmp, 0, 2) != 64)
        return termine("ml - La valeur de la case [0,2] n'est pas égale à 64.");

    if(getVal(tmp, 0, 3) != 64)
        return termine("ml - La valeur de la case [0,3] n'est pas égale à 64.");
    
    return 1;
}

int test_mouvementLignes(){
    int n = 2;
    int vMax = 2048;
    jeu jeu_test;
    jeu * tmp = &jeu_test;
    initialiseJeu(tmp, n, vMax);

    setVal(tmp, 0, 1, 2);
    setVal(tmp, 1, 1, 2);
    
    int res = mouvementLignes(tmp, -1);

    if(res != 0)
        return termine("mls - Le mouvement sur les lignes est effectué.");
    
    res = mouvementLignes(tmp, 1);
    
    if(res != 1)
        return termine("mls - 1 - Le mouvement sur les ligne n'est pas effectué.");

    setVal(tmp, 0, 1, 2);
    setVal(tmp, 1, 1, 2);
    res = mouvementLignes(tmp, -1);

    if(res != 1)
        return termine("mls - 2 - Le mouvement sur les ligne n'est pas été effectué.");
    
    if(getVal(tmp, 0, 1) != 4 || getVal(tmp, 1, 1) != 4)
        return termine("mls - Le mouvement n'as pas donnée 4 sur les case [0,1] ou [1,1]");
    
    setVal(tmp, 1, 1, 0);
    setVal(tmp, 1, 0, 2);

    res = mouvementLignes(tmp, -1);

    if(res != 1)
        return termine("mls - Aucun mouvement vers la droite detecté.");

    return 1;
}

int test_mouvementColonne(){
    int n = 2;
    int vMax = 2048;
    jeu jeu_test;
    jeu * tmp = &jeu_test;
    initialiseJeu(tmp, n, vMax);

    setVal(tmp, 0, 0, 2);
    setVal(tmp, 1, 1, 2);

    int res = mouvementColonne(tmp, 1, -1);

    if(res != 0)
        return termine("mc - 1 -Aucune case ne devrait bougé.");
    
    res = mouvementColonne(tmp, 0, 1);
    if(res != 0)
        return termine("mc - 2 - Aucune case ne devrait bougé.");
    
    setVal(tmp, 0, 1, 2);
    setVal(tmp, 1, 0, 2);
    res = mouvementColonne(tmp, 1, 1);

    if(res != 1)
        return termine("mc - 1 - Aucun case n'as bougé");
    
    if (getVal(tmp, 0, 1) != 4)
        return termine("mc - La valeur de la case [0,1] devrait être égale à 4");
    
    if(getVal(tmp, 1, 1) != 0)
        return termine("mc - La valeur de la case [1,1] n'as pas été reinitialisé.");
    
    res = mouvementColonne(tmp, 0, -1);

    if(res != 1)
        return termine("mc - 2 - Aucune case n'as bougé.");
    
    if(getVal(tmp, 1, 0) != 4)
        return termine("mc - La valeur de la case [1,0] devrait etre égale à 4");
    
    if(getVal(tmp, 0, 0) != 0)
        return termine("mc - La valeur de la case [0,0] n'as pas été reinitialisé.");
    setVal(tmp, 0,0, 32);
    res = mouvementColonne(tmp, 0, 1);

    if(res != 0)
        return termine("mc - Le mouvement effectuer est interdit.");
    
    if(getVal(tmp, 0, 0) != 32)
        return termine("mc - La valeur de la case [0,0] à été changer.");

    return 1;
}

int test_mouvementColonnes(){
    int n = 2;
    int vMax = 2048;
    jeu jeu_test;
    jeu * tmp = &jeu_test;
    initialiseJeu(tmp, n, vMax);
    setVal(tmp, 0, 1, 2);
    setVal(tmp, 1, 0, 2);
    int res = mouvementColonnes(tmp, 1);

    if(res != 1)
        return termine("mcs - 1 - Aucune case n'as bouger.");
    
    res = mouvementColonnes(tmp, -1);
    if(res != 1)
        return termine("mcs - 2 - Aucune case n'as bougé.");

    res = mouvementColonnes(tmp, -1);

    if(res != 0)
        return termine("mcs - 1 - Aucune case ne devait bouger.");
    
    mouvementColonnes(tmp, 1);
    res = mouvementColonnes(tmp, 1);

    if(res != 0)
        return termine("mcs - 2 - Aucune case ne devait bouger.");
    
    setVal(tmp, 1, 0, 2);
    setVal(tmp, 1, 1, 4);

    res = mouvementColonnes(tmp, -1);

    if(res != 1)
        return termine("mcs - 3 - Aucun case n'as bougé.");
    
    if(getVal(tmp, 1, 1) != 4)
        return termine("mcs - La valeur de la case [1,1] ne devait pas changer.");

    return 1;
}

int test_mouvement(){
    int n = 2;
    int vMax = 2048;
    jeu jeu_test;
    jeu * tmp = &jeu_test;
    initialiseJeu(tmp, n, vMax);
    setVal(tmp, 0, 1, 2);

    int res = mouvement(tmp, 0);

    if(res != 1)
        return termine("m - Le mouvement vers le bas a echoué");
    if(getVal(tmp, 0, 1) != 0)
        return termine("La valeur de la case [0,1] n'est pas réinitialisé.");

    res = mouvement(tmp, 3);

    if(res != 1)
        return termine("Le mouvement vers la gauche a echoué");
    
    if(getVal(tmp, 1, 1) != 0)
        return termine("La valeur de la case [1,1] n'est pas réinitialisé.");
    
    res = mouvement(tmp, 2);
    if(res != 1)
        return termine("le mouvement vers le haut a échoué");
    
    if(getVal(tmp, 1, 0) != 0)
        return termine("La valeur de la case [1,0] n'est pas réinitialisé.");
    
    res = mouvement(tmp, 1);
    if(res != 1)
        return termine("Le mouvement ver la droite a echoué.");
    
    if(getVal(tmp, 0, 0) != 0)
        return termine("La valeur de la case [0,0] n'est pas réinitialisé.");
    
    setVal(tmp, 0, 0, 32);
    setVal(tmp, 1, 0, 64);
    setVal(tmp, 1, 1, 2);

    res = mouvement(tmp, 3);

    if(res != 0)
        return termine("les cases ne devrait pas bouger vers la gauche");
    
    res = mouvement(tmp, 0);
    if(res != 1)
        return termine("la case [0,1] devait bouger sur la case [1,1]");
    
    if(getVal(tmp, 1,1) != 4)
        return termine("La valeur de la case [1,1] n'est pas égale à 4.");
    
    res = mouvement(tmp, 0);
    if(res != 0)
        return termine("m - 1 - Mouvement interdit");
    
    mouvement(tmp, 1);    
    res = mouvement(tmp, 1);
    if(res != 0)
        return termine("m - 2 - Mouvement interdit");

    return 1;
}

int test_saisieD(){

    printf("\033[33;01mTest interactif - Clavier \033[00m\n");
    printf("Il n'y a que 5 touches fonctionnelles lors de ce jeux \n - ECHAP \n - Flèche 'HAUT' \
    \n - Flèche 'BAS' \n - Flèche 'DROITE' \n - Flèche 'GAUCHE' \
    \n \033[31;01m(3 essaie par Touche)\033[00m\n");
    int res, essaie = 1;
    do{
        printf("Appuyer sur la touche 'ECHAP' (%d/3)\n", essaie);
        fflush(stdout);
        res = saisieD();
        essaie++;
    }while(res != -1 && essaie <= 3);

    if(essaie > 3)
        return termine("La Touche echap ne fonctionne pas. (ou c'est une erreur de saisie volontaire)");

    essaie = 1;
    do{
        printf("Appuyer sur la flèche 'HAUT' (%d/3)\n", essaie);
        fflush(stdout);
        res = saisieD();
        essaie++;
    }while(res != 2 && essaie <= 3);
    
    if(essaie > 3)
        return termine("la flèche 'HAUT' ne fonctionne pas. (ou c'est une erreur de saisie volontaire)");
    
    essaie = 1;
    do{
        printf("Appuyer sur la flèche 'BAS' (%d/3)\n", essaie);
        fflush(stdout);
        res = saisieD();
        essaie++;
    }while(res != 0 && essaie <= 3);
    if(essaie > 3)
        return termine("La flèche 'BAS' ne fonctionne pas. (ou c'est une erreur de saisie volontaire)");

    essaie = 1;
    do{
        printf("Appuyer sur la flèche 'DROITE' (%d/3)\n", essaie);
        fflush(stdout);
        res = saisieD();
        essaie++;
    }while(res != 1 && essaie <= 3);
    if(essaie > 3)
        return termine("la flèche 'DROITE' ne fonctionne pas. (ou c'est une erreur de saisie volontaire)");

    essaie = 1;
    do{
        printf("Appuyer sur la flèche 'GAUCHE' (%d/3)\n", essaie);
        fflush(stdout);
        res = saisieD();
        essaie++;
    }while(res != 3 && essaie <= 3);
    if(essaie > 3)
        return termine("la flèche 'GAUCHE' ne fonctionne pas. (ou c'est une erreur de saisie volontaire)");
    return 1;
}

int test_jouer(){
    int n = 2;
    int vMax = 2048;
    jeu jeu_test;
    jeu * tmp = &jeu_test;
    initialiseJeu(tmp, n, vMax);
    setVal(tmp, 0, 1, 2);
    int res, essaie = 1;
    do{
        printf("\033[34;01mUne partie va être lancer Appuyer sur echap. (%d/3)\033[00m\n", essaie);
        fflush(stdout);
        sleep(5);
        res = jouer(tmp);
        essaie++;
    }while(res != 0 && essaie <= 3);

    if(essaie > 3 && res != 0)
        return termine("La partie ne renvoie pas 0 ou vous n'appuyez pas sur 'ECHAP'");

    setVal(tmp, 0, 0, 2045);
    setVal(tmp, 0, 1, 2046);
    setVal(tmp, 1, 0, 2047);
    setVal(tmp, 1, 1, 2049);
    essaie = 1;
    do{
        printf("\033[34;01mUne partie va être lancer Appuyer sur flèche directionnelle. (%d/3)\033[00m\n", essaie);
        fflush(stdout);
        sleep(5);
        res = jouer(tmp);
        essaie++;
    }while(res != 1 && essaie <= 3);

    if(essaie > 3 && res != 0)
        return termine("La partie ne renvoie pas 1 ou vous n'appuyez pas une flèche directionnelle.");
    
    setVal(tmp, 0, 0, 0);
    setVal(tmp, 0, 1, 0);
    setVal(tmp, 1, 0, 0);
    setVal(tmp, 1, 1, 2048);
    essaie = 1;
    do{
        printf("\033[34;01mUne partie va être lancer Appuyer sur flèche directionnelle. (%d/3)\033[00m\n", essaie);
        fflush(stdout);
        sleep(5);
        res = jouer(tmp);
        essaie++;
    }while(res != 1 && essaie <= 3);

    if(essaie > 3 && res != 0)
        return termine("La partie ne renvoie pas 1 ou vous n'appuyez pas une flèche directionnelle.");
    return 1;
}

void test_partie3(){
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
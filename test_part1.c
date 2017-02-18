#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include "couleurs_terminal.h"
#include "grille.h"
#include "test_part.h"

int termine(const char *ch){
    printf("***********************\n");
    printf("******* Erreur ********\n");
    printf("***********************\n");
    printf("* %s *\n", ch);
    return 0;    
}

int test_creer_initialiseJeu(){
    int i;
    int n = 4;
    int vMax = 2048;
    
    jeu jeu_test;

    jeu * tmp = &jeu_test;

    initialiseJeu(tmp, n, vMax);
    if(tmp->valMax != vMax)
        return termine("La valeur maximun à atteindre n'est pas correcte ! ");

    if(tmp->nbCasesLibres != n*n)
        return termine("Le nombre de case libre n'est pas correct !");
    
    int somme = 0;

    for(i=0; i<n*n; i++)
        somme+=tmp->grille[i];

    if(somme != 0)
        return termine("La grille ne contient pas que des cases libres !");
    
    libereMemoire(tmp);

    return 1;

}

int test_indice_valide(){
    int n=4;
    int vMax = 2048;
    
    jeu jeu_test;

    jeu * tmp = &jeu_test;

    initialiseJeu(tmp ,n,vMax);
    
    int i,j;

    int somme = 0;

    for(i = 0 ; i < n ; i++)
        for(j = 0 ; j <n ; j++)
            somme += indiceValide(tmp,i,j);

    if (somme != n*n)
        return termine("indice =Valide ne retourne pas 1 correctement");
    
    if(indiceValide(tmp,-1,2) || indiceValide(tmp,n,2))
        return termine("indiceValide ne retourne pas 0 correctement !");

    if(indiceValide(tmp,3,-1) || indiceValide(tmp,3,n))
        return termine("indiceValide ne retourne pas 0 correctement !");

    libereMemoire(tmp);
    return 1;        
}

int test_fonction_get_val(){
    int n=6;
    int vMax = 2048;
    
    jeu jeu_test;

    jeu * tmp = &jeu_test;
    
    initialiseJeu(tmp,n,vMax);
    
    int i,j;

    int somme = 0;

    for(i = -1 ; i <= n ; i++)
        for(j = -1 ; j <= n ; j++)
            somme += getVal(tmp,i,j);
    
    if (somme != -28)
        return termine("La case n'est pas vide ou getVal ne retourne pas -1 quand on n'est pas sur la case");
    
    for(i = 7 ; i <= 10 ; i++)
        tmp->grille[i] = i -6;
    
    somme=0;
    for(i=0; i<=5;i++)
        for(j=0; j<=5; j++)
            somme += getVal(tmp, i, j);

    if (somme != 10)
        return termine("getVal ne retourne pas la bonne valeur !");
    
    libereMemoire(tmp);
    return 1;
}

int test_fonction_set_val(){
    int n=6;
    int vMax = 2048;
    
    jeu jeu_test;

    jeu * tmp = &jeu_test;

    initialiseJeu(tmp,n,vMax);

    int res = setVal(tmp, 1,1,5);
    
    if(res != 1)
        return termine("set valeur ne retourne pas la bonne valeur !");
    
    
    if(tmp->nbCasesLibres != 35)
        return termine("Le nombre de case libre n'est pas correct ! test");

    if(tmp->grille[7] != 5)
        return termine("setVal ne modifie pas correctement la case !");
    
    res = setVal(tmp, 18,2,5);
    if(res != 0)
        return termine("setVAl ne renvoie pas ka bonne valeur ! L'indice de ligne n'est pas bon !");

    res = setVal(tmp, -1,2,7);
    if(res != 0)
        return termine("setVAl ne renvoie pas ka bonne valeur ! L'indice de ligne n'est pas bon !");
    
    res = setVal(tmp, 0, 2, 3);
    if(res != 1)
        return termine("setVal ne renvoie pas la bonne valeur !");
    
    if(tmp->nbCasesLibres != 34)
        return termine("Le nombre de case libre n'est pas correcte ! On modifie la bordure !");
    
    if (tmp->grille[2] != 3)
        return termine("setVal ne modifie pas correctement la valeur !");

    res = setVal(tmp, 1,1,3);
    if (res != 1)
        return termine("setVal ne renvoie pas la bonne valeur !");

    if (tmp->nbCasesLibres != 34)
        return termine("le nombre de case libre n'est pas correct !");

    if(tmp->grille[7] != 3)
        return termine("setVal ne modifie pas correctement le jeu !");

    res = setVal(tmp, 1,1,0);
    if (res != 1)
        return termine("set valeur ne renvoie pas la bonne valeur !");
    
    
    if (tmp->nbCasesLibres != 35)
        return termine("le nombre de cases de libres n'est pas correct !");

    if (tmp->grille[7] != 0)
        return termine("setVal ne modifie pas correctement le jeu !");
    
    libereMemoire(tmp);
    return 1;
}

void test_partie1(){
    int somme = 0;
    somme += test_creer_initialiseJeu();
    somme += test_indice_valide();
    somme += test_fonction_get_val();
    somme += test_fonction_set_val();

    if(somme != 4)
        termine("TOUS LES TESTS DE LA PARTIE 1 NE SONT PAS PASSES !");
    else{
        printf("#########################\n");
        printf("#   TESTS PARTIE 1 OK   #\n");
        printf("#########################\n");
    }
}
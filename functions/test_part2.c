#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#include "./headers/couleurs_terminal.h"
#include "./headers/grille.h"
#include "./headers/partie.h"
#include "./headers/test_part.h"



int test_case_vide(){
    int i, j;
    int n = 4;
    int vMax = 2048;
    
    jeu jeu_test;

    jeu * tmp = &jeu_test;

    initialiseJeu(tmp, n, vMax);

    setVal(tmp, 1, 3, 5);
       
    int res = caseVide(tmp, 1, 3);
    
    if(res != 0)
        return termine("La case est vide.");
    
    setVal(tmp, 1, 3, 0);
    res = caseVide(tmp, 1, 3);
        
    if(res != 1)
        return termine("La case n'est pas vide.");
    
    res = caseVide(tmp, 9, 9);  
    if(res != 0)
        return termine("La case n'existe pas.");
    
    for(i=0; i<=n;i++)
        for(j=0; j<=n; j++)
            setVal(tmp, i, j, 1);
    
    int somme = 0;
    for(i=0; i<n;i++)
        for(j=0; j<n; j++)
            somme += caseVide(tmp, i, j);
    
    if(somme != 0)
        return termine("Un case ou plusieurs cases du tableau ne sont pas vide");

    for(i=0; i<=n;i++)
        for(j=0; j<=n; j++)
            setVal(tmp, i, j, 0);
    
    somme = 0;
    for(i=0; i<n;i++)
        for(j=0; j<n; j++)
            somme += caseVide(tmp, i, j);
    
    if (somme != 16)
        return termine("Une case ou plusieurs case sont rempli");

    return 1;
}

int test_ajouter_val_aleatoire(){
    int i, j;
    int n = 4;
    int vMax = 2048;
    
    jeu jeu_test;

    jeu * tmp = &jeu_test;

    initialiseJeu(tmp, n, vMax);

    ajouteValAlea(tmp);
    
    int compteur = 0;
    for(i=0; i<n;i++){
        for(j=0; j<n; j++){
            if(getVal(tmp, i, j) == 2 || getVal(tmp, i, j) == 4){
                compteur++;
                setVal(tmp, i, j, 0);
            }
        }
    }
    
    if(compteur == 0)
        return termine("Aucun valeur aleatoire n'as été rajouter.");

    if(compteur > 1)
        return termine("Plusieurs valeurs aleatoires ont été toruver.");
    
    int l = 0;
    int nb_2 = 0;
    int nb_4 = 0;
    while(l<1000 && (nb_2 == 0 || nb_4 == 0)){
        ajouteValAlea(tmp);
        for(i=0; i<n;i++){
            for(j=0; j<n; j++){
                if(getVal(tmp, i, j) == 2){
                    nb_2++;
                    setVal(tmp, i, j, 0);
                }else if(getVal(tmp, i, j) == 4){
                    nb_4++;
                    setVal(tmp, i, j, 0);
                }
            }
        }
        l++;
    }

    if(nb_2 == 0 || nb_4 == 0)
        return termine("L'une des 2 valeurs aleatoires est manquante.");

    int case_alea = 0;
    int pos_ligne = -1, pos_colonne=-1;
    l=0;
    while(l<10){
        ajouteValAlea(tmp);
        for(i=0; i<n;i++){
            for(j=0; j<n; j++){
                if(getVal(tmp, i, j) == 2 || getVal(tmp, i, j) == 4){
                    if(i != pos_ligne && j != pos_colonne){
                        pos_ligne = i;
                        pos_colonne = j;
                        setVal(tmp, i, j, 0);
                        case_alea--;
                    }else{
                        case_alea++;
                        setVal(tmp, i, j, 0);
                    }
                }
            }
        }
        l++;
    }
 
    if(case_alea == 10)
        return termine("Les valeur 2 et 4 n'apparaissent pas aléatoirement.'");

    for(i=0; i<=n;i++)
        for(j=0; j<=n; j++)
            setVal(tmp, i, j, 1);
    
    ajouteValAlea(tmp);
    compteur=0;
    for(i=0; i<n;i++){
        for(j=0; j<n; j++){
            if(getVal(tmp, i, j) == 2 || getVal(tmp, i, j) == 4){
                compteur++;
                setVal(tmp, i, j, 0);
            }
        }
    }

    if(compteur != 0)
        return termine("Un valeur a été rajouter aleatoirement alors que la grille est rempli");
    
    return 1;
}

int test_gagne(){
    int n = 4;
    int vMax = 2048;
    
    jeu jeu_test;

    jeu * tmp = &jeu_test;

    initialiseJeu(tmp, n, vMax);
    setVal(tmp, 1,1, 2048);
    int res = gagne(tmp);
    if(res != 1)
        return termine("La valeurs set devait permettre de gagner.");
    
    setVal(tmp, 1,1, 1024);
    res = gagne(tmp);
    if(res != 0)
        return termine("La valeur 2048 a été modifier par 1024, donc il est impossible de gagner.");
    return 1;    
}

int test_perdu(){
    int n = 2;
    int vMax = 2048;
    
    jeu jeu_test;

    jeu * tmp = &jeu_test;

    initialiseJeu(tmp, n, vMax);
    setVal(tmp, 0, 0, 1);
    setVal(tmp, 0, 1, 2);
    setVal(tmp, 1, 0, 3);
    setVal(tmp, 1, 1, 4);

    int res = perdu(tmp);

    if(res != 1)
        return termine("La partie devrait être perdu");
    
    setVal(tmp, 1, 1, 2);

    res = perdu(tmp);
    if(res != 0)
        return termine("1 - La partie devait continuer");
    
    setVal(tmp, 0, 0, 2);
    setVal(tmp, 0, 1, 4);
    setVal(tmp, 1, 1, 4);
    res = perdu(tmp);
    if(res != 0)
        return termine("2 - La partie devait continuer");
    
    return 1;
}

int test_finPartie(){
    int n = 2;
    int vMax = 2048;
    
    jeu jeu_test;

    jeu * tmp = &jeu_test;

    initialiseJeu(tmp, n, vMax);
    setVal(tmp, 1, 1, 2048);
    int res = finPartie(tmp);

    if(res != 1)
        return termine("La partie devrait être fini.");
    
    setVal(tmp, 1, 1, 1024);
    res = finPartie(tmp);
    if (res != 0)
        return termine("La partie est encore jouable.");

    return 1;
}

void test_partie2(){
    int somme = 0;
    somme += test_case_vide();
    somme += test_ajouter_val_aleatoire();
    somme += test_gagne();
    somme += test_perdu();
    somme += test_finPartie();

    if(somme != 5)
        termine("TOUS LES TESTS DE LA PARTIE 2 NE SONT PAS PASSES !");
    else{
        printf("\033[32;01m#########################\n");
        printf("#   TESTS PARTIE 2 OK   #\n");
        printf("#########################\033[00m\n");
    }
}
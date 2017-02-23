### Auteur : Jerent Steeve

## 1 - Fonction **termine**

Permet d'afficher les messages d'erreurs lors des tests unitaire et retourne 0 pour signaler l'erreur.
<br>

```c
    int termine(const char *ch){
        printf("\033[31;01m***********************\n");
        printf("******* Erreur ********\n");
        printf("***********************\n");
        printf("* %s *\033[00m\n", ch);
        return 0;    
    }
```

## 2 - Fonction **int test_creer_initialiseJeu**

Cas de test :
1. Test de la valeur max :
> <p class="font">On vérifie si la valeur max n'est pas différente de celle donnée dans la norme.<p>
2. Test du nombre de case libre :
> <p class="font">Après initialisation de la partie on vérifie si nbCaseLibre est égale à n * n.<br> On réalise une seconde vérification, en fesant la somme des valeurs composant la grille pour déterminer si elle vaut 0<p>
<br>

```c
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
```

## 3 - Fonction **test_indice_valide**
Cas de test :
- Test indice case :
> <p class="font">On cumule chaque indice valide de notre grille et on vérifie si elle vaut n * n.<br> Puis nous réalisons des tests si l'indice est hors des limites de la grille<p>
<br>

```c
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
```

## 4 - Fonction **test_fonction_get_val**

Cas de tests :
- Test valeur case :
> <p class="font">On rempli une grille de jeu avec des valeurs puis on vérifie la somme des valeurs de la grille<p> 

<br>

```c
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
```

## 5 - Fonction **test_fonction_set_val**
Cas de test : 
1. Test set valeur :
> <p class="font">On set les valeurs de plusieurs case et on test si la fonction "setVal" renvoie 1.</p>
2. Test nbCasesLibres :
> <p class="font">On vérifie si le nombre de case libre s'incrémente ou décrémente en fonction de la valeur à mise dans la case.<br> 0 - incrémente <br> sup. 0 - décrémente</p>

<br>

```c
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
            return termine("setVAl ne renvoie pas la bonne valeur ! L'indice de ligne n'est pas bon !");

        res = setVal(tmp, -1,2,7);
        if(res != 0)
            return termine("setVAl ne renvoie pas la bonne valeur ! L'indice de ligne n'est pas bon !");
        
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
```

## 6 - Fonction **test_partie1**

Permet de caculer le score des tests réalisé lors de cette partie, afin de valider les fonctions utilisé.

```c
    void test_partie1(){
        int somme = 0;
        somme += test_creer_initialiseJeu();
        somme += test_indice_valide();
        somme += test_fonction_get_val();
        somme += test_fonction_set_val();

        if(somme != 4)
            termine("TOUS LES TESTS DE LA PARTIE 1 NE SONT PAS PASSES !");
        else{
            printf("\033[32;01m#########################\n");
            printf("#   TESTS PARTIE 1 OK   #\n");
            printf("#########################\033[00m\n");
        }
    }
```

## Source

Document de test de la grille du jeu 2048 fournis par monsieur B. KHAFIF.

<style>
    .font{
        font-size: 14px !important;
    }
</style>
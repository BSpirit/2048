## 8 - Fonction **caseVide**

<br>

```c
    /*!
     *  Retourne 1 si la case est vide, 0 sinon.
     *  
     *  \param p        : pointeur sur la partie en cours
     *  \param ligne    : entier correspondant au numero de ligne
     *  \param colonne  : entier correspondant au numéro de colonne
     */
    int caseVide(jeu *p, int i, int j){
        if(getVal(p, i, j)==0)
            return 1;

        return 0;
    }
```

## 9 - Fonction **ajoutValAlea**

```c
    /*!
     *  Ajoute une valeur (2 ou 4 choisi aléatoirement) sur une case vide 
     *  (elle aussi choisi aleatoirement)
     *  
     *  \param p : pointeur sur la partie en cours
     */
    void ajouteValAlea(jeu *p){
        int ligne;
        int colonne;

        if(p->nbCasesLibres>0){
            //On génère des indices (ligne, colonne) jusqu'à tomber sur une case vide
            do{
                ligne = rand()%p->n;
                colonne = rand()%p->n;
            }while(!caseVide(p, ligne, colonne));

            // On assigne 2 ou 4 à la case sélectionnée
            if(rand()%2)
                setVal(p, ligne, colonne, 2);
            else
                setVal(p, ligne, colonne, 4);
        }
    }
```

## 10 - Fonction **gagne**

<br>

```c
    /*!
     * Retourne 1 si la partie est gagnée, 0 sinon.
     *
     *  \param p : Pointeur sur la partie en cours
     */
     int gagne(jeu *p){
        int flag = 0;
        int i = 0;// indice de ligne
        int j = 0;// indice de colonne

        //boucles imbriquées pour parcourir la grille
        while(i<p->n && flag==0){
            j = 0;
            while(j<p->n && flag==0){
                if(getVal(p, i, j)==p->valMax)
                    flag = 1;
                j++;
            }
            i++;
        }//sortie : grille entièrement parcourue ou une case de la grille a pour valeur p->valMax (flag==1)

        // flag==1 uniquement si une des cases de la grille a comme valeur p->valMax
        return flag;
    }
```

## 11 - Fonction **perdu**

<br>

```c
    /*!
     *  Retourne 1 si la partie est perdu,0 sinon.
     *
     *  \param p : Pointeur sur la partie en cours
     */
    int perdu(jeu *p){
        //S'il reste des cases libres, on n'a pas perdu
        if(p->nbCasesLibres>0)
            return 0;

        int flag = 1;
        int i = 0; //indice de ligne
        int j = 0;// indice de colonne

        //Boucles imbriquées pour parcourir la grille, on commence à la case (0,0)
        while(i<p->n && flag==1){
            j = 0;
            while(j<p->n && flag==1){
                // si on arrive à la dernière case de la grille, c'est qu'on a perdu
                if(i==p->n-1 && j==p->n-1)
                    flag = 1;
                // sinon on compare la case actuelle avec celle à droite et celle en dessous	
                else if(getVal(p, i, j)==getVal(p, i+1, j) || getVal(p, i, j)==getVal(p, i, j+1))
                    flag = 0;
                j++;
            }
            i++;
        }
        /* 
         *  sortie : grille entièrement parcourue (flag==1, on a perdu) ou
         *  deux cases adjacentes ont les mêmes valeurs (flag==0 i.e. on n'a pas encore perdu)
         */

        return flag;
    }
```

## 12 - Fonction **finPartie**

<br>

```c
    /*!
     *  Retourne 1 si la partie est terminé, 0 sinon.
     *
     *  \param p : Pointeur sur la partie en cours
     */
     int finPartie(jeu *p){
        return (perdu(p) || gagne(p));
    }
```
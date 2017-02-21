## 1 - Structure de données **Jeu**
<br>

```c
typedef struct{
	int n; //taille de la grille = n*n 
	int valMax; // valeur à atteindre pour gagner
	int nbCasesLibres; //nbre de cases libres sur la grille
	int score; //score de la partie en cours
	int *grille;
}jeu;
```


## 2 - Fonction **initialiseJeu**

<br>

```c
    /*!
     *  Alloue la grille de la variable jeu passée par adresse.
     *  Initialise les cases de la grille avec des cases vides (valeur nulles)
     *  Initialise les champs n et valMax avec les valeurs passées en paramètre 
     *
     *  \param p        : Pointeur sur une partie de 2048
     *  \param n        : Taille de la grille
     *  \param valMax   : Valeur à atteindre pour gagner
     *
     */
    void initialiseJeu(jeu *p, int n, int valMax){
        //Initialisation des variables
        p->n = n;
        p->nbCasesLibres = n*n; 
        p->valMax = valMax;
        p->score = 0;

        //allocation dynamique de la taille de la grille
        p->grille = (int*) malloc(p->nbCasesLibres*sizeof(int));
        if(p->grille==NULL){
            printf("Erreur allocation ! \n");
            exit(-1);
        }

        //Initialisation des cases de la grille à 0
        int i;
        for(i=0;i<p->nbCasesLibres;i++)
            p->grille[i] = 0;
    }
```

## 3 - Fonction **LibereMemoire**
<br>

```c
    /*!
     *  Libère la mémoire allouer pour la grille du jeu passé par adresse.
     *  
     *  \param p    : pointeur sur la partie de 2048
     */
    void libereMemoire(jeu *p){
	    free(p->grille);
    }
```

## 4 - Fonction **indiceValide**

<br>

```c
    /*!
     *  Fonction retournant 1 si la case (i, j) existe, 0 sinon.
     *
     *  \param p : Pointeur sur la partie de 2048
     *  \param i : Ligne de la case ciblé
     *  \param j : colonne de la case ciblé
     */
    int indiceValide(jeu *p, int i, int j){
	    //les indices i et j doivent être compris entre 0 (inclus) et p->n (exclus)
	    return (i>=0 && i < p->n && j>=0 && j < p->n);
    }
```

## 5 - Fonction **getVal**

<br>

```c
    /*!
     *  Fonction retournant la valeur de la case (ligne, colonne) de la partie p
     *  ou -1 si la case n'existe pas.
     *
     *  \param p        : pointeur sur la partie en cours
     *  \param ligne    : entier correspondant au numero de ligne
     *  \param colonne  : entier correspondant au numéro de colonne
     */
    int getVal(jeu *p, int ligne, int colonne){
        if(indiceValide(p, ligne, colonne))
            return p->grille[p->n*ligne+colonne];
        
        return -1;
    }
```

## 6 - Fonction **setVal**

```c
    /*!
     *  Fonction modifiant la valeur de la case (ligne, colonne) de la partie p,
     *  avec la valeur val
     *
     *  \param p        : pointeur sur la partie en cours
     *  \param ligne    : entier correspondant au numero de ligne
     *  \param colonne  : entier correspondant au numéro de colonne
     *  \param val      : entier à mettre dans la case (i,j) (si elle existe) 
     */
    int setVal(jeu *p, int ligne, int colonne, int val){
        // On verifie que l'indice est valide
        if(indiceValide(p, ligne, colonne)){
            // si la valeur de la case est identique à val, on ne fait rien
            if(getVal(p, ligne, colonne) == val)
                return 0;
            //si une ajoute une valeur à une case vide, on décrémente le nombre de cases vides
            if(caseVide(p, ligne, colonne) && val > 0)
                p->nbCasesLibres--;
            //si on vide une case, on incrémente le nombre de cases vides
            if(!caseVide(p, ligne, colonne) && val == 0 )
                p->nbCasesLibres++;
            //modification de la valeur de la case
            p->grille[p->n*ligne+colonne] = val;
            return 1;
        }

        return 0;
    }
```

## 7 - Fonction **affichage**
<br>

```c
    /*!
     *  Fonction affichant la grille à l'écran
     *  
     *  \param p : pointeur sur la partie en cours.
     */
    void affichage(jeu * p){
        clear_terminal();
        int val;

        //boucles imbriquées pour parcourir la grille
        int i;
        for(i=0;i<p->n;i++){
            //Retour chariot à la fin d'une ligne
            printf("\n");
            int j;
            for(j=0; j<p->n; j++){
                val = getVal(p, i, j);
                //Si la case est vide on l'affiche intégralement en noir
                if(val == 0)
                    color_printf(BLACK, BLACK, "       ");
                //sinon on appelle la fonction choixCouleur pour lui assigner une couleur
                else
                    color_printf(WHITE, choixCouleur(val), " %5d ", val);
            }
        }
        
        printf("\n");
        printf("Score : %d\n\n", p->score);
        
        if(gagne(p))
            printf("Vous avez gagné ! \n\n");
        else if(perdu(p))
            printf("Vous avez perdu ! \n\n");
    }
```
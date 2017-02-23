
### Auteur : *Jerent Steeve*

## 1 - Fonction **test_case_vide**

Cas de test :

1. Test case :
> <p class="font">On test une case remplie dans la grille puis une vide.</p>
2. Test case hors grille :
> <p class="font">On test une case hors de la grille. la fonction caseVide doit retourner 0.</p>
3. Test case grille remplie totalement :
> <p class="font">On fait la somme des cases remplies dans le tableau et on compare à n*n (taille de la grille)</p>
4. Test case grille vide :
> <p class="font">On fait la somme des cases vides dans le tableau et on compare à n*n (taille de la grille)</p>

<br>

```c
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
            return termine("Une case ou plusieurs cases du tableau ne sont pas vides");

        for(i=0; i<=n;i++)
            for(j=0; j<=n; j++)
                setVal(tmp, i, j, 0);
        
        somme = 0;
        for(i=0; i<n;i++)
            for(j=0; j<n; j++)
                somme += caseVide(tmp, i, j);
        
        if (somme != 16)
            return termine("Une case ou plusieurs cases sont remplies");

        libereMemoire(tmp);
        return 1;
    }
```

## 2 - Fonction **test_ajouter_val_aleatoire**
Cas de test :
1. Test ajout valeur aléatoire :
> <p class="font">On utilise la fonction ajoutValAlea puis on vérifie dans la grille si elle a bien été créée.
 On vérifie ensuite si elle a créé plusieurs valeurs aleatoires dans la grille.</p>
2. Test ajout de 2 ou 4 :
> <p class="font">On test si la fonction affectent les bonnes valeurs (2 ou 4).
Si le nombre d'essai dépasse 1000 ou s'l ne trouve qu'une des deux valeurs, on envoie une erreur</p>
3. Test apparition aléatoire:
> <p class"font">On vérifie que les valeurs aléatoires n'apparaissent pas sur la même case.</p>
3. Test grille remplie:
> <p class"font">On vérifie qu'aucune valeur n'est entrée dans une grille remplie.</p>
<br>

```c
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
            return termine("Aucune valeur aleatoire n'as été rajoutée.");

        if(compteur > 1)
            return termine("Plusieurs valeurs aleatoires ont été trouvées.");
        
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
            return termine("Un valeur a été rajoutée aleatoirement alors que la grille est remplie");
        libereMemoire(tmp);
        return 1;
    }
```

## 3 - Fonction **test_gagne**
Cas de test :
- On vérifie que la fonction gagne retourne 1 quand la valeur vMax est atteinte, sinon 0.

<br>

```c
    int test_gagne(){
        int n = 4;
        int vMax = 2048;
        
        jeu jeu_test;

        jeu * tmp = &jeu_test;

        initialiseJeu(tmp, n, vMax);

        // Si la valeur est égale à vMax
        setVal(tmp, 1,1, 2048);
        int res = gagne(tmp);
        if(res != 1)
            return termine("La valeurs set devaient permettre de gagner.");
        
        // si la valeur est inférieure à vMax
        setVal(tmp, 1,1, 1024);
        res = gagne(tmp);
        if(res != 0)
            return termine("La valeur 2048 a été modifiée par 1024, donc il est impossible de gagner.");
        
        // Si la valeur est strictement supérieure à vMax
        setVal(tmp, 1, 1, 2049);
        res = gagne(tmp);
        if(res != 1)
            return termine("La valeurs set devaient permettre de gagner.");
                
        libereMemoire(tmp);
        return 1;    
    }
```

## 4 - Fonction **test_perdu**
Cas de test :
- On vérifie que la fonction perdu retourne 1 quand aucun mouvement n'est possible, sinon 0.

```c
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
            return termine("La partie devrait être perdue");
        
        setVal(tmp, 1, 1, 2);

        res = perdu(tmp);
        if(res != 0)
            return termine("1 - La partie devrait continuer");
        
        setVal(tmp, 0, 0, 2);
        setVal(tmp, 0, 1, 4);
        setVal(tmp, 1, 1, 4);
        res = perdu(tmp);
        if(res != 0)
            return termine("2 - La partie devrait continuer");
        libereMemoire(tmp);
        return 1;
    }
```

## 5 - Fonction **test_finPartie**
Cas de test
- On set la valeur max dans la grille
- On remplace la valeur max ajoutée par une valeur inférieure à vMax
- On fini de remplir la grille afin que l'utilisateur ne puisse pas effectuer de mouvement

<br>

```c
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
        
        setVal(tmp, 0, 0, 1025);
        setVal(tmp, 1, 0, 1022);
        setVal(tmp, 0, 1, 1023);
        res = finPartie(tmp);

        if (res != 1)
            return termine("La partie n'est plus jouable.");

        libereMemoire(tmp);
        return 1;
    }
```

## 6 - Fonction **test_partie2**
On calcule la somme des tests de la partie 2.

```c
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
```

<style>
    .font{
        font-size: 14px !important;
    }
</style>

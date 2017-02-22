
Auteur : *Jerent Steeve*

## 1 - Fonction **test_case_vide**

Cas de test :

1. Test case :
> <p class="font">On test une case rempli dans la grille puis une vide.</p>
2. Test case hors grille :
> <p class="font">On test une case hors de la grille. la fonction caseVide doit retourner 0.</p>
3. Test case grille rempli totalement :
> <p class="font">On a fait la somme des case remplis dans le tableau le comparer à n*n</p>
4. Test case grille vide :
> <p class="font">On a fait la somme des case vides dans le tableau le comparer à n*n</p>

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

        libereMemoire(tmp);
        return 1;
    }
```

## 2 - Fonction **test_ajouter_val_aleatoire**
Cas de test :
1. Test ajout valeur aléatoire :
> <p class="font">On utilise la fonction ajouteValAlea puis on vérifie dans la grille, <br> si elle a bien été créée et on détermine si elle n'a pas créé plusieurs valeurs aleatoires dans la grille.</p>
2. Test ajout de 2 ou 4 :
> <p class="font">On test si la fonction retourne la valeur 2 ou 4, <br> si le nombre d'essaie dépasse 1000 ou si il ne trouve qu'une des deux valeur on envoie une erreur</p>
3. Test apparition aléatoire:
> <p class"font">On vérifie que les valeurs aléatoires n'apparaissent pas sur la même cases.</p>
3. Test grille rempli:
> <p class"font">On vérifie qu'aucune valeur n'est rentrer dans une grille rempli.</p>
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
        libereMemoire(tmp);
        return 1;
    }
```

## 3 - Fonction **test_gagne**
Cas de test :
- On vérifie la fonction gagne retourne soit 1 quand la valeur vMax est atteinte, sinon 0.

<br>

```c
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
        libereMemoire(tmp);
        return 1;    
    }
```

## 4 - Fonction **test_perdu**
Cas de test :
- On vérifie la fonction gagne retourne soit 1 quand la valeur vMax est atteinte, sinon 0 permettant de continuer la partie.

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
        libereMemoire(tmp);
        return 1;
    }
```

## Fonction **test_finPartie**
Cas de test
```c
```
```c
```
```c
```
```c
```
<style>
    .font{
        font-size: 14px !important;
    }
</style>

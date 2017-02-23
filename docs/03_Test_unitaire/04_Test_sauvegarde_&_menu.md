### Auteur : Jerent Steeve

## 1 - Fonction **test_sauvegarde**

```c
    int test_sauvegarde(){
        int n = 4;
        // 418 est la valeur max pour lancer les tests en sauvegardeJeu
        // Histoire : 418 est un code de status http créer par google, pour rire.
        // signifiant "I'm a teapot" =>  "Je suis une théière"
        int res;
        int vMax = 418;
        jeu jeu_test;
        jeu * tmp = &jeu_test;
        initialiseJeu(tmp, n, vMax);
        
        
        ajouteValAlea(tmp);
        ajouteValAlea(tmp);
        ajouteValAlea(tmp);
        ajouteValAlea(tmp);
        // on crée un fichier de sauvegarde
        res = sauvegardeJeu(tmp);
        remove("./Saves/test_Iam_a_teampot.bin");
        if(res != 1)
            return termine("La sauvegarde n'a pas été créée. Ou vous avez couper le dernier test de manière brutale.");
        res = sauvegardeJeu(tmp);
        int essaie = 1;
        // on vérifie le cas ou le choix [n|N] ne fonctionnerais pas
        do{
            printf("\033[33;01mSaisir 'n' ou 'N' pour valider la suppression\n\033[31;01mEssaie : (%d/3)\033[00m\n", essaie);
            res = sauvegardeJeu(tmp);
            essaie++;
        }while  (essaie<=3 && res != 0);

        // La supression du fichier n'est pas faite pour exécuter le test_chargement
        if(essaie > 3)
            return termine("Le nombre de tentative est dépassé. le choix [n|N] ne fonctionne pas");
        
        return 1;
    }
```

## 2 - Fonction **test_chargement**

```c
    int test_chargement(){
        int n = 4;
        int res;
        int vMax = 418;
        jeu jeu_test;
        jeu * tmp = &jeu_test;
        initialiseJeu(tmp, n, vMax);

        // on charge le fichier de sauvegarde pour les test ./Saves/test_Iam_a_teampot.bin
        res = chargementJeu(tmp);

        if(res != 1)
            return termine("Le chargement n'as pas pu être effectuer");
        
        // Supression du fichier de sauvegarde pour les tests
        remove("./Saves/test_Iam_a_teampot.bin");
        res = chargementJeu(tmp);

        if(res != 0)
            return termine("Le chargement ne devait pas être réaliser après supression du fichier de sauvegarde");

        return 1;
    }
```

## 3 - Fonction **test_menu**

```c
    int test_menu(){
        // Test special : on fait le testeur rentrer
        // chaque valeur pour voir si elle coresponde
        int i=1, choix;

        do{
            printf("\033[33;01mEntrer le chiffre 1 et valider avec Entrer\n\033[31;01mEssaie : (%d/3)\033[00m\n", i);
            choix = menu();
            i++;
        }while(i<=3 && choix != 1);
        
        if(i>3)
            return termine("Saisie échouer");
        
        i=1;
        do{
            printf("\033[33;01mEntrer le chiffre 2 et valider avec Entrer\n\033[31;01mEssaie : (%d/3)\033[00m\n", i);
            choix = menu();
            i++;
        }while(i<=3 && choix != 2);
        
        if(i>3)
            return termine("Saisie échouer");
        
        i=1, choix;
        do{
            printf("\033[33;01mEntrer le chiffre 3 et valider avec Entrer\n\033[31;01mEssaie : (%d/3)\033[00m\n", i);
            choix = menu();
            i++;
        }while(i<=3 && choix != 3);
        
        if(i>3)
            return termine("Saisie échouer");
        
        i=1, choix;
        do{
            printf("\033[33;01mEntrer le chiffre 4 et valider avec Entrer\n\033[31;01mEssaie : (%d/3)\033[00m\n", i);
            choix = menu();
            i++;
        }while(i<=3 && choix != 4);
        
        if(i>3)
            return termine("Saisie échouer");
        
        i=1, choix;
        do{
            printf("\033[33;01mEntrer le chiffre 5 et valider avec Entrer\n\033[31;01mEssaie : (%d/3)\033[00m\n", i);
            choix = menu();
            i++;
        }while(i<=3 && choix != 5);
        
        if(i>3)
            return termine("Saisie échouer");
        
        i=1, choix;
        do{
            printf("\033[33;01mEntrer le chiffre 6 et valider avec Entrer\n\033[31;01mEssaie : (%d/3)\033[00m\n", i);
            choix = menu();
            i++;
        }while(i<=3 && choix != 6);
        
        if(i>3)
            return termine("Saisie échouer");
        
        return 1;
    }

```

## 4 - Fonction **test_partie4**

```c
    void test_partie4(){
        int somme = 0;
        somme += test_sauvegarde();
        somme += test_chargement();
        somme += test_menu();
        

        if(somme != 3)
            termine("TOUS LES TESTS DE LA PARTIE 4 NE SONT PAS PASSES !");
        else{
            printf("\033[32;01m#########################\n");
            printf("#   TESTS PARTIE 4 OK   #\n");
            printf("######################### \033[00m\n");
        }
    }
```
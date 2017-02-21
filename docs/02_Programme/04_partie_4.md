## 20 - Fonction **sauvegardeJeu**

<br>

```c
/*! * Fonction sauvegardant la partie en cours
    * Retourne 0 en cas de problème ou si l'utilisateur annule
    * Retourne 1 sinon
    *
    * \param p : pointeur sur la partie en cours
    */
int sauvegardeJeu(jeu *p){
    FILE *f;
	char nomF[20];//Stock le nom du fichier à sauvegarder
	char saisie;

    //On demande à l'utilisateur de choisir un slot de sauvegarde
	printf("Veuillez choisir un slot de sauvegarde [1/2/3] [0 pour annuler] \n");
	do{
		scanf("%c", &saisie);
	}while(saisie!= '1' && saisie!='2' && saisie!='3' && saisie!='0');

    if(saisie=='0')
        return 0;

    //Assigne un fichier à nomF en fonction du slot choisi
	if(saisie=='1')
			strcpy(nomF, "./Saves/Save1.bin");
	if(saisie=='2')
			strcpy(nomF, "./Saves/Save2.bin");
	if(saisie=='3')
			strcpy(nomF, "./Saves/Save3.bin");

    //On test l'existance du fichier, s'il existe on demande à l'utilisateur s'il souhaite l'écraser
    f = fopen(nomF, "r");
	if(!(f==NULL)){
		printf("Une sauvegarde existe déjà, voulez vous l'écraser ?[o/n]\n");
		do{
			scanf("%c", &saisie);
		}while(saisie!='o' && saisie!='n' && saisie!='O' && saisie!='N');
        //S'il ne souhaite pas l'écraser, on ferme le fichier et retourne 0
		if(saisie=='n' || saisie=='N'){
			fclose(f);
			return 0;
		}
	}

    //Sinon on sauvegarde
	f = fopen(nomF, "wb");

    if(f==NULL){
        printf("Erreur de fopen \n");
        return 0;
    }

	fwrite( &p->n , sizeof(int) , 1 , f);
	fwrite( &p->valMax , sizeof(int) , 1 , f);
	fwrite( &p->nbCasesLibres , sizeof(int) , 1 , f);
    fwrite( &p->score, sizeof(int), 1, f);
	fwrite( p->grille, sizeof(int), p->n*p->n, f);

    fclose(f);

    //Retourne 1 si sauvegarde effectuée
    return 1;
}
```

## 21 - Fonction **chargementJeu**

<br>

```c
/*! * Fonction chargeant la dernière partie sauvegardée
    * Retourne 0 en cas de problème et si la sauvegarde n'existe pas
    * Retourne 1 sinon
    *
    * \param p : pointeur sur la partie en cours
    */
int chargementJeu(jeu *p){
    FILE *f;
	char nomF[20];
	char saisie;

    //On demande à l'utilisateur quelle sauvegarde il souhaite charger
	printf("Veuillez choisir un slot de sauvegarde à charger [1/2/3] [0 pour annuler] \n");
	do{
		scanf("%c", &saisie);
	}while(saisie!= '1' && saisie!='2' && saisie!='3' && saisie!='0');

    if(saisie=='0')
        return 0;

    //Assigne un fichier à nomF en fonction du slot choisi
	if(saisie=='1')
			strcpy(nomF, "./Saves/Save1.bin");
	if(saisie=='2')
			strcpy(nomF, "./Saves/Save2.bin");
	if(saisie=='3')
			strcpy(nomF, "./Saves/Save3.bin");

    //On test l'existance du fichier, s'il n'existe pas on retourne 0
	f = fopen(nomF, "rb");
    if(f==NULL)
        return 0;

    //Sinon on charge la sauvegarde
	fread( &p->n , sizeof(int) , 1 , f);
	fread( &p->valMax , sizeof(int) , 1 , f);
	fread( &p->nbCasesLibres , sizeof(int) , 1 , f);
    fread( &p->score, sizeof(int), 1, f);

    //On refait une allocation de la grille, dont la taille peut avoir changée
    p->grille = (int*)malloc((p->n*p->n)*sizeof(int));

	fread(p->grille, sizeof(int), p->n*p->n, f);

    fclose(f);

    //Retourne 1 si chargement effectué
    return 1;
}
```

## 22 - Fonction **menu**

<br>

```c
/*! * Affiche le menu :
    * 1 - Créer nouvelle partie
    * 2 - Jouer
    * 3 - Sauvegarder
    * 4 - Charger
    * 5 _ Afficher scores
    * 6 - Quitter
    * Retourne la valeur saisie par l'utilisateur
    */
int menu(){
    int choix;

    printf("\n");
    printf("1 - Créer nouvelle partie \n");
    printf("2 - Jouer \n");
    printf("3 - Sauvegarder \n");
    printf("4 - Charger \n");
    printf("5 - Afficher scores \n");
    printf("6 - Quitter \n");
    printf("\n");

    do{
        scanf("%d", &choix);
    }while(choix!=1 && choix!=2 && choix!=3 && choix!=4 && choix!=5 && choix!=6);

    return choix;
}
```

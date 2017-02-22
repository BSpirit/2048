#### Auteur : *Tony Clonier*

## Introduction
<br>
<p>Dans cette partie, nous allons tenter d'expliquer la décomposition fonctionnelle du programme.</p>

## 1 - Analyse fonctionnelle
<br>
<p>Les règles du jeu peuvent nous aider à identifier les principaux besoins fonctionnels :
<ul>
    <li> Créer et initialiser la grille de jeu</li>
    <li> Jouer au jeu </li>
    <li> Sauvegarder une ou plusieurs parties </li>
    <li> Charger les parties sauvegardées </li>
</ul></p>

### 1.1. La grille de jeu
<br>
<p> Les règles du jeu peuvent nous aider à définir les variables nécessaires à la définition de la grille.
Pour faciliter l'utilisation des ces variables et le passage par référence, ces variables sont stockées dans une structure nommée "jeu" définie ci-dessous</p>

```c
typedef struct{
	int n; //taille de la grille = n*n 
	int valMax; // valeur à atteindre pour gagner
	int nbCasesLibres; //nbre de cases libres sur la grille
	int score; //score de la partie en cours
	int *grille;
}jeu;
```
<p> 

<p> La taille de la grille n'est pas fixée, d'où l'utilisation d'une variable n et la nécessité d'allouer la mémoire de manière dynamique.
 La fonction initialiseJeu permet de créer la grille et d'initialiser ses variables. La fonction libereMemoire permet de libérer la mémoire réservée pour l'utilisation
 de la grille. </p>
<p> D'un point de vue conceptuel, la grille possède 2 dimensions (des lignes et des colonnes) et est composée de tuiles ayant une valeur variable.
Pour faciliter l'accès à ces valeurs, il est nécessaire de créer les fonctions getVal et setVal. Les fonctions indiceValide et caseVide permettent
des tests sur les tuiles de la grille.</p>
<p> Les fonctions affichage et choixCouleur permettent d'afficher la grille sur le terminal</p>
<p> Le code de ces fonctions est défini dans le fichier <strong>grille.c</strong> .</p>

### 1.2. Jouer au jeu
<br>
<p> Pour jouer au jeu, il est nécessaire de connaître les conditions de victoire et de défaite.
Les fonctions gagne, perdu et finPartie permettent de tester ces conditions.
La fonction ajouteValAlea permet d'ajouter une valeur sur la grille à chaque tour.
La fonction jouer permet de jouer au jeu en lui même.
Pour jouer au jeu, il est nécessaire de pouvoir en déplacer les tuiles. Pour ce faire, l'utilisateur doit pouvoir intéragir avec le programme. 
Cette intéraction se fait avec les touches du clavier.</p>
<p> Le code de ces fonctions est défini dans les fichiers <strong>partie.c</strong> et <strong>mouvement.c</strong>.</p>

### 1.3. Sauvegarder et charger une partie
<br>
<p> Il ne serait pas pertinent de ne pas pouvoir reprendre une partie en cours si interruption du programme, 
d'où la nécessité d'ajouter des fonctionnalités de sauvegarde/chargement.
Lors de la sauvegarde, les valeurs des variables définissant la structure "jeu" sont enregistrées dans un fichier.
Un fichier correspond à une sauvegarde de jeu (3 sauvegardes possibles).Les scores sont enregistrés dans un fichier séparé.
Pour que l'utilisateur ne puisse pas changer les valeurs des variables enregistrées et faire buguer le programme, les valeurs sont sauvegardées dans des fichiers binaires.</p>
<p> L'utilisation d'un menu permet de faciliter la navigation entre les fonctionnalités du programme.</p>
<p> Le code de ces fonctions est défini dans le fichier <strong>sauvegarde.c</strong> .</p>
<br>

## 2 - Répartition des tâches

<ul>
    <li> Réalisation des fonctions du jeu : Tony Clonier </li>
    <li> Réalisation de tous les tests unitaires : Steeve Jerent </li>
    <li> Création de la documentation : Steeve Jerent et Tony Clonier </li>
</ul>




//  Created by Bouchaib KHAFIF on 14/09/2015.
//  Copyright (c) 2015 Bouchaib KHAFIF. All rights reserved.
//
//  main.cpp
//  test_integration_calculateur
//

/**
 * Cette fonction calcule le score pour un test
 * A NE PAS MODIFIER
 */

int assertion(string refTest, double resObtenu, double resAttendu){

    double diff = resObtenu-resAttendu;

    if (diff<0)
        diff *= -1;

    if (diff>0.000000001){
        affichage(refTest,":","FAIL !\n");
        return 0;
    }
    return 1;
}
/*
 ########################################################
 ########################################################
 */


/*
 ########################################################
  COPIEZ ICI LE CODE DES FONCTIONS somme, soustraction,
  multiplication, puissance DEJA TESTEES AVEC LES 
  TESTS UNITAIRES
 ########################################################
 */


/*
 ########################################################
 ########################################################
*/

/*! double calculateur(char operation, int parX, int parY)
 * Calculateur
 * \param operation : char opération que le calculateur doit effectuer
 * \param parX : int première operande
 * \param parY : int deuxième opérande
 *
 * La valeur retournée correspond au résultat du calcul
 * effectué par le calculateur.
 *
 * IMPORTANT : La fonction retourne 0 si l'opération n'existe pas
 */

/*
 ########################################################
  C'EST ICI QUE VOUS DEVELOPPEZ LA FONCTION DEMANDEE
 ########################################################
 */






/*
 ########################################################
 ########################################################
 
 LA FONCTION main CONTIENT LES TESTS UNITAIRES
 
 COMPRENDRE LE CONTENU MAIS NE PAS Y TOUCHER !!!!
 
 ########################################################
 ########################################################
 */

int main() 
{
    /**
     * Valeurs effectives pour les paramètres de la fonctions
     */
    int testParX;
    int testParY;

    /**
     * Résultat obtenu par la fonction
     */
    double resObtenu;

    /**
     * Résultat attentdu
     */
    double resAttendu;

    /**
     * Référence du test
     */
    string refTest;

    /**
     * Scores
     */
    int score = 0 ; // Score courant
    int nbTotalTest = 20; // Nombre total de tests


    /**
     * Ref test : 5A
     * Test  d'intégration de la fonction calculateur
     */
    refTest = "5A";
    testParX = 3;
    testParY =  4;
    resAttendu = 7;
    resObtenu = calculateur('a',testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);

    /**
     * Ref test : 5B
     * Test  d'intégration de la fonction calculateur
     */
    refTest = "5B";
    testParX = -3;
    testParY =  2;
    resAttendu = -1;
    resObtenu = calculateur('A',testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);

    /**
     * Ref test : 5C
     * Test  d'intégration de la fonction calculateur
     */
    refTest = "5C";
    testParX = 0;
    testParY =  0;
    resAttendu = 0;
    resObtenu = calculateur('a',testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);

    /**
     * Ref test : 5D
     * Test  d'intégration de la fonction calculateur
     */
    refTest = "5D";
    testParX = -10;
    testParY =  -2;
    resAttendu = -12;
    resObtenu = calculateur('a', testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);


    /**
     * Ref test : 5E
     * Test  d'intégration de la fonction calculateur
     */
    refTest = "5E";
    testParX = 3;
    testParY =  4;
    resAttendu = 81;
    resObtenu = calculateur('p', testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);

    /**
     * Ref test : 5F
     * Test  d'intégration de la fonction calculateur
     */
    refTest = "5F";
    testParX = 3;
    testParY =  0;
    resAttendu = 1;
    resObtenu = calculateur('p',testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);

    /**
     * Ref test : 5G
     * Test  d'intégration de la fonction calculateur
     */
    refTest = "5G";
    testParX = 0;
    testParY =  0;
    resAttendu = 1;
    resObtenu = calculateur('P',testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);

    /**
     * Ref test : 5H
     * Test  d'intégration de la fonction calculateur
     */
    refTest = "5H";
    testParX = 10;
    testParY =  -2;
    resAttendu = 0.01;
    resObtenu = calculateur('P',testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);

    /**
     * Ref test : 5I
     * Test  d'intégration de la fonction calculateur
     */
    refTest = "5I";
    testParX = 2;
    testParY =  -3;
    resAttendu = 0.125;
    resObtenu = calculateur('p',testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);



    /**
     * Ref test : 5J
     * Test  d'intégration de la fonction calculateur
     */
    refTest = "5J";
    testParX = 3;
    testParY =  4;
    resAttendu = -1;
    resObtenu = calculateur('s',testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);

    /**
     * Ref test : 5K
     * Test  d'intégration de la fonction calculateur
     */
    refTest = "5K";
    testParX = -3;
    testParY =  2;
    resAttendu = -5;
    resObtenu = calculateur('S',testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);

    /**
     * Ref test : 5L
     * Test  d'intégration de la fonction calculateur
     */
    refTest = "5L";
    testParX = 0;
    testParY =  0;
    resAttendu = 0;
    resObtenu = calculateur('S',testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);

    /**
     * Ref test : 5M
     * Test  d'intégration de la fonction calculateur
     */
    refTest = "5M";
    testParX = -10;
    testParY =  -2;
    resAttendu = -8;
    resObtenu = calculateur('s', testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);


    /**
     * Ref test : 5N
     * Test  d'intégration de la fonction calculateur
     */
    refTest = "5N";
    testParX = 3;
    testParY =  4;
    resAttendu = 12;
    resObtenu = calculateur('M', testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);

    /**
     * Ref test : 5O
     * Test  d'intégration de la fonction calculateur
     */
    refTest = "5O";
    testParX = 3;
    testParY =  0;
    resAttendu = 0;
    resObtenu = calculateur('M', testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);

    /**
     * Ref test : 5P
     * Test  d'intégration de la fonction calculateur
     */
    refTest = "4P";
    testParX = 0;
    testParY =  0;
    resAttendu = 0.0;
    resObtenu = calculateur('m', testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);

    /**
     * Ref test : 5Q
     * Test  d'intégration de la fonction calculateur
     */
    refTest = "5Q";
    testParX = 10;
    testParY =  -2;
    resAttendu = -20;
    resObtenu = calculateur('m', testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);

    /**
     * Ref test : 5R
     * Test  d'intégration de la fonction calculateur
     */
    refTest = "5R";
    testParX = -2;
    testParY =  3;
    resAttendu = -6;
    resObtenu = calculateur('M', testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);


    refTest = "5S";
    testParX = -20;
    testParY = -30;
    resAttendu = 600;
    resObtenu = calculateur('M', testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);
 

    refTest = "5T";
    testParX = -20;
    testParY = -30;
    resAttendu = 0;
    resObtenu = calculateur('F', testParX, testParY);
    score+=assertion(refTest, resObtenu, resAttendu);


    affichage("Score : ",score, " sur ", nbTotalTest,'\n');

    return 0;
}





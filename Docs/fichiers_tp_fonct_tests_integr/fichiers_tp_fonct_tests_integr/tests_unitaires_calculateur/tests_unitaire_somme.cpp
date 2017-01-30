//  Created by Bouchaib KHAFIF on 14/09/2015.
//  Copyright (c) 2015 Bouchaib KHAFIF. All rights reserved.
//
//  tests_unitaire_somme.cpp
//  Tests unitaires pour la fonction somme
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

/*! int somme(int parX, int parY)
 * Calcule la somme de x et y
 * \param parX : int premier entier
 * \param parY : int second entier
 * La valeur retournée correspond au résultat du calcul
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
   * Valeurs effectives pour les paramètres de la fonction
   */
  int testParX;
  int testParY;

  /**
   * Résultat obtenu par la fonction
   */
  double resObtenu;


  /**
   * Résultat attendu
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
  int nbTotalTest = 4; // Nombre total de tests




  /**
   * Ref test : 1A
   * Test  unitaire de la fonction somme
   */
  refTest = "1A";
  testParX = 3;
  testParY = 4;
  resAttendu = 7;
  resObtenu = somme(testParX, testParY);
  score += assertion(refTest, resObtenu, resAttendu);

  /**
   * Ref test : 1B
   * Test  unitaire de la fonction somme
   */
  refTest = "1B";
  testParX = -3;
  testParY = 2;
  resAttendu = -1;
  resObtenu = somme(testParX, testParY);
  score += assertion(refTest, resObtenu, resAttendu);

  /**
   * Ref test : 1C
   * Test  unitaire de la fonction somme
   */
  refTest = "1C";
  testParX = 0;
  testParY = 0;
  resAttendu = 0;
  resObtenu = somme(testParX, testParY);
  score += assertion(refTest, resObtenu, resAttendu);

  /**
   * Ref test : 1D
   * Test  unitaire de la fonction somme
   */
  refTest = "1D";
  testParX = -10;
  testParY = -2;
  resAttendu = -12;
  resObtenu = somme(testParX, testParY);
  score += assertion(refTest, resObtenu, resAttendu);

  affichage("Score : ", score, " sur ", nbTotalTest, '\n');

  return 0;
}



//  Created by Bouchaib KHAFIF on 14/09/2015.
//  Copyright (c) 2015 Bouchaib KHAFIF. All rights reserved.
//
//  tests_unitaire_soustraction.cpp
//  Tests unitaires pour la fonction soustraction
//

/**
 * Cette fonction calcule le score pour un test
 * A NE PAS MODIFIER
 */

int assertion(string refTest, double resObtenu, double resAttendu){

  double diff = resObtenu - resAttendu;

  if (diff < 0)
    diff *= -1;

  if (diff > 0.000000001)
  {
    affichage(refTest, ":", "FAIL !\n");
    return 0;
  }
  return 1;
}
/*
 ########################################################
 ########################################################
 */

/*! int soustraction(int parX, int parY)
 * Calcule la soustraction de de x et y
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
  int nbTotalTest = 4; // Nombre total de tests


  /**
   * Ref test : 3A
   * Test  unitaire de la fonction soustraction
   */
  refTest = "3A";
  testParX = 3;
  testParY = 4;
  resAttendu = -1;
  resObtenu = soustraction(testParX, testParY);
  score += assertion(refTest, resObtenu, resAttendu);

  /**
   * Ref test : 3B
   * Test  unitaire de la fonction soustraction
   */
  refTest = "3B";
  testParX = -3;
  testParY = 2;
  resAttendu = -5;
  resObtenu = soustraction(testParX, testParY);
  score += assertion(refTest, resObtenu, resAttendu);

  /**
   * Ref test : 3C
   * Test  unitaire de la fonction soustraction
   */
  refTest = "3C";
  testParX = 0;
  testParY = 0;
  resAttendu = 0;
  resObtenu = soustraction(testParX, testParY);
  score += assertion(refTest, resObtenu, resAttendu);

  /**
   * Ref test : 3D
   * Test  unitaire de la fonction soustraction
   */
  refTest = "3D";
  testParX = -10;
  testParY = -2;
  resAttendu = -8;
  resObtenu = soustraction(testParX, testParY);
  score += assertion(refTest, resObtenu, resAttendu);

  affichage("Score : ", score, " sur ", nbTotalTest, '\n');

  return 0;
}



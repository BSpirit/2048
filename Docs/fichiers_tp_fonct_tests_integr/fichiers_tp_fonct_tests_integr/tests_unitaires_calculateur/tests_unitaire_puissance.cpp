//  Created by Bouchaib KHAFIF on 14/09/2015.
//  Copyright (c) 2015 Bouchaib KHAFIF. All rights reserved.
//
//  test_puissance.cpp
//  TP_Test
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

/*! double puissance(int parX, int parY)
 * Calcule la puissance de de x par y
 * \param parX : int un entier
 * \param parY : int puissance
 * La valeur retournée correspond au résultat du calcul
 *
 * IMPORTANT : Le calcul se fera en utilisant la
 * fonction multiplication développé précédemment,
 * par contre l'opérateur / (division) pour être utilisé
 *
 */


/*
 ########################################################
  C'EST ICI QUE VOUS DEVELOPPEZ LA FONCTION DEMANDEE
 ########################################################
 */



/*
 ########################################################
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
  int nbTotalTest = 5; // Nombre total de tests

  /**
   * Ref test : 4A
   * Test  unitaire de la fonction somme
   */
  refTest = "4A";
  testParX = 3;
  testParY = 4;
  resAttendu = 81;
  resObtenu = puissance(testParX, testParY);
  score += assertion(refTest, resObtenu, resAttendu);

  /**
   * Ref test : 4B
   * Test  unitaire de la fonction somme
   */
  refTest = "4B";
  testParX = 3;
  testParY = 0;
  resAttendu = 1;
  resObtenu = puissance(testParX, testParY);
  score += assertion(refTest, resObtenu, resAttendu);

  /**
   * Ref test : 4C
   * Test  unitaire de la fonction somme
   */
  refTest = "4C";
  testParX = 0;
  testParY = 0;
  resAttendu = 1;
  resObtenu = puissance(testParX, testParY);
  score += assertion(refTest, resObtenu, resAttendu);

  /**
   * Ref test : 4D
   * Test  unitaire de la fonction somme
   */
  refTest = "4D";
  testParX = 10;
  testParY = -2;
  resAttendu = 0.01;
  resObtenu = puissance(testParX, testParY);
  score += assertion(refTest, resObtenu, resAttendu);

  /**
   * Ref test : 4E
   * Test  unitaire de la fonction somme
   */
  refTest = "4E";
  testParX = 2;
  testParY = -3;
  resAttendu = 0.125;
  resObtenu = puissance(testParX, testParY);
  score += assertion(refTest, resObtenu, resAttendu);


  affichage("Score : ", score, " sur ", nbTotalTest, '\n');

  return 0;
}



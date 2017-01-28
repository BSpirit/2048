/*! * int caseVide(jeu *p, int i, int j)
	* 
	* Retourne 1 si la case (i,j) est vide
	* Retourne 0 sinon
	* 
 	* \param p : pointeur sur la partie en cours
	* \param i : entier correspondant au numéro de ligne
	* \param j : entier correspondant au numéro de colonne
	*/	
int caseVide(jeu *p, int i, int j){
	if(indiceValide(p, i, j)){
		if(getVal(p, i, j)==0)
			return 1;
	}
	
	return 0;
}	

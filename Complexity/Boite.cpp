//
//  Boite.cpp
//  Complexity
//
//  Created by Guillaume Rahbari on 29/12/2014.
//  Copyright (c) 2014 Guillaume Rahbari. All rights reserved.
//

#include "Boite.h"

/*! 
 * \param largeur largeur.
 * \param hauteur hauteur.
 */

int NBR = 1; 

Boite::Boite(int largeur, int hauteur) 
	: _largeur(largeur), _hauteur(hauteur), _boite(4*hauteur+2, 4*largeur+2, " ")
{
	for (int colonnes = 0; colonnes < 4*largeur+2; ++colonnes)
	{
		_boite(0,colonnes) = '#'; 
	}
	for (int lignes = 1; lignes < 4*hauteur+2; ++lignes)
	{
		_boite(lignes,0) = '#'; 
		_boite(lignes,4*largeur+1) = '#'; 
	}
	for (int colonnes = 0; colonnes < 4*largeur+2; ++colonnes)
	{
		_boite(4*hauteur + 1,colonnes) = '#'; 
	}
}

/*!
 * \param rect rectangle.
 */
void Boite::add (const Rectangle& rect) {
	string aux = to_string(NBR%9);
	for (int j = 1; j < 4*rect.hauteur() + 1; ++j)
	{
		for (int i = 0; i < 4*rect.largeur(); ++i)
		{
			_boite(j,1+i) = aux;
		}
	}
}

/*!
 * On affiche la boite.
 *
 * \param[in,out] os l'output stream.
 * \param[in] boite la boite a afficher.
 */

ostream& operator<<(ostream& os, Boite boite) {
os << boite._boite;
return os;
}
/*!
 * Ecris n fois la lettre *(asterisque).
 * 
 * \param  n le nombre de *.
 * \return Une chaine de caractère contenant n #.
 */
string Boite::printAsterisque(int n) const{
	string diez = "";
	for (int i = 0; i < n; ++i)
	{
		diez+="*";
	}
	return diez;
}

/*!
 * Ecris n fois un espace.
 * 
 * \param  n le nombre d'espaces'.
 * \return Une chaine de caractère contenant n espaces.
 */
string Boite::printSpace(int n) const{
	string space = "";
	for (int i = 0; i < n; ++i)
	{
		space+=" ";
	}
	return space;
}
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
Boite::Boite(int largeur, int hauteur) 
	: _largeur(largeur), _hauteur(hauteur), _boite(4*hauteur, 4*largeur, ' ')
{
	for (int colonnes = 0; colonnes < 4*largeur; ++colonnes)
	{
		_boite(0,colonnes) = '#'; 
	}
	for (int lignes = 1; lignes < 4*hauteur-1; ++lignes)
	{
		_boite(lignes,0) = '#'; 
		_boite(lignes,4*largeur-1) = '#'; 
	}
	for (int colonnes = 0; colonnes < 4*largeur; ++colonnes)
	{
		_boite(4*hauteur-1,colonnes) = '#'; 
	}
}

/*!
 * \param rect rectangle.
 */
void Boite::add (const Rectangle& rect) {
	
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
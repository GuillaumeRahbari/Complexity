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
Boite::Boite(int largeur, int hauteur) : _largeur(largeur), _hauteur(hauteur){}

/*!
 * Ajoute un rectangle directement a la fin du vecteur.
 * \param rect rectangle.
 */
void Boite::add (const Rectangle& rect)
{
	_boite.push_back(rect);
}

/*!
 * On affiche la boite.
 *
 * \param[in,out] os l'output stream.
 * \param[in] boite la boite a afficher.
 */
ostream& operator<<(ostream& os, Boite boite) {
	for_each (boite._boite.begin(), boite._boite.end(), [&os](Rectangle rect){
		os << rect << endl;
	});
	return os;
}
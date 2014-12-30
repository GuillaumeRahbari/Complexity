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
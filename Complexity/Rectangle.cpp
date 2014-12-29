//
//  Rectangle.cpp
//  Complexity
//
//  Created by Guillaume Rahbari on 29/12/2014.
//  Copyright (c) 2014 Guillaume Rahbari. All rights reserved.
//

#include "Rectangle.h"

/*! 
 * \param largeur largeur
 * \param hauteur hauteur
 */
Rectangle::Rectangle(int largeur, int hauteur) : _largeur(largeur), _hauteur(hauteur){}

/*!
 * On lit quelque chose de la forme largeurxhauteur. Le séparateur
 * doit etre \c 'x'.
 *
 * Si on ne peut pas lire le premier champs (la largeur), alors on a certainement atteint la fin de fichier
 * (ou une IO erreur). Dans l'autre cas, si on ne peut pas lire la hauteur,
 * separee par x, on leve une exception. Si la lecture est un success, on appelle
 * le constructeur de Rectangle.
 *
 * \param[in,out] is l'input stream.
 * \param[out] rect le rectangle a lire.
 * \throw Invalid_Input dans le cas d'un format incorrect.
 */
istream& operator>>(istream& is, Rectangle& rect) {
	int largeur;
	int hauteur;
	char sep;

	if (is >> largeur)
	{
		if (is >> sep >> hauteur)
		{
			if (sep != 'x')
				throw Rectangle::Invalid_Input();
			rect = Rectangle(largeur, hauteur);
		}
		else
			throw Rectangle::Invalid_Input();
	}
	return is;
}
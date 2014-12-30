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
 * On affiche le rectangle dans le format 'largeur x hauteur'.
 *
 * \param[in,out] os l'output stream.
 * \param[in] rect le rectangle a afficher.
 */
ostream& operator<<(ostream& os, Rectangle rect) {
	os << rect._largeur << 'x' << rect._hauteur;
	return os;
}

/*!
 * On lit quelque chose de la forme 'largeur x hauteur'. Le séparateur
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

/*!
 * On compare deux rectangles avec la fonction strictement inferieur a.
 * On compare d'abord sur le premier champs (la largeur).
 * Si les deux rectangles ont des largeurs egales, alors on compare sur le deuxieme champs (la hauteur).
 *
 * \param rect1 le premier rectangle.
 * \param rect2 le deuxieme rectangle.
 */
bool operator<(Rectangle rect1, Rectangle rect2) {
	if (rect1._largeur < rect2._largeur)
	{
		return true;
	}
	else if (rect1._largeur == rect2._largeur)
	{
		return rect1._hauteur < rect2._hauteur;
	}
	else
	{
		return false;
	}
}
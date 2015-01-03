//
//  Boite.cpp
//  Complexity
//
//  Created by Garrigos Fernando and Guillaume Rahbari on 29/12/2014.
//  Copyright (c) 2014 Garrigos Fernando et Guillaume Rahbari . All rights reserved.
//

#include "Boite.h"
#include <stdio.h>
#include <string.h>
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
		_boite(0,colonnes) = "#"; 
	}
	for (int lignes = 1; lignes < 4*hauteur+2; ++lignes)
	{
		_boite(lignes,0) = "#"; 
		_boite(lignes,4*largeur+1) = "#"; 
	}
	for (int colonnes = 0; colonnes < 4*largeur+2; ++colonnes)
	{
		_boite(4*hauteur + 1,colonnes) = "#"; 
	}
}

/*!
 *Ajoute le rect s'il y a une place valide dans la boite
 * \param rect rectangle.
 *	return true si le rect est ajoute
 * 	sinon false
 */
bool Boite::add (const Rectangle& rect)
{
	//"ERREUR : Impossible d'ajouter ce rectangle a une boite (dimensions incorrectes)."
	if ( 4*rect.largeur() > _largeur*4 || 4*rect.hauteur() > _hauteur*4) throw Invalid();

	bool ajoute = false;
	//on test la larguer jusqu'a la largeur de la boite - la largeur du rect
	//pour eviter que le rect deborde  en larguer
	for (int i = 1;i < _hauteur*4 - rect.hauteur()*4 + 2;++i)
	{
		//on test l'hauteur jusqu'a la l'hauteur de la boite - l'hauteur du rect
		//pour eviter que le rect deborde  en hauteur
		for(int j = 1;j < _largeur*4 - rect.largeur()*4 + 2 ;++j)
		{
			// tests si on peut placer Rect dans la Boite,
			// si oui, (i,j) est la position la plus
			// en haut et à gauche qui marche
			if (validePlace(i,j,rect) != 0)
			{
				//On ajoute le rect en la position 
				addInPosition(i,j,rect);
				ajoute = true;
				return  ajoute;
			}
		}
	}
	return ajoute;
}

/*!
 * \add un rect rectangle en la position determiné
 */
void Boite::addInPosition(const int x,const int y ,const Rectangle& rect)
{
	//le modulo c'est pour eviter le decalage avec 2 caractere
	string aux = to_string(NBR%9);
	//On marque les position dans la boite
	for ( int j = 0; j < 4*rect.hauteur(); ++j)
	{
		for (int i = 0; i < 4*rect.largeur(); ++i)
		{
			_boite(j+x,i+y) = aux;
		}
	}
	++NBR;
}


/*!
* Test si les position dans la boite ou
* on veut place le rect sont libre
*/
bool Boite::validePlace(const int x,const int y,const Rectangle& rect)
{
	bool valide = true;

	//un boucle pour la hauteur du rect
	for(int i = 0; i < rect.hauteur()*4 ;i++ )
	{
			//Un boucle pour la largeur du rect
			for(int j = 0;j < rect.largeur()*4  ;j++)
			{
				//On test pour chaque position (x,y) de la boite si est libre
				if (_boite(i+x,j+y) != " ")
				{
					//si (i,j) != " " alors la position n'est pas libre
					valide = false;
					return valide;
				}
			}
	}
	//si la condition n'est jamais false 
	//alors tous les position pour place le rect sont libres
	return valide;
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

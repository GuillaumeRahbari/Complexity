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
void Boite::add (const Rectangle& rect) {
	//_boite.push_back(rect);
	for(int i = 0 ; i < rect._largeur; ++i)
	{
		_boite.push_back(boite.nbR);
	}
	for (int i = 0; i < rect._hauteur; ++i)
	{
		_boite.push_back(boite.nbR);
	}


}

/*!
 * On affiche la boite.
 *
 * \param[in,out] os l'output stream.
 * \param[in] boite la boite a afficher.
 */
ostream& operator<<(ostream& os, Boite boite) {
	os << "Taille de la boite : " << boite._largeur << 'x' << boite._hauteur << endl;
	os << endl;
	//os << "Les différents rectangles : " << endl;

		os << boite.printAsterisque(boite._largeur*4) << endl ;
		for (Boite boite : listeBoite)
		{
			cout << _boite;
		}
		os << boite.printAsterisque(boite._largeur*4) << endl ;
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
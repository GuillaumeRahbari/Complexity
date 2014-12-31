//
//  Boite.h
//  Complexity
//
//  Created by Guillaume Rahbari on 29/12/2014.
//  Copyright (c) 2014 Guillaume Rahbari. All rights reserved.
//
//
#ifndef _BOITE_H_
#define _BOITE_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include "Rectangle.h"
using namespace std;


class Boite 
{
private:
	int _largeur;
	int _hauteur;
	int _nbR;
	vector<vector> _boite;

public:
	//! Ajout d'un rectangle invalide.
	class Invalid_Add {};

	//! Invalide rectangle.
	class Invalid {};

	//! Constructeur.
	Boite(int largeur = 0, int hauteur = 0);

	//! Ajoute un rectangle a la fin du vecteur.
	void add (const Rectangle& rect);

	//! Ecris des *.
    string printAsterisque(int n) const;

    // Ecris des espaces.
    string printSpace(int n) const;

	//! Ecris une Boite.
    friend ::std::ostream& operator<<(::std::ostream& os, Boite boite);

};

#endif
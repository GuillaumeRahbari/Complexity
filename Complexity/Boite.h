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
	vector<Rectangle> _boite;
public:
	//! Constructeur.
	Boite(int largeur = 0, int hauteur = 0);

	//! Ajoute un rectangle a la fin du vecteur.
	void add (const Rectangle& rect);

	//! Ecris une Boite.
    friend ::std::ostream& operator<<(::std::ostream& os, Boite boite);

};

#endif
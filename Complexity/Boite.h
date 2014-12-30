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
#include "Rectangle.h"
using namespace std;

class Boite
{
private:
	int largeur;
	int hauteur;
	vector<Rectangle> boite;
public:
	//! Constructeur.
	Boite(int largeur = 0, int hauteur = 0);

};

#endif
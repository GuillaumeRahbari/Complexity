//
//  Boite.h
//  Complexity
//
//  Created by Garrigos Fernando and Guillaume Rahbari on 29/12/2014.
//  Copyright (c) 2014 Garrigos Fernando et Guillaume Rahbari . All rights reserved.
//

#ifndef _BOITE_H_
#define _BOITE_H_

#include <iostream>
#include <algorithm>
#include "Rectangle.h"
#include "Matrix.h"
using namespace std;


class Boite 
{
private:
	int _largeur;
	int _hauteur;

	Matrix _boite;

public:

	//! Invalide rectangle.
	class Invalid {};

	//! Constructeur.
	Boite(int largeur = 0, int hauteur = 0);

	//! Ajoute un rectangle a la fin du vecteur.
	bool add (const Rectangle& rect);

	//! Ecris une Boite.
    friend ::std::ostream& operator<<(::std::ostream& os, Boite boite);
    
    //! Marque les position du rect dans la boite
    void addInPosition(const int x,const int y,const Rectangle& rect );

	//! Test si les position dans la boite ou on veut place le rect sont libre
	bool validePlace(const int x,const int y,const Rectangle& rect);



};

#endif
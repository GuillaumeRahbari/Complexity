//
//  Rectangle.h
//  Complexity
//
//  Created by Guillaume Rahbari on 29/12/2014.
//  Copyright (c) 2014 Guillaume Rahbari. All rights reserved.
//

#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <iostream>
using namespace std;

class Rectangle
{
private:
	//! Largeur du Rectangle.
	int _largeur;
	//! Hauteur du rectangle.
	int _hauteur;

public:
	//! Exception: le format d'entree est invalide.
    class Invalid_Input {};

	//! Constructeur.
	Rectangle(int largeur = 0, int hauteur = 0);

	//! Get de la largeur du rectangle.
    int largeur() const {return _largeur;}

    //! Get de la hauteur du rectangle.
    int hauteur() const {return _hauteur;}

    //! Ecris des #.
    string printDiez(int n) const;

    // Ecris des espaces.
    string printSpace(int n) const;

	//! Ecris un Rectangle.
    friend ::std::ostream& operator<<(::std::ostream& os, Rectangle rect);

    //! Lit un Rectangle.
    friend ::std::istream& operator>>(::std::istream& is, Rectangle& rect);

    //! Operateur plus petit que pour les rectangles
	friend bool operator< (Rectangle rect1, Rectangle rect2);

};

#endif
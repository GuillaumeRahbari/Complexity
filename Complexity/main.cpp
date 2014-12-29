//
//  main.cpp
//  Complexity
//
//  Created by Guillaume Rahbari on 29/12/2014.
//  Copyright (c) 2014 Guillaume Rahbari. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iterator>
#include "Rectangle.h"

using namespace std;

int main() {
    ifstream monFichier("File.txt");
    istream_iterator<Rectangle> it(monFichier); // Un iterateur lisant des rectangles depuis le fichier.
    istream_iterator<Rectangle> end; // Le signal de fin.
    Rectangle rect;
    
    if (monFichier) {
    	// Permet de recuperer tous les rectangles.
    	while (it != end)
    	{
    		// Permet de recuperer un rectangle.
        	rect = *it;
        	cout << rect << endl;
        	++it;
    	}
    } else {
        cerr << "ERREUR" << endl;;
    }
    return 0;
}

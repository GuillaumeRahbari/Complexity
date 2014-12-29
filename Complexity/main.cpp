//
//  main.cpp
//  Complexity
//
//  Created by Guillaume Rahbari on 29/12/2014.
//  Copyright (c) 2014 Guillaume Rahbari. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Rectangle.h"

using namespace std;

int main() {
    ifstream monFichier("File.txt");
    Rectangle rect;
    
    if (monFichier) {
    	// Permet de recuperer un rectangle.
        monFichier >> rect;
        cout << rect << endl;
    } else {
        cerr << "ERREUR" << endl;;
    }
    return 0;
}

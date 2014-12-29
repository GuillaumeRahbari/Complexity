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

using namespace std;

int main() {
    ifstream monFichier("File.txt");
    int taille; 
    int taille2;
    
    if (monFichier) {
    	// Permet de recuperer la largeur de boite.
        if(monFichier >> taille){
        	cout << taille << endl;
        }
        cout << taille << endl;
        // Lit un caractère dans le vide.
        (int)monFichier.get();
        // Permet de recuperer la longueur de la boite.
        if(monFichier >> taille2){
        	cout << taille2 << endl;
        }
    } else {
        cerr << "ERREUR" << endl;;
    }
    return 0;
}

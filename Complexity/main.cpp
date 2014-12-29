//
//  main.cpp
//  Complexity
//
//  Created by Guillaume Rahbari on 29/12/2014.
//  Copyright (c) 2014 Guillaume Rahbari. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream monFichier("File.txt");
    string taille;
    
    if (monFichier) {
        monFichier >> taille;
        cout << taille << endl;
    } else {
        cerr << "ERREUR" << endl;;
    }
    return 0;
}

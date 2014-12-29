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
#include <algorithm>
#include "Rectangle.h"

using namespace std;

void sansVirgule (ifstream& ifs, ofstream& ofs) 
{
	// sauvegarder la position courante 
    long pos = ifs.tellg(); 
    // se placer en fin de fichier 
    ifs.seekg( 0 , std::ios_base::end ); 
    // récupérer la nouvelle position = la taille du fichier 
    long size = ifs.tellg() ; 
    // restaurer la position initiale du fichier 
    ifs.seekg( pos,  std::ios_base::beg ) ;
	char c = 'a';
	for (long i = pos; i < size; ++i)
	{
		ifs.get(c);
		if (c != ',')
		{
			ofs << c;
		}
		else
		{
			ofs << ' ';
		}
	}
}

int main() {
    ifstream fichier("File.txt");
    ofstream fichierSansVirgule("FichierSansVirgule.txt");
    if(fichier)
    {
	    if (fichierSansVirgule)
	    {
	    	sansVirgule(fichier, fichierSansVirgule);
	    }
	    else
	    {
	    	cerr << "ERREUR" << endl;
	    }
    }
    else
    {
    	cerr << "ERREUR" << endl;
    }
    fichier.close();
    fichierSansVirgule.close();

    ifstream monFichier("FichierSansVirgule.txt");

    istream_iterator<Rectangle> it(monFichier); // Un iterateur lisant des rectangles depuis le fichier.
    istream_iterator<Rectangle> end; // Le signal de fin.

    Rectangle rect;
	// Permet de recuperer tous les rectangles.
	while (it != end)
	{
		// Permet de recuperer un rectangle.
    	rect = *it;
    	cout << rect << endl;
    	++it;
	}
    return 0;
}

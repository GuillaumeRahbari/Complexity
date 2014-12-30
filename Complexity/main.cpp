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
#include "Boite.h"

using namespace std;


/*!
 * On reecrit tout le fichier entree par l'utilisateur mais en supprimant les virgules.
 *
 * \param ifs le fichier ouvert en lecture.
 * \param ofs le fichier ouvert en ecriture.
 */
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

	// Parcours du fichier.
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
	cout << "Veuillez choisir un nom de fichier valide (respecter la casse et l'extension) : " << endl;
	string nomFichier;
	cin >> nomFichier;
	cout << endl;

	// Permet de creer le ifstream a partir du nom.
    ifstream fichier(nomFichier.c_str());
    ofstream fichierSansVirgule("FichierSansVirgule.txt");

    // On verifie qu'il n'y a pas de problème lors de l'ouverture.
    if(fichier)
    {
	    if (fichierSansVirgule)
	    {
	    	// Suppression des virgules.
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
    // Fermeture des fichiers.
    fichier.close();
    fichierSansVirgule.close();

    // Ouverture du fichier sans virgule.
    ifstream monFichier("FichierSansVirgule.txt");

    istream_iterator<Rectangle> it(monFichier); // Un iterateur lisant des rectangles depuis le fichier.
    istream_iterator<Rectangle> end; // Le signal de fin.

    // Permet de creer la boite.
    vector<Boite> listeBoite;
    listeBoite.push_back(Boite(it->largeur(), it->hauteur()));
    ++it;

    // Liste des rectangles
    vector<Rectangle> listeRectangle;
    while (it != end)
    {
    	listeRectangle.push_back(*it);
    	++it;
    }
    // Permet de trier les rectangles dans l'ordre croissant.
    std::sort(listeRectangle.begin(), listeRectangle.end());
    // Permet d'avoir les rectangles dans l'ordre decroissant.
	std::reverse(listeRectangle.begin(), listeRectangle.end());

	// Parcours de la liste de rectangles.
	for (Rectangle rect : listeRectangle)
	{
		bool boolean = true;
		int i = 0;
		// Essaye d'ajouter un rectangle a une boite.
		while (boolean)
		{
			try
			{
				listeBoite[i].add(rect);
				boolean = false;
			}
			catch (Boite::Invalid_Add)
			{
				cerr << "ERREUR : Impossible d'ajouter le rectangle a la boite" << endl;
			}
			catch (Boite::Invalid)
			{
				boolean = false;
				cerr << "ERREUR : Impossible d'ajouter ce rectangle a une boite (dimensions incorrectes)" << endl;
			}
			++i;
		}
	}
	cout << listeBoite[0];
    return 0;
}

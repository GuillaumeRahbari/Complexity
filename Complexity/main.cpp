//
//  main.cpp
//  Complexity
//
//  Created by Garrigos Fernando and Guillaume Rahbari on 29/12/2014.
//  Copyright (c) 2014 Garrigos Fernando et Guillaume Rahbari . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "Rectangle.h"
#include "Boite.h"
#include <sys/time.h>
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
	// Variables
	struct timeval tbegin,tend;
	double texec=0.;
	int impo = 0;

	cout << "Veuillez choisir un nom de fichier valide (respecter la casse et l'extension) : " << endl;
	cout << "Fichiers Disponibles : Exemple3.txt, Exemple2.txt, Exemple1.txt " << endl;
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
	    	cerr << "ERREUR Fichiers, problème lors de l'ouverture, respecter la casse et l'extension" << endl;
	    }
    }
    else
    {
    	cerr << "ERREUR Fichiers,problème lors de l'ouverture, respecter la casse et l'extension" << endl;
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
    int largeur = it->largeur();
    int hauteur = it->hauteur();
    ++it;

    // Start timer
	gettimeofday(&tbegin,NULL);
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
		bool boolean = false;
		int i = 0;
		// Essaie d'ajouter un rectangle a une boite.
	 	while (!boolean)
		{
			try
			{
				//si on ajoute tous les rectangles, on passe vers true
				boolean = listeBoite.at(i).add(rect);
			}
			catch (Boite::Invalid)
			{
				impo++;
				boolean = true;
				cerr << "ERREUR : Impossible d'ajouter ce rectangle a une boite (dimensions incorrectes)." << endl;
			}
			catch (exception const& e)
			{
				cerr << "Creation d'une nouvelle boite." << endl;
				listeBoite.push_back(Boite(largeur, hauteur));
				--i;
			}
			i++;
		}
	}

	// End timer
	gettimeofday(&tend,NULL);

	for (Boite boite : listeBoite)
	{
		cout << boite << endl ;
	}

	 
    // Compute execution time
    texec=((double)(1000*(tend.tv_sec-tbegin.tv_sec)+((tend.tv_usec-tbegin.tv_usec)/1000)))/1000.;
	
	cout << "Nombre des rectangles = " << listeRectangle.size()<< endl;
	cout << "Nombre des boites utilisées = " << listeBoite.size()<< endl;
	if (impo != 0)
	{
		cout << "Nombre des rectangles Impossible à ajouter = " << impo << endl;
	}
	cout << "Temps d'Execution  = " << texec <<" seg"<< endl;
	

    return 0;
}

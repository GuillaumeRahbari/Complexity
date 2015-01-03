//
//  Boite.cpp
//  Complexity
//
//  Created by Guillaume Rahbari on 29/12/2014.
//  Copyright (c) 2014 Guillaume Rahbari. All rights reserved.
//

#include "Boite.h"
#include <stdio.h>
#include <string.h>
/*! 
 * \param largeur largeur.
 * \param hauteur hauteur.
 */

int NBR = 1; 
int cc = 0; 
int cl = 0; 

Boite::Boite(int largeur, int hauteur) 
	: _largeur(largeur), _hauteur(hauteur), _boite(4*hauteur+2, 4*largeur+2, " ")
{
	for (int colonnes = 0; colonnes < 4*largeur+2; ++colonnes)
	{
		_boite(0,colonnes) = "#"; 
	}
	for (int lignes = 1; lignes < 4*hauteur+2; ++lignes)
	{
		_boite(lignes,0) = "#"; 
		_boite(lignes,4*largeur+1) = "#"; 
	}
	for (int colonnes = 0; colonnes < 4*largeur+2; ++colonnes)
	{
		_boite(4*hauteur + 1,colonnes) = "#"; 
	}
}

/*!
 * \param rect rectangle.
 */
/*void Boite::add (const Rectangle& rect) 
{

	//"ERREUR : Impossible d'ajouter ce rectangle a une boite (dimensions incorrectes)."
	if ( 4*rect.largeur() > _largeur*4 ||  4*rect.hauteur() > _hauteur*4) throw Invalid();
	
	while(cl != 4*_hauteur )
	{
		
		//cout << "cc = "<< cc << endl;
		//cout << "cl = "<< cl << endl;
		cc = valideLangeur(cl);
		//		cout<<"noooo = "<<cc<<endl;

		if (valideLangeurRect(rect) != 0 )
		{
				//cout << "valide largeur"<<endl;

			if (valideHauteurRect(rect) != 0)
			{
				//cout << "valide hauteur aaaaaaaaaaaaaaaa"<<endl;
				addInPosition(cc,cl,rect);
				break;
			}
		}
			//cout << cl+rect.largeur()*4 <<endl;
			//cout << "valide largeur"<<endl;
		//if (cl+rect.largeur()*4 > _hauteur*4) throw Invalid_Add();
		cl++;
	}
	cc = cl =0;
}*/


/*!
 * \param rect rectangle.
 bool place(R,i,j)
// tests si on peut placer R dans B, si oui (i,j) est la position la plus
// en haut et à gauche qui marche
for i = 1 to X(B)-X(R)+1
    for j = 1 to Y(B)-Y(R)+1
        if placement_valid(R,i,j) then return true
    endfor
endfor
return false
 */
bool Boite::add (const Rectangle& rect)
{
	bool ajoute = false;
	//on test la larguer jusqu'a la largeur de la boite - la largeur du rect
	//pour eviter que le rect deborde  en larguer
	for (int i = 1;i < _largeur*4 - rect.largeur()*4 + 2;++i)
	{
		//on test l'hauteur jusqu'a la l'hauteur de la boite - l'hauteur du rect
		//pour eviter que le rect deborde  en hauteur
		for(int j = 1;j < _hauteur*4 - rect.hauteur()*4 + 2 ;++j)
		{

			cout << "boite largeur = "<< i <<endl;
			cout << "boite hauteur = "<< j <<endl;
			// tests si on peut placer Rect dans la Boite,
			// si oui, (i,j) est la position la plus
			// en haut et à gauche qui marche
			if (validePlace(i,j,rect) != 0)
			{
				//On ajoute le rect en la position 
				cout << "ajoute"<<endl;
				addInPosition(i,j,rect);
				ajoute = true;
				return  ajoute;
			}
		}
	}
	return ajoute;
}

/*!
 * \add un rect rectangle en la position determiné
 */
void Boite::addInPosition(const int x,const int y ,const Rectangle& rect)
{
	//le modulo c'est pour eviter le decalage avec 2 caractere
	string aux = to_string(NBR%9);
	
	for ( int j = 0; j < 4*rect.largeur(); ++j)
	{
		for (int i = 0; i < 4*rect.hauteur(); ++i)
		{

			_boite(j+x,i+y) = aux;
		}
	}
	cout<<"add in position"<< endl;
	++NBR;
}


/*!
* Test si les position dans la boite ou
* on veut place le rect sont libre
*/
bool Boite::validePlace(const int x,const int y,const Rectangle& rect)
{
	bool valide = true;

	//un boucle pour la hauteur du rect
	for(int i = 0; i < rect.largeur()*4 ;++i )
	{
			//Un boucle pour la largeur du rect
			for(int j = 0;j < rect.hauteur()*4  ;++j)
			{
				//cout <<"largeur "<<rect.largeur()*4 <<endl;
				cout <<"h = "<< i<<endl;
				cout << "l = " <<j << endl;
				cout <<"x = "<< x<<endl;
				cout << "y = " <<y << endl;

				//On test pour chaque position (x,y) de la boite si est libre
				if (_boite(i+x,j+y) != " ")
				{
					cout << "NON valide = "<< _boite(i+x,j+y) << endl;
					cout << "NON valide x = "<< i+x << endl;
					cout << "NON valide y = "<< j+y << endl;
					//si (i,j) != " " alors la position n'est pas libre
					valide = false;
					return valide;
				}
			}
	}
	//si la condition n'est jamais false 
	//alors tous les position pour place le rect sont libres
	cout << " valide = "  << endl;

	return valide;
}


/*!
 * On valide la languer d'un rectangule
 *
 *
 */
	
int Boite::valideLangeur(int ligne)
{	
	/*for (int i = 0; i < 4*_largeur; ++i)
	{
		//cout << "l = "<< _boite(ligne+1  ,i)<< endl;

		if(_boite(ligne +1 ,i) == " ")
		{
			//cout << "lan = "<< i << endl;

			return i - 1;	
		}  
	}*/
	return 0;
}
int Boite::valideHauteur(int colonne)
{	
	/*for (int i = 0; i < 4*_hauteur; ++i)
	{
				//	cout << "i = "<< _boite(i,colonne+1) << endl;

		if(_boite(i,colonne+1) == " ")
		{
			//cout << "i = "<< i << endl;

			return i - 1;	
		}  
	}*/
	return 0;
}

bool Boite::valideLangeurRect(const Rectangle& rect)
{
	//cout << "bbb" << _boite(cl+1,cc + 4*rect.largeur())<< endl; 
	//cout << "bbb" << cl<< endl; 
	//cout << "bbb" << cc<< endl; 

	
	/*if (cc + 4*rect.largeur() <= _largeur*4)
	{
		if( _boite(cl+1,cc + 4*rect.largeur()) == " ")
		{
			return true;
		}
	}
	else
	{
		return false;
	}*/
	return true;
}

bool Boite::valideHauteurRect(const Rectangle& rect)
{
	//cout << "ccc" << _boite(cl+4*rect.hauteur(),cc+1)<< endl; 
	//cout << "ccc" << cl<< endl; 
	//cout << "ccc" << cc<< endl; 

	/*if (cl + 4*rect.hauteur() <= _hauteur*4)
	{
		if (_boite(cl+4*rect.hauteur(),cc+1) == " ")
		{
			return true;
		}
	}
	else
	{
		return false;
	}*/
		return true;
}

/*!
 * On affiche la boite.
 *
 * \param[in,out] os l'output stream.
 * \param[in] boite la boite a afficher.
 */

ostream& operator<<(ostream& os, Boite boite) {
os << boite._boite;
return os;
}

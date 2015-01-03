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
void Boite::add (const Rectangle& rect) 
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
}


/*!
 * \add un rect rectangle en la position determiné
 */
void Boite::addInPosition(const int x,const int y ,const Rectangle& rect)
{
	string aux = to_string(NBR%9);//le modulo c'est pour eviter le decalage avec 2 caractere
	/*cout << "4*rect.hauteur()+1 = "<< 4*rect.hauteur()+1 <<" "<<rect.hauteur()<< endl;
	cout << "4*rect.largeur() = "<< 4*rect.largeur() <<" "<< rect.largeur() << endl;
	*//*cout << "x = "<< cc + rect.largeur() << endl;
	cout << "y = "<< _largeur*4 << endl;*/

	for ( int j = 1; j < 4*rect.hauteur()+1; ++j)
	{
		for (int i = 0; i < 4*rect.largeur(); ++i)
		{
			_boite(y + j,1 + i + x) = aux;
		}
	}
	++NBR;
}


/*!
 * On valide la languer d'un rectangule
 *
 *
 */
	
int Boite::valideLangeur(int ligne)
{	
	for (int i = 0; i < 4*_largeur; ++i)
	{
		//cout << "l = "<< _boite(ligne+1  ,i)<< endl;

		if(_boite(ligne +1 ,i) == " ")
		{
			//cout << "lan = "<< i << endl;

			return i - 1;	
		}  
	}
	return 0;
}
int Boite::valideHauteur(int colonne)
{	
	for (int i = 0; i < 4*_hauteur; ++i)
	{
				//	cout << "i = "<< _boite(i,colonne+1) << endl;

		if(_boite(i,colonne+1) == " ")
		{
			//cout << "i = "<< i << endl;

			return i - 1;	
		}  
	}
	return 0;
}

bool Boite::valideLangeurRect(const Rectangle& rect)
{
	//cout << "bbb" << _boite(cl+1,cc + 4*rect.largeur())<< endl; 
	//cout << "bbb" << cl<< endl; 
	//cout << "bbb" << cc<< endl; 

	
	if (cc + 4*rect.largeur() <= _largeur*4)
	{
		if( _boite(cl+1,cc + 4*rect.largeur()) == " ")
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

bool Boite::valideHauteurRect(const Rectangle& rect)
{
	//cout << "ccc" << _boite(cl+4*rect.hauteur(),cc+1)<< endl; 
	//cout << "ccc" << cl<< endl; 
	//cout << "ccc" << cc<< endl; 

	if (cl + 4*rect.hauteur() <= _hauteur*4)
	{
		if (_boite(cl+4*rect.hauteur(),cc+1) == " ")
		{
			return true;
		}
	}
	else
	{
		return false;
	}
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

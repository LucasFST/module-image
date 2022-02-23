#include <iostream>
#include "Pixel.h"
#include <cassert>


//constructeur par défaut (couleur noir)
Pixel::Pixel()
{
	r = 0;
	g = 0;
	b = 0;
}


//constructeur avec des paramètres rentrés par l'uti
Pixel::Pixel (unsigned char nr, unsigned char ng, unsigned char nb)
{
	r = nr;	//on applique les modifs
	g = ng;
	b = nb;
}

//retourne la composante rouge du pixel 
unsigned char Pixel::getRouge () const 
{
	return r;
}

//retourne la composante verte du pixel 
unsigned char Pixel::getVert () const
{
	return g;
}

//retourne la composante bleue du pixel 
unsigned char Pixel::getBleu () const
{
	return b;
}

//change la composante rouge du pixel 
void Pixel::setRouge (unsigned char nr)
{
	r = nr; // on applique le changement
}

//change la composante verte du pixel 
void Pixel::setVert (unsigned char ng)
{
	g = ng;	// on applique le changement
}

//change la composante bleue du pixel 
void Pixel::setBleu (unsigned char nb)
{
	b = nb; // on applique le changement
}


#include <iostream>
#include "Pixel.h"
#include <cassert>


//constructeur par defaut (couleur noir)
Pixel::Pixel()
{
	r = 0;
	g = 0;
	b = 0;
}


//constructeur avec des parametres rentrés par l'uti
Pixel::Pixel (unsigned char nr, unsigned char ng, unsigned char nb)
{
	r = nr;	//on applique les modifs
	g = ng;
	b = nb;
}

//retourne la valeur R du code RGB
unsigned int Pixel::getRouge () const 
{
	return r;
}

//retourne la valeur G du code RGB
unsigned int Pixel::getVert () const
{
	return g;
}

//retourne la valeur B du code RGB
unsigned int Pixel::getBleu () const
{
	return b;
}

//change la couleur R du code RGB du pixel
void Pixel::setRouge (unsigned char nr)
{
	r = nr; // on applique le changement
}

//change la couleur G du code RGB du pixel
void Pixel::setVert (unsigned char ng)
{
	g = ng;	// on applique le changement
}

//change la couleur G du code RGB du pixel
void Pixel::setBleu (unsigned char nb)
{
	b = nb; // on applique le changement
}


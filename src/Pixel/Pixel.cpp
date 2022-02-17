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
Pixel::Pixel (unsigned int nr, unsigned int ng, unsigned int nb)
{
	assert(nr <= 255); // verif si c'est des valeurs corrects pour le code RGB
	assert(ng <= 255); 
	assert(nb <= 255);

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
void Pixel::setRouge (unsigned int nr)
{
	assert(nr <= 255); // verif si c'est des valeurs corrects pour le code RGB
	r = nr; // on applique le changement
}

//change la couleur G du code RGB du pixel
void Pixel::setVert (unsigned int ng)
{
	assert(ng <= 255); 
	g = ng;	// on applique le changement
}

//change la couleur G du code RGB du pixel
void Pixel::setBleu (unsigned int nb)
{
	assert(nb <= 255); 
	b = nb; // on applique le changement
}

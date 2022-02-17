#include <iostream>
#include "Pixel.h"
#include <cassert>

Pixel::Pixel()
{
	r = 0;
	g = 0;
	b = 0;
}

Pixel::Pixel (unsigned int nr, unsigned int ng, unsigned int nb)
{
	assert(nr <= 255); 
	assert(ng <= 255); 
	assert(nb <= 255); 
	r = nr;
	g = ng;
	b = nb;
}

unsigned int Pixel::getRouge () const
{
	return r;
}

unsigned int Pixel::getVert () const
{
	return g;
}

unsigned int Pixel::getBleu () const
{
	return b;
}

void Pixel::setRouge (unsigned int nr)
{
	assert(nr <= 255); 
	r = nr;
}

void Pixel::setVert (unsigned int ng)
{
	assert(ng <= 255); 
	g = ng;
}

void Pixel::setBleu (unsigned int nb)
{
	assert(nb <= 255); 
	b = nb;
}

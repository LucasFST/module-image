#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>

using namespace std;

class Pixel
{
	public :

	// Constructeur par défaut de la classe: initialise le pixel à la couleur noire
   Pixel ();

   // Constructeur de la classe: initialise r,g,b avec les paramètres
   Pixel (unsigned int nr, unsigned int ng, unsigned int nb);

   // Accesseur : récupère la composante rouge du pixel
   unsigned int getRouge () const;

   // Accesseur : récupère la composante verte du pixel
   unsigned int getVert () const;

   // Accesseur : récupère la composante bleue du pixel
   unsigned int getBleu () const;

   // Mutateur : modifie la composante rouge du pixel
   void setRouge (unsigned int nr);

   // Mutateur : modifie la composante verte du pixel
   void setVert (unsigned int ng);

   // Mutateur : modifie la composante bleue du pixel
   void setBleu (unsigned int nb);

   private :

    unsigned int r,g,b;    // les composantes du pixel, unsigned char en C++
};

#endif


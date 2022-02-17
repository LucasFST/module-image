#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>

using namespace std;

class Pixel
{
	public :

    /**
     * @brief   Constructeur par défaut de la classe : initialise le pixel à la couleur noire
    */

   Pixel ();

    /**
     * @brief   Constructeur de la classe : initialise r,g,b avec les paramètres
     * @param[in] nr un entier strictement positif <=255 représentant le pixel rouge
     * @param[in] nv un entier strictement positif <=255 représentant le pixel vert 
     * @param[in] nb un entier strictement positif <=255 représentant le pixel bleu
    */

   Pixel (unsigned int nr, unsigned int ng, unsigned int nb);

    /**
     * @brief   Accesseur : récupère la composante rouge du pixel
     * @return unsigned int (entier compris entre 0 et 255)     
    */

   unsigned int getRouge () const;

    /**
     * @brief   Accesseur : récupère la composante vert du pixel
     * @return unsigned int (entier compris entre 0 et 255)       
    */

   unsigned int getVert () const;

    /**
     * @brief   Accesseur : récupère la composante bleu du pixel
     * @return unsigned int (entier compris entre 0 et 255)       
    */

   unsigned int getBleu () const;

    /**
     * @brief  Mutateur : modifie la composante rouge du pixel
     * @return void     
    */

   void setRouge (unsigned int nr);

    /**
     * @brief  Mutateur : modifie la composante vert du pixel
     * @return void     
    */

   void setVert (unsigned int ng);

    /**
     * @brief  Mutateur : modifie la composante bleu du pixel
     * @return void     
    */   

   void setBleu (unsigned int nb);

   private :

    unsigned int r,g,b;    // les composantes du pixel, unsigned char en C++
};

#endif


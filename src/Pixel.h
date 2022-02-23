#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>

using namespace std;

/**
*   @author {Brossat Pierrick ; Faustmann Lucas}
*/
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
     * @remark nr, ng et nb doivent être inferieur à 255 (d'où le usigned char)
    */

   Pixel (unsigned char nr, unsigned char ng, unsigned char nb);

    /**
     * @brief   Accesseur : récupère la composante rouge du pixel
     * @return unsigned char (entier compris entre 0 et 255)     
    */

   unsigned int getRouge () const;

    /**
     * @brief   Accesseur : récupère la composante vert du pixel
     * @return unsigned char (entier compris entre 0 et 255)       
    */

   unsigned int getVert () const;

    /**
     * @brief   Accesseur : récupère la composante bleu du pixel
     * @return unsigned char (entier compris entre 0 et 255)       
    */

   unsigned int getBleu () const;

    /**
     * @brief  Mutateur : modifie la composante rouge du pixel
     * @param[in] nr un entier strictement positif représentant le pixel rouge
     * @return void     
     * @remark nr doit être inferieur à 255 (d'où le usigned char)
    */

   void setRouge (unsigned char nr);

    /**
     * @brief  Mutateur : modifie la composante vert du pixel
     * @param[in] ng un entier strictement positif représentant le pixel vert 
     * @return void   
    * @remark ng doit être inferieur à 255 (d'où le usigned char)
    */

   void setVert (unsigned char ng);

    /**
     * @brief  Mutateur : modifie la composante bleu du pixel
     * @param[in] nb un entier strictement positif représentant le pixel bleu
     * @return void     
     * @remark nb doit être inferieur à 255 (d'où le usigned char)
    */   

   void setBleu (unsigned char nb);

   private :

    unsigned int r,g,b;    // les composantes du pixel
};

#endif


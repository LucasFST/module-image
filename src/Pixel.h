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
     * @param[in] nr un entier strictement positif représentant la composante rouge du pixel
     * @param[in] ng un entier strictement positif représentant la composante verte du pixel
     * @param[in] nb un entier strictement positif représentant la composante bleue du pixel
     * @remark nr, ng et nb doivent être inférieurs ou égaux à 255 (unsigned char)
    */

   Pixel (unsigned char nr, unsigned char ng, unsigned char nb);

    /**
     * @brief   Accesseur : récupère la composante rouge du pixel
     * @return unsigned char (entier compris entre 0 et 255)     
    */

   unsigned char getRouge () const;

    /**
     * @brief   Accesseur : récupère la composante verte du pixel
     * @return unsigned char (entier compris entre 0 et 255)       
    */

   unsigned char getVert () const;

    /**
     * @brief   Accesseur : récupère la composante bleue du pixel
     * @return unsigned char (entier compris entre 0 et 255)       
    */

   unsigned char getBleu () const;

    /**
     * @brief  Mutateur : modifie la composante rouge du pixel
     * @param[in] nr un entier strictement positif représentant la composante rouge du pixel
     * @return void     
     * @remark nr doit être inférieur ou égal à 255 (unsigned char)
    */

   void setRouge (unsigned char nr);

    /**
     * @brief  Mutateur : modifie la composante verte du pixel
     * @param[in] ng un entier strictement positif représentant la composante verte du pixel 
     * @return void   
    * @remark ng doit être inférieur ou égal à 255 (usigned char)
    */

   void setVert (unsigned char ng);

    /**
     * @brief  Mutateur : modifie la composante bleue du pixel
     * @param[in] nb un entier strictement positif représentant la composante bleue du pixel
     * @return void     
     * @remark nb doit être inférieur ou égal à 255 (usigned char)
    */   

   void setBleu (unsigned char nb);

   private :
    
    unsigned char r,g,b;    
};

#endif


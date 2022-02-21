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
     * @param[in] nr un entier strictement positif représentant le pixel rouge
     * @param[in] ng un entier strictement positif représentant le pixel vert 
     * @param[in] nb un entier strictement positif représentant le pixel bleu
     * @remark nr, ng et nb doivent être inférieurs ou égaux à 255
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
     * @param[in] nr un entier strictement positif représentant le pixel rouge
     * @return void     
     * @remark nr doit être inférieur ou égal à 255
    */

   void setRouge (unsigned int nr);

    /**
     * @brief  Mutateur : modifie la composante vert du pixel
     * @param[in] ng un entier strictement positif représentant le pixel vert 
     * @return void   
    * @remark ng doit être inférieur ou égal à 255
    */

   void setVert (unsigned int ng);

    /**
     * @brief  Mutateur : modifie la composante bleu du pixel
     * @param[in] nb un entier strictement positif représentant le pixel bleu
     * @return void     
     * @remark nb doit être inférieur ou égal à 255
    */   

   void setBleu (unsigned int nb);

   private :

    unsigned int r,g,b;    // les composantes du pixel, unsigned char en C++ ????????????????????????????????????????????????????????????? (changer les unsigned int ds fonctions en unsigned char ????????)
};

#endif


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
     * 
     * Exemple d'utilisation : 
     * @code
     * Pixel un_Pixel;
     * @endcode
    */
    Pixel ();

    /**
     * @brief   Constructeur de la classe : initialise r,g,b avec respectivement les paramètres nr,ng,nb
     * @param[in] nr un entier strictement positif représentant la composante rouge du pixel
     * @param[in] ng un entier strictement positif représentant la composante verte du pixel
     * @param[in] nb un entier strictement positif représentant la composante bleue du pixel
     * 
     * Exemple d'utilisation : 
     * @code
     * Pixel blanc (255,255,255);
     * @endcode
     * @warning nr, ng et nb doivent être inférieurs ou égaux à 255 (unsigned char)
    */
    Pixel (unsigned char nr, unsigned char ng, unsigned char nb);

    /**
     * @brief   Accesseur : récupère la composante rouge du pixel
     * @return unsigned char (entier compris entre 0 et 255)
     * 
     * Exemple d'utilisation : 
     * @code
     * unsigned char nr = un_Pixel.getRouge();
     * @endcode    
    */
    unsigned char getRouge () const;

    /**
     * @brief   Accesseur : récupère la composante verte du pixel
     * @return unsigned char (entier compris entre 0 et 255)
     * 
     * Exemple d'utilisation :
     * @code
     * unsigned char ng = un_Pixel.getVert();
     * @endcode        
    */
    unsigned char getVert () const;

    /**
     * @brief   Accesseur : récupère la composante bleue du pixel
     * @return unsigned char (entier compris entre 0 et 255) 
     * 
     * Exemple d'utilisation :
     * @code
     * unsigned char nb = un_Pixel.getBleu();
     * @endcode       
    */
    unsigned char getBleu () const;

    /**
     * @brief  Mutateur : modifie la composante rouge du pixel
     * @param[in] nr un entier strictement positif représentant la composante rouge du pixel
     * @return void 
     * 
     * Exemple d'utilisation :
     * @code
     * un_Pixel.setRouge(148);
     * @endcode    
     * @warning nr doit être inférieur ou égal à 255 (unsigned char)
    */
    void setRouge (unsigned char nr);

    /**
     * @brief  Mutateur : modifie la composante verte du pixel
     * @param[in] ng un entier strictement positif représentant la composante verte du pixel 
     * @return void 
     * 
     * Exemple d'utilisation :
     * @code
     * un_Pixel.setVert(28);
     * @endcode   
     * @warning ng doit être inférieur ou égal à 255 (usigned char)
    */
    void setVert (unsigned char ng);

    /**
     * @brief  Mutateur : modifie la composante bleue du pixel
     * @param[in] nb un entier strictement positif représentant la composante bleue du pixel
     * @return void 
     * 
     * Exemple d'utilisation :
     * @code
     * un_Pixel.setBleu(213);
     * @endcode     
     * @warning nb doit être inférieur ou égal à 255 (usigned char)
    */   
    void setBleu (unsigned char nb);

    private :
    
    unsigned char r,g,b;    
};

#endif


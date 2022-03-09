#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

/**
* @author {Brossat Pierrick ; Faustmann Lucas}
*/

class Picture {

public:

    /**
    * @brief Constructeur par défaut de la classe
    * 
    * Exemple d'utilisation :
    * @code
    * Picture une_Picture;
    * @endcode
    */
    Picture () ;

    /**
    * @brief Déstructeur de la classe
    */
    ~Picture () ;

    /**
    * @brief Charge l'image à afficher
    * @param[in] filename le chemin vers l'image
    * @return void  
    * 
    * Exemple d'utilisation :
    * @code
    * Picture une_Picture;
    * une_Picture.loadFromFile("chemin_vers_image", renderer);
    * @endcode
    */
    void loadFromFile (const char* filename, SDL_Renderer * renderer);  

    /**
    * @brief Met l'image dans le renderer pour qu'il puisse la dessiner et donc l'afficher
    * @return void 
    * 
    * Exemple d'utilisation :
    * @code
    * Picture une_Picture;
    * une_Picture.loadFromCurrentSurface(renderer);
    * @endcode
    */
    void loadFromCurrentSurface (SDL_Renderer * renderer);  

    /**
    * @brief Dessine l'image que pointe le renderer et suivant les coordonnées x et y 
    * @param[in] x position en abscisse de l'image 
    * @param[in] y position en ordonnée de l'image 
    * @param[in] w largeur (width)
    * @param[in] h hauteur (heigh)
    * @return void   
    *
    * Exemple d'utilisation :
    * @code
    * Picture une_Picture;
    * une_Picture.draw(renderer, 1OO, 100, 5, 5);
    * @endcode
    */
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);  

private:

    SDL_Surface * surface;
    SDL_Texture * texture;
    bool has_changed;

};




//-------------------------------------------------- Class Image




class Image {

public:
  
    /**
    * @brief Constructeur par défaut de la classe : initialise dimx et dimy à 0, ce constructeur n'alloue pas de pixel
    * 
    * Exemple d'utilisation :
    * @code
    * Image une_Image;
    * @endcode
    */
    Image ();

    /**
    * @brief  Constructeur de la classe : initialise dimx et dimy (après vérification), puis alloue le tableau de pixel dans le tas (image noire)
    * @param[in] dimx la dimension en abscisse de notre image 
    * @param[in] dimy la dimension en ordonnée de notre image 
    * 
    * Exemple d'utilisation :
    * @code
    * Image une_Image(2,3);
    * @endcode
    * @warning dimx et dimy ne peuvent être supérieurs ou égaux à 50000 (limite arbitraire)
    */
    Image (unsigned int dimx, unsigned int dimy);

    /**
    * @brief  Destructeur de la classe : désallocation de la mémoire du tableau de pixel et mise à jour des champs dimx et dimy à 0
    */
    ~Image ();

    /**
    * @brief   Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
    * @param[in] x la coordonnée x du pixel
    * @param[in] y la coordonnée y du pixel
    * @return Pixel 
    * 
    * Exemple d'utilisation :
    * @code
    * Pixel un_Pixel = une_Image.getPix(1,1)
    * @endcode
    * @warning x et y doivent être inférieurs strictement à dimx et dimy respectivement (dimensions de l'image) 
    */
    Pixel& getPix (unsigned int x, unsigned int y) const; //retourne Pixel ou Pixel&

    /**
    * @brief   Mutateur : modifie la couleur du pixel de coordonnées (x,y) en vérifiant leur validité
    * @param[in] x la coordonnée x du pixel
    * @param[in] y la coordonnée y du pixel
    * @param[in,out] couleur un pixel de la nouvelle couleur désirée (attention : en mode donnée/résultat mais CONST)
    * @return void
    * 
    * Exemple d'utilisation :
    * @code
    * Pixel Blanc(255,255,255);
    * une_Image.setPix(1,1,Blanc);
    * @endcode 
    * @warning x et y doivent être inférieurs strictement à dimx et dimy respectivement (dimensions de l'image)
    */
    void setPix (unsigned int x, unsigned int y, const Pixel& couleur );

    /**
    * @brief   Dessine un rectangle plein de la couleur désirée dans l'image 
    * @param[in] Xmin la composante x du coin haut gauche  
    * @param[in] Ymin la composante y du coin haut gauche 
    * @param[in] Xmax la composante x du coin bas droite
    * @param[in] Ymax la composante x du coin bas droite 
    * @param[in,out] couleur un pixel de la couleur du rectangle désiré (attention : en mode donnée/résultat mais CONST)
    * @return void 
    * 
    * Exemple d'utilisation :
    * @code
    * Pixel Blanc(255,255,255);
    * une_Image.dessinerRectangle(0,0,2,3,Blanc);
    * @endcode
    */
    void dessinerRectangle (unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, const Pixel& couleur );

    /**
    * @brief Efface l'image en la remplissant de la couleur passée en paramètre 
    * @param[in,out] couleur un pixel de la couleur désirée (attention : en mode donnée/résultat mais CONST) 
    * @return void 
    * 
    * Exemple d'utilisation :
    * @code
    * Pixel Blanc(255,255,255);
    * une_Image.effacer(Blanc);
    * @endcode
    */
    void effacer (const Pixel& couleur);

    /**
    * @brief  Effectue une série de tests vérifiant que le module fonctionne et que les données membres de l'objet sont conformes
    * @return void 
    * 
    * Exemple d'utilisation :
    * @code
    * une_Image.testRegression();
    * @endcode
    */
    void testRegression ();  

    /**
    * @brief Sauver une image dans un fichier
    * @param[in,out] filename nom de l'image à sauvegarder (attention : en mode donnée/résultat mais CONST)
    * @return void 
    * 
    * Exemple d'utilisation :
    * @code
    * une_Image.sauver("../data/image1.ppm");
    * @endcode
    */
    void sauver(const string& filename) const;

    /**
    * @brief Ouvrir une image depuis un fichier
    * @param[in,out] filename chemin/nom de l'image à ouvrir (attention : en mode donnée/résultat mais CONST)
    * @return void 
    * 
    * Exemple d'utilisation :
    * @code
    * une_Image.ouvrir("../data/image1.ppm");
    * @endcode
    */
    void ouvrir(const string& filename);

    /**
    * @brief Afficher les composantes RGB des pixels sur la console
    * @return void 
    * 
    * Exemple d'utilisation :
    * @code
    * une_Image.afficherConsole();
    * @endcode
    */
    void afficherConsole();

    /**
    * @brief Affiche l'image dans une fenêtre SDL2
    * @return void 
    * 
    * Exemple d'utilisation :
    * @code
    * une_Image.afficher();
    * @endcode
    */
    void afficher();

    /**
    * @brief Initialise la fenêtre SDL 
    * @return void 
    * 
    * Exemple d'utilisation :
    * @code 
    * une_Image.afficherInit();
    * @endcode
    */
    void afficherInit (); 

    /**
    * @brief S'occupe de l'affichage de l'image et des actions de l'utilisateur (zoom, dézoom, ...)
    * @return void 
    * 
    * Exemple d'utilisation :
    * @code 
    * une_Image.afficherBoucle();
    * @endcode
    */
    void afficherBoucle ();

    /**
    * @brief Détruit la fenêtre SDL 
    * @return void 
    * 
    * Exemple d'utilisation :
    * @code 
    * une_Image.afficherDetruit();
    * @endcode
    */
    void afficherDetruit ();


private:

    unsigned int dimx,dimy;
    Pixel* tab;
    SDL_Window * window;
    SDL_Renderer * renderer;
    Picture imageSDL;
};


#endif
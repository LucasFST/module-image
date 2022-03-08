#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

using namespace std;

/**
*   @author {Brossat Pierrick ; Faustmann Lucas}
*/
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
        * @param[in] dimx la dimension en abcsisse de notre image 
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
        void afficher() const;

        void afficherInit ()const; 

        void afficherBoucle ()const;

        void afficherDetruit ()const;


    private:

        unsigned int dimx,dimy;
        Pixel* tab;
        //SDL_window * window;
        //SDL_Renderer * renderer;
};

#endif
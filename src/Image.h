#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"
#include <iostream>
using namespace std;

class Image {

    private:
        unsigned int dimx,dimy;
        Pixel* tab;

    public:
      
        /**
        * @brief Constructeur par défaut de la classe: initialise dimx et dimy à 0, ce constructeur n'alloue pas de pixel
        */
        Image ();

    

        /**
        *   @brief  Constructeur de la classe: initialise dimx et dimy (après vérification), puis alloue le tableau de pixel dans le tas (image noire)
        *   @param[in] dimx la dimension en abcsisse de notre image 
        *   @param[in] dimy la dimension en ordonnée de notre image 
        */
        Image (unsigned int dimx, unsigned int dimy);



      
        /**
        *   @brief  Destructeur de la classe: déallocation de la mémoire du tableau de pixel et mise à jour des champs dimx et dimy à 0
        */
        ~Image ();



        /**
        *   @brief   Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
        *   @param[in] x la coordonnée x du pixel
        *   @param[in] y la coordonnée y du pixel
        *   @return Pixel 
        */
        Pixel getPix (unsigned int x, unsigned int y) const;


      
        /**
        *   @brief   Mutateur : modifie la couleur du pixel de coordonnées (x,y)
        *   @param[in] dimx la dimension en abcsisse de notre image 
        *   @param[in] dimy la dimension en ordonnée de notre image
        *   @param[in,out] couleur la couleur en code RGB de notre pixel 
        *   @return void 
        */
    void setPix (unsigned int x, unsigned int y, const Pixel& couleur );


        //Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
        /**
        *   @brief   Dessine un rectangle plein de la couleur dans l'image 
        *   @param[in] Xmin la composante x du coin haut gauche  
        *   @param[in] Ymin la composante y du coin haut gauche 
        *   @param[in] Xmax la composante x du coin bas droite
        *   @param[in] Ymax la composante x du coin bas droite 
        *   @param[in,out] couleur la couleur en code RGB de notre pixel 
        *   @return void 
        */
    void dessinerRectangle (unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, const Pixel& couleur );

        
        /**
        *   @brief Efface l'image en la remplissant de la couleur en paramètre 
        *   @param[in,out] couleur la couleur en code RGB de notre pixel 
        *   @return void 
        */
    void effacer (const Pixel& couleur);

        
        /**
        *   @brief  Effectue une série de tests vérifiant que le module fonctionne et que les données membres de l'objet sont conformes
        *   @return void 
        */
   void testRegression ();

        
        /**
        *   @brief sauver une image dans un fichier
        *   @param[in,out] filename nom de l'image à sauvegarder
        *   @return void 
        */
   void sauver(const string& filename) const;

        //ouvrir une image depuis un fichier
        /**
        *   @brief ouvrir une image depuis un fichier
        *   @param[in,out] filename chemin/nom de l'image à ouvrir
        *   @return void 
        */
   void ouvrir(const string& filename);

        
        /**
        *   @brief afficher les valeurs des pixels sur la console
        *   @return void 
        */
   void afficherConsole();


};

#endif
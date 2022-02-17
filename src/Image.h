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
        // Constructeur par défaut de la classe: initialise dimx et dimy à 0
        // ce constructeur n'alloue pas de pixel
    Image ();

        // Constructeur de la classe: initialise dimx et dimy (après vérification)
        // puis alloue le tableau de pixel dans le tas (image noire)
    Image (unsigned int dimx, unsigned int dimy);

        // Destructeur de la classe: déallocation de la mémoire du tableau de pixels
        // et mise à jour des champs dimx et dimy à 0
    ~Image ();

        // Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
        // la formule pour passer d'un tab 2D à un tab 1D est tab[ydimx+x]
    Pixel getPix (unsigned int x, unsigned int y) const;

        // Mutateur : modifie le pixel de coordonnées (x,y)
    void setPix (unsigned int dimx, unsigned int dimy, const Pixel& couleur );

        // Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
    void dessinerRectangle (unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, const Pixel& couleur );

        // Efface l'image en la remplissant de la couleur en paramètre
        // (en appelant dessinerRectangle avec le bon rectangle)
    void effacer (const Pixel& couleur);

        // Effectue une série de tests vérifiant que le module fonctionne et
        // que les données membres de l'objet sont conformes
   void testRegression ();

        //sauver une image dans un fichier
   void sauver(const string& filename) const;

        //ouvrir une image depuis un fichier
   void ouvrir(const string& filename);

        //afficher les valeurs des pixels sur la console
   void afficherConsole();


};

#endif
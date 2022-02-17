
#include "Image.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <string.h>
using namespace std;

Image::Image()
{
    dimx=0;
    dimy=0;
    tab = NULL;
}

Image::Image(unsigned int dimX, unsigned int dimY)
{
    assert (dimX<50000 && dimY<50000 ); //taille limitée pour dimX et dimY, pas de verification si negatif puisque ce sont des unsigned int.
    dimx=dimX;
    dimy=dimY;
    tab=new Pixel[dimX*dimY];
    // for (unsigned int i=0; i<=dimX*dimY; i++)
    // {
    //        tab[i];
    // }
}


Image::~Image()
    {
        if(tab != NULL)
        {
            delete[]tab;
        }
        tab=NULL;
        dimx=0;
        dimy=0;
    }


Pixel Image::getPix (unsigned int x,unsigned int y) const
    {
        assert (x<dimx && y<dimy );//taille limitée pour dimx et dimy, pas de verification si negatif puisque ce sont des unsigned int.
        return tab[y*dimx+x];  //y*dimx+y+x

    }


void Image::setPix (unsigned int x,unsigned int y, const Pixel& couleur)
    {
        assert (x<dimx && y<dimy );
        tab [y*dimx+x].setVert(couleur.getVert());
        tab [y*dimx+x].setRouge(couleur.getRouge());
        tab [y*dimx+x].setBleu(couleur.getBleu());
    }


void Image::dessinerRectangle (unsigned int Xmin,unsigned int Ymin,unsigned int Xmax,unsigned int Ymax, const Pixel& couleur)
     {
        for (unsigned int i=Ymin; i<=Ymax; i++)
            {
            for (unsigned int j=Xmin; j<=Xmax; j++ )
                {
                   setPix(j,i,couleur);
                }

            }
     }


void Image::effacer (const Pixel& couleur)
    {
        dessinerRectangle (0,0,dimx-1,dimy-1,couleur);

    }

void Image::testRegression () //const
{
    dimx=2;
    dimy=3;
    tab = new Pixel[dimx*dimy];
    Pixel pxTestNoir = getPix(1,2);
    assert(pxTestNoir.getVert()==0);
    assert(pxTestNoir.getRouge()==0);
    assert(pxTestNoir.getBleu()==0);
    Pixel pxBlanc(255,255,255);
    dessinerRectangle(0,0,1,1, pxBlanc);
    Pixel pxTestBlanc = getPix(0,0);
    assert(pxTestBlanc.getVert()==255);
    assert(pxTestBlanc.getRouge()==255);
    assert(pxTestBlanc.getBleu()==255);
    assert(pxTestNoir.getVert()==0);
    assert(pxTestNoir.getRouge()==0);
    assert(pxTestNoir.getBleu()==0);
    effacer(pxBlanc);
    pxTestNoir = getPix(1,2);
    assert(pxTestNoir.getVert()==255);
    assert(pxTestNoir.getRouge()==255);
    assert(pxTestNoir.getBleu()==255);
    Pixel pxCouleur(145,167,23);
    setPix(1,1,pxCouleur);
    Pixel Test = getPix(1,1);
    assert(Test.getRouge()==145);
    assert(Test.getVert()==167);
    assert(Test.getBleu()==23);
}


void Image::sauver(const string & filename) const {
    ofstream fichier (filename.c_str());
    assert(fichier.is_open());
    //fichier << "P3" << endl;  //A quoi ça sert zebi ? A rien ?
    fichier << dimx << " " << dimy << endl;
    //fichier << "255" << endl; //A quoi ça sert zebi ? A rien ?
    for(unsigned int y=0; y<dimy; y++) //y++
        //{
        for(unsigned int x=0; x<dimx; x++) //x++
         {
            Pixel pix = getPix(x,y); //Pixel& to Pixel
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " "; //accesseurs
        }
        //}
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const string & filename) {
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
    string r,g,b; //char to string
    string mot;
    dimx = dimy = 0; //séparer les =
    fichier /*>> mot*/ >> dimx >> dimy /*>> mot*/; //mot servait à enlever P3 et 255
    assert(dimx > 0 && dimy > 0);
    if (tab != NULL) delete [] tab;
    tab = new Pixel [dimx*dimy];
    for(unsigned int y=0; y<dimy; y++) //y++
        //{
        for(unsigned int x=0; x<dimx; x++) //x++
        {
            fichier >> r >> g >> b;  //inverser b et g
            Pixel couleur(stoi(r),stoi(g), stoi(b)); //stoi() string to int (unsigned int ça serait mieux)
            setPix(x,y,couleur);   //getPix to setPix
            setPix(x,y,couleur);
            setPix(x,y,couleur);
        }
        //}
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficherConsole(){
    cout << dimx << " " << dimy << endl;
    for(unsigned int y=0; y<dimy; y++) //y++
    {
        for(unsigned int x=0; x<dimx; x++) //x++ 
        {
            Pixel pix = getPix(x,y); //Pixel& to Pixel
            cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
        cout << endl;
    }
}

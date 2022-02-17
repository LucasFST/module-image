#include <string.h>
using namespace std;

//constructeur de l'image par defaut 
Image::Image()
{
    dimx=0;
    tab = NULL;
}


//constructeur avec des parametres rentrés par l'uti 
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


//destructeur par defaut
Image::~Image()
    {
        if(tab != NULL)
    }



Pixel Image::getPix (unsigned int x,unsigned int y) const
    {
        assert (x<dimx && y<dimy );//taille limitée pour dimx et dimy, pas de verification si negatif puisque ce sont des unsigned int.
        return tab[y*dimx+x];  //y*dimx+y+x
        assert (x<dimx && y<dimy ); //x et y doivent être respectivement plus petit que dimx et dimy
        return tab[y*dimx+x];  //formule pour passer d'un tab 2D à un tab 1D

    }



void Image::setPix (unsigned int x,unsigned int y, const Pixel& couleur)
    {
        assert (x<dimx && y<dimy );
        assert (x<dimx && y<dimy ); //x et y doivent être respectivement plus petit que dimx et dimy
        
        tab [y*dimx+x].setRouge(couleur.getRouge());  //on attribue un couleur bien spécifique a notre pixel (R G B)
        tab [y*dimx+x].setVert(couleur.getVert());
        tab [y*dimx+x].setRouge(couleur.getRouge());
        tab [y*dimx+x].setBleu(couleur.getBleu());
    }




void Image::dessinerRectangle (unsigned int Xmin,unsigned int Ymin,unsigned int Xmax,unsigned int Ymax, const Pixel& couleur)
     {
        for (unsigned int i=Ymin; i<=Ymax; i++)
        for (unsigned int i=Ymin; i<=Ymax; i++) 
            {
            for (unsigned int j=Xmin; j<=Xmax; j++ )
                {
                   setPix(j,i,couleur);
                   setPix(j,i,couleur); //on change la couleur des pixels qui seront dans le rectangle 
                }

            }
     }




void Image::effacer (const Pixel& couleur)
    {
        dessinerRectangle (0,0,dimx-1,dimy-1,couleur);
        dessinerRectangle (0,0,dimx-1,dimy-1,couleur); // on recouvre toute l'image par la couleur en parametre grâce a dessinerRectange 

    }

void Image::testRegression () //const



void Image::testRegression ()
{
    dimx=2;
    dimy=3;
    tab = new Pixel[dimx*dimy];
    Pixel pxTestNoir = getPix(1,2);
    assert(pxTestNoir.getVert()==0);
    dimx=2; //valeur choisi arbitrairement 
    dimy=3; //valeur choisi arbitrairement 

    tab = new Pixel[dimx*dimy]; //on alloue un tab de pixel sur le tas avec les valeurs dimx et dimy
    Pixel pxTestNoir = getPix(1,2); //on prend un pixel dans l'image
    assert(pxTestNoir.getVert()==0);//on teste si ce pixel est bien noir (couleur par defaut = 0;0;0)
    assert(pxTestNoir.getRouge()==0);
    assert(pxTestNoir.getBleu()==0);
    Pixel pxBlanc(255,255,255);
    dessinerRectangle(0,0,1,1, pxBlanc);
    Pixel pxTestBlanc = getPix(0,0);
    assert(pxTestBlanc.getVert()==255);

    Pixel pxBlanc(255,255,255); //on creer un pixel blanc 
    dessinerRectangle(0,0,1,1, pxBlanc); // on dessine un rectangle avec ce pixel (en blanc) sur une partie de l'image 
    Pixel pxTestBlanc = getPix(0,0); //on prend un pixel dans ce rectangle 
    assert(pxTestBlanc.getVert()==255); // on teste si il est bien blanc (255,255,255)
    assert(pxTestBlanc.getRouge()==255);
    assert(pxTestBlanc.getBleu()==255);
    assert(pxTestNoir.getVert()==0);

    //on teste si le pixel noir l'est toujours (il n'a pas été recouvert par le rectangle)
    assert(pxTestNoir.getVert()==0); 
    assert(pxTestNoir.getRouge()==0);
    assert(pxTestNoir.getBleu()==0);
    effacer(pxBlanc);
    pxTestNoir = getPix(1,2);

    effacer(pxBlanc); // rempli l'image par un rectangle entierement blanc 
    pxTestNoir = getPix(1,2); // on prend le pixel anciennement noir et on teste si il est blanc (255,255,255)
    assert(pxTestNoir.getVert()==255);
    assert(pxTestNoir.getRouge()==255);
    assert(pxTestNoir.getBleu()==255);
    Pixel pxCouleur(145,167,23);
    setPix(1,1,pxCouleur);
    Pixel Test = getPix(1,1);
    assert(Test.getRouge()==145);

    Pixel pxCouleur(145,167,23); //on creer un pixel(pxCouleur) d'une couleur arbitraire
    setPix(1,1,pxCouleur); //on change un pixel blanc par le pxCouleur 
    Pixel Test = getPix(1,1); //on recupere le pixel que l'on vient de modifier 
    assert(Test.getRouge()==145); //on verifie qu'il est bien de la couleur que l'on souhaite 
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

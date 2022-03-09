#include "Image.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <string.h>

using namespace std;

//constructeur de l'image par defaut 
Image::Image()
{
    dimx=0;
    dimy=0;
    tab = NULL;
    window = NULL;
    renderer = NULL;
}


//constructeur avec des parametres rentrés par l'uti 
Image::Image(unsigned int dimX, unsigned int dimY)
{
    assert (dimX<50000 && dimY<50000 ); //taille limitée pour dimX et dimY, pas de verification si negatif puisque ce sont des unsigned int.
    dimx=dimX;
    dimy=dimY;
    tab=new Pixel[dimX*dimY];   
}


//destructeur par defaut
Image::~Image()
{
    if(tab != NULL) 
    {
       delete[] tab;
    }
    tab=NULL;
    if(window != NULL) 
    {
       window = NULL;
    }
    if(renderer != NULL) 
    {
       renderer = NULL;
    }
    dimx=0;
    dimy=0;
}


Pixel& Image::getPix (unsigned int x,unsigned int y) const 
{
    assert (x<dimx && y<dimy ); //x et y doivent être respectivement plus petit que dimx et dimy
    return tab[y*dimx+x];  //formule pour passer d'un tab 2D à un tab 1D
}


void Image::setPix (unsigned int x,unsigned int y, const Pixel& couleur)
{
    assert (x<dimx && y<dimy ); //x et y doivent être respectivement plus petit que dimx et dimy
        
    tab [y*dimx+x].setRouge(couleur.getRouge());  //on attribue un couleur bien spécifique a notre pixel (R G B)
    tab [y*dimx+x].setVert(couleur.getVert());
    tab [y*dimx+x].setBleu(couleur.getBleu());
}


void Image::dessinerRectangle (unsigned int Xmin,unsigned int Ymin,unsigned int Xmax,unsigned int Ymax, const Pixel& couleur)
{
    for (unsigned int i=Ymin; i<=Ymax; i++) 
    {
        for (unsigned int j=Xmin; j<=Xmax; j++ )
        {
            setPix(j,i,couleur); //on change la couleur des pixels qui seront dans le rectangle 
        }

    }
}


void Image::effacer (const Pixel& couleur)
{
    dessinerRectangle (0,0,dimx-1,dimy-1,couleur); // on recouvre toute l'image par la couleur en parametre grâce a dessinerRectange 
}


void Image::testRegression ()
{

    //test constructeur par défaut 
    Image img;
    assert (img.dimx==0 && img.dimy==0 && img.tab==NULL);

    dimx=2; //valeur choisi arbitrairement 
    dimy=3; //valeur choisi arbitrairement 

    tab = new Pixel[dimx*dimy]; //on alloue un tab de pixel sur le tas avec les valeurs dimx et dimy
    Pixel& pxTestNoir = getPix(1,2); //on prend un pixel dans l'image
    assert(pxTestNoir.getVert()==0);//on teste si ce pixel est bien noir (couleur par defaut = 0;0;0)
    assert(pxTestNoir.getRouge()==0);
    assert(pxTestNoir.getBleu()==0);

    Pixel pxBlanc(255,255,255); //on creer un pixel blanc 
    dessinerRectangle(0,0,1,1, pxBlanc); // on dessine un rectangle avec ce pixel (en blanc) sur une partie de l'image 
    Pixel& pxTestBlanc = getPix(0,0); //on prend un pixel dans ce rectangle 
    assert(pxTestBlanc.getVert()==255); // on teste si il est bien blanc (255,255,255)
    assert(pxTestBlanc.getRouge()==255);
    assert(pxTestBlanc.getBleu()==255);

    //on teste si le pixel noir l'est toujours (il n'a pas été recouvert par le rectangle)
    assert(pxTestNoir.getVert()==0); 
    assert(pxTestNoir.getRouge()==0);
    assert(pxTestNoir.getBleu()==0);

    effacer(pxBlanc); // rempli l'image par un rectangle entierement blanc 
    pxTestNoir = getPix(1,2); // on prend le pixel anciennement noir et on teste si il est blanc (255,255,255)
    assert(pxTestNoir.getVert()==255);
    assert(pxTestNoir.getRouge()==255);
    assert(pxTestNoir.getBleu()==255);

    Pixel pxCouleur(145,167,23); //on creer un pixel(pxCouleur) d'une couleur arbitraire
    setPix(1,1,pxCouleur); //on change un pixel blanc par le pxCouleur 
    Pixel& Test = getPix(1,1); //on recupere le pixel que l'on vient de modifier 
    assert(Test.getRouge()==145); //on verifie qu'il est bien de la couleur que l'on souhaite 
    assert(Test.getVert()==167);
    assert(Test.getBleu()==23);

    cout<<"Test de Regression passé avec succès"<<endl;
}


void Image::sauver(const string & filename) const 
{
    ofstream fichier (filename.c_str());
    assert(fichier.is_open());
    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;
    for(unsigned int y=0; y<dimy; y++) 
        for(unsigned int x=0; x<dimx; x++) 
        {
            Pixel& pix = getPix(x,y); 
            fichier << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " "; 
        }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}


void Image::ouvrir(const string & filename) 
{
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
    string r,g,b; //à la place de char car char fait chiffre par chiffre
    string mot;
    dimx = dimy = 0; 
    fichier >> mot >> dimx >> dimy >> mot;
    assert(dimx > 0 && dimy > 0);
    if (tab != NULL) delete [] tab;
    tab = new Pixel [dimx*dimy];
    for(unsigned int y=0; y<dimy; y++) 
        for(unsigned int x=0; x<dimx; x++) 
        {
            fichier >> r >> g >> b;  
            Pixel couleur(stoi(r),stoi(g),stoi(b)); //car string et pas char
            setPix(x,y,couleur);   
        }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}


void Image::afficherConsole()
{
    cout << dimx << " " << dimy << endl;
    for(unsigned int y=0; y<dimy; y++) 
    {
        for(unsigned int x=0; x<dimx; x++) 
        {
            Pixel pix = getPix(x,y); 
            cout << +pix.getRouge() << " " << +pix.getVert() << " " << +pix.getBleu() << " ";
        }
        cout << endl;
    }
}


void Image::afficher() 
{
    afficherInit();
    afficherBoucle();
    afficherDetruit();
}


void Image::afficherInit() 
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    window = SDL_CreateWindow("Image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 200, 200, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) 
    {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    sauver("./data/image.ppm");

    imageSDL.loadFromFile("data/image.ppm", renderer);
    imageSDL.loadFromCurrentSurface(renderer);

}


void Image::afficherBoucle() 
{
    bool stop = false;
    SDL_Event events;
    int h,w,DIM;
    h=50;
    w=50;
    DIM=200;
    while (!stop)
    {
        while (SDL_PollEvent(&events)) 
        {
        
        if (events.type == SDL_QUIT) stop = true;           // Si l'utilisateur a clique sur la croix de fermeture
        else if (events.type == SDL_KEYDOWN) 
        {              // Si une touche est enfoncee
            switch (events.key.keysym.scancode) 
            {
            case SDL_SCANCODE_ESCAPE:
                stop = true;
            case SDL_SCANCODE_G:
                h=h*0.75;
                w=w*0.75;
                if(w<5) w=5;
                if(h<5) h=5;
                break;
            case SDL_SCANCODE_T:
                h=h*2;
                w=w*2;
                if(h>10000) h=10000;
                if(w>10000) w=10000;
                break;
            default: break;
            }
        }
        }
        SDL_SetRenderDrawColor(renderer, 206, 206, 206, 255); 
        SDL_RenderClear(renderer);
        imageSDL.draw(renderer, (DIM/2)-w/2, (DIM/2)-h/2, w, h);
        SDL_RenderPresent(renderer);
    }
}


void Image::afficherDetruit ()
{
    SDL_DestroyRenderer(renderer); 
    SDL_DestroyWindow(window); 
    SDL_Quit();
}



//-------------------------------------------------- Class Picture


Picture::Picture () 
{
    surface = NULL;
    texture = NULL;
    has_changed = false;
}


Picture::~Picture () 
{
    if(surface != NULL) 
    {
       surface = NULL;
    }
     if(texture != NULL) 
    {
       texture = NULL;
    }
}


void Picture::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    surface = IMG_Load(filename);
    if (surface == NULL) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == NULL) {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == NULL) {
        cout<<"Error: cannot load "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }
}


void Picture::loadFromCurrentSurface (SDL_Renderer * renderer) {
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}


void Picture::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,NULL,&r);
    assert(ok == 0);
}








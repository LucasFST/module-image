# Module Image

# Contributeurs : 

    p2020351 Faustmann Lucas
    p2002218 Brossat Pierrick 

# Presentation :

	Le projet module image permet de gérer des images et de les afficher grâce à la librairie SDL.
	Une image est en quelque sorte un tableau à 2 dimensions de largeur dimx et de hauteur dimy, dont les éléments sont des pixels (R,G,B). En interne, nous allons allouer un tableau 1D de taille dimxdimy. En externe (ie. le code utilisant le module Image) nous interpréterons l'image avec deux dimensions (x,y) en passant par les fonctions getPix (un accesseur) et setPix (un mutateur).

# Installation dépendances 

	Nous avons programmés notre module image en utilisant C++, SDL2.

	Pour installer sous Linux toutes les dépendances nécessaires pour notre projet il faut exécuter la commande suivante :
		~/sudo apt install doxygen libsdl2-dev libsdl2-image-dev 

	Pour installer g++, le compilateur C++, nécessaire pour compiler notre projet il faut exécuter la commande suivante :
		~/sudo apt-get install g++

# Compilation 

Pour compiler, utiliser la commande make : 

    ~/p2002218_p2020351$ make
    g++ -g -Wall -c src/Image.cpp -o obj/Image.o -I/usr/include/SDL2
    g++ -g -Wall obj/mainTest.o obj/Image.o obj/Pixel.o -o bin/test -lSDL2 -lSDL2_image
    g++ -g -Wall obj/mainExemple.o obj/Image.o obj/Pixel.o -o bin/exemple -lSDL2 -lSDL2_image
    g++ -g -Wall obj/mainAffichage.o obj/Image.o obj/Pixel.o -o bin/affichage -lSDL2 -lSDL2_image
    g++ -g -Wall -c src/mainTest.cpp -o obj/mainTest.o -lSDL2 -lSDL2_image
    g++ -g -Wall -c src/mainExemple.cpp -o obj/mainExemple.o -lSDL2 -lSDL2_image
    g++ -g -Wall -c src/mainAffichage.cpp -o obj/mainAffichage.o -lSDL2 -lSDL2_image
    g++ -g -Wall -c src/Image.cpp -o obj/Image.o -lSDL2 -lSDL2_image
    g++ -g -Wall -c src/Pixel.cpp -o obj/Pixel.o

Pour "nettoyer" les dossiers bin, obj et data (supprimer les éxécutables dans bin, les .o dans obj et les images dans data) nous utilisons la commande make clean : 

    ~/p2002218_p2020351$ make clean 
    rm -f obj/*
    rm -f bin/*
    rm -f data/* 

# Arborescence

	p2002218_p2020351/
	├─ bin/
	│  ├─ contient les exécutables du projet (affichage, exemple, test)
	├─ data/
	│  ├─ contient les images du projet  
	├─ doc/
	│  ├─ image.doxy
	│  ├─ html/
	│  │  ├─ contient tous les fichiers nécessaires à la documentation en html
	├─ makefile
	├─ obj/
	│  ├─ contient les fichiers objets du projet (Image.o, Pixel.o, ...)
	├─ Readme.txt
	├─ src/
	│  ├─ Pixel.h
	│  ├─ Pixel.cpp
	│  ├─ Image.h
	│  ├─ Image.cpp
	│  ├─ mainTest.cpp
	│  ├─ mainExemple.cpp
	│  ├─ mainAffichage.cpp

- Les fichiers sources (.h et .cpp) sont placés dans le dossier src
- Les images sauvées et lues seront toujours placées dans le dossier data
- doc/image.doxy est le fichier de configuration de doxygen
- doc/html/index.html est la page d'entrée de la documentation (générée avec doxygen)

# Utilisation

Le projet permet de créer tois exécutables bin/affichage, bin/exemple, bin/test.

## bin/affichage : cet exécutable permet d'afficher une image d'une maison qui sera placée au centre d'une fenêtre SDL2 de taille 200×200 pixels de fond gris clair. Il est possible de zoomer/dézoomer sur l'image grâce respectivement aux touches T et G et de quitter la procédure afficher() grâce à la touche ESCAPE.

	Pour le lancer :
		~/p2002218_p2020351$ ./bin/affichage

## bin/exemple: cet exécutable permet de créer une image et de l'enregistrer dans notre dossier data avant de la modifier et d'enregistrer ses modifications via une nouvelle image toujours placée dans le dossier data

	Pour le lancer :
		~/p2002218_p2020351$ ./bin/exemple

## bin/test : cet exécutable permet d'appeler la procédure testRegression() de la classe Image afin de faire passer une multitude de tests à notre module image afin de vérifier que ce dernier fonctionne correctement

	Pour le lancer :
		~/p2002218_p2020351$ ./bin/test


# Documentation du code

Voir doc/html/index.html pour accéder à la documentation des classes Image, Picture et Pixel

	NB : pour la générer : 
	 	~/p2002218_p2020351$ doxygen doc/image.doxy

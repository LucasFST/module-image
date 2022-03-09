CC := g++ -g -Wall

all : bin/test bin/exemple bin/affichage

bin/test : obj/mainTest.o obj/Image.o obj/Pixel.o
	$(CC) obj/mainTest.o obj/Image.o obj/Pixel.o -o bin/test -lSDL2 -lSDL2_image

bin/exemple : obj/mainExemple.o obj/Image.o obj/Pixel.o
	$(CC) obj/mainExemple.o obj/Image.o obj/Pixel.o -o bin/exemple -lSDL2 -lSDL2_image

bin/affichage : obj/mainAffichage.o obj/Image.o obj/Pixel.o
	$(CC) obj/mainAffichage.o obj/Image.o obj/Pixel.o -o bin/affichage -lSDL2 -lSDL2_image

obj/mainTest.o : src/mainTest.cpp src/Image.h src/Pixel.h
	$(CC) -c src/mainTest.cpp -o obj/mainTest.o -I/usr/include/SDL2  

obj/mainExemple.o : src/mainExemple.cpp src/Image.h src/Pixel.h
	$(CC) -c src/mainExemple.cpp -o obj/mainExemple.o -I/usr/include/SDL2  

obj/mainAffichage.o : src/mainAffichage.cpp src/Image.h src/Pixel.h
	$(CC) -c src/mainAffichage.cpp -o obj/mainAffichage.o -I/usr/include/SDL2  

obj/Image.o : src/Image.cpp src/Image.h src/Pixel.h
	$(CC) -c src/Image.cpp -o obj/Image.o -I/usr/include/SDL2

obj/Pixel.o : src/Pixel.cpp src/Pixel.h
	$(CC) -c src/Pixel.cpp -o obj/Pixel.o


clean :
	rm -f obj/*
	rm -f bin/*
	rm -f data/*









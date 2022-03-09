CC := g++ -g -Wall
SDL2 := -lSDL2 -lSDL2_image
SDL2_OBJ := -I/usr/include/SDL2  


all : bin/test bin/exemple bin/affichage

bin/test : obj/mainTest.o obj/Image.o obj/Pixel.o
	$(CC) obj/mainTest.o obj/Image.o obj/Pixel.o -o bin/test $(SDL2)

bin/exemple : obj/mainExemple.o obj/Image.o obj/Pixel.o
	$(CC) obj/mainExemple.o obj/Image.o obj/Pixel.o -o bin/exemple $(SDL2)

bin/affichage : obj/mainAffichage.o obj/Image.o obj/Pixel.o
	$(CC) obj/mainAffichage.o obj/Image.o obj/Pixel.o -o bin/affichage $(SDL2)

obj/mainTest.o : src/mainTest.cpp src/Image.h src/Pixel.h
	$(CC) -c src/mainTest.cpp -o obj/mainTest.o $(SDL2_OBJ)

obj/mainExemple.o : src/mainExemple.cpp src/Image.h src/Pixel.h
	$(CC) -c src/mainExemple.cpp -o obj/mainExemple.o $(SDL2_OBJ) 

obj/mainAffichage.o : src/mainAffichage.cpp src/Image.h src/Pixel.h
	$(CC) -c src/mainAffichage.cpp -o obj/mainAffichage.o $(SDL2_OBJ)  

obj/Image.o : src/Image.cpp src/Image.h src/Pixel.h
	$(CC) -c src/Image.cpp -o obj/Image.o $(SDL2_OBJ)

obj/Pixel.o : src/Pixel.cpp src/Pixel.h
	$(CC) -c src/Pixel.cpp -o obj/Pixel.o


clean :
	rm -f obj/*
	rm -f bin/*
	rm -f data/*









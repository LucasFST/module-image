.PHONY: veryclean clean all
CC := g++
CCFLAGS := -g -Wall
OBJS1 := bin/Pixel.o bin/Image.o
OBJS2 := src/Pixel.h src/Image.h
BIN := bin
BIN1 := bin/test
BIN2 := bin/exemple
BIN3 := bin/affichage
SRC := src


all : $(BIN1) $(BIN2) $(BIN3)

$(BIN1) : $(BIN)/mainTest.o $(OBJS1)
	$(CC) $(CCFLAGS) $(BIN)/mainTest.o $(OBJS1) -o $(BIN1) -lSDL2 -lSDL2_image

$(BIN2) : $(BIN)/mainExemple.o $(OBJS1)
	$(CC) $(CCFLAGS) $(BIN)/mainExemple.o $(OBJS1) -o $(BIN2)  -lSDL2 -lSDL2_image

bin/affichage : bin/mainAffichage.o bin/Pixel.o  bin/Image.o 
	$(CC) $(CCFLAGS) bin/mainAffichage.o bin/Pixel.o  bin/Image.o -o bin/affichage -lSDL2 -lSDL2_image

$(BIN)/mainTest.o : $(SRC)/mainTest.cpp $(OBJS2)
	$(CC) $(CCFLAGS) -c $(SRC)/mainTest.cpp -o $(BIN)/mainTest.o -I/usr/include/SDL2

$(BIN)/mainExemple.o : $(SRC)/mainExemple.cpp $(OBJS2)
	$(CC) $(CCFLAGS) -c $(SRC)/mainExemple.cpp -o $(BIN)/mainExemple.o -I/usr/include/SDL2

bin/mainAffichage.o : src/mainAffichage.cpp src/Image.h src/Pixel.h
	$(CC) $(CCFLAGS) -c src/mainAffichage.cpp -o bin/mainAffichage.o -I/usr/include/SDL2

$(BIN)/Image.o : $(SRC)/Image.cpp $(OBJS2)
	$(CC) $(CCFLAGS) -c $(SRC)/Image.cpp -o $(BIN)/Image.o -I/usr/include/SDL2

$(BIN)/Pixel.o : $(SRC)/Pixel.cpp $(SRC)/Pixel.h
	$(CC) $(CCFLAGS) -c $(SRC)/Pixel.cpp -o $(BIN)/Pixel.o





clean :
	rm -f bin/*










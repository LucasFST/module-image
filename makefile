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

INCLUDE_DIR_SDL := -I/usr/include/SDL2
LIBS_SDL := -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

all : $(BIN1) $(BIN2) $(BIN3)

$(BIN1) : $(BIN)/mainTest.o $(OBJS1)
	$(CC) $(CCFLAGS) $(BIN)/mainTest.o $(OBJS1) -o $(BIN1) 

$(BIN2) : $(BIN)/mainExemple.o $(OBJS1)
	$(CC) $(CCFLAGS) $(BIN)/mainExemple.o $(OBJS1) -o $(BIN2) 

$(BIN3) : $(BIN)/mainAffichage.o $(OBJS1)
	$(CC) $(CCFLAGS) $(BIN)/mainAffichage.o $(OBJS1) -o $(BIN3) $(LIBS_SDL)

$(BIN)/mainTest.o : $(SRC)/mainTest.cpp $(OBJS2)
	$(CC) $(CCFLAGS) -c $(SRC)/mainTest.cpp -o $(BIN)/mainTest.o

$(BIN)/mainExemple.o : $(SRC)/mainExemple.cpp $(OBJS2)
	$(CC) $(CCFLAGS) -c $(SRC)/mainExemple.cpp -o $(BIN)/mainExemple.o 

$(BIN)/mainAffichage.o : $(SRC)/mainAffichage.cpp $(OBJS2)
	$(CC) $(CCFLAGS) -c $(SRC)/mainAffichage.cpp -o $(BIN)/mainAffichage.o $(INCLUDE_DIR_SDL)

$(BIN)/Image.o : $(SRC)/Image.cpp $(OBJS2)
	$(CC) $(CCFLAGS) -c $(SRC)/Image.cpp -o $(BIN)/Image.o

$(BIN)/Pixel.o : $(SRC)/Pixel.cpp $(SRC)/Pixel.h
	$(CC) $(CCFLAGS) -c $(SRC)/Pixel.cpp -o $(BIN)/Pixel.o



veryclean : clean
	rm -rf $(BIN)

clean :
	rm -f $(BIN)/*.o










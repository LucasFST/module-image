.PHONY: veryclean clean all
CC := g++
CCFLAGS := -g -Wall
OBJS1 := Pixel.o Image.o
OBJS2 := Pixel.h Image.h
BIN := ./bin
BIN1 := ./bin/test
BIN2 := ./bin/exemple

all : $(BIN1) $(BIN2) 

$(BIN1) : mainTest.o $(OBJS1)
	$(CC) $(CCFLAGS) mainTest.o $(OBJS1) -o $(BIN1)

$(BIN2) : mainExemple.o $(OBJS1)
	$(CC) $(CCFLAGS) mainExemple.o $(OBJS1) -o $(BIN2)

mainTest.o : mainTest.cpp $(OBJS2)
	$(CC) $(CCFLAGS) -Isrc -c mainTest.cpp

mainExemple.o : mainExemple.cpp $(OBJS2)
	$(CC) $(CCFLAGS) -Isrc -c mainExemple.cpp

Image.o : Image.cpp $(OBJS2)
	$(CC) $(CCFLAGS) -Isrc -c Image.cpp

Pixel.o : Pixel.cpp Pixel.h
	$(CC) $(CCFLAGS) -Isrc -c Pixel.cpp

veryclean : clean
	rm -rf $(BIN)

clean :
	rm $(BIN)/*.o






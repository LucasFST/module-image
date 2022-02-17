all : executable.out #doit compiler les différents mains --> test / exemple / .... et dans les bons fichiers

executable.out : mainTest.o Pixel.o Image.o
	g++ -g -Wall mainTest.o Pixel.o Image.o -o executable.out

mainTest.o : mainTest.cpp Pixel.h Image.h
	g++ -g -Wall -c mainTest.cpp

Image.o : Image.cpp Image.h Pixel.h
	g++ -g -Wall -c Image.cpp

Pixel.o : Pixel.cpp Pixel.h
	g++ -g -Wall -c Pixel.cpp

clean :
	rm *.o

veryclean : 
	clean rm *.out

# Factoriser le makefile avec des variables


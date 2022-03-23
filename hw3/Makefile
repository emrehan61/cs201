
GCC = g++
CXXFLAGS = -g -Wall


hw3: ConsoleApplication1.o Flower.o FlowerLibrary.o FlowerList.o
	g++ -g -o hw3  ConsoleApplication1.o FlowerLibrary.o FlowerList.o Flower.o

ConsoleApplication1.o: ConsoleApplication1.cpp FlowerLibrary.o
	g++ -c -g ConsoleApplication1.cpp

FlowerLibrary.o:FlowerLibrary.cpp FlowerLibrary.h FlowerList.o
	g++ -c FlowerLibrary.cpp


FlowerList.o: FlowerList.cpp FlowerList.h Flower.o
	g++ -c FlowerList.cpp

Flower.o: Flower.cpp Flower.h
	g++ -c Flower.cpp

.PHONY: clean

clean:
	rm -f *.exe *.o

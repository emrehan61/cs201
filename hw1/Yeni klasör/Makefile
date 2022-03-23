
GCC = g++
CXXFLAGS = -g -Wall


hw1: main.o cabinet.o labOrganizer.o
	g++ -g -o hw1  main.o cabinet.o labOrganizer.o

main.o: main.cpp labOrganizer.o
	g++ -c -g main.cpp

labOrganizer.o:labOrganizer.cpp labOrganizer.h cabinet.o
	g++ -c labOrganizer.cpp


cabinet.o: cabinet.cpp cabinet.h
	g++ -c cabinet.cpp

.PHONY: clean

clean:
	del -f *.exe *.o

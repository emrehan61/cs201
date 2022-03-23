
GCC = g++
CXXFLAGS = -g -Wall


hw1: main.o cabinet.o LabOrganizer.o
	g++ -g -o hw1  main.o cabinet.o LabOrganizer.o

main.o: main.cpp LabOrganizer.o
	g++ -c -g main.cpp

labOrganizer.o:LabOrganizer.cpp LabOrganizer.h cabinet.o
	g++ -c LabOrganizer.cpp


cabinet.o: cabinet.cpp cabinet.h
	g++ -c cabinet.cpp

.PHONY: clean

clean:
	del -f *.exe *.o

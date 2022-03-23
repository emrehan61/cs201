#ifndef LABORGANIZER_H
#define LABORGANIZER_H
#include <iostream>
#include "cabinet.h"
class labOrganizer{
public:
  labOrganizer();
  ~labOrganizer();
  void addCabinet(int id, int rows, int colunm);
  void removeCabinet(int id);
  void listCabinets();
  void cabinetContents();
  void placeChemical(int cabinetId, std::string location,std::string chemicaltype,int chemicalid);
  void findChemical(int id);
  void removeChemical(int id);
  bool cabIdCheck(int id);
  
  int found = 0;
  int carry = 0;
private:
  int size = 0;
  cabinet* cabinets;

  int check;
  std::string posss;



};
#endif

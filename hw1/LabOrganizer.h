#ifndef LABORGANIZER_H
#define LABORGANIZER_H
#include <iostream>
#include "cabinet.h"
class LabOrganizer{
public:
  LabOrganizer();
  ~LabOrganizer();
  void addCabinet(int id, int rows, int colunm);
  void removeCabinet(int id);
  void listCabinets();
  void cabinetContents(int id);
  void placeChemical(int cabinetId, std::string location,std::string chemicaltype,int chemicalid);
  void findChemical(int id);
  void removeChemical(int id);
  bool cabIdCheck2(int id);
  bool cabIdCheck(int id);

  int found ;
  int carry ;
private:
  int size ;
  cabinet* cabinets;

  int check;
  std::string posss;



};
#endif

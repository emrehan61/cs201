#ifndef CABINET_H
#define CABINET_H
#include <string>
#include <iostream>
#include<stdio.h>
class cabinet{
public:
  cabinet(int cabinetid,int row,int colunm);
  cabinet();
  
  int getId();
  void addChemical(std::string chemicalpos,std::string chemicaltype,int chemicalid);
  void removeChemical2(std::string chemicalpos);
  //void operator= (const cabinet &right);
  bool checkChemical(int chemicalid);
  bool checkChemical2(std::string pos);
  void createArray(int row, int colunm);
  bool fullChecker(char type, int row, int colunm);
  void printCabinet();
  void printChemicals();

  void selfdes();
  int tr;
  int tc;
  int emptycount;
  void addId(int id);
  void delId(int id);
  void addPos(std::string position);
  void delPos(std::string position);
  void printids();
  void printrows();
  std::string info;
  std::string *poss;
  int checkk ;
  std::string its(int id);
  int posindex;
private:
  int cabinetid;
  int size1;
  int size2;
  char** chems;
  std::string id;

  int* ids;
  char colids[9];
  std::string rowids ;

};
#endif

#ifndef CABINET_H
#define CABINET_H
#include <string>
#include <iostream>
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
  int emptycount = 0;
  void addId(int id);
  void delId(int id);
  void addPos(std::string position);
  void delPos(std::string position);
  void printids();
  void printrows();
  std::string info;
  std::string *poss;
  int checkk ;
  int posindex;
private:
  int cabinetid;
  int size1 = 0;
  int size2 = 0;
  char** chems;
  std::string id;

  int* ids;

  char colids[9] = {'1','2','3','4','5','6','7','8','9'};
  std::string rowids = {"ABCDEFGHI"};
};
#endif

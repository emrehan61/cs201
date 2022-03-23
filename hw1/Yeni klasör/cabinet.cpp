#include "cabinet.h"

cabinet::cabinet(int cabinetid, int row, int colunm){

  this->cabinetid = cabinetid;
  createArray(row, colunm);
  ids = new int[size1];
  poss = new std::string[size2];
  tr = row;
  tc = colunm;

}
/*void cabinet::operator= (const cabinet &right){

  if(&right != this){

    tr =  right.tr;
    tc = right.tc;
    for(int i = 0; i <= tr; ++i) {
          delete[] chems[i];
      }

    delete[] chems;
    delete [] ids;
    delete [] poss;
    emptycount = right.emptycount;
    info = right.info;

    checkk = right.checkk;
    posindex = right.posindex;
    cabinetid = right.cabinetid;
    size1 = right.size1;
    size2 = right.size2;
    chems = right.chems;
    id = right.id;
    this->createArray(tr,tc);
    for(int i = 0;i<tr+1;i++){
      for(int j = 0;j<tc+1;j++){
        chems[i][j] = right.chems[i][j];
      }
    }
    ids = new int[size1];
    poss = new std::string[size2];
    for(int i = 0 ;i<size1;i++){
      ids[i] = right.ids[i];

    }
    for(int i = 0;i<size2;i++){

      poss[i] = right.poss[i];
    }


  }
}*/
cabinet::cabinet(){}


void cabinet::selfdes(){
  for(int i = 0; i <= tr; ++i) {
        delete[] chems[i];
    }

    delete[] chems;
    delete [] ids;
    delete [] poss;}


void cabinet::createArray(int row, int colunm){

    chems = new char*[row+1];
    for(int i = 0;i<row+1;i++){

      chems[i] = new char [colunm+1];

    }
    chems[0][0] = ' ';
    for(int i = 1;i<=row;i++){

      chems[i][0] = rowids[i-1];
    }
    for(int i = 1;i<=colunm;i++){

      chems[0][i] = colids[i-1];

    }
    for(int i = 1;i<=row;i++){
      for(int j = 1;j<=colunm;j++){
        chems[i][j] = '+';

      }

    }

}

int cabinet::getId(){

  return cabinetid;

}
void cabinet::addChemical(std::string chemicalpos,std::string chemicaltype,int id){

  if(!checkChemical(id)){
        int boole = 0;
        int tempos = 0;
        int tempc = chemicalpos[1]-'0';

        for(int i = 0;i<rowids.length();i++){

          if(chemicalpos[0] == rowids[i]){

            boole = 1;
            tempos = i+1;

            break;


          }


        }
        if(boole){

          if(tempc <=9 && tempc>=1 && fullChecker(chemicaltype[0],tempos ,tempc)){
            chems[tempos][tempc] = chemicaltype[0];
            emptycount++;

            addId(id);

            addPos(chemicalpos);


          }
          else std::cout << "invalid colunm or dangerzone" << '\n';

        }

  }
  else std::cout << "chemical already included" << '\n';

}
bool cabinet::checkChemical(int chemicalid){
  for(int i = 0;i<size1;i++){
    if(ids[i] == chemicalid){
      std::string xx = std::to_string(ids[i]);
      std::string x =  std::to_string(getId());
    //  std::cout << "chemical already exist" << '\n';
      info = std::string("Cabinet ID: ")+x+" Chemical Pos " + poss[i] +" chemical id" +xx;
      checkk = i;
      return true;
      break;
    }


  }
  return false;

}

bool cabinet::fullChecker(char type, int row, int colunm){


    if(type == 'r'){

    if(chems[row][colunm] == '+'){


      return true;

    }
    else{


      std::cout << "place is full " << '\n';
      return false;
    }
  }
  if(type == 'c'){
    int x;
    int j ;

    if(row == 1) {

      x = row;}
    else if(row > 1) x = row-1;
    if(colunm == 1) j = colunm;
    else if(colunm>1) {
      j = colunm -1;}
    for(x;x<=row+1;x++){
      for(j;j<=colunm+1;j++){

        if(chems[x][j] == 'c'){
          std::cout << "there is another combustive in danger zone" << '\n';

          return false;
          break;
        }
        if(x+1>tr || j+1 >tc){

          return true;
          break;

        }


      }


    }


    return true;
  }
  else return false;


}
void cabinet::removeChemical2(std::string chemicalpos){
if(size1 > 0 && size2 >0){
  if(checkChemical2(chemicalpos)){
  int tempos;
  int tempc = chemicalpos[1]-'0';
  for(int i = 0;i<rowids.length();i++){

    if(chemicalpos[0] == rowids[i]){

      tempos = i+1;
      if(tempc >= 1 && tempc<=9){

       chems[tempos][tempc] = '+';


       delId(ids[posindex]);
       delPos(chemicalpos);

       emptycount--;

      }
        else std::cout << "not valid colunm" << '\n';
      break;


    }
  }
}
}
else std::cout << "cabinet is empty " << '\n';
}
void cabinet::printCabinet(){

  for(int i = 0;i<=tr;i++){
    std::cout <<'\n';
    for(int j = 0;j<=tc;j++){

      std::cout << chems[i][j] << ' ';
    }
  }
  std::cout << '\n';

}
void cabinet::printChemicals(){
    std::cout <<getId()<<" "<<"Empty slot: " <<(tr*tc)-emptycount<< " chemicals are" << " ";
    int checker = 0;
    for(int x = 1;x<=tr;x++){
      for(int j = 1;j<=tc;j++){

        if(chems[x][j] == 'r' || chems[x][j] == 'c'){
          std::cout << rowids[x-1] <<j<< " ";
          checker++;
        }
        if(x == tr && j == tc && checker == 0){

          std::cout << "none" << '\n';
        }

      }

    }

}
void cabinet::addId(int id){

  int* temparr3 = new int[size1+1];
  
  for(int i = 0;i<size1;i++){

    temparr3[i] = ids[i];
  }

  delete[] ids;

  ids = temparr3;

  ids[size1] = id;

  size1++;

}
void cabinet::addPos(std::string position){

  std::string* temparr4 = new std::string[size2+1];
  for(int i = 0;i<size2;i++){
    temparr4[i] = poss[i];

  }
  delete[] poss;
  poss = temparr4;
  poss[size2] = position;
  size2++;
}
void cabinet::delId(int id){
   if(size1 > 0){

    if (checkChemical(id)) {
      int* temparr5 = new int [size1-1];
      ids[checkk] = 0;
      for(int i = 0;i<size1-1;i++){
        if(ids[i] != 0){

          temparr5[i] = ids[i];
        }
        else temparr5[i] = ids[i+1];


      }
      delete[] ids;
      ids = temparr5;

      size1--;
    }
    else std::cout << "chemical cannot be found" << '\n';
      }
else std::cout << "there is no cabinet at all" << '\n';
    }

void cabinet::delPos(std::string position){
  if(size2 > 0){

    if (checkChemical2(position)) {

      std::string* temparr6 = new std::string [size2-1];
      for(int i = 0;i<size2-1;i++){
        if(i == posindex){

          poss[i] = "";

        }
      if(poss[i] != ""){
        temparr6[i] = poss[i];

      }
      else temparr6[i] = poss[i+1];
      }
      delete[] poss;
      poss = temparr6;

      size2--;
    }
    else std::cout << "cabinet cannot be found" << '\n';
      }
else std::cout << "there is no cabinet at all" << '\n';
    }
bool cabinet::checkChemical2(std::string pos){

  for(int i = 0;i<size2;i++){

    if(poss[i] == pos){
      posindex = i;
      return true;
    }

  }
  return false;
}
void cabinet::printids(){

  for(int i = 0;i<size1;i++){

    std::cout << ids[i] << " ";
  }
  std::cout << '\n';
}
void cabinet::printrows(){
  for(int i = 0;i<size2;i++){

  std::cout << poss[i] << " ";
}
std::cout << '\n';}

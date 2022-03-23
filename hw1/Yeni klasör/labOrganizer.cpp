#include "labOrganizer.h"

labOrganizer::labOrganizer(){

    cabinets = new cabinet[size];
}

labOrganizer::~labOrganizer(){
  
  for(int i = 0;i<size;i++){

    cabinets[i].selfdes();
  }
  delete [] cabinets;
}

void labOrganizer::addCabinet(int id, int rows, int colunm){
    cabinet temp (id,rows,colunm);
    cabinet* temparr = new cabinet[size+1];
    for(int i = 0;i<size;i++){
      temparr[0] = cabinets[i];

    }
    delete [] cabinets;
    cabinets = temparr;
    cabinets[size] = temp;
    size++;


}
void labOrganizer::listCabinets(){
  if(size > 0){for(int i = 0; i<size;i++){

    cabinets[i].printChemicals();
  }
}
else std::cout << "there is no cabinet" << '\n';


}
void labOrganizer::cabinetContents(){
  for(int i = 0; i<size;i++){
    std::cout << cabinets[i].getId() <<" "<<" "<<cabinets[i].tr<<"x"<<cabinets[i].tc<<" ";
    cabinets[i].printChemicals();
    std::cout << '\n';
    cabinets[i].printCabinet();
  }
}
void labOrganizer::removeCabinet(int id){

  if(size > 0){

    if (cabIdCheck(id)) {
      cabinet* temparr2 = new cabinet [size-1];
      for(int i = 0;i<size-1;i++){
        if(i != check){

          temparr2[i] = cabinets[i];
        }
        temparr2[i] = cabinets[i+1];

      }
      delete[] cabinets;
      cabinets = temparr2;
      std::cout << "deleted" << '\n';
      size--;
    }
    else std::cout << "cabinet cannot be found" << '\n';
      }
else std::cout << "there is no cabinet at all" << '\n';
    }


void labOrganizer::placeChemical(int cabinetId, std::string location,std::string chemicaltype,int chemicalid){

  if(cabIdCheck(cabinetId)){

    cabinets[check].addChemical(location,chemicaltype,chemicalid);

  }
  else std::cout << "there is no such cabinet" << '\n';

};

bool labOrganizer::cabIdCheck(int id){

  for (int i = 0;i<size;i++){
    if(cabinets[i].getId() == id) {
      check = i;
      return true;

  }

}
return false;
}
void labOrganizer::findChemical(int id){

  for(int i = 0;i<size;i++){
    if(cabinets[i].checkChemical(id)){
      std::cout << cabinets[i].info<<'\n';
      posss = cabinets[i].poss[cabinets[i].checkk];// to use in remove chemical
      found = 1;
      carry = i;
      break;
    }
    if(i == size-1){
    found = 0;
    carry = 0;}
  }
}
void labOrganizer::removeChemical(int id){
  findChemical(id);
  if(found){
    posss = cabinets[carry].poss[cabinets[carry].checkk];

    cabinets[carry].removeChemical2(posss);
    std::cout << "deleted" << '\n';

  }
  else std::cout << "chemical not found" << '\n';
}

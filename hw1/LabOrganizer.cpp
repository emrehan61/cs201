#include "LabOrganizer.h"

LabOrganizer::LabOrganizer(){

    cabinets = new cabinet[size];
    found = 0;
    carry = 0;
    size = 0;
}


LabOrganizer::~LabOrganizer(){

  for(int i = 0;i<size;i++){

    cabinets[i].selfdes();
  }
  delete [] cabinets;
}

void LabOrganizer::addCabinet(int id, int rows, int colunm){
    if(cabIdCheck2(id)){cabinet temp (id,rows,colunm);
    cabinet* temparr = new cabinet[size+1];
    for(int i = 0;i<size;i++){
      temparr[i] = cabinets[i];

    }

    delete [] cabinets;
    cabinets = temparr;
    cabinets[size] = temp;
    size++;}
}
void LabOrganizer::listCabinets(){
  if(size > 0){for(int i = 0; i<size;i++){

    cabinets[i].printChemicals();
    std::cout  << '\n';
  }
}
else std::cout << "there is no cabinet" << '\n';


}
void LabOrganizer::cabinetContents(int id){
  if(!cabIdCheck2(id)){
    for(int i = 0; i<size;i++){
    //  std::cout << cabinets[i].getId() <<" "<<" "<<cabinets[i].tr<<"x"<<cabinets[i].tc<<" ";
    if(cabinets[i].getId() == id){

       std::cout << cabinets[i].getId() <<" "<<" "<<cabinets[i].tr<<"x"<<cabinets[i].tc<<'\n';
        cabinets[i].printChemicals();
        std::cout << '\n';
        cabinets[i].printCabinet();
      }



    }
  }
  else std::cout << "there is no cabinet" << '\n';
}
void LabOrganizer::removeCabinet(int id){

  if(size > 0){

    if (cabIdCheck(id)) {
      cabinet* temparr2 = new cabinet [size-1];
      for(int i = 0;i<size-1;i++){
        if(i != check){

          temparr2[i] = cabinets[i];
        }
        else {

            temparr2[i] = cabinets[i+1];
            cabinets[i].selfdes();
      }

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


void LabOrganizer::placeChemical(int cabinetId, std::string location,std::string chemicaltype,int chemicalid){

  if(cabIdCheck(cabinetId)){

    cabinets[check].addChemical(location,chemicaltype,chemicalid);
    std::cout << "added" << '\n';
  }
  else std::cout << "there is no such cabinet" << '\n';

}

bool LabOrganizer::cabIdCheck(int id){

  for (int i = 0;i<size;i++){
    if(cabinets[i].getId() == id) {
      check = i;
      return true;
  }
}
return false;
}
bool LabOrganizer::cabIdCheck2(int id){
  for(int i = 0;i<size;i++){
    if(cabinets[i].getId() == id) return false;

  }
  return true;
}
void LabOrganizer::findChemical(int id){

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
void LabOrganizer::removeChemical(int id){
  findChemical(id);
  if(found){
    posss = cabinets[carry].poss[cabinets[carry].checkk];

    cabinets[carry].removeChemical2(posss);
    std::cout << "deleted" << '\n';

  }
  else std::cout << "chemical not found" << '\n';
}

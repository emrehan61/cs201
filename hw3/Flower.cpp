#include"Flower.h"

Flower::Flower(std::string flowerName){

  this->flowerName = flowerName;
  size = 0;
  head = NULL;

}
Flower::Flower(const Flower& aFlower){

  this->size = aFlower.size;
  this->flowerName = aFlower.flowerName;
  this-> head = aFlower.head;

}
Flower::Flower(){
    size = 0;
    head = NULL;
} 
Flower::~Flower(){// internetten deconstructor bak 
  FeatureNode* deleter = head;
  
  while (deleter != NULL){
      FeatureNode* deleter2 = deleter->next;
      delete deleter;
      deleter = deleter2
  
  }
  head = NULL;
}

bool Flower::isEmpty() const {
  if(this->size == 0) return true;
  else return false;
}

int Flower::getLength() const {

  return size;
}
bool Flower::add(std::string feature){
  //featureın varlığını kontrol eden başka bir if statement yazılmalı
  if(!detectFuture(feature)){

    
    if(head == NULL){
        FeatureNode* temp = new FeatureNode;
        temp->feature = feature;
      head = temp;
      head->next = NULL;
      return true;
    }
    else{
      FeatureNode* checker = head;
      FeatureNode* temp = new FeatureNode;
      temp->feature = feature;
      while(checker->next != NULL){
        if(checker->feature.compare(temp->feature)<0){
          FeatureNode* temp2 = checker;
          temp->next = temp2->next;
          temp2->next = temp;
          size++;
          break;
        }
        checker = checker->next;

      }
      size++;
      return true;
        
    }
  
  }

  else return false;

}

bool Flower::detectFuture(std::string feature){
  FeatureNode* checker = head;
  while(checker->feature != feature){
    checker = checker->next;

    if(checker->feature == feature) return true;

  }
  return false;
}

bool Flower::remove(std::string feature){

  if(detectFuture(feature)){
    FeatureNode* temp = head;
    FeatureNode* temp2 ;
    while(temp->next->feature != feature){

      temp = temp->next;

    }
    temp2 = temp->next;
    temp->next == temp->next->next;
    delete temp2;
    size--;
    return true;

  }
  else return false;
}

std::string Flower::printFlower() const {
  FeatureNode* temp = head;
  std::string print;
  std::cout<<this->flowerName<<": ";
if(temp->feature == ""){
  print = print + "No Future"+ "\n" ;

}
else {
  while(temp->next != NULL){
    print = print + temp->feature + ", " ;
    temp = temp->next;
  }
  print = print +"\n";
}
return print;
}

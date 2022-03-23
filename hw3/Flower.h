#ifndef FLOWER_H
#define FLOWER_H
#include <iostream>
#include <string>
class Flower{
public:
  Flower();
  Flower(std::string flowerName);
  Flower(const Flower& aFlower);
  ~Flower();
  bool isEmpty() const;
  int getLength() const ;
  bool add(std::string feature);
  bool remove(std::string feature);
  std::string printFlower() const;
  bool detectFuture(std::string feature);
private:
  struct FeatureNode{
    std::string feature;
    FeatureNode* next;
  };
  int size;
  std::string flowerName;
  FeatureNode *head;
}; //the features are stored in a sorted singly linear linked list
  #endif

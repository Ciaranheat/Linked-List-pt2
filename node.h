#ifndef NODE_H
#define NODE_H
#include "student.h"
#include <iostream>

using namespace std;

class Node {
 public:
  Node();
  ~Node();

  
  void setStudent(Student*);
  Student* getStudent();
  Node* getNext();
  void setNext(Node* newNext);
 private:
  Student* student;
  Node* next;
};
#endif

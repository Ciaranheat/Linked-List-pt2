#ifndef NODE_H
#define NODE_H
#include "student.h"
#include <iostream>

using namespace std;

class Node {
 public:
  Node(Student*);
  ~Node();

  Student* getStudent();
  Node* getNext();
  void setNext(Node*);
 private:
  Student* sdt;
  Node* next;
};
#endif

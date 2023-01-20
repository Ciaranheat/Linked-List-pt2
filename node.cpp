#include "Node.h"
#include <iostream>

using namespace std;

Node :: Node(Student* newsdt) {
  sdt = newsdt;
  next = NULL;
}

Node :: ~Node() {
  delete sdt;
}

void Node :: setNext(Node* newNode) {
  next = newNode;
}

Node* Node :: getNext() {
  return next;
}

Student* Node :: getStudent() {
  return sdt;
}

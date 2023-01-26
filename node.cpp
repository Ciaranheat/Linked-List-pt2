#include "Node.h"
#include <iostream>

using namespace std;

Node :: Node() {
  student = NULL;
  next = NULL;
}

Node :: ~Node() {
  delete student;
}

void Node :: setNext(Node* newNext) {
  next = newNext;
}

Node* Node :: getNext() {
  return next;
}

void Node :: setStudent(Student* newStudent) {
  student = newStudent;
}

Student* Node :: getStudent() {
  return student;
}

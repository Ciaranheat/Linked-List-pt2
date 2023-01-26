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

void Node :: setNext(Node* newNext) { //Sets next
  next = newNext;
}

Node* Node :: getNext() {//gets next
  return next;
}

void Node :: setStudent(Student* newStudent) {//Sets student
  student = newStudent;
}

Student* Node :: getStudent() {//Gets student
  return student;
}

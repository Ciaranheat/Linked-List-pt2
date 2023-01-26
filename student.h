#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student {
public: //Makes all of this public
  Student();
  ~Student();

  string getFN();
  string getLN();
  int getID();
  float getGPA();
  void makeStudent();
  void printStudent();

private:

  char firstname[100];
  char lastname[100];
  int id;
  float gpa;
 
};

#endif

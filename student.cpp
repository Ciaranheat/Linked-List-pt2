#include<iostream>
#include "Student.h"
#include <iomanip>

using namespace std;

Student :: Student() {
  firstname[0] = '\0';
  lastname[0] = '\0';
  id = 0;
  gpa = 0;
  
}

Student :: ~Student() {

}

string Student :: getFN() { //Gets first name
  return firstname;
  
}

string Student :: getLN() {//Gets last name
  return lastname;
}

int Student :: getID() {//Gets ID
  return id;
}

float Student :: getGPA() {//Gets GPa
  return gpa;
}

void Student :: makeStudent() {//Makes the student 
  cin.ignore();
  cout << "Enter first Name: " << endl;
  cin.getline(firstname, 100);

  cout << "Enter last Name: " << endl;
  cin.getline(lastname, 100);

  cout << "Enter id: " << endl;
  cin >> id;
  cin.ignore();

  cout << "Enter gpa: " << endl;
  cin >> gpa;
  cin.ignore();
}

void Student :: printStudent() {//Format to how the student is printed
  cout << firstname << " " << lastname << ", " << id << ", ";

  cout.setf(ios :: fixed);
  cout.precision(2);
  cout << gpa << endl;
}

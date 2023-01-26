#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;
//Void of all the main functions
void addStudent(Node* &head, Node* n);
void printAll(Node* head);
void printAverage(Node* n);
void deleteStudent(Node* &head, int id);

int main() {

  Node* Head = NULL;

  int running = 1;

  string in;
  int id = 0;

  while (running == 1) {//Kills the program when told too 

    cout << "enter command: [ADD,PRINT,DELETE,AVERAGE,QUIT]" << endl;
    cin >> in;
    if (in == "ADD" || in == "Add" || in == "add") { //Adds student when told too 
      Student* s = new Student;
      s -> makeStudent();
      Node* n = new Node;
      n -> setStudent(s);

      addStudent(Head,n);
    }
    if (in == "PRINT" || in == "Print" || in == "print") {//Prints out all students 
      printAll(Head);
    }
    if (in == "DELETE" || in == "Delete" || in == "delete") {//Deletes seleceted student 
      if (Head == NULL) {
	cout << "Student not in list" << endl;
      }
      else {
	cout << "Enter ID to be deleted: " << endl;
	cin >> id;
	cin.ignore();

	deleteStudent(Head,id);

      }
    }
    if (in == "AVERAGE" || in == "Average" || in == "average") {//Averages gpa
      printAverage(Head);
    }
    if ( in == "QUIT" || in == "Quit" || in == "quit") {//Quits when told
      running = 0;
    }


  }
  
}

void addStudent(Node* &head, Node* n){//Function to add student

  if(head == NULL) {
    head = n;
    return;
  }

  if (n -> getStudent() -> getID() < head -> getStudent() -> getID()) {
    n -> setNext(head);
    head = n;
  }
  else {
    Node* next = head -> getNext();
    addStudent(next, n);
    head -> setNext(next);
  }

}

void deleteStudent(Node* &head, int id) {//Function to delete student
  if(head == NULL) {
    return;
  }

  if(head -> getStudent() -> getID() == id) {
    Node *temp = head;
    head = head -> getNext();

    delete temp -> getStudent();
    cout << "Student " << id << " deleted." << endl;

    deleteStudent(head, id);

    return;
  }
  else {
    head -> getStudent() -> printStudent();
    printAll(head -> getNext());
    
  }
}


void printAll(Node* head){//Function to print all of the student
  if(head == NULL) {
    cout << endl;
    return;
  }
  else {
    head -> getStudent() -> printStudent();
    printAll(head -> getNext());
}

}

void printAverage(Node* n) {//Function to average grades
  float sum = 0;
  int count = 0;
  float avg = 0;

  Node* temp = n;

  if(temp == NULL) {
    cout << "No students" << endl;
    return;

  }

  while(temp != NULL) {
    sum = sum + temp -> getStudent() -> getGPA();
    count++;
    temp = temp -> getNext();
  }

  avg = sum/count;
  cout << "Average = ";
  cout.setf(ios :: fixed);
  cout.precision(2);
  cout << avg << endl;

  return;
  
}

#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

void addStudent(Node* &head, Node* n);
void printAll(Node* head);
void printAverage(Node* n);
void deleteStudent(Node* &head, int id);

int main() {

  Node* Head = NULL;

  int running = 1;

  string in;
  int id = 0;

  while (running == 1) {

    cout << "enter command: [ADD,PRINT,DELETE,AVERAGE,QUIT]" << endl;
    cin >> in;
    if (in == "ADD" || in == "Add" || in == "add") {
      Student* s = new Student;
      s -> makeStudent();
      Node* n = new Node;
      n -> setStudent(s);

      addStudent(Head,n);
    }
    if (in == "PRINT" || in == "Print" || in == "print") {
      printAll(Head);
    }
    if (in == "DELETE" || in == "Delete" || in == "delete") {
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
    if (in == "AVERAGE" || in == "Average" || in == "average") {
      printAverage(Head);
    }
    if ( in == "QUIT" || in == "Quit" || in == "quit") {
      running = 0;
    }


  }
  
}

void addStudent(Node* &head, Node* n){

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

void deleteStudent(Node* &head, int id) {
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


void printAll(Node* head){
  if(head == NULL) {
    cout << endl;
    return;
  }
  else {
    head -> getStudent() -> printStudent();
    printAll(head -> getNext());
}

}

void printAverage(Node* n) {
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

#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

void addStudent(Node* &head, Node* n);
void printALL(Node* head);
void printAverage(Node* n);
void deleteStudent(Node* &head, int id);

int main() {

  Node* node = NULL;

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
      printALL(Head);
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

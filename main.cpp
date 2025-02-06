#include "Student.h"
#include "Node.h"

#include <iostream>
#include <cstring>

//Main code for LinkedList2
//Created by Tai Wong, Jan 2nd.


using namespace LinkedList;
using namespace std;

//function prototypes
void addStudent(Node* &head);
void insertStudent(Node* &head, Student* student);
void printStudent(Node* head);
void deleteStudent(Node* &head, int id);
void averageGPA(Node* head, float &count, int &sCount);

//maim
int main() {
  //creates head outside of loop for continuity
  Node* head = NULL;
   
  while (true) {
    //asks for command
    cout << "What command?" << endl;
    char response[10];
    cin >> response;
    //compares response and gives the corresponding action
    if (strcmp(response, "ADD") == 0) {
      addStudent(head);
    } else if (strcmp(response, "PRINT") == 0) {
      printStudent(head);
    } else if (strcmp(response, "DELETE") == 0) {
      cout << "What is the ID of the student?" << endl;
      int deleteID;
      cin >> deleteID;
      deleteStudent(head, deleteID);
    } else if (strcmp(response, "QUIT") == 0) {
      return 0;
    } else if (strcmp(response, "AVERAGE") == 0) {
      float count = 0.0;
      int sCount = 0;
      averageGPA(head, count, sCount);
      float roundedGPA = roundf((count / 2) * 100) / 100;

      cout << "Average GPA is " << roundedGPA << endl;
      
    }
  }
}

//add student function
void addStudent(Node* &head) {
  cout << "First Name?" << endl;
  char fName[80];
  cin >> fName;

  cout << "Last Name?" << endl;
  char lName[80];
  cin >> lName;

  cout << "ID#?" << endl;
  int idNum;
  cin >> idNum;

  cout << "GPA?" << endl;
  float GPA;
  cin >> GPA;
  //inserts student into linked list recursively
  Student* newStudent = new Student(fName, lName, idNum, GPA);
  insertStudent(head, newStudent);
}

void insertStudent(Node* &head, Student* student) {
  //inserts based on ID number, least to greatest
  if (head == NULL || student->getID() < head->getStudent()->getID()) {
    Node* newNode = new Node(student);
    newNode->setNext(head);
    head = newNode;
  } else {
    Node* &nextNode = head->getNext();
    insertStudent(nextNode, student);
  }
}

//prints student recursively
void printStudent(Node* head) {
  if (head == NULL) {
    cout << "No Students Added" << endl;
  } else {
    Student* cStudent = head->getStudent();
    float roundedGPA = roundf(cStudent->getGPA() * 100) / 100;
    cout << cStudent->getFirstName() << ' ' << cStudent->getLastName() << ", " << cStudent->getID() << ", " << roundedGPA << endl;

    if (head->getNext() != NULL) {
      printStudent(head->getNext());
    }
  }
}

//deletes student recursively
void deleteStudent(Node* &head, int id) {
  if (head == NULL) {
    cout << "No Students in List" << endl;
    return;
  }

  if (head->getStudent()->getID() == id) {
    Node* temp = head;
    head = head->getNext();
    delete temp;
    return;
  }
  deleteStudent(head->getNext(), id);
}

//averages gpa of students recursively
void averageGPA(Node* head, float &count, int &sCount) {
  if (head == NULL) {
    cout << "No Students Added" << endl;
  } else {
    Student* cStudent = head->getStudent();
    float roundedGPA = roundf(cStudent->getGPA() * 100) / 100;
    count += roundedGPA;
    sCount += 1;
    if (head->getNext() != NULL) {
      averageGPA(head->getNext(), count, sCount);
    }
  }
}

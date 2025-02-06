#include <cstring>
#include <vector>
#include <math.h>
#include <iostream>

//StudentList, a simple program to store student data by Tai Wong
//10/17/24



using namespace std;

// student struct to store Student data
struct Student {
  char firstName[80];
  char lastName[80];
  int studentID;
  float gpa;
};

// function prototypes
void addStudent(vector<Student*> &studentList);
void printStudentList(const vector<Student*> &studentList);
void deleteStudent(vector<Student*> &studentList, int id);

int main() {
  bool run = true;
  vector<Student*> studentList; // vector to store pointers to students

  // loops code
  while (run) {
    cout << "Do you want to ADD, PRINT, DELETE, or QUIT?" << endl;
    char response[10];
    cin >> response;

    if (strcmp(response, "ADD") == 0) {
      addStudent(studentList);
    } else if (strcmp(response, "PRINT") == 0) {
      printStudentList(studentList);
    } else if (strcmp(response, "DELETE") == 0) {
      cout << "What is their ID number?" << std::endl;
      int id;
      cin >> id;
      deleteStudent(studentList, id);
    } else if (strcmp(response, "QUIT") == 0) {
      run = false;
    } else {
      cout << "Invalid Response" << std::endl;
    }
  }

  // free allocated memory before exiting
  for (Student* student : studentList) {
    delete student;
  }
  studentList.clear();

  return 0;
}

// function to add a new student to the list
void addStudent(vector<Student*> &studentList) {
  Student* newStudent = new Student();

  // get student information from user
  cout << "What is their first name?" << std::endl;
  cin >> newStudent->firstName;

  cout << "What is their last name?" << std::endl;
  cin >> newStudent->lastName;

  cout << "What is their student ID?" << std::endl;
  cin >> newStudent->studentID;

  cout << "What is their GPA?" << std::endl;
  cin >> newStudent->gpa;

  // add the new student to the list
  studentList.push_back(newStudent);
}

// function to print all students in the list
void printStudentList(const vector<Student*> &studentList) {
  // iterate over the student list
  for (Student* x : studentList) {
    // round GPA to two decimal places
    float roundedGPA = roundf(x->gpa * 100) / 100;
    cout << x->firstName << ' ' << x->lastName << ", " << x->studentID << ", " << roundedGPA << std::endl;
  }
}

// function to delete a student by ID
void deleteStudent(vector<Student*> &studentList, int id) {
  int index = -1;

  // loops through student list
  for (int x = 0; x < studentList.size(); x++) {
    //if it is equal to an id, sets index to it
    if (studentList[x]->studentID == id) {
      index = x;
      break;
    }
  }

  if (index != -1) {
    delete studentList[index];
    // remove the student from the vector
    studentList.erase(studentList.begin() + index);
    cout << "Student deleted." << endl;
  } else {
    cout << "Student ID not found." << endl;
  }
} 

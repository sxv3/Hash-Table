#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

//Student class declaration
//Created by Tai Wong, Jan 2nd.

class Student {
private:
  //class vriables
  char firstName[80];
  char lastName[80];
  int id;
  float gpa;
 public:
  //constructor
  Student(const char* firstName, const char* lastName, int id, float gpa);

  //getters
  const char* getFirstName();
  const char* getLastName();
  int getID();
  float getGPA();
};

#endif

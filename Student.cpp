#include "Student.h"

#include <iostream>
#include <cstring>

//Student class code
//Created by Tai Wong Jan 2nd.

//constructor code
Student::Student(const char* firstName, const char* lastName, int id, float gpa) {
  strncpy(this->firstName, firstName, sizeof(this->firstName) - 1);
  this->firstName[sizeof(this->firstName) - 1] = '\0';
  strncpy(this->lastName, lastName, sizeof(this->lastName) - 1);
  this->lastName[sizeof(this->lastName) - 1] = '\0';
  this->id = id;
  this->gpa = gpa;
}

//getter code

const char* Student::getFirstName() {
  return firstName;
}

const char* Student::getLastName() {
  return lastName;
}

int Student::getID() {
  return id;
}

float Student::getGPA() {
  return gpa;
}

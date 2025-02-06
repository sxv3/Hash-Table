#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Student.h"

//Hash table header
//created by Tai Wong, 2/6/25

//node struct for linked list
struct Node {
    Student* student;
    Node* next;
};

//hash table class
class HashTable {
private:
  //array of linked list
    Node* *table;
    int size;
  //functions
    int hashFunction(int id);
    void rehash();

public:
    HashTable();
    ~HashTable();
  //prototypes
    void addStudent(Student* student);
    void printStudents();
    void deleteStudent(int id);
};

#endif

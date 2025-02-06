#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Student.h"

struct Node {
    Student* student;
    Node* next;
};

class HashTable {
private:
    Node* *table;
    int size;
    int hashFunction(int id);
    void rehash();

public:
    HashTable();
    ~HashTable();
    
    void addStudent(Student* student);
    void printStudents();
    void deleteStudent(int id);
};

#endif

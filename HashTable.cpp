#include "HashTable.h"
#include <iostream>

using namespace std;

//functions for HashTable class.
//Created by Tai Wong, 2/6/25


//initial size of hash table
const int INITIAL_SIZE = 100;

//hash table init code, makes an array of null ptrs
HashTable::HashTable() : size(INITIAL_SIZE) {
    table = new Node*[size]();
}

//hash table destructor
HashTable::~HashTable() {
    for (int i = 0; i < size; i++) {
        Node* current = table[i];
	//deletes and frees memory
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp->student;
            delete temp;
        }
    }
    delete[] table;
}

//hash function, just the student ID * size
int HashTable::hashFunction(int id) {
    return id % size;
}

//rehash function
void HashTable::rehash() {
  //doubles size and creates  the new table
    int newSize = size * 2;
    Node** newTable = new Node*[newSize]();
    //loops through
    for (int i = 0; i < size; i++) {
        Node* current = table[i];
        while (current) {
            int newIndex = current->student->getID() % newSize;

	    Node* newNode = new Node();
	    newNode->student = current->student;
	    newNode->next = newTable[newIndex];
	    //insert into new table
            newTable[newIndex] = newNode;

            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    //gets rid of old table
    delete[] table;
    table = newTable;
    size = newSize;
}

//add student function
void HashTable::addStudent(Student* student) {
  //insert student at head
    int index = hashFunction(student->getID());
    Node* newNode = new Node();
    newNode->student = student;
    newNode->next = table[index];
    
    table[index] = newNode;
    //check if rehashing is needed
    int chainLength = 0;
    Node* current = table[index];
    while (current) {
        chainLength++;
        current = current->next;
    }

    if (chainLength > 3) {
        rehash();
    }
}
//prints all students
void HashTable::printStudents() {
    for (int i = 0; i < size; i++) {
        Node* current = table[i];
        while (current) {
            cout << "ID: " << current->student->getID() << ", " << current->student->getFirstName() << " "
		 << current->student->getLastName() << ", GPA: " << current->student->getGPA() << endl;
            current = current->next;
        }
    }
}

//delete student by id
void HashTable::deleteStudent(int id) {
    int index = hashFunction(id);
    Node* current = table[index];
    Node* prev = nullptr;
    //traverses linked list
    while (current) {
        if (current->student->getID() == id) {
            if (prev) {
                prev->next = current->next;
            } else {
                table[index] = current->next;
            }
            delete current->student;
            delete current;
            cout << "Deleted student with ID " << id << endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Student not found." << endl;
}

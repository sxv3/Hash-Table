#include "HashTable.h"
#include <iostream>

using namespace std;

const int INITIAL_SIZE = 100;

HashTable::HashTable() : size(INITIAL_SIZE) {
    table = new Node*[size]();
}

HashTable::~HashTable() {
    for (int i = 0; i < size; i++) {
        Node* current = table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp->student;
            delete temp;
        }
    }
    delete[] table;
}

int HashTable::hashFunction(int id) {
    return id % size;
}

void HashTable::rehash() {
    int newSize = size * 2;
    Node** newTable = new Node*[newSize]();

    for (int i = 0; i < size; i++) {
        Node* current = table[i];
        while (current) {
            int newIndex = current->student->getID() % newSize;

            Node* newNode = new Node{current->student, newTable[newIndex]};
            newTable[newIndex] = newNode;

            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    delete[] table;
    table = newTable;
    size = newSize;
}

void HashTable::addStudent(Student* student) {
    int index = hashFunction(student->getID());
    Node* newNode = new Node{student, table[index]};
    table[index] = newNode;

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

void HashTable::printStudents() {
    for (int i = 0; i < size; i++) {
        Node* current = table[i];
        while (current) {
            cout << "ID: " << current->student->getID() << ", " 
                 << current->student->getFirstName() << " " 
                 << current->student->getLastName() << ", GPA: " 
                 << current->student->getGPA() << endl;
            current = current->next;
        }
    }
}

void HashTable::deleteStudent(int id) {
    int index = hashFunction(id);
    Node* current = table[index];
    Node* prev = nullptr;

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

#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

//main.cpp for the Hash Table
//Created by Tai Wong, 2/6/25

//loads names from the text files
void loadNames(char firstNames[][80], int& firstCount, char lastNames[][80], int& lastCount) {
    ifstream firstFile("first_names.txt"), lastFile("last_names.txt");
    firstCount = 0;
    lastCount = 0;

    while (firstFile >> firstNames[firstCount] && firstCount < 1000) firstCount++;
    while (lastFile >> lastNames[lastCount] && lastCount < 1000) lastCount++;
}

//random student generator
Student* generateRandomStudent(char firstNames[][80], int firstCount, char lastNames[][80], int lastCount, int& nextID) {
  //self explanatory
    char firstName[80], lastName[80];
    strcpy(firstName, firstNames[rand() % firstCount]);
    strcpy(lastName, lastNames[rand() % lastCount]);

    float gpa = ((rand() % 301) / 100.0f) + 1.0f;
    return new Student(firstName, lastName, nextID++, gpa);
}

//main function
int main() {
    srand(time(0));
    HashTable students;
    char firstNames[1000][80], lastNames[1000][80];
    int firstCount = 0, lastCount = 0;
    int nextID = 1;
    //loads the text files
    loadNames(firstNames, firstCount, lastNames, lastCount);

    while (true) {
        cout << "ADD, PRINT, DELETE, GENERATE, QUIT? ";
        char command[10];
        cin >> command;
	//if ADD
        if (strcmp(command, "ADD") == 0) {
            char firstName[80], lastName[80];
            int id;
            float gpa;
            cout << "First name: ";
            cin >> firstName;
            cout << "Last name: ";
            cin >> lastName;
            cout << "ID: ";
            cin >> id;
            cout << "GPA: ";
            cin >> gpa;

            students.addStudent(new Student(firstName, lastName, id, gpa));
        }
	//if PRINT
        else if (strcmp(command, "PRINT") == 0) {
            students.printStudents();
        }
	//if DELETE
        else if (strcmp(command, "DELETE") == 0) {
            int id;
            cout << "Enter student ID: ";
            cin >> id;
            students.deleteStudent(id);
        }
	//if GENERATE
        else if (strcmp(command, "GENERATE") == 0) {
            int num;
            cout << "How many students to generate? ";
            cin >> num;

            for (int i = 0; i < num; i++) {
                students.addStudent(generateRandomStudent(firstNames, firstCount, lastNames, lastCount, nextID));
            }
            cout << num << " random students added." << endl;
        }
        else if (strcmp(command, "QUIT") == 0) {
            break;
        }
        else {
            cout << "Invalid command." << endl;
        }
    }
    return 0;
}

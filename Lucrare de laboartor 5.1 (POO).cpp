//Lucrare de laborator 5.1

#include <iostream>

// Base class 1 Student
class Student {
public:
    Student() {
        std::cout << "Constructor Student" << std::endl;
    }

    void studiaza() {
        std::cout << "Studentul: Invata..." << std::endl;
    }

    ~Student() {
        std::cout << "Destructor Student" << std::endl;
    }
};

// Base class 2 Colaborator
class Colaborator {
public:
    Colaborator() {
        std::cout << "Constructor Colaborator" << std::endl;
    }

    void initiaza() {
        std::cout << "Colaboratorul: Ajuta" << std::endl;
    }

    ~Colaborator() {
        std::cout << "Destructor Colaborator" << std::endl;
    }
};

// Derived class Practicant
class Practicant : public Student, Colaborator {
public:
    Practicant() {
        std::cout << "Constructor Practicant" << std::endl;
    }

    void studiaza() {
        std::cout << "Studentul: Studiaza ..." << std::endl;
    }

    void initiaza() {
        std::cout << "Practicantul: Initiaza practica..." << std::endl;
    }

    ~Practicant() {
        std::cout << "Destructor Practicant" << std::endl;
    }
};

int main() {
    Practicant* practic = new Practicant();
    practic->studiaza();
    practic->initiaza();
    delete practic;

    return 0;
}

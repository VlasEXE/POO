//Lucrare de laborator 5.2

#include <iostream>
#include <string>

class Om {
public:
    Om() {
        std::cout << "Constructor Om\n";
    }

    virtual ~Om() {
        std::cout << "Destructor Om\n";
    }

    void foloseste(const std::string& parametru) const {
        if (parametru == "s") {
            std::cout << "Studentul citeste.\n";
        }
        else if (parametru == "c") {
            std::cout << "Colaboratorul initiaza.\n";
        }
        else if (parametru == "p") {
            std::cout << "Practicantul initiaza.\n";
        }
        else {
            std::cout << "Error.\n";
        }
    }
};

class Student : virtual public Om {
public:
    Student() {
        std::cout << "Constructor Student\n";
    }

    virtual ~Student() {
        std::cout << "Destructor Student\n";
    }
};

class Colaborator : virtual public Om {
public:
    Colaborator() {
        std::cout << "Constructor Colaborator\n";
    }

    virtual ~Colaborator() {
        std::cout << "Destructor Colaborator\n";
    }
};

class Practicant : public Student, public Colaborator {
public:
    Practicant() {
        std::cout << "Constructor Practicant\n";
    }

    virtual ~Practicant() {
        std::cout << "Destructor Practicant\n";
    }
};

int main() {
    
    Om* colaborator = new Colaborator();
    colaborator->foloseste("c");
    delete colaborator;

    Om* student = new Student();
    student->foloseste("s");
    delete student;

    Practicant* practic = new Practicant();
    practic->foloseste("p");
    delete practic;

    return 0;
}

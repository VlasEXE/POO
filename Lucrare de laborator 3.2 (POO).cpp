//Lab 3.2

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Set {
private:
    vector<int>* elements;

public:
    Set() : elements(new vector<int>) {}

    ~Set() {
        delete elements;
    }

    // Operatori de lucru cu multimi
    friend Set operator+(const Set& set1, const Set& set2);
    friend Set operator*(const Set& set1, const Set& set2);
    friend Set operator-(const Set& set1, const Set& set2);

    // Operatori pentru manipularea elementelor
    Set& operator+=(int element);
    bool operator==(const Set& other) const;

    // Functii prietene pentru afisare si citire
    friend ostream& operator<<(ostream& os, const Set& set);
    friend istream& operator>>(istream& is, Set& set);

    // Functie pentru verificarea apartenentiei unui element la multime
    bool contains(int element) const;

    // Alte metode utile
    size_t size() const;

    // Meniu recursiv
    static void displayMenu(Set& set);
};

Set operator+(const Set& set1, const Set& set2) {
    Set result = set1;
    for (int element : *set2.elements) {
        result += element;
    }
    return result;
}

Set operator*(const Set& set1, const Set& set2) {
    Set result;
    for (int element : *set1.elements) {
        if (set2.contains(element)) {
            result += element;
        }
    }
    return result;
}

Set operator-(const Set& set1, const Set& set2) {
    Set result = set1;
    for (int element : *set2.elements) {
        result.elements->erase(remove(result.elements->begin(), result.elements->end(), element), result.elements->end());
    }
    return result;
}

Set& Set::operator+=(int element) {
    if (!contains(element)) {
        elements->push_back(element);
    }
    return *this;
}

bool Set::operator==(const Set& other) const {
    return *elements == *other.elements;
}

ostream& operator<<(ostream& os, const Set& set) {
    os << "{ ";
    for (int element : *set.elements) {
        os << element << " ";
    }
    os << "}";
    return os;
}

istream& operator>>(istream& is, Set& set) {
    int element;
    is >> element;
    set += element;
    return is;
}

bool Set::contains(int element) const {
    return find(elements->begin(), elements->end(), element) != elements->end();
}

size_t Set::size() const {
    return elements->size();
}

void Set::displayMenu(Set& set) {
    int choice;
    cout << "1. Adauga element\n"
         << "2. Afiseaza multimea\n"
         << "3. Verifica apartenenta\n"
         << "4. Uniune\n"
         << "5. Intersectie\n"
         << "6. Diferenta\n"
         << "7. Comparare multimi\n"
         << "0. Iesire\n";

    cout << "Alege o optiune: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int element;
            cout << "Introdu un element: ";
            cin >> element;
            set += element;
            break;
        }
        case 2: {
            cout << "Multimea: " << set << endl;
            break;
        }
        case 3: {
            int element;
            cout << "Introdu elementul pentru verificare: ";
            cin >> element;
            if (set.contains(element)) {
                cout << element << " apartine multimii.\n";
            } else {
                cout << element << " nu apartine multimii.\n";
            }
            break;
        }
        case 4: {
            Set set2;
            cout << "Introdu o noua multime pentru uniune:\n";
            cin >> set2;
            Set result = set + set2;
            cout << "Uniunea: " << result << endl;
            break;
        }
        case 5: {
            Set set2;
            cout << "Introdu o noua multime pentru intersectie:\n";
            cin >> set2;
            Set result = set * set2;
            cout << "Intersectia: " << result << endl;
            break;
        }
        case 6: {
            Set set2;
            cout << "Introdu o noua multime pentru diferenta:\n";
            cin >> set2;
            Set result = set - set2;
            cout << "Diferenta: " << result << endl;
            break;
        }
        case 7: {
            Set set2;
            cout << "Introdu o noua multime pentru comparare:\n";
            cin >> set2;
            if (set == set2) {
                cout << "Multimile sunt egale.\n";
            } else {
                cout << "Multimile nu sunt egale.\n";
            }
            break;
        }
        case 0: {
            cout << "La revedere!\n";
            return;
        }
        default: {
            cout << "Optiune invalida.\n";
            break;
        }
    }

    displayMenu(set);
}

int main() {
    Set mySet;
    Set::displayMenu(mySet);

    return 0;
}
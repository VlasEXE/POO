//Lab 3.1

#include <iostream>

class NumarIntreg {
private:
    int valoare;

public:
    NumarIntreg() : valoare(0) {}

    // Suprascrierea operatorului de incrementare pre-increment
    NumarIntreg& operator++() {
        ++valoare;
        return *this;
    }

    // Suprascrierea operatorului de adunare cu un alt numar intreg
    NumarIntreg operator+(const NumarIntreg& other) const {
        NumarIntreg rezultat;
        rezultat.valoare = this->valoare + other.valoare;
        return rezultat;
    }

    // Suprascrierea operatorului de adunare cu un intreg
    NumarIntreg operator+(int numar) const {
        NumarIntreg rezultat;
        rezultat.valoare = this->valoare + numar;
        return rezultat;
    }

    // Func?ia prietena pentru operatorul de decrementare pre-decrement
    friend NumarIntreg operator--(NumarIntreg& numar);

    // Func?ia prietena pentru operatorul de scadere cu un alt numar intreg
    friend NumarIntreg operator-(const NumarIntreg& left, const NumarIntreg& right);

    // Func?ie pentru citirea valorii de la tastatura
    void citesteDeLaTastatura() {
        std::cout << "Introduceti valoarea: ";
        std::cin >> valoare;
    }

    // Func?ie pentru afi?area valorii
    void afiseazaValoare() const {
        std::cout << "Valoarea: " << valoare << std::endl;
    }
};

// Definirea func?iei prietene pentru operatorul de decrementare pre-decrement
NumarIntreg operator--(NumarIntreg& numar) {
    --numar.valoare;
    return numar;
}

// Definirea func?iei prietene pentru operatorul de scadere cu un alt numar intreg
NumarIntreg operator-(const NumarIntreg& left, const NumarIntreg& right) {
    NumarIntreg rezultat;
    rezultat.valoare = left.valoare - right.valoare;
    return rezultat;
}

int main() {
    NumarIntreg a, b;

    // Citirea valorilor de la tastatura
    a.citesteDeLaTastatura();
    b.citesteDeLaTastatura();

    // Utilizarea operatorului de incrementare pre-increment
    ++a;
    std::cout << "Valoarea lui a dupa incrementare: ";
    a.afiseazaValoare();

    // Utilizarea operatorului de adunare cu alt numar intreg
    NumarIntreg suma = a + b;
    std::cout << "Suma lui a si b: ";
    suma.afiseazaValoare();

    // Utilizarea operatorului de adunare cu un intreg
    NumarIntreg rezultatAdunare = a + 5;
    std::cout << "Rezultatul adunarii lui a cu 5: ";
    rezultatAdunare.afiseazaValoare();

    // Utilizarea operatorului de decrementare pre-decrement
    --a;
    std::cout << "Valoarea lui a dupa decrementare: ";
    a.afiseazaValoare();

    // Utilizarea operatorului de scadere cu alt numar intreg
    NumarIntreg diferenta = a - b;
    std::cout << "Diferenta dintre a si b: ";
    diferenta.afiseazaValoare();

    return 0;
}

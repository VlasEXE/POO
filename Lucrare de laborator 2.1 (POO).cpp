//Lab 2.1

#include <iostream>
#include <string>

using namespace std; // Adaugam using namespace std pentru a evita prefixul "std::"

class Date {
private:
    int zi;
    int luna;
    int an;

public:
    // Constructorul clasei, ini?ializeaza data la crearea obiectului
    Date(int zi, int luna, int an) {
        seteazaData(zi, luna, an);
    }

    // Metoda pentru setarea zilei cu validare
    void seteazaZi(int zi) {
        if (zi >= 1 && zi <= 31) {
            this->zi = zi;
        } else {
            cerr << "Ziua introdusa nu este valida." << endl;
        }
    }

    // Metoda pentru setarea lunii cu validare
    void seteazaLuna(int luna) {
        if (luna >= 1 && luna <= 12) {
            this->luna = luna;
        } else {
            cerr << "Luna introdusa nu este valida." << endl;
        }
    }

    // Metoda pentru setarea anului
    void seteazaAn(int an) {
        this->an = an;
    }

    // Metoda pentru ob?inerea zilei
    int obtineZi() const {
        return zi;
    }

    // Metoda pentru ob?inerea lunii
    int obtineLuna() const {
        return luna;
    }

    // Metoda pentru ob?inerea anului
    int obtineAn() const {
        return an;
    }

    // Afi?eaza data in formatul "zi luna an"
    void afisareFormat1() const {
        string luni[] = {"ianuarie", "februarie", "martie", "aprilie", "mai", "iunie", "iulie", "august", "septembrie", "octombrie", "noiembrie", "decembrie"};
        cout << zi << " " << luni[luna - 1] << " " << an << endl;
    }

    // Afi?eaza data in formatul "ZZ.LL.AAAA"
    void afisareFormat2() const {
        printf("%02d.%02d.%04d\n", zi, luna, an);
    }

    // Seteaza toate componentele datei
    void seteazaData(int zi, int luna, int an) {
        seteazaZi(zi);
        seteazaLuna(luna);
        seteazaAn(an);
    }
};

int main() {
    // Crearea unui obiect Date cu data ini?iala 6 iunie 2004
    Date data(6, 6, 2004);
    
    // Afi?eaza data in cele doua formate
    data.afisareFormat1();
    data.afisareFormat2();
    cout << ("\n") << endl; // Linie goala pentru claritate
    
    // Modificarea datei
    data.seteazaZi(15);
    data.seteazaLuna(9);
    data.seteazaAn(2023);

    // Afi?eaza data modificata in cele doua formate
    data.afisareFormat1();
    data.afisareFormat2();

    return 0;
}
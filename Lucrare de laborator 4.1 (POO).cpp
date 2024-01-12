//Lucrare de laborator 4.1

#include <iostream>
#include <string>

class Cladire {
protected:
    std::string adresa;
    int nrEtaje;
    int nrLocatari;

public:
    Cladire() : nrEtaje(0), nrLocatari(0) {}

    Cladire(const Cladire &c) : adresa(c.adresa), nrEtaje(c.nrEtaje), nrLocatari(c.nrLocatari) {}

    ~Cladire() {}

    friend std::istream &operator>>(std::istream &in, Cladire &c) {
        std::cout << "Introduceti adresa >> ";
        std::getline(in, c.adresa);
        std::cout << "Introduceti numarul de etaje >> ";
        in >> c.nrEtaje;
        std::cout << "Introduceti numarul de locatari >> ";
        in >> c.nrLocatari;
        in.ignore(); // Ignoram newline-ul ramas in buffer
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const Cladire &c) {
        return out << "Adresa: " << c.adresa << "\nNumar etaje: " << c.nrEtaje << "\nNumar locatari: " << c.nrLocatari << "\n";
    }
};

class CladireAdministrativa : public Cladire {
private:
    std::string administrator;
    int nrOficii;

public:
    CladireAdministrativa() : nrOficii(0) {}

    CladireAdministrativa(const CladireAdministrativa &c) : Cladire(c), administrator(c.administrator), nrOficii(c.nrOficii) {}

    friend std::istream &operator>>(std::istream &in, CladireAdministrativa &c) {
        Cladire &cladireBaza = c; // Accesam clasa de baza prin referin?a
        in >> cladireBaza;
        std::cout << "Introduceti numele administratorului >> ";
        std::getline(in, c.administrator);
        std::cout << "Introduceti numarul oficiului >> ";
        in >> c.nrOficii;
        in.ignore(); // Ignoram newline-ul ramas in buffer
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const CladireAdministrativa &c) {
        const Cladire &cladireBaza = c; // Accesam clasa de baza prin referin?a constanta
        out << cladireBaza;
        return out << "Administrator: " << c.administrator << "\nNumar oficii: " << c.nrOficii << "\n";
    }
};

class CladireLocuit : public Cladire {
private:
    std::string numeLocatar;
    int nrCamere;

public:
    CladireLocuit() : nrCamere(0) {}

    CladireLocuit(const CladireLocuit &c) : Cladire(c), numeLocatar(c.numeLocatar), nrCamere(c.nrCamere) {}

    friend std::istream &operator>>(std::istream &in, CladireLocuit &c) {
        Cladire &cladireBaza = c; // Accesam clasa de baza prin referin?a
        in >> cladireBaza;
        std::cout << "Introduceti numele locatarului >> ";
        std::getline(in, c.numeLocatar);
        std::cout << "Introduceti numarul camerei >> ";
        in >> c.nrCamere;
        in.ignore(); // Ignoram newline-ul ramas in buffer
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const CladireLocuit &c) {
        const Cladire &cladireBaza = c; // Accesam clasa de baza prin referin?a constanta
        out << cladireBaza;
        return out << "Nume locatar: " << c.numeLocatar << "\nNumar camere: " << c.nrCamere << "\n";
    }
};

int main() {
    CladireAdministrativa c1;
    CladireLocuit c2;

    std::cin >> c1;
    std::cin >> c2;

    std::cout << "Detalii Cladire Administrativa:\n" << c1;
    std::cout << "Detalii Cladire Locuit:\n" << c2;

    return 0;}
//Lucrade de laborator 4.2

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
public:
    string nume;
    string specialitate;
    int an_studiu;
    float medie;

    Student() {}

    Student(const string &nume, const string &specialitate, int an_studiu, float medie)
        : nume(nume), specialitate(specialitate), an_studiu(an_studiu), medie(medie) {}

    void definire() {
        cout << "Introduceti datele studentului:" << endl;
        cout << "Nume: ";
        cin >> nume;
        cout << "Specialitate: ";
        cin >> specialitate;
        cout << "An de studiu: ";
        cin >> an_studiu;
        cout << "Medie: ";
        cin >> medie;
    }

    void afisare() const {
        cout << "Nume: " << nume << endl;
        cout << "Specialitate: " << specialitate << endl;
        cout << "An de studiu: " << an_studiu << endl;
        cout << "Medie: " << medie << endl;
    }
};

class Grupa : public Student {
public:
    Student *studenti; // Vectorul de studen?i
    int numarStudenti; // Numarul actual de studen?i in grupa
    int dimensiuneMaxima; // Dimensiunea maxima a grupului

    Grupa(int dimensiuneMaxima) : numarStudenti(0), dimensiuneMaxima(dimensiuneMaxima) {
        studenti = new Student[dimensiuneMaxima];
    }

    ~Grupa() {
        delete[] studenti;
    }

    void adaugaStudent() {
        if (numarStudenti < dimensiuneMaxima) {
            studenti[numarStudenti].definire();
            numarStudenti++;
        } else {
            cout << "Grupa este plina! Nu se mai pot adauga studenti." << endl;
        }
    }

    void eliminaStudent(int indexStudent) {
        if (indexStudent >= 0 && indexStudent < numarStudenti) {
            // Mutam ultimul student in locul studentului de eliminat
            studenti[indexStudent] = studenti[numarStudenti - 1];
            numarStudenti--;
            cout << "Student eliminat cu succes." << endl;
        } else {
            cout << "Index invalid pentru eliminare." << endl;
        }
    }

    void afiseazaStudenti() const {
        cout << "Lista de studenti din grupa:" << endl;
        for (int i = 0; i < numarStudenti; i++) {
            cout << "Studentul " << i + 1 << ":" << endl;
            studenti[i].afisare();
            cout << "--------------------------" << endl;
        }
    }

    void afiseazaMediaGrupei() const {
        if (numarStudenti == 0) {
            cout << "Nu exista studenti in grupa pentru calculul mediei." << endl;
            return;
        }

        float sumaMedii = 0;
        for (int i = 0; i < numarStudenti; i++) {
            sumaMedii += studenti[i].medie;
        }

        float mediaGrupei = sumaMedii / numarStudenti;
        cout << "Media grupei este: " << mediaGrupei << endl;
    }
};

int main() {
    int dimensiuneMaximaGrupe;
    cout << "Introduceti dimensiunea maxima a grupei: ";
    cin >> dimensiuneMaximaGrupe;

    Grupa grupa(dimensiuneMaximaGrupe);

    while (true) {
        cout << "\nMeniu:" << endl;
        cout << "1. Adaugare student" << endl;
        cout << "2. Eliminare student" << endl;
        cout << "3. Afisare studenti" << endl;
        cout << "4. Afisare media grupei" << endl;
        cout << "0. Iesire" << endl;

        int optiune;
        cout << "Alegeti o optiune: ";
        cin >> optiune;

        switch (optiune) {
            case 1:
                grupa.adaugaStudent();
                break;
            case 2: {
                int indexStudent;
                cout << "Introduceti indexul studentului de eliminat: ";
                cin >> indexStudent;
                grupa.eliminaStudent(indexStudent - 1);
                break;
            }
            case 3:
                grupa.afiseazaStudenti();
                break;
            case 4:
                grupa.afiseazaMediaGrupei();
                break;
            case 0:
                cout << "Programul se inchide. La revedere!" << endl;
                return 0;
            default:
                cout << "Optiune invalida. Va rugam alegeti din nou." << endl;
        }
    }

    return 0;
}
//Variante 6 (a)

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

class Casa {
private:
    std::string firmaConstructie;
    std::string adresa;
    int numarEtaje;
    int numarApartamente;

public:
    Casa(const std::string& firma, const std::string& adr, int etaje, int apartamente)
        : firmaConstructie(firma), adresa(adr), numarEtaje(etaje), numarApartamente(apartamente) {}

    // Funcție de comparare a caselor
    bool operator<(const Casa& other) const {
        int thisValue = numarEtaje;
        int otherValue = other.numarEtaje;
        if (thisValue == otherValue) {
            int cmp = adresa.compare(other.adresa);
            if (cmp == 0) {
                return firmaConstructie < other.firmaConstructie;
            }
            return cmp < 0;
        }
        return thisValue < otherValue;
    }

    // Funcție de afișare a datelor casei
    void AfisareCasa() const {
        std::cout << "Firma de constructie: " << firmaConstructie << std::endl;
        std::cout << "Adresa: " << adresa << std::endl;
        std::cout << "Numar etaje: " << numarEtaje << std::endl;
        std::cout << "Numar apartamente: " << numarApartamente << std::endl;
    }

    // Funcții pentru setarea datelor
    void SetFirmaConstructie(const std::string& firma) {
        firmaConstructie = firma;
    }

    void SetAdresa(const std::string& adr) {
        adresa = adr;
    }

    void SetNumarEtaje(int etaje) {
        numarEtaje = etaje;
    }

    void SetNumarApartamente(int apartamente) {
        numarApartamente = apartamente;
    }

    const std::string& GetFirmaConstructie() const {
        return firmaConstructie;
    }

    const std::string& GetAdresa() const {
        return adresa;
    }

    int GetNumarEtaje() const {
        return numarEtaje;
    }

    int GetNumarApartamente() const {
        return numarApartamente;
    }
};

// Funcție pentru eliberarea memoriei alocate dinamic pentru obiectele Casa
void ElibereazaMemorie(std::vector<Casa*>& caseVector) {
    for (Casa* casa : caseVector) {
        delete casa;
    }
}

// Funcție pentru sortarea crescătoare a numărului de etaje
void SortareDupaEtajeCrescator(std::vector<Casa*>& caseVector) {
    std::sort(caseVector.begin(), caseVector.end(), [](Casa* a, Casa* b) {
        return a->GetNumarEtaje() < b->GetNumarEtaje();
    });
}

// Funcție pentru sortarea descrescătoare a numărului de etaje
void SortareDupaEtajeDescrescator(std::vector<Casa*>& caseVector) {
    std::sort(caseVector.begin(), caseVector.end(), [](Casa* a, Casa* b) {
        return a->GetNumarEtaje() > b->GetNumarEtaje();
    });
}

// Funcție pentru sortarea adresei de la A la Z
void SortareDupaAdresaAZ(std::vector<Casa*>& caseVector) {
    std::sort(caseVector.begin(), caseVector.end(), [](Casa* a, Casa* b) {
        return a->GetAdresa() < b->GetAdresa();
    });
}

// Funcție pentru sortarea adresei de la Z la A
void SortareDupaAdresaZA(std::vector<Casa*>& caseVector) {
    std::sort(caseVector.begin(), caseVector.end(), [](Casa* a, Casa* b) {
        return a->GetAdresa() > b->GetAdresa();
    });
}

void AfisareMeniu() {
    std::cout << "Meniu:" << std::endl;
    std::cout << "1. Adauga casa noua" << std::endl;
    std::cout << "2. Modifica date pentru o casa existenta" << std::endl;
    std::cout << "3. Afiseaza casele existente" << std::endl;
    std::cout << "4. Sortare" << std::endl;
    std::cout << "5. Salveaza si Iesire" << std::endl;
    std::cout << "Alege o optiune: ";
}

void AfisareMeniuModificare() {
    std::cout << "Meniu de modificare:" << std::endl;
    std::cout << "1. Modifica firma de constructie" << std::endl;
    std::cout << "2. Modifica adresa" << std::endl;
    std::cout << "3. Modifica numarul de etaje" << std::endl;
    std::cout << "4. Modifica numarul de apartamente" << std::endl;
    std::cout << "5. Iesire" << std::endl;
    std::cout << "Alege ce doresti sa modifici: ";
}

void AfisareSubmeniuSortare() {
    std::cout << "Optiuni de sortare:" << std::endl;
    std::cout << "1. Sortare dupa numar de etaje (crescator)" << std::endl;
    std::cout << "2. Sortare dupa numar de etaje (descrescator)" << std::endl;
    std::cout << "3. Sortare dupa adresa (de la A la Z)" << std::endl;
    std::cout << "4. Sortare dupa adresa (de la Z la A)" << std::endl;
    std::cout << "5. Iesire din meniul de sortare" << std::endl;
    std::cout << "Alege o optiune de sortare: ";
}

// Funcție pentru a salva casele într-un fișier text
void SalveazaInFisier(const std::vector<Casa*>& caseVector, const std::string& numeFisier) {
    std::ofstream fisier(numeFisier);
    if (fisier.is_open()) {
        for (const Casa* casa : caseVector) {
            fisier << casa->GetFirmaConstructie() << " ";
            fisier << casa->GetAdresa() << " ";
            fisier << casa->GetNumarEtaje() << " ";
            fisier << casa->GetNumarApartamente() << std::endl;
        }
        fisier.close();
    } else {
        std::cerr << "Eroare la deschiderea fisierului pentru scriere." << std::endl;
    }
}

// Funcție pentru a încărca casele dintr-un fișier text
void IncarcaDinFisier(std::vector<Casa*>& caseVector, const std::string& numeFisier) {
    std::ifstream fisier(numeFisier);
    if (fisier.is_open()) {
        std::string firma, adresa;
        int etaje, apartamente;

        while (fisier >> firma >> adresa >> etaje >> apartamente) {
            Casa* casa = new Casa(firma, adresa, etaje, apartamente);
            caseVector.push_back(casa);
        }

        fisier.close();
    } else {
        std::cerr << "Eroare la deschiderea fisierului pentru citire." << std::endl;
    }
}

// Funcție pentru a crea fișierul dacă nu există
void CreazaFisierDacaNuExista(const std::string& numeFisier) {
    std::ofstream fisier(numeFisier, std::ios::app); // Deschide fișierul în modul adăugare pentru a crea dacă nu există
    if (fisier.is_open()) {
        fisier.close();
    } else {
        std::cerr << "Eroare la crearea fisierului." << std::endl;
    }
}

int main() {
    CreazaFisierDacaNuExista("baza_date.txt"); // Verifică și creează fișierul la început

    std::vector<Casa*> caseVector;
    IncarcaDinFisier(caseVector, "baza_date.txt"); // Încarcă datele din fișier (dacă există)

    while (true) {
        system("cls"); // Curata consola

        AfisareMeniu();

        int optiune;
        std::cin >> optiune;

        if (optiune == 1) {
            // Adaugare casa noua
            std::string firma, adresa;
            int etaje, apartamente;

            std::cout << "Introduceti firma de constructie: ";
            std::cin >> firma;
            std::cout << "Introduceti adresa: ";
            std::cin >> adresa;
            std::cout << "Introduceti numarul de etaje: ";
            std::cin >> etaje;
            std::cout << "Introduceti numarul de apartamente: ";
            std::cin >> apartamente;

            Casa* nouaCasa = new Casa(firma, adresa, etaje, apartamente);
            caseVector.push_back(nouaCasa);
        } else if (optiune == 2) {
            // Modificare date pentru o casa existenta
            if (caseVector.empty()) {
                std::cout << "Nu exista nicio casa pentru a modifica datele." << std::endl;
            } else {
                int index;
                std::cout << "Introduceti indicele casei pe care doriti sa o modificati: ";
                std::cin >> index;

                if (index >= 0 && index < caseVector.size()) {
                    while (true) {
                        AfisareMeniuModificare();
                        int optiuneModificare;
                        std::cin >> optiuneModificare;

                        if (optiuneModificare == 1) {
                            std::string firma;
                            std::cout << "Introduceti noua firma de constructie: ";
                            std::cin >> firma;
                            caseVector[index]->SetFirmaConstructie(firma);
                        } else if (optiuneModificare == 2) {
                            std::string adresa;
                            std::cout << "Introduceti noua adresa: ";
                            std::cin >> adresa;
                            caseVector[index]->SetAdresa(adresa);
                        } else if (optiuneModificare == 3) {
                            int etaje;
                            std::cout << "Introduceti noul numar de etaje: ";
                            std::cin >> etaje;
                            caseVector[index]->SetNumarEtaje(etaje);
                        } else if (optiuneModificare == 4) {
                            int apartamente;
                            std::cout << "Introduceti noul numar de apartamente: ";
                            std::cin >> apartamente;
                            caseVector[index]->SetNumarApartamente(apartamente);
                        } else if (optiuneModificare == 5) {
                            break;
                        } else {
                            std::cout << "Optiune invalida. Va rugam sa alegeti o optiune valida." << std::endl;
                        }
                    }
                } else {
                    std::cout << "Indice invalid. Va rugam sa introduceti un indice valid." << std::endl;
                }
            }
        } else if (optiune == 3) {
            // Afiseaza casele existente
            if (caseVector.empty()) {
                std::cout << "Nu exista nicio casa inregistrata." << std::endl;
            } else {
                for (size_t i = 0; i < caseVector.size(); ++i) {
                    std::cout << "Casa cu indicele " << i << ":" << std::endl;
                    caseVector[i]->AfisareCasa();
                    std::cout << std::endl;
                }
            }
        } else if (optiune == 4) {
            // Meniu de sortare
            while (true) {
                AfisareSubmeniuSortare();
                int optiuneSortare;
                std::cin >> optiuneSortare;

                switch (optiuneSortare) {
                case 1:
                    SortareDupaEtajeCrescator(caseVector);
                    break;
                case 2:
                    SortareDupaEtajeDescrescator(caseVector);
                    break;
                case 3:
                    SortareDupaAdresaAZ(caseVector);
                    break;
                case 4:
                    SortareDupaAdresaZA(caseVector);
                    break;
                case 5:
                    // Iesire din meniul de sortare
                    break;
                default:
                    std::cout << "Optiune invalida. Va rugam sa alegeti o optiune valida." << std::endl;
                }

                if (optiuneSortare == 5) {
                    break;
                }
            }
        } else if (optiune == 5) {
            // Iesire din program
            SalveazaInFisier(caseVector, "baza_date.txt"); // Salvează datele înainte de ieșire
            std::cout << "Programul s-a incheiat." << std::endl;
            break;
        } else {
            std::cout << "Optiune invalida. Va rugam sa alegeti o optiune valida." << std::endl;
        }

        // Asteapta ca utilizatorul sa apese Enter inainte de a afisa din nou meniul
        std::cout << "Apasa Enter pentru a continua...";
        std::cin.ignore(); // Ignora orice caracter ramas in bufferul de intrare
        std::cin.get(); // Asteapta pana cand utilizatorul apasa Enter
    }

    // Eliberarea memoriei inainte de iesire
    ElibereazaMemorie(caseVector);

    return 0;
}











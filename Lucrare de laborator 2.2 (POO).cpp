//Lab 2.2

#include <iostream>
#include <stdexcept>
#include <cstdlib> 
#include <limits>  // pentru std::numeric_limits

using namespace std;

class Matrix {
private:
    int** data;
    int numRows;
    int numColumns;

public:
    Matrix() : data(nullptr), numRows(0), numColumns(0) {}

    Matrix(int size) : numRows(size), numColumns(size) {
        if (size <= 0) {
            throw invalid_argument("Dimensiunea matricei trebuie sa fie mai mare decat zero.");
        }
        data = new int*[numRows];
        for (int i = 0; i < numRows; ++i) {
            data[i] = new int[numColumns];
        }
    }

    Matrix(int rows, int columns) : numRows(rows), numColumns(columns) {
        if (rows <= 0 || columns <= 0) {
            throw invalid_argument("Dimensiunile matricei trebuie sa fie mai mari decat zero.");
        }
        data = new int*[numRows];
        for (int i = 0; i < numRows; ++i) {
            data[i] = new int[numColumns];
        }
    }

    void setValue(int i, int j, int value) {
        if (i < 0 || i >= numRows || j < 0 || j >= numColumns) {
            throw out_of_range("Indexul este in afara limitei matricei.");
        }
        data[i][j] = value;
    }

    int getValue(int i, int j) const {
        if (i < 0 || i >= numRows || j < 0 || j >= numColumns) {
            throw out_of_range("Indexul este in afara limitei matricei.");
        }
        return data[i][j];
    }

    int getNumRows() const {
        return numRows;
    }

    int getNumColumns() const {
        return numColumns;
    }

    Matrix operator+(const Matrix& other) const {
        if (numRows != other.numRows || numColumns != other.numColumns) {
            throw invalid_argument("Dimensiunile matricelor nu corespund.");
        }

        Matrix result(numRows, numColumns);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numColumns; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        if (numRows != other.numRows || numColumns != other.numColumns) {
            throw invalid_argument("Dimensiunile matricelor nu corespund.");
        }

        Matrix result(numRows, numColumns);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numColumns; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (numColumns != other.numRows) {
            throw invalid_argument("Numarul de coloane al primei matrice nu corespunde cu numarul de randuri al celei de-a doua matrice.");
        }

        Matrix result(numRows, other.numColumns);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < other.numColumns; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < numColumns; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix operator*(int scalar) const {
        Matrix result(numRows, numColumns);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numColumns; ++j) {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    void print() const {
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numColumns; ++j) {
                cout << data[i][j] << " ";
            }
            cout << "\n";
        }
    }

    ~Matrix() {
        if (data != nullptr) {
            for (int i = 0; i < numRows; ++i) {
                delete[] data[i];
            }
            delete[] data;
        }
    }
};

void showMenu(Matrix& matrix1, Matrix& matrix2) {
    while (true) {
        // Se șterge ecranul consolei
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        cout << "Meniu:\n";
        cout << "1. Adunare matrici\n";
        cout << "2. Scadere matrici\n";
        cout << "3. Inmultire matrici\n";
        cout << "4. Inmultire matrice cu scalar\n";
        cout << "5. Afisare matrice 1\n";
        cout << "6. Afisare matrice 2\n";
        cout << "7. Iesire\n";

        int choice;
        cout << "Introduceti optiunea : ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Matrix sumMatrix = matrix1 + matrix2;
                cout << "Rezultatul adunarii matricilor:\n";
                sumMatrix.print();
                break;
            }
            case 2: {
                Matrix diffMatrix = matrix1 - matrix2;
                cout << "Rezultatul scaderii matricilor:\n";
                diffMatrix.print();
                break;
            }
            case 3: {
                Matrix productMatrix = matrix1 * matrix2;
                cout << "Rezultatul inmultirii matricilor:\n";
                productMatrix.print();
                break;
            }
            case 4: {
                int scalar;
                cout << "Introduceti scalarul: ";
                cin >> scalar;
                Matrix scalarProduct = matrix1 * scalar;
                cout << "Rezultatul inmultirii primei matrice cu un numar scalar:\n";
                scalarProduct.print();
                break;
            }
            case 5:
                cout << "Matricea 1:\n";
                matrix1.print();
                break;
            case 6:
                cout << "Matricea 2:\n";
                matrix2.print();
                break;
            case 7:
                cout << "Iesire din program.\n";
                return;
            default:
                cout << "Optiune invalida. Va rugam sa alegeti din nou.\n";
        }

        // Așteaptă apăsarea tastei Enter
        cout << "Apasa Enter pentru a continua...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoră caracterele rămase în buffer
        cin.get();  // Așteaptă apăsarea Enter
    }
}


int main() {
    int rows, columns;
    cout << "Introduceti numarul de randuri si coloane ale primei matrice: ";
    cin >> rows >> columns;

    Matrix matrix1(rows, columns);

    cout << "Introduceti elementele primei matrice:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            int value;
            cin >> value;
            matrix1.setValue(i, j, value);
        }
    }

    cout << "Introduceti numarul de randuri si coloane ale celei de-a doua matrice: ";
    cin >> rows >> columns;

    Matrix matrix2(rows, columns);

    cout << "Introduceti elementele celei de-a doua matrice:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            int value;
            cin >> value;
            matrix2.setValue(i, j, value);
        }
    }

    showMenu(matrix1, matrix2);

    return 0;
}
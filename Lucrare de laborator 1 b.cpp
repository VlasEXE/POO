// Varianta 6 (b)

#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

class Vector {
private:
    std::vector<float> data;

public:
    Vector(int size) : data(size) {
        srand(static_cast<unsigned int>(time(0)));
    }

    float& operator[](int index) {
        return data.at(index);
    }

    int getSize() const {
        return data.size();
    }

    void resize(int newSize, bool randomValues = false) {
        if (newSize < getSize()) {
            data.resize(newSize);
        } else if (newSize > getSize()) {
            int sizeDifference = newSize - getSize();
            for (int i = 0; i < sizeDifference; i++) {
                float newValue;
                if (randomValues) {
                    newValue = static_cast<float>(rand()) / RAND_MAX;
                } else {
                    std::cout << "Enter value for element " << i + getSize() << ": ";
                    std::cin >> newValue;
                }
                data.push_back(newValue);
            }
        }
    }

    float norm() {
        float result = 0.0;
        for (float value : data) {
            result += value * value;
        }
        return std::sqrt(result);
    }

    void addScalar(float scalar) {
        for (float& value : data) {
            value += scalar;
        }
    }
};

void clearScreen() {
    system(CLEAR_SCREEN);
}

int main() {
    Vector vec(0);

    int choice;
    while (true) {
        clearScreen();
        std::cout << "Menu:\n";
        std::cout << "1. Initialize vector with random values\n";
        std::cout << "2. Initialize vector manually\n";
        std::cout << "3. Resize vector\n";
        if (vec.getSize() > 0) {
            std::cout << "4. Access/Modify vector values\n";
            std::cout << "5. Delete vector\n";
            std::cout << "6. Add scalar\n";
            std::cout << "7. Display vector\n";
            std::cout << "8. Calculate norm\n";
        }
        std::cout << "9. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int size;
                std::cout << "Enter the size of the vector: ";
                std::cin >> size;
                vec = Vector(size);
                for (int i = 0; i < size; i++) {
                    vec[i] = static_cast<float>(rand()) / RAND_MAX;
                }
                std::cout << "The vector has been initialized with random values." << std::endl;
                break;
            }
            case 2: {
                int size;
                std::cout << "Enter the size of the vector: ";
                std::cin >> size;
                vec = Vector(size);
                std::cout << "Enter values for the vector manually:\n";
                for (int i = 0; i < size; i++) {
                    std::cout << "Element " << i << ": ";
                    std::cin >> vec[i];
                }
                std::cout << "The vector has been initialized manually." << std::endl;
                break;
            }
            case 3: {
                int newSize;
                std::cout << "Enter the new size of the vector: ";
                std::cin >> newSize;
                if (newSize < vec.getSize()) {
                    vec.resize(newSize, false);
                    std::cout << "The vector size has been reduced." << std::endl;
                } else if (newSize > vec.getSize()) {
                    int mode;
                    clearScreen();
                    std::cout << "Choose the mode for entering new values:\n";
                    std::cout << "1. Manual\n";
                    std::cout << "2. Random\n";
                    std::cout << "Choose an option: ";
                    std::cin >> mode;

                    vec.resize(newSize, mode == 2);
                    std::cout << "The vector size has been increased." << std::endl;
                    if (mode == 1) {
                        std::cout << "Enter values for the new elements:\n";
                        for (int i = vec.getSize() - (newSize - newSize); i < vec.getSize(); i++) {
                            std::cout << "Element " << i << ": ";
                            std::cin >> vec[i];
                        }
                    }
                } else {
                    std::cout << "The vector size remains unchanged." << std::endl;
                }
                break;
            }
            case 4: {
                int index;
                std::cout << "Enter the index of the element you want to access/modify: ";
                std::cin >> index;
                if (index >= 0 && index < vec.getSize()) {
                    float value = vec[index];
                    std::cout << "The current value for element " << index << " is " << value << std::endl;
                    std::cout << "Enter the new value for this element: ";
                    std::cin >> value;
                    vec[index] = value;
                    std::cout << "The value of the element has been modified." << std::endl;
                } else {
                    std::cout << "The entered index is invalid." << std::endl;
                }
                break;
            }
            case 5:
                vec = Vector(0);
                std::cout << "The vector has been deleted." << std::endl;
                break;
            case 6: {
                float scalar;
                std::cout << "Enter the scalar for addition: ";
                std::cin >> scalar;
                vec.addScalar(scalar);
                std::cout << "Scalar added to the vector. Press Enter to continue..." << std::endl;
                std::cin.ignore();
                std::cin.get();
                break;
            }
            case 7:
                clearScreen();
                std::cout << "Current vector:\n";
                for (int i = 0; i < vec.getSize(); i++) {
                    std::cout << vec[i] << " ";
                }
                std::cout << std::endl;
                std::cout << "Press Enter to continue..." << std::endl;
                std::cin.ignore();
                std::cin.get();
                break;
            case 8:
                clearScreen();
                std::cout << "Vector norm: " << vec.norm() << std::endl;
                std::cout << "Press Enter to continue..." << std::endl;
                std::cin.ignore();
                std::cin.get();
                break;
            case 9:
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid option. Please choose again." << std::endl;
        }
    }

    return 0;
}





















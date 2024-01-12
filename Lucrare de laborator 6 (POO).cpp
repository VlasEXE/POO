//Lucrare de laborator 6

#include <iostream>
#include <vector>

// Clasa abstractă de bază Figure
class Figure {
public:
    virtual double perimeter() const = 0; // Funcție virtuală pură
    virtual ~Figure() {} // Destructor virtual pentru clasa abstractă
};

// Clasa derivată Rectangle
class Rectangle : public Figure {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double perimeter() const override {
        return 2 * (length + width);
    }
};

// Clasa derivată Circle
class Circle : public Figure {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double perimeter() const override {
        return 2 * 3.14159 * radius;
    }
};

// Clasa derivată Triangle
class Triangle : public Figure {
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    double perimeter() const override {
        return side1 + side2 + side3;
    }
};

// Clasa derivată Rhomb
class Rhomb : public Figure {
private:
    double side;

public:
    Rhomb(double s) : side(s) {}

    double perimeter() const override {
        return 4 * side;
    }
};

int main() {
    const int size = 4;
    std::vector<Figure*> figuresArray; // Masiv de pointeri la clasa abstractă Figure

    // Atribuirea adreselor obiectelor claselor derivate
    figuresArray.push_back(new Rectangle(4, 6));
    figuresArray.push_back(new Circle(5));
    figuresArray.push_back(new Triangle(3, 4, 5));
    figuresArray.push_back(new Rhomb(8));

    // Utilizarea masivului de pointeri pentru a apela funcția virtuală
    for (const auto& figure : figuresArray) {
        std::cout << "Perimeter: " << figure->perimeter() << std::endl;
    }

    // Eliberarea memoriei alocate pentru obiecte
    for (auto& figure : figuresArray) {
        delete figure;
    }

    return 0;
}

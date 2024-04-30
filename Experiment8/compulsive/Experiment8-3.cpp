#include <iostream>
#include <cmath>
using namespace std;

class Shape {
    public:
        Shape() {}
        virtual ~Shape() {}
        virtual double GetArea() = 0;
        virtual double GetPerim() = 0;
};

class Circle : public Shape {
    public:
        static constexpr double PI = 3.1415926535897932384626;
        double radius;
        Circle(double r) : radius(r) {}
        virtual ~Circle() {}
        virtual double GetArea() {
            return PI * radius * radius;
        }
        virtual double GetPerim() {
            return 2 * PI * radius;
        }
};

class Rectangle : public Shape {
    public:
        double width, height;
        Rectangle(double w, double h) : width(w), height(h) {}
        virtual ~Rectangle() {}
        virtual double GetArea() {
            return width * height;
        }
        virtual double GetPerim() {
            return 2 * (width + height);
        }
};

int main() {
    Circle c(5);
    Rectangle r(4, 6);
    cout << "Circle radius: " << c.radius << endl;
    cout << "Circle area: " << c.GetArea() << endl;
    cout << "Circle perimeter: " << c.GetPerim() << endl;
    cout << "====================" << endl; // "====================
    cout << "Rectangle width: " << r.width << ", height: " << r.height << endl;
    cout << "Rectangle area: " << r.GetArea() << endl;
    cout << "Rectangle perimeter: " << r.GetPerim() << endl;
    return 0;
}
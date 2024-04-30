#include <iostream>
#include <cmath>
using namespace std;

class Shape {
    public:
        Shape() {}
        virtual ~Shape() {}
        virtual double getArea() = 0;
        virtual double getPerim() = 0;
        virtual void print() = 0;
};

class Point : public Shape {
    public:
        double x, y;
        Point(double x, double y) : x(x), y(y) {}
        virtual ~Point() {}
        virtual double getArea() {
            return 0;
        }
        virtual double getPerim() {
            return 0;
        }
        virtual void print() {
            cout << (*this) << endl;
        }
    
    friend ostream& operator << (ostream &os, const Point &p) {
        os << "Point: (" << p.x << ", " << p.y << ")";
        return os;
    }
    friend istream& operator >> (istream &is, Point &p) {
        is >> p.x >> p.y;
        return is;
    }
};

class Line : public Shape {
    public:
        Point p1, p2;
        double length;
        Line(Point p1, Point p2) : p1(p1), p2(p2) {
            length = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
        }
        virtual ~Line() {}
        virtual double getArea() {
            return 0;
        }
        virtual double getPerim() {
            return length;
        }
        virtual void print() {
            cout << (*this) << endl;
        }
        friend ostream& operator << (ostream &os, const Line &l) {
            os << "Line: " << "(" << l.p1.x << ", " << l.p1.y << ")" << " -- " << "(" << l.p2.x << ", " << l.p2.y << ")";
            return os;
        }
        friend istream& operator >> (istream &is, Line &l) {
            is >> l.p1 >> l.p2;
            return is;
        }
};

class Rectangle : public Shape {
    public:
        Point p1, p2;
        double width, height;
        Rectangle(Point p1, Point p2) : p1(p1), p2(p2) {
            width = abs(p2.x - p1.x);
            height = abs(p2.y - p1.y);
        }
        virtual ~Rectangle() {}
        virtual double getArea() {
            return width * height;
        }
        virtual double getPerim() {
            return 2 * (width + height);
        }
        virtual void print() {
            cout << (*this) << endl;
        }
        friend ostream& operator << (ostream &os, const Rectangle &r) {
            os << "Rectangle: (" << r.p1.x << ", " << r.p1.y << ") -- (" << r.p2.x << ", " << r.p1.y << ") -- (" << r.p2.x << ", " << r.p2.y << ") -- (" << r.p1.x << ", " << r.p2.y << ") -- (" << r.p1.x << ", " << r.p1.y << ")";
            return os;
        }
        friend istream& operator >> (istream &is, Rectangle &r) {
            is >> r.p1 >> r.p2;
            r.width = abs(r.p2.x - r.p1.x); r.height = abs(r.p2.y - r.p1.y);
            return is;
        }
};

class Circle : public Shape {
    public:
        Point center;
        double radius;
        static constexpr double PI = 3.1415926535897932384626;
        Circle(Point center, double radius) : center(center), radius(radius) {}
        virtual ~Circle() {}
        virtual double getArea() {
            return PI * pow(radius, 2);
        }
        virtual double getPerim() {
            return 2 * PI * radius;
        }
        virtual void print() {
            cout << (*this) << endl;
        }
        friend ostream& operator << (ostream &os, const Circle &c) {
            os << "Circle: center: (" << c.center.x << ", " << c.center.y << "), radius: " << c.radius;
            return os;
        }
        friend istream& operator >> (istream &is, Circle &c) {
            is >> c.center >> c.radius;
            return is;
        }
};

class Triangle : public Shape {
    private:
        double a, b, c;
    public:
        Point p1, p2, p3;
        Triangle(Point p1, Point p2, Point p3) : p1(p1), p2(p2), p3(p3) {
            a = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
            b = sqrt(pow(p3.x - p2.x, 2) + pow(p3.y - p2.y, 2));
            c = sqrt(pow(p1.x - p3.x, 2) + pow(p1.y - p3.y, 2));
        }
        virtual ~Triangle() {}
        virtual double getArea() {
            double s = getPerim() / 2;
            return sqrt(s * (s - a) * (s - b) * (s - c));
        }
        virtual double getPerim() {
            return a + b + c;
        }
        virtual void print() {
            cout << (*this) << endl;
        }
        friend ostream& operator << (ostream &os, const Triangle &t) {
            os << "Triangle: (" << t.p1.x << ", " << t.p1.y << ") -- (" << t.p2.x << ", " << t.p2.y << ") -- (" << t.p3.x << ", " << t.p3.y << ")";
            return os;
        }
        friend istream& operator >> (istream &is, Triangle &t) {
            is >> t.p1 >> t.p2 >> t.p3;
            t.a = sqrt(pow(t.p2.x - t.p1.x, 2) + pow(t.p2.y - t.p1.y, 2));
            t.b = sqrt(pow(t.p3.x - t.p2.x, 2) + pow(t.p3.y - t.p2.y, 2));
            t.c = sqrt(pow(t.p1.x - t.p3.x, 2) + pow(t.p1.y - t.p3.y, 2));
            return is;
        }
};

int main() {
    Shape *shapes[5];
    shapes[0] = new Point(0, 0);
    shapes[1] = new Line(Point(0, 0), Point(3, 4));
    shapes[2] = new Rectangle(Point(0, 0), Point(3, 4));
    shapes[3] = new Circle(Point(0, 0), 5);
    shapes[4] = new Triangle(Point(0, 0), Point(3, 0), Point(0, 4));
    for (int i = 0; i < 5; i++) {
        shapes[i]->print();
        cout << "area: " << shapes[i]->getArea() << endl;
        cout << "perimeter: " << shapes[i]->getPerim() << endl;
        if (i < 4) cout << "---------------------------------" << endl;
    }
    for (int i = 0; i < 5; i++) {
        delete shapes[i];
    }
    return 0;
}
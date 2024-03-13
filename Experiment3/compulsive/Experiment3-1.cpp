#include <iostream>

class Point {
    private:
        double x, y;

    public:
        Point(): x(0), y(0) {
            Print();
            std::cout << "Point Default Constructor called" << std::endl;
        }
        Point(double xx, double yy): x(xx), y(yy) {
            Print();
            std::cout << "Point Constructor called" << std::endl;
        }
        Point(const Point &px): x(px.x), y(px.y) {
            Print();    
            std::cout << "Point Copy Constructor called" << std::endl;
        }
        ~Point() {
            Print();
            std::cout << "Point Destructor called" << std::endl;
        }
        void set(double x, double y) {
            this->x = x;
            this->y = y;
        }
        void set(const Point &p) {
            x = p.x;
            y = p.y;
        }
        void setX(double x) {
            this->x = x;
        }
        void setY(double y) {
            this->y = y;
        }
        double getX() const {
            return x;
        }
        double getY() const {
            return y;
        }
        void Print() const {
            std::cout << "(" << x << ", " << y << ") ";
        }
        void move(double dx, double dy) {
            x += dx;
            y += dy;
        }
        Point &operator=(const Point &p) {
            x = p.x;
            y = p.y;
            return *this;
        }
        bool operator==(const Point &p) const {
            return x == p.x && y == p.y;
        }
        bool operator!=(const Point &p) const {
            return x != p.x || y != p.y;
        }
};

class Rectangle {
    private:
        Point left_bottom, right_top;

    public:
        Rectangle(): left_bottom(), right_top() {
            Print();
            std::cout << "Rectangle Default Constructor called" << std::endl;
        }
        Rectangle(const Point &p1, const Point &p2): left_bottom(p1), right_top(p2) {
            Print();
            std::cout << "Rectangle Constructor called" << std::endl;
        }
        Rectangle(double x1, double y1, double x2, double y2): left_bottom(x1, y1), right_top(x2, y2) {
            Print();
            std::cout << "Rectangle Constructor called" << std::endl;
        }
        Rectangle(const Rectangle &r): left_bottom(r.left_bottom), right_top(r.right_top) {
            Print();
            std::cout << "Rectangle Copy Constructor called" << std::endl;
        }
        ~Rectangle() {
            Print();
            std::cout << "Rectangle Destructor called" << std::endl;
        }
        void set(const Point &p1, const Point &p2) {
            left_bottom.set(p1);
            right_top.set(p2);
        }
        void set(double x1, double y1, double x2, double y2) {
            left_bottom.set(x1, y1);
            right_top.set(x2, y2);
        }
        void setLeftBottom(const Point &p) {
            left_bottom.set(p);
        }
        void setRightTop(const Point &p) {
            right_top.set(p);
        }
        Point getLeftBottom() const {
            return left_bottom;
        }
        Point getRightTop() const {
            return right_top;
        }
        void Print() const {
            std::cout << "Left Bottom: ";
            left_bottom.Print();
            std::cout << "Right Top: ";
            right_top.Print();
        }
        double Area() const {
            return (right_top.getX() - left_bottom.getX()) * (right_top.getY() - left_bottom.getY());
        }
        double Perimeter() const {
            return 2 * (right_top.getX() - left_bottom.getX() + right_top.getY() - left_bottom.getY());
        }
        bool isSquare() const {
            return (right_top.getX() - left_bottom.getX()) == (right_top.getY() - left_bottom.getY());
        }
        Point Center() const {
            return Point((left_bottom.getX() + right_top.getX()) / 2, (left_bottom.getY() + right_top.getY()) / 2);
        }
        Rectangle &operator=(const Rectangle &r) {
            left_bottom = r.left_bottom;
            right_top = r.right_top;
            return *this;
        }
        bool operator==(const Rectangle &r) const {
            return left_bottom.getX() == r.left_bottom.getX() && left_bottom.getY() == r.left_bottom.getY() && right_top.getX() == r.right_top.getX() && right_top.getY() == r.right_top.getY();
        }
        bool operator!=(const Rectangle &r) const {
            return left_bottom.getX() != r.left_bottom.getX() || left_bottom.getY() != r.left_bottom.getY() || right_top.getX() != r.right_top.getX() || right_top.getY() != r.right_top.getY();
        }
        void move(double dx, double dy) {
            left_bottom.move(dx, dy);
            right_top.move(dx, dy);
        }
};

inline void test() {
    Point p1(1, 1), p2(2, 2);
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    
    Rectangle r1(p1, p2);
    r1.Print(); std::cout << std::endl; // Left Bottom: (1, 1) Right Top: (2, 2)
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    
    std::cout << "Area: " << r1.Area() << std::endl; // Area: 1
    std::cout << "Perimeter: " << r1.Perimeter() << std::endl; // Perimeter: 4
    std::cout << "Is Square: " << r1.isSquare() << std::endl; // Is Square: 1
    Point center1 = r1.Center();
    std::cout << "Center: (" << center1.getX() << ", " << center1.getY() << ")" << std::endl; // Center: (1.5 1.5)
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;

    r1.move(1, 1);
    r1.Print(); std::cout << std::endl; // Left Bottom: (2, 2) Right Top: (3, 3)
    Point center2 = r1.Center();
    std::cout << "Center: (" << center2.getX() << ", " << center2.getY() << ")" << std::endl; // Center: (2.5 2.5)
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    
    Rectangle r2(r1);
    r2.Print(); std::cout << std::endl; // Left Bottom: (2, 2) Right Top: (3, 3)
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    
    Rectangle r3;
    r3 = r2;
    r3.Print(); std::cout << std::endl; // Left Bottom: (2, 2) Right Top: (3, 3)
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
}

int main() {
    test();
    return 0;
}
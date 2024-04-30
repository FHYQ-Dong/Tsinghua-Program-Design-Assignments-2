# Experiment8-董皓彧
环境：
```txt
g++.exe (x86_64-win32-seh-rev1, Built by MinGW-Builds project) 13.2.0
Visual Stdio Code 1.88.1
```
作业仓库地址：
[https://github.com/FHYQ-Dong/Tsinghua-Program-Design-Assignments-2/tree/main/Experiment8](https://github.com/FHYQ-Dong/Tsinghua-Program-Design-Assignments-2/tree/main/Experiment8)
## 必做题
### Experiment8-1
题目：
```txt
分析下列程序的运行结果
```
输入格式：
```txt
无
```
输出格式：
```txt
略
```
代码：
```cpp
#include <iostream>
using namespace std;

class B {
    public:
        void f1() {
            cout << "B::f1()" << endl;
        }
};

class D : public B {
    public:
        void f1() {
            cout << "D::f1()" << endl;
        }
};

void f(B &rb) { // 由于形参类型为B，所以始终调用B类的f1()函数
    rb.f1();
}

int main() {
    D d;
    B b, &rb1 = b, &rb2 = d;
    f(rb1); // B::f1()
    f(rb2); // B::f1()
    return 0;
}
```
输入1：
```txt

```
输出1：
```txt
B::f1()
B::f1()
```

### Experiment8-2
题目：
```txt
声明一个哺乳动物Mammal类，再由此派生出狗Dog类，二者都定义speak()成员函数，基类中定义为虚函数。声明一个Dog类的对象，调用Speak()函数，观察运行结果。
```
输入格式：
```txt
无
```
输出格式：
```txt
略
```
代码：
```cpp
#include <iostream>
using namespace std;

class Mammal {
    public:
        virtual void speak() {
            cout << "Mammal speaks!" << endl;
        }
};

class Dog : public Mammal {
    public:
        virtual void speak() {
            cout << "Woof!" << endl;
        }
};

int main() {
    Dog d;
    d.speak();
    return 0;
}
```
输入1：
```txt

```
输出1：
```txt
Woof!
```

### Experiment8-3
题目：
```txt
声明一个Shape抽象类，在此基础上派生出Rectangle和Circle类，二者都有getArea()函数计算对象的面积，getPerim()函数计算对象的周长。给定部分程序代码，根据题意要求和基类代码，完成整个程序。
```
输入格式：
```txt
无
```
输出格式：
```txt
略
```
代码：
```cpp
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
```
输入1：
```txt

```
输出1：
```txt
Circle radius: 5
Circle area: 78.5398
Circle perimeter: 31.4159
====================
Rectangle width: 4, height: 6
Rectangle area: 24
Rectangle perimeter: 20
```

## 选做题
### Optional-Experiment8-1
题目：
```txt
回顾上一讲附加题，通过继承方式实现了点、线、矩阵类，请考虑在此基础上实现下列功能；
1. 定义抽象类shape，包含求面积函数和输出函数，其中输出函数用纯虚函数实现；
2. 除了矩阵类之外，再派生出三角类和圆类；这些派生类中输出函数用于说明派生类是什么形状；
3. 在主函数中，使用基函数指针数组，分别调用不同类实体
```
输入格式：
```txt
无
```
输出格式：
```txt
略
```
代码：
```cpp
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
```
输入1：
```txt

```
输出1：
```txt
Point: (0, 0)
area: 0
perimeter: 0
---------------------------------
Line: (0, 0) -- (3, 4)
area: 0
perimeter: 5
---------------------------------
Rectangle: (0, 0) -- (3, 0) -- (3, 4) -- (0, 4) -- (0, 0)
area: 12
perimeter: 14
---------------------------------
Circle: center: (0, 0), radius: 5
area: 78.5398
perimeter: 31.4159
---------------------------------
Triangle: (0, 0) -- (3, 0) -- (0, 4)
area: 6
perimeter: 12
```


#include <iostream>
#include <cmath>
using namespace std;

class Horizontal;
class Pole;

class Horizontal {
    public:
        double x, y;

        Horizontal();
        Horizontal(double x, double y);
        Horizontal(const Horizontal &h);
        Horizontal(const Pole &p);

        double distance(const Horizontal &h) const;
        double distance(const Pole &p) const;

        Horizontal operator+(const Horizontal &h) const;
        Horizontal operator+(const Pole &p) const;
        Horizontal operator-(const Horizontal &h) const;
        Horizontal operator-(const Pole &p) const;
        Horizontal operator*(double k) const;
        Horizontal operator/(double k) const;
        friend Horizontal operator*(double k, const Horizontal &h);
        operator Pole() const;

        friend ostream &operator<<(ostream &os, const Horizontal &h);
        friend istream &operator>>(istream &is, Horizontal &h);
};

class Pole {
    public:
        double r, theta;
        constexpr static double PI = 3.14159265358979323846;

        Pole();
        Pole(double r, double theta);
        Pole(const Pole &p);
        Pole(const Horizontal &h);

        double distance(const Pole &p) const;
        double distance(const Horizontal &h) const;
        
        Pole operator+(const Pole &p) const;
        Pole operator+(const Horizontal &h) const;
        Pole operator-(const Pole &p) const;
        Pole operator-(const Horizontal &h) const;
        Pole operator*(double k) const;
        Pole operator/(double k) const;
        friend Pole operator*(double k, const Pole &p);
        operator Horizontal() const;

        friend ostream &operator<<(ostream &os, const Pole &p);
        friend istream &operator>>(istream &is, Pole &p);
};

Horizontal::Horizontal() : Horizontal(0, 0) {}
Horizontal::Horizontal(double x, double y) : x(x), y(y) {}
Horizontal::Horizontal(const Horizontal &h) : Horizontal(h.x, h.y) {}
Horizontal::Horizontal(const Pole &p) : x(p.r * cos(p.theta)), y(p.r * sin(p.theta)) {}
double Horizontal::distance(const Horizontal &h) const {
    return sqrt(pow(x - h.x, 2) + pow(y - h.y, 2));
}
double Horizontal::distance(const Pole &p) const {
    return sqrt(pow(x - p.r * cos(p.theta), 2) + pow(y - p.r * sin(p.theta), 2));
}
Horizontal Horizontal::operator+(const Horizontal &h) const {
    return Horizontal(x + h.x, y + h.y);
}
Horizontal Horizontal::operator+(const Pole &p) const {
    return Horizontal(x + p.r * cos(p.theta), y + p.r * sin(p.theta));
}
Horizontal Horizontal::operator-(const Horizontal &h) const {
    return Horizontal(x - h.x, y - h.y);
}
Horizontal Horizontal::operator-(const Pole &p) const {
    return Horizontal(x - p.r * cos(p.theta), y - p.r * sin(p.theta));
}
Horizontal Horizontal::operator*(double k) const {
    return Horizontal(x * k, y * k);
}
Horizontal Horizontal::operator/(double k) const {
    return Horizontal(x / k, y / k);
}
Horizontal operator*(double k, const Horizontal &h) {
    return h * k;
}
Horizontal::operator Pole() const {
    return Pole(sqrt(pow(x, 2) + pow(y, 2)), atan2(y, x));
}
ostream &operator<<(ostream &os, const Horizontal &h) {
    os << "Horizontal: (" << h.x << ", " << h.y << ")";
    return os;
}
istream &operator>>(istream &is, Horizontal &h) {
    is >> h.x >> h.y;
    return is;
}

Pole::Pole() : Pole(0, 0) {}
Pole::Pole(double r, double theta) : r(r), theta(theta) {
    if (r < 0) {
        r = -r;
        theta += PI;
    }
    theta = fmod(theta, 2 * PI);
}
Pole::Pole(const Pole &p) : Pole(p.r, p.theta) {}
Pole::Pole(const Horizontal &h) : r(sqrt(pow(h.x, 2) + pow(h.y, 2))), theta(atan2(h.y, h.x)) {}
double Pole::distance(const Pole &p) const {
    return sqrt(pow(r - p.r, 2) + pow(fmod(theta - p.theta + PI, 2 * PI) - PI, 2));
}
double Pole::distance(const Horizontal &h) const {
    return sqrt(pow(h.x - r * cos(theta), 2) + pow(h.y - r * sin(theta), 2));
}
Pole Pole::operator+(const Pole &p) const {
    return Pole(sqrt(pow(r, 2) + pow(p.r, 2) + 2 * r * p.r * cos(theta - p.theta)), fmod(theta + p.theta, 2 * PI));
}
Pole Pole::operator+(const Horizontal &h) const {
    return Pole(sqrt(pow(r, 2) + pow(h.x, 2) + pow(h.y, 2) + 2 * r * (h.x * cos(theta) + h.y * sin(theta))), atan2(r * sin(theta) + h.y, r * cos(theta) + h.x));
}
Pole Pole::operator-(const Pole &p) const {
    return Pole(sqrt(pow(r, 2) + pow(p.r, 2) - 2 * r * p.r * cos(theta - p.theta)), fmod(theta - p.theta + PI, 2 * PI));
}
Pole Pole::operator-(const Horizontal &h) const {
    return Pole(sqrt(pow(r, 2) + pow(h.x, 2) + pow(h.y, 2) - 2 * r * (h.x * cos(theta) + h.y * sin(theta))), atan2(r * sin(theta) - h.y, r * cos(theta) - h.x));
}
Pole Pole::operator*(double k) const {
    return Pole(r * k, theta);
}
Pole Pole::operator/(double k) const {
    return Pole(r / k, theta);
}
Pole::operator Horizontal() const {
    return Horizontal(r * cos(theta), r * sin(theta));
}
Pole operator*(double k, const Pole &p) {
    return p * k;
}
ostream &operator<<(ostream &os, const Pole &p) {
    os << "Pole: (" << p.r << ", " << p.theta << ")";
    return os;
}
istream &operator>>(istream &is, Pole &p) {
    is >> p.r >> p.theta;
    return is;
}
int main() {
    Horizontal h;
    Pole p;
    cin >> h >> p;
    cout << h << endl << p << endl;
    cout << "+: " << h + p << " " << p + h << endl;
    cout << "-: " << h - p << " " << p - h << endl;
    cout << "*2: " << h * 2 << " " << 2 * h << " " << p * 2 << " " << 2 * p << endl;
    cout << "/2: " << h / 2 << " " << p / 2 << endl;
    return 0;
}
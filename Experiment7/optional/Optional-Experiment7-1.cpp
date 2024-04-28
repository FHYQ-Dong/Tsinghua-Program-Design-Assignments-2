#include <iostream>

class Point {
    public:
        int x, y;
        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }
        Point() {
            x = 0;
            y = 0;
        }
        Point(const Point &p) {
            x = p.x;
            y = p.y;
        }
        virtual ~Point() {}

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }
};

class Line : virtual public Point {
    private:
        Point p2;

    public:
        Line(int x1, int y1, int x2, int y2) : Point(x1, y1), p2(x2, y2) {}
        Line() : Point(), p2() {}
        Line(const Point &p1, const Point &p2) : Point(p1), p2(p2) {}
        Line(const Line &l) : Point(l), p2(l.p2) {}
        virtual ~Line() {}

        Point getP1() {
            return Point(x, y);
        }
        Point getP2() {
            return p2;
        }
        void setP1(Point &p) {
            x = p.x;
            y = p.y;
        }
        void setP2(Point &p) {
            p2 = p;
        }

    friend std::ostream& operator<<(std::ostream& os, const Line& l) {
        os << Point(l) << " - " << l.p2;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Line& l) {
        is >> l >> l.p2;
        return is;
    }
};

class Rect : public Line {
    private:
        Line l2, l3, l4;

    public:
        Rect(int x1, int y1, int x2, int y2) : Line(x1, y1, x2, y1), l2(x2, y1, x2, y2), l3(x2, y2, x1, y2), l4(x1, y2, x1, y1) {}
        Rect() : Line(), l2(), l3(), l4() {}
        Rect(const Point &p1, const Point &p2) : Line(p1.x, p1.y, p2.x, p1.y), l2(p2.x, p1.y, p2.x, p2.y), l3(p2.x, p2.y, p1.x, p2.y), l4(p1.x, p2.y, p1.x, p1.y) {}
        Rect(const Rect &r) : Line(r), l2(r.l2), l3(r.l3), l4(r.l4) {}
        virtual ~Rect() {}

    friend std::ostream& operator<<(std::ostream& os, const Rect& r) {
        os << Line(r) << " - " << r.l3 << std::endl;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Rect& r) {
        is >> r >> r.l2 >> r.l3 >> r.l4;
        return is;
    }
};

int main() {
    Point p1(1, 1), p2(2, 2);
    Line l1(p1, p2);
    Rect r1(p1, p2);
    std::cout << "Point 1: " << p1 << std::endl;
    std::cout << "Point 2: " << p2 << std::endl;
    std::cout << "Line 1: " << l1 << std::endl;
    std::cout << "Rect 1: " << r1 << std::endl;
    return 0;
}
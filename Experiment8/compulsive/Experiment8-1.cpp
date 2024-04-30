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
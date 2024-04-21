#include <iostream>
using namespace std;

class B1 {
    public:
        B1(int i) { cout << "constructing B1 " << i << endl; }
        ~B1() { cout << "destructing B1" << endl; }  
};

class B2 {
    public:
        B2() { cout << "constructing B2 "  << endl; }
        ~B2() { cout << "destructing B2" << endl; }
};

class C : public B2, virtual public B1 {
    private:
        int j;
        B1 memberB1;
        B2 memberB2;
    public:
        C(int a, int b, int c): B1(a), memberB1(b), j(c) {
            cout << "constructing C " << j << endl;
        }
        ~C() {
            cout << "destructing C" << endl;
        }
};

int main() {
    C obj(1, 2, 3);
    return 0;
}
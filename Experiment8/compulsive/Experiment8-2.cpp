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
#include <iostream>
#include <cstring>
using std::cout, std::endl;

class Person {
    private:
        char* name; 
        int age;
    public:
        Person() {
            name = nullptr;
            age = 0;
            cout << "default constructor" << endl;
        }
        Person(const char* name, int age) {
            size_t len = strlen(name);
            this->name = new char[len + 1];
            strcpy(this->name, name);
            this->age = age;
            cout << "constructor with args" << endl;
        }
        Person(const Person& p) {
            size_t len = strlen(p.name);
            this->name = new char[len + 1];
            strcpy(this->name, p.name);
            this->age = p.age;
            cout << "deep copy constructor" << endl;
        }
        ~Person() {
            // delete[] name; // cause error if name is nullptr (when shallow copy is used & the original object is destructed)
            cout << "destructor" << endl;
        }
};

int main() {
    // Constructor
    Person p1("Tom", 20), p2;
    // Shallow copy
    p2 = p1;
    // Deep copy
    Person p3 = p1;
    return 0;
}
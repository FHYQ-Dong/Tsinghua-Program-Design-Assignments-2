#include <iostream>
#include <string>
using namespace std;

template <class T>
class Base {
    private:
        T* a;
        int n;
    public:
        Base() {
            n = 0;
        }
        template <int m>
        Base(T (&a)[m]) {
            this->n = m;
            this->a = new T[m];
            for (int i = 0; i < n; i++) this->a[i] = a[i];
        }
        Base(Base &b) {
            n = b.n;
            for (int i = 0; i < n; i++) a[i] = b.a[i];
        }
        ~Base() {
            n = 0;
        }
        int search(T x) {
            for (int i = 0; i < n; i++) {
                if (a[i] == x) return i;
            }
            return -1;
        }
};


int main() {
    string s[10] = {
        "apple", "banana", "cherry", "date", "elderberry",
        "fig", "grape", "honeydew", "imbe", "jackfruit"
    };
    Base b(s);
    for (int i = 0; i < 10; i++) {
        cout << "idx of " << s[i] << " is " << b.search(s[i]) << endl;
    }
    return 0;
}
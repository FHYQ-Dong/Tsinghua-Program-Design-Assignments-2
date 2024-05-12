#include <iostream>
using namespace std;

int main() {
    double x = 123.456;
    cout.width(10);
    cout.setf(ios::dec, ios::basefield);
    cout << x << endl; // ___123.456
    cout.setf(ios::left);
    cout << x << endl; // 123.456___
    cout.width(15);
    cout.setf(ios::right, ios::left);
    cout << x << endl; // ________123.456
    cout.setf(ios::showpos);
    cout << x << endl; // +123.456
    cout << -x << endl; // -123.456
    cout.setf(ios::scientific);
    cout << x << endl; // 1.234560e+02
    return 0;
}
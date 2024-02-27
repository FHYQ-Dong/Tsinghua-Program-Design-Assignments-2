#include <iostream>
using std::cout, std::endl;

int main() {
    // init
    int a[11][11] = {0};
    for (int i = 0; i < 11; ++i) {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    // calculate
    for (int i = 1; i < 11; ++i) {
        for (int j = 1; j < i; ++j) {
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }
    // print
    for (int i = 1; i < 11; ++i) {
        for (int j = 0; j <= i; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
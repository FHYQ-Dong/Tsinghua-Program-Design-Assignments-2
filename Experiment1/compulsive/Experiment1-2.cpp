#include <iostream>
using std::cin, std::cout, std::endl;

inline double func(int n) {
    double ***a = new double** [n];
    for (int i = 0; i < n; ++i) {
        a[i] = new double* [n];
        for (int j = 0; j < n; ++j) {
            a[i][j] = new double [n];
            for (int k = 0; k < n; ++k) 
                a[i][j][k] = i*j/(k+1);
        }
    }
    // calculate
    double sum = 0;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            for (int k = 0; k < n; ++k) 
                sum += a[i][j][k];
    // free
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) 
            delete [] a[i][j];
        delete [] a[i];
    }
    return sum;
}

int main() {
    int n; cin >> n;
    cout << func(n) << endl;
    return 0;
}
    
#include <iostream>
#include <string>
using namespace std;

template <class T, int n>
void sort(T (&a)[n], int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    T x = a[(l + r) / 2];
    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    sort(a, l, j);
    sort(a, i, r);
}

int main() {
    string s[10] = {
        "lemon", "kiwi", "honeydew", "grape", "fig",
        "elderberry", "date", "coconut", "banana", "apple"
    };
    sort(s, 0, 9);
    for (int i = 0; i < 10; i++) {
        cout << s[i] << endl;
    }
    return 0;
}
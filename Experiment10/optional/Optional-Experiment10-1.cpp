#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

template <class T>
void sort(T* begin, T* end, bool (*cmp)(T, T)=[](T a, T b) { return a < b; }) {
    if (begin >= end) return;
    T* pivot = begin;
    T* left = begin;
    T* right = end;
    while (left < right) {
        while (left < right && cmp(*left, *pivot)) left++;
        while (left < right && !cmp(*right, *pivot)) right--;
        if (left < right) {
            T tmp = *left;
            *left = *right;
            *right = tmp;
        }
    }
    T tmp = *pivot;
    *pivot = *right;
    *right = tmp;
    sort(begin, right - 1, cmp);
    sort(right + 1, end, cmp);
}

int main() {
    // generate random numbers
    srand(time(0));
    int a[10];
    for (int i = 0; i < 10; i++) a[i] = rand() % 100;
    // before sort
    for (int i = 0; i < 10; i++) cout << a[i] << " ";
    cout << endl;
    // sort
    sort(a, a + 9);
    // after sort
    for (int i = 0; i < 10; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}
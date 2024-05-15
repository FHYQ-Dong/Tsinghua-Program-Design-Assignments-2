#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
    // generate random numbers
    srand(time(0));
    vector<int> v(120);
    for (int i = 0; i < v.size(); i++) v[i] = rand();

    // remove Fibonacci numbers
    int idx = 1, tmp = 2;
    while (idx < v.size()) {
        v.erase(v.begin() + idx);
        idx += tmp; swap(idx, tmp);
    }

    // sort the first half in ascending order and the second half in descending order
    int mid = v.size() / 2;
    sort(v.begin(), v.begin() + mid, less<int>());
    sort(v.begin() + mid, v.end(), greater<int>());

    // output the result
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    return 0;
}
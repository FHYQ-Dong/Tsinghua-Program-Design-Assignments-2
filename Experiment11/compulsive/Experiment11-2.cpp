#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
    // generate random numbers
    srand(time(0));
    set<int> A, B, C;
    for (int i = 0; i < 12; i++) A.insert(rand());
    for (int i = 0; i < 6; i++) B.insert(rand());
    for (int i = 0; i < 18; i++) C.insert(rand());
    
    // calculate D & E
    set<int> D;
    for (auto it = A.begin(); it != A.end(); it++) {
        if (B.find(*it) != B.end()) D.insert(*it);
    }
    set<int> E(B);
    for (auto it = D.begin(); it != D.end(); it++)
        E.insert(*it);

    // output the result
    for (auto it = E.begin(); it != E.end(); it++)
        cout << *it << " ";
    return 0;
}
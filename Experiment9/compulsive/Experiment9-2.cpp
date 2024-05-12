#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
void gen(const string& filename) {
    size_t len = rand() % 1000 + 1;
    T* arr = new T[len];

    ofstream fout(filename, ios::binary);
    for (size_t i = 0; i < len; i++) arr[i] = T(rand());
    sort(arr, arr + len);
    fout.write(reinterpret_cast<char*>(arr), len * sizeof(T));
    fout.close();
    delete[] arr;
    return;
}

int main() {
    srand(time(NULL));
    gen<int>("Experiment9-2-1.bin");
    gen<int>("Experiment9-2-2.bin");

    ifstream fin1("Experiment9-2-1.bin", ios::binary);
    ifstream fin2("Experiment9-2-2.bin", ios::binary);
    ofstream fout("Experiment9-2-3.bin", ios::binary);
    int bufa, bufb;
    while (fin1.read(reinterpret_cast<char*>(&bufa), sizeof(int)) && fin2.read(reinterpret_cast<char*>(&bufb), sizeof(int))) {
        if (bufa < bufb) fout.write(reinterpret_cast<char*>(&bufa), sizeof(int));
        else fout.write(reinterpret_cast<char*>(&bufb), sizeof(int));
    }
    while (fin1.read(reinterpret_cast<char*>(&bufa), sizeof(int))) fout.write(reinterpret_cast<char*>(&bufa), sizeof(int));
    while (fin2.read(reinterpret_cast<char*>(&bufb), sizeof(int))) fout.write(reinterpret_cast<char*>(&bufb), sizeof(int));
    fin1.close(); fin2.close(); fout.close();
    cout << "Check Experiment9-2-3.bin" << endl;
    return 0;
}
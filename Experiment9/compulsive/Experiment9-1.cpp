#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;
    ofstream fout("Experiment9-1.txt");
    while (getline(cin, line)) fout << line << endl;
    fout.close();

    ifstream fin("Experiment9-1.txt");
    int line_cnt = 0;
    while (getline(fin, line)) {
        cout << line << endl;
        line_cnt++;
    }
    cout << "Total lines: " << line_cnt << endl;
    fin.close();
}
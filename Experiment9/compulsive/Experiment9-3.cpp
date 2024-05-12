#include <iostream>
#include <fstream>
#include <strstream>
using namespace std;

int main() {
    char c[100], d[100], buf[100];
    ofstream fout("Experiment9-3-1.txt");
    while (cin.getline(buf, 100)) {
        ostrstream ostr(c, 100);
        ostr << buf << ends;
        fout << c << endl;
    }
    fout.close();

    ifstream fin("Experiment9-3-1.txt");
    while (fin.getline(buf, 100)) {
        ostrstream ostr(d, 100);
        ostr << buf << ends;
        cout << d << endl;
    }
    fin.close();
    return 0;
}
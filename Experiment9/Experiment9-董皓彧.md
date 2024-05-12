# Experiment9-董皓彧
环境：
```txt
g++.exe (x86_64-win32-seh-rev1, Built by MinGW-Builds project) 13.2.0
Visual Stdio Code 1.89.0
```
作业仓库地址：
[https://github.com/FHYQ-Dong/Tsinghua-Program-Design-Assignments-2/tree/main/Experiment9](https://github.com/FHYQ-Dong/Tsinghua-Program-Design-Assignments-2/tree/main/Experiment9)

**本次作业中所有涉及文件操作的题目的文件输入及输出请在git仓库中查看。**

## 必做题
### Experiment9-1
题目：
```txt
建立一个文本文件,从键盘输入一篇短文存放在该文件中,短文由若干行构成,每行不超过30个字符。然后将文本文件读出,显示在屏幕上并统计该文件的行数。
```
输入格式：
```txt
若干行文本，每行不超过30个字符。
```
输出格式：
```txt
一个文本文件，文件名为Experiment9-1.txt，内容为输入的短文；同时输出到终端中。
```
代码：
```cpp
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
```
输入1：
```txt
AAAAAAAAAAAAAAAAA
BBBB
CCCCCCCCC
DDDDDD
EEEEEEEEEEE
FF
```
输出1：
```txt
AAAAAAAAAAAAAAAAA
BBBB
CCCCCCCCC
DDDDDD
EEEEEEEEEEE
FF
Total lines: 6
```

### Experiment9-2
题目：
```txt
设有两个按升序排列的二进制数据文件f和g,将它们合并生成一个新的升序二进制数据文件h。
```
输入格式：
```txt
两个文件二进制，文件名分别为Experiment9-2-1.bin和Experiment9-2-2.bin，内容为两个升序排列的二进制数据文件。
```
输出格式：
```txt
一个二进制文件，文件名为Experiment9-2-3.bin，内容为合并后的升序二进制数据文件。
```
代码：
```cpp
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
```
输入1：
```txt

```
输出1：
```txt
Check Experiment9-2-3.bin
```

### Experiment9-3
题目：
```txt
在Experiment9-1基础上,采用字符串流类的相关概念,修改程序,将键盘读人的数据先存放在数组c中,然后在写人到文件。接着从文件中再读入到数组d中,在从数组d输出到屏幕。
```
输入格式：
```txt
若干行文本，每行不超过30个字符。
```
输出格式：
```txt
一个文本文件，文件名为Experiment9-3.txt，内容为输入的短文；同时输出到终端中。
```
代码：
```cpp
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
```
输入1：
```txt
AAAAAAAAAAAAAAAAA
BBBB
CCCCCCCCC
DDDDDD
EEEEEEEEEEE
FF
```
输出1：
```txt
AAAAAAAAAAAAAAAAA
BBBB
CCCCCCCCC
DDDDDD
EEEEEEEEEEE
FF
```

### Experiment9-4
题目：
```txt
阅读下列程序，写出执行结果
```
输入格式：
```txt
无
```
输出格式：
```txt
略
```
代码：
```cpp
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
```
输入1：
```txt

```
输出1：
```txt
   123.456
123.456
        123.456
+123.456
-123.456
+1.234560e+02
```

## 选做题
### Optional-Experiment9-1
题目：
```txt
定义一个极坐标类数据成员包括极径和极角两个数字；成员函数包括但不限于构造函数、复制构造函数、析构函数、及其他重载函数，可通过键盘输入复数、向屏幕输出复数。
•要求重载“ 和“ “>>”>>”，使极坐标类可以直接调用；
•要求重载加、减、乘、 除法
```
输入格式：
```txt
无
```
输出格式：
```txt
略
```
代码：
```cpp
#include <iostream>
#include <cmath>
using namespace std;

class Horizontal;
class Pole;

class Horizontal {
    public:
        double x, y;

        Horizontal();
        Horizontal(double x, double y);
        Horizontal(const Horizontal &h);
        Horizontal(const Pole &p);

        double distance(const Horizontal &h) const;
        double distance(const Pole &p) const;

        Horizontal operator+(const Horizontal &h) const;
        Horizontal operator+(const Pole &p) const;
        Horizontal operator-(const Horizontal &h) const;
        Horizontal operator-(const Pole &p) const;
        Horizontal operator*(double k) const;
        Horizontal operator/(double k) const;
        friend Horizontal operator*(double k, const Horizontal &h);
        operator Pole() const;

        friend ostream &operator<<(ostream &os, const Horizontal &h);
        friend istream &operator>>(istream &is, Horizontal &h);
};

class Pole {
    public:
        double r, theta;
        constexpr static double PI = 3.14159265358979323846;

        Pole();
        Pole(double r, double theta);
        Pole(const Pole &p);
        Pole(const Horizontal &h);

        double distance(const Pole &p) const;
        double distance(const Horizontal &h) const;
        
        Pole operator+(const Pole &p) const;
        Pole operator+(const Horizontal &h) const;
        Pole operator-(const Pole &p) const;
        Pole operator-(const Horizontal &h) const;
        Pole operator*(double k) const;
        Pole operator/(double k) const;
        friend Pole operator*(double k, const Pole &p);
        operator Horizontal() const;

        friend ostream &operator<<(ostream &os, const Pole &p);
        friend istream &operator>>(istream &is, Pole &p);
};

Horizontal::Horizontal() : Horizontal(0, 0) {}
Horizontal::Horizontal(double x, double y) : x(x), y(y) {}
Horizontal::Horizontal(const Horizontal &h) : Horizontal(h.x, h.y) {}
Horizontal::Horizontal(const Pole &p) : x(p.r * cos(p.theta)), y(p.r * sin(p.theta)) {}
double Horizontal::distance(const Horizontal &h) const {
    return sqrt(pow(x - h.x, 2) + pow(y - h.y, 2));
}
double Horizontal::distance(const Pole &p) const {
    return sqrt(pow(x - p.r * cos(p.theta), 2) + pow(y - p.r * sin(p.theta), 2));
}
Horizontal Horizontal::operator+(const Horizontal &h) const {
    return Horizontal(x + h.x, y + h.y);
}
Horizontal Horizontal::operator+(const Pole &p) const {
    return Horizontal(x + p.r * cos(p.theta), y + p.r * sin(p.theta));
}
Horizontal Horizontal::operator-(const Horizontal &h) const {
    return Horizontal(x - h.x, y - h.y);
}
Horizontal Horizontal::operator-(const Pole &p) const {
    return Horizontal(x - p.r * cos(p.theta), y - p.r * sin(p.theta));
}
Horizontal Horizontal::operator*(double k) const {
    return Horizontal(x * k, y * k);
}
Horizontal Horizontal::operator/(double k) const {
    return Horizontal(x / k, y / k);
}
Horizontal operator*(double k, const Horizontal &h) {
    return h * k;
}
Horizontal::operator Pole() const {
    return Pole(sqrt(pow(x, 2) + pow(y, 2)), atan2(y, x));
}
ostream &operator<<(ostream &os, const Horizontal &h) {
    os << "Horizontal: (" << h.x << ", " << h.y << ")";
    return os;
}
istream &operator>>(istream &is, Horizontal &h) {
    is >> h.x >> h.y;
    return is;
}

Pole::Pole() : Pole(0, 0) {}
Pole::Pole(double r, double theta) : r(r), theta(theta) {
    if (r < 0) {
        r = -r;
        theta += PI;
    }
    theta = fmod(theta, 2 * PI);
}
Pole::Pole(const Pole &p) : Pole(p.r, p.theta) {}
Pole::Pole(const Horizontal &h) : r(sqrt(pow(h.x, 2) + pow(h.y, 2))), theta(atan2(h.y, h.x)) {}
double Pole::distance(const Pole &p) const {
    return sqrt(pow(r - p.r, 2) + pow(fmod(theta - p.theta + PI, 2 * PI) - PI, 2));
}
double Pole::distance(const Horizontal &h) const {
    return sqrt(pow(h.x - r * cos(theta), 2) + pow(h.y - r * sin(theta), 2));
}
Pole Pole::operator+(const Pole &p) const {
    return Pole(sqrt(pow(r, 2) + pow(p.r, 2) + 2 * r * p.r * cos(theta - p.theta)), fmod(theta + p.theta, 2 * PI));
}
Pole Pole::operator+(const Horizontal &h) const {
    return Pole(sqrt(pow(r, 2) + pow(h.x, 2) + pow(h.y, 2) + 2 * r * (h.x * cos(theta) + h.y * sin(theta))), atan2(r * sin(theta) + h.y, r * cos(theta) + h.x));
}
Pole Pole::operator-(const Pole &p) const {
    return Pole(sqrt(pow(r, 2) + pow(p.r, 2) - 2 * r * p.r * cos(theta - p.theta)), fmod(theta - p.theta + PI, 2 * PI));
}
Pole Pole::operator-(const Horizontal &h) const {
    return Pole(sqrt(pow(r, 2) + pow(h.x, 2) + pow(h.y, 2) - 2 * r * (h.x * cos(theta) + h.y * sin(theta))), atan2(r * sin(theta) - h.y, r * cos(theta) - h.x));
}
Pole Pole::operator*(double k) const {
    return Pole(r * k, theta);
}
Pole Pole::operator/(double k) const {
    return Pole(r / k, theta);
}
Pole::operator Horizontal() const {
    return Horizontal(r * cos(theta), r * sin(theta));
}
Pole operator*(double k, const Pole &p) {
    return p * k;
}
ostream &operator<<(ostream &os, const Pole &p) {
    os << "Pole: (" << p.r << ", " << p.theta << ")";
    return os;
}
istream &operator>>(istream &is, Pole &p) {
    is >> p.r >> p.theta;
    return is;
}
int main() {
    Horizontal h;
    Pole p;
    cin >> h >> p;
    cout << h << endl << p << endl;
    cout << "+: " << h + p << " " << p + h << endl;
    cout << "-: " << h - p << " " << p - h << endl;
    cout << "*2: " << h * 2 << " " << 2 * h << " " << p * 2 << " " << 2 * p << endl;
    cout << "/2: " << h / 2 << " " << p / 2 << endl;
    return 0;
}
```
输入1：
```txt

```
输出1：
```txt
Horizontal: (0, 0)
Pole: (0, 0)
+: Horizontal: (0, 0) Pole: (0, 0)
-: Horizontal: (0, 0) Pole: (0, 0)
*2: Horizontal: (0, 0) Horizontal: (0, 0) Pole: (0, 0) Pole: (0, 0)
/2: Horizontal: (0, 0) Pole: (0, 0)
```


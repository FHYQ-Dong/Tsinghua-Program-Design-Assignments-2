# Experiment10-董皓彧
环境：
```txt
g++.exe (x86_64-win32-seh-rev1, Built by MinGW-Builds project) 13.2.0
Visual Stdio Code 1.89.0
```
作业仓库地址：
[https://github.com/FHYQ-Dong/Tsinghua-Program-Design-Assignments-2/tree/main/Experiment10](https://github.com/FHYQ-Dong/Tsinghua-Program-Design-Assignments-2/tree/main/Experiment10)
## 必做题
### Experiment10-1
题目：
```txt
解释为什么在C++每个程序前需要加一条“using namespace std;”
```
答：
```txt
C++中标准函数、类等定义在namespace std中，在程序前加using namespace std;可以在之后使用标准函数、类的时候不再需要作用域限定符std::
```

### Experiment10-2
题目：
```txt
设计一个函数模板,其中包括数据成员T a[n]以及对其进行排序的成员函数sort(),模板参数T可实例化成字符串。
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
```
输入1：
```txt

```
输出1：
```txt
apple
banana
coconut
date
elderberry
fig
grape
honeydew
kiwi
lemon
```

### Experiment10-3
题目：
```txt
设计一个类模板,其中包括数据成员T a[n]以及在其中进行査找数据元素的函数int search(T),模板参数T可实例化成字符串。
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
#include <string>
using namespace std;

template <class T>
class Base {
    private:
        T* a;
        int n;
    public:
        Base() {
            n = 0;
        }
        template <int m>
        Base(T (&a)[m]) {
            this->n = m;
            this->a = new T[m];
            for (int i = 0; i < n; i++) this->a[i] = a[i];
        }
        Base(Base &b) {
            n = b.n;
            for (int i = 0; i < n; i++) a[i] = b.a[i];
        }
        ~Base() {
            n = 0;
        }
        int search(T x) {
            for (int i = 0; i < n; i++) {
                if (a[i] == x) return i;
            }
            return -1;
        }
};


int main() {
    string s[10] = {
        "apple", "banana", "cherry", "date", "elderberry",
        "fig", "grape", "honeydew", "imbe", "jackfruit"
    };
    Base b(s);
    for (int i = 0; i < 10; i++) {
        cout << "idx of " << s[i] << " is " << b.search(s[i]) << endl;
    }
    return 0;
}
```
输入1：
```txt

```
输出1：
```txt
idx of apple is 0
idx of banana is 1
idx of cherry is 2
idx of date is 3
idx of elderberry is 4
idx of fig is 5
idx of grape is 6
idx of honeydew is 7
idx of imbe is 8
idx of jackfruit is 9
```

## 选做题
### Optional-Experiment10-1
题目：
```txt
请使用函数模板或类模版，实现快速排序算法，使其可以被用于不同数据类型的序列排序
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
```
输入1：
```txt

```
输出1：
```txt
60 34 35 75 0 95 98 17 95 40 
0 17 34 35 40 60 75 95 95 98 
```


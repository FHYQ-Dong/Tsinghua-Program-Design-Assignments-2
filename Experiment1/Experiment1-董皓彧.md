# Experiment1-董皓彧
环境：
```txt
g++.exe (x86_64-win32-seh-rev1, Built by MinGW-Builds project) 13.2.0
Visual Stdio Code 1.86.2
```
作业仓库地址：
[https://github.com/FHYQ-Dong/Tsinghua-Program-Design-Assignments-2/tree/main/Experiment1](https://github.com/FHYQ-Dong/Tsinghua-Program-Design-Assignments-2/tree/main/Experiment1)
## 必做题
### Experiment1-1
题目：
```txt
用 C++ 打印杨辉三角，直至第十行
```
输入格式：
```txt
略
```
输出格式：
```txt
杨辉三角
```
代码：
```c
#include <iostream>
using std::cout, std::endl;

int main() {
    // init
    int a[11][11] = {0};
    for (int i = 0; i < 11; ++i) {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    // calculate
    for (int i = 1; i < 11; ++i) {
        for (int j = 1; j < i; ++j) {
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }
    // print
    for (int i = 1; i < 11; ++i) {
        for (int j = 0; j <= i; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
```
输入1：
```txt

```
输出1：
```txt
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
1 6 15 20 15 6 1 
1 7 21 35 35 21 7 1 
1 8 28 56 70 56 28 8 1 
1 9 36 84 126 126 84 36 9 1 
1 10 45 120 210 252 210 120 45 10 1 
```

### Experiment1-2
题目：
```txt
用 C++ 编程实现如下三维动态数组 x：动态数组大小为 n×n×n，x[i][j][k] = i*j/(k+1)，输出该三维数组各个元素之和，取 n=5, 10, 15
```
输入格式：
```txt
一个数字 n，表示三维数组的大小
```
输出格式：
```txt
一行，一个数字，表示该三维数组各个元素之和
```
代码：
```c
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
    
```
输入1：
```txt
5
```
输出1：
```txt
210
```
输入2：
```txt
10
```
输出2：
```txt
5694
```
输入3：
```txt
15
```
输出3：
```txt
35611
```

## 选做题
### Optional-Experiment1-1
题目：
```txt
利用‘*’符号，使用格式控制符，在控制台组成一个“龙”字图样
```
输入格式：
```txt
略
```
输出格式：
```txt
“龙“字
```
代码：
```c
#include <iostream>
#include <iomanip>
#include <vector>
using std::cin, std::cout, std::endl, std::setw;

int main() {
    // pixel data
    std::vector<int> v[15] = {
        {6}, \
        {6, 3}, \
        {6, 4}, \
        {6}, \
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
        {6, 2}, \
        {6, 2, 4}, \
        {5, 3, 4}, \
        {5, 3, 3}, \
        {5, 3, 2}, \
        {4, 4, 1}, \
        {4, 4, 6}, \
        {3, 4, 1, 6}, \
        {2, 3, 1, 2, 6}, \
        {1, 8, 1, 1, 1, 1}
    };
    // print
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << setw(v[i][j]) << "*";
        }
        cout << endl;
    }
    return 0;
}

/*===================

     *
     *  *
     *   *
     *
**************
     * *
     * *   *
    *  *   *
    *  *  *
    *  * *
   *   **
   *   *     *
  *   **     *
 *  ** *     *
*       *****

===================*/
```
输入1：
```txt

```
输出1：
```txt
     *
     *  *
     *   *
     *
**************
     * *
     * *   *
    *  *   *
    *  *  *
    *  * *
   *   **
   *   *     *
  *   **     *
 *  ** *     *
*       *****
```


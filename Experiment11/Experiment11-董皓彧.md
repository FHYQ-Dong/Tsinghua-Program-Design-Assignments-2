# Experiment11-董皓彧
环境：
```txt
g++.exe (x86_64-win32-seh-rev1, Built by MinGW-Builds project) 13.2.0
Visual Stdio Code 1.89.0
```
作业仓库地址：
[https://github.com/FHYQ-Dong/Tsinghua-Program-Design-Assignments-2/tree/main/Experiment11](https://github.com/FHYQ-Dong/Tsinghua-Program-Design-Assignments-2/tree/main/Experiment11)
## 必做题
### Experiment11-1
题目：
```txt
使用STL中的vector，生成长度为120的整型动态数组，其各个元素取值随机。然后，依次将数组中第1，2，3，5…位置（斐波那契数）的元素删除。接着，使用内置的sort函数，对当前数组的前一半进行升序排序，后一半进行降序排序（若长度为奇数，正中间的元素归为前一半）。最后，将排序后结果输出到屏幕上。
```
输入格式：
```txt
无
```
输出格式：
```txt
一行，排序结果，用空格隔开
```
代码：
```cpp
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
```
输入1：
```txt

```
输出1：
```txt
421 648 1070 1138 1210 1298 1429 2459 3924 6793 6803 8124 8664 8799 8949 9010 10462 10563 11560 11915 12113 12151 12992 13051 13124 13742 13825 14025 14283 14329 16333 18153 18521 18849 19139 19242 22009 22465 23879 24104 24691 25509 26148 27005 27390 27636 27648 27668 28189 28392 29896 29957 31146 31781 32183 32425 31632 30129 28243 28122 26825 26116 25096 24547 23849 22731 22482 20810 20438 20331 19809 19748 19217 18579 18064 17480 17401 17341 16920 15651 15264 15161 14214 14209 13515 13311 13071 12735 12637 11905 11827 10911 10904 10424 10288 9848 9494 9436 8072 6740 6654 4880 4385 3369 2075 1643 1603 1582 1278 350 
```

### Experiment11-2
题目：
```txt
选择STL中某一容器来实现：容器A，B，C内分别含有12，6，18个随机生成的整型变量。首先求A和C容器的交集，得到容器D。然后，求B和D的并集E，并将新得到集合E中的元素按照从小到大的顺序输出。
```
输入格式：
```txt
无
```
输出格式：
```txt
一行，集合运算的结果，升序输出，用空格隔开
```
代码：
```cpp
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
```
输入1：
```txt

```
输出1：
```txt
6793 13742 20214 29896 29957 32183 
```

## 选做题
### Optional-Experiment11-1
题目：
```txt
对于vector类对象，当不断进行push_back使向量空间占满后，STL会如何进行内存管理？请将相应源码进行摘取和注释分析
```
答：vector对象在创建时会申请用户指定长度2倍的内存空间，其中多出的空间作为备用。当进行push_back时，会出现以下两种情况：

1. 还有可用空间：直接在后面插入；
2. 无可用空间：申请一个长度*2的新内存空间，将原有数据复制到新内存空间中，再在末尾插入。

代码：

```cpp
// 如果可用空间还有就调用对象的构造函数并使用空间的尾增加
// 没有空间就重新申请一个更大的空间, 然后进行插入
template <class T, class Alloc>
void vector<T, Alloc>::push_back(const T& x) 
{
      // 如果还没有到填满整个数组, 就在数据尾部插入
      if (finish != end_of_storage) 
      {
        	construct(finish, x);
        	++finish;
      }
    // 数组被填充满, 调用insert_aux必须重新寻找新的更大的连续空间, 再进行插入
      else
          insert_aux(end(), x);
}

// insert_aux实现
template <class T, class Alloc>
void vector<T, Alloc>::insert_aux(iterator position, const T& x) 
{
     // 如果数组还有备用空间, 就直接移动元素, 再将元素插入过去, 最后调整finish就行了.
  if (finish != end_of_storage) 
  {
      // 调用构造, 并将最后一个元素复制过去, 调整finish
    construct(finish, *(finish - 1));
    ++finish;
    T x_copy = x;
      // 将插入元素位置的后面所有元素往后移动, 最后元素插入到位置上.
    copy_backward(position, finish - 2, finish - 1);
    *position = x_copy;
  }
   // 没有备用空间, 重新申请空间再将元素拷贝过去同时执行插入操作
  else {
    const size_type old_size = size();
    const size_type len = old_size != 0 ? 2 * old_size : 1;	// 重新申请空间原始空间的两倍的空间

    iterator new_start = data_allocator::allocate(len);
    iterator new_finish = new_start;
    __STL_TRY {
        // 进行分段将原始元素拷贝新的空间中, 这样也就实现了插入操作
      new_finish = uninitialized_copy(start, position, new_start);
      construct(new_finish, x);
      ++new_finish;
      new_finish = uninitialized_copy(position, finish, new_finish);
    }

#       ifdef  __STL_USE_EXCEPTIONS 
    catch(...) {
      destroy(new_start, new_finish); 
      data_allocator::deallocate(new_start, len);
      throw;
    }
#       endif /* __STL_USE_EXCEPTIONS */
      // 释放掉原来的空间, 调整新的3个迭代器的位置
    destroy(begin(), end());
    deallocate();
    start = new_start;
    finish = new_finish;
    end_of_storage = new_start + len;
  }
}
```


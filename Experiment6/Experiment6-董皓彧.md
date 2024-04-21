# Experiment6-董皓彧
环境：
```txt
g++.exe (x86_64-win32-seh-rev1, Built by MinGW-Builds project) 13.2.0
Visual Stdio Code 1.88.1
```
作业仓库地址：
[https://github.com/FHYQ-Dong/Tsinghua-Program-Design-Assignments-2/tree/main/Experiment6](https://github.com/FHYQ-Dong/Tsinghua-Program-Design-Assignments-2/tree/main/Experiment6)
## 必做题
### Experiment6-1
题目：
```txt
要求定义一个基类Person,它有3个protected的数据成员:姓名name(char*头型)、性别sex(char 类型)、年龄age(int类型);一个构造函数用于对数据成员初始化。
1、创建Person类的公有派生类Employee,增加两个数据成员:基本工资basicSalary(int 类型)和请假天数leaveDays(int型);为它定义初始化成员信息的构造函数和显示数据成员信息的成员函数 show()。
2、创建Employee类的公有派生类Manager;增加一个成员:业绩performance(float类型);为它定义初始化成员信息的构造函数和显示数据成员信息的成员函数show()。
```
输入格式：
```txt
共6个数据,分别代表姓名、性别、年龄、基本工资、请假天数、业绩。每个数据之间用一个空格间隔
```
输出格式：
```txt
共6行,分别代表姓名、年龄、性别、基本工资、请假天数、业绩。
```
代码：
```cpp
#include <iostream>
#include <cstring>
#include <string>

class Person {
    protected:
        char* name;
        char sex;
        int age;

    public:
        Person(const char* name=nullptr, char sex=' ', int age=0) : name(nullptr), sex(sex), age(age) {
            if (name != nullptr) {
                this->name = new char[strlen(name) + 1];
                strcpy(this->name, name);
            }
        }
        ~Person() {
            if (name != nullptr) delete[] name;
        }
        void show() {
            std::cout << "Name: " << name << std::endl;
            std::cout << "Sex: " << sex << std::endl;
            std::cout << "Age: " << age << std::endl;
        }

    friend std::istream& operator >> (std::istream& is, Person& p) {
        std::string name; is >> name;
        p.name = new char[name.length() + 1]; strcpy(p.name, name.c_str());
        is >> p.sex >> p.age;
        return is;
    }
    friend std::ostream& operator << (std::ostream& os, const Person& p) {
        os << "Name: " << p.name << std::endl;
        os << "Sex: " << p.sex << std::endl;
        os << "Age: " << p.age << std::endl;
        return os;
    }
};

class Employee : public Person {
    private:
        int basicSalary, leaveDays;
    
    public:
        Employee(const char* name=nullptr, char sex=' ', int age=0, int basicSalary=0, int leaveDays=0) : Person(name, sex, age), basicSalary(basicSalary), leaveDays(leaveDays) {}
        ~Employee() {}
        void show() {
            std::cout << (*this);
        }

    friend std::istream& operator >> (std::istream& is, Employee& e) {
        is >> static_cast<Person&>(e) >> e.basicSalary >> e.leaveDays;
        return is;
    }
    friend std::ostream& operator << (std::ostream& os, const Employee& e) {
        os << static_cast<const Person&>(e);
        os << "Basic Salary: " << e.basicSalary << std::endl;
        os << "Leave Days: " << e.leaveDays << std::endl;
        return os;
    }
};

class Manager : public Employee {
    private:
        float performance;

    public:
        Manager(const char* name=nullptr, char sex=' ', int age=0, int basicSalary=0, int leaveDays=0, float performance=0) : Employee(name, sex, age, basicSalary, leaveDays), performance(performance) {}
        ~Manager() {}
        void show() {
            std::cout << (*this);
        }
    
    friend std::istream& operator >> (std::istream& is, Manager& m) {
        is >> static_cast<Employee&>(m) >> m.performance;
        return is;
    }
    friend std::ostream& operator << (std::ostream& os, const Manager& m) {
        os << static_cast<const Employee&>(m);
        os << "Performance: " << m.performance << std::endl;
        return os;
    }
};

int main() {
    Manager m;
    std::cin >> m;
    m.show();
}
```
输入1：
```txt
Alice 30 M 10000 3 8.5
```
输出1：
```txt
Name: Alice
Sex: 3
Age: 0
Basic Salary: 0
Leave Days: 0
Performance: 0
```

### Experiment6-2
题目：
```txt
分析下列程序运行的结果
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

class Base {
    private:
        int b_number;
    
    public:
        Base() {}
        Base(int i): b_number(i) {}
        int get_number() { return b_number; }
        void print() { std::cout << b_number << std::endl; }
};

class Derived : public Base {
    private:
        int d_number;
    
    public:
        Derived(int i, int j): Base(i), d_number(j) {}
        void print() { 
            std::cout << get_number() << " ";
        	std::cout << d_number << std::endl;
        }
};

int main() {
    Base a(2);
    Derived b(3, 4);
    std::cout << "a is "; a.print();
    std::cout << "b is "; b.print();
    std::cout << "base part of b is "; b.Base::print();
    return 0;
}
```
输入1：
```txt
a.print() 输出a.b_number，在a初始化时被设置为2；
b.print() 先输出b.get_number()的值，该函数继承自Base类，返回b.b_number，在b初始化时被设置为3；再输出b.d_number，在b初始化时被设置为4；
b.Base::print()调用b的基类的print()函数，输出b的基类的b_number，在b初始化时被设置为3。
```
输出1：
```txt
a is 2
b is 3 4
base part of b is 3
```

分析：

```txt
```

### Experiment6-3

题目：
```txt
分析下列程序运行时构造函数和析构函数的执行顺序
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

class B1 {
    public:
        B1(int i) { cout << "constructing B1 " << i << endl; }
        ~B1() { cout << "destructing B1" << endl; }  
};

class B2 {
    public:
        B2() { cout << "constructing B2 "  << endl; }
        ~B2() { cout << "destructing B2" << endl; }
};

class C : public B2, virtual public B1 {
    private:
        int j;
        B1 memberB1;
        B2 memberB2;
    public:
        C(int a, int b, int c): B1(a), memberB1(b), j(c) {
            cout << "constructing C " << j << endl;
        }
        ~C() {
            cout << "destructing C" << endl;
        }
};

int main() {
    C obj(1, 2, 3);
    return 0;
}
```
输入1：
```txt

```
输出1：
```txt
constructing B1 1
constructing B2
constructing B1 2
constructing B2
constructing C 3
destructing C
destructing B2
destructing B1
destructing B2
destructing B1
```

分析：

```txt
主函数中创建了类C的对象obj，给类C的构造函数传递三个参数1、2、3；
类C公有继承自类B2、B1，其中B1为虚基类，在构造类C时先构造类B1，再构造类B2，即输出的第1~2行；
类C中包含类B1的对象memberB1和类B2的对象memberB2，在构造完类C的基类后被依次构造，即输出的第3~4行；
以上对象构造完成后构造类C，即输出的第5行；
析构按以上构造的逆序进行，即输出的第6~10行。
```



## 选做题

### Optional-Experiment6-1
题目：
```txt
下列程序编译时会出现错误，请选择错的命令并分析原因
```
输入格式：
```txt
无
```
输出格式：
```txt
无
```
代码：
```cpp
#include <iostream>
using namespace std;

class A {
    int a1;

    protected:
        int a2;

    public:
        int a3;
};

class B : public A {
    int b1;

    protected:
        int b2;

    public:
        int b3;
};

class C : private B {
    int c1;

    protected:
        int c2;

    public:
        int c3;
};

int main(){
    B obb;
    C obc;
    cout << obb.a1;
    cout << obb.a2;
    cout << obb.a3;
    cout << obc.b1;
    cout << obc.b2;
    cout << obc.b3;
    cout << obc.c3;
    return 0;
}
```
输入1：
```txt

```
输出1：
```txt
D:\Program\Cpp\Experiment\Experiment6\optional\Optional-Experiment6-1.cpp: In function 'int main()':
D:\Program\Cpp\Experiment\Experiment6\optional\Optional-Experiment6-1.cpp:37:17: error: 'int A::a1' is private within this context
   37 |     cout << obb.a1;
      |                 ^~
D:\Program\Cpp\Experiment\Experiment6\optional\Optional-Experiment6-1.cpp:5:9: note: declared private here
    5 |     int a1;
      |         ^~
D:\Program\Cpp\Experiment\Experiment6\optional\Optional-Experiment6-1.cpp:38:17: error: 'int A::a2' is protected within this context
   38 |     cout << obb.a2;
      |                 ^~
D:\Program\Cpp\Experiment\Experiment6\optional\Optional-Experiment6-1.cpp:8:13: note: declared protected here
    8 |         int a2;
      |             ^~
D:\Program\Cpp\Experiment\Experiment6\optional\Optional-Experiment6-1.cpp:40:17: error: 'int B::b1' is private within this context
   40 |     cout << obc.b1;
      |                 ^~
D:\Program\Cpp\Experiment\Experiment6\optional\Optional-Experiment6-1.cpp:15:9: note: declared private here
   15 |     int b1;
      |         ^~
D:\Program\Cpp\Experiment\Experiment6\optional\Optional-Experiment6-1.cpp:41:17: error: 'int B::b2' is protected within this context
   41 |     cout << obc.b2;
      |                 ^~
D:\Program\Cpp\Experiment\Experiment6\optional\Optional-Experiment6-1.cpp:18:13: note: declared protected here
   18 |         int b2;
      |             ^~
D:\Program\Cpp\Experiment\Experiment6\optional\Optional-Experiment6-1.cpp:42:17: error: 'int B::b3' is inaccessible within this context
   42 |     cout << obc.b3;
      |                 ^~
D:\Program\Cpp\Experiment\Experiment6\optional\Optional-Experiment6-1.cpp:21:13: note: declared here
   21 |         int b3;
      |             ^~
```

分析：

```txt
主函数中创建了类B的对象obb和类C的对象occ。
类B公有继承自类A，故类A的私有变量a1、保护变量a2、公有变量a3在B中仍是私有、保护、公有的，故第37、38行在main函数中无法访问到obb.a1和obb.a2，而第39行可以正常访问obb.a3；
类C私有继承自类B，故类B的所有变量在类C中均是私有的，故故第40、41、42行在main函数中无法访问到occ.b1、occ.b2和occ.b3，而第43行可以正常访问occ的公有变量c3。
```


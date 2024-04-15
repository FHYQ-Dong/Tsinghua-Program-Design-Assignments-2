# Experiment5-董皓彧
环境：
```txt
g++.exe (x86_64-win32-seh-rev1, Built by MinGW-Builds project) 13.2.0
Visual Stdio Code 1.86.2
```
作业仓库地址：
[https://github.com/FHYQ-Dong/Tsinghua-Program-Design-Assignments-2/tree/main/Experiment5](https://github.com/FHYQ-Dong/Tsinghua-Program-Design-Assignments-2/tree/main/Experiment5)
## 必做题
### Experiment5-1
题目：
```txt
设计一个用于人事管理的People(人员)类,具有的属性如下:姓名char name[11]、编号char number[7]、性别char sex[3]、生日birthday、身份证号char id[16]。其中“出生日期”声明为一个“日期”类内嵌子对象。用成员函数实现对人员信息的录人和显示。要求包括构造函数和析构函数、拷贝构造函数、内联成员函数、运算符重载等。在测试程序中声明。
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
#include <iomanip>
#include <cstring>

class Date {   
    public:
        int year, month, day;
        Date(int y=1970, int m=1, int d=1) {
            year = y;
            month = m;
            day = d;
        };
        ~Date() {};
    friend std::ostream& operator << (std::ostream &os, const Date &d);
};

class Person {
    private:
        char name[11], number[8], sex[2], id[19];
        Date birthday;

    friend std::ostream& operator << (std::ostream &os, const Person &p);

    public:
        Person(const char name[], const char number[], const char sex[], const char id[], const Date &birthday) {
            strcpy(this->name, name); this->name[10] = '\0';
            strcpy(this->number, number); this->number[7] = '\0';
            strcpy(this->sex, sex); this->sex[1] = '\0';
            strcpy(this->id, id); this->id[18] = '\0';
            this->birthday = birthday;
        }
        Person(const Person &p) {
            strcpy(this->name, p.name);
            strcpy(this->number, p.number);
            strcpy(this->sex, p.sex);
            strcpy(this->id, p.id);
            this->birthday = p.birthday;
        }
        ~Person() {};
        Person& operator = (const Person &p) {
            if (this != &p) {
                strcpy(this->name, p.name);
                strcpy(this->number, p.number);
                strcpy(this->sex, p.sex);
                strcpy(this->id, p.id);
                this->birthday = p.birthday;
            }
            return *this;
        }
        bool operator == (const Person &p) {
            return strcmp(this->id, p.id) == 0;
        }
        void set(const char key[], const char value[]) {
            if (strcmp(key, "name") == 0) 
                strcpy(this->name, value), this->name[10] = '\0';
            else if (strcmp(key, "number") == 0) 
                strcpy(this->number, value), this->number[7] = '\0';
            else if (strcmp(key, "sex") == 0)
                strcpy(this->sex, value), sex[1] = '\0';
            else if (strcmp(key, "id") == 0)
                strcpy(this->id, value), id[18] = '\0';
            else 
                return;
            return;
        }
        void set(const char key[], const Date &value) {
            if (strcmp(key, "birthday") == 0) 
                this->birthday = value;
            else 
                return;
            return;
        }
        void get(const char key[], char result[]) {
            if (strcmp(key, "name") == 0) 
                strcpy(result, this->name);
            else if (strcmp(key, "number") == 0) 
                strcpy(result, this->number);
            else if (strcmp(key, sex) == 0)
                strcpy(result, this->sex);
            else if (strcmp(key, "id") == 0)
                strcpy(result, this->id);
            else 
                return;
            return;
        }
        void get(const char key[], Date &result) {
            if (strcmp(key, "birthday") == 0) 
                result = this->birthday;
            else 
                return;
            return;
        }
};

std::ostream& operator << (std::ostream &os, const Date &d) {
    os << d.year << "-" << d.month << "-" << d.day;
    return os;
}
std::ostream& operator << (std::ostream &os, const Person &p) {
    os << "Name: " << p.name << std::endl;
    os << "Number: " << p.number << std::endl;
    os << "Sex: " << p.sex << std::endl;
    os << "ID: " << p.id << std::endl;
    os << "Birthday: " << p.birthday << std::endl;
    return os;
}

int main() {
    Date birthday(2000, 1, 1);
    Person p("John", "1234567", "M", "123456789012345678", birthday);
    std::cout << p;
    std::cout << "----------------------" << std::endl;
    p.set("name", "Jane");
    p.set("number", "7654321");
    p.set("sex", "F");
    p.set("id", "876543210987654321");
    p.set("birthday", Date(2001, 2, 2));
    std::cout << p;
    return 0;
}
```
输入1：
```txt

```
输出1：
```txt
Name: John
Number: 1234567
Sex: M
ID: 123456789012345678
Birthday: 2000-1-1
----------------------
Name: Jane
Number: 7654321
Sex: F
ID: 876543210987654321
Birthday: 2001-2-2
```

### Experiment5-2
题目：
```txt
定义一个Teacher 类和一个Student类,两者有一部分的数据成员是相同的,例如:num，name和sex。编写一个程序,将一个Teacher 类对象转为 Student类对象,只需将以上3个相同的数据成员移植过去。
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
#include <cstring>

class Person;
class Teacher;
class Student;

class Person {
    protected:
        char name[11], num[8], sex[2];
    public:
        Person(const char name[11], const char num[8], const char sex[2]) {
            strncpy(this->name, name, 10), this->name[10] = '\0';
            strncpy(this->num, num, 7), this->num[7] = '\0';
            strncpy(this->sex, sex, 1), this->sex[1] = '\0';
        }
        Person(const Person &p) {
            strcpy(this->name, p.name);
            strcpy(this->num, p.num);
            strcpy(this->sex, p.sex);
        }
        void set(const char key[], const char value[]) {
            if (strcmp(key, "name") == 0) 
                strncpy(name, value, 10), name[10] = '\0';
            else if (strcmp(key, "num") == 0) 
                strncpy(this->num, num, 7), this->num[7] = '\0';
            else if (strcmp(key, "sex") == 0)
                strncpy(this->sex, sex, 1), this->sex[1] = '\0';
        }
        Person& operator = (const Person &p) {
            if (this != &p) {
                strcpy(name, p.name);
                strcpy(num, p.num);
                strcpy(sex, p.sex);
            }
            return *this;
        }
};

class Teacher: public Person {
    private:
        char title[11];
    public:
        Teacher(const char name[11], const char num[8], const char sex[2], const char title[11]): Person(name, num, sex) {
            strncpy(this->title, title, 10), this->title[10] = '\0';
        }
        Teacher(const Teacher &t): Person(t) {
            strcpy(this->title, t.title);
        }
        void set(const char key[], const char value[]) {
            if (strcmp(key, "title") == 0) 
                strncpy(title, value, 10), title[10] = '\0';
            else 
                Person::set(key, value);
        }
        Teacher& operator = (const Teacher &t) {
            if (this != &t) {
                Person::operator = (t);
                strcpy(title, t.title);
            }
            return *this;
        }
        Student Teacher2Student();

    friend std::ostream& operator << (std::ostream &os, const Teacher &t) {
        os << "Name: " << t.name << std::endl;
        os << "Number: " << t.num << std::endl;
        os << "Sex: " << t.sex << std::endl;
        os << "Title: " << t.title << std::endl;
        return os;
    }
};

class Student: public Person {
    private:
        char major[11];
    public:
        Student(const char name[11], const char num[8], const char sex[2], const char major[11]): Person(name, num, sex) {
            strncpy(this->major, major, 10), this->major[10] = '\0';
        }
        Student(const Student &s): Person(s) {
            strcpy(this->major, s.major);
        }
        void set(const char key[], const char value[]) {
            if (strcmp(key, "major") == 0) 
                strncpy(major, value, 10), major[10] = '\0';
            else 
                Person::set(key, value);
        }
        Student& operator = (const Student &s) {
            if (this != &s) {
                Person::operator = (s);
                strcpy(major, s.major);
            }
            return *this;
        }
        Teacher Student2Teacher();

    friend std::ostream& operator << (std::ostream &os, const Student &s) {
        os << "Name: " << s.name << std::endl;
        os << "Number: " << s.num << std::endl;
        os << "Sex: " << s.sex << std::endl;
        os << "Major: " << s.major << std::endl;
        return os;
    }
};

Student Teacher::Teacher2Student() {
    return Student(name, num, sex, "");
}
Teacher Student::Student2Teacher() {
    return Teacher(name, num, sex, "");
}

int main() {
    Teacher t("Teacher", "1234567", "M", "Professor");
    Student s("Student", "7654321", "F", "Computer Science");
    std::cout << t << std::endl;
    std::cout << s << std::endl;
    std::cout << "-----------------\n" << std::endl;

    Teacher t2 = s.Student2Teacher();
    Student s2 = t.Teacher2Student();
    std::cout << t2 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << "-----------------\n" << std::endl;

    t2.set("title", "Assistant Professor");
    s2.set("major", "Mathematics");
    std::cout << t2 << std::endl;
    std::cout << s2 << std::endl;
    
    return 0;
}
```
输入1：
```txt

```
输出1：
```txt
Name: Teacher
Number: 1234567
Sex: M
Title: Professor

Name: Student
Number: 7654321
Sex: F
Major: Computer S

-----------------

Name: Student
Number: 7654321
Sex: F
Title: 

Name: Teacher
Number: 1234567
Sex: M
Major: 

-----------------

Name: Student
Number: 7654321
Sex: F
Title: Assistant 

Name: Teacher
Number: 1234567
Sex: M
Major: Mathematic

```

## 选做题
### Optional-Experiment5-1
题目：
```txt
定义一个字符串类String，其唯一数据是一个字符串
•重载“+”，使其能够完成两端对象的字符串的拼接，并返回一个新的string对象
•重载“<<”，输出字符串的值
•重载“*”,对于一个String对象a, a*3表示将a中的字符串复制三遍并顺序拼接起来，只对对象a自身进行操作，不要求返回值。
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
#include <cstring>

class String;

class String {
    private:
        char *str;
    public:
        String(const char *s) {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
        String(const String &s) {
            str = new char[strlen(s.str) + 1];
            strcpy(str, s.str);
        }
        ~String() {
            delete[] str;
        }
        void set(const char *s) {
            delete[] str;
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
        String& operator = (const String &s) {
            if (this != &s) {
                delete[] str;
                str = new char[strlen(s.str) + 1];
                strcpy(str, s.str);
            }
            return *this;
        }
        String operator + (const String &s) {
            char *temp = new char[strlen(str) + strlen(s.str) + 1];
            strcpy(temp, str);
            strcat(temp, s.str);
            String result(temp);
            delete[] temp;
            return result;
        }
        void operator += (const String &s) {
            char *temp = new char[strlen(str) + strlen(s.str) + 1];
            strcpy(temp, str);
            strcat(temp, s.str);
            delete[] str;
            str = temp;
        }
        void operator * (int n) {
            char *temp = new char[strlen(str) * n + 1];
            strcpy(temp, str);
            for (int i = 1; i < n; i++) {
                strcat(temp, str);
            }
            delete[] str;
            str = temp;
        }

    friend std::ostream& operator << (std::ostream &os, const String &s) {
        os << s.str;
        return os;
    }
};

int main() {
    String s1("Hello"), s2("World");
    std::cout << s1 + s2 << std::endl;
    s1 += s2;
    std::cout << s1 << std::endl;
    s1 * 3;
    std::cout << s1 << std::endl;
    return 0;
}
```
输入1：
```txt

```
输出1：
```txt
HelloWorld
HelloWorld
HelloWorldHelloWorldHelloWorld
```


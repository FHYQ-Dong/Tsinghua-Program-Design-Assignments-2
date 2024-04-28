# Experiment7-董皓彧
环境：
```txt
g++.exe (x86_64-win32-seh-rev1, Built by MinGW-Builds project) 13.2.0
Visual Stdio Code 1.88.1
```
作业仓库地址：
[https://github.com/FHYQ-Dong/Tsinghua-Program-Design-Assignments-2/tree/main/Experiment7](https://github.com/FHYQ-Dong/Tsinghua-Program-Design-Assignments-2/tree/main/Experiment7)
## 必做题
### Experiment7-1
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

### Experiment7-2
题目：
```txt
在上一题的基础上,从People(人员)类派生出student(学生)类,添加属性:班号charclassNo[7];从 People(人员)类派生出 teacher(教师)类,添加属性:职务 char principalship[11]部门 char department[21];从 student类中派生出 graduate(研究生)类、添加属性:专业 charsubject[21]、导师 teacher advisor;从teacher 类和 graduate类派生出 TA(助教)类,注意虚基类的使用。要求编制一能管理上述四类人员的测试程序,能实现数据项录入、显示、删除操作。
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
#include <set>

class Date {
    public:
        int year, month, day;
        Date(int y=1970, int m=1, int d=1) {
            year = y;
            month = m;
            day = d;
        };
        ~Date() {};

    friend std::ostream& operator << (std::ostream &os, const Date &d) {
        os << d.year << "-" << d.month << "-" << d.day;
        return os;
    }
};

class Person {
    public:
        char name[11], number[8], sex[2], id[19];
        Date birthday;

    friend std::ostream& operator << (std::ostream &os, const Person &p) {
        os << "Name: " << p.name << std::endl;
        os << "Number: " << p.number << std::endl;
        os << "Sex: " << p.sex << std::endl;
        os << "ID: " << p.id << std::endl;
        os << "Birthday: " << p.birthday << std::endl;
        return os;
    }

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
        virtual ~Person() {};
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
        friend bool operator == (const Person &p1, const Person &p2) {
            return strcmp(p1.id, p2.id) == 0;
        }
        friend bool operator < (const Person &p1, const Person &p2) {
            return strcmp(p1.id, p2.id) < 0;
        }
        friend bool operator > (const Person &p1, const Person &p2) {
            return strcmp(p1.id, p2.id) > 0;
        }
};

class Student : virtual public Person {
    public:
        char classNo[7];
        Student(const char name[], const char number[], const char sex[], const char id[], const Date &birthday, const char classNo[]) : \
        Person(name, number, sex, id, birthday) {
            strcpy(this->classNo, classNo); this->classNo[6] = '\0';
        }
        Student(const Student &s) : Person(s) {
            strcpy(this->classNo, s.classNo);
        }
        virtual ~Student() {};
        Student& operator = (const Student &s) {
            if (this != &s) {
                static_cast<Person&>(*this) = s;
                strcpy(this->classNo, s.classNo);
            }
            return *this;
        }
        friend bool operator == (const Student &s1, const Student &s2) {
            return strcmp(s1.id, s2.id) == 0;
        }
        friend bool operator < (const Student &s1, const Student &s2) {
            return strcmp(s1.id, s2.id) < 0;
        }
        friend bool operator > (const Student &s1, const Student &s2) {
            return strcmp(s1.id, s2.id) > 0;
        }
};

class Teacher : virtual public Person {
    public:
        char principalship[11], department[21];
        Teacher(const char name[], const char number[], const char sex[], const char id[], const Date &birthday, const char principalship[], const char department[]) : \
        Person(name, number, sex, id, birthday) {
            strcpy(this->principalship, principalship); this->principalship[10] = '\0';
            strcpy(this->department, department); this->department[20] = '\0';
        }
        Teacher(const Teacher &t) : Person(t) {
            strcpy(this->principalship, t.principalship);
            strcpy(this->department, t.department);
        }
        virtual ~Teacher() {};
        Teacher& operator = (const Teacher &t) {
            if (this != &t) {
                static_cast<Person&>(*this) = t;
                strcpy(this->principalship, t.principalship);
                strcpy(this->department, t.department);
            }
            return *this;
        }
        friend bool operator == (const Teacher &t1, const Teacher &t2) {
            return strcmp(t1.id, t2.id) == 0;
        }
        friend bool operator < (const Teacher &t1, const Teacher &t2) {
            return strcmp(t1.id, t2.id) < 0;
        }
        friend bool operator > (const Teacher &t1, const Teacher &t2) {
            return strcmp(t1.id, t2.id) > 0;
        }
};

class Graduate : virtual public Student {
    public:
        char subject[21];
        Teacher advisor;
        Graduate(const char name[], const char number[], const char sex[], const char id[], const Date &birthday, const char subject[], const Teacher &advisor) : \
        Person(name, number, sex, id, birthday), \
        Student(name, number, sex, id, birthday, classNo), \
        advisor(advisor) {
            strcpy(this->subject, subject); this->subject[20] = '\0';
        }
        Graduate(const Graduate &g) : Person(g), Student(g), advisor(g.advisor) {
            strcpy(this->subject, g.subject);
        }
        virtual ~Graduate() {};
        Graduate& operator = (const Graduate &g) {
            if (this != &g) {
                static_cast<Person&>(*this) = g;
                strcpy(this->subject, g.subject);
                this->advisor = g.advisor;
            }
            return *this;
        }
        friend bool operator == (const Graduate &g1, const Graduate &g2) {
            return strcmp(g1.id, g2.id) == 0;
        }
        friend bool operator < (const Graduate &g1, const Graduate &g2) {
            return strcmp(g1.id, g2.id) < 0;
        }
        friend bool operator > (const Graduate &g1, const Graduate &g2) {
            return strcmp(g1.id, g2.id) > 0;
        }
};

class TA : virtual public Graduate, virtual public Teacher {
    public:
        char course[21];
        TA(const char name[], const char number[], const char sex[], const char id[], const Date &birthday, const char principalship[], const char department[], const char subject[], const Teacher &advisor) : \
            Person(name, number, sex, id, birthday), \
            Student(name, number, sex, id, birthday, classNo), \
            Teacher(name, number, sex, id, birthday, principalship, department), \
            Graduate(name, number, sex, id, birthday, subject, advisor) {
            strcpy(this->course, course); this->course[20] = '\0';
        }
        TA(const TA &ta) : Person(ta), Student(ta), Teacher(ta), Graduate(ta) {
            strcpy(this->course, ta.course);
        }
        virtual ~TA() {};
        TA& operator = (const TA &ta) {
            if (this != &ta) {
                static_cast<Graduate&>(*this) = ta;
                static_cast<Teacher&>(*this) = ta;
                strcpy(this->course, ta.course);
            }
            return *this;
        }
        friend bool operator == (const TA &ta1, const TA &ta2) {
            return strcmp(ta1.id, ta2.id) == 0;
        }
        friend bool operator < (const TA &ta1, const TA &ta2) {
            return strcmp(ta1.id, ta2.id) < 0;
        }
        friend bool operator > (const TA &ta1, const TA &ta2) {
            return strcmp(ta1.id, ta2.id) > 0;
        }
};

class ManageSystem {
    private:
        std::set<Student> students;
        std::set<Teacher> teachers;
        std::set<Graduate> graduates;
        std::set<TA> tas;
    public:
        ManageSystem() {};
        ~ManageSystem() {};
        void addStudent(const Student &s) {
            students.insert(s);
        }
        void addTeacher(const Teacher &t) {
            teachers.insert(t);
        }
        void addGraduate(const Graduate &g) {
            graduates.insert(g);
        }
        void addTA(const TA &ta) {
            tas.insert(ta);
        }
        void deleteStudent(const Student &s) {
            students.erase(s);
        }
        void deleteTeacher(const Teacher &t) {
            teachers.erase(t);
        }
        void deleteGraduate(const Graduate &g) {
            graduates.erase(g);
        }
        void deleteTA(const TA &ta) {
            tas.erase(ta);
        }
        void showStudents() {
            for (std::set<Student>::iterator it = students.begin(); it != students.end(); it++) {
                std::cout << *it << std::endl;
            }
        }
        void showTeachers() {
            for (std::set<Teacher>::iterator it = teachers.begin(); it != teachers.end(); it++) {
                std::cout << *it << std::endl;
            }
        }
        void showGraduates() {
            for (std::set<Graduate>::iterator it = graduates.begin(); it != graduates.end(); it++) {
                std::cout << *it << std::endl;
            }
        }
        void showTAs() {
            for (std::set<TA>::iterator it = tas.begin(); it != tas.end(); it++) {
                std::cout << *it << std::endl;
            }
        }
        void showall() {
            showStudents();
            showTeachers();
            showGraduates();
            showTAs();
        }
};

int main() {
    ManageSystem ms;
    Date d1(2000, 1, 1), d2(1990, 1, 1), d3(1980, 1, 1), d4(1970, 1, 1);
    Student s1("s1", "1234567", "M", "123456789012345678", d1, "class1");
    Teacher t1("t1", "7654321", "F", "876543210987654321", d2, "principalship1", "department1");
    Graduate g1("g1", "7654321", "F", "876543210987654321", d3, "subject1", t1);
    TA ta1("ta1", "7654321", "F", "876543210987654321", d4, "principalship1", "department1", "subject1", t1);
    ms.addStudent(s1);
    ms.addTeacher(t1);
    ms.addGraduate(g1);
    ms.addTA(ta1);
    ms.showall();
    std::cout << "============================" << std::endl;
    ms.deleteGraduate(g1);
    ms.showall();
    return 0;
}
```
输入1：
```txt

```
输出1：
```txt
Name: s1
Number: 1234567
Sex: M
ID: 123456789012345678
Birthday: 2000-1-1

Name: t1
Number: 7654321
Sex: F
ID: 876543210987654321
Birthday: 1990-1-1

Name: g1
Number: 7654321
Sex: F
ID: 876543210987654321
Birthday: 1980-1-1

Name: ta1
Number: 7654321
Sex: F
ID: 876543210987654321
Birthday: 1970-1-1

============================
Name: s1
Number: 1234567
Sex: M
ID: 123456789012345678
Birthday: 2000-1-1

Name: t1
Number: 7654321
Sex: F
ID: 876543210987654321
Birthday: 1990-1-1

Name: ta1
Number: 7654321
Sex: F
ID: 876543210987654321
Birthday: 1970-1-1

```

### Experiment7-3
题目：
```txt
在第6题的基础上,补充各类(People、student、graduate、teacher和TA)的构造函数和析构函数。
(1)编程测试和分析这些构造函数和析构函数的执行顺序。
(2)如果不采用虚基类,重新编程实现第5次作业要求,体会有什么差异?
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
#include <set>

class Date {
    public:
        int year, month, day;
        Date(int y=1970, int m=1, int d=1) {
            year = y;
            month = m;
            day = d;
        };
        ~Date() {};

    friend std::ostream& operator << (std::ostream &os, const Date &d) {
        os << d.year << "-" << d.month << "-" << d.day;
        return os;
    }
};

class Person {
    public:
        char name[11], number[8], sex[2], id[19];
        Date birthday;

    friend std::ostream& operator << (std::ostream &os, const Person &p) {
        os << "Name: " << p.name << std::endl;
        os << "Number: " << p.number << std::endl;
        os << "Sex: " << p.sex << std::endl;
        os << "ID: " << p.id << std::endl;
        os << "Birthday: " << p.birthday << std::endl;
        return os;
    }

    public:
        Person(const char name[], const char number[], const char sex[], const char id[], const Date &birthday) {
            strcpy(this->name, name); this->name[10] = '\0';
            strcpy(this->number, number); this->number[7] = '\0';
            strcpy(this->sex, sex); this->sex[1] = '\0';
            strcpy(this->id, id); this->id[18] = '\0';
            this->birthday = birthday;
            std::cout << "Person constructor called" << std::endl;
        }
        Person(const Person &p) {
            strcpy(this->name, p.name);
            strcpy(this->number, p.number);
            strcpy(this->sex, p.sex);
            strcpy(this->id, p.id);
            this->birthday = p.birthday;
            std::cout << "Person copy constructor called" << std::endl;
        }
        virtual ~Person() {
            std::cout << "Person destructor called" << std::endl;
        };
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
        friend bool operator == (const Person &p1, const Person &p2) {
            return strcmp(p1.id, p2.id) == 0;
        }
        friend bool operator < (const Person &p1, const Person &p2) {
            return strcmp(p1.id, p2.id) < 0;
        }
        friend bool operator > (const Person &p1, const Person &p2) {
            return strcmp(p1.id, p2.id) > 0;
        }
};

class Student : virtual public Person {
    public:
        char classNo[7];
        Student(const char name[], const char number[], const char sex[], const char id[], const Date &birthday, const char classNo[]) : \
        Person(name, number, sex, id, birthday) {
            strcpy(this->classNo, classNo); this->classNo[6] = '\0';
            std::cout << "Student constructor called" << std::endl;
        }
        Student(const Student &s) : Person(s) {
            strcpy(this->classNo, s.classNo);
            std::cout << "Student copy constructor called" << std::endl;
        }
        virtual ~Student() {
            std::cout << "Student destructor called" << std::endl;
        };
        Student& operator = (const Student &s) {
            if (this != &s) {
                static_cast<Person&>(*this) = s;
                strcpy(this->classNo, s.classNo);
            }
            return *this;
        }
        friend bool operator == (const Student &s1, const Student &s2) {
            return strcmp(s1.id, s2.id) == 0;
        }
        friend bool operator < (const Student &s1, const Student &s2) {
            return strcmp(s1.id, s2.id) < 0;
        }
        friend bool operator > (const Student &s1, const Student &s2) {
            return strcmp(s1.id, s2.id) > 0;
        }
};

class Teacher : virtual public Person {
    public:
        char principalship[11], department[21];
        Teacher(const char name[], const char number[], const char sex[], const char id[], const Date &birthday, const char principalship[], const char department[]) : \
        Person(name, number, sex, id, birthday) {
            strcpy(this->principalship, principalship); this->principalship[10] = '\0';
            strcpy(this->department, department); this->department[20] = '\0';
            std::cout << "Teacher constructor called" << std::endl;
        }
        Teacher(const Teacher &t) : Person(t) {
            strcpy(this->principalship, t.principalship);
            strcpy(this->department, t.department);
            std::cout << "Teacher copy constructor called" << std::endl; 
        }
        virtual ~Teacher() {
            std::cout << "Teacher destructor called" << std::endl;
        };
        Teacher& operator = (const Teacher &t) {
            if (this != &t) {
                static_cast<Person&>(*this) = t;
                strcpy(this->principalship, t.principalship);
                strcpy(this->department, t.department);
            }
            return *this;
        }
        friend bool operator == (const Teacher &t1, const Teacher &t2) {
            return strcmp(t1.id, t2.id) == 0;
        }
        friend bool operator < (const Teacher &t1, const Teacher &t2) {
            return strcmp(t1.id, t2.id) < 0;
        }
        friend bool operator > (const Teacher &t1, const Teacher &t2) {
            return strcmp(t1.id, t2.id) > 0;
        }
};

class Graduate : virtual public Student {
    public:
        char subject[21];
        Teacher advisor;
        Graduate(const char name[], const char number[], const char sex[], const char id[], const Date &birthday, const char subject[], const Teacher &advisor) : \
        Person(name, number, sex, id, birthday), \
        Student(name, number, sex, id, birthday, classNo), \
        advisor(advisor) {
            strcpy(this->subject, subject); this->subject[20] = '\0';
            std::cout << "Graduate constructor called" << std::endl;
        }
        Graduate(const Graduate &g) : Person(g), Student(g), advisor(g.advisor) {
            strcpy(this->subject, g.subject);
            std::cout << "Graduate copy constructor called" << std::endl;
        }
        virtual ~Graduate() {
            std::cout << "Graduate destructor called" << std::endl;
        };
        Graduate& operator = (const Graduate &g) {
            if (this != &g) {
                static_cast<Person&>(*this) = g;
                strcpy(this->subject, g.subject);
                this->advisor = g.advisor;
            }
            return *this;
        }
        friend bool operator == (const Graduate &g1, const Graduate &g2) {
            return strcmp(g1.id, g2.id) == 0;
        }
        friend bool operator < (const Graduate &g1, const Graduate &g2) {
            return strcmp(g1.id, g2.id) < 0;
        }
        friend bool operator > (const Graduate &g1, const Graduate &g2) {
            return strcmp(g1.id, g2.id) > 0;
        }
};

class TA : virtual public Graduate, virtual public Teacher {
    public:
        char course[21];
        TA(const char name[], const char number[], const char sex[], const char id[], const Date &birthday, const char principalship[], const char department[], const char subject[], const Teacher &advisor) : \
            Person(name, number, sex, id, birthday), \
            Student(name, number, sex, id, birthday, classNo), \
            Teacher(name, number, sex, id, birthday, principalship, department), \
            Graduate(name, number, sex, id, birthday, subject, advisor) {
            strcpy(this->course, course); this->course[20] = '\0';
            std::cout << "TA constructor called" << std::endl;
        }
        TA(const TA &ta) : Person(ta), Student(ta), Teacher(ta), Graduate(ta) {
            strcpy(this->course, ta.course);
            std::cout << "TA copy constructor called" << std::endl;
        }
        virtual ~TA() {
            std::cout << "TA destructor called" << std::endl;
        };
        TA& operator = (const TA &ta) {
            if (this != &ta) {
                static_cast<Graduate&>(*this) = ta;
                static_cast<Teacher&>(*this) = ta;
                strcpy(this->course, ta.course);
            }
            return *this;
        }
        friend bool operator == (const TA &ta1, const TA &ta2) {
            return strcmp(ta1.id, ta2.id) == 0;
        }
        friend bool operator < (const TA &ta1, const TA &ta2) {
            return strcmp(ta1.id, ta2.id) < 0;
        }
        friend bool operator > (const TA &ta1, const TA &ta2) {
            return strcmp(ta1.id, ta2.id) > 0;
        }
};

class ManageSystem {
    private:
        std::set<Student> students;
        std::set<Teacher> teachers;
        std::set<Graduate> graduates;
        std::set<TA> tas;
    public:
        ManageSystem() {};
        ~ManageSystem() {};
        void addStudent(const Student &s) {
            students.insert(s);
        }
        void addTeacher(const Teacher &t) {
            teachers.insert(t);
        }
        void addGraduate(const Graduate &g) {
            graduates.insert(g);
        }
        void addTA(const TA &ta) {
            tas.insert(ta);
        }
        void deleteStudent(const Student &s) {
            students.erase(s);
        }
        void deleteTeacher(const Teacher &t) {
            teachers.erase(t);
        }
        void deleteGraduate(const Graduate &g) {
            graduates.erase(g);
        }
        void deleteTA(const TA &ta) {
            tas.erase(ta);
        }
        void showStudents() {
            for (std::set<Student>::iterator it = students.begin(); it != students.end(); it++) {
                std::cout << *it << std::endl;
            }
        }
        void showTeachers() {
            for (std::set<Teacher>::iterator it = teachers.begin(); it != teachers.end(); it++) {
                std::cout << *it << std::endl;
            }
        }
        void showGraduates() {
            for (std::set<Graduate>::iterator it = graduates.begin(); it != graduates.end(); it++) {
                std::cout << *it << std::endl;
            }
        }
        void showTAs() {
            for (std::set<TA>::iterator it = tas.begin(); it != tas.end(); it++) {
                std::cout << *it << std::endl;
            }
        }
        void showall() {
            showStudents();
            showTeachers();
            showGraduates();
            showTAs();
        }
};

int main() {
    ManageSystem ms;
    Date d1(2000, 1, 1), d2(1990, 1, 1), d3(1980, 1, 1), d4(1970, 1, 1);
    Student s1("s1", "1234567", "M", "123456789012345678", d1, "class1");
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    Teacher t1("t1", "7654321", "F", "876543210987654321", d2, "principalship1", "department1");
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    Graduate g1("g1", "7654321", "F", "876543210987654321", d3, "subject1", t1);
    std::cout << ">>>>>>>>>>>>>>>>>>>>>>" << std::endl;
    TA ta1("ta1", "7654321", "F", "876543210987654321", d4, "principalship1", "department1", "subject1", t1);
    std::cout << "<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
    return 0;
}
```
输入1：
```txt

```
输出1：
```txt
Person constructor called
Student constructor called
>>>>>>>>>>>>>>>>>>>>>>
Person constructor called
Teacher constructor called
<<<<<<<<<<<<<<<<<<<<<<
Person constructor called
Student constructor called
Person copy constructor called
Teacher copy constructor called
Graduate constructor called
>>>>>>>>>>>>>>>>>>>>>>
Person constructor called
Student constructor called
Person copy constructor called
Teacher copy constructor called
Graduate constructor called
Teacher constructor called
TA constructor called
<<<<<<<<<<<<<<<<<<<<<<
TA destructor called
Teacher destructor called
Graduate destructor called
Teacher destructor called
Person destructor called
Student destructor called
Person destructor called
Graduate destructor called
Teacher destructor called
Person destructor called
Student destructor called
Person destructor called
Teacher destructor called
Person destructor called
Student destructor called
Person destructor called
```

## 选做题
### Optional-Experiment7-1
题目：
```txt
定义点类、线段类、矩形类的层次结构。每个矩形由4条线段组成，每条线段由2个点组成，要求每个点只构造1次
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

class Point {
    public:
        int x, y;
        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }
        Point() {
            x = 0;
            y = 0;
        }
        Point(const Point &p) {
            x = p.x;
            y = p.y;
        }
        virtual ~Point() {}

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }
};

class Line : virtual public Point {
    private:
        Point p2;

    public:
        Line(int x1, int y1, int x2, int y2) : Point(x1, y1), p2(x2, y2) {}
        Line() : Point(), p2() {}
        Line(const Point &p1, const Point &p2) : Point(p1), p2(p2) {}
        Line(const Line &l) : Point(l), p2(l.p2) {}
        virtual ~Line() {}

        Point getP1() {
            return Point(x, y);
        }
        Point getP2() {
            return p2;
        }
        void setP1(Point &p) {
            x = p.x;
            y = p.y;
        }
        void setP2(Point &p) {
            p2 = p;
        }

    friend std::ostream& operator<<(std::ostream& os, const Line& l) {
        os << Point(l) << " - " << l.p2;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Line& l) {
        is >> l >> l.p2;
        return is;
    }
};

class Rect : public Line {
    private:
        Line l2, l3, l4;

    public:
        Rect(int x1, int y1, int x2, int y2) : Line(x1, y1, x2, y1), l2(x2, y1, x2, y2), l3(x2, y2, x1, y2), l4(x1, y2, x1, y1) {}
        Rect() : Line(), l2(), l3(), l4() {}
        Rect(const Point &p1, const Point &p2) : Line(p1.x, p1.y, p2.x, p1.y), l2(p2.x, p1.y, p2.x, p2.y), l3(p2.x, p2.y, p1.x, p2.y), l4(p1.x, p2.y, p1.x, p1.y) {}
        Rect(const Rect &r) : Line(r), l2(r.l2), l3(r.l3), l4(r.l4) {}
        virtual ~Rect() {}

    friend std::ostream& operator<<(std::ostream& os, const Rect& r) {
        os << Line(r) << " - " << r.l3 << std::endl;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Rect& r) {
        is >> r >> r.l2 >> r.l3 >> r.l4;
        return is;
    }
};

int main() {
    Point p1(1, 1), p2(2, 2);
    Line l1(p1, p2);
    Rect r1(p1, p2);
    std::cout << "Point 1: " << p1 << std::endl;
    std::cout << "Point 2: " << p2 << std::endl;
    std::cout << "Line 1: " << l1 << std::endl;
    std::cout << "Rect 1: " << r1 << std::endl;
    return 0;
}
```
输入1：
```txt

```
输出1：
```txt
Point 1: (1, 1)
Point 2: (2, 2)
Line 1: (1, 1) - (2, 2)
Rect 1: (0, 0) - (2, 1) - (2, 2) - (1, 2)

```


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
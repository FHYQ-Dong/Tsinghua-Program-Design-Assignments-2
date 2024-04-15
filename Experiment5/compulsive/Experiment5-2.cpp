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
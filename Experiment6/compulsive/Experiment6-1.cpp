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
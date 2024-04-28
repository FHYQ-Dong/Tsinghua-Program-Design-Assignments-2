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
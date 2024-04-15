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
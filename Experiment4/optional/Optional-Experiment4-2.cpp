#include <iostream>
#include <ctime>

class Date {
    private:
        int year, month, day;
        bool is_leap;
        static constexpr int daysInMonth[][2] = {
            {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30},
            {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}
        };
        
        bool is_leap_year() const {
            return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
        }

        void normalize() {
            is_leap = is_leap_year();
            while (day > daysInMonth[month-1][is_leap]) {
                day -= daysInMonth[month-1][is_leap];
                month++;
                while (month > 12) {
                    month -= 12;
                    year++;
                    is_leap = is_leap_year();
                }
            }
            while (day < 1) {
                month--;
                while (month < 1) {
                    month += 12;
                    year--;
                    is_leap = is_leap_year();
                }
                day += daysInMonth[month-1][is_leap];
            }
        }

    public:
        Date(int year=1970, int month=1, int day=1) : year(year), month(month), day(day) {
            normalize();
        }
        Date(const Date& d) : year(d.year), month(d.month), day(d.day) {}
        Date(const time_t& t) {
            struct tm* timeinfo = localtime(&t);
            day = timeinfo->tm_mday;
            month = timeinfo->tm_mon + 1;
            year = timeinfo->tm_year + 1900;
            normalize();
        }
        ~Date() {}
        void print(const char* sep) const {
            std::cout << year << sep << month << sep << day << std::endl;
        }
        Date& operator = (const Date& d) {
            day = d.day;
            month = d.month;
            year = d.year;
            return *this;
        }
        Date operator + (const Date& d) const {
            Date result;
            result.day = day + d.day;
            result.month = month + d.month;
            result.year = year + d.year;
            result.normalize();
            return result;
        }
        Date operator - (const Date& d) const {
            Date result;
            result.day = day - d.day;
            result.month = month - d.month;
            result.year = year - d.year;
            result.normalize();
            return result;
        }
        bool operator == (const Date& d) const {
            return day == d.day && month == d.month && year == d.year;
        }
        bool operator != (const Date& d) const {
            return day != d.day || month != d.month || year != d.year;
        }
        bool operator < (const Date& d) const {
            if (year < d.year) return true;
            if (year > d.year) return false;
            if (month < d.month) return true;
            if (month > d.month) return false;
            return day < d.day;
        }
        bool operator > (const Date& d) const {
            if (year > d.year) return true;
            if (year < d.year) return false;
            if (month > d.month) return true;
            if (month < d.month) return false;
            return day > d.day;
        }
        bool operator <= (const Date& d) const {
            return *this < d || *this == d;
        }
        bool operator >= (const Date& d) const {
            return *this > d || *this == d;
        }
        Date& operator += (const Date& d) {
            day += d.day;
            month += d.month;
            year += d.year;
            normalize();
            return *this;
        }
        Date& operator -= (const Date& d) {
            day -= d.day;
            month -= d.month;
            year -= d.year;
            normalize();
            return *this;
        }
        Date& operator ++ () {
            day++;
            normalize();
            return *this;
        }
        Date operator ++ (int) {
            Date temp(*this);
            operator++();
            return temp;
        }
};

inline void test() {
    Date d1(2024, 2, 28);
    d1.print("/");
    d1++;
    d1.print("/");
    ++d1;
    d1.print("/");
}

int main() {
    test();
    return 0;
}
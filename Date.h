#ifndef DATE_H
#define DATE_H

#include <string>
#include <ctime>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() {
        time_t now = time(0);
        tm* ltm = localtime(&now);

        day = ltm->tm_mday;
        month = 1 + ltm->tm_mon;
        year = 1900 + ltm->tm_year;
    }

    Date(int day, int month, int year) : day(day), month(month), year(year) {}

    string toString() const {
        return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    }
};

#endif // DATE_H

#include <iostream>
using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) return 29;
    return days[month - 1];
}

int main() {
    int current_date[3], birth_date[3];

    cout << "Enter current date (YYYY MM DD): ";
    cin >> current_date[0] >> current_date[1] >> current_date[2];

    cout << "Enter birth date (YYYY MM DD): ";
    cin >> birth_date[0] >> birth_date[1] >> birth_date[2];

    int years = current_date[0] - birth_date[0];
    int months = current_date[1] - birth_date[1];
    int days = current_date[2] - birth_date[2];

    if (days < 0) {
        months--;
        days += daysInMonth(birth_date[1], birth_date[0]);
    }

    if (months < 0) {
        years--;
        months += 12;
    }

    cout << "Your Age is: " << years << " Years, " << months << " Months, " << days << " Days." << endl;
    return 0;
}

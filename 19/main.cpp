#include <iostream>
#include <vector>

using namespace std;


int count_sundays(int n)
{
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int sundays = 0;
    int extra_days = 0;
    int sundays_on_first_of_month = 0;
    int year = 1900;

    for (int i = 0; i < n; i++)
    {
        if ((year % 100) == 0)
        {
            if ((year % 400) == 0)
                month[1] = 29;
        }
        else if ((year % 4) == 0)
            month[1] = 29;
        else
            month[1] = 28;

        if (i % 12 == 0 && i != 0)
            year++;

        sundays += month[i % 12] / 7 + (month[i % 12] % 7 + extra_days) / 7;

        extra_days += month[i % 12] % 7;

        if (extra_days > 7)
            extra_days = extra_days % 7;

        if (extra_days == 6)
            sundays_on_first_of_month++;

        cout << "Year: " << year << ", month: " << i % 12 + 1 << ", sundays: " << sundays << ", extra_days: " << extra_days << endl;
    }
    return sundays_on_first_of_month;
}

int main()
{
    cout << "Answer: " << count_sundays(1212) - count_sundays(12) << endl;
    return 0;
}
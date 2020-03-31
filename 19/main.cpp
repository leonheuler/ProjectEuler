#include <iostream>
#include <vector>
#include <string>

using namespace std;

int months_to_sundays(int n)
{
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int sundays = 0;
    int extra_days = 0;

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

        sundays += month[i % 13] / 7 + (month[i % 13] % 7 + extra_days) / 7;
        extra_days += month[i % 13] % 7;

        if (extra_days > 7)
        {
            sundays += extra_days / 7;
            extra_days = extra_days % 7;
        }
        cout << "Year: " << year << ", month: " << i % 12 + 1 << ", sundays: " << sundays << ", extra_days: " << extra_days << endl;
    }
}

int main()
{

    months_to_sundays(5);

    return 0;
}
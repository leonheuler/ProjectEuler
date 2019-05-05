//eleven twelve thirteen

#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

int how_many_letters(string s)
{
    int ret = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]))
            ret++;
    }
    return ret;
}

int main()
{

    typedef map<int, string> num_t;

    num_t numbers = {
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
        {10, "ten"},
        {11, "eleven"},
        {12, "twelve"},
        {13, "thirteen"},
        {14, "fourteen"},
        {15, "fifteen"},
        {16, "sixteen"},
        {17, "seventeen"},
        {18, "eighteen"},
        {19, "nineteen"},
        {20, "twenty"},
        {30, "thirty"},
        {40, "forty"},
        {50, "fifty"},
        {60, "sixty"},
        {70, "seventy"},
        {80, "eighty"},
        {90, "ninety"},
        {100, "hundred"},
        {1000, "one thousand"}};

    for (int i = 21; i < 100; i++)
    {
        if (i % 10 != 0)
        {
            numbers[i] = numbers[ i - i % 10 ] + "-" + numbers[ i % 10 ];
        }
    }

    for (int i = 100; i < 1000; i++)
    {
        if (i % 100 != 0)
            numbers[i] = numbers[i / 100] + " hundred" + " and " + numbers[i % 100];
        else 
            numbers[i] = numbers[i / 100] + " hundred";
    }


    int ans = 0;
    for (num_t::const_iterator it = numbers.begin();
         it != numbers.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
        ans += how_many_letters(it->second);
    }
    cout << ans << endl;
    system("pause");

    return 0;
}
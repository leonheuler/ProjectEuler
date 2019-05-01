//eleven twelve thirteen

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{

    typedef map<int, vector<string>> num_t;

    num_t numbers = {
        {1, {"one"}},
        {2, {"two"}},
        {3, {"three"}},
        {4, {"four"}},
        {5, {"five"}},
        {6, {"six"}},
        {7, {"seven"}},
        {8, {"eight"}},
        {9, {"nine"}},
        {10, {"ten"}},
        {11, {"eleven"}},
        {12, {"twelve"}},   
        {13, {"thirteen"}},
        {14, {"fourteen"}},
        {15, {"fifteen"}},
        {16, {"sixteen"}},
        {17, {"seventeen"}},
        {18, {"eighteen"}},
        {19, {"nineteen"}},
        {20, {"twenty"}},
        {30, {"thirty"}},
        {40, {"forty"}},
        {50, {"fifty"}},
        {60, {"sixty"}},
        {70, {"seventy"}},
        {80, {"eighty"}},
        {90, {"ninety"}},
        {100, {"one", "hundred"}},
        {1000, {"one", "thousand"}}
    };


    for (int i = 21; i < 100; i++)
    {
    }


    for (num_t::const_iterator it = numbers.begin();
         it != numbers.end(); ++it)
    {
        cout << it->first << " ";
        copy(it->second.begin(), it->second.end(), ostream_iterator<string>(cout, " "));
        cout << endl;
    }

    system("pause");

    return 0;
}
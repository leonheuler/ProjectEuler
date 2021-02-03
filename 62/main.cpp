#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

typedef unsigned long long num_t;

int main()
{
    map<string, int> cubic_permutations;

    string result_digits; // найти цифры из которых состоит искомое число
    for (num_t n = 1;; ++n)
    {
        num_t cube = n * n * n;
        string digits = to_string(cube);
        sort(digits.begin(), digits.end());
        if (++cubic_permutations[digits] == 5)
        {
            result_digits = digits;
            break;
        }
    }

    // найти первое число состоящее из этих цифр 
    for (num_t n = 1;; ++n)
    {
        num_t cube = n * n * n;
        string digits = to_string(cube);
        sort(digits.begin(), digits.end());
        if (result_digits == digits)
        {
            cout << cube << endl;
            break;
        }
    }

    cin.get();
    return 0;
}
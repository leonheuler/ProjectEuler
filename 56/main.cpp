#include <iostream>
#include <gmpxx.h>
#include <numeric>

typedef uint64_t num_t;

using namespace std;

int main()
{
    num_t result = 0;
    for (int a = 2; a < 100; a++)
    {
        for (int b = 2; b < 100; b++)
        {
            mpz_class num;
            mpz_ui_pow_ui(num.get_mpz_t(), a, b);
            string str = num.get_str();
            num_t digit_sum = accumulate(str.begin(), str.end(), (num_t)0) - 48*str.size(); 
            result = max(result, digit_sum);
        }
    }

    cout << result << endl;
    cin.get();

    return 0;
}
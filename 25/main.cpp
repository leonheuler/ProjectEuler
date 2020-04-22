#include <gmpxx.h>
#include <iostream> 

using namespace std;

int digits(const mpz_class&);

int main()
{
    mpz_class a = 1, b = 1, c;
    int index = 2;        
    while (c.get_str().size() != 1000)
    {
        c = a + b;
        index += 1;
        a = b;
        b = c;
    }
    cout << index;
    return 0;
}


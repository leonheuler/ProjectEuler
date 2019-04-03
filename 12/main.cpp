#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>

using namespace std;

unsigned long create_triangle_number(unsigned long n)
{
    return n * (n + 1) / 2;
}

int get_number_of_dividers(ostream& os, unsigned long a)
{
    map<int, int> prime_factorization;

    unsigned long n = 2;
    while (n <= a)
    {
        if (a % n == 0)
        {
            ++prime_factorization[n];
            a /= n;
            n = 2;
            continue;
        }
        n++;
    }

    int ret = 1;
    for (map<int, int>::const_iterator it = prime_factorization.begin(); it != prime_factorization.end(); ++it)
    {   
        os << it->first << "^" << it->second << " ";
        ret *= it->second + 1;
    }
    os << ret;
    return ret;
}

int main()
{
    ofstream fileo("result.txt");

    // a_n - n-th triangle number
    unsigned long n = 1;
    while (true)
    {
        unsigned long a_i = create_triangle_number(n++);
        fileo << a_i << " ";
        int ans = get_number_of_dividers(fileo, a_i);
        fileo << endl;

        if (ans > 500) 
            break;
    }

    fileo.close();
    return 0;
}
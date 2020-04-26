#include <vector>
#include <math.h>
#include <iostream>
#include <fstream>

std::ofstream fileo("output.txt");

typedef int num_t;
typedef std::vector<num_t> vec_t;

bool is_prime(const int &);
vec_t ints(const double &, const double &);
vec_t ints();

struct rec_t
{
    int a;
    int b;
    int len;
};

int main()
{
    /** test 
     * 
    std::cout << "is_prime() test:" << std:: endl;
    std::cout << is_prime(1) << " " << is_prime(2) << " " << is_prime(7) << std::endl;
    vec_t tv1 = ints(-sqrt(1),sqrt(1)); // -1, 1
    std::cout << "ints() test:" << std:: endl;
    for (vec_t::const_iterator it = tv1.begin(); it != tv1.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;    
    vec_t tv2 = ints(-sqrt(2),sqrt(2)); // -1.4, 1.4
    for (vec_t::const_iterator it = tv2.begin(); it != tv2.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;    
    vec_t tv3 = ints(-sqrt(7),sqrt(7)); // -2.64, 2.64
    for (vec_t::const_iterator it = tv3.begin(); it != tv3.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;    
    return 0; 
    */

    unsigned int b = 0;
    std::vector<rec_t> ret;
    do
    {
        ++b;
        rec_t rec;
        if (is_prime(b))
        {
            vec_t va = ints(/*-sqrt(2 * b), sqrt(2 * b)*/);
            size_t i = 0;
            int len = 0, n = 0;
            while (i != va.size())
            {
                while (is_prime(n * n + va[i] * n + b))
                {
                    ++len;
                    ++n;
                }
                if (len != 1)
                {
                    rec.a = va[i];
                    rec.b = b;
                    rec.len = len;
                    ret.push_back(rec);
                }
                ++i;
                len = 0;
                n = 0;
            }
        }
    } while (b <= 1000);

    for (std::vector<rec_t>::const_iterator it = ret.begin(); it != ret.end(); ++it)
        fileo << "a = " << it->a << " b = " << it->b << " len = " << it->len << std::endl;

    return 0;
}

bool is_prime(const int &n)
{
    int d = 2;
    do
    {
        if (n % d == 0 || n <= 0)
            return false;
    } while (++d < n);
    return true;
}

vec_t ints(const double &a, const double &b)
{
    vec_t ret;
    int c = a;
    ret.push_back(c);
    while (++c <= b)
        ret.push_back(c);
    return ret;
}

vec_t ints()
{
    vec_t ret;
    for (int i = -999; i < 1000; ++i)
        ret.push_back(i);
    return ret;
}
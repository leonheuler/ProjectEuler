/**
 * In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:
 * 
 * 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
 * It is possible to make £2 in the following way:
 * 
 * 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
 * How many different ways can £2 be made using any number of coins? */

#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <fstream>

std::ofstream fileo("output.txt");

#define OSTREAM fileo
// #define OSTREAM std::cout

typedef unsigned long num_t;
typedef std::vector<num_t> vec_t;
typedef std::vector<vec_t> vvec_t;

void print(const vvec_t &);
void print_vec(const vec_t &);
num_t sum(const vec_t &);
bool transform(vec_t &);

#define N 20

int main()
{

    vec_t w(N, 1);
    num_t rem = 1;

    vvec_t ans = {w};
    print_vec(w);

    while (w[0] == 1)
    {
        num_t new_rem;
        do
        {
            w.pop_back();
            new_rem = N - sum(w);

        } while (new_rem <= rem);

        rem = new_rem;

        vec_t tail;
        // gen tale
        if (rem % 2 == 0)
        {
            vec_t t(rem / 2, 2);
            tail = t;
        }
        else if (rem >= 5)
        {
            vec_t t((rem - 5) / 2, 2);
            t.push_back(5);
            std::copy(t.rbegin(), t.rend(), std::back_inserter(tail));
        }
        else // rem == 3
            continue;

        if (tail.size() > 0)
        {
            do
            {
                std::copy(tail.begin(), tail.end(), std::back_inserter(w));
                ans.push_back(w);
            } while (transform(tail));

            print_vec(w);
        }
    }

    return 0;
}

num_t sum(const vec_t &v)
{
    return std::accumulate(v.begin(), v.end(), (num_t)0);
}

bool transform(vec_t &v, const num_t &r)
{

    return false;
}

void print_vec(const vec_t &v)
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<num_t>(OSTREAM, " "));
    OSTREAM << std::endl;
}

void print(const vvec_t &vv)
{
    std::for_each(vv.begin(), vv.end(), print_vec);
}

bool is_odd_and_greater_3(const num_t &n)
{
    return n > 3 && n % 2 != 0;
}

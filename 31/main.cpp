/**
 * In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:
 * 
 * 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
 * It is possible to make £2 in the following way:
 * 
 * 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
 * How many different ways can £2 be made using any number of coins? */

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <fstream>

std::ofstream fileo("output.txt");

typedef unsigned int num_t;
typedef std::vector<num_t> vec_t;

void next(vec_t &, num_t& );
int sum(const vec_t &);
void print_vec(const vec_t &);
void print_list(const std::vector<vec_t> &);
bool is_odd(num_t);

#define N 200

int main()
{
    vec_t coins = {1, 2, 5, 10, 20, 50, 100, 200};
    vec_t way(N, 1);
    std::vector<vec_t> ways = {way};
    num_t odd_rem = 0;
    while (way.size() != 2)
    {
        next(way, odd_rem);
        // print_vec(way);
        if (way.size() != 0)
            ways.push_back(way);
    }
    print_list(ways);
    fileo << "ways: " << ways.size() + 1;
    return 0;
}

void next(vec_t &v, num_t &prev_odd_rem)
{

    vec_t coins = {2, 5, 10, 20, 50, 100, 200};

    num_t popped = v[v.size() - 1];
    v.pop_back();
    num_t rem = N - sum(v);
    if (rem >= 7 && rem != prev_odd_rem && is_odd(rem))
    {
        if (prev_odd_rem % 5 == 0)
            return next(v, prev_odd_rem);
        // resize v
        // create vec
        // copy vec to v's back

        vec_t::size_type vec_sz = (rem - 5) / 2;
        vec_t vec(vec_sz, 2);
        vec.push_back(5);
        std::copy(vec.rbegin(), vec.rend(), std::back_inserter(v));
        prev_odd_rem = rem;
        return;
    }

    vec_t::size_type i = 0;
    while (i != coins.size())
        if (rem % coins[i] == 0 && coins[i] > popped)
            break;
        else
            ++i;

    if (i == coins.size())
        return next(v, prev_odd_rem);
    else
        for (int j = 0; j < rem / coins[i]; ++j)
            v.push_back(coins[i]);
    return;
}

int sum(const vec_t &v)
{
    return std::accumulate(v.begin(), v.end(), 0);
}

void print_vec(const vec_t &v)
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<num_t>(fileo, " "));
    fileo << std::endl;
}
void print_list(const std::vector<vec_t> &list)
{
    std::for_each(list.begin(), list.end(), print_vec);
}

bool is_odd(num_t n)
{
    return n % 2 != 0;
}
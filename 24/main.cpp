#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>

using namespace std;

typedef unsigned long num_t;
typedef vector<num_t> vec_t;
typedef vec_t seed_t;
typedef pair<vec_t, seed_t> block_t;

vector<block_t> grow_seed(const seed_t &);
vector<block_t> grow_row(const vector<block_t> &);
vector<vector<block_t>> transpose(const vector<vector<block_t>> &);
void print(const vector<block_t> &);
void print_block(const block_t &);
void print_vec(const vec_t &);
size_t fact(num_t);

ofstream fileo("result.txt");

int main()
{
    seed_t rootSeed = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<block_t>> mat = {grow_seed(rootSeed)};
    print(mat[0]);
    for (seed_t::size_type i = 0; i < rootSeed.size() - 1; ++i)
    {
        vector<block_t> row = grow_row(mat[i]);
        mat.push_back(row);
        print(row);
    }

    return 0;
}

/** expands seed to block */
vector<block_t> grow_seed(const seed_t &rootSeed)
{
    vector<block_t> ret;
    size_t fact_len = fact(rootSeed.size() - 1);
    for (seed_t::size_type i = 0; i != rootSeed.size(); ++i)
    {
        seed_t seed = rootSeed;
        seed.erase(find(seed.begin(), seed.end(), rootSeed[i]));
        vec_t part(fact_len, rootSeed[i]);
        block_t block = {part, seed};
        ret.push_back(block);
    }
    return ret;
}

/** walks through prev_row blocks, finds seeds 
 * grows new blocks */
vector<block_t> grow_row(const vector<block_t> &prev_row)
{
    vector<block_t> ret;
    vector<block_t>::size_type size = prev_row.size();
    for (vector<block_t>::const_iterator it = prev_row.begin(); it != prev_row.end(); ++it)
    {
        vector<block_t> block = grow_seed(it->second);
        copy(block.begin(), block.end(), back_inserter(ret)); 
    }
    return ret;
}

size_t fact(num_t n)
{
    return (n == 1 || n == 0) ? 1 : n * fact(n - 1);
}

void print(const vector<block_t> &v)
{
    for_each(v.begin(), v.end(), print_block);
    fileo << endl;
}

void print_block(const block_t &b)
{
    print_vec(b.first);
    // print_vec(b.second);
}

void print_vec(const vec_t &v)
{
    copy(v.begin(), v.end(), ostream_iterator<num_t>(fileo));
}

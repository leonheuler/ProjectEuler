#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <algorithm>

std::ofstream fileo("output.txt");

typedef int num_t;
typedef std::vector<num_t> vec_t;
typedef std::pair<vec_t, vec_t> cell_t;
typedef std::vector<cell_t> col_t;
typedef std::vector<col_t> table_t;

cell_t fact(num_t);
table_t spawn_rows(const col_t &col);
void print_cell(const cell_t &);
void print_col(const col_t &);
void print_table(const table_t &);
void erase_matches(table_t &);
int count_elements(const table_t &);

#define N 100

int main()
{
    col_t col_1;
    for (int a = 2; a <= N; ++a)
        col_1.push_back(fact(a));

    table_t table = spawn_rows(col_1);

    std::cout << count_elements(table) << std::endl;

    erase_matches(table);

    print_table(table);

    std::cout << count_elements(table) << std::endl;

    return 0;
}

int count_elements(const table_t &t)
{
    int ret = 0;
    for (table_t::const_iterator it = t.begin(); it != t.end(); ++it)
        for (col_t::const_iterator jt = it->begin(); jt != it->end(); ++jt)
            ++ret;
    return ret;
}

void erase_matches(table_t &t)
{
    for (table_t::iterator it = t.begin(); it != t.end(); ++it)
    {
        for (table_t::iterator jt = it + 1; jt != t.end(); ++jt)
        {
            if ((it->begin()->first) == (jt->begin()->first))
            {
                for (col_t::iterator kt = it->begin(); kt != it->end(); ++kt)
                {
                    for (col_t::iterator lt = jt->begin(); lt != jt->end(); ++lt)
                    {
                        if (kt->second == lt->second)
                        {
                            jt->erase(lt);
                            std::cout << "match!" << std::endl;
                        }
                    }
                }
            }
        }
    }
}

table_t spawn_rows(const col_t &col)
{
    table_t ret;
    for (col_t::const_iterator it = col.begin(); it != col.end(); ++it)
    {
        col_t row;
        for (int i = 2; i <= N; ++i)
        {
            cell_t cell = *it;
            for (vec_t::iterator jt = cell.second.begin(); jt != cell.second.end(); ++jt)
                *jt *= i;
            row.push_back(cell);
        }
        ret.push_back(row);
    }
    return ret;
}

cell_t fact(num_t n)
{
    int d = 2;
    vec_t degrees = {1};
    vec_t primes = {1};
    while (n != 1)
    {
        int degree = 0;
        while (n % d == 0)
        {
            ++degree;
            n /= d;
        }
        if (degree > 0)
        {
            primes.push_back(d);
            degrees.push_back(degree);
        }
        d++;
    }
    primes.erase(primes.begin());
    degrees.erase(degrees.begin());
    return {primes, degrees};
}

void print_cell(const cell_t &cell)
{
    copy(cell.first.begin(), cell.first.end(), std::ostream_iterator<num_t>(fileo, " "));
    fileo << "| ";
    copy(cell.second.begin(), cell.second.end(), std::ostream_iterator<num_t>(fileo, " "));
    fileo << "\t\t\t\t";
}

void print_col(const col_t &col)
{
    std::for_each(col.begin(), col.end(), print_cell);
    fileo << std::endl;
}

void print_table(const table_t &t)
{
    std::for_each(t.begin(), t.end(), print_col);
}
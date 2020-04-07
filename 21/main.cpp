// Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
// If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284.
//
// The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
// Evaluate the sum of all the amicable numbers under 10000.

#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

bool is_amicable(int);
vector<int> factorization(int);
void print_mat(vector<vector<int>> &);
void find_proper_divisors(vector<int>, vector<int> &);
void sift_mat(vector<vector<int>> &);

int main()
{

    vector<int> am_vec;

    for (int n = 1; n <= 10000; n++)
        if (is_amicable(n))
            am_vec.push_back(n);

    copy(am_vec.begin(), am_vec.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    int ans = accumulate(am_vec.begin(), am_vec.end(), 0);

    cout << "Answer: " << ans << endl;

    return 0;
}

bool is_amicable(int n)
{
    vector<int> divs1 = {1};
    // find_proper_divisors(factorization(n), divs1);
    find_proper_divisors(n, divs1);
    int sum1 = accumulate(divs1.begin(), divs1.end(), 0);
    if (sum1 == 1)
        return false;
    cout << "d(" << n << ") = " << sum1 << endl;

    vector<int> divs2 = {1};
    // find_proper_divisors(factorization(sum1), divs2);
    find_proper_divisors(sum1, divs2);
    int sum2 = accumulate(divs2.begin(), divs2.end(), 0);
    cout << "d(" << sum1 << ") = " << sum2 << endl;

    if ((n == sum2) && (n != sum1))
        cout << "bingo!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl
             << endl;

    return (n == sum2) && (n != sum1);
}

vector<int> factorization(int n)
{
    vector<int> ret;
    int d = 2;
    while (n != 1)
    {
        if (n % d == 0)
        {
            ret.push_back(d);
            n /= d;
        }
        else
            d++;
    }
    /*
    cout << "factorisation of " << n << ": ";
    copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    */
    return ret;
}

void remove_diagonal(vector<vector<int>> &);

/** Нахождение всех делителей числа меньших его самого, 
 * */
void find_proper_divisors(vector<int> prime_factors_vec, vector<int> &proper_divisors)
{

    if (prime_factors_vec.size() <= 1)
        return;

    vector<vector<int>> mat(prime_factors_vec.size(), prime_factors_vec); // Создаём квадратную матрицу, строки которой являются копиями prime_factor_vec

    remove_diagonal(mat); // Удаляем диагональ
    sift_mat(mat);        // Удаляем повторяющиеся строки

    for (auto row = mat.begin(); row != mat.end(); row++) // Идём по строкам матрицы
    {
        int prod = accumulate(row->begin(), row->end(), 1, std::multiplies<int>()); // Находим очередной делитель, перемножая элементы строки

        if (find(proper_divisors.begin(), proper_divisors.end(), prod) == proper_divisors.end()) // Если такого делителя ещё не было
            proper_divisors.push_back(prod);                                                     // добавляем в proper_divisors
    }
    for (auto row = mat.begin(); row != mat.end(); row++) // Идём по строкам матрицы
    {
        find_proper_divisors(*row, proper_divisors); // Применяем к каждой из них действия выше
    }
}

void find_proper_divisors(int n, vector<int> &proper_divisors)
{
    for (int d = 2; d <= sqrt(n); d++)
    {
        if (n % d == 0)
            proper_divisors.push_back(d);
    }
}

void remove_diagonal(vector<vector<int>> &M)
{
    int pos = 0;
    for (vector<vector<int>>::iterator row = M.begin(); row != M.end(); row++)
    {
        row->erase(row->begin() + pos);
        pos++;
    }
}

// helper function
void print_mat(vector<vector<int>> &M)
{
    for (auto row = M.begin(); row != M.end(); row++)
    {
        for (auto col = row->begin(); col != row->end(); col++)
        {
            cout << *col << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void sift_mat(vector<vector<int>> &M)
{
    if (M.size() == 1)
        return;

    for (auto vec1 = M.begin(); vec1 != M.end(); vec1++)
    {
        auto vec2 = vec1;
        while (vec2 != M.end())
            if (*++vec2 == *vec1)
                vec2 = M.erase(vec2);
    }
}

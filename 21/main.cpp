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
#include <ctime>

using namespace std;

#define num_t unsigned long
#define upper_limit 100000

bool is_amicable(num_t);
vector<num_t> factorization(num_t);
void print_mat(vector<vector<num_t>> &);
void find_proper_divisors(vector<num_t>, vector<num_t> &);
void find_proper_divisors(num_t n, vector<num_t> &);
void sift_mat(vector<vector<num_t>> &);

#define PRINT_VEC(vec) \
    copy(vec.begin(), vec.end(), ostream_iterator<num_t>(cout, " ")); \
    cout << endl

// #define RECURSIVE_MATRIX_GENERATION_METHOD

int main()
{
    unsigned int start_time = clock();
    vector<num_t> am_vec;

    for (num_t n = 1; n <= upper_limit; n++)
        if (is_amicable(n))
            am_vec.push_back(n);

    PRINT_VEC(am_vec);

    num_t ans = accumulate(am_vec.begin(), am_vec.end(), 0);

    cout << "Answer: " << ans << endl;
    unsigned int end_time = clock();
    cout << "Runtime: " << (end_time - start_time) / CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}

bool is_amicable(num_t n)
{
    vector<num_t> divs1 = {1};
#ifdef RECURSIVE_MATRIX_GENERATION_METHOD
    find_proper_divisors(factorization(n), divs1);
#else
    find_proper_divisors(n, divs1);
#endif
    num_t sum1 = accumulate(divs1.begin(), divs1.end(), 0);
    if (sum1 == 1)
        return false;
    cout << "d(" << n << ") = " << sum1 << endl;

    vector<num_t> divs2 = {1};

#ifdef RECURSIVE_MATRIX_GENERATION_METHOD
    find_proper_divisors(factorization(sum1), divs2);
#else
    find_proper_divisors(sum1, divs2);
#endif

    num_t sum2 = accumulate(divs2.begin(), divs2.end(), 0);
    cout << "d(" << sum1 << ") = " << sum2 << endl;

    if ((n == sum2) && (n != sum1))
        cout << "bingo!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl
             << endl;

    return (n == sum2) && (n != sum1);
}

vector<num_t> factorization(num_t n)
{
    vector<num_t> ret;
    num_t d = 2;
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
    // PRINT_VEC(ret);
    return ret;
}

void remove_diagonal(vector<vector<num_t>> &);

/** Нахождение всех делителей числа меньших его самого методом рекурсивной генерации матриц, 
 * строки которой содержат комбинации простых множителей
 * */
void find_proper_divisors(vector<num_t> prime_factors_vec, vector<num_t> &proper_divisors)
{

    if (prime_factors_vec.size() <= 1)
        return;

    vector<vector<num_t>> mat(prime_factors_vec.size(), prime_factors_vec); // Создаём квадратную матрицу, строки которой являются копиями prime_factor_vec

    remove_diagonal(mat); // Удаляем диагональ для получения различных комбинаций
    sift_mat(mat);        // Удаляем повторяющиеся строки

    for (auto row = mat.begin(); row != mat.end(); row++) // Идём по строкам матрицы
    {
        int prod = accumulate(row->begin(), row->end(), 1, std::multiplies<num_t>()); // Находим очередной делитель, перемножая элементы строки

        if (find(proper_divisors.begin(), proper_divisors.end(), prod) == proper_divisors.end()) // Если такого делителя ещё не было
            proper_divisors.push_back(prod);                                                     // добавляем в proper_divisors
    }
    for (auto row = mat.begin(); row != mat.end(); row++) // Идём по строкам матрицы
    {
        find_proper_divisors(*row, proper_divisors); // Применяем к каждой из них действия выше
    }
}

/** Нахождение всех делителей числа меньших его самого методом перебора
 * */
void find_proper_divisors(num_t n, vector<num_t> &proper_divisors)
{
    for (num_t d = 2; d < n; d++)
        if (n % d == 0)
            proper_divisors.push_back(d);

    // PRINT_VEC(proper_divisors);
}

/** Удаление главной диагонали матрицы
 * */
void remove_diagonal(vector<vector<num_t>> &M)
{
    int pos = 0;
    for (vector<vector<num_t>>::iterator row = M.begin(); row != M.end(); row++)
    {
        row->erase(row->begin() + pos);
        pos++;
    }
}


/** Отрисовать матрицу
 * */
void print_mat(vector<vector<num_t>> &M)
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

/** Удаление повторяющихся строк матрицы %M
 * */
void sift_mat(vector<vector<num_t>> &M)
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

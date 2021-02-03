#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <numeric>

using namespace std;

bool is_triangle(int n)
{
    float k = (-1 + sqrt(1 + 8 * n)) / 2;
    return k - (int)k == 0;
}

bool is_square(int n)
{
    float k = sqrt(n);
    return k - (int)k == 0;
}

bool is_pentagonal(int n)
{
    float k = (1 + sqrt(1 + 24 * n)) / 6;
    return k - (int)k == 0;
}

bool is_hexagonal(int n)
{
    float k = (1 + sqrt(1 + 8 * n)) / 4;
    return k - (int)k == 0;
}
bool is_heptagonal(int n)
{
    float k = (3 + sqrt(9 + 40 * n)) / 10;
    return k - (int)k == 0;
}
bool is_octagonal(int n)
{
    float k = (1 + sqrt(1 + 3 * n)) / 3;
    return k - (int)k == 0;
}

bool is_polygonal(int n)
{
    return is_triangle(n) || is_square(n) || is_pentagonal(n) || is_hexagonal(n) || is_heptagonal(n) || is_octagonal(n);
}

// т.к. одно и то же число может принадлежать нескольким типам строим вектор принадлежности типам
vector<int> get_poligonal_types(vector<int> comb)
{
    vector<int> result(6, 0);
    for (auto c : comb)
    {
        if (is_triangle(c))
            result[0]++;
        if (is_square(c))
            result[1]++;
        if (is_pentagonal(c))
            result[2]++;
        if (is_hexagonal(c))
            result[3]++;
        if (is_heptagonal(c))
            result[4]++;
        if (is_octagonal(c))
            result[5]++;
    }
    return result;
}

int main()
{
    // генерация всех возможных комбинаций двух крайних чисел
    vector<pair<int, int>> edge;
    for (int i = 1000; i < 10000; ++i)
        if (is_polygonal(i) && i % 100 > 10)
            for (int j = 1000; j < 10000; ++j)
                if (is_polygonal(j) && i / 100 == j % 100)
                    edge.push_back({i, j});

    // генерация всех возможных комбинаций двух центральных чисел
    vector<pair<int, int>> center;
    for (int i = 1000; i < 10000; ++i)
        if (is_polygonal(i) && i % 100 > 10)
            for (int j = 1000; j < 10000; ++j)
                if (is_polygonal(j) && i % 100 == j / 100)
                    center.push_back({i, j});

    // генерация всех возможных двух оставшихся чисел для имеющихся комбинаций 
    for (auto i : edge)
    {
        for (auto j : center)
        {
            int k = (i.first % 100) * 100 + j.first / 100;   // левое
            int l = (j.second % 100) * 100 + i.second / 100; // правое
            if (is_polygonal(k) && is_polygonal(l) && k > 1000 && l > 1000)
            {
                // работаем с полной комбинацией
                if (set<int>({i.first, k, j.first, j.second, l, i.second}).size() == 6) // исключаем комбинации с повторяющимися числами
                {
                    vector<int> comb = {i.first, k, j.first, j.second, l, i.second};
                    vector<int> types = get_poligonal_types(comb);

                    // у этого вектора не должно быть нулей, чтобы встречались все типы
                    // двойки могут быть только на 1 и 4 элементах
                    if (find(types.begin(), types.end(), 0) == types.end() && (types[3] == 2 || types[0] == 2))
                    {
                        for (auto c : comb)
                            cout << c << " ";
                        cout << endl;
                        cout << accumulate(comb.begin(), comb.end(), 0) << endl;
                    }
                    // получаем ответ с точностью до перестановки
                }
            }
        }
    }

    cin.get();
    return 0;
}
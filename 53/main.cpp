#include <iostream>
#include <numeric>
#include <vector>

typedef unsigned long long num_t;
typedef std::vector<num_t> vec_t;

vec_t factorial(num_t n)
{
    vec_t ret;
    do
    {
        ret.push_back(n);
    } while (--n);

    return ret;
}

int main()
{

    num_t ans = 0;

    for (num_t n = 2; n <= 100; ++n)
    {

        for (num_t r = 1; r < n; ++r)
        {
            auto nom = factorial(n);
            auto den1 = factorial(r);
            auto den2 = factorial(n - r);

            for (auto &&den1_factor : den1)
                for (auto &&nom_factor : nom)
                    if (den1_factor > 1 && nom_factor > 1)
                        if (nom_factor % den1_factor == 0)
                        {
                            nom_factor /= den1_factor;
                            den1_factor = 1;
                            break;
                        }

            for (auto &&den2_factor : den2)
                for (auto &&nom_factor : nom)
                    if (den2_factor > 1 && nom_factor > 1)
                        if (nom_factor % den2_factor == 0)
                        {
                            nom_factor /= den2_factor;
                            den2_factor = 1;
                        }

            for (auto &&den2_factor : den2)
                for (auto &&nom_factor : nom)
                    if (den2_factor > 1 && nom_factor > 1)
                        if (den2_factor % nom_factor == 0)
                        {
                            den2_factor /= nom_factor;
                            nom_factor = 1;
                        }

            num_t res = std::accumulate(nom.begin(), nom.end(), 1, std::multiplies<num_t>()) / std::accumulate(den2.begin(), den2.end(), 1, std::multiplies<num_t>());
            if (res > 1e6)
                ++ans;
        }
    }

    std::cout << ans << std::endl;
    system("pause");
    return 0;
}
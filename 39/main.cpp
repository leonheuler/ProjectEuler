#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> right_solutions(int p)
{
    std::vector<std::vector<int>> ret;
    int a = 1;
    while (a < p / 2)
    {
        int b = a, c = p - (a + b);
        while (b < p / 2)
        {
            if (a + b > c)
                if (a * a + b * b == c * c)
                    ret.push_back({a, b, c});
            ++b;
            c = p - (a + b);
        }
        ++a;
    }
    return ret;
}

int main()
{
    std::map<int, std::vector<std::vector<int>>> triangles;
    int pval = 0;
    int sol_num = 0;
    for (int p = 5; p <= 1000; ++p)
    {
        triangles[p] = right_solutions(p);
        if (triangles[p].size() > sol_num)
        {
            pval = p;
            sol_num = triangles[p].size();
        }
    }

    std::cout << "p: " << pval << " solutions: " << sol_num << std::endl;
    return 0;
}
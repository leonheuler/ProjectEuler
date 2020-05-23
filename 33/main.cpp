#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> expand(const std::pair<int, int> &frct)
{
    std::vector<std::pair<int, int>> ret;
    int nom = frct.first * 10;
    int den = frct.second * 10;
    for (;;)
    {
        nom += 1;
        if (nom * frct.second % frct.first != 0)
            continue;
        else
            den = nom * frct.second / frct.first;
        
        if (den >= 100)
            break;

        ret.push_back({nom, den});
    }
    return ret;
}

int main()
{
    std::vector<std::pair<std::pair<int, int>, std::vector<std::pair<int, int>>>> vec;
    for (int nom = 1; nom <= 8; ++nom)
        for (int den = nom + 1; den <= 9; ++den)
            vec.push_back({{nom, den}, expand({nom, den})});

    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        std::cout << i->first.first << "," << i->first.second << "\t";
        for (auto j = i->second.begin(); j != i->second.end(); ++j)
            std::cout << j->first << "," << j->second << "\t";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (auto i = vec.begin(); i != vec.end(); ++i)
    {
        std::string nom_par = std::to_string(i->first.first);
        std::string den_par = std::to_string(i->first.second);
        
        for (auto j = i->second.begin(); j != i->second.end(); ++j)
        {
            std::string nom = std::to_string(j->first);
            std::string den = std::to_string(j->second);
            size_t nom_par_pos = nom.find(nom_par);
            size_t den_par_pos = den.find(den_par);
            if (nom_par_pos != std::string::npos && den_par_pos != std::string::npos)
            {
                nom.erase(nom_par_pos,1);
                den.erase(den_par_pos,1);
                if (nom == den)
                    std::cout << i->first.first << "," << i->first.second << "\t" << j->first << "," << j->second << std::endl;
            }
        }
    }

    return 0;
}
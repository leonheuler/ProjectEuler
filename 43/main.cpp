#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

std::ofstream fileo("output.txt");

typedef unsigned long long num_t;

bool has_substring_divisability(const std::string &s)
{
    if (std::stoi(std::string(s.end() - 3, s.end())) % 17 == 0)
        if (std::stoi(std::string(s.end() - 4, s.end() - 1)) % 13 == 0)
            if (std::stoi(std::string(s.end() - 5, s.end() - 2)) % 11 == 0)
                if (std::stoi(std::string(s.end() - 6, s.end() - 3)) % 7 == 0)
                    if (std::stoi(std::string(s.end() - 7, s.end() - 4)) % 5 == 0)
                        if (std::stoi(std::string(s.end() - 8, s.end() - 5)) % 3 == 0)
                            if (std::stoi(std::string(s.end() - 9, s.end() - 6)) % 2 == 0)
                                return true;
    return false;
}

int main()
{
    num_t ans = 0;

    std::string s = "1023456789";
    while (s != "0123456789")
    {
        if (has_substring_divisability(s))
            ans += std::stoull(s);
        std::next_permutation(s.begin(), s.end());
    }

    std::cout << ans << std::endl;
    return 0;
}
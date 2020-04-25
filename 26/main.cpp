/** 26
 * 0.3
 * 0.3333333
 * 0.1333333
 * 0.1313131
 * 0.
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::ofstream fileo("output.txt");

#define DECIMAL_DIGITS 2000

typedef std::vector<std::pair<int, int>> rec_t;

std::string prime_divide(const int &q, int n)
{
    std::string ret = "0.";
    int nom = 1;
    for (int i = 0; i < n; ++i)
    {
        nom *= 10;
        int den = nom / q;
        ret += std::to_string(den);
        nom = nom - q * den;
    }
    return ret;
}

bool is_trivial(const std::string &s)
{
    return (s[0] == s[s.size() - 1]);
}

int rec_cycle_len(std::string dd) // 0434782608695652173913.0434782608695652173913
{
    int ret = 0;
    dd.erase(dd.begin(), dd.begin() + 2);
    size_t i = 0;
    while (i != dd.size())
    {
        size_t reccuring_digit_position = dd.find(dd[i], i + 1);
        while (reccuring_digit_position != std::string::npos)
        {
            if (reccuring_digit_position != std::string::npos)
            {
                std::string reccuring_seq_candidate(dd.begin() + i, dd.begin() + reccuring_digit_position);
                if (is_trivial(reccuring_seq_candidate))
                {
                    reccuring_digit_position = dd.find(dd[i], reccuring_digit_position + 1);
                    continue;
                }
                std::cout << reccuring_seq_candidate << " " << std::endl;
                size_t spos = dd.find(reccuring_seq_candidate, reccuring_digit_position);
                size_t len = reccuring_seq_candidate.length();
                if (spos == reccuring_digit_position)
                {
                    fileo << " [" << reccuring_seq_candidate << "] ";
                    return len;
                }
            }
            reccuring_digit_position = dd.find(dd[i], reccuring_digit_position + 1);
        }
        ++i;
    }
    return ret;
}

bool check_uniqness(const rec_t &v);

int main()
{
    for (int d = 2; d < 1000; ++d)
    {
        std::string dd = prime_divide(d, DECIMAL_DIGITS);
        fileo << dd << '\t' << " d " << d << '\t' << " len " << rec_cycle_len(dd) << std::endl;
    }
    return 0;
}

bool check_uniqness(const rec_t &v)
{
    std::pair<int, int> max_rec = {0, 0};
    int match_counter = 0;
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        if (i->second > max_rec.second)
        {
            max_rec.first = i->first;
            max_rec.second = i->second;
            match_counter = 1;
        }
        else if (i->second == max_rec.second)
            ++match_counter;
    }

    if (match_counter == 1)
        std::cout << "ans: " << max_rec.first << " " << max_rec.second;

    return match_counter == 1;
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<std::string> split(const std::string &);

bool is_triangle(const std::string &word)
{
    int word_value = std::accumulate(word.begin(), word.end(), 0) - 64 * word.size();
    int triangle_num = 1;
    for (int n = 1; triangle_num <= word_value; ++n)
        if ((triangle_num = n * (n + 1) / 2) == word_value)
            return true;
    return false;
}

int main()
{
    std::ifstream infile("p042_words.txt");
    std::vector<std::string> words;
    std::string s;
    while (getline(infile, s))
    {
        std::vector<std::string> n = split(s);
        copy(n.begin(), n.end(), back_inserter(words));
    }

    int ans = 0;
    for (auto w : words)
        if (is_triangle(w))
            ++ans;

    std::cout << ans << std::endl;

    return 0;
}

bool alpha(char c) { return isalpha(c); }

bool not_alpha(char c) { return !isalpha(c); }

std::vector<std::string> split(const std::string &s)
{
    std::vector<std::string> ret;
    typedef std::string::const_iterator iter;
    iter i = s.begin();

    while (i != s.end())
    {
        i = find_if(i, s.end(), alpha);
        iter j = find_if(i, s.end(), not_alpha);
        if (j != s.end())
            ret.push_back(std::string(i, j));
        i = j;
    }
    return ret;
}
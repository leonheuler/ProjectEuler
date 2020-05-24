#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string champ_const;
    int i = 1;
    while (champ_const.size() < 1e6)
    {
        champ_const += std::to_string(i);
        ++i;
    }

    unsigned long ans = (champ_const[0] - 48) * (champ_const[10 - 1] - 48) * (champ_const[100 - 1] - 48) * (champ_const[1000 - 1] - 48) *
                        (champ_const[10000 - 1] - 48) * (champ_const[100000 - 1] - 48) * (champ_const[1000000 - 1] - 48);

    std::cout << ans << std::endl;

    return 0;
}
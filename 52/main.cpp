/** It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
 * Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
 * */

#include <iostream>
#include <string>
#include <set>

typedef unsigned long num_t;

int main()
{
    for (num_t n = 1;; ++n)
    {
        std::string n1 = std::to_string(n);
        std::set<char> x1(n1.begin(), n1.end());

        std::string n2 = std::to_string(n * 2);
        std::set<char> x2(n2.begin(), n2.end());
        if (x2 == x1)
        {
            std::string n3 = std::to_string(n * 3);
            std::set<char> x3(n3.begin(), n3.end());
            if (x3 == x2)
            {
                std::string n4 = std::to_string(n * 4);
                std::set<char> x4(n4.begin(), n4.end());
                if (x4 == x3)
                {
                    std::string n5 = std::to_string(n * 5);
                    std::set<char> x5(n5.begin(), n5.end());
                    if (x5 == x4)
                    {
                        std::string n6 = std::to_string(n * 6);
                        std::set<char> x6(n6.begin(), n6.end());
                        if (x6 == x5)
                        {
                            std::cout << n << std::endl;
                            break;
                        }
                    }
                }
            }
        }
    }
    std::cout << "Press any key to continue..." << std::endl;
    std::cin.get();
    return 0;
}
/**
 * In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:
 * 
 * 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
 * It is possible to make £2 in the following way:
 * 
 * 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
 * How many different ways can £2 be made using any number of coins? */

#include <iostream>


int main()
{
    int ans = 0;

    for (int c1 = 0; c1 <= 200; ++c1)
    {
        for (int c2 = 0; c2 <= 100; ++c2)
        {
            for (int c5 = 0; c5 <= 40; ++c5)
            {
                for (int c10 = 0; c10 <= 20; ++c10)
                {
                    for (int c20 = 0; c20 <= 10; ++c20)
                    {
                        for (int c50 = 0; c50 <= 4; ++c50)
                        {
                            for (int c100 = 0; c100 <= 2; ++c100)
                            {
                                for (int c200 = 0; c200 <= 1; ++c200)
                                    if (1*c1 + 2*c2 +5*c5 + 10*c10 + 20*c20 + 50*c50 + 100*c100 + 200*c200 == 200)
                                        ++ans;
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}



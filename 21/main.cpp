// Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
// If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. 
//                                  
// The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
// Evaluate the sum of all the amicable numbers under 10000.

#include <iostream>
#include <vector>
#include <numeric>
#include <map>

using namespace std;

bool is_amicable(int);

int main()
{
    vector<int> am_vec;

    for (int n = 2; n <= 10000; n++)
    {
        if (is_amicable(n))
            am_vec.push_back(n);
    }

    int ans = accumulate(am_vec.begin(), am_vec.end(), 0);

    cout << "Answer: " << ans << endl;

}

vector<int> find_divisors(int n);

bool is_amicable(int n)
{
    vector<int> divisors1;
    divisors1 = find_divisors(n); // if n = 220, then divisors1 = {1, 2, 4, 5, 10, 11, 20, 22, 44, 55, 110}
    int sum1 = accumulate(divisors1.begin(), divisors1.end(), 0); // sum1 = 286

    vector<int> divisors2;
    divisors2 = find_divisors(sum1);  // if n = 286, then divisors2 = {1, 2, 4, 71, 142}
    int sum2 = accumulate(divisors2.begin(), divisors2.end(), 0); // sum2 =  

    if (sum1 == sum2)
        return true;
    else
        return false;
    
}





#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>
#include <iterator>
using namespace std;

typedef int num_t;

void decimal_multiplication(list<num_t> &v, num_t n)
{
    // multiply v's elements by n
    int t = 0;
    list<num_t>::reverse_iterator it = v.rbegin();
    while (it != v.rend())
    {
        *it *= n;
        *it += t;
        t = *it / 10;
        *it %= 10;
        it++;
    }

    while (t / 10 > 0)
    {
        v.push_front(t % 10);
        t /= 10;
    }

    v.push_front(t);

}

int main()
{

    list<num_t> number = {1};
    int n = 2;
    while (n <= 100)
    {
        decimal_multiplication(number, n);
        n++;
    }
    
    copy(number.begin(), number.end(), ostream_iterator<num_t>(cout, ""));
    cout << endl << accumulate(number.begin(), number.end(), 0) << endl;

    system("pause");

    return 0;
}
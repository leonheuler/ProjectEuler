#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int properFractions(int d)
{
    double dist_min = 1.0;
    int res = 0;
    for (int den = 2; den <= d; den++) 
    {
        for (int nom = den / 2; nom > 0; nom--)
        {
            if (double(nom)/den < 1/3.0)
                break;

            double dist = 3.0/7 - double(nom)/double(den);

            if (dist > 0) {
                if (dist > dist_min)
                    break;
                else {
                    res = nom;
                    dist_min = dist;
                }
            }
        }
    }
    return res;

}


int main() {

    const int n = 1000000;
    unsigned int start_time = clock();
    cout << properFractions(n) << endl;
    unsigned int end_time = clock();
    cout << "Runtime: " << (end_time - start_time) / CLOCKS_PER_SEC << " sec" << endl; // 146 sec
    system("pause");
    return 0;
}


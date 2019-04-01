#include <fstream>
#include <cmath>

using namespace std;

int main()
{


    ofstream fileo("result.txt");


    for (int a = 1; a < 500; ++a)
    {
        for (int b = 500 - a + 1; b < 500; ++b)
        {

            fileo << a << " " << b << endl;

            if (a*b == 1000*(a+b) - 500000)
            {
                a = 500;
                break;               
            }
        }
    }   


    fileo.close();


    return 0;
}
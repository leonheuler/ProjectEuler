#include <fstream>
#include <iostream>

using namespace std;

unsigned int gcd (unsigned int n1, unsigned int n2) {
    return (n2 == 0) ? n1 : gcd (n2, n1 % n2);
}

int main()
{

    ofstream fileo("result.txt");

    const int N = 1000;
    const int Nstart = 1;
    double n_div_phi = 0;
    // перебор всех чисел от 1 до N
    for (int i = Nstart; i <= N; i++)
    {
        int phi = 0;
        // проверка всех чисел от 1 до n на взаимнюу простоту с n
        for (int j = 1; j <= i; j++)
        {
            if (gcd(i,j) == 1) 
            {
                phi++;
            }   
        }

        n_div_phi = (double)i / (double)phi; 
        // fileo << "n: " << i << " phi(n): " << phi << " n/phi(n): " << n_div_phi << endl;
        fileo <</*phi << " " */ n_div_phi << endl;
    }

    fileo.close();
}
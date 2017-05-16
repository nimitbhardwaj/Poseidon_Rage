#include<iostream>
#include<vector>
using namespace std;
struct Trip
{
    int a, b, c;
};
int main()
{
    int r, k = 0, kapa = 100;
    struct Trip A[100];
    cin >> r;
    for(int a = 1; a <= kapa; a++)
    {
        for(int b = 1; b <= kapa; b++)
        {
            for(int c = 1; c <= kapa; c++)
            {
                int p = a + b + c;
                if(4 * b * c * (p - 2 * a) == p * ((p - 2 * a) * (p - 2 * a) + 4 * r * r))
                {
                    cout << a << ' ' << b << ' ' << c << endl; 
                }
            }
        }
    }
    return 0;
}

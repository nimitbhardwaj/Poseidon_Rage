#include<iostream>
const int mod = 1e9 + 7;
int *Pas[100000];
int pascal(int, int);
int main()
{
    int t;
    std::cin >> t;
    for(int i = 0; i < 100000; i++)
        Pas[i] = new int[i + 2];
    while(t--)
    {
        int n;
        std::cin >> n;
        //for(int i = 0; i < n; i++)
            //std::cout << ' ';
        std::cout << '1' << std::endl;
        for(int i = 1; i <= n; i++)
        {
            //for(int j = 0; j < n - i; j++)
                //std::cout.put(' ');
            for(int j = 0; j <= i; j++)
            {
                std::cout << pascal(i, j) << ' ';
            }
            std::cout << std::endl;
        }
    }
    for(int i = 0; i < 100000; i++)
        delete[] Pas[i];
    return 0;
}

int pascal(int n, int r)
{
    if(n == r || r == 0)
    {
        Pas[n][r] = 1;
        return Pas[n][r];
    }
    if(Pas[n][r] != 0)
        return Pas[n][r];
    else
    {
        Pas[n - 1][r - 1] = pascal(n - 1, r - 1);
        Pas[n - 1][r] = pascal(n - 1, r);
        return (Pas[n - 1][r - 1] + Pas[n - 1][r]) % mod;
        //return (pascal(n - 1, r - 1) + pascal(n - 1, r)) % mod;
    }
}

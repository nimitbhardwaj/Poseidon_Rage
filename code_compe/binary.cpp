#include <iostream>
#include <cstring>

const unsigned int MOD = 1000000007;
int dynamic_prog(unsigned int, unsigned int, unsigned int *);

int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        unsigned int n;
        unsigned int A[100000] = {0};
        std::cin >> n;
        std::cout << dynamic_prog(n, 0, A) << std::endl;
    }
    return 0;
}

int dynamic_prog(unsigned int n, unsigned int pos, unsigned int *A)
{
    if(A[pos] != 0)
        return A[pos];
    if(pos == n)
        return 1;
    if(pos + 4 > n || pos + 3 > n || pos + 2 > n)
    {
        A[pos] = (1 + dynamic_prog(n, pos + 1, A)) % MOD;
        return A[pos];
    }
    else
    {
        A[pos] = (dynamic_prog(n, pos + 1, A) + dynamic_prog(n, pos + 4, A)) % MOD;
        return A[pos];
    }
}

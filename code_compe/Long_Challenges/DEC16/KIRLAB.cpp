#include <iostream>
#include <algorithm>
int gcd(int, int);
int answer(int *, int *, int, int);
int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int n;
        std::cin >> n;
        int *A = new int[n]();
        int *B = new int[n]();
        for(int i = 0; i < n; i++)
            std::cin >> A[i];
        //std::cout << gcd(13, 2);
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(gcd(A[i], A[j]) != 1)
                {
                    B[i] = j;
                    break;
                }
            }
            if(B[i] == 0)
                B[i] = -1;
        }
        //for(int i = 0; i < n; i++)
            //std::cout << B[i] << std::endl;
        std::cout << answer(A, B, 0, n) << std::endl;
        delete[] A;
        delete[] B;
    }
    return 0;
}

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return 0;
    if(a > b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    while(a)
    {
        int tmp = a;
        a = b % a;
        b = tmp;
    }
    return b;
}

int answer(int *A, int *B, int k, int n)
{
    if(B[k] == -1)
        if(k == n - 1)
        {
            return 1;
        }
        else
            return answer(A, B, k + 1, n);
    return std::max(answer(A, B, k + 1, n), 1 + answer(A, B, B[k], n));
}

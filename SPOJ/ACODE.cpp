#include<iostream>
#include<string>
//using ull = unsigned long long int;
typedef unsigned long long int ull; 
ull codes(const std::string &S, int, ull *);
int main()
{
    while(1)
    {
        std::string S;
        std::cin >> S;
        if(S.size() == 1 && S == "0")
            break;
        ull *A;
        A = new ull[S.size()]();
        ull b = codes(S, 0, A);
        std::cout << b << std::endl;
        delete[] A;
    }
    return 0;
}

ull codes(const std::string &S, int n, ull *A)
{
    if(S[n] == '0')
    {
        A[n] = 0;
        return A[n];
    }
    if(n == S.size() - 1)
    {
        A[n] = 1;
        return A[n];
    }
    if(n == S.size() - 2)
    {
        if(S[n] == '1' || S[n] == '2' && S[n + 1] <= '6')
            A[n] = 2;
        else
            A[n] = 1;
        return A[n];
    }
    if(S[n] == '1' || S[n] == '2' && S[n + 1] <= '6')
    {
        if(A[n] != 0)
            return A[n];
        if(A[n + 1] == 0)
            A[n + 1] = codes(S, n + 1, A);
        if(A[n + 2] == 0)
            A[n + 2] = codes(S, n + 2, A);
        A[n] = A[n + 1] + A[n + 2];
        return A[n];
    }
    else
    {
        if(A[n] == 0)
        {
            if(A[n + 1] == 0)
                A[n + 1] = codes(S, n + 1, A);
            A[n] = A[n + 1];
        }
        return A[n];
    }

}

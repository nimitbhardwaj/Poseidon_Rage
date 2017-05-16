#include<iostream>
#include<string>
int count(const std::string &, const std::string &, int, int);
int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        std::string S, T;
        std::cin >> S >> T;
        std::cout << count(S, T, S.size(), T.size()) << std::endl;
    }
    return 0;
}

int count(const std::string &S, const std::string &T, int m, int n)
{
    if(m == 0 && n == 0 || n == 0)
        return 1;
    if(m == 0)
        return 0;
    
    if(S[m - 1] == T[n - 1])
        return count(S, T, m - 1, n - 1) + count(S, T, m - 1, n);
    else
        return count(S, T, m - 1, n);
}

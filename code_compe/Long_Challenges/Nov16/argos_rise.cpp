#include<iostream>
#include<string>
using std::string;
int argos_rise(string &, string &, int, int);
int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        string S, T;
        std::cin >> S >> T;
        std::cout << argos_rise(S, T, S.size(), T.size()) << std::endl;
    }
    return 0;
}

int argos_rise(string &S, string &T, int l, int m)
{
    if(l == 0 && m == 0 || m == 0)
        return 1;
    if(l == 0)
        return 0;
    if(S[l - 1] == T[m - 1])
        return argos_rise(S, T, l - 1, m - 1) + argos_rise(S, T, l - 1, m);
    else
        return argos_rise(S, T, l - 1, m);
}

#include<iostream>
#include<string>
int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int res = 0;
        std::string S;
        std::cin >> S;
        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] == '>')
                S[i] = '<';
            else if(S[i] == '<')
                S[i] = '>';
        }
        S += '0';
        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] == '>' && S[i + 1] == '<')
                res++;
        }
        std::cout << res << std::endl;
    }
    return 0;
}

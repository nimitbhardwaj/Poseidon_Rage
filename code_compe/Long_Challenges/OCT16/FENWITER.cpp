#include<iostream>
#include<string>
int L3_count(std::string &);
int L2_count(std::string &);
int L1_count(std::string &);
int checkStatus(std::string &);
int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        std::string s1, s2, s3, s4;
        int n;
        std::cin >> s1 >> s2 >> s3 >> n;
        int step3 = L3_count(s3);
        int step2 = L2_count(s2);
        if(step3 == 0)
            step2 = 0;
        step2 *= n;
        int step1 = L1_count(s1);
        std::cout << step1 + step2 + step3 + 1<< std::endl;
    }
    return 0;
}

int L3_count(std::string &S)
{
    int size = S.size(), result = 0;
    std::string s_dummy(size, '1');
    while(S != s_dummy)
    {
        int flag = 0, flag2 = 0;
        for(auto i = size - 1; i >= 0; i--)
        {
            char c = S[i];
            if(flag == 0 && c == '1')
            {
                S[i] = '0';
            }
            else if(flag == 0 && c == '0')
            {
                S[i] = '1';
                flag = 1;
            }
            S[i] = ((c - '0') & (S[i] - '0')) + '0';
            if(flag2 == 0 && S[i] == '0')
            {
                S[i] = '1';
            }
            else if(flag2 == 0 && S[i] == '1')
            {
                S[i] = '0';
                flag2 = 1;
            }
        }
        result++;
    }
    return result;
}

int L2_count(std::string &S)
{
    int size = S.size();
    for(int i = size - 1; i >= 0; i--)
    {
        if(S[i] == '0')
        {
            S[i] = '1';
        }
        else if(S[i] == '1')
        {
            S[i] = '0';
            break;
        }
    }
    return L3_count(S);
}

int checkStatus(std::string &S)
{
    int size = S.size();
    int ck = 0, s_ck = 0;
    for(int i = size - 1; i >= 0; i--)
    {
        char c = S[i];
        if(c == '1' && ck == 0)
            ck = 0;
        else if(c == '0')
        {
            ck = 1;
        }
        if(ck == 1 && c == '1')
            return 0;
    }
    return 1;
}

int L1_count(std::string &S)
{
    int size = S.size();
    int res = 0;
    if(checkStatus(S))
        return 0;
    while(!checkStatus(S))
    {
        int flag = 0, flag2 = 0;
        for(auto i = size - 1; i >= 0; i--)
        {
            char c = S[i];
            if(flag == 0 && c == '1')
            {
                S[i] = '0';
            }
            else if(flag == 0 && c == '0')
            {
                S[i] = '1';
                flag = 1;
            }
            S[i] = ((c - '0') & (S[i] - '0')) + '0';
            if(flag2 == 0 && S[i] == '0')
            {
                S[i] = '1';
            }
            else if(flag2 == 0 && S[i] == '1')
            {
                S[i] = '0';
                flag2 = 1;
            }
        }
        res++;
    }
    return res - 1;
}


#include<iostream>
#include<string>
int count(const std::string &, const std::string &);
int main(void)
{
    int t;
    std::cin >> t;
    while(t--)
    {
        std::string S, T;
        std::cin >> S >> T;
        std::cout << count(S, T) << std::endl;
    }
    return 0;
}

int count(const std::string &S, const std::string &T)
{
    int m = S.size();
    int n = T.size();
    int A[m + 1][n + 1];
    A[0][0] = 1;
    for(int i = 1; i <= n; i++)
        A[0][i] = 0;
    for(int i = 0; i <= m; i++)
        A[i][0] = 1;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(S[i - 1] == T[j - 1])
                A[i][j] = A[i - 1][j - 1] + A[i - 1][j];
            else
                A[i][j] = A[i - 1][j];
        }
    }
    return A[m][n];
}

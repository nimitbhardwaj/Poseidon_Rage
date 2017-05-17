#include <bits/stdc++.h>

using namespace std;

long long int dp(long long int n, vector<long long int> &);

int main()
{
    long long int n;
    vector<long long int> V(10000000, INT_MIN);
    for(int i = 0; i < 12; i++)
        V[i] = i;
    while(cin >> n)
    {
        if(n == 0)
            cout << 0 << endl;
        else
            cout << dp(n, V) << endl;
    }
    return 0;
}

long long int dp(long long int n, vector<long long int> &V)
{
    if(n < 10000000 && V[n] != INT_MIN)
        return V[n];
    if(n <= 11)
        return n;
    long long int kapa = max(dp(n / 2, V) + dp(n / 3, V) + dp(n / 4, V), n);
    if(n < 10000000)
        V[n] = kapa;
    return kapa;
}

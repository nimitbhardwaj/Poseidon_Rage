#include <bits/stdc++.h>

using namespace std;


long long int ans(long long int, map<long long int, long long int> &);

int main()
{
    long long int n;
    while(cin >> n)
    {
        map<long long int, long long int> m;
        cout << ans(n, m) << endl;
    }
    return 0;
}


long long int ans(long long int a, map<long long int, long long int> &m)
{
    if(a <= 5)
        return a;
    else if(m[a] != 0)
    {
        return m[a];
    }
    else
    {
        long long int A = ans(a / 2, m);
        long long int B = ans(a / 3, m);
        long long int C = ans(a / 4, m);
        long long int kapa = max(a, A + B + C);
        m[a] = kapa;
        return kapa;
    }
}

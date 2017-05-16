#include <bits/stdc++.h>
#define MOD 1000000007ll

using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while(t--)
    {
        long long int n;
        cin >> n;
        long long int min = (n * (((n - 1ll) / 2ll) * ((n - 1ll) / 2ll)) % MOD) % MOD;
        n--;
        long long int max = (((n % MOD) * (n + 1) % MOD * (2 * n + 1) % MOD) % MOD) / 6;
        cout << min << ' ' << max << endl;
    }
    return 0;
}

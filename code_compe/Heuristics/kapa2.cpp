#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, m, ans = 0;
    cin >> n >> m;
    if(n <= m)
        cout << n << endl, exit(0);
    if((n - m + 1) % 2 != 0) 
        ans = 1;
    ans += (n - m + 1) / 2 + m;
    cout << ans << endl;
    return 0;
}

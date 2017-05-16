#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, a, ans = 0;
    cin >> n;
    for(long long int i = 0; i < n; i++)
    {
        cin >> a;
        ans += a / 4;
        ans += a % 4;
    }
    cout << ans << endl;
    return 0;
}

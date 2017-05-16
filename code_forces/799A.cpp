#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t, k, d;
    cin >> n >> t >> k >> d;
    int kapa = n / k + (n % k != 0);
    kapa = t * kapa;
    if(kapa <= d)
        cout << "NO" << endl;
    else
    {
        if(kapa - d > t)
            cout << "YES" << endl;
        else
            cout << "NO" << endl << endl;
    }
    return 0;
}

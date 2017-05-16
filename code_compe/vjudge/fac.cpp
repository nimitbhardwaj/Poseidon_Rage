#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int kapa = 0;
        while(n)
        {
            kapa += n / 5;
            n = n / 5;
        }
        cout << kapa << endl;
    }
    return 0;
}

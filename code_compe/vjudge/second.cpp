#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cin >> a >> b >> c;
        cout << "Case " << i << ": ";
        cout << a + b + c - max(a, max(b, c)) - min(a, min(b, c)) << endl;
    }
    return 0;
}

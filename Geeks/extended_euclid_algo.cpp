#include <bits/stdc++.h>

using namespace std;

int gcdExtended(int, int, int &, int &);

int main()
{
    int a, b, x, y;
    cin >> a >> b;
    int gcd = gcdExtended(a, b, x, y);
    cout << "GCD = " << gcd << endl;
    cout << "x = " << x << " y = " << y << endl;
    return 0;
}

int gcdExtended(int a, int b, int &x, int &y)
{
    if(a == 0)
    {
        x = 0, y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}
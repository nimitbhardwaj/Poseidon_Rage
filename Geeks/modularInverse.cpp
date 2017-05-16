#include <bits/stdc++.h>

using namespace std;

int gcdExtended(int, int, int &, int &);
int modInverse(int, int);

int main()
{
    int n, m;
    cin >> n >> m;
    cout << modInverse(n, m) << endl;
    return 0;
}

int modInverse(int n, int m)
{
    int a, b;
    int gcd = gcdExtended(n, m, a, b);
    cout << "Kapa" << a << ' ' << b << endl;
    if(gcd != 1)
        return -1;
    else
        return (a % m + m) % m;
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

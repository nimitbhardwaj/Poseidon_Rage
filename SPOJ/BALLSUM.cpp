#include <iostream>
#include <algorithm>

using namespace std;

long long int gcd(long long int, long long int);

int main()
{
    long long int n, k;
    cin >> n >> k;
    while(n != -1 && k != -1)
    {
        long long int favour = k * (k - 2) / 4, max = (n * (n - 1)) / 2;
        if(k * (k - 2) % 4 != 0)
            favour++;
        long long int div = gcd(favour, max);
        if(k == 0 || k == 1 || k == 2 || n == 0 || n == 1 || n == 2)
            cout << 0 << endl;
        else if(favour == 0)
            cout << 0 << endl;
        else if(favour >= max)
            cout << 1 << endl;
        else
            cout << favour / div << '/' << max / div << endl;
        cin >> n >> k;
    }
    return 0;
}

long long int gcd(long long int a, long long int b)
{
    if(a == 0 || b == 0)
        return 0;
    if(a > b)
    {
        long long int tmp = a;
        a = b;
        b = tmp;
    }
    while(a)
    {
        long long int tmp = a;
        a = b % a;
        b = tmp;
    }
    return b;
}

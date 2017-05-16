#include <bits/stdc++.h>

using namespace std;

bool findSeq(int a, int b);

int main()
{
    int p, x, y;
    int b;
    cin >> p >> x >> y;
    b = x;
    int kapa = 0;
    bool napa = false;
    if(x < y)
    {
        kapa += (y - x) / 100;
        if((y - x) % 100)
            kapa++;
        x = x + kapa * 100;
        if(x - y > 50)
            x = x - 50, napa = true;
    }
    int i = 1;
    if(napa)
        i = 0;
    while(true)
    {
        if(findSeq(p, x))
            break;
        x = x + 50;
        kapa += i % 2;
        i++;
    }
    while(b >= y)
    {
        if(findSeq(p, b))
        {
            kapa = 0;
            break;
        }
        b -= 50;
    }
    cout << kapa << endl;
    return 0;
}

bool findSeq(int p, int x)
{
    int i = (x / 50) % 475;
    for(int j = 0; j < 25; j++)
    {
        i = (i * 96 + 42) % 475;
        if(i + 26 == p)
            return true;
    }
    return false;
}

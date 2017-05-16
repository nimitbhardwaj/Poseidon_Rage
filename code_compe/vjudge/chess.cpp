#include <bits/stdc++.h>

using namespace std;

int rook(int a, int b);
int knight(int a, int b);
int king(int a, int b);
int queen(int a, int b);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        char type;
        int a, b;
        cin >> type >> a >> b;
        if(type == 'r')
        {
            cout << rook(a, b);
        }
        else if(type == 'k')
        {
            cout << knight(a, b);
        }
        else if(type == 'K')
        {
            cout << king(a, b);
        }
        else if(type == 'Q')
        {
            cout << queen(a, b);
        }
        cout << endl;
    }
    return 0;
}

int rook(int a, int b)
{
    return min(a, b);
}

int knight(int a, int b)
{
    if((a * b) % 2 == 0)
        return (a * b) / 2;
    else
        return (a * b) / 2 + 1;
}

int king(int a, int b)
{
    return ((a + 1) / 2) * ((b + 1) / 2);
}

int queen(int a, int b)
{
    return min(a, b);
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    bool check = true;
    int mxy = INT_MAX;
    int kapa = 0;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if(mxy >= a)
        {
            mxy = a;
            kapa++;
        }
        if(a != b)
            check = false;
    }
    if(check == false)
        cout << "rated" << endl;
    else if(kapa == n)
        cout << "maybe" << endl;
    else
        cout << "unrated" << endl;
    return 0;
}

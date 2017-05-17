#include <bits/stdc++.h>

using namespace std;

char dp(int a, int turn, vector<int> &kapa, int l, int k);

int main()
{
    int k, l, m;
    cin >> k >> l >> m;
    vector<int> kapa(1000000, false);
    for(int i = 1; i < kapa.size(); i++)
    {
        if(i >= 0 && kapa[i - 1] == false)
            kapa[i] = true;
        else if(i - k >= 0 && kapa[i - k] == false)
            kapa[i] = true;
        else if(i - l >= 0 && kapa[i - l] == false)
            kapa[i] = true;
    }
    for(int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        if(kapa[a])
            cout << 'A';
        else
            cout << 'B';
    }
    cout << endl;
    return 0;
}

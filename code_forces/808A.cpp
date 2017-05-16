#include <bits/stdc++.h>

using namespace std;

int main()
{
    string n, m, S(20, 0);
    cin >> n;
    m = n;
    if(n[0] == '9')
    {
        n[0] = '0';
        n = '1' + n;
    }
    else
        n[0] = n[0] + 1;
    S[0] = n[0];
    for(int i = 0; i < n.size() - 1; i++)
        S[i + 1] = '0';
    cout << stoi(S) - stoi(m) << endl;

    return 0;
}

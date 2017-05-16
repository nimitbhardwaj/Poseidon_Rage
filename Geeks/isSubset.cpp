#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> V1(n), V2(m);
    map<int, bool> hash;
    for(int i = 0; i < n; i++)
    {
        cin >> V1[i];
        hash[V1[i]] = true;
    }
    for(int i = 0; i < m; i++)
        cin >> V2[i];
    bool kapa = false;
    for(int i = 0; i < m; i++)
    {
        if(hash[V2[i]] == false)
        {
            kapa = true;
            break;
        }
    }
    if(kapa)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}

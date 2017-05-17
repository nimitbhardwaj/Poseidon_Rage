#include <bits/stdc++.h>

using namespace std;

int dp(vector<int> &V);

int main()
{
    int r, c;
    while(cin >> r >> c && r != 0 && c != 0)
    {
        vector<vector<int> > V(r, vector<int> (c, 0));
        vector<int> kapa(V.size(), 0);
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cin >> V[i][j];
        for(int i = 0; i < V.size(); i++)
            kapa[i] = dp(V[i]);
        cout << dp(kapa) << endl;
    }
    return 0;
}

int dp(vector<int> &V)
{
    vector<int> kapa(V.size(), 0);
    int maxy = 0;
    kapa[0] = V[0];
    if(V.size() == 1)
        return V[0];
    kapa[1] = max(V[0], V[1]);
    if(V.size() == 2)
        return max(V[0], V[1]);
    for(int i = 2; i < V.size(); i++)
        kapa[i] = max(kapa[i - 1], kapa[i - 2] + V[i]);
    return *(kapa.end() - 1);
}

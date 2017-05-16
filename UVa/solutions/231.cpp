#include <bits/stdc++.h>

using namespace std;

int dp(vector<int> &V, int a, int prev);

int main()
{
    int a;
    int t = 0;
    while(cin >> a && a != -1)
    {
        t++;
        vector<int> V;
        V.push_back(a);
        while(cin >> a && a != -1)
            V.push_back(a);
        if(t != 1)
            cout << endl;
        cout << "Test #" << t << ':' << endl;
        cout << "  maximum possible interceptions: " << dp(V, 0, INT_MAX) << endl;
    }
    return 0;
}

int dp(vector<int> &V, int a, int prev)
{
    if(a == 0)
        return max(1 + dp(V, a + 1, V[0]), dp(V, a + 1, prev));
    if(a == V.size())
        return 0;
    else
    {
        if(V[a] < prev)
            return max(1 + dp(V, a + 1, V[a]), dp(V, a + 1, prev));
        else
            return dp(V, a + 1, prev);
    }
    
}

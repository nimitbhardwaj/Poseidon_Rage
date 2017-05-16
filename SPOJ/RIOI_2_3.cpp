#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<int> > V(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cin >> V[i][j];
        }
        int x, y, a, b;
        cin >> x >> y;
        cin >> a >> b;
    }
    return 0;
}

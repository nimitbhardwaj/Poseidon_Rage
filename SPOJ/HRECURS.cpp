#include <bits/stdc++.h>

using namespace std;

int sum(vector<int> &V, int n);

int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        vector<int> V(n, 0);
        for(int j = 0; j < n; j++)
            cin >> V[j];
        cout << "Case " << i << ": " << sum(V, V.size() - 1) << endl;
    }
    return 0;
}

int sum(vector<int> &V, int n)
{
    if(n == 0)
        return V[0];
    else
        return V[n] + sum(V, n - 1);
}

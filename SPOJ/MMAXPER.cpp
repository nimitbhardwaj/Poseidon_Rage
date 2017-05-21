#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > V(n);
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        V[i] = make_pair(a, b);
    }
    vector<int> out(n, 0);
    out[0] = max(V[0].first + V[0].second)
    return 0;
}

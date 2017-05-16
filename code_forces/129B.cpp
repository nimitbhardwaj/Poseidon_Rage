#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<list<pair<int, bool *> > > V(n);
    vector<bool> present(n, true);
    vector<int> degree(n, 0);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        V[a].push_back(make_pair(b, &present[b]));
        V[b].push_back(make_pair(a, &present[a]));
        degree[a]++;
        degree[b]++;
    }
    return 0;
}

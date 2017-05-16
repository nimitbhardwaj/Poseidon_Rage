#include <bits/stdc++.h>

using namespace std;

int dfs(vector<list<int> > &, vector<bool> &, int);

int main()
{
    int n, m;
    cin >> n >> m;
    vector<bool> mask(n);
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp)
            mask[i] = true;
        else
            mask[i] = false;
    }
    vector<list<int> > G(n);
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cout << dfs(G, mask, m) << endl;
    return 0;
}

int dfs(vector<list<int> > &G, vector<bool> &mask, int m)
{
    stack<pair<int, int> > S;
    S.push(make_pair(0, int(mask[0])));
    vector<bool> visited(G.size(), false);
    visited[0] = true;
    int ans = 0;
    while(!S.empty())
    {
        pair<int, int> kapa = S.top();
        S.pop();
        if(G[kapa.first].size() == 1 && kapa.second <= m && kapa.first != 0)
            ans++;
        for(list<int>::iterator i = G[kapa.first].begin(); i != G[kapa.first].end(); i++)
        {
            if(visited[*i])
                continue;
            pair<int, int> pussy;
            if(!mask[*i])
                pussy = make_pair(*i, 0);
            else
                pussy = make_pair(*i, kapa.second + int(mask[*i]));
            if(pussy.second > m)
                continue;
            visited[*i] = true;
            S.push(pussy);
        }
    }
    return ans;
}

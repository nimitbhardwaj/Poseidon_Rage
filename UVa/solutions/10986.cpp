#include <bits/stdc++.h>

using namespace std;

struct Comp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    { return a.second > b.second; }
};

int djikstra(vector<list<pair<int, int> > > &G, int S, int T);

int main()
{
    int t;
    cin >> t;
    for(int k = 1; k <= t; k++)
    {
        int n, m, S, T;
        cin >> n >> m >> S >> T;
        vector<list<pair<int, int> > > G(n);
        for(int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            G[a].push_back(make_pair(b, c));
            G[b].push_back(make_pair(a, c));
        }
        int kapa = djikstra(G, S, T);
        if(kapa == INT_MAX)
            cout << "Case #" << k << ": unreachable" << endl;
        else
            cout << "Case #" << k << ": " << kapa << endl;
    }
    return 0;
}

int djikstra(vector<list<pair<int, int> > > &G, int S, int T)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, Comp> Q;
    vector<int> V(G.size(), INT_MAX);
    V[S] = 0;
    Q.push(make_pair(S, 0));
    while(!Q.empty())
    {
        pair<int, int> kapa = Q.top();
        Q.pop();
        for(list<pair<int, int> >::iterator i = G[kapa.first].begin(); i != G[kapa.first].end(); i++)
        {
            if(V[i->first] > V[kapa.first] + i->second)
                V[i->first] = V[kapa.first] + i->second, Q.push(make_pair(i->first, V[i->first]));
        }
    }
    return V[T];
}

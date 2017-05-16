#include <bits/stdc++.h>

using namespace std;

struct Comp
{
    bool operator() (const int &a, const int &b)
    { return a > b; }
};

int djikstra(vector<vector<pair<int, int> > > &G, int a, int b);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        a--, b--;
        vector<vector<pair<int, int> > > G(n);
        for(int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            x--, y--;
            G[x].push_back(make_pair(y, z));
            G[y].push_back(make_pair(x, z));
        }
        int alpha = djikstra(G, a, b);
        if(alpha == INT_MAX)
            cout << "NONE" << endl;
        else
            cout << alpha << endl;
    }
    return 0;
}

int djikstra(vector<vector<pair<int, int> > > &G, int a, int b)
{
    priority_queue<int, vector<int>, Comp> Q;
    vector<int> dist(G.size(), INT_MAX);
    dist[a] = 0;
    Q.push(a);
    while(!Q.empty())
    {
        int kapa = Q.top();
        Q.pop();
        for(int i = 0; i < G[kapa].size(); i++)
        {
            if(dist[G[kapa][i].first] > dist[kapa] + G[kapa][i].second)
            {
                dist[G[kapa][i].first] = dist[kapa] + G[kapa][i].second;
                Q.push(G[kapa][i].first);
            }
        }
    }
    return dist[b];
}

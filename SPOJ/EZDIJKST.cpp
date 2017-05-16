#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<pair<int, int> > > Graph;

int djikstra(Graph &, int, int);

struct Comp
{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second >= b.second;
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        Graph G(n);
        for(int i = 0; i < k; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            G[a].push_back(make_pair(b, c));
        }
        int A, B;
        cin >> A >> B;
        A--, B--;
        int kapa = djikstra(G, A, B);
        if(kapa == INT_MAX)
            cout << "NO" << endl;
        else
            cout << kapa << endl;
    }
    return 0;
}

int djikstra(Graph &G, int a, int b)
{
    vector<int> V(G.size(), INT_MAX);
    V[a] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, Comp> Q;
    Q.push(make_pair(a, 0));
    while(!Q.empty())
    {
        pair<int, int> p = Q.top();
        Q.pop();
        for(int i = 0; i < G[p.first].size(); i++)
        {
            int kapa = V[p.first] + G[p.first][i].second;
            if(kapa < V[G[p.first][i].first])
            {
                V[G[p.first][i].first] = kapa;
                Q.push(make_pair(G[p.first][i].first, kapa));
            }
        }
    }
    return V[b];
}

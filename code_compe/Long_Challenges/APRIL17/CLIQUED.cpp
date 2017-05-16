#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<pair<long long int, long long int> > > Graph;

void djikstra(Graph &, long long int, long long int, long long int, vector<long long int> &);

struct Comp
{
    bool operator() (const pair<long long int, long long int> &a, const pair<long long int, long long int> &b)
    {
        return a.second > b.second;
    }
};

int main()
{
    long long int t;
    cin >> t;
    while(t--)
    {
        long long int n, k, x, m, s;
        cin >> n >> k >> x >> m >> s;
        s--;
        Graph G(n, vector<pair<long long int, long long int> >());
        for(long long int i = 0; i < m; i++)
        {
            long long int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            G[a].push_back(make_pair(b, c));
            G[b].push_back(make_pair(a, c));
        }
        vector<long long int> V(n);
        djikstra(G, k, x, s, V);
        for(long long int i = 0; i < V.size(); i++)
            cout << V[i] << ' ';
        cout << endl;
    }
    return 0;
}

void djikstra(Graph &G, long long int k, long long int x, long long int s, vector<long long int> &V)
{
    if(s < k)
    {
        for(long long int i = 0; i < V.size(); i++)
        {
            if(i < k)
                V[i] = x;
            else
                V[i] = LLONG_MAX;
        }
        V[s] = 0;
        priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int> >, Comp> Q;
        queue<pair<long long int, long long int> > kapaQ;
        for(long long int i = 0; i < k; i++)
            kapaQ.push(make_pair(i, V[i]));
        while(!kapaQ.empty())
        {
            Q.push(kapaQ.front());
            kapaQ.pop();
            while(!Q.empty())
            {
                pair<long long int, long long int> p = Q.top();
                Q.pop();
                if(p.second > V[p.first])
                    continue;
                for(long long int i = 0; i < G[p.first].size(); i++)
                {
                    long long int kapa = p.second + G[p.first][i].second;
                    if(kapa < V[G[p.first][i].first])
                    {
                        V[G[p.first][i].first] = kapa;
                        Q.push(make_pair(G[p.first][i].first, kapa));
                    }
                }
            }
        }
    }
    else
    {
        for(long long int i = 0; i < V.size(); i++)
            V[i] = LLONG_MAX;
        V[s] = 0;
        priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int> >, Comp> Q;
        Q.push(make_pair(s, 0));
        while(!Q.empty())
        {
            pair<long long int, long long int> p = Q.top();
            Q.pop();
            if(p.second > V[p.first])
                continue;
            for(long long int i = 0; i < G[p.first].size(); i++)
            {
                long long int kapa = p.second + G[p.first][i].second;
                if(kapa < V[G[p.first][i].first])
                {
                    V[G[p.first][i].first] = kapa;
                    Q.push(make_pair(G[p.first][i].first, kapa));
                }
            }
        }
        long long int napa = LLONG_MAX, napaI = 0;
        for(long long int i = 0; i < k; i++)
        {
            if(napa > V[i])
            {
                napa = V[i];
                napaI = i;
            }
        }
        queue<pair<long long int, long long int> > kapaQ;
        for(long long int i = 0; i < k; i++)
        {
            if(V[i] >= napa + x)
            {
                V[i] = napa + x;
            }
            if(i != napaI)
                kapaQ.push(make_pair(i, V[i]));
        }
        while(!kapaQ.empty())
        {
            Q.push(kapaQ.front());
            kapaQ.pop();
            while(!Q.empty())
            {
                pair<long long int, long long int> p = Q.top();
                Q.pop();
                if(p.second > V[p.first])
                    continue;
                for(long long int i = 0; i < G[p.first].size(); i++)
                {
                    long long int kapa = p.second + G[p.first][i].second;
                    if(kapa < V[G[p.first][i].first])
                    {
                        V[G[p.first][i].first] = kapa;
                        Q.push(make_pair(G[p.first][i].first, kapa));
                    }
                }
            }
        }
    }
}

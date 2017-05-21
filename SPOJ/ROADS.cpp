#include <bits/stdc++.h>

using namespace std;

using Point = pair<int, pair<int, int> >;

int djikstra(vector<list<Point > > &G, int k);

bool comp(const Point &a, const Point &b)
{ return a.second.first > b.second.first; }

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int k, n, r;
        cin >> k >> n >> r;
        vector<list<Point > > G(n);
        for(int i = 0; i < r; i++)
        {
            int a, b, l, ti;
            cin >> a >> b >> l >> ti;
            a--, b--;
            if(a == b)
                continue;
            G[a].push_back(make_pair(b, make_pair(l, ti)));
        }
        if(k == 0)
        {
            cout << -1 << endl;
            continue;
        }
        cout << djikstra(G, k) << endl;
    }
    return 0;
}

int djikstra(vector<list<Point > > &G, int k)
{
    vector<vector<int> > dist(G.size(), vector<int>(k + 1, INT_MAX));
    for(int i = 0; i <dist[0].size(); i++)
        dist[0][i] = 0;
    priority_queue<Point, vector<Point>, bool (*)(const Point &, const Point &)> Q(comp);
    Q.push(make_pair(0, make_pair(0, 0)));
    while(!Q.empty())
    {
        pair<int, pair<int, int> > kapa = Q.top();
        Q.pop();
        for(list<Point>::iterator i = G[kapa.first].begin(); i != G[kapa.first].end(); i++)
        {
            int coin = kapa.second.second + i->second.second;
            if(coin > k)
                continue;
            if(dist[i->first][coin] > kapa.second.first + i->second.first)
            {
                dist[i->first][coin] = kapa.second.first + i->second.first;
                Q.push(make_pair(i->first, make_pair(dist[i->first][coin], coin)));
            }
        }
    }
    //for(int i = 0; i < dist.size(); i++)
    //{
        //for(int j = 0; j < dist[i].size(); j++)
        //{
            //cout << dist[i][j] << ' ';
        //}
        //cout << endl;
    //}
    int kapa = *min_element(dist[G.size() - 1].begin(), dist[G.size() - 1].end());
    if(kapa == INT_MAX)
        return -1;
    return kapa;
}

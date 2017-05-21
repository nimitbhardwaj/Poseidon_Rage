#include <bits/stdc++.h>

using namespace std;

pair<int, int> bfs(vector<list<int> > &G, int k);

int main()
{
    int E;
    cin >> E;
    vector<list<int> > G(E);
    for(int i = 0; i < E; i++)
    {
        int n;
        cin >> n;
        for(int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            G[i].push_back(a);
        }
    }
    int m;
    cin >> m;
    while(m--)
    {
        int k;
        cin >> k;
        pair<int, int> kapa = bfs(G, k);
        if(kapa.first == 0)
            cout << 0 << endl;
        else
            cout << kapa.first << ' ' << kapa.second << endl;
    }
    return 0;
}

pair<int, int> bfs(vector<list<int> > &G, int k)
{
    queue<int> Q;
    vector<bool> visi(G.size(), false);
    Q.push(k);
    visi[k] = true;
    Q.push(-1);
    int day = 0, bloom = 0;
    pair<int, int> mxy = make_pair(0, 0);
    while(!Q.empty())
    {
        int kapa = Q.front();
        Q.pop();
        if(kapa == -1)
        {
            day++;
            if(mxy.first < bloom)
                mxy.first = bloom, mxy.second = day;
            bloom = 0;
            if(Q.empty())
                break;
            Q.push(-1);
            continue;
        }
        for(list<int>::iterator i = G[kapa].begin(); i != G[kapa].end(); i++)
        {
            if(!visi[*i])
            {
                visi[*i] = true;
                bloom++;
                Q.push(*i);
            }
        }
    }
    return mxy;
}

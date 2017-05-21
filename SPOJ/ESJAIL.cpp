#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<list<int> > &G, vector<int> &key, vector<int> &door);

int main()
{
    int n, k, m;
    while(cin >> n >> k >> m && n != -1 && k != -1 && m != -1)
    {
        vector<int> door(n, -1);
        vector<int> key(n, -1);
        vector<list<int> > G(n);
        for(int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            key[a] = b;
            door[b] = a;
        }
        for(int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        if(bfs(G, key, door))
            cout << 'Y' << endl;
        else
            cout << 'N' << endl;
    }
    return 0;
}

bool bfs(vector<list<int> > &G, vector<int> &key, vector<int> &door)
{
    vector<bool> visi(G.size(), false);
    vector<bool> unlock(G.size(), false);
    vector<bool> need(G.size(), false);
    queue<int> Q;
    Q.push(0);
    visi[0] = true;
    while(!Q.empty())
    {
        int kapa = Q.front();
        Q.pop();
        for(list<int>::iterator i = G[kapa].begin(); i != G[kapa].end(); i++)
        {
            if(!visi[*i])
            {
                visi[*i] = true;
                if(key[*i] != -1)
                {
                    unlock[key[*i]] = true;
                    if(need[key[*i]])
                        Q.push(key[*i]);
                    Q.push(*i);
                }
                else if(door[*i] != -1)
                {
                    if(unlock[*i])
                        Q.push(*i);
                    else
                        need[*i] = true;
                }
                else
                    Q.push(*i);
            }
        }
    }
    return visi[G.size() - 1];
}

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int> > &G, vector<int> &protection, int k, int s);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, r, m;
        cin >> n >> r >> m;
        vector<vector<int> > G(n, vector<int>());
        for(int i = 0; i < r; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        vector<int> protection(n, 0);
        for(int i = 0; i < m; i++)
        {
            int k, s;
            cin >> k >> s;
            k--;
            bfs(G, protection, k, s);
        }
        bool check = true;
        for(int i = 0; i < n; i++)
        {
            if(protection[i] != 1)
            {
                check = false;
                break;
            }
        }
        if(check)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

void bfs(vector<vector<int> > &G, vector<int> &protection, int k, int s)
{
    queue<int> Q;
    Q.push(k);
    Q.push(-1);
    int level = 0;
    vector<bool> visited(protection.size(), false);
    while(!Q.empty() && level != s + 1)
    {
        int a =  Q.front();
        Q.pop();
        if(a == -1)
        {
            Q.push(-1);
            level++;
            continue;
        }
        if(visited[a] == true)
            continue;
        visited[a] = true;
        protection[a] += 1;
        for(int i = 0; i < G[a].size(); i++)
        {
            if(visited[G[a][i]])
                continue;
            Q.push(G[a][i]);
        }
    }
}

#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<char> > &G, int sx, int sy, int fx, int fy);
bool saiyanFlash(vector<vector<char> > &G, vector<vector<int> > &V, pair<int, int>);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        int sx, sy, fx, fy;
        cin >> n >> m;
        vector<vector<char> > G(n, vector<char>(m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> G[i][j];
                if(G[i][j] == 'S')
                    sx = i, sy = j;
                if(G[i][j] == 'F')
                    fx = i, fy = j;
            }
        }
        cout << bfs(G, sx, sy, fx, fy) << endl;
    }
    return 0;
}

int bfs(vector<vector<char> > &G, int sx, int sy, int fx, int fy)
{
    queue<pair<int, int> > Q;
    vector<vector<int> > V(G.size(), vector<int>(G[0].size(), INT_MAX));
    Q.push(make_pair(sx, sy));
    V[sx][sy] = 0;
    while(!Q.empty())
    {
        pair<int, int> kapa = Q.top();
        Q.pop();
        if(saiyanFlash(G, V, kapa)) return V[fx][fy];
    }
}

bool saiyanFlash(vector<vector<char> > &G, vector<vector<int> > &V, pair<int, int> p)
{
    for(int i = p.first + 1; i < G.size(); i++)
    {
        if(G[i][p.second] == '*')
            break;
        else if(G[i][p.second] == 'F')
        {
            V[i][p.second] = V[p.first][p.second] + 1;
            return true;
        }
        else
            V[i][p.second] = V[p.first][p.second] + 1;
    }
    for(int i = p.first - 1; i >= 0; i--)
    {
        if(G[i][p.second] == '*')
            break;
        else if(G[i][p.second] == 'F')
        {
            V[i][p.second] = V[p.first][p.second] + 1;
            return true;
        }
        else
            V[i][p.second] = V[p.first][p.second] + 1;
    }
    for(int i = p.second + 1; i < G[0].size(); i++)
    {
        if(G[p.first][i] == '*')
            break;
        else if(G[p.first][i] == 'F')
        {
            V[p.first][i] = V[p.first][p.second] + 1;
            return true;
        }
        else
            V[p.first][i] = V[p.first][p.second] + 1;
    }
    for(int i = p.second - 1; i >= G[0].size(); i--)
    {
        if(G[p.first][i] == '*')
            break;
        else if(G[p.first][i] == 'F')
        {
            V[p.first][i] = V[p.first][p.second] + 1;
            return true;
        }
        else
            V[p.first][i] = V[p.first][p.second] + 1;
    }
    for(int i = p.first + 1, j = p.second + 1; i < G.size() && j < G[0].size(); i++, j++)
    {
        if(G[i][j] == '*')
            break;
        else if(G[i][j] == 'F')
        {
            V[i][j] = V[p.first][p.second] + 1;
            return true;
        }
        else
            V[i][j] = V[p.first][p.second] + 1;
    }
}

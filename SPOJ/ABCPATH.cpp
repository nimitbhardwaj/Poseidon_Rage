#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<char> > &, pair<int, int>, vector<vector<bool> > &);

struct Block
{
    int x, y, depth;
    Block(int a, int b, int c)
        :x(a), y(b), depth(c) {}
};

int main()
{
    int k = 1;
    int a, b;
    cin >> a >> b;
    while(a != 0 && b != 0)
    {
        vector<vector<char> > V(a, vector<char>(b, 0));
        stack<pair<int, int> > S;
        for(int i = 0; i < V.size(); i++)
        {
            for(int j = 0; j < V[0].size(); j++)
            {
                cin >> V[i][j];
                if(V[i][j] == 'A')
                    S.push(make_pair(i, j));
            }
        }
        int maxy = 0;
        vector<vector<bool> > visited(a, vector<bool>(b, false));
        bool napa = false;
        while(!S.empty())
        {
            napa = true;
            pair<int, int> tmp = S.top();
            S.pop();
            visited[tmp.first][tmp.second] = true;
            maxy = max(maxy, dfs(V, tmp, visited));
        }
        if(napa == false)
            maxy = -1;
        cout << "Case " << k << ": " << maxy + 1<< endl;
        cin >> a >> b;
        k++;
    }
    return 0;
}

int dfs(vector<vector<char> > &V, pair<int, int> pos, vector<vector<bool> > &visited)
{
    stack<Block> S;
    S.push(Block(pos.first, pos.second, 0));
    int alpha[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int beta[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int maxy = 0;
    while(!S.empty())
    {
        Block kapa = S.top();
        S.pop();
        for(int i = 0; i < 8; i++)
        {
            try
            {
                if(V.at(kapa.x + alpha[i]).at(kapa.y + beta[i]) == V.at(kapa.x).at(kapa.y) + 1 && !visited[kapa.x + alpha[i]][kapa.y + beta[i]])
                {
                    S.push(Block(kapa.x + alpha[i], kapa.y + beta[i], kapa.depth + 1));
                    visited[kapa.x +  alpha[i]][kapa.y + beta[i]] = true;
                    maxy = max(maxy, kapa.depth + 1);
                }
            }
            catch (out_of_range &e) {}
        }
    }
    return maxy;
}

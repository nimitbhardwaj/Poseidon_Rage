#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int> > &sol, vector<vector<int> > &V, int, int);

struct Node
{
    int dist, x, y;
    Node(int a, int b, int c)
        :x(a), y(b), dist(c){}
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > V(n, vector<int>(m, 0));
        vector<vector<int> > sol(n, vector<int>(m, INT_MAX));
        int a, b;
        string S;
        for(int i = 0; i < n; i++)
        {
            cin >> S;
            for(int j = 0; j < m; j++)
            {
                V[i][j] = S[j] - '0';
                if(V[i][j])
                    a = i, b = j;
            }
        }
        //for(int i = 0; i < n; i++)
        //{
            //for(int j = 0; j < m; j++)
                //cout << V[i][j];
            //cout << endl;
        //}
        bfs(sol, V, a, b);
        for(int i = 0; i < sol.size(); i++)
        {
            for(int j = 0; j < sol[0].size(); j++)
                cout << sol[i][j] << ' ';
            cout << endl;
        }
    }
    return 0;
}

void bfs(vector<vector<int> > &sol, vector<vector<int> > &V, int a, int b)
{
    queue<Node> Q;
    Q.push(Node(a, b, 0));
    int alpha[4] = {1, 0, -1, 0};
    int beta[4] =  {0, -1, 0, 1};
    while(!Q.empty())
    {
        //cout << "hellA";
        Node kapa = Q.front();
        Q.pop();
        if(kapa.dist < sol[kapa.x][kapa.y])
        {
            int dist = kapa.dist;
            sol[kapa.x][kapa.y] = kapa.dist;
            if(V[kapa.x][kapa.y] == 1)
                sol[kapa.x][kapa.y] = 0, dist = 0;
            for(int i = 0; i < 4; i++)
            {
                int x = kapa.x + alpha[i];
                int y = kapa.y + beta[i];
                if(x < 0 || y < 0 || x >= V.size() || y > V[0].size())
                    continue;
                Q.push(Node(x, y, dist + 1));
            }
        }
    }
}

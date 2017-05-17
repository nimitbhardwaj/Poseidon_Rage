#include <bits/stdc++.h>

using namespace std;

struct Cell
{
    int x, y, time;
    Cell(int a, int b, int c)
        :x(a), y(b), time(c){}
};

bool comp(const Cell &a, const Cell &b)
{ return a.time > b.time; }

int djikstra(vector<vector<char> > &V, int sx, int sy, int dx, int dy);


int main()
{
    int r, c;
    while(cin >> c >> r && c != 0 && r != 0)
    {
        vector<vector<char> > V(r, vector<char>(c, 0));
        int sx, sy, dx, dy;
        getchar();
        for(int i = 0; i < r; i++)
        {
            char ch;
            int j = 0;
            while((ch = getchar()) != '\n')
            {
                V[i][j] = ch;
                if(ch == 'S')
                    sx = i, sy = j;
                if(ch == 'D')
                    dx = i, dy = j;
                j++;
            }
        }
        cout << djikstra(V, sx, sy, dx, dy) << endl;
    }
    return 0;
}

int djikstra(vector<vector<char> > &V, int sx, int sy, int dx, int dy)
{
    vector<vector<int> > dist(V.size(), vector<int>(V[0].size(), INT_MAX));
    dist[sx][sy] = 0;
    priority_queue<Cell, vector<Cell>, bool (*)(const Cell &, const Cell &)> Q(comp);
    Q.push(Cell(sx, sy, 0));
    int alpha[4] = {0, 0, 1, -1}, beta[4] = {1, -1, 0, 0};
    while(!Q.empty())
    {
        Cell kapa = Q.top();
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            try
            {
                int x = kapa.x + alpha[i], y = kapa.y + beta[i];
                if(V.at(x).at(y) == 'D')
                    return kapa.time;
                if(V[x][y] != 'S' && V[x][y] != 'X')
                {
                    if(dist[x][y] > dist[kapa.x][kapa.y] + V[x][y] - '0')
                    {
                        dist[x][y] = dist[kapa.x][kapa.y] + V[x][y] - '0';
                        Q.push(Cell(x, y, dist[x][y]));
                    }
                }
            }catch(exception &e){}
        }
    }
    return -1;
}

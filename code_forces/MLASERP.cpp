#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <climits>

using namespace std;

int bfs(vector<vector<char> > &, int, int, int, int);
inline int absolute(int a) { return a < 0 ? -a : a; }

struct Position
{
    int x, y;
    Position(int a, int b)
        :x(a), y(b) {}
};


int main()
{
    int r, c;
    int c1x, c1y, c2x, c2y, count = 0;
    cin >> r >> c;
    vector<vector<char> > V(r, vector<char> (c, 0));
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            char tmp;
            cin >> tmp;
            if(tmp == 'S')
            {
                c1x = i;
                c1y = j;
                count++;
            }
            else if(tmp == 'T')
            {
                c2x = i;
                c2y = j;
            }
            V[i][j] = tmp;
        }
    }
    if(bfs(V, c1x, c1y, c2x, c2y) <= 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}

int bfs(vector<vector<char> > &V, int c1x, int c1y, int c2x, int c2y)
{
    vector<vector<int> > dist(V.size(), vector<int>(V[0].size(), INT_MAX));
    queue<Position> Q;
    dist[c1x][c1y] = 0;
    Q.push(Position(c1x, c1y));
    int kapa = 0;
    while(!Q.empty())
    {
        kapa++;
        Position p = Q.front();
        int a = p.x, b = p.y;
        int i = a, j = b;
        int maxy = 0;
        while(i + 1 < V.size() && V[i + 1][j] != '*')
        {
            if(dist[i + 1][j] > dist[a][b] + 1)
            {
                Q.push(Position(i + 1, j));
                int napa = dist[i + 1][j] = dist[a][b] + 1;
                maxy = max(napa, maxy);
            }
            i++;
        }
        i = a;

        while(i - 1 >= 0 && V[i - 1][j] != '*')
        {
            if(dist[i - 1][j] > dist[a][b] + 1)
            {
                Q.push(Position(i - 1, j));
                int napa = dist[i - 1][j] = dist[a][b] + 1;
                maxy = max(napa, maxy);
            }
            i--;
        }
        i = a;

        while(j + 1 < V[0].size() && V[i][j + 1] != '*')
        {
            if(dist[i][j + 1] > dist[a][b] + 1)
            {
                Q.push(Position(i, j + 1));
                int napa = dist[i][j + 1] = dist[a][b] + 1;
                maxy = max(napa, maxy);
            }
            j++;
        }
        j = b;

        while(j - 1 >= 0 && V[i][j - 1] != '*')
        {
            if(dist[i][j - 1] > dist[a][b] + 1)
            {
                Q.push(Position(i, j - 1));
                int napa = dist[i][j - 1] = dist[a][b] + 1;
                maxy = max(napa, maxy);
            }
            j--;
        }
        j = b;

        Q.pop();
    }
    return dist[c2x][c2y] - 1;
}

#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x, y, z;
    Point(int a, int b, int c)
        :x(a), y(b), z(c){}
};

int bfs(vector<vector<string> > &V, int sx, int sy, int sz, int ex, int ey, int ez);

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int sx, sy, sz, ex, ey, ez;
    while(a != 0 && b != 0 && c != 0)
    {
        vector<vector<string> > V(a, vector<string>(b));
        for(int i = 0; i < a; i++)
        {
            for(int j = 0; j < b; j++)
            {
                cin >> V[i][j];
                size_t kapa = V[i][j].find('S');
                if(kapa != string::npos)
                    sz = i, sx = j, sy = kapa;
                size_t napa = V[i][j].find('E');
                if(napa != string::npos)
                    ez = i, ex = j, ey = napa;
            }
        }
        int ans = bfs(V, sx, sy, sz, ex, ey, ez);
        if(ans == -1)
            cout << "Trapped!" << endl;
        else
            cout << "Escaped in " << ans << " minute(s)." << endl;
        cin >> a >> b >> c;
    }
    return 0;
}

int bfs(vector<vector<string> > &V, int sx, int sy, int sz, int ex, int ey, int ez)
{
    queue<Point> Q;
    vector<vector<vector<bool> > > visi(V.size(), vector<vector<bool> >(V[0].size(), vector<bool>(V[0][0].size(), false)));
    Q.push(Point(sx, sy, sz));
    visi[sz][sx][sy] = true;
    Q.push(Point(-1, -1, -1));
    int T = 0;
    int alpha[6] = {1, -1, 0, 0, 0, 0}, beta[6] = {0, 0, 1, -1, 0, 0}, gamma[6] = {0, 0, 0, 0, 1, -1};
    while(!Q.empty())
    {
        Point kapa = Q.front();
        Q.pop();
        if(kapa.x == -1)
        {
            if(Q.empty())
                break;
            T++;
            Q.push(Point(-1, -1, -1));
            continue;
        }
        for(int i = 0; i < 6; i++)
        {
            try
            {
                int x = kapa.x + alpha[i], y = kapa.y + beta[i], z = kapa.z + gamma[i];
                if(!visi.at(z).at(x).at(y) && V[z][x][y] != '#')
                {
                    visi[z][x][y] = true;
                    Q.push(Point(x, y, z));
                    if(x == ex && y == ey && z == ez)
                        return T + 1;
                }
            }
            catch(exception &e){}
        }
    }
    return -1;
}

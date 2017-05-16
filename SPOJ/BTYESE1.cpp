#include <bits/stdc++.h>

using namespace std;

int djikstra(vector<vector<int> > &V, int a, int b, int T);

struct Room
{
    int x, y, dist;
    Room(int a, int b, int c)
        :x(a), y(b), dist(c){}
};

bool lessey(const Room &a, const Room &b) { return a.dist > b.dist; }


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int> > V(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> V[i][j];
            }
        }
        int a, b, T;
        cin >> a >> b >> T;
        a--;
        b--;
        int kapa = djikstra(V, a, b, T);
        if(kapa == -1)
            cout << "NO" << endl;
        else
            cout << "YES" << '\n' << kapa << endl;
    }
    return 0;
}

int djikstra(vector<vector<int> > &V, int a, int b, int T)
{
    vector<vector<int> > dist(V.size(), vector<int>(V[0].size(), INT_MAX));
    dist[0][0] = V[0][0];
    priority_queue<Room, vector<Room>, bool (*)(const Room &, const Room &)> Q(lessey);
    Q.push(Room(0, 0, V[0][0]));
    int alpha[4] = {1, -1, 0, 0}, beta[4] = {0, 0, -1, 1};
    while(!Q.empty())
    {
        Room kapa = Q.top();
        Q.pop();
        //cout << "kapa" << kapa.dist << endl;
        for(int i = 0; i < 4; i++)
        {
            try
            {
                int x = kapa.x + alpha[i], y = kapa.y + beta[i];
                if(dist.at(x).at(y) > kapa.dist + V[x][y])
                {
                    dist[x][y] = kapa.dist + V[x][y];
                    Q.push(Room(x, y, dist[x][y]));
                }
            }
            catch(exception &e){}
        }
    }
    if(dist[a][b] > T)
        return -1;
    else
        return T - dist[a][b];
}

#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x, y, pow;
    Point(int a, int b, int c)
        :x(a), y(b), pow(c){}
    Point(){}
};

bool comp(const Point &a, const Point &b) { return a.pow > b.pow; }

int djikstra(const vector<vector<int> > &V, int x, int y);

int main()
{
    int r, c;    
    cin >> r >> c;
    int x, y;
    cin >> x >> y;
    x--, y--;
    vector<vector<int> > V(r, vector<int> (c, 0));
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> V[i][j];
    int kapa = djikstra(V, x, y);
    if(kapa < 0)
        cout << "N" << endl;
    else
        cout << "Y " << kapa << endl;
    return 0;   
}

int djikstra(const vector<vector<int> > &V, int x, int y)
{
    vector<vector<int> > dist(V.size(), vector<int>(V[0].size(), INT_MAX));
    dist[x][y] = 0;
    priority_queue<Point, vector<Point>, bool (*)(const Point &, const Point &)> Q(comp);
    Q.push(Point(x, y, 0));
    int alpha[2] = {0, 1}, beta[2] = {1, 0};
    while(!Q.empty())
    {
        Point kapa = Q.top();
        Q.pop();
        for(int i = 0; i < 2; i++)
        {
            try
            {
                int A = alpha[i] + kapa.x, B = beta[i] + kapa.y;
                if(dist.at(A).at(B) > kapa.pow + V[A][B])
                {
                    dist[A][B] = kapa.pow + V[A][B];
                    Q.push(Point(A, B, dist[A][B]));
                    if(A == V.size() - 1 && B == V[0].size() - 1)
                        return V[x][y] - dist[A][B];
                }
            }
            catch(exception &e){}
        }
    }
    return V[x][y] - dist[V.size() - 1][V[0].size() - 1];
}

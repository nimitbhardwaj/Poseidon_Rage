#include <bits/stdc++.h>

using namespace std;

int djikstra(int, int, int, int);

struct Point
{
    int x, y, dist;
    Point(int a, int b, int c)
        :x(a), y(b), dist(c){}
    Point()
        :x(0), y(0), dist(0){}
    bool operator() (const Point &a, const Point &b)
    { return a.dist > b.dist; }
};

int main()
{
    int a, b, c, d;
    while(cin >> a >> b >> c >> d)
        cout << djikstra(a, b, c, d) << endl;
    return 0;
}

int djikstra(int a, int b, int c, int d)
{
    vector<vector<int> > dist(8, vector<int>(8, INT_MAX));
    dist[a][b] = 0;
    priority_queue<Point, vector<Point>, Point> Q;
    int alpha[8] = {2, 2, 1, -1, -2, -2, -1, 1}, beta[8] = {1, -1, -2, -2, -1, 1, 2, 2};
    Q.push(Point(a, b, 0));
    while(!Q.empty())
    {
        Point kapa = Q.top();
        Q.pop();
        for(int i = 0; i < 8; i++)
        {
            try
            {
                if(dist.at(kapa.x + alpha[i]).at(kapa.y + beta[i]) > kapa.dist + kapa.x * (kapa.x + alpha[i]) + kapa.y * (kapa.y + beta[i]))
                {
                    dist[kapa.x + alpha[i]][kapa.y + beta[i]] = kapa.dist +  kapa.x * (kapa.x + alpha[i]) + kapa.y * (kapa.y + beta[i]);
                    Q.push(Point(kapa.x + alpha[i], kapa.y + beta[i], dist[kapa.x + alpha[i]][kapa.y + beta[i]]));
                }
            }
            catch(exception &e){}
        }
    }
    return dist[c][d];
}

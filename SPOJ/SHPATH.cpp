#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <climits>

using namespace std;

using Graph = vector<vector<pair<int, int> > >;

class Comp
{
    public:
        bool operator()(const pair<int, int> &a, const pair<int, int> &b)
        { return a.second >= b.second; }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        Graph G(n, vector<pair<int, int> >())
        for(int i = 0; i < n; i++)
        {
            string tmp;
            cin >> tmp;
            int m;
            cin >> m;
            for(int j = 0; j < m; j++)
            {
                int kapa, c;
                cin >> kapa >> c;
                kapa--;
                G[i].push_back(make_pair(kapa, c));
            }
        }
        priority_queue<pair<int, int>, vector<int>, Comp> Q;
        vector<bool> visited(n, false);
        vector<int> minDist(n, INT_MAX);
    }
    return 0;
}

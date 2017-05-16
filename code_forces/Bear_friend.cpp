#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Graph
{
    private:
        vector<vector<int> > grp;
        int nVer, nEdg;
    public:
        Graph(int ver)
            :nVer(ver), nEdg(0)
        { grp = vector<vector<int> >(nVer, vector<int>()); }
        void addVertex(int a, int b);
        pair<int, int> bfs(vector<bool> &, int i);
};

int main()
{
    int m, n;
    cin >> n >> m;
    Graph G(n);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G.addVertex(a, b);
    }
    vector<bool> visited(n, false);
    vector<pair<int, int> > newGraphs;
    for(int i = 0; i < visited.size(); i++)
    {
        if(visited[i] == false)
        {
            newGraphs.push_back(G.bfs(visited, i));
        }
    }
    bool check = true;
    for(int i = 0; i < newGraphs.size(); i++)
    {
        if((newGraphs[i].first * (newGraphs[i].first - 1)) != newGraphs[i].second)
        {
            check = false;
        }
    }
    if(check == false)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}

void Graph::addVertex(int a, int b)
{
    grp[a].push_back(b);
    grp[b].push_back(a);
    nEdg += 1;
}

pair<int, int> Graph::bfs(vector<bool> &V, int i)
{
    V[i] = true;
    queue<int> Q;
    Q.push(i);
    pair<int, int> P = make_pair(1, grp[i].size());
    while(!Q.empty())
    {
        int kapa = Q.front();
        Q.pop();
        for(int j = 0; j < grp[kapa].size(); j++)
        {
            if(V[grp[kapa][j]] == false)
            {
                Q.push(grp[kapa][j]);
                V[grp[kapa][j]] = true;
                P.first += 1;
                P.second += grp[grp[kapa][j]].size();
            }
        }
    }
    return P;
}

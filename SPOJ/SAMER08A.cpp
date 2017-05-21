#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int x, cost;
    Node (int a, int c)
        :x(a), cost(c){}
};

bool comp(const Node &a, const Node &b)
{ return a.cost < b.cost; }

void deleteShortestPath(vector<vector<int> > &G, int s, int e);
int djikstra(vector<vector<int> > &G, int s, int e);

int main()
{
    int n, m;
    int u, v, p;
    int start, end;
    while(cin >> n >> m && n != 0 && m != 0)
    {
        vector<vector<int> > G(n, vector<int> (n, 0));
        cin >> start >> end;
        for(int i = 0; i < m; i++)
        {
            cin >> u >> v >> p;
            G[u][v] = p;
        }
        deleteShortestPath(G, start, end);
        cout << djikstra(G, start, end) << endl;
    }
}

void deleteShortestPath(vector<vector<int> > &G, int s, int e)
{
    priority_queue<Node, vector<Node>, bool(*)(const Node &, const Node &)> Q(comp);
    vector<int> dist(G.size(), INT_MAX);
    Q.push(Node(s, 0));
    dist[s] = 0;
    vector<int> tree(G.size(), -1);
    tree[s] = -1;
    vector<int> destiny;
    while(!Q.empty())
    {
        Node kapa = Q.top();
        Q.pop();
        for(vector<int>::iterator i = G[kapa.x].begin(); i != G[kapa.x].end(); i++)
        {
            if(*i == 0)
                continue;
            if(dist[i - G[kapa.x].begin()] > kapa.cost + *i)
            {
                dist[i - G[kapa.x].begin()] = kapa.cost + *i;
                tree[i - G[kapa.x].begin()] = kapa.x;
                Q.push(Node(i - G[kapa.x].begin(), dist[i - G[kapa.x].begin()]));
            }
            int napa = i - G[kapa.x].begin();
            if(dist[napa] == kapa.cost + *i && napa == e)
                destiny.push_back(kapa.x);
        }
    }
    for(vector<int>::iterator i = destiny.begin(); i != destiny.end(); i++)
    {
        int k = *i, k2 = e;
        if(dist[*i] + G[*i][e] != dist[e])
            continue;
        while(k != -1)
        {
            G[k][k2] =  0;
            k2 = k;
            k = tree[k];
        }
    }
    //for(int i = 0; i < G.size(); i++)
    //{
        //for(int j = 0; j < G[0].size(); j++)
            //cout << G[i][j] << ' ';
        //cout << endl;
    //}
}

int djikstra(vector<vector<int> > &G, int s, int e)
{
    priority_queue<Node, vector<Node>, bool (*)(const Node &, const Node &)> Q(comp);
    vector<int> dist(G.size(), INT_MAX);
    Q.push(Node(s, 0));
    dist[s] = 0;
    while(!Q.empty())
    {
        Node kapa = Q.top();
        Q.pop();
        for(int i = 0; i < G.size(); i++)
        {
            if(G[kapa.x][i] == 0)
                continue;
            if(dist[i] > kapa.cost + G[kapa.x][i])
            {
                dist[i] = kapa.cost + G[kapa.x][i];
                Q.push(Node(i, dist[i]));
            }
        }
    }
    return dist[e] == INT_MAX ? -1 : dist[e];
}

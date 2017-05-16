#include <bits/stdc++.h>

using namespace std;

bool isTree(vector<vector<int> > &G);

struct Node
{
    int x, prev;
    Node(int a, int b)
        :x(a), prev(b){}
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > G(n);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    if(isTree(G))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}

bool isTree(vector<vector<int> > &G)
{
    vector<bool> visited(G.size(), false);
    stack<Node> S;
    S.push(Node(0, -1));
    while(!S.empty())
    {
        Node k = S.top();
        S.pop();
        visited[k.x] = true;
        for(int i = 0; i < G[k.x].size(); i++)
        {
            if(G[k.x][i] == k.prev)
                continue;
            if(visited[G[k.x][i]])
                return false;
            visited[G[k.x][i]] = true;
            S.push(Node(G[k.x][i], k.x));
        }
    }
    return true;
}

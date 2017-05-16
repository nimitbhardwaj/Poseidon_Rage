#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>


class Graph
{
    public:
        int V;
        std::list<int> adj[50001];
        Graph(int v);
        void addEdge(int u, int v) { adj[u].push_back(v), adj[v].push_back(u); }
        int bfs(int, const std::vector<std::pair<int, int> > &);
};


Graph::Graph(int v)
{
    V = v;
    for(int i = 0; i < 50001; i++)
        adj[i] = 0;
}

int Graph::bfs(int n, const std::vector<std::pair<int, int> > &planets)
{
    std::queue<std::pair<int, int> > Q;
    Q.push(planets[n]);
    bool visited[50000];
    visited[n] = true;
    std::list<int>::iterator i;
    int kapa = 0, mode = 0;
    std::pair<int, int> max;
    max.first = -1, max.second = 0;
    while(!Q.empty())
    {
        std::pair<int, int> cksum = Q.front();
        int k = cksum.first;
        //std::cout << "Poseidon: " << k << std::endl;
        Q.pop();
        if(k == -1)
        {
            mode = 1;
            kapa++;
            continue;
        }
        if(mode == 1)
        {
            if(max.second < cksum.second)
                max = cksum;
        }
        for(i = adj[k].begin(); i != adj[k].end(); i++)
        {
            if(visited[*i] == false)
                Q.push(planets[*i]), visited[*i] = true;
        }
        if(kapa == 0)
            Q.push(max);
        kapa++;
    }
    return max.first;
}

int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int n;
        std::cin >> n;
        std::vector<std::pair<int, int> > planets;
        for(int i = 0; i < n; i++)
        {
            int tmp;
            std::cin >> tmp;
            std::pair<int, int> tmp_pair = std::make_pair(i, tmp);
            planets.push_back(tmp_pair);
        }
        Graph G(n);
        for(int i = 0; i < n - 1; i++)
        {
            int a, b;
            std::cin >> a >> b;
            a--, b--;
            G.addEdge(a, b);
        }
        for(int i = 0; i < n; i++)
        {
            int a = G.bfs(i, planets);
            if(a != -1)
                a++;
            std::cout << a << ' ';
        }
        std::cout << '\n';
        //for(int i = 0; i < n; i++)
            //std::cout << planets[i].first << ':' << planets[i].second << std::endl;
        
    }
    return 0;
}

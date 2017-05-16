#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <queue>
#include <climits>
struct Road
{
    int endP;
    int cost;
    bool flag;
    int originP;
};

class priority{public: bool operator()(Road &a, Road &b) { return a.cost < a.cost; }};
class Graph
{
    private:
        std::vector<std::list<Road > > adj;
        int E, V;
        std::vector<int> dist;
        std::vector<bool> visited;
    public:
        Graph(int v, int e);
        void addEdge(int a, int b, int c);
        void dijkstra(int i);
        int sum(void);
        void print(void);
};

void Graph::print(void)
{
    for(int i = 0; i < V; i++)
    {
        std::cout << i + 1 << ':' << std::endl;
        for(std::list<Road >::iterator j = adj[i].begin(); j != adj[i].end(); j++)
            std::cout << j->endP + 1 << ' ';
        std::cout << std::endl;
    }
}

Graph::Graph(int v, int e)
    :V(v), E(e)
{
    adj = std::vector<std::list<Road > >(V);
    dist = std::vector<int>(V, INT_MAX);
    visited = std::vector<bool>(V, false);
}

void Graph::addEdge(int a, int b, int c)
{
    Road alpha = {b, c, false};
    adj[a].push_back(alpha);
    alpha.endP = a;
    alpha.cost = c;
    adj[b].push_back(alpha);
}

void Graph::dijkstra(int source)
{
    //std::cout << "Hello" << std::endl;
    int ret = 0;
    Road prev;
    std::priority_queue<Road, std::vector<Road>, priority> Q;
    dist[source] = 0;
    for(int i = 0; i < V; i++)
    {
        if(i != source)
            dist[i] = INT_MAX;
        Road alpha = {i, INT_MAX, false};
        if(i == source)
            alpha.originP = -1;
        Q.push(alpha);
    }
    while(!Q.empty())
    {
        Road u = Q.top();
        Q.pop();
        ret += length(u.originP, u.endP);
        for(std::list<Road >::iterator i = adj[u.endP].begin(); i != adj[u.endP].end(); i++)
        {
            int alt = dist[u.endP] + i->cost;
            if(alt < dist[i->endP])
            {
                dist[i->endP] = alt;
                i->flag = true;
            }
        }
        prev = u;
    }
    //dist[source] = 0;
    //for(int i = 0; i < V; i++)
        //Q.push()
    //Q.push(std::make_pair(source, 0));
    //while(!Q.empty())
    //{
        //Road a = Q.top();
        //Q.pop();
        //visited[a.endP] = true;
        //for(std::list<Road >::iterator i = adj[a.endP].begin(); i != adj[a.endP].end(); i++)
        //{
            //int alt;
            //if(dist[i->endP] == INT_MAX)
                //alt = i->cost;
            //else
                //alt = i->cost + dist[i->endP];
            //std::cout << "Hello" << alt << std::endl;
            //if(!visited[i->endP] && alt < dist[i->endP])
            //{
                //dist[i->endP] = alt;
                //Q.push(std::make_pair(i->endP, alt)), visited[i->endP] = true;
            //}
        //}
    //}
    //std::cout << "Hello" << std::endl;
}

int Graph::sum(void)
{
    int ret = 0;
    for(std::vector<std::list<Road> >::iterator i = adj.begin(); i != adj.end(); i++)
    {
        for(std::list<Road>::iterator j = adj[i - adj.begin()].begin(); j != adj[i - adj.begin()].end(); j++)
            if(j->flag == true)
                ret += j->cost;
    }
    return ret;
}

int main()
{
    int v, e;
    std::cin >> v >> e;
    Graph G(v, e);
    for(int i = 0; i < e; i++)
    {
        int p, q, w;
        std::cin >> p >> q >> w;
        G.addEdge(p - 1, q - 1, w);
    }
    G.dijkstra(0);
    //G.print();
    std::cout << G.sum() << std::endl;
    return 0;
}


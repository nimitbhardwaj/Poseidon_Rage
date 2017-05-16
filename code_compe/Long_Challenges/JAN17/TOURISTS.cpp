#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stack>
#include <cstdlib>

bool P[100000];

class Graph
{
    private:
        int V;
        std::list<int> *E;
        std::stack<int> S;
        std::vector<int> tour;
    public:
        Graph(int v)
            :V(v) { E = new std::list<int> [v]; }
        void addEdge(int a, int b) { E[a].push_back(b), E[b].push_back(a); }
        void addDirectedEdge(int a, int b) { E[a].push_back(b); }
        bool isEulerian(void);
        void getTour(int, int);
        void printTour(void);
        bool isValid();
        ~Graph();
};

bool Graph::isEulerian(void)
{
    for(int i = 0; i < V; i++)
    {
        if(E[i].size() % 2 != 0)
            return false;
    }
    return true;
}

void Graph::getTour(int n, int came)
{
    std::list<int>::iterator i = E[n].begin();
    while(E[n].size())
    {
        if(*i == came)
            i = E[n].erase(i);
        else
        {
            int a = *i;
            i = E[n].erase(i);
            getTour(a, n);
        }
    }
    P[n - 1] = true;
    S.push(n);
}

void Graph::printTour(void)
{
    int a = -1;
    int b;
    while(!S.empty())
    {
        if(a == -1)
            a = S.top(), S.pop();
        else
            a = b;
        std::cout << 1 + a << ' ';
        b = S.top();
        S.pop();
        std::cout << 1 + b << std::endl;
    }
    //while(!S.empty())
        //std::cout << S.top() << std::endl, S.pop();
}

bool Graph::isValid()
{
    for(int i = 0; i < V; i++)
    {
        std::cout << P[i];
        if(P[i] == false)
            return false;
    }
    return true;
}

Graph::~Graph()
{
    delete[] E;
}

int main()
{
    int n, e;
    std::cin >> n >> e;
    Graph G(n);
    for(int i = 0; i < e; i++)
    {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        G.addEdge(a, b);
    }
    if(!G.isEulerian())
    {
        std::cout << "NO" << std::endl;
        std::exit(EXIT_SUCCESS);
    }
    else
    {
        //if(!G.isValid())
            //std::cout << "NO" << std::endl;
        //else
        {
            std::cout << "YES" << std::endl;
            G.getTour(0, -1);
            G.printTour();
        }
    }
    return 0;
}

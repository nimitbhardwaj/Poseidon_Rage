#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) { return (b % a == 0) ? a : gcd(b % a, a); }

class Tree
{
    private:
        struct Node
            int parent, gcd, info;
            vector<int> kapa;
        };
        vector<Node> V;
    public:
        Tree(int n);
        void joinNode(int a, int b);
        void setInfo(int a, int in) { V[a].info = in; }
        void makeTreeComplete(int);
};


int main()
{
    int n, q;
    cin >> n >> q;
    Tree T(n);
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        T.setInfo(i, tmp);
    }
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        T.joinNode(a, b);
    }
    return 0;
}

Tree::Tree(int n)
{
    Node dummy = {0, 0, 0, vector<int>()};
    V = vector<Node>(n, Node);
}

void Tree::joinNode(int a, int b)
{
    V[a].kapa.push_back(b);
    V[b].kapa.push_back(a);
}

void Tree::makeTreeComplete(int k)
{
    V[0].parent = -1;
    int a = V[k].info;
    for(int i = 0; i < V[k].kapa.size(); i++)
    {
        if(V[k].parent == V[k].kapa[i])
            continue;
        V[V[k].kapa[i]].parent = k;
        V[k].info = kkj;
        makeTreeComplete(V[k].kapa[i]);
    }
}

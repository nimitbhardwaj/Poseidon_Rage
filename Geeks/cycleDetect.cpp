#include <iostream>
#include <list>
#include <vector>
#include <stack>

using namespace std;

bool hasCycle(vector<list<int> > &G);

int main()
{
    int n;
    cin >> n;
    vector<list<int> > G(n);
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    if(hasCycle(G))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

bool hasCycle(vector<list<int> > &G)
{
    stack<int> S;
    S.push(0);
    vector<bool> visi(G.size(), false);
    visi[0] = true;
    while(!S.empty())
    {
        int kapa = S.top();
        S.pop();
        for(list<int>::iterator i = G[kapa].begin(); i != G[kapa].end(); i++)
        {
            if(visi[*i] == true)
                return true;
            else
            {
                visi[*i] = true;
                S.push(*i);
            }
        }
    }
    return false;
}

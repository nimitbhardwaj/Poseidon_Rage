#include <bits/stdc++.h>

using namespace std;

int bfs(vector<list<int> > &G, string &S);

int main()
{
    string S;
    cin >> S;
    vector<list<int> > G(10);
    for(int i = 0; i < S.size(); i++)
        G[S[i] - '0'].push_back(i);
    cout << bfs(G, S) << endl;
    return 0;
}

int bfs(vector<list<int> > &G, string &S)
{
    queue<int> Q;
    vector<bool> V(S.size(), false);
    V[0] = true;
    Q.push(0);
    Q.push(-1);
    int ans = 0;
    while(!Q.empty())
    {
        int kapa = Q.front();
        Q.pop();
        if(kapa == -1)
        {
            Q.push(-1);
            ans++;
            continue;
        }
        if(kapa == S.size() - 1)
            return ans;
        for(list<int>::iterator i = G[S[kapa] - '0'].begin(); i != G[S[kapa] - '0'].end(); i++)
        {
            if(!V[*i])
            {
                Q.push(*i);
                V[*i] = true;
            }
        }
        if(kapa != 0)
            if(!V[kapa - 1])
            {
                Q.push(kapa - 1);
                V[kapa - 1] = true;
            }
        if(!V[kapa + 1])
        {
            Q.push(kapa + 1);
            V[kapa + 1] = true;
        }
    }
}

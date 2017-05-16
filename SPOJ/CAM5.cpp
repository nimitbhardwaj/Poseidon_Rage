#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int> > &G, vector<bool> &visited, int k);

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        vector<vector<int> > G(n, vector<int>());
        int e;
        scanf("%d", &e);
        for(int i = 0; i < e; i++)
        {
            int tmp1, tmp2;
            scanf("%d %d", &tmp1, &tmp2);
            G[tmp1].push_back(tmp2);
            G[tmp2].push_back(tmp1);
        }
        vector<bool> visited(n, false);
        int kapa = 0;
        for(int i = 0; i < n; i++)
        {
            if(visited[i] == false)
            {
                dfs(G, visited, i);
                kapa++;
            }
        }
        printf("%d\n", kapa);
    }
    return 0;
}

void dfs(vector<vector<int> > &G, vector<bool> &visited, int k)
{
    stack<int> S;
    S.push(k);
    while(!S.empty())
    {
        int a = S.top();
        S.pop();
        visited[a] = true;
        for(int i = 0; i < G[a].size(); i++)
            if(!visited[G[a][i]])
                S.push(G[a][i]);
    }
}

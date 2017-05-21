#include <bits/stdc++.h>
#define MAX 10000000

using namespace std;

void floydWarshall(vector<vector<int> > &G, vector<vector<int> > &dist);

int main()
{
    int n;
    while(cin >> n && n != 0)
    {
        vector<vector<int> > G(n, vector<int>(n, 0));
        vector<vector<int> > dist(n, vector<int>(n, MAX));
        int c;
        while(cin >> c && c != 0)
        {
            c--;
            int a;
            while(cin >> a && a != 0)
            {
                a--;
                G[c][a] = 1;
            }
        }
        floydWarshall(G, dist);
        int napa;
        cin >> napa;
        for(int i = 0; i < napa; i++)
        {
            int beta;
            cin >> beta;
            beta--;
            vector<int> kapa;
            for(int i = 0; i < G.size(); i++)
            {
                if(dist[beta][i] == MAX)
                {
                    kapa.push_back(i + 1);
                }
            }
            cout << kapa.size();
            for(int i = 0; i < kapa.size(); i++)
                cout << ' ' << kapa[i];
            cout << endl;
        }
    }
    return 0;
}

void floydWarshall(vector<vector<int> > &G, vector<vector<int> > &dist)
{
    for(int i = 0; i < G.size(); i++)
        for(int j = 0; j < G[0].size(); j++)
            if(G[i][j] != 0)
                dist[i][j] = G[i][j];
    for(int k = 0; k < G.size(); k++)
    {
        for(int i = 0; i < G.size(); i++)
        {
            for(int j = 0; j < G.size(); j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

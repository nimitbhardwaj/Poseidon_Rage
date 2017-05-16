#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

void floydWarshall(vector<vector<int> > &, int);

int main()
{
    int a = 1, b = 1;
    cout.precision(3);
    int k = 0;
    while(cin >> a >> b && a != 0 && b != 0)
    {
        k++;
        int maxy = 0;
        vector<vector<int> > G(100, vector<int>(100, MAX));
        a--, b--;
        G[a][b] = 1;
        maxy = max(a, b);
        while(cin >> a >> b && a != 0 && b != 0)
        {
            a--, b--;
            G[a][b] = 1;
            maxy = max(max(a, b), maxy);
        }
        for(int i = 0; i < 100; i++)
            G[i][i] = 0;
        maxy++;
        floydWarshall(G, maxy);
        int sum = 0, kapa = 0;
        for(int i = 0; i < maxy; i++)
        {
            for(int j = 0; j < maxy; j++)
            {
                if(G[i][j] != MAX && G[i][j] != 0)
                    sum += G[i][j], kapa++;
            }
        }
        cout << "Case " << k << ": average length between pages = ";
        cout << fixed << float(sum) / kapa << " clicks"<< endl;
    }

    return 0;
}

void floydWarshall(vector<vector<int> > &G, int maxy)
{
    for(int k = 0; k < maxy; k++)
    {
        for(int i = 0; i < maxy; i++)
        {
            for(int j = 0; j < maxy; j++)
            {
                if(G[i][j] > G[i][k] + G[k][j])
                    G[i][j] = G[i][k] + G[k][j];
            }
        }
    }
}

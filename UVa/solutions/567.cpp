#include <bits/stdc++.h>
#define MAX 10000000

using namespace std;

void floydWarshall(vector<vector<int> > &V);

int main()
{
    int first;
    int kapa = 1;
    while(cin >> first)
    {
        vector<vector<int> > V(20, vector<int>(20, MAX));
        for(int i = 0; i < 20; i++)
            V[i][i] = 0;
        for(int i = 0; i < first; i++)
        {
            int a;
            cin >> a;
            a--;
            V[a][0] = 1;
            V[0][a] = 1;
        }
        for(int i = 1; i < 19; i++)
        {
            int n;
            cin >> n;
            for(int j = 0; j < n; j++)
            {
                int a;
                cin >> a;
                a--;
                V[a][i] = 1;
                V[i][a] = 1;
            }
        }
        floydWarshall(V);
        int napa;
        cin >> napa;
        cout << "Test Set #" << kapa << endl;
        for(int i = 0; i < napa; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            printf("%2d to %2d: %d\n", a + 1, b + 1, V[a][b]);
        }
        cout << endl;
        kapa++;
    }
    return 0;
}

void floydWarshall(vector<vector<int> > &V)
{
    for(int k = 0; k < V.size(); k++)
    {
        for(int i = 0; i < V.size(); i++)
        {
            for(int j = 0; j < V.size(); j++)
            {
                if(V[i][j] > V[i][k] + V[k][j])
                    V[i][j] = V[i][k] + V[k][j];
            }
        }
    }
}

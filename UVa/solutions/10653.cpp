#include <bits/stdc++.h>

using namespace std;

int bfs(int a, int b, int c, int d, vector<vector<bool> > &V);

int main()
{
    int r = 1, c = 1;
    while(true)
    {
        cin >> r >> c;
        if(r == 0 || c == 0)
            break;
        vector<vector<bool> > field(r, vector<bool>(c, false));
        int m;
        cin >> m;
        while(m--)
        {
            int a, b;
            cin >> a >> b;
            for(int i = 0; i < b; i++)
            {
                int kapa;
                cin >> kapa;
                field[a][kapa] = true;
            }
        }
        int stx, sty, enx, eny;
        cin >> stx >> sty;
        cin >> enx >> eny;
        cout << bfs(stx, sty, enx, eny, field) << endl;
    }
}

int bfs(int a, int b, int c, int d, vector<vector<bool> > &V)
{
    vector<vector<bool> > visi(V.size(), vector<bool>(V[0].size(), false));
    visi[a][b] = true;
    queue<pair<int, int> > Q;
    Q.push(make_pair(a, b));
    Q.push(make_pair(-1, -1));
    int T = 0;
    int alpha[4] = {0, 0, 1, -1}, beta[4] = {1, -1, 0, 0};
    while(!Q.empty())
    {
        pair<int, int> napa = Q.front();
        Q.pop();
        if(napa.first == c && napa.second == d)
            return T;
        if(napa.first == -1)
        {
            T++;
            Q.push(make_pair(-1, -1));
            continue;
        }
        for(int i = 0; i < 4; i++)
        {
            try
            {
                if(V.at(alpha[i] + napa.first).at(beta[i] + napa.second) == false)
                {
                    if(visi[alpha[i] + napa.first][beta[i] + napa.second] == false)
                    {
                        visi[alpha[i] + napa.first][beta[i] + napa.second] = true;
                        Q.push(make_pair(alpha[i] + napa.first, beta[i] + napa.second));
                    }
                }
            }
            catch(exception &e) {}
        }
    }
}

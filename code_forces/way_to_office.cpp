#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> G(n);
    for(int i = 0; i < n; i++)
        cin >> G[i];
    int sx, sy, tx, ty;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            if(G[i][j] == 'S')
                sx = i, sy = j;
            else if(G[i][j] == 'T')
                tx = i, ty = j;
    }
    vector<vector<int> > V(n, vector<int> (m, 0));
    for(int i = sx; i < n; i++)
        if(G[i][sy] == '.')
            V[i][sy] = 1;
        else if(G[i][sy] == 'T')
        {
            cout << "YES" << endl;
            exit(0);
        }
        else if(G[i][sy] == '*')
            break;
    for(int i = sx; i >= 0; i--)
        if(G[i][sy] == '.')
            V[i][sy] = 1;
        else if(G[i][sy] == 'T')
        {
            cout << "YES" << endl;
            exit(0);
        }
        else if(G[i][sy] == '*')
            break;
    for(int i = sy; i < m; i++)
        if(G[sx][i] == '.')
            V[sx][i] = 1;
        else if(G[sx][i] == 'T')
        {
            cout << "YES" << endl;
            exit(0);
        }
        else if(G[sx][i] == '*')
            break;
    for(int i = sy; i >= m; i--)
        if(G[sx][i] == '.')
            V[sx][i] = 1;
        else if(G[sx][i] == 'T')
        {
            cout << "YES" << endl;
            exit(0);
        }
        else if(G[sx][i] == '*')
            break;

    for(int i = tx; i < n; i++)
        if(G[i][ty] == '.')
        {
            for(int j = ty; j < m; j++)
                if(V[i][j] == 1)
                {
                    cout << "YES" << endl;
                    exit(0);
                }
            for(int j = ty; j >= 0; j++)
                if(V[i][j] == 1)
                {
                    cout << "YES" << endl;
                    exit(0);
                }
        }
        else if(G[i][sy] == 'T')
        {
            cout << "YES" << endl;
            exit(0);
        }
        else if(G[i][sy] == '*')
            break;
    for(int i = sx; i >= 0; i--)
        if(G[i][sy] == '.')
        {
            for(int j = ty; j < m; j++)
                if(V[i][j] == 1)
                {
                    cout << "YES" << endl;
                    exit(0);
                }
            for(int j = ty; j >= 0; j++)
                if(V[i][j] == 1)
                {
                    cout << "YES" << endl;
                    exit(0);
                }
        }
        else if(G[i][sy] == 'T')
        {
            cout << "YES" << endl;
            exit(0);
        }
        else if(G[i][sy] == '*')
            break;
    for(int i = sy; i < m; i++)
        if(G[sx][i] == '.')
        {
            for(int j = tx; j < n; j++)
                if(V[j][i] == 1)
                {
                    cout << "YES" << endl;
                    exit(0);
                }
            for(int j = tx; j >= 0; j++)
                if(V[j][i] == 1)
                {
                    cout << "YES" << endl;
                    exit(0);
                }
        }
        else if(G[sx][i] == 'T')
        {
            cout << "YES" << endl;
            exit(0);
        }
        else if(G[sx][i] == '*')
            break;
    for(int i = sy; i >= m; i--)
        if(G[sx][i] == '.')
        {
            for(int j = tx; j < n; j++)
                if(V[j][i] == 1)
                {
                    cout << "YES" << endl;
                    exit(0);
                }
            for(int j = tx; j >= 0; j++)
                if(V[j][i] == 1)
                {
                    cout << "YES" << endl;
                    exit(0);
                }
        }
        else if(G[sx][i] == 'T')
        {
            cout << "YES" << endl;
            exit(0);
        }
        else if(G[sx][i] == '*')
            break;
    cout << "NO" << endl;
    return 0;
}

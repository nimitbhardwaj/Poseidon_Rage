#include <bits/stdc++.h>

using namespace std;

bool bfs(int a, int b, int c, int d, vector<vector<char> > &V, int R, int C);

int main()
{
    int t;
    scanf("%d", &t);
    vector<vector<char> > V(5000, vector<char>(5000));
    while(t--)
    {
        int r, c;
        scanf("%d %d", &r, &c);
        getchar();
        for(int i = 0; i < r; i++)
        {
            char ch;
            int j = 0;
            while((ch = getchar()) != '\n')
            {
                if(ch == ' ' || ch == '\t')
                    continue;
                V[i][j] = ch;
                j++;
            }
        }
        if(r == 1 && c == 1)
        {
            printf("invalid\n");
            continue;
        }
        int ends = 0;
        int ax = -1, ay = -1, bx = -1, by = -1;
        for(int i = 0; i < r; i++)
        {
            if(V[i][0] == '.')
            {
                if(ends == 0)
                    ax = i, ay = 0;
                if(ends == 1)
                    bx = i, by = 0;
                ends++;
            }
            if(V[i][c - 1] == '.')
            {
                if(ends == 0)
                    ax = i, ay = c - 1;
                if(ends == 1)
                    bx = i, by = c - 1;
                ends++;
            }
        }
        for(int i = 1; i < c - 1; i++)
        {
            if(V[0][i] == '.')
            {
                if(ends == 0)
                    ax = 0, ay = i;
                if(ends == 1)
                    bx = 0, by = i;
                ends++;
            }
            if(V[r - 1][i] == '.')
            {
                if(ends == 0)
                    ax = r - 1, ay = i;
                if(ends == 1)
                    bx = r - 1, by = i;
                ends++;
            }
        }
        if(r == 1)
        {
            ends = 0;
            for(int i = 0; i < c; i++)
            {
                if(V[0][i] == '.')
                {
                    if(ends == 0)
                        ax = 0, by = i;
                    if(ends == 1)
                        bx = 0, by = i;
                    ends++;
                }
            }
        }
        if(c == 1)
        {
            ends = 0;
            for(int i = 0; i < r; i++)
            {
                if(V[i][0] == '.')
                {
                    if(ends == 0)
                        ax = i, ay = 0;
                    if(ends == 1)
                        bx = i, by = 0;
                    ends++;
                }
            }
        }
        if(ends != 2)
        {
            printf("invalid\n");
            continue;
        }
        if(bfs(ax, ay, bx, by, V, r, c))
            printf("valid\n");
        else
            printf("invalid\n");
    }
    return 0;
}

bool bfs(int a, int b, int c, int d, vector<vector<char> > &V, int R, int C)
{
    queue<pair<int, int> > Q;
    vector<vector<bool> > visi(R, vector<bool>(C, false));
    visi[a][b] = true;
    Q.push(make_pair(a, b));
    int alpha[4] = {0, 0, -1, 1}, beta[4] = {1, -1, 0, 0};
    while(!Q.empty())
    {
        pair<int, int> kapa = Q.front();
        Q.pop();
        if(kapa.first == c && kapa.second == d)
            return true;
        for(int i = 0; i < 4; i++)
        {
            if(kapa.first + alpha[i] < 0 || kapa.first + alpha[i] >= R)
                continue;
            if(kapa.second + beta[i] < 0 || kapa.second + beta[i] >= C)
                continue;
            if(V.at(kapa.first + alpha[i]).at(kapa.second + beta[i]) == '.')
            {
                if(!visi[kapa.first + alpha[i]][kapa.second + beta[i]])
                {
                    visi[kapa.first + alpha[i]][kapa.second + beta[i]] = true;
                    Q.push(make_pair(kapa.first + alpha[i], kapa.second + beta[i]));
                }
            }
        }
    }
    return false;
}

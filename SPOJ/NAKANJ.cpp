#include <bits/stdc++.h>

using namespace std;

int bfs(int, int, int, int);

struct Move
{
    int x, y, moves;
    Move(int a, int b, int c)
        :x(a), y(b), moves(c) {}
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int x1 = s1[0] - 'a', x2 = s2[0] - 'a';
        int y1 = s1[1] - '1', y2 = s2[1] - '1';
        cout << bfs(x1, y1, x2, y2) << endl;
    }
    return 0;
}

int bfs(int x1, int y1, int x2, int y2)
{
    queue<Move> Q;
    Q.push(Move(x1, y1, 0));
    vector<vector<bool> > visited(8, vector<bool> (8, false));
    int alpha[8] = {2, 2, 1, -1, -2, -2, -1, 1}, beta[8] = {1, -1, -2, -2, -1, 1, 2, 2};
    while(!Q.empty())
    {
        Move kapa = Q.front();
        Q.pop();
        visited[kapa.x][kapa.y] = true;
        if(kapa.x == x2 && kapa.y == y2)
            return kapa.moves;
        for(int i = 0; i < 8; i++)
        {
            int a = kapa.x + alpha[i], b = kapa.y + beta[i];
            if(a < 0 || b < 0 || a >= 8 || b >= 8)
                continue;
            if(!visited[a][b])
                Q.push(Move(a, b, kapa.moves + 1));
        }
    }
}

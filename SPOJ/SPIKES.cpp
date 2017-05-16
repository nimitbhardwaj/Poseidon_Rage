#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool getAns(vector<vector<char> > &, int x, int y, int k, int &ans, vector<vector<char> > &);
bool isValidPosition(int, int, vector<vector<char> > &V, vector<vector<char> > &visited);

int main()
{
    int m, n, k, x, y;
    cin >> m >> n >> k;
    vector<vector<char> > V(m, vector<char>(n, 0));
    vector<vector<char> > visited(m, vector<char>(n, 0));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> V[i][j];
            if(V[i][j] == '@')
                x = i, y = j;
        }
    }
    int ans = 0;
    if(getAns(V, x, y, k, ans, visited))
        cout << "SUCCESS" << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}

bool getAns(vector<vector<char> > &V, int x, int y, int k, int &ans, vector<vector<char> > &visited)
{
    if(V[x][y] == 'x')
    {
        if(2 * ans <= k)
            return true;
        else
            return false;
    }
    for(int i = 0; i < V.size(); i++)
    {
        for(int j = 0; j < V[i].size(); j++)
        {
            int c1x = x;
            int c1y = y + 1;
            int c2x = x;
            int c2y = y - 1;
            int c3x = x - 1;
            int c3y = y;
            int c4x = x + 1;
            int c4y = y;
            visited[x][y] = 1;
            if(isValidPosition(c1x, c1y, V, visited))
            {
                if(V[c1x][c1y] == 's')
                    ans++;
                if(getAns(V, c1x, c1y, k, ans, visited))
                    return true;
                if(V[c1x][c1y] == 's')
                    ans--;
            }
            if(isValidPosition(c2x, c2y, V, visited))
            {
                if(V[c2x][c2y] == 's')
                    ans++;
                if(getAns(V, c2x, c2y, k, ans, visited))
                    return true;
                if(V[c2x][c2y] == 's')
                    ans--;
            }
            if(isValidPosition(c3x, c3y, V, visited))
            {
                if(V[c3x][c3y] == 's')
                    ans++;
                if(getAns(V, c3x, c3y, k, ans, visited))
                    return true;
                if(V[c3x][c3y] == 's')
                    ans--;
            }
            if(isValidPosition(c4x, c4y, V, visited))
            {
                if(V[c4x][c4y] == 's')
                    ans++;
                if(getAns(V, c4x, c4y, k, ans, visited))
                    return true;
                if(V[c4x][c4y] == 's')
                    ans--;
            }
            visited[x][y] = 0;
        }
    }
    return false;
}

bool isValidPosition(int x, int y, vector<vector<char> > &V, vector<vector<char> > &visited)
{
    if(x < 0 || x >= V[0].size() || y < 0 || y >= V.size())
        return false;
    if(V[x][y] == '#')
        return false;
    if(visited[x][y] == 1)
        return false;
    return true;
}

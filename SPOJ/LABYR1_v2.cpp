#include <cstdio>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdexcept>

using namespace std;

struct Node
{
    int x, y, depth;
    Node(int a, int b, int c)
        :x(a), y(b), depth(c)
    {}
};

int dfs(int x, int y, vector<vector<char> > &, int, int);

int main()
{
    int t;
    scanf("%d\n", &t);
    while(t--)
    {
        int c, r;
        scanf("%d %d\n", &c, &r);
        vector<vector<char> > labyrith(r, vector<char>(c, 0));
        stack<pair<int, int> > S;
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                //scanf("%c", &labyrith[i][j]);
                labyrith[i][j] = getchar();
            }
            getchar();
        }
        for(int i =  0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(labyrith[i][j] == '.')
                {
                    int kapa = 0;
                    try
                    {
                        if(labyrith.at(i).at(j + 1) == '.')
                            kapa++;
                    }
                    catch(out_of_range &e)
                    {}

                    try
                    {
                        if(labyrith.at(i).at(j - 1) == '.')
                            kapa++;
                    }
                    catch(out_of_range &e)
                    {}

                    try
                    {
                        if(labyrith.at(i + 1).at(j) == '.')
                            kapa++;
                    }
                    catch(out_of_range &e)
                    {}

                    try
                    {
                        if(labyrith.at(i - 1).at(j) == '.')
                            kapa++;
                    }
                    catch(out_of_range &e)
                    {}
                    if(kapa == 1 || kapa == 0)
                        S.push(make_pair(i, j));
                }
            }
        }
        int maxy = 0;
        //while(!S.empty())
        //{
            //pair<int, int> pos = S.top();
            //S.pop();
            //maxy = max(maxy, dfs(pos.first, pos.second, labyrith, r, c));
        //}
        pair<int, int> pos = S.top();
        maxy = dfs(pos.first, pos.second, labyrith, r, c);
        printf("Maximum rope length is %d\n", maxy);
        
    }
    return 0;
}

int dfs(int x, int y, vector<vector<char> > &V, int a, int b)
{
    stack<Node> S;
    vector<vector<bool> > visited(a, vector<bool>(b, false));
    S.push(Node(x, y, 0));
    visited[x][y] = true;
    int maxLevel = 0;
    while(!S.empty())
    {
        Node tmp = S.top();
        S.pop();
        maxLevel = max(maxLevel, tmp.depth);
        try
        {
            if(V.at(tmp.x).at(tmp.y + 1) == '.' && visited.at(tmp.x).at(tmp.y + 1) == false)
            {
                S.push(Node(tmp.x, tmp.y + 1, tmp.depth + 1));
                visited.at(tmp.x).at(tmp.y + 1) = true;
            }
        }
        catch(out_of_range &e)
        {}

        try
        {
            if(V.at(tmp.x).at(tmp.y - 1) == '.' && visited.at(tmp.x).at(tmp.y - 1) == false)
            {
                S.push(Node(tmp.x, tmp.y - 1, tmp.depth + 1));
                visited.at(tmp.x).at(tmp.y - 1) = true;
            }
        }
        catch(out_of_range &e)
        {}

        try
        {
            if(V.at(tmp.x + 1).at(tmp.y) == '.' && visited.at(tmp.x + 1).at(tmp.y) == false)
            {
                S.push(Node(tmp.x + 1, tmp.y, tmp.depth + 1));
                visited.at(tmp.x + 1).at(tmp.y) = true;
            }
        }
        catch(out_of_range &e)
        {}

        try
        {
            if(V.at(tmp.x - 1).at(tmp.y) == '.' && visited.at(tmp.x - 1).at(tmp.y) == false)
            {
                S.push(Node(tmp.x - 1, tmp.y, tmp.depth + 1));
                visited.at(tmp.x - 1).at(tmp.y) = true;
            }
        }
        catch(out_of_range &e)
        {}

    }
    return maxLevel;
}

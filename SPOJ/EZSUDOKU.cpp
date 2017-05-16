#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <cstdio>

using namespace std;

bool solveSudoku(vector<vector<int> > &, stack<pair<int, int> > &);
bool validMove(vector<vector<int> > &, pair<int, int>, int);
bool isValidSudoku(vector<vector<int> > &);

int main()
{
    int t;
    scanf("%d", &t);
    vector<vector<int> > V(8, vector<int>(8, 0));
    for(int kapa = 1; kapa <= t; kapa++)
    {
        stack<pair<int, int> > S;
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                scanf("%d", &V[i][j]);
                if(V[i][j] == 0)
                    S.push(make_pair(i, j));
            }
        }
        if(solveSudoku(V, S))
        {
            printf("Test case #%d: YES\n", kapa);
            for(int i = 0; i < 8; i++)
            {
                for(int j = 0; j < 8; j++)
                    printf("%d ", V[i][j]);
                printf("\n");
        
            }
        }
        else
        {
            printf("Test case #%d: NO\n", kapa);
        }
    }
    return 0;
}

bool solveSudoku(vector<vector<int> > &V, stack<pair<int, int> > &S)
{
    if(S.empty())
    {
        if(isValidSudoku(V))
            return true;
        else
            return false;
    }
    pair<int, int> position = S.top();
    S.pop();
    for(int i = 1; i <= 8; i++)
    {
        if(validMove(V, position, i))
        {
            V[position.first][position.second] = i;
            if(solveSudoku(V, S))
                return true;
            V[position.first][position.second] = 0;
        }
    }
    S.push(position);
    return false;
}

bool validMove(vector<vector<int> > &V, pair<int, int> position, int k)
{
    bool check = true;
    int regx = 0, regy = 0;
    for(int i = 0; i < 8; i++)
    {
        if(V[i][position.second] == k)
        {
            check = false;
            break;
        }
        if(V[position.first][i] == k)
        {
            check = false;
            break;
        }
    }
    if(check == false)
        return false;
    if(position.first >= 4)
        regx = 4;
    if(position.second >= 4)
        regy = 4;
    int alpha = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(V[regx + i][regy + j] == k)
            {
                if(alpha == 0)
                    alpha++;
                else
                {
                    check = false;
                    return false;
                }
            }
        }
    }
    return check;
}

bool isValidSudoku(vector<vector<int> > &V)
{
    vector<vector<int> > alpha(8, vector<int>(8, 0)), beta(8, vector<int>(8, 0));
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(V[i][j] != 0)
                if(alpha[i][V[i][j] - 1] == 1)
                {
                    return false;
                }
                else
                    alpha[i][V[i][j] - 1] += 1;
            if(V[j][i] != 0)
                if(beta[i][V[j][i] - 1] == 1)
                {
                    return false;
                }
                else
                    beta[i][V[j][i] - 1] += 1;
        }
    }
    vector<int> napa(8, 0), kapa(8, 0), delta(8, 0), lambda(8, 0);
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(V[i][j] != 0)
                if(kapa[V[i][j] - 1] >= 2)
                {
                    return false;
                }
                else
                    kapa[V[i][j] - 1] += 1;
            if(V[i][j + 4] != 0)
                if(napa[V[i][j + 4] - 1] >= 2)
                {
                    return false;
                }
                else
                    napa[V[i][j + 4] - 1] += 1;
            if(V[i + 4][j] != 0)
                if(delta[V[i + 4][j] - 1] >= 2)
                {
                    return false;
                }
                else
                    delta[V[i + 4][j] - 1] += 1;
            if(V[i + 4][j + 4] != 0)
                if(lambda[V[i + 4][j + 4] - 1] >= 2)
                {
                    return false;
                }
                else
                    lambda[V[i + 4][j + 4] - 1] += 1;
        }
    }
    return true;
}

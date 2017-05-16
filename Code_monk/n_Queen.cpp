#include <iostream>
#include <vector>

using namespace std;

bool nQueenSolution(vector<vector<int> > &, int);
bool isAttacked(int, int, vector<vector<int> > &);


int main()
{
    int n;
    cin >> n;
    vector<vector<int> > board(n, vector<int> (n, 0));
    nQueenSolution(board, n);
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[i].size(); j++)
            cout << board[i][j] << ' ';
        cout << endl;
    }
    return 0;
}

bool nQueenSolution(vector<vector<int> > &board, int n)
{
    if(n == 0)
    {
        return true;
    }
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board.size(); j++)
        {
            if(isAttacked(i, j, board))
                continue;
            board[i][j] = 1;
            if(nQueenSolution(board, n - 1))
                return true;
            board[i][j] = 0;
        }
    }
}

bool isAttacked(int x, int y, vector<vector<int> > &board)
{
    for(int i = 0; i < board.size(); i++)
    {
        if(board[x][i] == 1)
            return true;
        if(board[i][y] == 1)
            return true;
        if(i + x < board.size() && i + y < board.size())
            if(board[i + x][i + y] == 1)
                return true;
        if(i + x < board.size() && y - i >= 0)
            if(board[i + x][y - i] == 1)
                return true;
        if(x - i >= 0 && i + y < board.size())
            if(board[x - i][i + y] == 1)
                return true;
        if(x - i >= 0 && y - i >= 0)
            if(board[x - i][y - i] == 1)
                return true;
    }
}

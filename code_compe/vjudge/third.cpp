#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> player(a, 1);
        vector<int> board(101, 0);
        for(int i = 0; i < b; i++)
        {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            board[tmp1] = tmp2;
        }
        int beta = 0;
        bool win = false;
        for(int i = 0; i < c; i++)
        {
            int alpha;
            cin >> alpha;
            if(win)
                continue;
            player[beta] = player[beta] + alpha;
            if(board[player[beta]] != 0)
                player[beta] = board[player[beta]];
            if(player[beta] == 100)
                win = true;
            beta = (beta + 1) % a;
        }
        for(int i = 0; i < a; i++)
        {
            cout << "Position of player " << i + 1 << " is " << player[i] << '.' <<endl;
        }
    }
    return 0;
}

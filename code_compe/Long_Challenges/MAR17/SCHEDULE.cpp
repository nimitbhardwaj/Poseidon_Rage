#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Comp
{
    public:
        bool operator()(const int &a, const int &b)
        { return a < b; }
};

int minMovesFor(int, const string &);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        string S;
        cin >> n >> k;
        cin >> S;
        int dat = 0;
        priority_queue<int, vector<int>, Comp> Q;
        int prev = 0;
        for(int i = 0; i < S.size(); i++)
        {
            if(i == 0)
                prev = S[i] - '0', dat++;
            else if(prev != S[i] - '0')
            {
                Q.push(dat);
                prev = S[i] - '0';
                dat = 1;
            }
            else
                dat++;
            if(i == S.size() - 1)
            {
                Q.push(dat);
            }
        }

        if(Q.top() == 1)
        {
            cout << 1 << endl;
        }
        else if(Q.top() == 2)
        {
            int minMoves0 = minMovesFor(0, S);
            int minMoves1 = minMovesFor(1, S);
            int minMoves = min(minMoves0, minMoves1);
            if(minMoves <= k)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
        else
        {
            int minMoves0 = minMovesFor(0, S);
            int minMoves1 = minMovesFor(1, S);
            int minMoves = min(minMoves0, minMoves1);
            if(minMoves <= k)
                cout << 1 << endl;
            else
            {
                while(k != 0 && Q.top() != 2 && Q.top() != 1)
                {
                    int mxy = Q.top();
                    int sp1 = mxy / 2;
                    int sp2 = mxy - sp1 - 1;
                    Q.pop();
                    Q.push(sp1);
                    Q.push(sp2);
                    Q.push(1);
                    k--;
                }
                if(Q.top() == 2)
                    cout << 2 << endl;
                else if(k == 0)
                    cout << Q.top() << endl;
                else if(Q.top() == 1)
                    cout << 1 << endl;
            }
        }
    }
    return 0;
}

int minMovesFor(int a, const string &S)
{
    int ret = 0;
    for(int i = 0; i < S.length(); i++)
    {
        if(S[i] != a + '0')
            ret++;
        a = 1 - a;
    }
    return ret;
}

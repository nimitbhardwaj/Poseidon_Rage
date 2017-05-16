#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(const int &a, const int &b)
{ return a > b; }

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
        vector<int> V;
        int prev = 0;
        for(int i = 0; i < S.size(); i++)
        {
            if(i == 0)
                prev = S[i] - '0', dat++;
            else if(prev != S[i] - '0')
            {
                V.push_back(dat);
                prev = S[i] - '0';
                dat = 1;
            }
            else
                dat++;
            if(i == S.size() - 1)
            {
                V.push_back(dat);
            }
        }
        sort(V.begin(), V.end(), comp);

        if(V.front() == 1)
        {
            cout << 1 << endl;
        }
        else if(V.front() == 2)
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
                int ans = V.front();
                for(int i = V.front() - 1; i >= 2; i--)
                {
                    int res = 0;
                    bool flg = false;
                    for(int j = 0; j < V.size(); j++)
                    {
                        res += V[j] / (i + 1);
                        if(res > k)
                        {
                            flg = true;
                            break;
                        }
                    }
                    if(flg == true)
                        break;
                    ans = i;
                }
                cout << ans << endl;
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

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void calcAns(vector<pair<int, vector<int> > > &V, int& ans, int& count, int x, int y);
bool isValid(vector<pair<int, vector<int> > > &, int, int);

int main()
{
    int n;
    int t = 1;
    cin >> n;
    while(n != 0)
    {
        vector<pair<int, vector<int> > > V;
        int ans = 0, count = 0, kapa = 0;
        for(int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            kapa += b;
            pair<int, vector<int> > pr = make_pair(a, vector<int>(b, 0));
            V.push_back(pr);
        }
        calcAns(V, ans, count, 0, V[0].first);
        if(kapa - ans != 1)
            cout << "Case " << t << ", " << kapa - ans
                 << " squares can not be reached." << endl;
        else
            cout << "Case " << t << ", " << kapa - ans
                 << " square can not be reached." << endl;
        cin >> n;
        t++;
    }
    return 0;
}

void calcAns(vector<pair<int, vector<int> > > &V, int& ans, int &count, int x, int y)
{
    V[y].second[x - V[y].first] = 1;
    count++;
    ans = max(ans, count);
    int pos1x = x + 2;
    int pos1y = y - 1;

    int pos2x = x + 2;
    int pos2y = y + 1;

    int pos3x = x + 1;
    int pos3y = y + 2;

    int pos4x = x - 1;
    int pos4y = y + 2;

    int pos5x = x - 2;
    int pos5y = y + 1;

    int pos6x = x - 2;
    int pos6y = y - 1;

    int pos7x = x - 1;
    int pos7y = y - 2;

    int pos8x = x + 1;
    int pos8y = y - 2;
    if(isValid(V, pos1x, pos1y))
    {
        calcAns(V, ans, count, pos1x, pos1y);
    }

    if(isValid(V, pos2x, pos2y))
    {
        calcAns(V, ans, count, pos2x, pos2y);
    }

    if(isValid(V, pos3x, pos3y))
    {
        calcAns(V, ans, count, pos3x, pos3y);
    }

    if(isValid(V, pos4x, pos4y))
    {
        calcAns(V, ans, count, pos4x, pos4y);
    }

    if(isValid(V, pos5x, pos5y))
    {
        calcAns(V, ans, count, pos5x, pos5y);
    }

    if(isValid(V, pos6x, pos6y))
    {
        calcAns(V, ans, count, pos6x, pos6y);
    }

    if(isValid(V, pos7x, pos7y))
    {
        calcAns(V, ans, count, pos7x, pos7y);
    }

    if(isValid(V, pos8x, pos8y))
    {
        calcAns(V, ans, count, pos8x, pos8y);
    }
    V[y].second[x - V[y].first] = 0;
    count--;
}

bool isValid(vector<pair<int, vector<int> > > &V, int x, int y)
{
    if(y < 0 || y >= V.size())
        return false;
    if(x - V[y].first < 0 || x - V[y].first >= V[y].second.size())
        return false;
    x = x - V[y].first;
    if(V[y].second[x] == 1)
        return false;
    return true;
}

#include <bits/stdc++.h>

using namespace std;

inline bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first <= b.first;
}

int main()
{
    int s, n;
    cin >> s >> n;
    vector<pair<int, int> > V;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        V.push_back(make_pair(a, b));
    }
    sort(V.begin(), V.end(), comp);
    bool win = true;
    for(int i = 0; i < V.size(); i++)
    {
        if(s > V[i].first)
            s += V[i].second;
        else
        {
            win = false;
            break;
        }
    }
    if(win)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}

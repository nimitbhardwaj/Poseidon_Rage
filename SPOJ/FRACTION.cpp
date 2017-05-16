#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool comp(const pair<int, int> &, const pair<int, int> &);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int> > V;
        int a = 0, b = 1, c = 1, d = n;
        V.push_back(make_pair(a, b));
        V.push_back(make_pair(c, d));
        while(c <= n)
        {
            int k = (n + b) / d;
            int a_ = a, b_ = b, c_ = c, d_ = d;
            a = c;
            b = d;
            c = k * c - a_;
            d = k * d - b_;
            V.push_back(make_pair(c, d));
        }
        for(int i = 0; i < m; i++)
        {
            int tmp;
            cin >> tmp;
            tmp--;
            cout << V[tmp].first << '/' << V[tmp].second << endl;
        }
    }
    return 0;
}


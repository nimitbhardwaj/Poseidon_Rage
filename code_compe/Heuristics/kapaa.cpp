#include <bits/stdc++.h>

using namespace std;

int ans(int a, int b);

int main()
{
    int n, m;
    cin >> n >> m;
    cout << ans(n, m) << endl;

    return 0;
}

int ans(int a, int b)
{
    queue<pair<int, int> > Q;
    vector<int> V(10000000, INT_MAX);
    Q.push(make_pair(a, 0));
    while(Q.front().first != b)
    {
        pair<int, int> kapa = Q.front();
        Q.pop();
        if(V[kapa.first] > kapa.second)
        {
            V[kapa.first] = kapa.second;
            if(kapa.first - 1 > 0)
                Q.push(make_pair(kapa.first - 1, kapa.second + 1));
            Q.push(make_pair(2 * kapa.first, kapa.second + 1));
        }

    }
    return Q.front().second;
}

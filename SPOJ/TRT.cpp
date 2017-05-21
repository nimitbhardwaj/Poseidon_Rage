#include <bits/stdc++.h>

using namespace std;

int dp(vector<int> &V, int a, int b, vector<vector<int> > &hash, int day);

int main()
{
    int n;
    cin >> n;
    vector<int> V(n);
    vector<vector<int> >hash(n + 10, vector<int>(n + 10, 0));
    for(int i = 0; i < n; i++)
        cin >> V[i];
    cout << dp(V, 0, V.size() - 1, hash, 1) << endl;
    return 0;
}

int dp(vector<int> &V, int a, int b, vector<vector<int> > &hash, int day)
{
    if(b < a)
        return 0;
    //cout << "kapa" << day << ' ' << a << ' ' << b << endl;
    if(hash[day][a] != 0)
        return hash[day][a];
    int kapa = max(V[a] * day + dp(V, a + 1, b, hash, day + 1), V[b] * day + dp(V, a, b - 1, hash, day + 1));
    hash[day][a] = kapa;
    return kapa;
}

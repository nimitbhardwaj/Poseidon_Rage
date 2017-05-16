#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, k;
    cin >> n >> k;
    vector<long long int> V(n);
    long long int mini = LLONG_MAX;
    for(long long int i = 0; i < n; i++)
    {
        cin >> V[i];
        mini = min(mini, V[i]);
    }
    long long int ans = 0;
    bool napa = true;
    for(long long int i = 0; i < V.size(); i++)
    {
        if((V[i] - mini) % k == 0)
            ans += (V[i] - mini) / k;
        else
        {
            napa = false;
            break;
        }
    }
    if(napa)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}

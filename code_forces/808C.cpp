#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, w;
    int used = 0;
    cin >> n >> w;
    vector<int> V(n);
    priority_queue<int> Q;
    for(int i = 0; i < n; i++)
    {
        cin >> V[i];
        used = used + V[i] / 2 + (V[i] % 2 != 0);
        Q.push(V[i] / 2 + (V[i] % 2 != 0));
    }
    if(used > w)
        cout << -1, exit(0);
    return 0;
}

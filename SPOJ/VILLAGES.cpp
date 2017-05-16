#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<bitset<1000> > V(n, bitset<1000>());
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        V[a].set(b);
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            bitset<1000> bt;
            bt = (V[i] & V[j]);
            int count = bt.count();
            ans += (count * (count - 1)) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}

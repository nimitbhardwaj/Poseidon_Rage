#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> V(n, 0);
    int ans = 0, kapa;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        kapa = V[a];
        for(int j = a; j <= b; j++)
        {
            V[j]++;
            if(j == a || j == b)
            {
                kapa = V[a];
                continue;
            }
            if(V[j] - kapa >= 1 || V[j] - kapa <= -1)
                ans++;
            kapa = V[j];
        }
        cout << ans << endl;
    }
    return 0;
}

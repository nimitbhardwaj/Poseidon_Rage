#include <bits/stdc++.h>

using namespace std;

struct Kapa
{
    int strt, end;
    bool status;
    Kapa(int a, int b, bool d)
        : strt(a), end(b), status(d) {}
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> V(n, 0);
        vector<Kapa> napa;
        int a = 0, z;
        for(int i = 0; i < n; i++)
        {
            cin >> V[i];
            if(i == 0)
                a = V[i], z = V[i];
            else
            {
                if(V[i - 1] != V[i] - 1)
                {
                    napa.push_back(Kapa(a, z, false));
                    a = V[i];
                }
                z = V[i];
            }
        }
        if(napa.back().strt != a && napa.back().end != z)
            napa.push_back(Kapa(a, z, false));
        int ans = 0;
        for(int i = 0; i < napa.size(); i++)
        {
            ans += (napa[i].end - napa[i].strt + 1) / 2;
            if((napa[i].end - napa[i].strt + 1) % 2 == 1)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}

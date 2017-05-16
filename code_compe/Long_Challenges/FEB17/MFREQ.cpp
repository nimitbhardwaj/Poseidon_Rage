#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int n, m, L, R, k, kapa, napa;
    cin >> n >> m;
    vector<int> V(n);
    for(int i = 0; i < n; i++)
        cin >> V[i];
    while(m--)
    {
        cin >> L >> R >> k;
        kapa = V[L];
        napa = 0;
        pair<int, int> max_napa(0, 0);
        for(int i = L - 1; i <= R - 1; i++)
        {
            if(kapa == V[i])
                napa++;
            else
                napa = 1;
            if(napa > max_napa.second)
                max_napa.second = napa, max_napa.first = V[i];
            if(max_napa.second >= k)
                break;
        }
        if(max_napa.second >= k)
            cout << max_napa.first << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}

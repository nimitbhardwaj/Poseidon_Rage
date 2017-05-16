#include <bits/stdc++.h>

using namespace std;

int main()
{
    while(1)
    {
        int n;
        cin >> n;
        if(n == -1)
            break;
        vector<int> V(n);
        int sum = 0, avg = 0, ans = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> V[i];
            sum += V[i];
        }
        avg = sum / n;
        if(n * (sum / n) != sum)
        {
            cout << -1 << endl;
            continue;
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                if(V[i] > avg)
                    ans += V[i] - avg;
            }
            cout << ans << endl;
        }
    }
    return 0;
}

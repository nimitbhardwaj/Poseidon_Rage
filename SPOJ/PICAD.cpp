#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int t = 10;
    while(t--)
    {
        int x, y;
        cin >> x >> y;
        vector<int> V(y - x + 2, 0);
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            if(b < x || a > y)
                continue;
            a = a - x;
            b = b - x;
            if(a < 0)
                a = 0;
            if(b > y - x)
                b = y - x;
            V[a] += 1;
            V[b + 1] -= 1;
        }
        for(int i = 1; i < V.size(); i++)
            V[i] = V[i - 1] + V[i];
        int maxy = INT_MIN, mini = INT_MAX;
        for(int i = 0; i < V.size() - 1; i++)
        {
            maxy = max(V[i], maxy);
            mini = min(V[i], mini);
        }
        cout << mini << ' ' << maxy << endl;
    }
}

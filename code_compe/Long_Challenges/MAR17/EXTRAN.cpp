#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, i;
        cin >> n;
        vector<int> V(n);
        for(int i = 0; i < n; i++)
            cin >> V[i];
        sort(V.begin(), V.end());
        for(i = 1; i < n; i++)
        {
            if(V[i - 1] + 1 != V[i])
                break;
        }
        if(i == 1)
            cout << V[0] << endl;
        else
            cout << V[i] << endl;
    }
    return 0;
}

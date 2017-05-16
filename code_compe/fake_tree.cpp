#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> V(n, 0), V2(n, 0);
        int max = 0, max_i = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> V[i];
        }
        for(int i = n - 1; i >= 0; i--)
        {
            if(max <= V[i])
            {
                max = V[i];
                max_i = i;
            }
        }
        int cost = max_i;
        int min = INT_MAX, min_i = 0;
        for(int i = 0; i < n; i++)
        {
            if(min >= V[i])
            {
                min = V[i];
                min_i = i;
            }
        }
        if(min_i < max_i)
            min_i++;
        cost += n - min_i - 1;
        cout << cost << endl;
    }
    return 0;
}


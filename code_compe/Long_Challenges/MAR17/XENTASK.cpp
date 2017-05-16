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
        int n;
        cin >> n;
        vector<int> V1(n), V2(n);
        for(int i = 0; i < n; i++)
            cin >> V1[i];
        for(int i = 0; i < n; i++)
            cin >> V2[i];
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
                sum1 += V1[i], sum2 += V2[i];
            else
                sum2 += V1[i], sum1 += V2[i];
        }
        cout << min(sum1, sum2) << endl;

    }
    return 0;
}

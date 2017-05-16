#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    int status = 0, days = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(status == 1)
        {
            a -= k;
            days++;
            status = 0;
        }
        if(a <= 0)
            continue;
        days = days + a / (2 * k);
        a = a % (2 * k);
        if(a == 0)
            continue;
        if(a <= k)
        {
            status = 1;
        }
        else
            days++;
    }
    if(status == 1)
        days++;
    cout << days << endl;
    return 0;
}

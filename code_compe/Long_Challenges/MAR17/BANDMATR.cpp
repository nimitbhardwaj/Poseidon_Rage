#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, a = 0, k;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> k;
                a += k;
            }
        }
        k = -1;
        while(a > 0)
        {
            if(k == -1)
                a -= n;
            else
                a -= 2 * (n - k - 1);
            k++;
            if(a < 0)
                break;
        }
        if(k == -1)
            k = 0;
        cout << k << endl;
    }
    return 0;
}

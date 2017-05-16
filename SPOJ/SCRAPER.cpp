#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int f, e, a, b;
        bool status1 = false, status2 = false;
        cin >> f >> e >> a >> b;
        Vector<pair<bool, bool> > V(e, make_pair(false, false));
        for(int i = 0; i < e; i++)
        {
            int x, y, kapa = a, napa = b;
            cin >> x >> y;
            if(y <= kapa)
            {
                kapa -= y;
                if(kapa % x == 0)
            }
        }
    }
    return 0;
}

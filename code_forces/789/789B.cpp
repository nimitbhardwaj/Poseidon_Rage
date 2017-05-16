#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main()
{
    long long int a, r, l, m, ans = 0;
    vector<long long int> V(m);
    cin >> a >> r >> l >> m;
    for(int i = 0; i < m; i++)
        cin >> V[i];
    sort(V.begin(), V.end());
    if(a == 0)
    {
        if(binary_search(V.begin(), V.end(), 0))
        {
            cout << 0 << endl;
            return 0;
        }
        else
        {
            cout << "inf" << endl;
            return 0;
        }
    }
    else if(r == 0)
    {
        if(binary_search(V.begin(), V.end(), a) && binary_search(V.begin(), V.end(), 0))
            cout << 0 << endl;
        else if(binary_search(V.begin(), V.end(), 0))
            cout << 1 << endl;
        else
            cout << "inf" << endl;
    }
    else if(r == 1)
    {
        if(binary_search(V.begin(), V.end(), a))
            cout << 0 << endl;
        else
            cout << "inf" << endl;
    }
    while(abs(a) <= l)
    {
        if(!binary_search(V.begin(), V.end(), a))
            ans++;
        a = a * r;
    }
    cout << ans << endl;
    return 0;
}

int binLog(int a)
{
    int index = 0;
    while(a >>= 1) index++;
    return index;
}

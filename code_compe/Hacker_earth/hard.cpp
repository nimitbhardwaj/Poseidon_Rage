#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    long long int n, mn = LLONG_MAX;
    cin >> n;
    while(n--)
    {
        long long int tmp;
        cin >> tmp;
        mn = min(tmp, mn);
    }
    cout << mn << endl;
    return 0;
}

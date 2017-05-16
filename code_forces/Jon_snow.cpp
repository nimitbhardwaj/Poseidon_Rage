#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n;
    vector<int> V(n);
    for(int i = 0; i < n; i++)
        cin >> V[i];
    sort(V.begin(), V.end());
    a = 0, b = n - 1;
    for(int i = 1; i < n; i++)
        if(V[i] == V[0])
            a++;
        else
            break;
    for(int i = n - 2; i >= 0; i--)
        if(V[i] == V[n - 1])
            b--;
        else
            break;
    std::cout << b - a - 1 << endl;
    return 0;
}

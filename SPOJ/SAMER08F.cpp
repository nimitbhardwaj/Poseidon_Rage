#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<long long int> V(110, 0);
    long long int sum = 0;
    for(int i = 1; i < V.size(); i++)
    {
        V[i] = sum +  i * i;
        sum = V[i];
    }
    int a;
    while(cin >> a && a != 0)
        cout << V[a] << endl;
    return 0;
}

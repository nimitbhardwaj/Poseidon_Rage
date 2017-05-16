#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, k;
    cin >> n >> k;
    vector<long long int> V(n + 1);
    V[0] = 0;
    for(long long int i = 0; i < n; i++)
    {
        long long int a;
        cin >> a;
        V[i + 1] = a + V[i];
    }
    double avg = 0;
    for(long long int i = 0; i < n - k + 1; i++)
    {
        avg = avg + double((V[i + k] - V[i])) / (n - k + 1);
    }
    cout << setprecision(16) << avg << endl;
    return 0;
}

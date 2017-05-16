#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> V(n + 1, 0);
    while(k--)
    {
        int a, b;
        cin >> a >> b;
        V[a - 1]++;
        V[b]--;
    }
    for(int i = 1; i < V.size(); i++)
        V[i] += V[i - 1];
    V.pop_back();
    sort(V.begin(), V.end());
    cout << V[V.size() / 2] << endl;
    return 0;
}

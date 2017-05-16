#include <bits/stdc++.h>

using namespace std;

int dist(vector<int> &V1, vector<int> &V2);

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);
    vector<vector<int> > V(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < d; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            V[i].push_back(tmp);
        }
    }
    int maxy = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            maxy = max(dist(V[i], V[j]), maxy);
        }
    }
    cout << maxy << endl;
    return 0;
}

int dist(vector<int> &V1, vector<int> &V2)
{
    int sum = 0, a;
    for(int i = 0; i < V1.size(); i++)
    {
        a = V1[i] - V2[i];
        sum += a >= 0 ? a : -a;
    }
    return sum;
}

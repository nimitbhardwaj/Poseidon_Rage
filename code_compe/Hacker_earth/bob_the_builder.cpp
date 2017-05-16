#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool comp1(const pair<int, int> &a, const pair<int, int> &b)
{ return a.second < b.second; }
bool comp2(const pair<int, int> &a, const pair<int, int> &b)
{ return a.second > b.second; }

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int> > V(n, make_pair(0, 0));
        for(int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            V[i] = make_pair(i, tmp);
        }
        sort(V.begin(), V.end(), comp1);
        int cost1 = 0, cost2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(V[i].first != i)
                cost1++;
        }
        sort(V.begin(), V.end(), comp2);
        for(int i = 0; i < n; i++)
        {
            if(V[i].first != i)
                cost2++;
        }
        cout << min(cost1, cost2) << endl;
    }
    return 0;
}

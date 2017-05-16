#include <iostream>
#include <iomanip>
#include <queue>
#include <cstdio>
#include <utility>

using namespace std;

class comp
{
    public:
        bool operator() (const pair<int, pair<int, int> > &a, 
                const pair<int, pair<int, int> > &b)
        {
            return a.second.second > b.second.second;
        }
};

int main()
{
    cout.setf(ios::fixed);
    int t;
    cin >> t;
    while(t--)
    {
        int n, time = 0;
        long double x, sum = 0.0;
        cin >> n;
        priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, comp > Q;
        pair<int, pair<int, int> > val;
        for(int i = 0; i < n; i++)
        {
            int a, b, d, x;
            cin >> a >> b >> d;
            val = make_pair(a, make_pair(b, d));
            Q.push(val);
        }
        while(!Q.empty())
        {
            val = Q.top();
            x = double(val.second.first - val.second.second + time) / val.first;
            if(x > 0)
                sum += x;
            Q.pop();
            if(x <= 0)
                time += val.second.first;
            else
                time = val.second.second;
        }
        printf("%llf\n", sum);
    }
    return 0;
}

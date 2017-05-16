#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> Job;

struct comp
{
    bool operator() (const int a, const int b)
    {
        if(a < b)
            return true;
        else
            return false;
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, a;
        queue< Job > Q;
        priority_queue< int, vector<int>, comp> pQ;
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            cin >> a;
            Q.push(make_pair(i, a));
            pQ.push(a);
        }
        int time = 0;
        bool exec = false;
        Job kapa = Q.front();
        while(exec == false)
        {
            if(kapa.second != pQ.top())
            {
                Q.push(kapa);
                Q.pop();
                kapa = Q.front();
            }
            else
            {
                if(kapa.first == m)
                    exec = true;
                Q.pop();
                kapa = Q.front();
                pQ.pop();
                time++;
            }
        }
        cout << time << endl;
    }
    return 0;
}

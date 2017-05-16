#include <bits/stdc++.h>

using namespace std;

struct Shirt
{
    int a, b, c;
};

struct Comp
{
    bool operator()(int a, int b)
    { return a > b; }
};

int main()
{
    int n;
    cin >> n;
    vector<Shirt> V(n);
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        V[i].a = a;
    }
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        a--;
        V[i].b = a;
    }
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        a--;
        V[i].c = a;
    }
    int m;
    cin >> m;
    queue<int> Q;
    for(int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        a--;
        Q.push(a);
    }
    priority_queue<int, vector<int>, Comp> pQ[9];
    for(int i = 0; i < n; i++)
        pQ[V[i].b + V[i].c * 3].push(V[i].a);
    //cout << "kapa" << endl;
    //for(int i = 0; i < 9; i++)
    //{
        //while(!pQ[i].empty())
            //cout << pQ[i].top() << ' ', pQ[i].pop();
        //cout << endl;
    //}
    //return 0;
    while(!Q.empty())
    {
        int mini = INT_MAX;
        int ind = -1;
        for(int i = 0; i < 3; i++)
        {
            if(!pQ[Q.front() * 3 + i].empty())
            {
                mini = min(mini, pQ[Q.front() * 3 + i].top());
                if(mini == pQ[Q.front() * 3 + i].top())
                    ind = Q.front() * 3 + i;
            }
            if(!pQ[Q.front() + i * 3].empty())
            {
                mini = min(mini, pQ[Q.front() + i * 3].top());
                if(mini == pQ[Q.front() + i * 3].top())
                    ind = Q.front() + i * 3;
            }
        }
        if(ind == -1)
            cout << -1 << ' ';
        else
        {
            cout << pQ[ind].top() << ' ';
            pQ[ind].pop();
        }
        Q.pop();
    }
    cout << endl;
    return 0;
}

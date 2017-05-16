#include <bits/stdc++.h>

using namespace std;

int bfs(int a, int b, vector<bool> &V);
int incDig(int a, int b);
int decDig(int a, int b);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int st = d + 10 * c + 100 * b + 1000 * a;
        cin >> a >> b >> c >> d;
        int en = d + 10 * c + 100 * b + 1000 * a;
        int m;
        cin >> m;
        vector<bool> visi(100000, false);
        while(m--)
        {
            cin >> a >> b >> c >> d;
            visi[d + 10 * c + 100 * b + 1000 * a] = true;
        }
        cout << bfs(st, en, visi) << endl;
    }
    return 0;
}

int bfs(int a, int b, vector<bool> &V)
{
    if(a == b )
        return 0;
    if(V[b])
        return -1;
    queue<int> Q;
    Q.push(a);
    Q.push(-1);
    V[a] = true;
    int count = 1;
    while(!Q.empty())
    {
        int kapa = Q.front();
        int napa;
        Q.pop();
        if(kapa == -1)
        {
            if(Q.empty())
                break;
            Q.push(-1);
            count++;
            continue;
        }

        napa = kapa;
        napa = incDig(napa, 0);
        if(!V[napa])
            V[napa] = true, Q.push(napa);
        if(napa == b)
            return count;

        napa = kapa;
        napa = decDig(napa, 0);
        if(!V[napa])
            V[napa] = true, Q.push(napa);
        if(napa == b)
            return count;

        napa = kapa;
        napa = incDig(napa, 1);
        if(!V[napa])
            V[napa] = true, Q.push(napa);
        if(napa == b)
            return count;

        napa = kapa;
        napa = decDig(napa, 1);
        if(!V[napa])
            V[napa] = true, Q.push(napa);
        if(napa == b)
            return count;

        napa = kapa;
        napa = incDig(napa, 2);
        if(!V[napa])
            V[napa] = true, Q.push(napa);
        if(napa == b)
            return count;

        napa = kapa;
        napa = decDig(napa, 2);
        if(!V[napa])
            V[napa] = true, Q.push(napa);
        if(napa == b)
            return count;

        napa = kapa;
        napa = incDig(napa, 3);
        if(!V[napa])
            V[napa] = true, Q.push(napa);
        if(napa == b)
            return count;

        napa = kapa;
        napa = decDig(napa, 3);
        if(!V[napa])
            V[napa] = true, Q.push(napa);
        if(napa == b)
            return count;
    }
    return -1;
}

int incDig(int a, int b)
{
    int A[4] = {(a / 1000) % 10, (a / 100) % 10, (a / 10) % 10, a % 10};
    if(A[b] == 9)
        A[b] = 0;
    else
        A[b]++;
    return A[3] + 10 * A[2] + 100 * A[1] + 1000 * A[0];
}

int decDig(int a, int b)
{
    int A[4] = {(a / 1000) % 10, (a / 100) % 10, (a / 10) % 10, a % 10};
    if(A[b] == 0)
        A[b] = 9;
    else
        A[b]--;
    return A[3] + 10 * A[2] + 100 * A[1] + 1000 * A[0];
}

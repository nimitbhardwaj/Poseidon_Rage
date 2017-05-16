#include <bits/stdc++.h>
#define MAX 100000000

using namespace std;

struct Kapa
{
    int a, b, c;    
    Kapa(int x, int y, int z)
        :a(x), b(y), c(z) {}
};

inline bool func(int a, int b)
{ return a > b; }

inline bool placement(int a, int b, int c, int d)
{ return (c >= a && d >= b) || (d >= a && c >= b); }

int getAns(int a, int b, int h, int w, vector<int> &V, int kapa);

int main()
{
    int a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;
    vector<int> V;
    for(int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        V.push_back(p);
    }
    sort(V.begin(), V.end(), func);
    int k =  getAns(a, b, h, w, V, 0);
    cout << k << endl;
    return 0;
}

int getAns(int a, int b, int h, int w, vector<int> &V, int kapa)
{
    queue<Kapa> Q;
    if(placement(a, b, h, w))
        return 0;
    Q.push(Kapa(h, w, 0));
    Q.push(Kapa(-1, -1, -1));
    while(!Q.empty() && kapa < V.size())
    {
        Kapa napa = Q.front();
        Q.pop();
        if(napa.a == -1)
        {
            kapa++;
            continue;
        }
        Kapa alpha = Kapa(napa.a * V[kapa], napa.b, napa.c + 1);
        Kapa beta = Kapa(napa.a, napa.b * V[kapa], napa.c + 1);
        if(placement(a, b, alpha.a, alpha.b))
            return napa.c + 1;
        if(placement(a, b, beta.a, beta.b))
            return napa.c + 1;
        Q.push(alpha);
        Q.push(beta);
    }
    return -1;
}

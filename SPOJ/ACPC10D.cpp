#include <bits/stdc++.h>

using namespace std;


struct Level
{
    int a, b, c;
    Level(int x, int y, int z)
        :a(x), b(y), c(z){}
    Level(){ a = b = c = 0; }
};

int calcSol(vector<Level> &V);

int main()
{
    int n;
    int t = 1;
    while(cin >> n && n != 0)
    {
        vector<Level> V(n);
        int a, b, c;
        for(int i = 0; i < n; i++)
        {
            cin >> a >> b >> c;
            V[i] = Level(a, b, c);
        }
        cout << t << ". " << calcSol(V) << endl;
        t++;
    }
    return 0;
}

int calcSol(vector<Level> &V)
{
    vector<Level> kapa(V.size());
    kapa[0] = Level(INT_MAX - 10000, V[0].b, INT_MAX - 10000);
    for(int i = 1; i < V.size(); i++)
    {
        int alpha = kapa[i - 1].a, beta = kapa[i - 1].b, gama = kapa[i - 1].c;
        int A = V[i].a, B = V[i].b, C = V[i].c;
        int a = V[i - 1].a, b = V[i - 1].b, c = V[i - 1].c;
        kapa[i].a = min(alpha + A, min(alpha + b + A, beta + A));
        kapa[i].b = min(alpha + B, min(kapa[i].a + B, min(beta + B, min(gama + B, beta + c + B))));
        kapa[i].c = min(kapa[i].b + C, min(beta + C, min(gama + C, beta + c + C)));
    }
    return kapa.back().b;
}

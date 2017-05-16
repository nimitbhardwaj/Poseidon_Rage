#include <bits/stdc++.h>

using namespace std;

long long int maxElem(long long int a,long long int b, const vector<long long int> &V)
{
    int max = -1;
    int index = 0;
    for(int i = a; i < b; i++)
        if(V[i] > max)
            max = V[i], index = i;
    return index;
}

int main()
{
    long long int t;
    scanf("%lld", &t);
    while(t--)
    {
        long long int n, m; 
        scanf("%lld %lld", &n, &m);
        vector<long long int> V(n + 1);
        vector<long long int> A(n + 1);
        vector<long long int> dummy(n + 1);
        A[0] = 0;
        for(long long int i = 0; i < n; i++)
        {
            scanf("%lld", &V[i]);
            A[i + 1] = A[i] + V[i];
        }
        stack<long long int> S;
        long long int a;
        for(long long int i = 0; i < m; i++)
        {
            scanf("%lld", &a);
            S.push(a);
        }
        long long int napa = 0, kapa = 0 , maxx = 0;
        while(!S.empty())
        {
            if(kapa == 0)
            {
                kapa = S.top();
                for(long long int i = 0; i + kapa < n + 1; i++)
                {
                    dummy[i] = A[i + kapa] - A[i];
                    //printf("kapa%d: %d %d\n", i, i, i + kapa);
                }
                napa = kapa;
            }
            else
            {
                kapa = S.top();
                for(long long int i = 0; i + kapa < n + 1; i++)
                {
                    maxx=dummy[maxElem(i + 1, i + kapa - napa, dummy)];
                    dummy[i] = A[i + kapa] - A[i] - maxx;
                    //printf("kapa%d: %d %d\n", i, i + 1, i + kapa - napa);
                }
                napa = kapa;
            }
            S.pop();
        }
        printf("%lld\n", dummy[maxElem(0,  n - kapa + 1, dummy)]);
    }
    return 0;
}

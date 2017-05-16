#include<iostream>
#include<climits>
using namespace std;
using ull = unsigned long long;
ull euclid_hcf(ull, ull);
int main(void)
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ull *A = new ull[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        ull min = ULLONG_MAX;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    continue;
                ull kapa = (A[i] * A[j]) / euclid_hcf(A[i], A[j]);
                if(min > kapa)
                    min = kapa;
            }
        }
        cout << min << endl;
        delete[] A;
    }
    return 0;
}

ull euclid_hcf(ull a, ull b)
{
    ull tmp, kapa = 1;
    if(a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    while(kapa)
    {
        kapa = a % b;
        a = b;
        b = kapa;
    }
    return a;
}

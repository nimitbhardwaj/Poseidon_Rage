#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Stone
{
    int red, violet, megenta;
};

int calcAns(vector<Stone> &, vector<int> &sol1, vector<int> &sol2, vector<int> &sol3, int kapa, int prev);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<Stone> V(n);
        vector<int> sol1(n, INT_MAX), sol2(n, INT_MAX), sol3(n, INT_MAX);
        for(int i = 0; i < n; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            Stone tmp = {a, b, c};
            V[i] = tmp;
        }
        cout << calcAns(V, sol1, sol2, sol3, 0, 0) << endl;
    }
    return 0;
}

int calcAns(vector<Stone> &V, vector<int> &sol1, vector<int> &sol2, vector<int> &sol3, int kapa, int prev)
{
    if(kapa == V.size())
        return 0;
    if(prev == 1 && sol1[kapa] != INT_MAX)
        return sol1[kapa];

    if(prev == 2 && sol2[kapa] != INT_MAX)
        return sol2[kapa];

    if(prev == 3 && sol3[kapa] != INT_MAX)
        return sol3[kapa];

    if(prev == 0)
    {
        int a = V[kapa].red + calcAns(V, sol1, sol2, sol3, kapa + 1, 1);
        sol1[kapa] = a;
        int b = V[kapa].violet + calcAns(V, sol1, sol2, sol3, kapa + 1, 2);
        sol2[kapa] = b;
        int c = V[kapa].megenta + calcAns(V, sol1, sol2, sol3, kapa + 1, 3);
        sol3[kapa] = c;
        return min(a, min(b, c));
    }
    else if(prev == 1)
    {
        int b = V[kapa].violet + calcAns(V, sol1, sol2, sol3, kapa + 1, 2);
        //sol2[kapa] = min(b, sol2[kapa]);
        sol2[kapa] = b;
        int c = V[kapa].megenta + calcAns(V, sol1, sol2, sol3, kapa + 1, 3);
        //sol3[kapa] = min(c, sol3[kapa]);
        sol3[kapa] = c;
        return min(b, c);
    }
    else if(prev == 2)
    {
        int a = V[kapa].red + calcAns(V, sol1, sol2, sol3, kapa + 1, 1);
        //sol1[kapa] = min(a, sol1[kapa]);
        sol1[kapa] = a;
        int c = V[kapa].megenta + calcAns(V, sol1, sol2, sol3, kapa + 1, 3);
        //sol3[kapa] = min(c, sol3[kapa]);
        sol3[kapa] = c;
        return min(a, c);
    }
    else
    {
        int a = V[kapa].red + calcAns(V, sol1, sol2, sol3, kapa + 1, 1);
        //sol1[kapa] = min(a, sol1[kapa]);
        sol1[kapa] = a;
        int b = V[kapa].violet + calcAns(V, sol1, sol2, sol3, kapa + 1, 2);
        //sol2[kapa] = min(b, sol2[kapa]);
        sol2[kapa] = b;
        return min(a, b);
        
    }

}

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t, n, k, kapa1, kapa2, kapa, test;
    vector<int> V;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        test = 1;
        V.clear();
        for(int i = 1; i <= n; i++)
        {
            kapa1 = k + i;
            kapa2 = i - k;
            if(kapa1 > 0 && kapa2 > 0)
                kapa = kapa1 < kapa2 ? kapa1 : kapa2;
            else
                kapa = kapa1 > kapa2 ? kapa1 : kapa2;
            if(kapa > n || kapa <= 0)
            {
                test = 0;
                break;
            }
            V.push_back(kapa);
        }
        if(test == 0)
            cout << "CAPTAIN AMERICA EVADES\n";
        else
        {
            for(auto i : V)
                cout << i << ' ';
            cout << endl;
        }

    }
    return 0;
}

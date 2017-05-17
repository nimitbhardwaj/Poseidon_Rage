#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    while(cin >> S && S != "0")
    {
        vector<long long int> V(S.size(), 0);
        bool kapa = true;
        if(S[0] == '0')
        {
            cout << 0 << endl;
            continue;
        }
        for(int i = 0; i < S.size(); i++)
        {
            if(i == 0)
            {
                V[i]++;
                continue;
            }
            else
            {
                if((S[i] == '0' && S[i - 1] == '0') || (S[i] == '0' && S[i - 1] >= '3'))
                {
                    kapa = false;
                    break;
                }
                else if(S[i] == '0' && (S[i - 1] == '1' || S[i - 1] == '2'))
                {
                    if(i - 2 >= 0)
                        V[i] = V[i - 2];
                    else
                        V[i] = 1;
                }
                else if(S[i - 1] == '1')
                {
                    if(i - 2 >= 0)
                        V[i] = V[i - 2] + V[i - 1];
                    else
                        V[i] = 2;
                }
                else if(S[i - 1] == '2' && S[i] <= '6')
                {
                    if(i - 2 >= 0)
                        V[i] = V[i - 2] + V[i - 1];
                    else
                        V[i] = 2;
                }
                else
                {
                    V[i] = V[i - 1];
                }
            }
        }
        if(kapa)
        {
            cout << V[S.size() - 1] << endl;
        }
        else
            cout << 0 << endl;
    }
    return 0;
}

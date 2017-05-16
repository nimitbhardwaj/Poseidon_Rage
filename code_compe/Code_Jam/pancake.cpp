#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int j = 1; j <= t; j++)
    {
        string S;
        int kapa;
        cin >> S >> kapa;
        vector<int> V(S.size(), 0);
        int napa = 0;
        for(int i = 0; i < S.size(); i++)
        {
            if(i != 0)
                V[i] += V[i - 1];
            if(i >= S.size() - kapa + 1)
                continue;
            if(S[i] == '-' && V[i] % 2 == 0)
            {
                V[i] += 1;
                try
                {
                    V.at(i + kapa + 1) -= 1;
                }catch(out_of_range &e) {}
                napa++;
            }
            else if(S[i] == '+' && V[i] % 2 == 1)
            {
                V[i] += 1;
                try
                {
                    V.at(i + kapa + 1) -= 1;
                }catch(out_of_range &e) {}
                napa++;
            }
        }
    cout << "Case #" << j << ": " << napa << endl;
    }
    return 0;
}

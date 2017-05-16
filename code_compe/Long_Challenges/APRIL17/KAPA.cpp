#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string S;
        cin >> S;
        int sexyCount = 0, answer = 0;
        bool kapa = false;
        for(int i = 0; i < S.size(); i++)
        {
            if(S[i] == '1')
            {
                sexyCount++;
                kapa = true;
            }
            if(S[i] == '0' && kapa == true)
            {
                kapa = false;
                answer += sexyCount;
            }
        }
        int prev = 1;
        for(int i = S.size() - 1; i >= 0; i--)
        {
            if(S[i] == '1')
            {
                answer = answer + S.size() - i - prev;
                prev++;
            }
        }
        cout << answer << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    int state = 0;
    bool kapa = false;
    for(int i = 0; i < S.size(); i++)
    {
        if(state == 0 && S[i] == 'h')
            state++;
        else if(state == 1 && S[i] == 'e')
            state++;
        else if(state == 2 && S[i] == 'l')
            state++;
        else if(state == 3 && S[i] == 'l')
            state++;
        else if(state == 4 && S[i] == 'o')
            state++;
        if(state == 5)
        {
            kapa = true;
            break;
        }
    }
    if(kapa)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}

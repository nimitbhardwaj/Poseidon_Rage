#include <bits/stdc++.h>

using namespace std;

 int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string S;
        cin >> S;
        bool head = false;
        bool valid = true;
        for(int i = 0; i < S.size(); i++)
        {
            if(head == false && S[i] == 'H')
                head = true;
            else if(head == false && S[i] == 'T')
            {
                valid = false;
                break;
            }
            else if(head == true && S[i] == 'T')
                head = false;
            else if(head == true && S[i] == 'H')
            {
                valid = false;
                break;
            }
        }
        if(valid)
        {
            if(head)
                cout << "Invalid" << endl;
            else
                cout << "Valid" << endl;
        }
        else
            cout << "Invalid" << endl;
    }
    return 0;
}

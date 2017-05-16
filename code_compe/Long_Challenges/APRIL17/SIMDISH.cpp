#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<string> V1(4);
        vector<string> V2(4);
        for(int i = 0; i < 4; i++)
            cin >> V1[i];
        for(int i = 0; i < 4; i++)
            cin >> V2[i];
        int ctr = 0;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                if(V1[i] == V2[j])
                    ctr++;
        if(ctr >= 2)
            cout << "similar" << endl;
        else
            cout << "dissimilar" << endl;
    }
    return 0;
}

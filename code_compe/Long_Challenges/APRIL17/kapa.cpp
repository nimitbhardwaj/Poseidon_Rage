#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<bool> visi(k, false);
        bool kapa = true;
        for(int i = 0; i < n; i++)
        {
            int tmp, a;
            bool napa = false;
            cin >> tmp;
            for(int j = 0; j < tmp; j++)
            {
                cin >> a;
                a--;
                if(visi[a] == true)
                    continue;
                visi[a] = true;
                napa = true;
            }
            if(napa == false)
                kapa = false;
        }
        bool napa = true;
        for(int i = 0; i < visi.size(); i++)
        {
            if(visi[i] == false)
            {
                napa = false;
                break;
            }
        }
        if(napa == false)
        {
            cout << "sad" << endl;
            continue;
        }
        if(kapa == true)
        {
            cout << "all" << endl;
        }
        else
            cout << "some" << endl;
    }
    return 0;
}

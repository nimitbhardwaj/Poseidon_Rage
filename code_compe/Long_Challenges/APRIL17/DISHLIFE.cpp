#include <bits/stdc++.h>

using namespace std;

bool comp(const vector<int> *a, const vector<int> *b)
{ return a->size() >= b->size(); }

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int k, n;
        cin >> n >> k;
        vector<vector<int> > V(n, vector<int>());
        vector<vector<int> *> pV(n, NULL);
        for(int i = 0; i < n; i++)
        {
            int tmp, a;
            cin >> tmp;
            for(int j = 0; j < tmp; j++)
            {
                cin >> a;
                V[i].push_back(a - 1);
            }
            pV[i] = &V[i];
        }

        sort(pV.begin(), pV.end(), comp);
        vector<bool> ingredient(k, false);
        bool kapa = false;
        for(int i = 0; i < pV.size(); i++)
        {
            bool napa = true;
            for(int j = 0; j < pV[i]->size(); j++)
            {
                if(ingredient[pV[i]->at(j)])
                    continue;
                napa = false;
                ingredient[pV[i]->at(j)] = true;
            }
            if(napa == true)
                kapa = true;
        }
        bool napa = false;
        for(int i = 0; i < ingredient.size(); i++)
        {
            if(ingredient[i] == false)
            {
                cout << "sad" << endl;
                napa = true;
                break;
            }
        }
        if(napa == true)
            continue;
        if(kapa == false)
            cout << "all" << endl;
        else
            cout << "some" << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int bfs(string &S1, string &S2, vector<string> &V);


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<string> V;
        string tmp;
        while(true)
        {
            cin >> tmp;
            if(tmp.find('*') != string::npos)
                break;
            V.push_back(tmp);
        }
        getchar();
        sort(V.begin(), V.end());
        int kapa = 0;
        while(true)
        {
            getline(cin, tmp);
            if(tmp.length() == 0)
                break;
            int a = tmp.find(' ');
            string S1 = string(tmp.begin(), tmp.begin() + a);
            string S2 = string(tmp.begin() + a + 1, tmp.end());
            cout << S1 << ' ' << S2 << ' ' << bfs(S1, S2, V) << endl;
            kapa++;
        }
        if(t != 0)
            cout << endl;
    }
    return 0;
}

int bfs(string &S1, string &S2, vector<string> &V)
{
    queue<string> Q;
    Q.push(S1);
    Q.push("-1");
    map<string, bool> hash;
    hash[S1] = true;
    int count = 0;
    while(!Q.empty())
    {
        string tmp = Q.front();
        Q.pop();
        if(tmp == "-1")
        {
            count++;
            if(Q.empty())
                break;
            Q.push("-1");
            continue;
        }
        for(int i = 0; i < tmp.size(); i++)
        {
            for(int j = 0; j < 26; j++)
            {
                if(tmp[i] == 'z')
                    tmp[i] = 'a';
                else
                    tmp[i]++;
                //cout << tmp << ' ' << (binary_search(V.begin(), V.end(), tmp)) << endl;
                if(binary_search(V.begin(), V.end(), tmp) && !hash[tmp])
                {
                    hash[tmp] = true;
                    Q.push(tmp);
                    if(tmp == S2)
                        return count + 1;
                }
            }
        }
    }
    return 0;
}


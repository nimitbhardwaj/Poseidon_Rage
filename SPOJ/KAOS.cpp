#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

bool operator<(const pair<string, string> &a, const pair<string, string> &b);
bool operator<(const string &a, const string &b);

int main()
{
    int n;    
    cin >> n;
    vector<pair<string, string> > V;
    for(int i = 0; i < n; i++)
    {
        string tmp, tmp1;
        cin >> tmp;
        tmp1 = tmp;
        reverse(tmp.begin(), tmp.end());
        V.push_back(make_pair(tmp1, tmp));
    }
    sort(V.begin(), V.end());
    vector<int> ans(n, 0);
    for(int i = 0, j = 0; i < n; i++)
    {
        if(V[j].second < V[i].second)
        {
            ans[i] = 0;
            ans[j]++;
            ans[i + 1] = -1;
        }
        else
        {
            j++;
            i--;
            continue;
        }
    }
    for(int i = 0; i < V.size(); i++)
        cout << V[i].first << ' ' << V[i].second << endl;
    return 0;   
}
bool operator<(const pair<string, string> &a, const pair<string, string> &b)
{
    for(int i = 0; i < min(a.first.size(), b.first.size()); i++)
    {
        if(a.first[i] < b.first[i])
            return true;
        else if(a.first[i] == b.first[i])
            continue;
        else
            return false;
    }
    return false;
}

bool operator<(const string &a, const string &b)
{
    for(int i = 0; i < min(a.size(), b.size()); i++)
    {
        if(a[i] < b[i])
            return true;
        else if(a[i] == b[i])
            continue;
        else
            return false;
    }
    return false;
}

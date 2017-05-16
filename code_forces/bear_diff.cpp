#include <iostream>
#include <string>
#include <vector>

using namespace std;

void nameStarts(vector<string> &V, char c);

int main()
{
    int n, k;
    cin >> n >> k;
    vector<bool> stolenList;
    vector<string> names;
    for(int i = 0; i < n - k + 1; i++)
    {
        string tmp;
        cin >> tmp;
        if(tmp == "NO")
            stolenList.push_back(false);
        else
            stolenList.push_back(true);
    }
    nameStarts(names, 'A');
    nameStarts(names, 'B');
    nameStarts(names, 'C');
    nameStarts(names, 'D');
    return 0;
}

void nameStarts(vector<string> &V, char c)
{
    string S = "";
    S = S + c;
    for(int i = 0; i < 26; i++)
    {
        V.push_back(S + char('a' + i));
    }
}

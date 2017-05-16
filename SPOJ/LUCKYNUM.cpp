#include <bits/stdc++.h>

using namespace std;

struct Kapa
{
    string S;
    long long int n;
    bool flag;
    Kapa(string s, long long int k, bool napa)
        :S(s), n(k), flag(napa) {}
};

string bfs(long long int n);



int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long int n;
        cin >> n;
        //if(n % 5 == 0)
        //{
            //cout << -1 << endl;
            //continue;
        //}
        cout << bfs(n) << endl;
    }
    return 0;
}

string bfs(long long int n)
{
    queue<Kapa> Q;
    int level = 0;
    Q.push(Kapa("", 0, false));
    Q.push(Kapa("", -1, false));
    while(!Q.empty() && level <= 200)
    {
        Kapa a = Q.front();
        if(a.n == -1)
        {
            level++;
            Q.push(a);
            Q.pop();
            continue;
        }
        if(a.n % n == 0 && a.S != "")
            return a.S;
        if(a.S[a.S.size() - 1] == '6' && a.flag == true)
            Q.push(Kapa(a.S + '6', (10 * a.n + 6) % n, true));
        else if(a.S[a.S.size() - 1] == '8' && a.flag == false)
        {
            Q.push(Kapa(a.S + '6', (10 * a.n + 6) % n, true));
            Q.push(Kapa(a.S + '8', (10 * a.n + 8) % n, false));
        }
        else if(a.S == "")
        {
            Q.push(Kapa(a.S + '6', (10 * a.n + 6) % n, true));
            Q.push(Kapa(a.S + '8', (10 * a.n + 8) % n, false));
        }
        Q.pop();
    }
    return string("-1");
}

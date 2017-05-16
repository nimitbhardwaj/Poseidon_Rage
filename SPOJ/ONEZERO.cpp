#include <bits/stdc++.h>

using namespace std;

struct Kapa
{
    string S;
    long long int n;
    Kapa(string s, long long int k)
        :S(s), n(k) {}
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
        cout << bfs(n) << endl;
    }
    return 0;
}

string bfs(long long int n)
{
    queue<Kapa> Q;
    Q.push(Kapa("1", 1));
    while(!Q.empty())
    {
        Kapa a = Q.front();
        if(a.n % n == 0)
            return a.S;
        Q.push(Kapa(a.S + '0', (10 * a.n) % n));
        Q.push(Kapa(a.S + '1', (10 * a.n + 1) % n));
        Q.pop();
    }
}

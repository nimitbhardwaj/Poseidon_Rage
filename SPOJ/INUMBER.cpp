#include <bits/stdc++.h>

using namespace std;

struct Move
{
    int n, sum;
    string num;
    Node(string S, int s, int N)
        :num(S), sum(s), n(N) {}
};

string bfs(int n);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << bfs(n) << endl;
    }
    return 0;
}

string bfs(int n)
{
    queue<Node> Q;
    Q.push(Node("", 0, 0));
    while(!Q.empty())
    {
        Node napa = Q.front();
        Q.pop();
        if(napa.sum == n && napa.n % n == 0)
            return napa.num;
        for(int i = 0; i <= 9; i++)
        {
            if(napa.num == "" && i == 0)
                continue;
            if(napa.sum + i <= n)
                Q.push(Node(napa.num + char(i + '0'), napa.sum + i, (10 * napa.n + i) % n));
        }
    }
}

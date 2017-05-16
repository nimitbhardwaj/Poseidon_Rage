#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

void makeSieve(vector<bool> &);

int main()
{
    int t;
    vector<bool> sieve(10100, true);
    makeSieve(sieve);
    cin >> t;
    while(t--)
    {
        queue<int> Q;
        int a, b, level = 0;
        vector<bool> visited(10000, false);
        cin >> a >> b;
        if(sieve[a] == false || sieve[b] == false)
        {
            cout << "Impossible" << endl;
            continue;
        }
        Q.push(a);
        visited[a] = true;
        Q.push(-1);
        while(Q.front() != b)
        {
            int kapa = Q.front();
            Q.pop();
            if(kapa == -1)
            {
                Q.push(-1);
                level++;
                continue;
            }
            for(int i = kapa + 1; i != kapa; i++)
            {
                if(i % 10 == 0)
                    i -= 10;
                if(i == kapa)
                    break;
                if(sieve[i] == true && visited[i] == false)
                {
                    Q.push(i);
                    visited[i] = true;
                }
            }
            for(int i = kapa + 10; i != kapa; i += 10)
            {
                if((i / 10) % 10 == 0)
                    i -= 100;
                if(i == kapa)
                    break;
                if(sieve[i] == true && visited[i] == false)
                {
                    Q.push(i);
                    visited[i] = true;
                }
            }
            for(int i = kapa + 100; i != kapa; i += 100)
            {
                if((i / 100) % 10 == 0)
                    i -= 1000;
                if(i == kapa)
                    break;
                if(sieve[i] == true && visited[i] == false)
                {
                    Q.push(i);
                    visited[i] = true;
                }
            }
            for(int i = kapa + 1000; i != kapa; i += 1000)
            {
                if((i / 1000) % 10 == 0)
                    i = i - 10000 + 1000;
                if(i == kapa)
                    break;
                if(sieve[i] == true && visited[i] == false)
                {
                    Q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << level << endl;
    }
    return 0;
}

void makeSieve(vector<bool> &V)
{
    V[0] = V[1] = false;
    for(int i = 2; i * i <= V.size(); i++)
    {
        if(V[i] == true)
        {
            for(int j = 2 * i; j < V.size(); j++)
                if(j % i == 0)
                    V[j] = false;
        }
    }
}

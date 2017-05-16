#include <bits/stdc++.h>
#define lld long long int
#define mp make_pair

using namespace std;

struct Comp
{
    bool operator() (const lld a, const lld b)
    { return a < b; }
};

void Sieve(vector<bool> &);
void getFactors(lld a, lld b, vector<lld> &, vector<vector<pair<lld, lld> > > &, vector<bool> &);

int main()
{
    lld a, b;
    cin >> a >> b;
    vector<bool> sieve(1001000, true);
    vector<lld> primes;
    Sieve(sieve);
    for(lld i = 0; i < sieve.size(); i++)
        if(sieve[i])
            primes.push_back(i);//, cout << i << endl;
    //return 0;
    vector<vector<pair<lld, lld> > > V(b - a + 1);
    getFactors(a, b, primes, V, sieve);
    //for(lld i = 0; i < V.size(); i++)
    //{
        //cout << "case" << i + a << endl;
        //for(lld j = 0; j < V[i].size(); j++)
        //{
            //cout << V[i][j].first << ' ' << V[i][j].second << endl;
        //}
    //}
    lld sum = 0;
    for(long long int i = 0; i < V.size(); i++)
    {
        priority_queue<lld, vector<lld>, Comp> Q;
        lld kapa = 1;
        lld alpha = 0;
        for(long long int j = 0; j < V[i].size(); j++)
        {
                Q.push(V[i][j].second);
                kapa *= V[i][j].second + 1;
        }
        sum += kapa;
        while(!Q.empty())
        {
            alpha = Q.top();
            Q.pop();
            kapa = (kapa / (alpha + 1)) * (alpha);
            sum += kapa;
            if(alpha == 1)
                continue;
            Q.push(alpha - 1);
        }
        sum--;
    }
    cout << sum << endl;
    return 0;
}

void Sieve(vector<bool> &sieve)
{
    sieve[0] = sieve[1] = false;
    for(lld i = 2; i * i <= sieve.size(); i++)
    {
        if(sieve[i] == true)
        {
            for(lld j = i * i; j < sieve.size(); j += i)
                if(j % i == 0)
                    sieve[j] = false;
        }
    }
}

void getFactors(lld a, lld b, vector<lld> &primes, vector<vector<pair<lld, lld> > > &V, vector<bool> &sieve)
{
    lld alpha, kapa;
    vector<bool> poseidon(b - a + 100, true);
    if(a > 100000000)
    {
        for(long long int i = 0; i < primes.size(); i++)
        {
            long long int napa = (a / primes[i]) * primes[i];
            if(napa < a)
                napa += primes[i];
            for(long long int j = napa; j <= b; j += primes[i])
            {
                poseidon[j - a] = false;
            }
        }
    }
    //for(long long int i = 0; i <= b - a + 1; i++)
        //if(poseidon[i] == true)
            //cout << i + a << endl;
    for(lld i = a; i <= b; i++)
    {
        alpha = i;
        for(lld j = 0; primes[j] * primes[j] <= alpha; j++)
        {
            if(alpha < 1000000 && sieve[alpha])
                break;
            if(alpha > 100000000 && alpha - a >= 0 && poseidon[alpha - a] == true)
                break;
            kapa = 0;
            while(alpha % primes[j] == 0)
            {
                alpha = alpha / primes[j];
                kapa++;
            }
            if(kapa != 0)
                V[i - a].push_back(mp(primes[j], kapa));
        }
        if(alpha != 1)
            V[i - a].push_back(mp(alpha, 1));
    }
}

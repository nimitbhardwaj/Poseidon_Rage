#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int binarySearch(int, int, vector<pair<pair<int, int>, int> > &, int);
bool comp1(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
{
    return a.second < b.second;
}

int main()
{
    int n, napa = -1, a, q;
    std::cin >> n >> q;
    vector<int> V;
    vector<pair<pair<int, int>, int> > poseidon;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        V.push_back(a);
        if(a != napa)
        {
            poseidon.push_back(make_pair(make_pair(a, i), 1));
            napa = a;
        }
        else
        {
            poseidon.back().second += 1;
        }
    }
    for(int i = 0; i < poseidon.size(); i++)
        cout << poseidon[i].first.first << ' ' << poseidon[i].first.second << ' ' << poseidon[i].second << endl;
    while(q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        int alpha = binarySearch(0, poseidon.size(), poseidon, l);
        int beta = binarySearch(0, poseidon.size(), poseidon, r);
        if(alpha == beta)
        {
            if(beta - alpha + 1 < k)
                cout << -1 << endl;
            else
                cout << poseidon[beta].first.first << endl;
        }
        else
        {
            pair<pair<int, int>, int> maxy = {{0, 0}, 0};
            for(int i = alpha + 1; i < beta; i++)
            {
                if(!(poseidon[i] < maxy))
                    maxy = poseidon[i];
            }
            std::cout << maxy.second << ' ' << maxy.first.first << endl;

        }
    }
    return 0;
}

int binarySearch(int l, int r, vector<pair<pair<int, int> , int> > &V, int a)
{
    int kapa = (l + r) / 2;
    if(l == r)
    {
        cout << "hello" << endl;
        return l - 1;
    }
    if(a < V[kapa].first.second)
        return binarySearch(l, kapa, V, a);
    else if(a > V[kapa].first.second)
        return binarySearch(kapa + 1, r, V, a);
    else if(a == V[kapa].first.second)
    {
        cout << "kapa" << endl;
        return kapa;
    }
}

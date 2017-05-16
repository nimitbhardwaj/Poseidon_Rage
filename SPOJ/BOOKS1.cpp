#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int binarySearch(int kapa, int napa, vector<int> &V, int strt, int end);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int m, k;
        cin >> m >> k;
        vector<int> V(m, 0), cV(m, 0);
        for(int i = 0; i < m; i++)
        {
            int tmp;
            cin >> tmp;
            V[i] = tmp;
            if(i == 0)
                cV[i] = tmp;
            else
                cV[i] = cV[i - 1] + tmp;
        }
        queue<int> Q;
        int kapa = 0, prevInd = 0;
        for(int i = 0; i < cV.size(); i++)
            cout << cV[i] << endl;
        for(int i = 0; i < k - 1; i++)
        {
            int l = binarySearch(kapa, cV.back() / k, cV, prevInd, V.size() - 1);
            l++;
            prevInd = l;
            kapa = cV[l];
            Q.push(l);
        }
        for(int i = 0; i < V.size(); i++)
        {
            if(Q.front() == i)
            {
                cout << '/' << ' ';
                Q.pop();
            }
            cout << V[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}

int binarySearch(int kapa, int napa, vector<int> &V, int strt, int end)
{
    int mid = (strt + end) / 2;
    if(strt >= end)
        return strt;
    if(V[mid] - kapa < napa)
        binarySearch(kapa, napa, V, mid + 1, end);
    else if(V[mid] - kapa > napa)
        binarySearch(kapa, napa, V, strt, mid);
    else
        return mid;
}

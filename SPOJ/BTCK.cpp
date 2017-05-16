#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool calcSol(vector<int> &, vector<int> &, int, int, int *a);
bool hasI(vector<int> &, int);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<int> inputs(10), out;
        int k, n = 10;
        for(int i = 0; i < n; i++)
            cin >> inputs[i];
        cin >> k;
        int sum = 0;
        bool sol = calcSol(inputs, out, n, k, &sum);
        if(sol == false)
        {
            cout << -1 << endl;
            continue;
        }
        for(int i = 0; i < out.size(); i++)
            cout << out[i] << ' ';
        cout << endl;
    }
    return 0;
}

bool calcSol(vector<int> &inputs, vector<int> &out, int n, int k, int *sum)
{
    if(n == 0)
    {
        if(*sum <= k)
            return true;
        else
            return false;
    }
    for(int i = 0; i < 10; i++)
    {
        if(hasI(out, i))
            continue;
        *sum += i * inputs[out.size()];
        if(*sum > k)
        {
            *sum -= i * inputs[out.size()];
            continue;
        }
        out.push_back(i);
        if(calcSol(inputs, out, n - 1, k, sum))
            return true;
        out.pop_back();
        *sum -= i * inputs[out.size()];
    }
    return false;
}

bool hasI(vector<int> &out, int i)
{
    for(int j = 0; j < out.size(); j++)
        if(out[j] == i)
            return true;
    return false;
}

#include <iostream>
#include <vector>

using namespace std;

bool isCool(vector<int> &, int sum, int kapa, vector<bool> &);

int main()
{
    vector<int> cool;
    int count = 0;
    for(int i = 11; i < 100000; i++)
    {
        int k = i, sum = 0;
        vector<int> V;
        while(k)
        {
            V.push_back(k % 10);
            sum += k % 10;
            k /= 10;
        }
        vector<bool> visited(V.size(), false);
        if(isCool(V, sum, 0, visited))
            count++, cool.push_back(i), cout << i << ' ' << count << endl;
    }
    //for(int i = 0; i < cool.size(); i++)
        //cout << cool[i] << endl;
    cout << "Hello" << endl;
    return 0;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> V;
        int sum = 0;
        while(n)
        {
            V.push_back(n % 10);
            sum += n % 10;
            n /= 10;
        }
        vector<bool> visited(V.size(), false);
        if(isCool(V, sum, 0, visited))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}

bool isCool(vector<int> &V, int sum, int kapa, vector<bool> &visited)
{
    if(sum % 2 == 1)
        return false;
    if(kapa == sum / 2)
        return true;
    for(int i = 0; i < V.size(); i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            kapa += V[i];
            if(isCool(V, sum, kapa, visited))
                return true;
            kapa -= V[i];
            visited[i] = false;
        }
    }
    return false;
}


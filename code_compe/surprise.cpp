#include <iostream>
#include <vector>

using namespace std;

bool isMagical(int);

int main()
{
    int n;
    vector<int> V(1011, 0);
    for(int i = 1; i <= 1010; i++)
    {
        if(isMagical(i))
        {
            V[i] = 1;
        }
    }
    for(int i = 1; i < V.size(); i++)
    {
        V[i] = V[i] + V[i - 1];
    }
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        cout << V[x - 1] << endl;
    }
    return 0;
}

bool isMagical(int a)
{
    int odd = 0, even = 0;
    while(a)
    {
        if((a % 10) % 2 == 0)
            even++;
        else
            odd++;
        a /= 10;
    }
    if(even > odd)
        return true;
    else
        return false;
}

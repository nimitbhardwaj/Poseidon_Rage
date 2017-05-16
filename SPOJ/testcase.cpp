#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << a << ' ' << b << endl;
    time_t k;
    srand(time(&k));
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            if(rand() % 4 == 0)
                cout << 1;
            else
                cout << 0;
        }
        cout << endl;
    }
    return 0;
}

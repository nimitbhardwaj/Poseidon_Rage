#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.get();
    for(int i = 1; i <= n; i++)
    {
        stack<int> kapa;
        int maxy = 0;
        kapa.push(0);
        string S;
        char c = ' ';
        while((c = cin.get()) != '\n')
        {
            S += c;
            if(c == '[')
            {
                kapa.push(kapa.top() + 1);
                maxy = max(maxy, kapa.top());
            }
            else if(c == ']')
                kapa.pop();
        }
        cout << i << ' ' << (1 << maxy) << endl;
    }
    return 0;
}

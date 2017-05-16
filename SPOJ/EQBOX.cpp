#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        if(a * a + b * b > x * x + y * x)
            cout << "Escape is possible." << endl;
        else
            cout << "Box cannot be dropped." << endl;
    }
    return 0;
}

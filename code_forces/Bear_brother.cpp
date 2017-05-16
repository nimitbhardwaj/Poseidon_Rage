#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int n = 0, alpha = 1, beta = 1;
    while(a * alpha <= b * beta)
    {
        alpha *= 3;
        beta *= 2;
        n++;
    }
    cout << n << endl;
    return 0;
}

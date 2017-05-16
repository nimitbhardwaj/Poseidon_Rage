#include <iostream>
#include <string>

using namespace std;

int leftOne(unsigned long long int);

int main()
{
    unsigned long long int n, l, r;
    cin >> n >> l >> r;
    cout << leftOne(n) << endl;
    return 0;
}

int leftOne(unsigned long long int n)
{
    int a = 0;
    while(n > 1)
    {
        n = n / 2;
        a++;
    }
    return a;
}

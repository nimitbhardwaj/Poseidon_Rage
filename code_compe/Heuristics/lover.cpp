#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    unsigned int n, x, k;
    std::cin >> n >> x >> k;
    unsigned int kapa = 1, napa;
    std::vector<unsigned int> A(n), forward(n, 0), backward(n, 0);
    while(k--)
        kapa *= x;
    for(int i = 0; i < n; i++)
    {
        std::cin >> A[i];
    }
    forward[0] = A[0];
    backward[n - 1] = A[n - 1];
    for(int i = 1; i < n; i++)
        forward[i] = forward[i - 1] | A[i];
    for(int i = n - 2; i >= 0; i--)
        backward[i] = backward[i + 1] | A[i];
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
            napa = (A[0] * kapa) | backward[1];
        else if(i == n - 1)
            napa = std::max(napa, (A[i] * kapa ) | forward[n - 2]);
        else
            napa = std::max(napa, forward[i - 1] | (A[i] * kapa) | backward[i + 1]);
    }
    std::cout << napa << std::endl;
    return 0;
}

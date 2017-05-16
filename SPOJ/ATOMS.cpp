#include <iostream>

int main()
{
    long long unsigned m, n, k;
    int t;
    std::cin >> t;
    while(t--)
    {
        float time = 0;
        std::cin >> n >> k >> m;
        if(m < n)
        {
            std::cout << 0 << std::endl;
            continue;
        }
        while(n <= m)
        {
            m = m / k;
            time++;
        }
        std::cout << time - 1 << std::endl;
    }
    return 0;
}

#include <iostream>
int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        if(a + b <= c)
        {
            std::cout << "NO" << std::endl;
            continue;
        }
        if(a + c <= b)
        {
            std::cout << "NO" << std::endl;
            continue;
        }
        if(b + c <= a)
        {
            std::cout << "NO" << std::endl;
            continue;
        }
        std::cout << "YES" << std::endl;
    }
    return 0;
}

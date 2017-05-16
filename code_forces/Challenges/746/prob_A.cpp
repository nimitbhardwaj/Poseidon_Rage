#include <iostream>
#include <algorithm>
int main()
{
    int a, b, c, ka, kb, kc;
    std::cin >> a >> b >> c;
    ka = a / 1;
    kb = b / 2;
    kc = c / 4;
    int val = std::min(ka, std::min(kb, kc));
    std::cout << val * 7 << std::endl;
    return 0;
}

#include <iostream>
#include <vector>

int main()
{
    int n, sum = 0;
    std::cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int tmp;
        std::cin >> tmp;
        sum += tmp;
    }
    std::cout << (n * (n + 1)) / 2 - sum << std::endl;
    return 0;
}

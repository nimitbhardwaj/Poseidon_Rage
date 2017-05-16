#include <iostream>

int main()
{
    int n, t = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        std::cin >> tmp;
        if(tmp == 1)
            t++;
    }
    std::cout << t / 4 + 1 + t % 2 << std::endl;
    return 0;
}

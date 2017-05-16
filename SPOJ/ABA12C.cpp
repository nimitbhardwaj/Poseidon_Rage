#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> price(k + 1);
        for(int i = 1; i <= k; i++)
            std::cin >> price[i];
        std::vector<int> kapa(price);
        for(int i = 2; i <= k; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                if(price[i - j] == -1 || kapa[j] == -1)
                    continue;
                if(kapa[i] == -1)
                    kapa[i] = kapa[j] + price[i - j];
                else
                    kapa[i] = std::min(kapa[i], kapa[j] + price[i - j]);
            }
        }
        if(k == 0)
            std::cout << 0 << std::endl;
        else
            std::cout << kapa[k] << std::endl;
    }
    return 0;
}

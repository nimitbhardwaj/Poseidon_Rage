#include <iostream>

int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int n, sync = 0;
        std::cin >> n;
        short int val;
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            std::cin >> val;
            if(val == 0)
                res += 1100;
            else if(val == 1 && sync == i)
                sync++;
            else if(val == 1 && sync != i)
                sync++, res += 100;
        }
        std::cout << res << std::endl;
    }
    return 0;
}

#include <iostream>
int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int p, q;
        int ans;
        std::cin >> p >> q; 
        if(p == 2)
            ans = 0;
        else
            ans = 1;
        std::cout << ans << std::endl;
    }
    return 0;
}

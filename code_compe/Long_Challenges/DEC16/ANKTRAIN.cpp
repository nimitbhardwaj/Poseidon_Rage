#include <iostream>
#include <string>
int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int n;
        std::string S;
        std::cin >> n;
        int a = n % 8, b = n / 8;
        int kapa;
        if(a == 3 || a == 6)
            S = "UB", kapa = 9 - a;
        else if(a == 2 || a == 5)
            S = "MB", kapa = 7 - a;
        else if(a == 1 || a == 4)
            S = "LB", kapa = 5 - a;
        else if(a == 7)
            S = "SU", kapa = 8;
        else if(a == 0)
            S = "SU", kapa = 7;
        kapa = kapa + b * 8;
        if(n % 8 == 0)
            std::cout << n - 1 << "SL" << std::endl;
        else
            std::cout << std::to_string(kapa) + S << std::endl;
    }
    return 0;
}

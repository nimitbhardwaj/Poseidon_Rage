#include <iostream>
int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        unsigned int c, d, l;
        std::cin >> c >> d >> l;
        unsigned int max = 4 * (c + d);
        unsigned int min = 4 * d;
        if(c <= 2 * d)
            min += 0;
        else
        {
            c -= 2 * d;
            min += 4 * c;
        }
        if(l % 4 != 0)
            std::cout << "no" << std::endl;
        else
            if(l <= max && l >= min)
                std::cout << "yes" << std::endl;
            else
                std::cout << "no" << std::endl;
    }
    return 0;
}

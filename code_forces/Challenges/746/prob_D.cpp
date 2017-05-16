#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    int n, k, a, b;
    std::cin >> n >> k >> a >> b;
    std::string S(n, 0);
    char tea = 'G';
    if(a < b)
        std::swap(a, b), tea = 'B';
    int fl = 0;
    int saint = 0;
    for(int i = 0; i < n; i++)
    {
        if(saint >= k)
        {
            if(tea == 'G')
                tea = 'B';
            else
                tea = 'G';
            saint = 0;
        }
        S += tea;
        saint++;
        if(tea == 'G')
            a--;
        else
            b--;
        if(a < 0 || b < 0)
        {
            fl = 1;
            break;
        }
    }
    if(fl == 1)
        std::cout << "NO" << std::endl;
    else
        std::cout << S << std::endl;
    return 0;
}

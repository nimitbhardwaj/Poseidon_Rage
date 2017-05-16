#include<iostream>
int main()
{
    int n, d = 0, a = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        char c = std::cin.get();
        if(c == 'D')
            d++;
        else
            a++;
    }
    if(a > d)
        std::cout << "Anton" << std::endl;
    else if(a < d)
        std::cout << "Danik" << std::endl;
    else
        std::cout << "Friendship" << std::endl;
    return 0;
}


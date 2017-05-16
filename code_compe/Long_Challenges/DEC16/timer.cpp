#include <iostream>
int main()
{
    int a = 1;
    for(int i = 0; i < 10000; i++)
    {
        for(int j = 0; j < 10000; j++)
            a = 1;
    }
    std::cout << a << std::endl;
    return 0;
}

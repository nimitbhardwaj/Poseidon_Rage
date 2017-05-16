#include <iostream>
#include <cmath>

int pow_of_2(int);
int pow_of_3(int);
int powk(int a, int b);

int main()
{
    int n, temp;
    bool kapa = false;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        int p2 = pow_of_2(a);
        int p3 = pow_of_3(a);
        a = a / (pow(2, p2) * pow(3, p3));
        if(i == 0)
            temp = a;
        else
        {
            if(temp == a)
                temp = a;
            else
            {
                kapa = true;
            }
        }
    }
    if(kapa == true)
        std::cout << "NO" << std::endl;
    else
        std::cout << "YES" << std::endl;
    return 0;
}

int pow_of_2(int a)
{
    int ret = 0;
    while(a % 2 == 0)
        ret++, a /= 2;
    return ret;
}
int pow_of_3(int a)
{
    int ret = 0;
    while(a % 3 == 0)
        ret++, a /= 3;
    return ret;
}

int powk(int a, int b)
{
    int ret = 1;
    for(int i = 0; i < b; i++)
        ret *= a;
    return ret;
}


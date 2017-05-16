#include<iostream>
int main()
{
    long long int a, b, c, d, t;
    std::cin >> t;
    while(t--)
    {
        long long int v = 0;
        std::cin >> a >> b >> c >> d;
        for(long long int i = a; i <= b; i++)
        {
            if(i < c)
                v += d - c + 1;
            else
                if(i <= d)
                    v += d - i;
        }
        std::cout << v << std::endl;
    }
    return 0;
}

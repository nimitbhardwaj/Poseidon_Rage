#include <iostream>
#include <string>
int main()
{
    int n;
    std::cin >> n;
    std::string S;
    std::cin >> S;
    std::string O(n, 0);
    int cent = (n - 1) / 2;
    int fl = 0, val = 1;
    if(n % 2 == 1)
    {
        O[cent] = S[0];
        for(int i = 1; i < n; i++)
        {
            if(fl == 0)
            {
                fl = 1;
                if(cent - val < 0)
                    continue;
                O[cent - val] = S[i];
            }
            else
            {
                fl = 0;
                if(cent + val >= n)
                {
                    val++;
                    continue;
                }
                O[cent + val] = S[i];
                val++;
            }
        }
    }
    else
    {
        O[cent] = S[0];
        O[cent + 1] = S[1];
        for(int i = 2; i < n; i++)
        {
            if(fl == 0)
            {
                fl = 1;
                if(cent - val < 0)
                    continue;
                O[cent - val] = S[i];
            }
            else
            {
                fl = 0;
                if(cent + val + 1 >= n)
                {
                    val++;
                    continue;
                }
                O[cent + val + 1] = S[i];
                val++;
            }
        }   

    }
    std::cout << O << std::endl;
}

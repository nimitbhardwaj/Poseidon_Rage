#include <iostream>
#include <string>


int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int o1, o2;
        std::cin >> o1 >> o2;
        std::string S("");
        int *A = new int[o1]();
        bool *winning = new bool[o1]();
        int winSum = 0;
        for(int i = 0; i < o1; i++)
        {
            int a;
            for(int j = 0; j < o2; j++)
            {
                std::cin >> a;
                S += '0' + a;
                A[i] += a;
            }
            if(A[i] > o2 / 2)
                winning[i] = true, winSum++;
            else
                winning[i] = false;
        }
        bool flag = false;
        for(int i = 0; i < o2; i++)
        {
            for(int j = 0; j < o1; j++)
            {
                bool napa = winning[j];
                if(napa == true)
                    winSum--;
                A[j] = A[j] - S[(i + j * o2) % (o1 * o2)] + S[(i + (j + 1) * o2) % (o1 * o2)];
                if(A[j] > o2 / 2)
                    winSum++,winning[j] = true;
                else
                    winning[j] = false;
            }
            if(winSum > o1 / 2)
            {
                flag = true;
                break;
            }
        }
        if(flag == true)
            std::cout << 1 << std::endl;
        else
            std::cout << 0 << std::endl;
        delete[] A;
        delete[] winning;
    }
    return 0;
}

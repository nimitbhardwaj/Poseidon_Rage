#include<iostream>
int main()
{
    int t;
    std::cin >> t;
    while(t--)
    {
        int n;
        std::cin >> n;
        int *A = new int[n + 10];
        A[0] = A[1] = A[2] = 0;
        A[3] = 1;
        for(int i = 4; i <= n; i++)
        {
            A[i] = A[i - 1] + A[i - 2] + A[i - 3];
        }
        std::cout << A[n] << std::endl;
    }
    return 0;
}

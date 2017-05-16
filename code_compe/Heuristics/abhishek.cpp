#include <iostream>
#include <vector>
int main()
{
    int n, q;
    std::cin >> n >> q;
    std::vector<int> V;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        std::cin >> tmp;
        V.push_back(tmp);
    }
    for(int i = 0; i < q; i++)
    {
        int a, b;
        std::cin >> a >> b;
        int sum = 0;
        for(int i = a - 1; i <= b - 1; i++)
            sum += V[i];
        std::cout << sum << std::endl;
    }
    return 0;
}

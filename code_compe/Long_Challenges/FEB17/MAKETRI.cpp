#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using ULL = unsigned long long int;

bool operator<(std::pair<ULL, ULL> &a, std::pair<ULL, ULL> &b)
{ return a.first < b.first; }


int main()
{
    ULL n, L, R;
    std::cin >> n >> L >> R;
    std::vector<ULL> V(n);
    for(ULL i = 0; i < n; i++)
        std::cin >> V[i];
    std::vector<std::pair<ULL, ULL> > dummy(n - 1);
    std::sort(V.begin(), V.end());
    for(ULL i = 1; i < n; i++)
    {
        dummy[i - 1].first = V[i] - V[i - 1];
        dummy[i - 1].second = V[i] + V[i - 1];
    }
    std::sort(dummy.begin(), dummy.end());
    ULL strt = L, counter = 0;
    for(ULL i = 0; i < n - 1; i++)
    {
        if(R <= dummy[i].first)
            break;
        if(strt <= dummy[i].first)
            counter += dummy[i].first - strt + 1;
        if(strt <= dummy[i].second)
            strt = dummy[i].second;
    }
    if(R >= strt)
        counter += R - strt + 1;
    std::cout << R - L + 1 - counter << std::endl;
    return 0;
}

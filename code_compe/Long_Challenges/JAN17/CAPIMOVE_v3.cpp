#include <iostream>
#include <vector>
#include <algorithm>

struct Planet
{
        int index;
        int pindex;
        int pop;
        std::vector<int> cont;
};

inline bool greaterThan(const Planet *a, const Planet *b) { return a->pop > b->pop; }

int main()
{
    int t, n, k, i, a, b, j;
    std::cin >> t;
    while(t--)
    {
        std::cin >> n;
        std::vector<int> best(n);
        std::vector<Planet *> index(n);
        std::vector<Planet *> sorted_pop(n);
        for(i = 0; i < n; i++)
        {
            index[i] = new Planet;
            std::cin >> index[i]->pop;
            index[i]->index = i;
            sorted_pop[i] = index[i];
        }
        std::sort(sorted_pop.begin(), sorted_pop.end(), greaterThan);
        for(i = 0; i < n; i++)
            sorted_pop[i]->pindex = i, sorted_pop[i]->cont.push_back(i);
        for(i = 0; i < n - 1; i++)
        {
            std::cin >> a >> b;
            a--;
            b--;
            index[a]->cont.push_back(index[b]->pindex);
            index[b]->cont.push_back(index[a]->pindex);
        }
        for(i = 0; i < n; i++)
        {
            std::sort(index[i]->cont.begin(), index[i]->cont.end());
            for(j = 0; j < n; j++)
            {
                if(index[i]->cont[j] != j)
                    break;
            }
            best[i] = sorted_pop[j]->index;
        }
        for(int i = 0; i < n; i++)
            std::cout << (best[i] + 1) % (n + 1) << ' ';
        std::cout << '\n';
    }
    return 0;
}

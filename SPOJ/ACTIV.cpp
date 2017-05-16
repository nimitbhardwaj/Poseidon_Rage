#include <iostream>
#include <vector>
struct OPair
{
    int x, y;    
};
std::istream &operator>>(std::istream &, OPair &);
int activities(std::vector<OPair> &, int);
int next(std::vector<OPair> &, int, int);
int main()
{
    std::vector<OPair> V;
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        OPair a;
        std::cin >> a;
        V.push_back(a);
    }
    std::cin >> n;
    std::cout << activities(V, 0);
    return 0;
}

std::istream &operator>>(std::istream &din, OPair &a)
{
    din >> a.x;
    din >> a.y;
    return din;
}

int activities(std::vector<OPair> &V, int a)
{
    if(a == V.size())
        return 1;
    if(a == -1)
        return 0;
    return activities(V, a + 1) + activities(V, next(V, a, V.size()));
}

int next(std::vector<OPair> &V, int a, int f)
{
    int n = a + f;
    n /= 2;
    if(a == f)
        return -1;
    if(V[a].y < V[n].x)
        return next(V, a, n);
    else if(V[f].x > V[n].y)
        return next(V, n, f);
    else
        return n;

}

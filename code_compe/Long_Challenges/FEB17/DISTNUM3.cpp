#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    vector<int> values(N); // store the values of the nodes of tree
    for(int i = 0; i < N; i++)
        scanf("%d", &values[i]);
    return 0;
}

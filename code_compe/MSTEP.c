#include<stdio.h>
#include<math.h>
int abs(int);
struct Coor
{
    int x;
    int y;
};
int main()
{
    int t, n, N, i, j, dis;
    struct Coor A[250001];
    scanf("%d", &t);
    while(t--)
    {
        dis = 0;
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                scanf("%d", &N);
                A[N].x = j;
                A[N].y = i;
            }
        }
        for(i = 2; i <= n * n; i++)
        {
            dis += (int)abs(A[i].x - (int)A[i - 1].x) + abs(A[i].y - A[i - 1].y);
        }
        printf("%d\n", dis);
    }
}

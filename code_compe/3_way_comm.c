#include<stdio.h>
#include<math.h>
typedef struct corr
{
    int x;
    int y;
}Location;
int main()
{
    int t, r, ck;
    float d1, d2, d3;
    Location A, B, C;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &r);
        scanf("%d %d", &A.x, &A.y);
        scanf("%d %d", &B.x, &B.y);
        scanf("%d %d", &C.x, &C.y);
        d1 = sqrt(pow((A.x - B.x), 2) + pow(A.y - B.y, 2));
        d2 = sqrt(pow((A.x - C.x), 2) + pow(A.y - C.y, 2));
        d3 = sqrt(pow((C.x - B.x), 2) + pow(C.y - B.y, 2));
        if(d1 <= r)
        {
            if(d2 <= r || d3 <= r)
                printf("yes\n");
            else
                printf("no\n");
        }
        else if(d2 <= r)
        {
            if(d1 <= r || d3 <= r)
                printf("yes\n");
            else
                printf("no\n");
        }
        else
            printf("no\n");
    }
    return 0;
}

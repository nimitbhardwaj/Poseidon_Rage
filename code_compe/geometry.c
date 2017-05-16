#include<stdio.h>

typedef struct pos
{
    int x;
    int y;
    struct pos *reject;
} Location;
void add(Location, Location *, int);
void rem(Location, Location *, int);
int area(struct pos *, int);
int main()
{
    int t, n, i, l = 0;
    char c;
    Location A[100000] = {0};
    Location test;
    A[0].x = 0;
    A[0].y = 0;
    A[0].reject = &A[1];
    test.reject = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; i++)
        {
            scanf("%c %d %d", &c, &test.x, &test.y);
            if(c =='+')
            {
                l++;
                add(test, A, i);
            }
            if(c == '-')
            {
                l--;
                rem(test, A, i);
            }
            if(l <= 2)
                printf("0.0\n");
            printf("%d", area(A, l));

        }
    }
    return 0;
}

void add(Location Test, Location *A, int l)
{

}
void rem(Location Test, Location *A, int l)
{

}
int area(Location * A, int l)
{

}

#include <stdio.h>
int main()
{
    int max(int, int, int);
    int t, i, n, j, R=0, G=0, B=0;
    char str[100001];
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        scanf("%d", &n);
        scanf("%s", str);
        for(j=0; j<n; j++)
        {

            fflush(stdin);
            switch(str[j])
            {
                case 'R':
                         R++;    break;
                case 'G':
                         G++;   break;
                case 'B':
                         B++;   break;
            }
        }
        printf("%d\n", R+G+B-max(R, G, B));
        R=G=B=0;
    }
    return 0;
}

int max(int R, int G, int B)
{
    int n=R;
    if(G>=n)
        n=G;
    if(B>=n)
        n=B;
        return n;
}

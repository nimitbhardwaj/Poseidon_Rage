#include<stdio.h>
int equate(int*, int*, int);
int main()
{
    int t, n, Base[100000], A1[100000], A2[100000], i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &Base[i]);
            if(i < n - 2)
                A1[i] = A1[i + 1] = A1[i + 2] = Base[i];
        }
        for(i = 0; i < n; i++)
        {
            if(i < n - 2)
                A2[n - i - 1] = A2[n - i - 2] = A2[n - i - 3] = Base[n - i - 1];
        }
        if(equate(Base, A1, n) || equate(Base, A2, n))
            printf("Yes\n");
        else
            printf("No\n");

    }
    return 0;
}

int equate(int *A, int *B, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(*(A + i) != *(B + i))
            return 0;
    }
    return 1;
}

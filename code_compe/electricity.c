#include <stdio.h>

int minWire(int, int, int*);

int main()
{
    int t, n, c, i, j, Arr[100000], dummy[100000], wire = 0, check = 0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        c = getchar();
        i = 0;
        while((c = getchar()) != '\n')
        {
            if(c == '0')
                ;
            else
            {
                dummy[check] = i;
                check++;
            }
            i++;
        }
        for(i = 0; i < n; i++)
            scanf("%d", &Arr[i]);
        wire += Arr[dummy[0]] - Arr[0] + Arr[n - 1] - Arr[dummy[check - 1]];
        for(j = 0; j < check - 1; j++)
            wire += minWire(dummy[j], dummy[j + 1], Arr);
        printf("%d\n", wire);
        wire = check = 0;
    }
}

int minWire(int a, int b, int *A)
{
    int min = 1000000000, j = 0, Sum[100000], Sum2[100000], sum = 0, i;
    j = 0;
    for(i = a; i < b; i++)
    {
        Sum[j] = A[i] - A[a];
        j++;
    }
    j = 0;
    for(i = a + 1; i <= b; i++)
    {
        Sum2[j] = A[b] - A[i];
        j++;
    }
    for(i = 0; i < b - a; i++)
    {
        if( min > Sum[i] + Sum2[i])
            min = Sum[i] + Sum2[i];
    }
    return min;
}

#include<stdio.h>
int main()
{
    int arr[5], i, a, len = 0, b, c, d, stat = 0;
    for(i = 0; i < 4; i++)
        scanf("%d", &arr[i]);
    a = arr[0];
    for(i = 1; i < 4; i++)
    {
        b = arr[i];
        if(i == 1)
            c = 2, d = 3;
        if(i == 2)
            c = 1, d = 3;
        if(i == 3)
            c = 1, d = 2;
        c = arr[c];
        d = arr[d];
        if(a * b == c * d)
        {
            stat = 1;
            break;
        }
    }
    printf("%s\n", stat == 0 ? "Impossible" : "Possible");
    return 0;
}

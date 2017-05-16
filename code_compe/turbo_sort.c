#include<stdio.h>
void sort(int *, int);
int main()
{
    int arr[1000000], t, i;
    scanf("%d", &t);
    for(i = 0; i < t; i++)
        scanf("%d", &arr[i]);
    sort(arr, t);
    printf("\n\n");
    for(i = 0; i < t; i++)
        printf("%d\n", arr[i]);
    return 0;
}

void sort(int *a, int n)
{
    int i, j = 0, min, ind, tmp;
    for(i = 0; i < n; i++)
    {
        ind = i;
        min = *(a + i);
        for(j = i + 1; j < n; j++)
        {
            if(min > *(a + j))
            {
                min = *(a + j);
                ind = j;
            }
        }
        tmp = *(a + i);
        *(a + i) = *(a + ind);
        *(a + ind) = tmp;
    }
}

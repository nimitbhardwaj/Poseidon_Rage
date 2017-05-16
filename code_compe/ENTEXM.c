#include<stdio.h>
void insertionSort(unsigned int *, int);
int main()
{
    int t, n, k, e, i, j;
    unsigned int m, arr[10001] = {0}, dump, req, sergy;
    scanf("%d\n", &t);
    while(t--)
    {
        scanf("%d %d %d %u", &n, &k, &e, &m);
        for(i = 0; i < n - 1; i++)
        {
            for(j = 0; j < e; j++)
            {
                scanf("%u", &dump);
                arr[i] += dump;
            }
        }
        sergy = 0;
        for(j = 0; j < e - 1; j++)
        {
            scanf("%u", &dump);
            sergy += dump;
        }
        insertionSort(arr, n - 1);
        req = arr[k - 1] + 1;
        if(req - sergy <= m)
            printf("%d\n", req - sergy);
        else
            puts("Impossible");
    }
    return 0;
}

void insertionSort(unsigned int *A, int n)
{// 1 2 3 4 5
    int i, j;
    unsigned int dump;
    for(i = 1; i < n; i++)
    {
        j = i;
        while(j)
        {
            if(A[j] >= A[j - 1])
            {
                dump = A[j];
                A[j] = A[j - 1];
                A[j - 1] = dump;
            }
            j--;
        }
    }

}

#include<stdio.h>
#include<malloc.h>
typedef struct player
{
    int count;
    int list[6];
    int score;
}Player;
void selectionSort(int *, int);
int main()
{
    int t, n, i, j, c, max, index, test;
    Player *A;
    scanf("%d", &t);
    while(t--)
    {
        max = index = -1;
        test = 0;
        scanf("%d", &n);
        A = (Player *) malloc(sizeof(Player) * n);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &(A[i].count));
            A[i].score = 0;
            for(j = 0; j < 6; j++)
                A[i].list[j] = 0;
            for(j = 0; j < A[i].count; j++)
            {
                scanf("%d", &c);
                A[i].list[c - 1] += 1;
            }
            A[i].score = A[i].count;
            selectionSort(A[i].list, 6);
            A[i].score += A[i].list[0] * 4;
            for(j = 1; j < 6; j++)
                A[i].list[j] = A[i].list[j] - A[i].list[0];
            A[i].score += A[i].list[1] * 2;
            for(j = 2; j < 6; j++)
                A[i].list[j] -= A[i].list[1];
            A[i].score += A[i].list[2] * 1;
            if(max < A[i].score)
                max = A[i].score, index = i;
        }
        for(i = 0; i < n; i++)
        {
            if(max == A[i].score && i != index)
            {
                test = 1;
                break;
            }
        }
        if(test == 1)
            printf("tie\n");
        else if(index == 0)
            printf("chef\n");
        else
            printf("%d\n", index + 1);
        free(A);
    }
    return 0;
}

void selectionSort(int *A, int n)
{
    int i, j, swap;
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(A[i] > A[j])
            {
                swap = A[i];
                A[i] = A[j];
                A[j] = swap;
            }
        }
    }
}
 

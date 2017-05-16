#include<stdio.h>
int main()
{
    int t, n, m, c, i, j, A[10][10], col, cru;
    scanf("%d", &t);
    while(t--)
    {
        col = 0;
        scanf("%d %d", &n, &m);
        c = getchar();
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                c = getchar();
                A[i][j] = c - '0';
            }
            c = getchar();
        }
        for(i = 0; i < m; i++)
        {
            cru = 0; 
            for(j = 0; j < n; j++)
            {
                if(A[j][i])
                    cru++;
            }
            col += cru * (cru - 1) / 2;
        }
        printf("%d\n", col);
    }
}

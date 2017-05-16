#include <stdio.h>

int main()
{
    int c, A[8] = {};
    int flg = 0, kapa, j = 0, i, sum;
    while((c = getchar()) != '\n')
    {
        if(flg == 0)
        {
            A[j] = c;
            if(j == 7)
                flg = 1;
        }
        else
        {
            flg = 0;
            sum = 0;
            for(i = 0; i < 8; i++)
                sum += (A[7 - i] - '0') * (1 << i);
            printf("%c", sum);
            A[j] = c;
        }
        j = (j + 1) % 8;
    }
    sum = 0;
    for(i = 0; i < 8; i++)
        sum += (A[7 - i] - '0') * (1 << i);
    printf("%c", sum);
}

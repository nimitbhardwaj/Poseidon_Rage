#include<stdio.h>
void swap(int *, int *);
void sort(int *, int);
int finisher(int *, int *, int);
int main()
{
    int t, i, n, j, min, k = 0, p = 0, fac, K=0;
    int *a, *b;
    int h[26]={0};
    char c;
    scanf("%d", &t);
    for(i = 1; i<=t; i++)
    {
        while((c = getchar()) != ' ')
        {
            h[c-'a']++;
        }
        scanf("%d", &n);
        sort(h, 26);
        for(j = 0; ; j++)
        {
            if((min = h[j]) != 0)
                break;
        }
        a = &h[j];
        b = &h[25];
        k = finisher(a, b, n);

        printf("%d\n", k );
        k = p = 0;
        for(j = 0; j<26; j++)
            h[j]=0;
    }
    return 0;
}

void swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void sort(int *a, int b)
{
    int i, *c, *d, j;
    c = a;
    for(i = 0; i < b; i++)
    {
        d = c + 1;
        for(j = i; j < b-1; j++)
        {
            if(*d <= *c)
                swap(c, d);
            d++;
        }
        c++;

    }
}


int finisher(int *a, int *b, int c)
{
    int *min, *max, k = 0, fac, k2 = 0, neg=0;
    min = a;
    max = b;
    while(1)
    {
        if((fac = *(max--) - *min - c) < 0)
            break;
        k += fac;
    }
    neg += *min++;
    max = b;
    while(1)
    {
        if((fac = *(max--) - *min - c) <= 0)
            break;
        k2 += fac;
    }
    if(k2+neg>=k)
        return k;
    else
        return neg;

}

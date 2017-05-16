#include<stdio.h>
#include<malloc.h>
#include<string.h>
int isPalin(char *, int);
void evenProcedurePalin(char *, int);
void oddProcedurePalin(char *, int);
void oddProcedureNPalin(char *, int);
void evenProcedureNPalin(char *, int);
int getNumber(char *, int *, int *);
int main()
{
    int t, len = 0, fl = 1, ze, i;
    char *num, *num2, c;
    num = (char *) malloc(sizeof(char) * 1400000);
    scanf("%d\n", &t);
    while(t--)
    {
        fl = 1;
        len = 0;
        ze = getNumber(num, &len, &fl);
        ze = 0;
        num2 = num + ze;
        len = len - ze;
        //num[0] = '0';
        //len = 0;
        //num[0] = '0';
        //while((c = getchar()) != '\n')
        //{
            //num[++len] = c;
            //if(fl == 1)
            //{
                //fl = c == '9' ? 1 : 0;
            //}
        //}
        //--------------------------------------------------
        //fgets(num + 1, 1000006, stdin);
        //puts(num);
        //len = strlen(num + 1) - 1;
        for(i = 0; i < ze; i++)
            putchar('0');
        if(fl == 1)
        {
            putchar('1');
            for(fl = 1; fl < len; fl++)
                putchar('0');
            putchar('1');
            puts("");
        }
        else
        {
            if(isPalin(num2, len))
            {
                if(len % 2 == 0)
                    evenProcedurePalin(num2, len);
                else
                    oddProcedurePalin(num2, len);
            }
            else
            {
                if(len % 2 == 0)
                    evenProcedureNPalin(num2, len);
                else
                    oddProcedureNPalin(num2, len);
            }

        }
        memset(num, 0, 1400000);
    }
    return 0;
}

int isPalin(char *num, int len)
{
    int beg = 1, end = len;
    while(beg <= end)
    {
        if(num[beg++] != num[end--])
        {
            return 0;
        }
    }
    return 1;
}

void evenProcedurePalin(char *num, int len)
{
    int beg = len / 2, end = len / 2 + 1, fl = 0;
    num[beg] += 1;
    num[end] += 1;
    while(num[beg] == '9' + 1)
    { num[beg] = num[end] = '0';
        beg--;
        end++;
        if(beg == 0)
            fl = 1;
        num[beg] += 1;
        num[end] = num[beg];
        if(fl == 1)
            num[end + 1] = 0;
    }
    if(fl == 0)
        puts(num + 1);
    else
        num[len] = num[0], num[len + 1] = 0, puts(num);
}
void oddProcedurePalin(char *num, int len)
{
    int beg, end, fl = 0;
    beg = end = len / 2 + 1;
    num[beg] += 1;
    while(num[beg] == '9' + 1)
    {
        num[beg] = num[end] = '0';
        beg--;
        end++;
        if(beg == 0)
            fl = 1;
        num[beg] += 1;
        num[end] = num[beg];
        if(fl ==  1)
            num[end + 1] = 0;
    }
    if(fl == 0)
        puts(num + 1);
    else
        num[len] = num[0], num[len + 1] = 0, puts(num);
}
void evenProcedureNPalin(char *num, int len)
{
    int beg = len / 2, end = len / 2 + 1, fl = 0, test = 0;
    int beg_d = beg, end_d = end;
    while(beg_d != 0)
    {
        if(num[beg_d] < num[end_d])
        {
            fl = 1;
            break;
        }
        else if(num[beg_d] > num[end_d])
        {
            fl = 0;
            break;
        }
        else
        {
            beg_d--;
            end_d++;
        }

    }
    if(fl == 1)
    {
        num[beg] += 1;
        num[end] = num[beg];
        while(num[beg] == '9' + 1)
        {
            num[beg] = num[end] = '0';
            beg--;
            end++;
            num[beg] += 1;
            num[end] = num[beg];
            if(beg == 0)
                test = 1;
        }
        if(test == 0)
        {
            while(beg != 1)
            {
                beg--;
                end++;
                num[end] = num[beg];
            }
        }
    }
    else
    {
        num[end] = num[beg];
        while(beg != 1)
        {
            beg--;
            end++;
            num[end] = num[beg];
        }
    }
    if(test == 1)
        puts(num);
    else
        puts(num + 1);
}
void oddProcedureNPalin(char *num, int len)
{
    int beg, end, fl = 0, beg_d, end_d;
    beg = end = len / 2 + 1;
    beg_d = end_d = beg;
    while(beg_d != 1)
    {
        beg_d--;
        end_d++;
        if(num[beg_d] > num[end_d])
        {
            fl = 0;
            break;
        }
        else if(num[beg_d] < num[end_d])
        {
            fl = 1;
            break;
        }
        else
            ;
    }
    if(fl == 0)
    {
        while(beg != 1)
        {
            end++;
            beg--;
            num[end] = num[beg];
        }
    }
    else
    {
        num[beg] += 1;
        beg_d = beg;
        end_d = end;
        while((num[beg_d] == '9' + 1 && num[end_d] == '9' + 1) && beg_d != 1)
        {
            if(num[beg_d] == '9' + 1)
                num[beg_d] = '0';
            if(num[end_d] == '9' + 1)
                num[end_d] = '0';
            beg_d--;
            end_d++;
            num[beg_d] += 1;
            num[end_d] += 1;
        }
        while(beg != 0)
        {
            num[end] = num[beg];
            beg--;
            end++;
        }

    }
    puts(num + 1);
}

int getNumber(char *A, int *len, int *flag)
{
    int i, ze = 0;
    char *p;
    A[0] = '0';
    fgets(A + 1, 1400000, stdin);
    *len = strlen(A) - 2;
    A[*len + 1] = 0;
    for(i = 1; i < *len + 1; i++)
    {
        if(A[i] != '9')
        {
            *flag = 0;
            break;
        }
    }
    for(i = 1; ;i++)
    {
        if(A[i] == '0')
            ze++;
        else
            break;
    }
    return ze;
}


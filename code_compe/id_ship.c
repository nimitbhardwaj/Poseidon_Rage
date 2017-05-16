#include<stdio.h>
void buff_clean(void);
int main()
{
    int t;
    char c;
    scanf("%d", &t);
    while(t--)
    {
        buff_clean();
        c = getc(stdin);
        switch(c)
        {
            case 'b':
            case 'B':
                puts("BattleShip");
                break;
            case 'c':
            case 'C':
                puts("Cruiser");
                break;
            case 'd':
            case 'D':
                puts("Destroyer");
                break;
            case 'f':
            case 'F':
                puts("Frigate");
                break;
        }
    }
    return 0;
}

void buff_clean(void)
{
    int c;
    do
    {
        c = getchar();
    } while(c !='\n' && c!=EOF);
}

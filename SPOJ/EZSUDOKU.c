#include <stdio.h>

typedef struct Coord
{
    int x, y;
} Coord;

int solveSudoku(int [][8], Coord [], int *);
int isValidMove(int [][8], Coord, int);
int isValidSudoku(int [][8]);

int main()
{
    int t, kapa, i, j;
    Coord stack[70];
    int top = 0;
    int sheet[8][8] = {0};
    scanf("%d\n", &t);
    for(kapa = 1; kapa <= t; kapa++)
    {
        for(i = 0; i < 8; i++)
        {
            for(j = 0; j < 8; j++)
            {
                scanf("%d", &sheet[i][j]);
                if(sheet[i][j] == 0)
                {
                    stack[top].x = i, stack[top].y = j;
                    top++;
                }
            }
        }
        if(isValidSudoku(sheet) == 0)
        {
            printf("Test case #%d: NO\n", kapa);
            continue;
        }
        if(solveSudoku(sheet, stack, &top) == 1)
        {
            printf("Test case #%d: YES\n", kapa);
            for(int i = 0; i < 8; i++)
            {
                for(int j = 0; j < 8; j++)
                    printf("%d ", sheet[i][j]);
                printf("\n");
        
            }
        }
        else
        {
            printf("Test case #%d: NO\n", kapa);
        }
    }
    return 0;
}

int solveSudoku(int sheet[][8], Coord stack[], int *top)
{
    int i, j;
    if(*top == 0)
    {
        return 1;
    }
    *top -= 1;
    Coord position = stack[*top];
    for(i = 1; i <= 8; i++)
    {
        if(isValidMove(sheet, position, i) == 1)
        {
            sheet[position.x][position.y] = i;
            if(solveSudoku(sheet, stack, top) == 1)
                return 1;
            sheet[position.x][position.y] = 0;
        }
    }
    stack[*top] = position;
    *top += 1;
    return 0;
}

int isValidMove(int sheet[][8], Coord position, int k)
{
    int check = 1;
    int regx = 0, regy = 0, i, j;
    int alpha = 0;
    for(i = 0; i < 8; i++)
    {
        if(sheet[i][position.y] == k)
        {
            check = 0;
            break;
        }
        if(sheet[position.x][i] == k)
        {
            check = 0;
            break;
        }
    }
    if(check == 0)
        return 0;
    if(position.x >= 4)
        regx = 4;
    if(position.y >= 4)
        regy = 4;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(sheet[regx + i][regy + j] == k)
            {
                if(alpha == 0)
                    alpha++;
                else
                {
                    check = 0;
                    return 0;
                }
            }
        }
    }
    return check;
    
}

int isValidSudoku(int V[][8])
{
    int i, j;
    int alpha[8][8] = {0}, beta[8][8] = {0};
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            if(V[i][j] != 0)
                if(alpha[i][V[i][j] - 1] == 1)
                {
                    return 0;
                }
                else
                    alpha[i][V[i][j] - 1] += 1;
            if(V[j][i] != 0)
                if(beta[i][V[j][i] - 1] == 1)
                {
                    return 0;
                }
                else
                    beta[i][V[j][i] - 1] += 1;
        }
    }
    int napa[8] = {0}, kapa[8] = {0}, delta[8] = {0}, lambda[8] = {0};
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(V[i][j] != 0)
                if(kapa[V[i][j] - 1] >= 2)
                {
                    return 0;
                }
                else
                    kapa[V[i][j] - 1] += 1;
            if(V[i][j + 4] != 0)
                if(napa[V[i][j + 4] - 1] >= 2)
                {
                    return 0;
                }
                else
                    napa[V[i][j + 4] - 1] += 1;
            if(V[i + 4][j] != 0)
                if(delta[V[i + 4][j] - 1] >= 2)
                {
                    return 0;
                }
                else
                    delta[V[i + 4][j] - 1] += 1;
            if(V[i + 4][j + 4] != 0)
                if(lambda[V[i + 4][j + 4] - 1] >= 2)
                {
                    return 0;
                }
                else
                    lambda[V[i + 4][j + 4] - 1] += 1;
        }
    }
    return 1;

}

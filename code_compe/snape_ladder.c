#include<stdio.h>
#include<math.h>
int main()
{
    int t, B, LS;
    float R_min, R_max;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &B, &LS);
        R_min = sqrt(LS * LS - B * B);
        R_max = sqrt(LS * LS + B * B);
        printf("%f %f\n", R_min, R_max);
    }
    return 0;
}

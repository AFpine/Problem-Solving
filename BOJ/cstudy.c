#include <stdio.h>
#include <math.h>

int main()
{
    int T;
    int A = 0, B = 0, C = 0;

    scanf("%d",&T);

    A = T/300;
    T %= 300;
    B = T/60;
    T %= 60;
    C = T/10;
    T %= 10;

    if(T != 0)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d %d %d\n",A,B,C);
    }



}
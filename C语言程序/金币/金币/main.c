#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,sum;
    while(scanf("%d",&i) != EOF)
    {
        if(i == 0) return 0;
        for(j = 1,sum = 0;i > j*(j+1)/2;j ++)
            sum += j * j;
        sum += (i-j*(j-1)/2)*j;
        printf("%d %d\n",i,sum);
    }
    return 0;
}

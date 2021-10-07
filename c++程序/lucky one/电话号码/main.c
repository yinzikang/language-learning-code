/*http://bailian.openjudge.cn/practice/1002/*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void change(char a[],char b[])
{
    int i = 0,j = 0;
    for(;j < 8;)
    {
        if(a[i] != '-')
        {
            if(j == 3) b[j] = '-';
            else
            {
                if(a[i] > 47&&a[i] < 58) b[j] = a[i];
                else if(a[i] > 64&&a[i] < 81) b[j] = (a[i]-59)/3 + '0';
                else if(a[i] > 81&&a[i] < 90) b[j] = (a[i]-60)/3 + '0';
                i ++;
            }
            j ++;
        }
        else i ++;
    }
    b[8] = '\0';
}
int main()
{
    int n,i,j,sum;
    scanf("%d\n",&n);
    char a[n][16],b[n][9],*c[n],*t;
    for(i = 0;i < n;i ++)
    {
        gets(a[i]);
        change(a[i],b[i]);
        c[i] = b[i];
    }
    for(i = 0;i < n -1;i ++)
        for(j = 0;j < n - i -1;j ++)
            if(strcmp(c[j],c[j + 1])>0)
                t = c[j],c[j] = c[j + 1],c[j + 1] = t;
    for(i = 0;i < n - 1;)
    {
        j = i;
        sum = 1;
        while((j < n - 1)&&(strcmp(c[j],c[j + 1]) == 0))
        {
            j ++;
            sum ++;
        }
        if(sum > 1) printf("%s %d\n",c[i],sum);
        i += sum;
    }
    return 0;
}

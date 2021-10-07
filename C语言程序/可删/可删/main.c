#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define uchar unsigned char
#define uint  unsigned int
uint p = 0,q = 0,r = 0,i = 0,get;
char express[10],ans[10],*l = express;
double num[2];
int main()
{
    gets(express);
    num[0] = atof(l);
    while(express[i] != '+')
            i ++;
    l = express + i;
    num[1] = atof(l);
    num[0] = num[0] + num[1];
    sprintf(ans,"%lf",num[0]);
    puts(ans);
    return 0;
}

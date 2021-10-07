#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char express[20],ans[10],*l = express;
double num[10];
int judge[10] = {0}, countl = 0,countr = 0,i = 0,j= 0,x = 0,y = 0,m = 0,n = 0;
int main()
{
    gets(express);
    for(i = 0;i < strlen(express);i ++)
    {
        if(express[i] == 's')
        {
            i = i + 3;
            l = express + i;
            num[m ++] = sin(atof(l));
            while((express[i] != '+')&&(express[i] != '-')&&(express[i] != '*')&&(express[i] != '/'))
                i ++;
            i --;
            judge[n ++] = 0;
        }
        if(express[i] == 'c')
        {
            i = i + 3;
            l = express + i;
            num[m ++] = cos(atof(l));
            while((express[i] != '+')&&(express[i] != '-')&&(express[i] != '*')&&(express[i] != '/'))
                i ++;
            i --;
            judge[n ++] = 0;
        }
        if(express[i] == 't')
        {
            i = i + 3;
            l = express + i;
            num[m ++] = cos(atof(l));
            while((express[i] != '+')&&(express[i] != '-')&&(express[i] != '*')&&(express[i] != '/'))
                i ++;
            i --;
            judge[n ++] = 0;
        }
        if((express[i] >= '0')&&(express[i] <= '9'))
        {
            l = express + i;
            num[m ++] = atof(l);
            while((express[i] != '+')&&(express[i] != '-')&&(express[i] != '*')&&(express[i] != '/'))
                i ++;
            i --;
            judge[n ++] = 0;
        }
        if(express[i] == '+') judge[n ++] = 1;
        if(express[i] == '-') judge[n ++] = 2;
        if(express[i] == '*') judge[n ++] = 3;
        if(express[i] == '/') judge[n ++] = 4;
    }
    for(i = 0;i < n;i ++)
        if(judge[i] == 3)
        {
            x = y = i;
            countl = countr = 0;
            while((x >= 0)&&(judge[x] != 0)) x --;
            while((y < n)&&(judge[y] != 0)) y ++;
            for(j = 0;j < x;j ++)
                if((judge[j] == 0)||(judge[j] == 5))
                    countl ++;
            for(j = 0;j < y;j ++)
                if((judge[j] == 0)||(judge[j] == 5))
                    countr ++;
            num[countl] = num[countl] * num[countr];
            judge[y] = 5;
            judge[i] = 6;
        }
    for(i = 0;i < n;i ++)
        if(judge[i] == 4)
        {
            x = y = i;
            countl = countr = 0;
            while((x >= 0)&&(judge[x] != 0)) x --;
            while((y < n)&&(judge[y] != 0)) y ++;
            for(j = 0;j < x;j ++)
                if((judge[j] == 0)||(judge[j] == 5))
                    countl ++;
            for(j = 0;j < y;j ++)
                if((judge[j] == 0)||(judge[j] == 5))
                    countr ++;
            num[countl] = num[countl] / num[countr];
            judge[y] = 5;
            judge[i] = 6;
        }
    for(i = 0;i < n;i ++)
        if(judge[i] == 1)
        {
            x = y = i;
            countl = countr = 0;
            while((x >= 0)&&(judge[x] != 0)) x --;
            while((y < n)&&(judge[y] != 0)) y ++;
            for(j = 0;j < x;j ++)
                if((judge[j] == 0)||(judge[j] == 5))
                    countl ++;
            for(j = 0;j < y;j ++)
                if((judge[j] == 0)||(judge[j] == 5))
                    countr ++;
            num[countl] = num[countl] + num[countr];
            judge[y] = 5;
            judge[i] = 6;
        }
    for(i = 0;i < n;i ++)
        if(judge[i] == 2)
        {
            x = y = i;
            countl = countr = 0;
            while((x >= 0)&&(judge[x] != 0)) x --;
            while((y < n)&&(judge[y] != 0)) y ++;
            for(j = 0;j < x;j ++)
                if((judge[j] == 0)||(judge[j] == 5))
                    countl ++;
            for(j = 0;j < y;j ++)
                if((judge[j] == 0)||(judge[j] == 5))
                    countr ++;
            num[countl] = num[countl] - num[countr];
            judge[y] = 5;
            judge[i] = 6;
        }
    sprintf(ans,"%lf",num[0]);
    puts(ans);//
    return 0;
}

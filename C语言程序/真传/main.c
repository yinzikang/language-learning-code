/*实现数据的多次输入，同时按下end之后自动结束程序*/
/*通过while(scanf("%d",n) != EOF)或while(gets(str) != NULL)判断*/
#include <stdio.h>
#include <string.h>
int real(char str[])
{
    int i,j;
    for(i = strlen(str)-1,j = 0;i >= j;i --,j ++)
        if(str[i] != str[j]) return 0;
    return 1;
}

int main()
{
    char str1[80],str2[80] = "end";
    while(gets(str1) != NULL)
    {
        if(strcmp(str1,str2) == 0) break;//专门用于设计跳出程序
        if(real(str1)) printf("HOW SMART YOU ARE !!!!!!!\n");
        else printf("try again\n");
    }
    return 0;
}

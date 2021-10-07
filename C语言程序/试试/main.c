#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void play(char str[])
{
    int i;
    i = strlen(str);
    printf("%d\n",i);
    puts(str);
}
int main()
{
    char str1[80],str2[80] = "I am boring";
    while(gets(str1) != NULL)
    {
        if(strcmp(str1,str2) == 0) break;//专门用于设计跳出程序
        play(str1);
    }
    return 0;
}

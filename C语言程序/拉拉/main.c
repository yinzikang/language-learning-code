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
    char str[80];
    while(gets(str) != NULL)
    {
        if(real(str)) printf("HOW SMART YOU ARE !!!!!!!\n");
        else printf("try again\n");
    }
    return 0;
}

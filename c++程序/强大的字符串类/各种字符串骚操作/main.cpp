#include <iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
    int i,j,n;
    char str[80];
    gets(str);
    for(j = strlen(str) - 1;j > 0;j --)
    {
        while(str[j]>'z'||str[j]<'A')
            j --;
        i = j;
        while(str[i]<='z'&&str[i]>='A')
            i --;
        for(n = i + 1;n <= j;n ++)
            cout<<str[n];
        cout<<'\n';
        j = i;
    }
    return 0;
}

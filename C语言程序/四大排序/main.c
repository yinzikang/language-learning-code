#include <stdio.h>
#include <stdlib.h>
int *maopao()
{
    return 0;
}
int *kuaisu()
{
    return 0;
}
int *charu()
{
    return 0;
}
int *xuanze()
{
    return 0;
}
int main()
{
    int i,j;
    int str[10];
    int (*(*f)[4])(int *) = {maopao,kuaisu,charu,xuanze};
    for(i = 0;i < 10;i ++)
        scanf("%d",str[i]);
    return 0;

}

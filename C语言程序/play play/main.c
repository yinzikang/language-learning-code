#include <stdio.h>
int a[4] = {1,2,3,4},b[4] = {5,6,7,8},*p = a;
int main()
{
    p = b;
    printf("%d",*p);
    return 0;
}

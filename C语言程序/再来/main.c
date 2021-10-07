#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    while(scanf("%d",&i) != EOF)
    {
        if(i == 0) break;
        switch(i / 10) {
            case 10 : printf("well done\n"); break;
            case 9 : printf("good\n"); break;
            case 8 : printf("still ok\n"); break;
            case 7 : printf("you can die\n"); break;
            default : printf("you lied\n"); break;
        }
    }
    return 0;
}

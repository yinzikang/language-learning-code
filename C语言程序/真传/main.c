/*ʵ�����ݵĶ�����룬ͬʱ����end֮���Զ���������*/
/*ͨ��while(scanf("%d",n) != EOF)��while(gets(str) != NULL)�ж�*/
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
        if(strcmp(str1,str2) == 0) break;//ר�����������������
        if(real(str1)) printf("HOW SMART YOU ARE !!!!!!!\n");
        else printf("try again\n");
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
void menu();
void add();
void modify();
void stat();
void search();
int load();
struct equipment
    {
    char num[10];            /*设备编号*/
    char kind[10];        /*设备种类*/
    char name[20];        /*设备名称*/
    char money[10];           /*设备价格*/
    char brithday[10]; /*设备购入日期*/
    char bf[10];          /*是否报废*/
    char badday[10];   /*报废日期*/
    }eup[N],temp;

/* 返回主函数模块 */
void menu()
{
    int n;
    puts("\t\t************************MENU*************************\n\n");
    puts("\t\t\t\t 1.添加实验设备");
    puts("\t\t\t\t 2.修改");
    puts("\t\t\t\t 3.统计");
    puts("\t\t\t\t 4.查找");
    puts("\t\t\t\t 5.退出");
    puts("\n\n\t\t**********************************************************\n");
    printf("请输入(1-5):[ ]\b\b");
    scanf("%d",&n);
    switch(n)
    {
        case 1:add();break;
        case 2:modify();break;
        case 3:stat();break;
        case 4:search();break;
        case 5:exit(0);
        default:menu();
    }
}

void main()/*主函数*/
{
    menu();
    getch();
}

/* 追加模块 */
void add()
{
    int i;
    FILE *fp;
    //fp=fopen("eup.txt","r");
    if((fp=fopen("eup.txt","a"))==NULL)
    {
        printf("不能打开文件\n"); 
    }
    printf("\n输入:编号  种类 名称 价格 购入日期(年.月.日)  报废  报废日期(年.月.日)\n");
    scanf("%s",temp.num);
    scanf("%s",temp.kind);
    scanf("%s",temp.name);
    scanf("%s",temp.money);
    scanf("%s",temp.brithday);
    scanf("%s",temp.bf);
    scanf("%s",temp.badday);
    fprintf(fp,"\n%2s\t%s\t%14s    %4s   %9s   %s   %9s",temp.num,temp.kind,temp.name,temp.money,temp.brithday,temp.bf,temp.badday);
    fclose(fp);
    printf("\n\n\t成功添加.^_^\n\n");
    printf("\n*******************************************************************************\n");
    printf("接下来要做什么?\n\n");
    printf("\t1.继续添加\t2.返回主菜单\t3.退出\n");
    printf("\n*******************************************************************************\n");
    printf("\n\n请输入(1-3):");
    scanf("%d",&i);
    if(i==1)
    {
        add();
    }
    if(i==2)
    {   
        menu();
    }
    if(i==3)
    {
        exit(0);
    }
}

/* 修改模块 */
void modify()
{
    FILE *fp;
    int n,k=0,b,c,i,e;
    char a[10];
    n=load();
    printf("\n编号    种类		  名称  价格(元)  购入日期  报废  报废日期\n");
	for(i=0;i<n;i++)
    {
        printf("%2s\t%s\t%14s    %4s   %9s   %s   %9s\n",eup[i].num,eup[i].kind,eup[i].name,eup[i].money,eup[i].brithday,eup[i].bf,eup[i].badday);
    }
    printf("\n请输入需要修改的设备编号!\n\n设备编号:");
    scanf("%s",a);
    for(i=0;i<n;i++)
    if(strcmp(a,eup[i].num)==0)         /*查找要修改的设备信息*/
    {
        k=1;
        c=i;
        break;
    }
    if(k==0)
    {
        printf("\n\n对不起，找不到该设备!");
        printf("\t1).再次查找    2).返回主菜单   []\b\b");
        scanf("%d",&b);
        if(b==1){modify();}
        if(b==2){menu();}
    }
    if(k==1)
    {
        printf("\n成功找到设备!\n");
        printf("\n请输入新的信息:\n");
        printf("\n编号  种类  名称  价格  购入日期  报废  报废日期\n");
        scanf("%s",eup[c].num);
        scanf("%s",eup[c].kind);
        scanf("%s",eup[c].name);
        scanf("%s",eup[c].money);
        scanf("%s",eup[c].brithday);
        scanf("%s",eup[c].bf);
        scanf("%s",eup[c].badday);
    }
    fp=fopen("eup.txt","w");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",eup[i].num,eup[i].kind,eup[i].name,eup[i].money,eup[i].brithday,eup[i].bf,eup[i].badday);
    }
    fclose(fp);
    printf("\n\n\t修改成功.^_^\n\n");
    printf("\n*******************************************************************************\n");
    printf("接下来要做什么?\n\n");
    printf("\t1.继续修改\t2.返回主菜单\t3.退出\n");
    printf("\n*******************************************************************************\n");
    printf("\n\n请输入(1-3):");
    scanf("%d",&e);
    if(e==1)
    {
        modify();
    }
    if(e==2)
    {   
        menu();
    }
    if(e==3)
    {
        exit(0);
    }
}

/* 分类统计模块 */
void stat()
{
    int n,i;
    FILE *fp;
    fp=fopen("eup.txt","r");
    if((fp=fopen("eup.txt","r"))==NULL)
    {
        printf("cannot open file\n"); 
    }
    printf("\n编号    种类		  名称  价格(元)  购入日期  报废  报废日期\n");
	while(!feof(fp))
    {   
        fscanf(fp,"\n%s%s%s%s%s%s%s",temp.num,temp.kind,temp.name,temp.money,temp.brithday,temp.bf,temp.badday);
        printf("\n%2s\t%s\t%14s    %4s   %9s   %s   %9s",temp.num,temp.kind,temp.name,temp.money,temp.brithday,temp.bf,temp.badday);
    }
    fclose(fp);
    menu();
}
/* 查找模块 */
void search()
{
    int i,n,k=-1,w1,w2,w3;
    char c[10];
    n=load();
    printf("\n\n 查找一个:\n\n1).设备编号 2).种类  3).名称  4).购入日期   [ ]\b\b");
    scanf("%d",&w3);
    switch(w3)
    {
        case 1:
        {
            printf("\n\n输入要查找的设备编号! 编号:");
            scanf("%s",c);
            printf("\n编号    种类		  名称  价格(元)  购入日期  报废  报废日期\n");
			for(i=0;i<n;i++)
            if(strcmp(c,eup[i].num)==0)
            { 
                k=i;
                printf("%2s\t%s\t%14s    %4s   %9s   %s   %9s\n",eup[i].num,eup[i].kind,eup[i].name,eup[i].money,eup[i].brithday,eup[i].bf,eup[i].badday);
            }
            if (k!=-1)
            printf("\n\n接下来要做.");
            if (k==-1)
            printf("对不起，找不到设备!\n");
            printf("\n\t1).再次寻找       2).返回主菜单  [ ]\b\b");
            scanf("%d",&w2);
            if(w2==2)  menu();
            if(w2==1) search();
        }break;
        case 2:
        {
            printf("\n\n输入要查找的种类! 种类:");
            scanf("%s",c);
            printf("\n编号    种类		  名称  价格(元)  购入日期  报废  报废日期\n");
			for(i=0;i<n;i++)
            if(strcmp(c,eup[i].kind)==0)
            { 
                k=i;
                printf("%2s\t%s\t%14s    %4s   %9s   %s   %9s\n",eup[i].num,eup[i].kind,eup[i].name,eup[i].money,eup[i].brithday,eup[i].bf,eup[i].badday);
            }
            if (k!=-1)
            printf("\n\n接下来要做.^_^.");
            if (k==-1)
            printf("对不起，找不到设备!\n");
            printf("\n\t1).再次查找       2).返回主菜单  [ ]\b\b");
            scanf("%d",&w2);
            if(w2==2)  menu();
            if(w2==1) search();
        }break;
        case 3:
        {
            printf("\n\n输入要查找的设备名称! 名称:");
            scanf("%s",c);
            printf("\n编号    种类		  名称  价格(元)  购入日期  报废  报废日期\n");
			for(i=0;i<n;i++)
            if(strcmp(c,eup[i].name)==0)
            { 
                k=i;
				printf("%2s\t%s\t%14s    %4s   %9s   %s   %9s\n",eup[i].num,eup[i].kind,eup[i].name,eup[i].money,eup[i].brithday,eup[i].bf,eup[i].badday);
            }
            if (k!=-1)
            printf("\n\n接下来要做.^_^.");
            if (k==-1)
            printf("对不起，找不到该设备!\n");
            printf("\n\t1).再次查找       2).返回主菜单  [ ]\b\b");
            scanf("%d",&w2);
            if(w2==2)  menu();
            if(w2==1) search();
        }break;
        case 4:
        {
            printf("\n\n输入要查找的设备的购入日期! 购入日期(年.月.日):");
            scanf("%s",c);
            printf("\n编号    种类		  名称  价格(元)  购入日期  报废  报废日期\n");
			for(i=0;i<n;i++)
            if(strcmp(c,eup[i].brithday)==0)
            { 
                k=i;
                printf("%2s\t%s\t%14s    %4s   %9s   %s   %9s\n",eup[i].num,eup[i].kind,eup[i].name,eup[i].money,eup[i].brithday,eup[i].bf,eup[i].badday);
            }
            if (k!=-1)
            printf("\n\n接下来要做.^_^.");
            if (k==-1)
            printf("对不起，找不到设备!\n");
            printf("\n\t1).再次查找       2).返回主菜单  [ ]\b\b");
            scanf("%d",&w2);
            if(w2==2)  menu();
            if(w2==1) search();
        }

    }
}
int load()
{
    FILE *fp;
    int i;
    if((fp=fopen("eup.txt","r"))==NULL)
    {
        printf("\n不能打开文件\n");
        return NULL;
    }
    for(i=0;!feof(fp);i++)
    fscanf(fp,"%s %s %s %s %s %s %s\n",eup[i].num,eup[i].kind,eup[i].name,eup[i].money,eup[i].brithday,eup[i].bf,eup[i].badday);
    fclose(fp);
    return(i);
}

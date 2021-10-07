#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
struct person
{
 char name[15]; 
 char tel[15]; 
 char kind[5];
 char Email[15];
}msg[15];

void name();
void printf_back();
int load();
void add();
void browse();
void del();
void search() ;
void main();
void menu();

void printf_back()
{
    menu();
    printf("\n\n成功^_^\n\n");
    getchar();
    menu();
}

int load()     
{
    FILE *fp;
    int i=0,t,k;
    if((fp=fopen("person.txt","r"))==NULL)
	{printf("\n不能打开此文件\n");
	}
    for(k=0;k<15;k++)
	{t=fscanf(fp,"%s %s %s %s",msg[k].name,msg[k].tel,msg[k].kind,msg[k].Email);
    if(t<4) break;
    i=i+1;
	}
    return(i);
	fclose(fp);
}
void add()
{ 
    int n,j,t,w1,w;
    FILE *fp;
    char name[10],kind[10],Email[20];
    char tel[11];
    if((fp=fopen("person.txt","a"))==NULL)
	{printf("\n不能打开此文件\n");
	}
	printf("您想输入多少人的信息?");
    scanf("%d",&t);
    n=load();
	for(j=0;j<t;j++)
	{  
	printf("\n\n序号:");
    printf("%d",n+1);
	printf("\n\n请输入联系人的姓名:");
	scanf("%s",name);
    for(w=0;w<n;w++)if(strcmp(msg[w].name,name)==0)
	{printf("\n     信息已存在!");
	fclose(fp);
    getchar();
    printf_back();}
	printf("\n\n请输入联系人的电话:");
	scanf("%s",tel);
	printf("\n\n请输入分类:");
    scanf("%s",kind);
	printf("\n\n请输入联系人的电子邮件:");
	scanf("%s",Email);
    strcpy(msg[n].name,name);
	strcpy(msg[n].tel,tel);
	strcpy(msg[n].kind,kind);
	strcpy(msg[n].Email,Email);
	fprintf(fp,"%s %s %s %s\n",msg[n].name,msg[n].tel,msg[n].kind,msg[n].Email);
	n=n+1;
	if(n>15) printf("空间已满");}
      printf("\n你想继续增添吗?1).是 2).否 回到主菜单:[]\b\b");
scanf("%d",&w1);
if(w1==1)
add();
else 
{fclose(fp);
    getchar();
    printf_back();}
}
void browse()
{   int t=-1;
    int i,n,j,c,w1;
	char name[10];
    FILE *fp;
	n=load();
	printf("\n\n输入要修改人的姓名:\n");
    scanf("%s",name);
    if((fp=fopen("person.txt","r+"))==NULL)
	{
	printf("\n\n不能打开!\n\n");exit(0);
	}
    for(j=0;j<n;j++)
    if(strcmp(name,msg[j].name)==0)
	{t=j;break;}
	if(t==-1) printf("\n\n该名字不存在!\n");
	else {for(j=0;j<n;j++)
    if(strcmp(name,msg[j].name)==0)
	{ 
	do
	{
	puts("\n请输入数字=>\n\n  1). 姓名 2).电话: 3).分类: 4).电子邮件:");
	printf("请输入选项?:[ ]\b\b  ");
	scanf("%d",&c);
	if(c>4||c<1)
	{
	puts("\n选择错误!");
	getchar();
	}
	}while(c>8||c<1);break;
	}
    do
	{
    switch(c)
	{
	case 1:printf("姓名:");scanf("%s",msg[j].name);break;
	case 2:printf("电话:");scanf("%s",msg[j].tel);break;
    case 3:printf("分类:");scanf("%s",msg[j].kind);break;
    case 4:printf("电子邮件:");scanf("%s",msg[j].Email);break;
	}
	}while(c<1||c>4);
    printf("\n    修改成功!\n");
	for(i=0;i<n;i++)
    fprintf(fp,"%s %s %s %s\n",msg[i].name,msg[i].tel,msg[i].kind,msg[i].Email);
	}
	  printf("\n你想继续修改吗?1).是 2).否 回到主菜单:[]\b\b");
scanf("%d",&w1);
if(w1==1)
browse();
else {fclose(fp);
    getchar();
    printf_back();}
}
void del()     
{   int i,j,n,w1;
    FILE *fp;
    char name[10];
    n=load();
    printf("\n\n请输入你想删除的人的名字:");            
    scanf("%s",name);
    if((fp=fopen("person.txt","r"))==NULL)
	{
    printf("\n\n不能打开此文件。\n\n");
    exit(0);
	}
    for(j=0;j<n;j++) {if(strcmp(msg[j].name,name)==0) {printf("\n    删除成功!\n");break;}} 
    if((fp=fopen("person.txt","w"))==NULL)
	{
    printf("\n\n不能打开此文件。\n\n");
    exit(0);
	}
    for(i=0;i<n;i++) {if(i!=j){
	strcpy(msg[i].name,msg[i].name);
	strcpy(msg[i].tel,msg[i].tel);
	strcpy(msg[n].kind,msg[i].kind);
	strcpy(msg[n].Email,msg[i].Email);
	fprintf(fp,"%s %s %s %s\n",msg[i].name,msg[i].tel,msg[i].kind,msg[i].Email);}}
     printf("\n你想继续删除吗?1).是 2).否 回到主菜单:[]\b\b");
scanf("%d",&w1);
if(w1==1)
del();
else 
{fclose(fp);
    getchar();
    printf_back();} 
}
void search()
{   FILE *fp;
    int n,j,w1;
    int k=-1;
    char kind[20];
    n=load();
    if((fp=fopen("person.txt","r"))==NULL)
    {
    printf("\n\n不能打开此文件。\n\n");
    }
    printf("\n\n请选择种类:\n 办公\n 商务\n 个人\n\n请选择分类:");
    scanf("%s",kind);
    for(j=0;j<n;j++)
    {if(strcmp(kind,msg[j].kind)==0)  
	{k=j;
	printf("\n%s  %s  %s  %s\n",msg[j].name,msg[j].tel,msg[j].kind,msg[j].Email);
	}}
    if(k==-1)                      
	{
    printf("\n\n不存在!");
    }
     printf("\n你想继续查看吗?1).是 2).否 回到主菜单[]:\b\b");
scanf("%d",&w1);
if(w1==1)
search();
else 
{fclose(fp);
    getchar();
    printf_back();}
} 
void name()
{   FILE *fp;
    int t=20,j,n,w1;
    char nme[10]; 
    n=load();
    if((fp=fopen("person.txt","r"))==NULL)
    {
    printf("\n\n不能打开此文件。\n\n");
    }
    printf("请输入您要查询的人的姓名:");
    scanf("%s",nme);
    for(j=0;j<n;j++)
	if(strcmp(nme,msg[j].name)==0)
	{t=j;
	 printf("\n姓名  电话  分类  电子邮件\n");
	printf("\n%s  %s  %s  %s\n",msg[j].name,msg[j].tel,msg[j].kind,msg[j].Email);
	}
    if(t==20) printf("查无此人!");
      printf("\n你想继续查看吗?1).是 2).否 回到主菜单:[]\b\b");
scanf("%d",&w1);
if(w1==1)
 name();
else {fclose(fp);
    getchar();
    printf_back();}
}
void menu()
{
   int n,w1;
   do
   {
    puts("\n\t\t**********菜单**********\n\n");
    puts("\t\t\t1.删除");
    puts("\t\t\t2.修改");
    puts("\t\t\t3.按类别查看");
    puts("\t\t\t4.按姓名查看");
	puts("\t\t\t5.增添");
    puts("\t\t\t6.退出");
    puts("\n\n\t\t**********************\n");
    printf("请选择数字(1-5):[]\b\b");
    scanf("%d",&n);
    if(n<1||n>6)
    {
    w1=1;
	getchar();
    }
    else w1=0;
   }
    while(w1==1);

   switch(n)
   {
   case 1:del();break;
   case 2:browse();break;
   case 3:search();break;
   case 4:name();break;
   case 5:add();break;
   case 6:exit(0);
   }
}

void main()
{
    menu();
}

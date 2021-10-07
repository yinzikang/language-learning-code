#include <stdio.h>           //一些预处理命令、结构体定义和函数声明   
#include <string.h>
#include <conio.h>              
#include <stdlib.h>              
#define N 100
//#define FOR(i) for(i=0;i<NUM;i++)
int NUM=3;
struct trafic            //整型变量、字符型数组存放信息
{
  int car;
  int num;
  char driver[10];
  char police[10];
  int year;
  int month;
  int date;
}list[N];

void save();
void load();
void out();
void del();
void add();
void p();
void search();
void manage();
void ser_car();
void ser_dri();
void ser_pol();

compare(int y,int m,int d,int y1,int y2,int m1,int m2,int d1,int d2)   
{
  int z=0;
  if(y>y1&&y<y2) z=1;
  if(y==y1&&y<y2&&m>m1) z=1;
  if(y>y1&&y==y2&&m<m2) z=1;
  if(y==y1&&y==y2)
  {
    if(m>m1&&m<m2) z=1;
    if(m==m1&&m<m2&&d>d1) z=1;
    if(m>m1&&m==m2&&d<d2) z=1;
    if(m==m1&&m==m2&&d>=d1&&d<=d2) z=1;
  }
  return(z);
}

void save()     //信息储存函数
{
  FILE *fp;
  int i;
  fp=fopen("List_tra.txt","w");
	if(fp == NULL)
	{
		printf("文件打开出错！！！\n");
		return;
	}
	else
		fprintf(fp,"%d\n",NUM);
		for(i=0;i<NUM;++i)
		{
			fprintf(fp,"%d %d %s %s %d %d %d\n",list[i].num,list[i].car,list[i].driver,list[i].police,list[i].year,list[i].month,list[i].date);
		}
		printf("\n数据保存成功！！！\n");
		fclose(fp);
}

void load()          //信息读取函数
{
	int i;
	FILE *fp;
	fp = fopen("List_tra.txt","r");
	if(fp == NULL)
	{
		printf("文件打开出错！！！\n");
		return;
	}
	else
	{
		fscanf(fp,"%d",&NUM);
		
		for(i=0;i<NUM;++i)
		{   
			fscanf(fp,"%d",&list[i].num);
			fscanf(fp,"%d",&list[i].car);
			fscanf(fp,"%s",list[i].driver);
			fscanf(fp,"%s",list[i].police);
			fscanf(fp,"%d",&list[i].year);
			fscanf(fp,"%d",&list[i].month);
			fscanf(fp,"%d",&list[i].date);
		}
		printf("\n文件读取成功！！！\n");
		fclose(fp);
	}
}

void ser_car()    
{
  int i,c;
  load();
  printf("请输入车牌号：");
  scanf("%d",&c);
  for(i=0;i<NUM;++i)
    if(c==list[i].car)
      printf("序号:%d 车牌号:%d  驾照号:%s  开单交警号码:%s\n年:%d  月:%d  日:%d\n\n",list[i].num,list[i].car,list[i].driver,list[i].police,list[i].year,list[i].month,list[i].date);
   else 
   {
	 printf("没有满足条件的罚单\n");
	 break;
   }
}

void ser_dri()
{
  int i;
  char d[10];
  load();
  printf("请输入驾照号：");
  scanf("%s",d);
  for(i=0;i<NUM;++i)
      if(strcmp(d,list[i].driver)==0)
         printf("序号:%d 车牌号:%d  驾照号:%s  开单交警号码:%s\n年:%d  月:%d  日:%d\n\n",list[i].num,list[i].car,list[i].driver,list[i].police,list[i].year,list[i].month,list[i].date);
	  else
	  {    
	    printf("没有满足条件的罚单\n");
	    break;
	  }    
}

void ser_pol()
{
  int i;
  char p[10];
  load();
   printf("请输入开单交警号：");
  scanf("%s",p);
  for(i=0;i<NUM;++i)
    if(strcmp(p,list[i].police)==0)
     printf("序号:%d 车牌号:%d  驾照号:%s  开单交警号码:%s\n年:%d  月:%d  日:%d\n\n",list[i].num,list[i].car,list[i].driver,list[i].police,list[i].year,list[i].month,list[i].date);
    else
	{
	   printf("没有满足条件的罚单\n");
	   break;
	 } 
}

void out()
{
  int i;
  printf("请输入:序号、车牌号、驾照号、开单交警号、年、月、日\n");
  for(i=0;i<NUM;++i)
  {
    scanf("%d%d%s%s%d%d%d",&list[i].num,&list[i].car,&list[i].driver,&list[i].police,&list[i].year,&list[i].month,&list[i].date);
    list[i].num=i+1;
  }
  save();
}

void del()
{
  int b;
  load();
  printf("请选择要删除的序号：");
  scanf("%d",&b);
  b--;
  list[b].car=list[b].year=list[b].month=list[b].date=0;
  list[b].driver[0]=list[b].police[0]='\0';
  save();
}

void add()
{
  int a;
  load();
  printf("请选择要添加的序号：");
  scanf("%d",&a);
  a--;
  printf("请输入:序号、车牌号、驾照号、开单交警号、年、月、日\n");
  scanf("%d%d%s%s%d%d%d",&list[a].num,&list[a].car,&list[a].driver,&list[a].police,&list[a].year,&list[a].month,&list[a].date);
  list[a].num=a+1;
  save();
}

void p()         //信息显示函数
{
  int b;
  load();
 	for(b=0;b<NUM;++b)
    printf("序号:%d 车牌号:%d  驾照号:%s  开单交警号码:%s\n年:%d  月:%d  日:%d\n\n",list[b].num,list[b].car,list[b].driver,list[b].police,list[b].year,list[b].month,list[b].date);
}

void search()    //信息查询函数
{
  int k=1;
  printf("请输入要查询的序号：\n");
  while(k)
  {
    printf("\t\t\t1.车牌号     2.驾照号     3.开单交警号码     0.退出\n");
    scanf("%d",&k);
    switch(k)
    {
      case 1:ser_car();break;
      case 2:ser_dri();break;
      case 3:ser_pol();break;
      case 0:break;
      default:printf("错误\n");
    }
  }
}

void manage()     //2.	信息管理函数
{
  int y1,y2,m1,m2,d1,d2,i,n=0,l[N]={0};
  char dr[10];
  load();
  printf("请输入起始日期（年 月 日）\n");
  scanf("%d%d%d",&y1,&m1,&d1);
  printf("请输入结束日期（年 月 日）\n");
  scanf("%d%d%d",&y2,&m2,&d2);
  printf("请输入司机驾照号:\n");
  scanf("%s",dr);
 for(i=0;i<NUM;++i)
  {
    if(compare(list[i].year,list[i].month,list[i].date,y1,y2,m1,m2,d1,d2))
      if(strcmp(dr,list[i].driver)==0)
      {
        printf("序号:%d  车牌号:%d  驾照号:%s  开单交警号:%s\n年:%d  月:%d  日:%d\n\n",list[i].num,list[i].car,list[i].driver,list[i].police,list[i].year,list[i].month,list[i].date);
        n++;
        l[i]=1;
      }
  }
  printf("罚单数为%d",n);
 //for(i=0;i<NUM;++i)
    if(l[i]) printf ("%d  ",i+1);
}

main()                        //显示菜单
{
	int key=1;
	while(key)
	{
		system("cls");
		printf("\n\t\t\t1.输入          2.浏览\n\n");  
		printf("\t\t\t3.删除          4.添加\n\n");
	    printf("\t\t\t5.查询          6.统计\n\n");
		printf("\t\t\t7.保存          8.读取\n\n");
		printf("\t\t\t0.退出\n");
		scanf("%d",&key);
		switch(key)
		{
		case 1:out();break;
		case 2:p();break;
		case 3:del();break;
		case 4:add();break;
		case 5:search();break;
		case 6:manage();break;
		case 7:save();break;
		case 8:load();break;
		case 0:break;
		default:printf("error\n");
		}
		if(key != 0)
		{
			printf("\n请按回车键继续 ... ");
			getchar();
			getchar();
		}
	}
}
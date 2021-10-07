#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 20
#define T  (time-8)/2

int sum[6]={0};
int computer[6][20]={{1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,1,1,1},
{1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0},
{1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1}};/*该数组表示假设某天某人查询时机房各个时间段机位数情况*/
void Menu();       
void Situation();
void Book();
void Cancel();
void SearchWaiting();
void detail(int time);
void prione(int i);
struct waitlist       /*等待列表*/
{
   char number[3];
   char telephonenumber[11];      
} wait[N];

void printone(int i);
int main()
{
	Menu();     /*当前状态函数*/
}

void Menu()         /*主界面*/
{
	int n,w;
	do
	{
	  puts("\t\t****************机房机位预约系统************************\n");
      puts("\t\t*************************菜单***************************\n");
	  puts("\t\t\t 1.查询某时间段机位状态");  /*查询某时间段机位状态*/
	  puts("\t\t\t 2.预定空机位");   /*预定空机位*/
	  puts("\t\t\t 3.取消预订");    /*取消预订*/
	  puts("\t\t\t 4.查询等待信息");     /*查询等待信息*/
      puts("\t\t\t 5.退出");    /*退出*/
	  puts("\t\t********************************************************\n");
	  printf("选择菜单号(1-5):");
	  scanf("%d",&n); 
	  if(n<1||n>5)
	  {w=1;getchar();}
	  else
	  w=0;
	}while(w==1);
	switch(n)
	{
	case 1:Situation();break;
	case 2:Book();break; 
	case 3:Cancel();break;
	case 4:SearchWaiting();break;
	case 5:exit(0);break;
	}
	getch();
}
/*时间查询*/
void Situation()
{
	int time;
	printf("输在 (8-20)范围内的时间:");
	scanf("%d",&time);
	if(time<8||time>20)
	{printf("\t时间输入错误!\n");
	printf("输入在 (8-20)范围内的时间:");
	scanf("%d",&time);
    }
	detail(time);              /*函数调用*/
	getchar();
	Menu();
}
/*预定函数*/
void Book()
{int time,i=0,x,y;

FILE *fp;
 char c;
 printf("在(8-20)时间范围内输入你想要预定的时间:");
 scanf("%d",&time);
 if(time<8||time>20)
 {
	 printf("\t时间输入错误!\n");
	 printf("\t在(8-20)时间范围内输入你想要预定的时间:");
	 scanf("%d",&time);
 }
 detail(time);              /*函数调用*/
if(sum[T]>0)
{   if((fp=fopen("waitlist.txt","a"))==NULL)
		{
		   printf("\n无法打开文件!\n");
		  exit(0);
		}
	    printf("\n\t请输入你想要预定的机号，并且留下你的电话号码!:\n");	
	   
	    scanf("%s %s",wait[i].number,wait[i].telephonenumber);
		for(i=0;i<1;i++)
	    fwrite(&wait[i],sizeof(struct waitlist),1,fp);
	    fclose(fp);/*向文本文档添加一个结构体单元*/
	printf("\t再次输入你想要预定的时间!\n");
	scanf("%d",&x);
	/*sum[T]--;       / *预定后该时间段空机位数减1*/
	/*computer[T][x]=1;   / *预定后该机状态变为1*/
	printf("\t预订成功!\n");
	getchar();
	Menu();
}
else
{
	printf("这是在这个时间段内未预定的电脑!\n");
	for(i=T+1;i<6;i++)
	{    time=9+2*i;
		detail(time);  /*函数调用*/
		if(sum[T]>0)
		printf("\t最近的空闲时间是 %d,%d\n",2*i+8,2*i+10);break;
	}
		printf("\t你想要预定吗?:y/n?");
		scanf("%s",&c);
		getchar();
		if(c=='Y'||c=='y')
		{
		   if((fp=fopen("waitlist.txt","r"))==NULL)
		 {
            printf("\n无法打开文件!\n");
	        exit(0);
		 }
		   else
		   {  printf("waitlist： number  telephonenumber\n");
              for(i=0;!feof(fp);i++)
			  {
			     fscanf(fp,"%s %s",&wait[i].number,&wait[i].telephonenumber);
			  }
                fclose(fp);
			  
		   }
		       for(i=0;i<10;i++)
			   { prione(i);}

        printf("\n\t请输入您想预定的机号并留下您的联系方式!:\n");
        if((fp=fopen("waitlist.txt","a"))==NULL)
		{
		   printf("\n无法打开文件!\n");
		  exit(0);
		}
	
	    scanf("%s %s",wait[i].number,wait[i].telephonenumber);
	    for(i=0;i<1;i++)
	    fwrite(&wait[i],sizeof(struct waitlist),1,fp);
	    fclose(fp);                 /*若等待，就用文件的方式列出当时的等待列表并提示输入你的等待序号和联系方式*/
		printf("再次输入电脑的序号!\n");
		scanf("%d",&y);
		sum[T]--;                  
		computer[T][y]=1;  
	    printf("\t好了,请等待我们的电话!\n");
	    Menu();
		}
   else Menu();
}
}
/*取消预订*/
void Cancel()
{
	int time,number;
	printf("在(8-20)时间范围内输入你已经预定的时间:");
	scanf("%d",&time); 
	if(time<8||time>20)
	{
	 printf("\t输入时间错误!\n");
	 printf("\t在(8-20)时间范围内输入你已经预定的时间:");
	 scanf("%d",&time);
     
	}
	else
	{printf("\t输入你预定的机号 :");
	scanf("%d",&number);}
	detail(time);
   /* sum[T]++;    / *预定后该时间段空机位数加1*/
	/*computer[T][number]=0;   / *预定后该机状态变为0*/

	printf("\t取消成功!\n");
	getchar();
	Menu();
}
/*查看等待信息*/
void SearchWaiting()
{
	int time,i;
     FILE *fp;
	printf("\t在(8-20)之间输入您要搜索的时间:");
	scanf("%d",&time);
	if(time<8||time>20)
	{
	 printf("\t时间输入错误!\n");
	 printf("\t在(8-20)之间输入您要搜索的时间:");
	 scanf("%d",&time);
	}
	else
		;
   if((fp=fopen("waitlist.txt","r"))==NULL)
   {
      printf("\nCannot open file!\n");
	 exit(0);
   }
   else
   {  printf("waitlist： number  telephonenumber\n");
        for(i=0;!feof(fp);i++)
		 {
			  fscanf(fp,"%s %s",&wait[i].number,&wait[i].telephonenumber);
		 }
          fclose(fp);
			  
}
	for(i=0;i<10;i++)
	{ prione(i);}
	Menu();
}

/*公共函数*/ 
void detail(int time)           /*此函数功能是实现查找每个时间段空机位总数和空机位号*/
{   
	int i,j=0,k,s=0;
	int v[30];
    for(i=0;i<20;i++)
	{
    if(computer[T][i]==0)
	{  s++;	
	   v[j++]=i;
	}
	}
	sum[T]=s;
	printf("\t目前空置的电脑:%d\n",sum[T]);
	for(k=0;k<j;k++)
	printf("\t空置的电脑是:%d\n",v[k]);
}

void prione(int i)             /*此函数功能是实现输出等待列表到屏幕*/
{
	printf("\t\t%s %s  \n",wait[i].number,wait[i].telephonenumber);}

#include<stdio.h>
#include<string.h>
#define N 100

struct date
{int year;
 int month;
 int day;
};
struct product
{char p_name[20];
 long int p_num;
 char size[4];
 struct date in_date;
 long int max_s;
 long int min_s;
 long int real_s;
 struct product *next;
}pro[N];

menu()                                    /***************菜单函数*************/
{
   int n,m;                       
    do
	{
      puts("\n\t\t*****************菜单********************\n\n");
      puts("\t\t\t1.物资信息录入");
      puts("\t\t\t2.物资信息查询");
      puts("\t\t\t3.新料入库");
      puts("\t\t\t4.物资领取");
      puts("\t\t\t5.物资打印");
	  puts("\t\t\t6.物资数据更新");
      puts("\t\t\t7.退出");
      puts("\n\n\t\t***************************************\n");
      puts("\t\t******************************杨超\n");
      puts("\t\t********************************2009.1.2\n");
      printf("选择操作 [1-7]:[ ]\b\b");
      scanf("%d",&n);
      if(n<1||n>7)
	  {
		  m=1;getchar();
	  }
      else m=0;
	} 
	while(m==1);
switch(n)                                   /***********分别进入各函数******/
 {case 1:write();break;                     /***********录入函数***********/
  case 2:search();break;                    /***********查询函数***********/
  case 3:insert();break;                    /***********新料入库函数*******/
  case 4:lend();break;                      /***********领料函数***********/
  case 5:print();break;                     /***********打印函数***********/
  case 6:rewrite();break;                   /***********信息更改***********/ 
  case 7:exit(0);                           /***********退出***********/
 }
}
main()                                      /***********主函数***********/
{    puts("\n\n\n\n\t\t┌──────欢迎使用物资管理系统────┐");
     puts("\t\t│Name:杨超                               │");
     puts("\t\t│Number:20071001560                      │");
     puts("\t\t│E-mail:ycdida@126.com                   │");
     puts("\t\t│Tel:15872351704                         │"); 
     puts("\t\t│                                        │");
     puts("\t\t│******************************杨超      │");
     puts("\t\t│********************************2009.1.2│");
     puts("\t\t└────────────────────┘");
     printf("\n\t\t\t    按任意键继续");
     getch();
     menu();
 }

/**********************物资信息录入函数****************/

write()
{int i,n,k;
 printf("\n\n\t提示:请确定这是你第一次录入信息,因为之前保存的数据将被删除!\n\n");
 printf("\t\t\t是否继续!\n\n\t\t\t0    *****是\n\n\t\t\t其它 *****否[ ]\b\b");
 scanf("%d",&k);
 if(k!=0) printf_back();
 printf("\n需要录入物资数量(0-%d)?:",N-1);
 scanf("%d",&n);
 printf("\n现在输入信息\n\n");
 for(i=0;i<n;i++)
  {printf("\n现在输入第 %d个物资的信息:\n",i+1);
   input(i);
  }
 if(i!=0)save(n);
 printf_back();
}
 /**********************查询函数************************/
search()
{
 searchmenu();
}
/********查询菜单********/

searchmenu()
{int n,w2;
 do
  {
   puts("\n\t\t*****************查询目录********************\n\n");
   puts("\t\t\t1.以名称查询");
   puts("\t\t\t2.以日期查询");
   puts("\t\t\t3.以名称和规格查询");
   puts("\t\t\t4.返回");
   puts("\n\n\t\t***************************************\n");
   printf("选择命令 [1-4]:[ ]\b\b");
   scanf("%d",&n);
   if(n<1||n>4)
    {w2=1;getchar();}
   else w2=0;
  }while(w2==1);
 switch(n)                                  /*********跳转到查询函数********/
 {case 1:search_by_name();break;            /*********转入以名称查询函数********/
  case 2:search_by_date();break;            /*********转入以日期查询函数***********/
  case 3:search_by_nameandsize();break;     /*********转入以名称和规格查询函数*****/
  case 4:getch();menu();                    /********跳转到菜单函数***********/
 }
}

/********以名称查询函数********/
search_by_name()
{int j,n,m=0;char a[20];
 n=load();
 printf("\n输入你所查询信息的名称！\nname:");
 scanf("%s",a);
 for(j=0;j<n;j++)
   if(strcmp(a,pro[j].p_name)==0)
    {m++;
     printf_data(j);
     }
printf("\n有%d种物资与查询相匹配!",m);
getch();
menu();
}
/********以日期查询函数********/
struct search_date
{int year;
 int month;
 int day;
}s;
search_by_date()
{int j,n,m=0;
 n=load();
 printf("\n输入你所查询信息的日期！\ndate:");
 scanf("%d.%d.%d",&s.year,&s.month,&s.day);
 for(j=0;j<n;j++)
if((s.year==pro[j].in_date.year)&&(s.month==pro[j].in_date.month)&&(s.day==pro[j].in_date.day))
    {m++;
     printf_data(j);
    }
printf("\n有%d种物资与查询相匹配!",m);
getch();
menu();
}
/******以名称和规格查询函数******/
search_by_nameandsize()
{int j,n,m=0;char a[20],b[4];
 n=load();
 printf("\n输入你所查询信息的名称！\nname:");
 scanf("%s",a);
 printf("\n输入你所查询信息的规格！\nsize:");
 scanf("%s",b);
 for(j=0;j<n;j++)
  if((strcmp(a,pro[j].p_name)==0)&&(strcmp(b,pro[j].size)==0))
   {m++;
    printf_data(j);
   }
printf("\n有%d种物资与查询相匹配!",m);
getch();
menu();
}

/****************************入库出库结构体****************************/
struct one_pro
{char p_name[20];
long int p_num;
 char size[4];
 struct date one_date;
 long int total;
 struct one_pro *next;
}take;
/****************************新料入库函数****************************/
insert()
{int n,c;
 n=load();
 puts("\n请输入相关信息:\n");
 do
  {input(n);
   printf_data(n);
 printf("\n\n是否确定输入\n1  ).是\n2  ).从新输入\n其它).返回 [ ]\b\b");
   scanf("%d",&c);
   if(c==1)
   { 
	 save(n+1);printf_back();
   }
   else if(c!=2)menu();
  }while(c==2);
}


/********************************信息更改函数***************************/

rewrite()
{char p_name[20];
long int p_num;
 char size[4];
int m,n,j,k=0;
   n=load();
   do
   {
     puts("\n要更改物资的信息:名称 编号 规格");
     scanf("%s%ld%s",&p_name,&p_num,&size);
     printf("名称：%s\t\t编号：%ld\t\t规格：%s",&p_name,p_num,&size);
     printf("\n\n\n\n\t\t\t是否继续!\n\n\t\t\t0 *****是\n\n\t\t\t1 ****退出\n\n\t\t\t其它 *****重新输入[ ]\b\b");
     scanf("%d",&m);
	 if(m==1) 
		 printf_back();
	 else if(m==0)
		 k=1;
   }
   while(k!=1);
 for(j=0;j<n;j++)
  if((strcmp(p_name,pro[j].p_name)==0)&&(p_num==pro[j].p_num)&&(strcmp(size,pro[j].size)==0))
  {
   puts("\n请重新输入信息\n");
   input(j);
   save(n);
   printf_back();
  }
      puts("未找到\n按任意键返回!");
      getch();
      menu();
}
/********************************领料函数*******************************/
lend()
{
 int j,n,k=0;
    n=load();
    printf("\n请输入你需要物资内容的相关信息！");
    printf("\n名称(1-20字母)\t规格(1-4字母)\t入库日期\t领取数量\n");
    scanf("%s\t%s\t%d.%d.%d\t%d",&take.p_name,&take.size,&take.one_date.year,&take.one_date.month,&take.one_date.day,&take.total);
 for(j=0;j<n;j++)
 if((strcmp(take.p_name,pro[j].p_name)==0)&&(strcmp(take.size,pro[j].size)==0)&&(take.one_date.year==pro[j].in_date.year)&&(take.one_date.month==pro[j].in_date.month)&&(take.one_date.day==pro[j].in_date.day)&&(take.total<=pro[j].real_s))
 {
  pro[j].real_s-=take.total;
  printf_data(j);
  k=1;
 }
if(k==0) {printf("输入数据未找到！");getch();menu();}
save(n);
printf_back();

}

/**************************打印函数********************/

print()
{int i,n;
 n=load();
 for(i=0;i<n;i++)
 printf_data(i);
 puts("\n\n\t\t\t任意键返回");
 getch();
 menu();
}


/********下面是一些常调用的函数**********/
#include<stdio.h>
save(int n)                          /*********保存函数***********/
{FILE*fp;
 int k;
 if((fp=fopen("pro.dat","wb"))==NULL)
   {printf("\n文件打开失败！\n");
   return NULL;
   }
 for(k=0;k<n;k++)
   if(pro[k].real_s!=0)
     if(fwrite(&pro[k],sizeof(struct product),1,fp)!=1)
       printf("文件存储失败\n");
 fclose(fp);
}

load()                               /*********从文件读入函数**********/
{
 FILE*fp;
 int k;
 if((fp=fopen("pro.dat","rb"))==NULL)
   {printf("\n文件打开失败！\n");
   return NULL;
   }
 for(k=0;!feof(fp);k++)
   fread(&pro[k],sizeof(struct product),1,fp);
 fclose(fp);
 return(k-1);
}

input(int i)                          /**********输入函数********/
{printf("\n名称(1-20字母):");
 scanf("%s",&pro[i].p_name);
 printf("\n编号(1-7数字):");
 scanf("%d",&pro[i].p_num);
 printf("\n规格(1-4字母):");
 scanf("%s",&pro[i].size);
 printf("\n入库日期（年.月.日）:");
 scanf("%d.%d.%d",&pro[i].in_date.year,&pro[i].in_date.month,&pro[i].in_date.day);
 printf("\n数量[库存最小-实际-最大]:");
 scanf("%d-%d-%d",&pro[i].min_s,&pro[i].real_s,&pro[i].max_s);
}

printf_data(int i)                                              /**********打印函数********/
{printf("\n名称\t\t编号\t规格\t日期\t\t库存最小-实际-最大\n");
printf("%s\t\t%d\t%s\t%d.%d.%d\t\t%d-%d-%d",pro[i].p_name,pro[i].p_num,pro[i].size,pro[i].in_date.year,pro[i].in_date.month,pro[i].in_date.day,pro[i].min_s,pro[i].real_s,pro[i].max_s);
}

printf_back()                                                 /**********返回提示函数*******/
{printf("\n\n操作完成\n\n按任意键返回!\n");
 getch();
 menu();
}

#include<stdio.h>  //标准输入、输出头文件
#include<string.h>    //包含字符串函数处理头文件
#include<stdlib.h>     //包含动态存储与释放函数头文件
#define N 10000  
struct air         //定义结构体数组
{
 int num;
 char start[20];
 char over[20];
 char time[10];
 int count;
}s[N];
int i;
int m=0;
#define PRINT "%-d%12s%12s%10s%12d\n",s[i].num,s[i].start,s[i].over,s[i].time,s[i].count    //定义输出格式
void input();    //输入航班信息
void print();    //输出航班信息
void save();     //保存航班信息 
void read();     //读取航班信息
void search();   //查找航班信息
void shanchu();  //删除航班信息
void dingpiao(); //订票信息
void tuipiao();  //退票信息
void xiugai();   //修改信息
void main()
{
 
 int  j;
 printf("                       ★---您好，欢迎进入中国民航管理系统！---★\n"); 
    printf("================================================================================\n");
    do
  {
  printf("           -------- ☆        1.输入航班信息            ☆-------- \n\n"
               "     -------- ☆        2.浏览航班信息            ☆-------- \n\n"
      "           -------- ☆        3.修改航班信息            ☆-------- \n\n"
      "           -------- ☆        4.查找航班信息            ☆-------- \n\n"
      "           -------- ☆        5.删除航班信息            ☆-------- \n\n"
      "           -------- ☆        6.订票信息                ☆-------- \n\n" 
         "           -------- ☆        7.退票信息                ☆-------- \n\n"
         "           -------- ☆        0.退出                    ☆-------- \n\n");
     printf("================================================================================\n");
 printf("请在0-7中选择以回车键结束：\n\n");
  scanf("%d",&j);
  switch(j)
  {
  case 1: input();//调用输入模块
    break;
  case 2:print();//调用打印模块
    break;
  case 3:xiugai();//调用修改模块
    break;
  case 4:search();//调用查找模块
    break;
  case 5:shanchu();  //调用删除模块
    break;
  case 6:dingpiao();//调用订票模块
    break;
  case 7:tuipiao();//调用退票模块
    break; 
  case 0:;
   break;
  }
 }while(j!=0);     //判断结束
 printf("谢谢使用，再见！\n");
}//主函数结束
void input()//打印模块程序
{ 
 char f[]="2014";    //设置密码
 int y;
 printf("请输入密码并以回车键结束:\n\n");
 scanf("%s",f);          //读取密码
 if(strcmp(f,"2014")==0)
 {
  printf("请依次输入航班信息（机票数位0结束输入）:\n\n"
         "完成输入信息请键入w以回车键结束\n\n");      //打印提示信息
  printf("--------------------------------------------------------------------------\n");
   for(i=0;i<N;i++)
   {
  
  printf("请输入航班号:\n");  
  scanf("%d",&s[i].num);     //读取航班号
  printf("请输入起始站:\n");
      scanf("%s",s[i].start);//读取起始站
  printf("请输入终点站:\n");
      scanf("%s",s[i].over);//读取终点站
  printf("请输入时间:\n");
      scanf("%s",s[i].time);//读取时间
  printf("请输入机票数（机票数为0结束输入）:\n",m);
      scanf("%d",&s[i].count);//读取机票数
  m++;
  
  printf("第%d个信息已经输完是否继续?按任意键继续，按 0结束",m);
  scanf("%d",&y);
  if(y==0)
  {
   save();//将结构体信息存盘
   print();//输出输入的航班信息
   break;
  }
  
   }
 
 }
 else
  printf("输入密码错误!请检查您的密码是否正确!谢谢!再见!\n\n");
}
void save()//保存模块程序
{   
 FILE *fp,*fp1;//定义文件指针
 if((fp=fopen("chen.dat","wb"))==NULL)//打开文件并判断是否出错  
 {
  printf("创建文件失败!\n\n");//打印出错提示
  getchar();
  return;
 }
 if((fp1=fopen("hao.dat","wb"))==NULL)//打开文件并判断是否出错  
 {
  printf("创建文件失败!\n\n");//打印出错提示
  getchar();
  return;
 }
 
 for(i=0;i<m;i++)
  if(fwrite(&s[i],sizeof(struct air),1,fp)==0)//向文件写入数据，并判断是否出错
 printf("向文件输入数据失败!\n\n");
 fprintf(fp1,"%d",m);
 fclose(fp);//关闭文件
 fclose(fp1);//关闭文件
}

void read()//从文件读取信息模块
{
 FILE *fp,*fp1;//定义文件指针
 if((fp=fopen("chen.dat","rb"))==NULL)//打开文件，并判断是否出错
 {
  printf("出错，请检查文件是否存在，按任意键返回住菜单");//打印出错提示
  getchar();
 }
 if((fp1=fopen("hao.dat","rb"))==NULL)//打开文件并判断是否出错  
 {
  printf("创建文件失败!\n\n");//打印出错提示
  getchar();
  return;
 }
 fscanf(fp1,"%d",&m);
 fclose(fp1);//关闭文件
 for(i=0;i<m;i++) 
 {
  fread(&s[i],sizeof(struct air),1,fp);
  
  //从文件中读取信息
 }
 fclose(fp);//关闭文件
}
void print()//打印模块
{
 char w[10];
 read();//调用读取文件函数
 printf("航班号       起始站      终点站    时间       机票数\n");
 for(i=0;i<m;i++)
 {
       printf(PRINT);//打印信息
 }
 printf("请按任意键回车键结束返回上层菜单以:\n");
 scanf("%s",w);
}
   
void search()//查询模块
{
 char name1[20];
 char name2[20];
 char ii[10];
 int n,no;
do
{
 printf("请选择查找方式：\n\n");//打印查询方式菜单
 printf("1.按航班号查找\n\n"
     "2.按终点站查找\n\n"
     "3.按航线查找\n\n"
     "0.返回\n\n");
 printf("请在0-3中选择：\n\n"
      "按其他键以回车键结束返回主菜单:\n\n");
 scanf("%d",&n);//读取查找方式
 if(n==0)
  break;
 switch(n)
 {
 case 1:
  printf("请输入航班号：\n");
  scanf("%d",&no);//航班号
  break;
 case 2:
  printf("请输入终点站名称：\n");
  scanf("%s",name2);//读取终点站
  break;
 case 3:
  printf("请输入起始站名称：\n");
  scanf("%s",name1);//读取起始站
  printf("请输入终点站名称：\n");
  scanf("%s",name2);//终点站
  break;
 }
 read();//调用读取函数
 for(i=0;i<m;i++)
 {    
  if(strcmp(s[i].over,name1)==0||strcmp(s[i].over,name2)==0)//按终点站起始站判断输出条件
  {
   printf("\n查找航班信息成功!\n");
   printf("航班号       起始站      终点站    时间       机票数\n");
   printf(PRINT);//打印信息
   break;
  }
  if(s[i].num==no)//按航班号判断输出条件
  {  
   printf("\n查找航班信息成功!\n");
   printf("航班号       起始站      终点站    时间       机票数\n");
   printf(PRINT);//打印信息
   break;
  } 
 }
 no=0;//将航班号赋值为0
 printf("没有您需要的信息或查找完毕：\n\n"
     "是否继续查找?请键入yes或no以回车键结束\n");
  scanf("%s",ii);
}while(strcmp(ii,"yes")==0);//判断结束
}
void shanchu()//删除模块
{
 char name1[20];
 char name2[20];
 char ii[10];
 char f[]="2008china";//设置密码
 int no,n; 
 printf("请输入密码并以回车键结束:\n\n");
 scanf("%s",f);//读取密码
 if(strcmp(f,"2008china")==0)    //判断密码是否正确
 {
  do 
   {
    printf("请选择删除以方式回车键结束：\n\n");//打印删除方式菜单
    printf("*1.按航班号删除\n\n"
        "*2.按航线删除\n\n"
        "*0.返回\n\n");
    printf("请在0-2中选择以回车键结束：\n");
    scanf("%d",&n);//读取删除方式
    if(n==0)
     break;    //跳出循环
    switch(n)
    {
    case 1:
     printf("请输入航班号：\n");
     scanf("%d",&no);//读取航班号
     read();//调用读取函数
     break;//跳出循环
    case 2:
     printf("请输入起始站 名称：\n");
     scanf("%s",name1);//读取起始站
     printf("请输入终点站名称：\n");
     scanf("%s",name2);//读取终点站
     read();//调用读取函数
     break;//跳出循环
    }
    for(i=0;i<m;i++)
    {
     if(s[i].num==no||strcmp(s[i].start,name1)==0&&strcmp(s[i].over,name2)==0)//判断输入信息是否存在
     {       
      s[i]=s[m-1];
      m--;
     }
     
    }
     printf("查找完毕或没有这个信息\n\n");
        printf("是否继续删除\n");     
    printf("请键入yes或no以回车键结束\n");
    scanf("%s",ii);       //读取是否继续信息
    save(); //调用读取函数
    if(!strcmp(ii,"yes")) //判断是否继续删除    
     printf("请按任意键以回车键结束返回上层菜单:\n");
    break;
   }while(n!=1&&n!=2&&n!=3&&n!=4&&n!=0);  //判断结束
 }
 else
  printf("对不起密码错误!您不是管理员，不能使用此项功能!谢谢!再见!\n\n");
}
  
void dingpiao()//订票模块
{
 int n;
 char a[10];
 do
 {
  search();//调用查询模块
  printf("请输入您要订的机票数以回车键结束：\n");
  scanf("%d",&n);//读取所订机票数
  if(n<0)
  {
   printf("请输入有效的机票数！\n");//判断机票数是否出错
   break;
  }
   if(s[i].count!=0&&s[i].count>=n)//判断是否出错
  {
   s[i].count=s[i].count-n;
   save();//调用保存函数
   printf("订票成功!\n\n");
   break;
  }
  if(s[i].count<n)//判断是否出错
  {
   printf("请输入有效的机票数：\n");
      break; 
  }
  printf("是否继续？ 请输入yes或no以回车键结束:\n");//判断是否继续订票
  scanf("%s",a);
 }while(!strcmp(a,"yes"));//判断结束
 
}
void tuipiao()//退票模块
{
 int n;
 char a[10];
 do
 {
  search();//调用查询模块
  printf("请输入您要退的机票数目：\n");
  scanf("%d",&n);//输入所退票数
  if(n<0) //判断票数是否有效
   printf("请输入有效的机票数！\n");
  s[i].count=s[i].count+n;
  save(); //调用保存模块
  printf("退票成功!\n\n");
  printf("是否继续？ 请键入yes或no以回车键结束:\n\n");//判断是否继续退票
  scanf("%s",a);
 }while(!strcmp(a,"yes"));//判断并跳出循环
 getchar();
}
void xiugai()   //修改模块
{
 struct xiu    //定义结构体 
 {
  int no;
  char name1[20];
  char name2[20];
  char time[20];
  int count;
 }x[1];
 char j[10];
 char f[]="2008china";//设置密码
 int n;
 printf("请输入密码并以回车键结束:\n\n");
 scanf("%s",f);//读取密码
 if(strcmp(f,"2008china")==0)//判断是否出错
 {
  read();//调用读取模块
  do
  {
   printf( "请选择修改方式：\n\n"
              "*1,按航班号修改:\n\n"
           "*2,按航线修改: \n\n");
   printf("请在1---2中修改以回车键结束：\n\n");
   scanf("%d",&n);//读取修改方式
   switch(n)
   {
   case 1:printf("请输入航班号：\n");
    scanf("%d",&x[0].no);//读取航班号
    break;
   case 2:printf("请输入起始站：\n");
    scanf("%s",x[0].name1);//读取起始站
    printf("请输入终点站：\n");
    scanf("%s",x[0].name2);//读取终点站
    break;
   }
   for(i=0;i<m;i++)
   {    
    if(strcmp(s[i].over,x[0].name1)==0&&strcmp(s[i].over,x[0].name2)==0)//判断输出条件
    {
     printf("航班号       起始站      终点站    时间       机票数\n");
     printf(PRINT);
     break;
    }
       if(s[i].num==x[0].no)//判断输出条件
    {  
     printf("航班号       起始站      终点站    时间       机票数\n");
     printf(PRINT);
     break;
    }
   }
   x[0].no=0;            //将结构体中的号为零
   printf("请输入新航班号、起始站、终点站、时间（星期几）、机票数：\n");
   scanf("%d%s%s%s%d",&x[0].no,x[0].name1,x[0].name2,x[0].time,&x[0].count);//定义输入格式
      s[i].num=x[0].no;//替换航班号
      strcpy(s[i].start,x[0].name1);//替换其始站
            strcpy(s[i].over,x[0].name2);//替换终点站
            strcpy(s[i].time,x[0].time);//替换时间
      s[i].count=x[0].count;//替换机票数
      save();//调用保存模块
      printf("是否继续？请键入yes或no以回车键结束:\n\n");
      scanf("%s",j);
  }while(strcmp(j,"yes")==0);  //判断结束
 }
 else
  printf("对不起密码错误!您不是管理员，不能使用此项功能!谢谢!再见!\n\n");
}


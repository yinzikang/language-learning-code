/* 高级语言程序设计（C语言）课程设计源程序 */
/* 题目：销售管理系统 */
/* 时间：2013.1.6   */

#include<stdio.h>
#include<conio.h>
#define max   155
struct   goods
{
     int p_num;
     int num;
     int g_num;

} s[max];


struct   persons
{
     int num[7];

}p[6],w;
/*主函数*/
int n;/*全局变量*/
main()
{  
int   input(), output1(),output2(),output3(),output4(); 
int arg(),mulu();
     int save();
       printf(" \n\n\n \t\t\t    *******销售管理系统********\n\n\n");
    printf("请输入销售信息 :(按-1结束)\n\n销售员代号<4 产品代号<5 销售额\n");   
for(n=0;n<max;n++)
     {  
         scanf("%d",&s[n].p_num);
   if(s[n].p_num==(-1))
             break;
       else 
     scanf("%d%d",&s[n].g_num,&s[n].num);
} 
     mulu();


} 
/*目录*/ 
int   mulu()     
{ int choice;
    arg();
do
{
    printf(" \n\n\n \t\t\t    *******销售管理系统********\n\n\n");
       printf("             1.计算上个月每个人每种产品的销售额\n\n"); 
       printf("             2.按销售额对销售员进行排序，输出排序结果（销售员代号）\n\n"); 
       printf("             3.统计每种产品的总销售额，对这些产品按从高到底的顺序，输出排序结果\n\n"); 
       printf("             4.输出统计报表\n\n"); 
       printf("             0.退出系统\n\n");
       printf("              请选择(0-4):");
       scanf("%d",&choice);
    switch(choice)
       { 
     case    1:    output1();break;
          case    2:    output2();break;    
          case    3:    output3();break;
          case    4:    output4();break;
          case    0:    exit(0);    
       } 

}while(choice!=0);
}


int arg()
{    int k,a,j;
for(k=1;k<=5;k++)
{      p[0].num[k]=k;
         for(a=1;a<=6;a++)
       p[k].num[a]=0;
}
for(k=1;k<=4;k++)
     p[k].num[0]=k;
      
     for(k=1;k<=4;k++)
       for(a=1;a<=5;a++)
         for(j=0;j<n;j++)
         if(s[j].p_num==k && s[j].g_num==a)
       p[k].num[a]=p[k].num[a]+s[j].num;
    /*每种产品的销售额*/
     for(a=1;a<=5;a++)
        for(k=1;k<=4;k++)
    p[5].num[a]=p[5].num[a]+p[k].num[a];
         
    
    /* 每个人的销售额*/
   for(k=1;k<=5;k++)
         for(a=1;a<=5;a++)       
           p[k].num[6]=p[k].num[6]+p[k].num[a];
}
int   output1()
{    int i,k;
     printf("**************上个月每个人销售情况如下:**********\n\n");
printf("                    产品代码 \n销售员码");
for(k=1;k<=5;k++)
   printf("%d\t",p[0].num[k]);
      printf("\n\n");
     for(i=1;i<=4;i++)
{       
   for(k=0;k<=5;k++)
    printf("%d\t",p[i].num[k]);
       printf("\n\n");
}
mulu();
}
/*按销售额对销售员进行排序，输出排序结果（销售员代号）*/
int output2()
{    
     int i,r,j;
      /*按销售额排序*/
     for(i=1;i<4;++i)
     {          
                  r=i;
         for(j=i+1;j<=4;j++)
          if(p[r].num[6]<p[j].num[6]) 
                       r=j;
          if(r!=i)
          {   w=p[i];
             p[i]=p[r];
             p[r]=w;
          }
      
      } 
printf("*********按销售额对销售员排序情况如下**********\n\n");
     printf("销售员代码   \t销售总额    \n");
     for(i=1;i<=4;i++)
         printf("      %d\t\t%d\n",p[i].num[0],p[i].num[6]);
mulu();
}
/*统计每种产品的总销售额，对这些产品按从高到底的顺序，输出排序结果 */    
int output3()    
{         
     int k,i,r,t;
     for(k=1;k<5;k++)
     {       

           r=k;
         for(t=k+1;t<=5;t++)
           if(p[5].num[r]<p[5].num[t])   r=t;
          if(r!=k)
          for(i=0;i<=5;i++)
    {     p[i].num[6]=p[i].num[k];
            p[i].num[k]=p[i].num[r];
         p[i].num[r]=p[i].num[6];
    }
    
     }
   printf("*****每种产品的总销售额顺序情况如下*****\n\n");
      printf(" 产品代码      总销售额\n");
     for(k=1;k<=5;k++)
         printf("    %d\t\t%d \n",p[0].num[k],p[5].num[k]);
     mulu();
      
       
}
/* 输出统计报表*/
int output4()
{ int i,k; 
   int flage=0;      
   printf("\t\t****销售统计报表****\n\n\n");
printf("                产品代号   \n销售员码1\t2\t3\t4\t5\t销售之和\n\n");
  
   for(i=1;i<=4;i++)
   {    for(k=0;k<=6;k++)
          printf("%d\t",p[i].num[k]);
          printf("\n\n");
   }
     printf("总和\t");
     for(k=1;k<=6;k++)
                printf("%d\t",p[5].num[k]);

if(flage==0)/*保证只存一次*/
{ save();
      flage=1; 
      printf("\n\n信息已成功保存！_(文件名:goods_informationt)");
}
mulu();
}
int save()
{
   FILE *fp;
   int i,k;
   if((fp=fopen("c://goods_information.txt","wt"))==NULL)
   {
    printf("不能打开文件，按任意键退出！");
    getch();
    exit(1);
   }
   fprintf(fp,"                产品代号   \n销售员码1\t2\t3\t4\t5\t销售之和\n\n");
   for(i=1;i<=4;i++)
   {    for(k=0;k<=6;k++)
          fprintf(fp,"%d\t",p[i].num[k]);
          fprintf(fp,"\n\n");
   }
     fprintf(fp,"总和    ");
     for(k=1;k<=6;k++)
                fprintf(fp,"%d\t",p[5].num[k]);
fclose(fp);
}


/* �߼����Գ�����ƣ�C���ԣ��γ����Դ���� */
/* ��Ŀ�����۹���ϵͳ */
/* ʱ�䣺2013.1.6   */

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
/*������*/
int n;/*ȫ�ֱ���*/
main()
{  
int   input(), output1(),output2(),output3(),output4(); 
int arg(),mulu();
     int save();
       printf(" \n\n\n \t\t\t    *******���۹���ϵͳ********\n\n\n");
    printf("������������Ϣ :(��-1����)\n\n����Ա����<4 ��Ʒ����<5 ���۶�\n");   
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
/*Ŀ¼*/ 
int   mulu()     
{ int choice;
    arg();
do
{
    printf(" \n\n\n \t\t\t    *******���۹���ϵͳ********\n\n\n");
       printf("             1.�����ϸ���ÿ����ÿ�ֲ�Ʒ�����۶�\n\n"); 
       printf("             2.�����۶������Ա�����������������������Ա���ţ�\n\n"); 
       printf("             3.ͳ��ÿ�ֲ�Ʒ�������۶����Щ��Ʒ���Ӹߵ��׵�˳�����������\n\n"); 
       printf("             4.���ͳ�Ʊ���\n\n"); 
       printf("             0.�˳�ϵͳ\n\n");
       printf("              ��ѡ��(0-4):");
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
    /*ÿ�ֲ�Ʒ�����۶�*/
     for(a=1;a<=5;a++)
        for(k=1;k<=4;k++)
    p[5].num[a]=p[5].num[a]+p[k].num[a];
         
    
    /* ÿ���˵����۶�*/
   for(k=1;k<=5;k++)
         for(a=1;a<=5;a++)       
           p[k].num[6]=p[k].num[6]+p[k].num[a];
}
int   output1()
{    int i,k;
     printf("**************�ϸ���ÿ���������������:**********\n\n");
printf("                    ��Ʒ���� \n����Ա��");
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
/*�����۶������Ա�����������������������Ա���ţ�*/
int output2()
{    
     int i,r,j;
      /*�����۶�����*/
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
printf("*********�����۶������Ա�����������**********\n\n");
     printf("����Ա����   \t�����ܶ�    \n");
     for(i=1;i<=4;i++)
         printf("      %d\t\t%d\n",p[i].num[0],p[i].num[6]);
mulu();
}
/*ͳ��ÿ�ֲ�Ʒ�������۶����Щ��Ʒ���Ӹߵ��׵�˳����������� */    
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
   printf("*****ÿ�ֲ�Ʒ�������۶�˳���������*****\n\n");
      printf(" ��Ʒ����      �����۶�\n");
     for(k=1;k<=5;k++)
         printf("    %d\t\t%d \n",p[0].num[k],p[5].num[k]);
     mulu();
      
       
}
/* ���ͳ�Ʊ���*/
int output4()
{ int i,k; 
   int flage=0;      
   printf("\t\t****����ͳ�Ʊ���****\n\n\n");
printf("                ��Ʒ����   \n����Ա��1\t2\t3\t4\t5\t����֮��\n\n");
  
   for(i=1;i<=4;i++)
   {    for(k=0;k<=6;k++)
          printf("%d\t",p[i].num[k]);
          printf("\n\n");
   }
     printf("�ܺ�\t");
     for(k=1;k<=6;k++)
                printf("%d\t",p[5].num[k]);

if(flage==0)/*��ֻ֤��һ��*/
{ save();
      flage=1; 
      printf("\n\n��Ϣ�ѳɹ����棡_(�ļ���:goods_informationt)");
}
mulu();
}
int save()
{
   FILE *fp;
   int i,k;
   if((fp=fopen("c://goods_information.txt","wt"))==NULL)
   {
    printf("���ܴ��ļ�����������˳���");
    getch();
    exit(1);
   }
   fprintf(fp,"                ��Ʒ����   \n����Ա��1\t2\t3\t4\t5\t����֮��\n\n");
   for(i=1;i<=4;i++)
   {    for(k=0;k<=6;k++)
          fprintf(fp,"%d\t",p[i].num[k]);
          fprintf(fp,"\n\n");
   }
     fprintf(fp,"�ܺ�    ");
     for(k=1;k<=6;k++)
                fprintf(fp,"%d\t",p[5].num[k]);
fclose(fp);
}


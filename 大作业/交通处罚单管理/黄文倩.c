#include <stdio.h>           //һЩԤ��������ṹ�嶨��ͺ�������   
#include <string.h>
#include <conio.h>              
#include <stdlib.h>              
#define N 100
//#define FOR(i) for(i=0;i<NUM;i++)
int NUM=3;
struct trafic            //���ͱ������ַ�����������Ϣ
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

void save()     //��Ϣ���溯��
{
  FILE *fp;
  int i;
  fp=fopen("List_tra.txt","w");
	if(fp == NULL)
	{
		printf("�ļ��򿪳�������\n");
		return;
	}
	else
		fprintf(fp,"%d\n",NUM);
		for(i=0;i<NUM;++i)
		{
			fprintf(fp,"%d %d %s %s %d %d %d\n",list[i].num,list[i].car,list[i].driver,list[i].police,list[i].year,list[i].month,list[i].date);
		}
		printf("\n���ݱ���ɹ�������\n");
		fclose(fp);
}

void load()          //��Ϣ��ȡ����
{
	int i;
	FILE *fp;
	fp = fopen("List_tra.txt","r");
	if(fp == NULL)
	{
		printf("�ļ��򿪳�������\n");
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
		printf("\n�ļ���ȡ�ɹ�������\n");
		fclose(fp);
	}
}

void ser_car()    
{
  int i,c;
  load();
  printf("�����복�ƺţ�");
  scanf("%d",&c);
  for(i=0;i<NUM;++i)
    if(c==list[i].car)
      printf("���:%d ���ƺ�:%d  ���պ�:%s  ������������:%s\n��:%d  ��:%d  ��:%d\n\n",list[i].num,list[i].car,list[i].driver,list[i].police,list[i].year,list[i].month,list[i].date);
   else 
   {
	 printf("û�����������ķ���\n");
	 break;
   }
}

void ser_dri()
{
  int i;
  char d[10];
  load();
  printf("��������պţ�");
  scanf("%s",d);
  for(i=0;i<NUM;++i)
      if(strcmp(d,list[i].driver)==0)
         printf("���:%d ���ƺ�:%d  ���պ�:%s  ������������:%s\n��:%d  ��:%d  ��:%d\n\n",list[i].num,list[i].car,list[i].driver,list[i].police,list[i].year,list[i].month,list[i].date);
	  else
	  {    
	    printf("û�����������ķ���\n");
	    break;
	  }    
}

void ser_pol()
{
  int i;
  char p[10];
  load();
   printf("�����뿪�������ţ�");
  scanf("%s",p);
  for(i=0;i<NUM;++i)
    if(strcmp(p,list[i].police)==0)
     printf("���:%d ���ƺ�:%d  ���պ�:%s  ������������:%s\n��:%d  ��:%d  ��:%d\n\n",list[i].num,list[i].car,list[i].driver,list[i].police,list[i].year,list[i].month,list[i].date);
    else
	{
	   printf("û�����������ķ���\n");
	   break;
	 } 
}

void out()
{
  int i;
  printf("������:��š����ƺš����պš����������š��ꡢ�¡���\n");
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
  printf("��ѡ��Ҫɾ������ţ�");
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
  printf("��ѡ��Ҫ��ӵ���ţ�");
  scanf("%d",&a);
  a--;
  printf("������:��š����ƺš����պš����������š��ꡢ�¡���\n");
  scanf("%d%d%s%s%d%d%d",&list[a].num,&list[a].car,&list[a].driver,&list[a].police,&list[a].year,&list[a].month,&list[a].date);
  list[a].num=a+1;
  save();
}

void p()         //��Ϣ��ʾ����
{
  int b;
  load();
 	for(b=0;b<NUM;++b)
    printf("���:%d ���ƺ�:%d  ���պ�:%s  ������������:%s\n��:%d  ��:%d  ��:%d\n\n",list[b].num,list[b].car,list[b].driver,list[b].police,list[b].year,list[b].month,list[b].date);
}

void search()    //��Ϣ��ѯ����
{
  int k=1;
  printf("������Ҫ��ѯ����ţ�\n");
  while(k)
  {
    printf("\t\t\t1.���ƺ�     2.���պ�     3.������������     0.�˳�\n");
    scanf("%d",&k);
    switch(k)
    {
      case 1:ser_car();break;
      case 2:ser_dri();break;
      case 3:ser_pol();break;
      case 0:break;
      default:printf("����\n");
    }
  }
}

void manage()     //2.	��Ϣ������
{
  int y1,y2,m1,m2,d1,d2,i,n=0,l[N]={0};
  char dr[10];
  load();
  printf("��������ʼ���ڣ��� �� �գ�\n");
  scanf("%d%d%d",&y1,&m1,&d1);
  printf("������������ڣ��� �� �գ�\n");
  scanf("%d%d%d",&y2,&m2,&d2);
  printf("������˾�����պ�:\n");
  scanf("%s",dr);
 for(i=0;i<NUM;++i)
  {
    if(compare(list[i].year,list[i].month,list[i].date,y1,y2,m1,m2,d1,d2))
      if(strcmp(dr,list[i].driver)==0)
      {
        printf("���:%d  ���ƺ�:%d  ���պ�:%s  ����������:%s\n��:%d  ��:%d  ��:%d\n\n",list[i].num,list[i].car,list[i].driver,list[i].police,list[i].year,list[i].month,list[i].date);
        n++;
        l[i]=1;
      }
  }
  printf("������Ϊ%d",n);
 //for(i=0;i<NUM;++i)
    if(l[i]) printf ("%d  ",i+1);
}

main()                        //��ʾ�˵�
{
	int key=1;
	while(key)
	{
		system("cls");
		printf("\n\t\t\t1.����          2.���\n\n");  
		printf("\t\t\t3.ɾ��          4.���\n\n");
	    printf("\t\t\t5.��ѯ          6.ͳ��\n\n");
		printf("\t\t\t7.����          8.��ȡ\n\n");
		printf("\t\t\t0.�˳�\n");
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
			printf("\n�밴�س������� ... ");
			getchar();
			getchar();
		}
	}
}
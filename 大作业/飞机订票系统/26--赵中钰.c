#include<stdio.h>  //��׼���롢���ͷ�ļ�
#include<string.h>    //�����ַ�����������ͷ�ļ�
#include<stdlib.h>     //������̬�洢���ͷź���ͷ�ļ�
#define N 10000  
struct air         //����ṹ������
{
 int num;
 char start[20];
 char over[20];
 char time[10];
 int count;
}s[N];
int i;
int m=0;
#define PRINT "%-d%12s%12s%10s%12d\n",s[i].num,s[i].start,s[i].over,s[i].time,s[i].count    //���������ʽ
void input();    //���뺽����Ϣ
void print();    //���������Ϣ
void save();     //���溽����Ϣ 
void read();     //��ȡ������Ϣ
void search();   //���Һ�����Ϣ
void shanchu();  //ɾ��������Ϣ
void dingpiao(); //��Ʊ��Ϣ
void tuipiao();  //��Ʊ��Ϣ
void xiugai();   //�޸���Ϣ
void main()
{
 
 int  j;
 printf("                       ��---���ã���ӭ�����й��񺽹���ϵͳ��---��\n"); 
    printf("================================================================================\n");
    do
  {
  printf("           -------- ��        1.���뺽����Ϣ            ��-------- \n\n"
               "     -------- ��        2.���������Ϣ            ��-------- \n\n"
      "           -------- ��        3.�޸ĺ�����Ϣ            ��-------- \n\n"
      "           -------- ��        4.���Һ�����Ϣ            ��-------- \n\n"
      "           -------- ��        5.ɾ��������Ϣ            ��-------- \n\n"
      "           -------- ��        6.��Ʊ��Ϣ                ��-------- \n\n" 
         "           -------- ��        7.��Ʊ��Ϣ                ��-------- \n\n"
         "           -------- ��        0.�˳�                    ��-------- \n\n");
     printf("================================================================================\n");
 printf("����0-7��ѡ���Իس���������\n\n");
  scanf("%d",&j);
  switch(j)
  {
  case 1: input();//��������ģ��
    break;
  case 2:print();//���ô�ӡģ��
    break;
  case 3:xiugai();//�����޸�ģ��
    break;
  case 4:search();//���ò���ģ��
    break;
  case 5:shanchu();  //����ɾ��ģ��
    break;
  case 6:dingpiao();//���ö�Ʊģ��
    break;
  case 7:tuipiao();//������Ʊģ��
    break; 
  case 0:;
   break;
  }
 }while(j!=0);     //�жϽ���
 printf("ллʹ�ã��ټ���\n");
}//����������
void input()//��ӡģ�����
{ 
 char f[]="2014";    //��������
 int y;
 printf("���������벢�Իس�������:\n\n");
 scanf("%s",f);          //��ȡ����
 if(strcmp(f,"2014")==0)
 {
  printf("���������뺽����Ϣ����Ʊ��λ0�������룩:\n\n"
         "���������Ϣ�����w�Իس�������\n\n");      //��ӡ��ʾ��Ϣ
  printf("--------------------------------------------------------------------------\n");
   for(i=0;i<N;i++)
   {
  
  printf("�����뺽���:\n");  
  scanf("%d",&s[i].num);     //��ȡ�����
  printf("��������ʼվ:\n");
      scanf("%s",s[i].start);//��ȡ��ʼվ
  printf("�������յ�վ:\n");
      scanf("%s",s[i].over);//��ȡ�յ�վ
  printf("������ʱ��:\n");
      scanf("%s",s[i].time);//��ȡʱ��
  printf("�������Ʊ������Ʊ��Ϊ0�������룩:\n",m);
      scanf("%d",&s[i].count);//��ȡ��Ʊ��
  m++;
  
  printf("��%d����Ϣ�Ѿ������Ƿ����?��������������� 0����",m);
  scanf("%d",&y);
  if(y==0)
  {
   save();//���ṹ����Ϣ����
   print();//�������ĺ�����Ϣ
   break;
  }
  
   }
 
 }
 else
  printf("�����������!�������������Ƿ���ȷ!лл!�ټ�!\n\n");
}
void save()//����ģ�����
{   
 FILE *fp,*fp1;//�����ļ�ָ��
 if((fp=fopen("chen.dat","wb"))==NULL)//���ļ����ж��Ƿ����  
 {
  printf("�����ļ�ʧ��!\n\n");//��ӡ������ʾ
  getchar();
  return;
 }
 if((fp1=fopen("hao.dat","wb"))==NULL)//���ļ����ж��Ƿ����  
 {
  printf("�����ļ�ʧ��!\n\n");//��ӡ������ʾ
  getchar();
  return;
 }
 
 for(i=0;i<m;i++)
  if(fwrite(&s[i],sizeof(struct air),1,fp)==0)//���ļ�д�����ݣ����ж��Ƿ����
 printf("���ļ���������ʧ��!\n\n");
 fprintf(fp1,"%d",m);
 fclose(fp);//�ر��ļ�
 fclose(fp1);//�ر��ļ�
}

void read()//���ļ���ȡ��Ϣģ��
{
 FILE *fp,*fp1;//�����ļ�ָ��
 if((fp=fopen("chen.dat","rb"))==NULL)//���ļ������ж��Ƿ����
 {
  printf("���������ļ��Ƿ���ڣ������������ס�˵�");//��ӡ������ʾ
  getchar();
 }
 if((fp1=fopen("hao.dat","rb"))==NULL)//���ļ����ж��Ƿ����  
 {
  printf("�����ļ�ʧ��!\n\n");//��ӡ������ʾ
  getchar();
  return;
 }
 fscanf(fp1,"%d",&m);
 fclose(fp1);//�ر��ļ�
 for(i=0;i<m;i++) 
 {
  fread(&s[i],sizeof(struct air),1,fp);
  
  //���ļ��ж�ȡ��Ϣ
 }
 fclose(fp);//�ر��ļ�
}
void print()//��ӡģ��
{
 char w[10];
 read();//���ö�ȡ�ļ�����
 printf("�����       ��ʼվ      �յ�վ    ʱ��       ��Ʊ��\n");
 for(i=0;i<m;i++)
 {
       printf(PRINT);//��ӡ��Ϣ
 }
 printf("�밴������س������������ϲ�˵���:\n");
 scanf("%s",w);
}
   
void search()//��ѯģ��
{
 char name1[20];
 char name2[20];
 char ii[10];
 int n,no;
do
{
 printf("��ѡ����ҷ�ʽ��\n\n");//��ӡ��ѯ��ʽ�˵�
 printf("1.������Ų���\n\n"
     "2.���յ�վ����\n\n"
     "3.�����߲���\n\n"
     "0.����\n\n");
 printf("����0-3��ѡ��\n\n"
      "���������Իس��������������˵�:\n\n");
 scanf("%d",&n);//��ȡ���ҷ�ʽ
 if(n==0)
  break;
 switch(n)
 {
 case 1:
  printf("�����뺽��ţ�\n");
  scanf("%d",&no);//�����
  break;
 case 2:
  printf("�������յ�վ���ƣ�\n");
  scanf("%s",name2);//��ȡ�յ�վ
  break;
 case 3:
  printf("��������ʼվ���ƣ�\n");
  scanf("%s",name1);//��ȡ��ʼվ
  printf("�������յ�վ���ƣ�\n");
  scanf("%s",name2);//�յ�վ
  break;
 }
 read();//���ö�ȡ����
 for(i=0;i<m;i++)
 {    
  if(strcmp(s[i].over,name1)==0||strcmp(s[i].over,name2)==0)//���յ�վ��ʼվ�ж��������
  {
   printf("\n���Һ�����Ϣ�ɹ�!\n");
   printf("�����       ��ʼվ      �յ�վ    ʱ��       ��Ʊ��\n");
   printf(PRINT);//��ӡ��Ϣ
   break;
  }
  if(s[i].num==no)//��������ж��������
  {  
   printf("\n���Һ�����Ϣ�ɹ�!\n");
   printf("�����       ��ʼվ      �յ�վ    ʱ��       ��Ʊ��\n");
   printf(PRINT);//��ӡ��Ϣ
   break;
  } 
 }
 no=0;//������Ÿ�ֵΪ0
 printf("û������Ҫ����Ϣ�������ϣ�\n\n"
     "�Ƿ��������?�����yes��no�Իس�������\n");
  scanf("%s",ii);
}while(strcmp(ii,"yes")==0);//�жϽ���
}
void shanchu()//ɾ��ģ��
{
 char name1[20];
 char name2[20];
 char ii[10];
 char f[]="2008china";//��������
 int no,n; 
 printf("���������벢�Իس�������:\n\n");
 scanf("%s",f);//��ȡ����
 if(strcmp(f,"2008china")==0)    //�ж������Ƿ���ȷ
 {
  do 
   {
    printf("��ѡ��ɾ���Է�ʽ�س���������\n\n");//��ӡɾ����ʽ�˵�
    printf("*1.�������ɾ��\n\n"
        "*2.������ɾ��\n\n"
        "*0.����\n\n");
    printf("����0-2��ѡ���Իس���������\n");
    scanf("%d",&n);//��ȡɾ����ʽ
    if(n==0)
     break;    //����ѭ��
    switch(n)
    {
    case 1:
     printf("�����뺽��ţ�\n");
     scanf("%d",&no);//��ȡ�����
     read();//���ö�ȡ����
     break;//����ѭ��
    case 2:
     printf("��������ʼվ ���ƣ�\n");
     scanf("%s",name1);//��ȡ��ʼվ
     printf("�������յ�վ���ƣ�\n");
     scanf("%s",name2);//��ȡ�յ�վ
     read();//���ö�ȡ����
     break;//����ѭ��
    }
    for(i=0;i<m;i++)
    {
     if(s[i].num==no||strcmp(s[i].start,name1)==0&&strcmp(s[i].over,name2)==0)//�ж�������Ϣ�Ƿ����
     {       
      s[i]=s[m-1];
      m--;
     }
     
    }
     printf("������ϻ�û�������Ϣ\n\n");
        printf("�Ƿ����ɾ��\n");     
    printf("�����yes��no�Իس�������\n");
    scanf("%s",ii);       //��ȡ�Ƿ������Ϣ
    save(); //���ö�ȡ����
    if(!strcmp(ii,"yes")) //�ж��Ƿ����ɾ��    
     printf("�밴������Իس������������ϲ�˵�:\n");
    break;
   }while(n!=1&&n!=2&&n!=3&&n!=4&&n!=0);  //�жϽ���
 }
 else
  printf("�Բ����������!�����ǹ���Ա������ʹ�ô����!лл!�ټ�!\n\n");
}
  
void dingpiao()//��Ʊģ��
{
 int n;
 char a[10];
 do
 {
  search();//���ò�ѯģ��
  printf("��������Ҫ���Ļ�Ʊ���Իس���������\n");
  scanf("%d",&n);//��ȡ������Ʊ��
  if(n<0)
  {
   printf("��������Ч�Ļ�Ʊ����\n");//�жϻ�Ʊ���Ƿ����
   break;
  }
   if(s[i].count!=0&&s[i].count>=n)//�ж��Ƿ����
  {
   s[i].count=s[i].count-n;
   save();//���ñ��溯��
   printf("��Ʊ�ɹ�!\n\n");
   break;
  }
  if(s[i].count<n)//�ж��Ƿ����
  {
   printf("��������Ч�Ļ�Ʊ����\n");
      break; 
  }
  printf("�Ƿ������ ������yes��no�Իس�������:\n");//�ж��Ƿ������Ʊ
  scanf("%s",a);
 }while(!strcmp(a,"yes"));//�жϽ���
 
}
void tuipiao()//��Ʊģ��
{
 int n;
 char a[10];
 do
 {
  search();//���ò�ѯģ��
  printf("��������Ҫ�˵Ļ�Ʊ��Ŀ��\n");
  scanf("%d",&n);//��������Ʊ��
  if(n<0) //�ж�Ʊ���Ƿ���Ч
   printf("��������Ч�Ļ�Ʊ����\n");
  s[i].count=s[i].count+n;
  save(); //���ñ���ģ��
  printf("��Ʊ�ɹ�!\n\n");
  printf("�Ƿ������ �����yes��no�Իس�������:\n\n");//�ж��Ƿ������Ʊ
  scanf("%s",a);
 }while(!strcmp(a,"yes"));//�жϲ�����ѭ��
 getchar();
}
void xiugai()   //�޸�ģ��
{
 struct xiu    //����ṹ�� 
 {
  int no;
  char name1[20];
  char name2[20];
  char time[20];
  int count;
 }x[1];
 char j[10];
 char f[]="2008china";//��������
 int n;
 printf("���������벢�Իس�������:\n\n");
 scanf("%s",f);//��ȡ����
 if(strcmp(f,"2008china")==0)//�ж��Ƿ����
 {
  read();//���ö�ȡģ��
  do
  {
   printf( "��ѡ���޸ķ�ʽ��\n\n"
              "*1,��������޸�:\n\n"
           "*2,�������޸�: \n\n");
   printf("����1---2���޸��Իس���������\n\n");
   scanf("%d",&n);//��ȡ�޸ķ�ʽ
   switch(n)
   {
   case 1:printf("�����뺽��ţ�\n");
    scanf("%d",&x[0].no);//��ȡ�����
    break;
   case 2:printf("��������ʼվ��\n");
    scanf("%s",x[0].name1);//��ȡ��ʼվ
    printf("�������յ�վ��\n");
    scanf("%s",x[0].name2);//��ȡ�յ�վ
    break;
   }
   for(i=0;i<m;i++)
   {    
    if(strcmp(s[i].over,x[0].name1)==0&&strcmp(s[i].over,x[0].name2)==0)//�ж��������
    {
     printf("�����       ��ʼվ      �յ�վ    ʱ��       ��Ʊ��\n");
     printf(PRINT);
     break;
    }
       if(s[i].num==x[0].no)//�ж��������
    {  
     printf("�����       ��ʼվ      �յ�վ    ʱ��       ��Ʊ��\n");
     printf(PRINT);
     break;
    }
   }
   x[0].no=0;            //���ṹ���еĺ�Ϊ��
   printf("�������º���š���ʼվ���յ�վ��ʱ�䣨���ڼ�������Ʊ����\n");
   scanf("%d%s%s%s%d",&x[0].no,x[0].name1,x[0].name2,x[0].time,&x[0].count);//���������ʽ
      s[i].num=x[0].no;//�滻�����
      strcpy(s[i].start,x[0].name1);//�滻��ʼվ
            strcpy(s[i].over,x[0].name2);//�滻�յ�վ
            strcpy(s[i].time,x[0].time);//�滻ʱ��
      s[i].count=x[0].count;//�滻��Ʊ��
      save();//���ñ���ģ��
      printf("�Ƿ�����������yes��no�Իس�������:\n\n");
      scanf("%s",j);
  }while(strcmp(j,"yes")==0);  //�жϽ���
 }
 else
  printf("�Բ����������!�����ǹ���Ա������ʹ�ô����!лл!�ټ�!\n\n");
}


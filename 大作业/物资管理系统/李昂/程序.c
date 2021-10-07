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

menu()                                    /***************�˵�����*************/
{
   int n,m;                       
    do
	{
      puts("\n\t\t*****************�˵�********************\n\n");
      puts("\t\t\t1.������Ϣ¼��");
      puts("\t\t\t2.������Ϣ��ѯ");
      puts("\t\t\t3.�������");
      puts("\t\t\t4.������ȡ");
      puts("\t\t\t5.���ʴ�ӡ");
	  puts("\t\t\t6.�������ݸ���");
      puts("\t\t\t7.�˳�");
      puts("\n\n\t\t***************************************\n");
      puts("\t\t******************************�\n");
      puts("\t\t********************************2009.1.2\n");
      printf("ѡ����� [1-7]:[ ]\b\b");
      scanf("%d",&n);
      if(n<1||n>7)
	  {
		  m=1;getchar();
	  }
      else m=0;
	} 
	while(m==1);
switch(n)                                   /***********�ֱ���������******/
 {case 1:write();break;                     /***********¼�뺯��***********/
  case 2:search();break;                    /***********��ѯ����***********/
  case 3:insert();break;                    /***********������⺯��*******/
  case 4:lend();break;                      /***********���Ϻ���***********/
  case 5:print();break;                     /***********��ӡ����***********/
  case 6:rewrite();break;                   /***********��Ϣ����***********/ 
  case 7:exit(0);                           /***********�˳�***********/
 }
}
main()                                      /***********������***********/
{    puts("\n\n\n\n\t\t����������������ӭʹ�����ʹ���ϵͳ����������");
     puts("\t\t��Name:�                               ��");
     puts("\t\t��Number:20071001560                      ��");
     puts("\t\t��E-mail:ycdida@126.com                   ��");
     puts("\t\t��Tel:15872351704                         ��"); 
     puts("\t\t��                                        ��");
     puts("\t\t��******************************�      ��");
     puts("\t\t��********************************2009.1.2��");
     puts("\t\t��������������������������������������������");
     printf("\n\t\t\t    �����������");
     getch();
     menu();
 }

/**********************������Ϣ¼�뺯��****************/

write()
{int i,n,k;
 printf("\n\n\t��ʾ:��ȷ���������һ��¼����Ϣ,��Ϊ֮ǰ��������ݽ���ɾ��!\n\n");
 printf("\t\t\t�Ƿ����!\n\n\t\t\t0    *****��\n\n\t\t\t���� *****��[ ]\b\b");
 scanf("%d",&k);
 if(k!=0) printf_back();
 printf("\n��Ҫ¼����������(0-%d)?:",N-1);
 scanf("%d",&n);
 printf("\n����������Ϣ\n\n");
 for(i=0;i<n;i++)
  {printf("\n��������� %d�����ʵ���Ϣ:\n",i+1);
   input(i);
  }
 if(i!=0)save(n);
 printf_back();
}
 /**********************��ѯ����************************/
search()
{
 searchmenu();
}
/********��ѯ�˵�********/

searchmenu()
{int n,w2;
 do
  {
   puts("\n\t\t*****************��ѯĿ¼********************\n\n");
   puts("\t\t\t1.�����Ʋ�ѯ");
   puts("\t\t\t2.�����ڲ�ѯ");
   puts("\t\t\t3.�����ƺ͹���ѯ");
   puts("\t\t\t4.����");
   puts("\n\n\t\t***************************************\n");
   printf("ѡ������ [1-4]:[ ]\b\b");
   scanf("%d",&n);
   if(n<1||n>4)
    {w2=1;getchar();}
   else w2=0;
  }while(w2==1);
 switch(n)                                  /*********��ת����ѯ����********/
 {case 1:search_by_name();break;            /*********ת�������Ʋ�ѯ����********/
  case 2:search_by_date();break;            /*********ת�������ڲ�ѯ����***********/
  case 3:search_by_nameandsize();break;     /*********ת�������ƺ͹���ѯ����*****/
  case 4:getch();menu();                    /********��ת���˵�����***********/
 }
}

/********�����Ʋ�ѯ����********/
search_by_name()
{int j,n,m=0;char a[20];
 n=load();
 printf("\n����������ѯ��Ϣ�����ƣ�\nname:");
 scanf("%s",a);
 for(j=0;j<n;j++)
   if(strcmp(a,pro[j].p_name)==0)
    {m++;
     printf_data(j);
     }
printf("\n��%d���������ѯ��ƥ��!",m);
getch();
menu();
}
/********�����ڲ�ѯ����********/
struct search_date
{int year;
 int month;
 int day;
}s;
search_by_date()
{int j,n,m=0;
 n=load();
 printf("\n����������ѯ��Ϣ�����ڣ�\ndate:");
 scanf("%d.%d.%d",&s.year,&s.month,&s.day);
 for(j=0;j<n;j++)
if((s.year==pro[j].in_date.year)&&(s.month==pro[j].in_date.month)&&(s.day==pro[j].in_date.day))
    {m++;
     printf_data(j);
    }
printf("\n��%d���������ѯ��ƥ��!",m);
getch();
menu();
}
/******�����ƺ͹���ѯ����******/
search_by_nameandsize()
{int j,n,m=0;char a[20],b[4];
 n=load();
 printf("\n����������ѯ��Ϣ�����ƣ�\nname:");
 scanf("%s",a);
 printf("\n����������ѯ��Ϣ�Ĺ��\nsize:");
 scanf("%s",b);
 for(j=0;j<n;j++)
  if((strcmp(a,pro[j].p_name)==0)&&(strcmp(b,pro[j].size)==0))
   {m++;
    printf_data(j);
   }
printf("\n��%d���������ѯ��ƥ��!",m);
getch();
menu();
}

/****************************������ṹ��****************************/
struct one_pro
{char p_name[20];
long int p_num;
 char size[4];
 struct date one_date;
 long int total;
 struct one_pro *next;
}take;
/****************************������⺯��****************************/
insert()
{int n,c;
 n=load();
 puts("\n�����������Ϣ:\n");
 do
  {input(n);
   printf_data(n);
 printf("\n\n�Ƿ�ȷ������\n1  ).��\n2  ).��������\n����).���� [ ]\b\b");
   scanf("%d",&c);
   if(c==1)
   { 
	 save(n+1);printf_back();
   }
   else if(c!=2)menu();
  }while(c==2);
}


/********************************��Ϣ���ĺ���***************************/

rewrite()
{char p_name[20];
long int p_num;
 char size[4];
int m,n,j,k=0;
   n=load();
   do
   {
     puts("\nҪ�������ʵ���Ϣ:���� ��� ���");
     scanf("%s%ld%s",&p_name,&p_num,&size);
     printf("���ƣ�%s\t\t��ţ�%ld\t\t���%s",&p_name,p_num,&size);
     printf("\n\n\n\n\t\t\t�Ƿ����!\n\n\t\t\t0 *****��\n\n\t\t\t1 ****�˳�\n\n\t\t\t���� *****��������[ ]\b\b");
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
   puts("\n������������Ϣ\n");
   input(j);
   save(n);
   printf_back();
  }
      puts("δ�ҵ�\n�����������!");
      getch();
      menu();
}
/********************************���Ϻ���*******************************/
lend()
{
 int j,n,k=0;
    n=load();
    printf("\n����������Ҫ�������ݵ������Ϣ��");
    printf("\n����(1-20��ĸ)\t���(1-4��ĸ)\t�������\t��ȡ����\n");
    scanf("%s\t%s\t%d.%d.%d\t%d",&take.p_name,&take.size,&take.one_date.year,&take.one_date.month,&take.one_date.day,&take.total);
 for(j=0;j<n;j++)
 if((strcmp(take.p_name,pro[j].p_name)==0)&&(strcmp(take.size,pro[j].size)==0)&&(take.one_date.year==pro[j].in_date.year)&&(take.one_date.month==pro[j].in_date.month)&&(take.one_date.day==pro[j].in_date.day)&&(take.total<=pro[j].real_s))
 {
  pro[j].real_s-=take.total;
  printf_data(j);
  k=1;
 }
if(k==0) {printf("��������δ�ҵ���");getch();menu();}
save(n);
printf_back();

}

/**************************��ӡ����********************/

print()
{int i,n;
 n=load();
 for(i=0;i<n;i++)
 printf_data(i);
 puts("\n\n\t\t\t���������");
 getch();
 menu();
}


/********������һЩ�����õĺ���**********/
#include<stdio.h>
save(int n)                          /*********���溯��***********/
{FILE*fp;
 int k;
 if((fp=fopen("pro.dat","wb"))==NULL)
   {printf("\n�ļ���ʧ�ܣ�\n");
   return NULL;
   }
 for(k=0;k<n;k++)
   if(pro[k].real_s!=0)
     if(fwrite(&pro[k],sizeof(struct product),1,fp)!=1)
       printf("�ļ��洢ʧ��\n");
 fclose(fp);
}

load()                               /*********���ļ����뺯��**********/
{
 FILE*fp;
 int k;
 if((fp=fopen("pro.dat","rb"))==NULL)
   {printf("\n�ļ���ʧ�ܣ�\n");
   return NULL;
   }
 for(k=0;!feof(fp);k++)
   fread(&pro[k],sizeof(struct product),1,fp);
 fclose(fp);
 return(k-1);
}

input(int i)                          /**********���뺯��********/
{printf("\n����(1-20��ĸ):");
 scanf("%s",&pro[i].p_name);
 printf("\n���(1-7����):");
 scanf("%d",&pro[i].p_num);
 printf("\n���(1-4��ĸ):");
 scanf("%s",&pro[i].size);
 printf("\n������ڣ���.��.�գ�:");
 scanf("%d.%d.%d",&pro[i].in_date.year,&pro[i].in_date.month,&pro[i].in_date.day);
 printf("\n����[�����С-ʵ��-���]:");
 scanf("%d-%d-%d",&pro[i].min_s,&pro[i].real_s,&pro[i].max_s);
}

printf_data(int i)                                              /**********��ӡ����********/
{printf("\n����\t\t���\t���\t����\t\t�����С-ʵ��-���\n");
printf("%s\t\t%d\t%s\t%d.%d.%d\t\t%d-%d-%d",pro[i].p_name,pro[i].p_num,pro[i].size,pro[i].in_date.year,pro[i].in_date.month,pro[i].in_date.day,pro[i].min_s,pro[i].real_s,pro[i].max_s);
}

printf_back()                                                 /**********������ʾ����*******/
{printf("\n\n�������\n\n�����������!\n");
 getch();
 menu();
}

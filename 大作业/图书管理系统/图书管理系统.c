#include<stdio.h> 
#include<string.h> 
#include<conio.h> 
#include<stdlib.h> 
#include<ctype.h> 
#define STACK_INIT_SIZE 10 
#define OK 1 
#define TRUE 1 
#define ERROR 0

/*����ѧ�����ͣ����ڴ�Ž�����鼮*/ 
struct student { 
int carnum; 
char lendbook[10]; 
}student[1000];

 /*�����������*/ 
struct book
{ 
int booknum; 
char bookname[20]; 
float bookprice;
char bookcreat[20]; 
int turefalse; /*���ڽ���ͻ���ģ���ж�һ�����Ƿ���������*/ 
}book[1000];

/*���鿨����������*/ 
struct car 
{ 
int carnum; 
char sex[5];
char studentname[20]; 
int studentclass; 
}car[1000];
//////////////////////////////////��ѯͼ����Ϣģ��//////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//////(1)����������
findbook()
{ 
FILE *fp; 
char bookname[10]; 
int i; 
fp=fopen("book.txt","r"); 
printf("��������Ҫ���ҵ�����:\n"); 
scanf("%s",bookname); 
for(i=0;fread(&book[i],sizeof(struct book),1,fp)!=0;i++) 
{ 
   if(strcmp(bookname,book[i].bookname)==0) 
   { 
    if(book[i].turefalse==1) 
     
    {
	printf(" ���      ����      ���� \n %d      %s     %s \n",book[i].booknum,book[i].bookname,book[i].bookcreat);
	printf("�����������˽���\n�����������\n"); } 
    else {printf("�Ȿ���Ѿ����˽��\n");fclose(fp);return 0;} 
    fclose(fp); 
    return 0; 
   } 
} 
printf("û����Ҫ��ѯ���鼮!\n"); 
fclose(fp); 
return 0; 
}
//////////(2)�����߲���
findbook1()
{ 
FILE *fp; 
char bookcreat[10]; 
int i; 
fp=fopen("book.txt","r"); 
printf("��������Ҫ���ҵ�������:\n"); 
scanf("%s",bookcreat); 
for(i=0;fread(&book[i],sizeof(struct book),1,fp)!=0;i++) 
{ 
   if(strcmp(bookcreat,book[i].bookcreat)==0) 
   { 
    if(book[i].turefalse==1) 
    { 
     printf(" ���  ����  ���� \n %d    %s    %s \n",book[i].booknum,book[i].bookname,book[i].bookcreat); 
    printf("�����������˽���\n�����������\n");
	} 
    else {printf("�Ȿ���Ѿ����˽��!\n");
	fclose(fp);
	return 0;
	} 
    fclose(fp); 
    return 0; 
   } 
} 
printf("û����Ҫ��ѯ���鼮\n"); 
fclose(fp); 
return 0; 
}
chabook()/////����ͼ����ģ�� 
{ 
char ch5; 
do 
{ 
printf("����ӭ����ͼ���ѯϵͳ����\n"); 
printf(" 1: ���������� \n"); 
printf(" 2: �����߲��� \n"); 
printf(" 0: ���� \n"); 
printf("������0��2:\n"); 
ch5=getch(); 
switch(ch5) 
   { 
    case '1':findbook();getch();break; 
    case '2':findbook1();getch();break; 
    case '0':break; 
    default:printf("�޴˲���!\n");getch();break; 
   } 
}while(ch5!='0');
return 0; 
}
/////////////////////////////////////////////////////////////////
//////////�����뻹��ģ��
/////(1).����ģ��
lendbook() 
{ 
FILE *fp,*fp2; 
int i,n; 
int carnum; 
system("cls");
printf("\t\t����ӭ�������ϵͳ����\n\n");
printf("����������˵�:\n����:\n"); 
scanf("%d",&carnum); 
fp=fopen("car.txt","r"); 
for(i=0;fread(&car[i],sizeof(struct car),1,fp)!=0;i++) 
{ 
   if(car[i].carnum==carnum) 
   { 
    n=i; 
    fclose(fp); 
    printf("����:\n"); 
    scanf("%s",student[n].lendbook); 
    fp=fopen("book.txt","r"); 
    for(i=0;fread(&book[i],sizeof(struct book),1,fp)!=0;i++) 
    { 
     if(strcmp(book[i].bookname,student[n].lendbook)==0) 
     { 
      if(book[i].turefalse==0) {printf("�Բ��𣬴������˽�������������\n");fclose(fp);getch();return 0;} 
      else 
      fclose(fp); 
      fp=fopen("record.txt","a+"); 
      student[n].carnum=carnum; 
      fwrite(&student[n],sizeof(struct student),1,fp); 
      fclose(fp); 
      fp=fopen("book.txt","r"); 
      fp2=fopen("bookl.txt","w"); 
      for(i=0;fread(&book[i],sizeof(struct book),1,fp)!=0;i++) 
      { 
       if(strcmp(book[i].bookname,student[n].lendbook)==0) 
       { 
        book[i].turefalse=0; 
        fwrite(&book[i],sizeof(struct book),1,fp2); 
        continue; 
       } 
       fwrite(&book[i],sizeof(struct book),1,fp2); 
      } 
      fclose(fp); 
      fclose(fp2); 
      fp=fopen("book.txt","w"); 
      fp2=fopen("bookl.txt","r"); 
      for(i=0;fread(&book[i],sizeof(struct book),1,fp2)!=0;i++) 
      { 
       fwrite(&book[i],sizeof(struct book),1,fp); 
      } 
      fclose(fp); 
      fclose(fp2); 
      fopen("bookl.txt","w"); 
      fclose(fp2); 
      printf("������ϣ������������...\n"); 
      getch(); 
      return 0; 
     } 
    } 
    printf("�������������飬���������...\n"); 
    fclose(fp); 
    getch(); 
    return 0; 
   } 
} 
printf("��Ŀ��Ų����ڣ��������¿�,�����������...\n"); 
fclose(fp); 
getch(); 
return 0;}
///////(2).���麯��
huanbook() 
{ 
FILE *fp,*fp2; /*���������ļ�ָ�룬fp2�����޸�����ʱ������ʱ�ļ��ã���ֹ�������ƻ�*/ 
int i,n; 
int carnum; 
char lendbook[10]; 
system("cls");
printf("\t\t����ӭ���뻹��������");
printf("\n�����������\n����:\n"); 
scanf("%d",&carnum); 
fp=fopen("car.txt","r"); /*��ȡ���ż�¼*/ 
for(i=0;fread(&car[i],sizeof(struct car),1,fp)!=0;i++) /*forѭ���жϿ����Ƿ����*/ 
{ 
   if(car[i].carnum==carnum) /*���Ŵ��ڣ�������һѭ��*/ 
   { 
    n=i; 
    fclose(fp); 
    printf("��������Ҫ�����������:\n"); 
    scanf("%s",lendbook); 
    fp=fopen("record.txt","r"); 
    for(i=0;fread(&student[i],sizeof(struct student),1,fp)!=0;i++) /*�ж��Ƿ�������������*/ 
    { 
     if(strcmp(student[i].lendbook,lendbook)==0) /*�����˸��飬������һѭ�������������ʾ*/ 
     { 
      fclose(fp); 
      fp=fopen("record.txt","r"); 
      fp2=fopen("bookl.txt","w"); 
      for(i=0;fread(&student[i],sizeof(struct student),1,fp)!=0;i++) 
      { 
       if(strcmp(student[i].lendbook,lendbook)==0) 
       { 
        continue; /*ɾ����������Ľ����¼*/ 
       } 
       fwrite(&student[i],sizeof(struct student),1,fp2); /*д��ԭ��û������ļ�¼*/ 
      } 
      fclose(fp); 
      fclose(fp2); 
      fp=fopen("record.txt","w"); 
      fp2=fopen("bookl.txt","r"); 
      for(i=0;fread(&student[i],sizeof(struct student),1,fp2)!=0;i++) 
       { 
        fwrite(&student[i],sizeof(struct student),1,fp); /*�������¼��Ϣд��*/ 
       } 
      fclose(fp); 
      fclose(fp2); 
      fopen("bookl.txt","w"); /*����ʱ�ļ��ļ�¼*/ 
      fclose(fp2); 
      fp=fopen("book.txt","r"); 
      fp2=fopen("bookl.txt","w"); 
      for(i=0;fread(&book[i],sizeof(struct book),1,fp)!=0;i++) /*����ļ�¼д����ʱ�ļ�����ֹ��Ϊ�޸���Ϣ�ƻ���ǰ�ļ�¼*/ 
      { 
       if(i==n) 
       { 
        book[i].turefalse=1; 
        fwrite(&book[i],sizeof(struct book),1,fp2); /*���������ԭ��״̬��Ϊ���˽��ĵ�*/ 
        continue; 
       } 
       fwrite(&book[i],sizeof(struct book),1,fp2); 
      } 
      fclose(fp); 
      fclose(fp2); 
      fp=fopen("book.txt","w"); 
      fp2=fopen("bookl.txt","r"); 
      for(i=0;fread(&book[i],sizeof(struct book),1,fp2)!=0;i++) 
      { 
       fwrite(&book[i],sizeof(struct book),1,fp); /*����ʱ�ļ�д��*/ 
      } 
      fclose(fp); 
      fclose(fp2); 
      fopen("bookl.txt","w"); /*����ʱ�ļ�*/ 
      fclose(fp2); 
      printf("������ϣ������������...\n"); 
      getch(); 
      return 1; 
     } 
    } 
    printf("��û�н��������飬���������...\n"); /*������ʾ*/ 
    fclose(fp); 
    getch(); 
    return 0; 
   } 
} 
printf("û�����Ŀ����͹���Ա��ϵ,�����������...\n"); /*������ʾ*/ 
fclose(fp); 
getch(); 
return 0;}
////////(3).����ͳ��
lendcount() 
{ 
FILE *fp; 
int i,n=0; 
fp=fopen("record.txt","r"); 
if((fp=fopen("record.txt","r"))==0)
{printf("�ļ���û������!\n");
printf("�����������...\n"); 
getch();
return(0);
}
for(i=0;fread(&student[i],sizeof(struct student),1,fp)!=0;i++) 
{ 
   printf("����      ������鼮     \n"); 
   printf("%d       %s \n",student[i].carnum,student[i].lendbook); 
   n=n+1; 
} 
fclose(fp); 
printf("Ŀǰ����%d������\n",n); 
printf("�������...\n"); 
getch();
return n; 
}
//////////////////////////////////��Ա������ģ��/////
//////////(1).���ӻ�Ա��
addcar() 
{ 
FILE *fp; 
int i=0; 
fp=fopen("car.txt","a+"); 
printf("����:\n"); 
scanf("%d",&car[i].carnum); 
printf("�Ա�:\n");
scanf("%s",car[i].sex);
printf("����:\n"); 
scanf("%s",car[i].studentname); 
printf("�༶:\n"); 
scanf("%d",&car[i].studentclass); 
fwrite(&car[i],sizeof(struct car),1,fp); 
fclose(fp); 
printf("������ϣ����������...\n"); 
getch(); 
}
//////////(2).ɾ����Ա��
delcar() 
{ 
FILE *fp,*fp2; 
int i; 
int carnum; 
char choice; 
fp=fopen("car.txt","r"); 
fp2=fopen("bookl.txt","w"); 
printf("Ҫɾ���Ŀ���(�����������Ķ�):\n"); 
scanf("%d",&carnum); 
for(i=0;fread(&car[i],sizeof(struct car),1,fp)!=0;i++) 
{ 
   if(car[i].carnum!=carnum) 
   { 
    fwrite(&car[i],sizeof(struct car),1,fp2); 
   } 
} 
fclose(fp); 
fclose(fp2);
system("color 25"); 
printf("ȷ��ɾ��?(Y/N)!\n"); 
scanf("%s",&choice); 
if(choice=='y'||choice=='Y') 
{ 
   fp=fopen("car.txt","w"); 
   fp2=fopen("bookl.txt","r"); 
   for(i=0;fread(&car[i],sizeof(struct car),1,fp2)!=0;i++) 
   { 
    fwrite(&car[i],sizeof(struct car),1,fp); 
   } 
   fclose(fp); 
   fclose(fp2); 
   fp2=fopen("bookl.txt","w"); 
   fclose(fp2); 
   printf("�������ɹ�!\n�����������...\n"); 
   getch(); 
   return 0; 
} 
else 
{ 
   printf("������ȡ��!\n�����������...\n"); 
   getch(); 
   return 0; 
} 
}
//////(3).��Ա��ͳ��
carcount() 
{ 
FILE *fp; 
int i,n=0; 
fp=fopen("car.txt","r"); 
for(i=0;fread(&car[i],sizeof(struct car),1,fp)!=0;i++) 
{ 
   printf("��%d�ſ� \n",i+1); 
   printf("����   �Ա�        ����  �༶   \n"); 
   printf("  %d    %5s    %10s   %3d \n\n",car[i].carnum,car[i].sex,car[i].studentname,car[i].studentclass); 
   n=n+1; 
} 
fclose(fp); 
printf("Ŀǰ����%d����Ա��\n",n); 
printf("�����������...\n"); 
getch(); 
}
////////////////////////////////////////////////////////
/////////////////ͼ�����ģ��///////////////////////////
//////////(1).����ͼ����Ϣ
addbook() 
{ 
FILE *fp; 
int i=0; 
char choice='y'; 
fp=fopen("book.txt","a+"); 
while(choice=='y'||choice=='Y') 
{ system("color 6e"); 
   printf("���:\n");
   scanf("%d",&book[i].booknum); 
   printf("����:\n"); 
   scanf("%s",book[i].bookname); 
   printf("����:\n"); 
   scanf("%s",book[i].bookcreat); 
   printf("����:\n");
   scanf("%f",&book[i].bookprice);
   printf("�����趨���״̬(1�ڼ�/0����):\n");  
   scanf("%d",&book[i].turefalse); 
   fwrite(&book[i],sizeof(struct book),1,fp); 
   printf("�Ƿ�Ҫ�����±���(y/n)\n"); 
   scanf("%s",&choice); 
} 
fclose(fp); 
}
/////////////(2).ɾ��ͼ����Ϣ 
delbook() 
{ 
FILE *fp,*fp2; 
int i; 
char bookname[10],choice; 
fp=fopen("book.txt","r"); 
fp2=fopen("bookl.txt","w"); 
printf("����:\n"); 
scanf("%s",bookname); 
for(i=0;fread(&book[i],sizeof(struct book),1,fp)!=0;i++) 
{ 
   if(strcmp(bookname,book[i].bookname)!=0) 
   { 
    fwrite(&book[i],sizeof(struct book),1,fp2); 
   } 
} 
fclose(fp); 
fclose(fp2); 
printf("ȷ��ɾ��(y/n)?\n"); 
scanf("%s",&choice); 
if(choice=='y'||choice=='Y') 
{ 
   fp=fopen("book.txt","w"); 
   fp2=fopen("bookl.txt","r"); 
   for(i=0;fread(&book[i],sizeof(struct book),1,fp2)!=0;i++) 
   { 
    fwrite(&book[i],sizeof(struct book),1,fp); 
   } 
   fclose(fp); 
   fclose(fp2); 
   fp2=fopen("bookl.txt","w"); 
   fclose(fp2); 
   printf("�����������...\n"); 
   getch(); 
   return 0; 
} 
else 
{ 
   printf("�����������...\n"); 
   getch(); 
   return 0; 
} 
}
/////////////(3)�޸�ͼ��
changebook() 
{ 
FILE *fp,*fp2; 
char bookname[10],choice; 
int i; 
fp=fopen("book.txt","r"); 
fp2=fopen("bookl.txt","w"); 
printf("����:\n"); 
scanf("%s",bookname); 
for(i=0;fread(&book[i],sizeof(struct book),1,fp)!=0;i++) 
{ 
   if(strcmp(book[i].bookname,bookname)==0) 
   { system("color 5e");
    printf("����Ҫ�޸ĵ�����������£���ѡ����Ҫ�޸ĵ�����:\n"); 
    printf("���       ����      ���� \n"); 
    printf("%d   %s  %s\n",book[i].booknum,book[i].bookname,book[i].bookcreat); 
	printf("1: �޸����:\n"); 
    printf("2: �޸�����:\n"); 
    printf("3: �޸�����:\n"); 
	printf("4: �޸ĵ���:");
    printf("������1��4:"); 
     choice=getch(); 
    switch(choice) 
    { 
     case '1': 
     { 
      printf("�µ����:\n"); 
      scanf("%d",&book[i].booknum); 
      fwrite(&book[i],sizeof(struct book),1,fp2); 
     }break; 
     case '2': 
     { 
      printf("�µ�����:\n"); 
      scanf("%s",book[i].bookname); 
      fwrite(&book[i],sizeof(struct book),1,fp2); 
     }break; 
     case '3': 
     { 
      printf("�µ�����:\n"); 
      scanf("%s",book[i].bookcreat); 
      fwrite(&book[i],sizeof(struct book),1,fp2); 
     }break; 
	 case '4':
	{
		printf("�µĵ���:");
		scanf("%f",book[i].bookprice);
        fwrite(&book[i],sizeof(struct book),1,fp2);
	}
     default:printf("û�������Ĳ���!");break; 
    } 
    continue; 
   } 
   fwrite(&book[i],sizeof(struct book),1,fp2); 
} 
fclose(fp); 
fclose(fp2); 
fp=fopen("book.txt","w"); 
fp2=fopen("bookl.txt","r"); 
for(i=0;fread(&book[i],sizeof(struct book),1,fp2)!=0;i++) 
{ 
   fwrite(&book[i],sizeof(struct book),1,fp); 
} 
fclose(fp); 
fp2=fopen("bookl.txt","w"); 
fclose(fp2); 
printf("�����������...\n"); 
getchar(); 
return 0; 
} 
////////////(4).ͼ��ͳ��
bookcount() 
{ 
FILE *fp; 
int i,n=0; 
fp=fopen("book.txt","r"); 
for(i=0;fread(&book[i],sizeof(struct book),1,fp)!=0;i++) 
{ 
   if(book[i].booknum!=0&&strlen(book[i].bookname)!=0&&strlen(book[i].bookcreat)!=0) 
   { 
    printf("��%d����\n���           ����               ����       ����    ״̬ \n",i+1); 
    printf(" %d       %10s    ",book[i].booknum,book[i].bookname); 
	printf("%15s      %4.2f    %d(1��/0����)\n",book[i].bookcreat,book[i].bookprice,book[i].turefalse);
	n=n+1; 
   } 
} 
fclose(fp); 
printf("Ŀǰ����%d����.\n",n); 
printf("�����������...\n"); 
}
//////////////////////�������溯��
end()
{   system("cls");
	printf("\t\t���ש������������������������ש�\n");
	printf("\t\t�ǩ贈�������������������������\n");
	printf("\t\t���� ллʹ�ñ�ϵͳ , �ټ�! ����\n");
      printf("\t\t�ǩ贈�������������������������\n");
      printf("\t\t���ߩ������������������������ߩ�\n");	
}/////////////////////////////////////////////////////////////
////////////////////������///////////////////////////
main() 
{ 
char ch1,ch2,ch4; 
system("color 2e");
do
{  system("cls");
   printf("\t\t���ש������������������������ש�\n");
   printf("\t\t�ǩ贈�������������������������\n");
   printf("\t\t����  ��ӭ����ͼ�����ϵͳ  ����\n");
   printf("\t\t�ǩ贈�������������������������\n");
   printf("\t\t���ߩ������������������������ߩ�\n");
   printf(" ��ѡ��:\n"); 
   printf(" 1:����ͼ�� \n"); 
   printf(" 2:����ͼ�� \n"); 
   printf(" 3:����ϵͳ \n"); 
   printf(" 4:���� \n"); 
   printf(" 0:�˳� \n"); 
   printf("������0��4:\n"); 
   ch1=getch(); 
   switch(ch1) 
   { 
    case '1':chabook();break; 
    case '2':lendbook();;break; 
    case '3':{ 
       do 
       { system("color 4e");
	    system("cls");
        printf("\t\t����ӭ�������ϵͳ����\n"); 
        printf(" 1:����ͼ�� \n"); 
        printf(" 2:ɾ��ͼ�� \n"); 
        printf(" 3:�޸�ͼ�� \n"); 
        printf(" 4:ͼ��ͳ�� \n"); 
    
        printf(" 5:��Ա����ϵͳ \n"); 
        printf(" 0:���� \n"); 
        printf("������0��5:\n"); 
         ch2=getch(); 
        switch(ch2) 
        { 
         case '1':addbook(); 
         break; 
         case '2':delbook();break; 
         case '3':changebook();break; 
         case '4':bookcount();getch();break; 
        
         case '5':{
            do 
            { system("color 4e");
			system("cls");
            printf("\t\t����ӭ����ѧ������ϵͳ����\n"); 
            printf(" 1: �����¿� \n"); 
            printf(" 2: ɾ������ \n"); 
            printf(" 3: ����ͳ�� \n"); 
            printf(" 4: ����ͳ�� \n"); 
            printf(" 0: ���� \n"); 
            printf("������0��4:\n"); 
             ch4=getch(); 
            switch(ch4) 
             { 
              case '1':addcar();break; 
              case '2':delcar();break; 
              case '3':lendcount();break; 
              case '4':carcount();break; 
              case '0':break; 
              default:printf("�޴˲���!\n");getch();break; 
             } 
            }while(ch4!='0');}break; 
            case '0':break; 
            default:printf("�޴˲���!\n");getch();break; 
           } 
        }
			 while(ch2!='0');}break; 
        case '4':huanbook();break; 
        case '0':break; 
        default:printf("�޴˲���!\n");getch();break; 
   } 
}while(ch1!='0'); 
}
 

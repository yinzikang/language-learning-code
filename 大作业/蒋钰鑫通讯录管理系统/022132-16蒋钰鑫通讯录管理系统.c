

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct persons
{ char name[10];
 char addr[20];
 char phnum[20];
char email[20];
}persons[MAX];

typedef struct p{
 char name[10];
 char addr[20];
char phnum[20];
char email[20];
 struct p *next;
 }p,*linklist;

 linklist head=NULL,t=NULL;
 p  *s,*p0,*p1,*p2,*p3,*p4,*p5;
 int i;
 char name1[10],ch;
 char str1[20 ];
 FILE *fp;

void creat()
{   int j;
long k;
 fp=fopen("ͨѶ¼","r+");
 if(fp!=NULL)
 {for(i=1;i<MAX;i++)
{ j=fgetc(fp);
 if(j==EOF)
 return;
 k=i-1;
 fseek(fp,k*sizeof(struct persons),0);
 fread(&persons[i],sizeof(struct persons),1,fp);
 s=(linklist)malloc(sizeof(p));
 strcpy(s->name,persons[i].name);
 strcpy(s->addr,persons[i].addr);
 strcpy(s->phnum,persons[i].phnum);
strcpy(s->email,persons[i].email);
 if(head==NULL)
 head=s;
 else
 t->next=s;
 t=s;}
}
 else
 { fp=fopen("people.txt","w");  i=1;
     }
}


void Add()
{  s=(linklist)malloc(sizeof(p));
     printf("\n\n\t*********������ĳ�˵���Ϣ:**********");
      printf("\n\n\t\tname:");
 scanf("%s",s->name);
 printf("\n\n\t\tAddr:");
 scanf("%s",s->addr);
 printf("\n\n\t\tphnum:");
 scanf("%s",s->phnum);
printf("\n\n\t\temai:");
 scanf("%s",s->email);
 if(head==NULL)
 head=s;
 else
 t->next=s;
 t=s;
}

void List()
{
 p0=head;


while(p0!=NULL)
   { printf("\tname:%s",p0->name);
     printf("\taddr:%s",p0->addr);
     printf("\tphnum:%s",p0->phnum);
     printf("\temail:%s\n",p0->email);
     p0=p0->next;
    }

 }

void Delete()
{
char name0[10];
p1=head;
printf("\n\t**********������һ���˵�����:**************\n");
printf("\n\t\tname0:");
gets(name0);
scanf("%s",name0);
while((strcmp(name0,p1->name)!=0)&&(p1!=NULL))
{p2=p1;
p1=p1->next;}
if(strcmp(name0,p1->name)==0)
{if(p1==head)head=p1->next;
else p2->next=p1->next;
printf("\n\t**************ɾ���ɹ���******************\n");}
else printf("\n\t**************ɾ��ʧ�ܣ�******************\n");
}


void Find()

{
int n;
char phnum1[20],name1[10];
printf("\n\t*******�����ֻ���סַ����*******����(n=0)\סַ(n=1)*********\n");
printf("*******��������'n':*************\n");

scanf("%d",&n);
if(n==0)
{printf("\n\tname:");
  p3=head;

  gets(name1);
  scanf("%s",&name1);
while((strcmp(name1,p3->name)!=0)&&(p3!=NULL))
p3=p3->next;
      if(p3->name==NULL)
{
  printf("\n\t**************�����ҵ������Ϣ!**********");
}
  else if(strcmp(name1,p3->name)==0)
      {
printf("\n\t *******�ҵ������Ϣ:**********************\n");
        printf("\n\tname: %s",p3->name);
    printf("\taddress:%s",p3->addr);
    printf("\temail: %s",p3->email);
    printf("\tphnum: %s",p3->phnum);
 }
 }
else if(n==1)
    { printf("\n\tphnum1");

     p3=head;
 gets(phnum1);
scanf("%s",&phnum1);
while((strcmp(phnum1,p3->phnum)!=0)&&(p3!=NULL))
p3=p3->next;
  if(p3->phnum==NULL)
     {printf("\n\t************�����ҵ������Ϣ!*********");}
    else if(strcmp(phnum1,p3->phnum)==0)
    {  printf("\n\n\t**********�ҵ������Ϣ:*********");
        printf("\n\tname: %s",p3->name);
    printf("\taddress:%s",p3->addr);
    printf("\temail: %s",p3->email);
    printf("\tphnum: %s",p3->phnum);}
     }
}



void Alter()
{
int m;char phnum2[20],name2[10];
printf("\n\n\t*******��һ����Ϣ������Ҫ�޸ĵ�*******����(m=0)\סַ(m=1)*********\n");
printf("************�������� 'm':***********************\n");
scanf("%d",&m);
if(m==0)
 {printf("\n\tname:");
    scanf("%s",&name2);
         p4=head;
while((strcmp(name2,p4->name)!=0)&&(p4!=NULL))
p4=p4->next;
    if(p4==NULL){printf("\n\t*********�����ҵ��������!**********\n");}
    else if(strcmp(name2,p4->name)==0)
    {  printf("\n\n\t*********��������Ϣ:************\n");
       printf("\n\n\n\t\tname:");
       scanf("%s",&name2);
       strcpy(p4->name,name2);
       printf("\n\n\t************�޸ĳɹ�!************\n");}
       }
else if(m==1)
    { printf("\n\tphnum:");


scanf("%s",&phnum2); p4=head;
while((strcmp(phnum2,p4->phnum)!=0)&&(p4!=NULL))
p4=p4->next;
    if(p4==NULL)
     {printf("\n\t************�����ҵ������ַ!*********\n");}
    else if(strcmp(phnum2,p4->phnum)==0)
    {  printf("\n\n\t**********��������Ϣ:*********\n");
 printf("\n\n\n\t\tphnum:");

    scanf("%s",&phnum2);
       strcpy(p4->phnum,phnum2);
       printf("\n\n\t************�޸ĳɹ�!************\n");}
}
}

void Save()
{ int j;
 fp=fopen("people.txt","w");
 for(p5=head,j=0;p5!=NULL;j++,p5=p5->next)
 {  strcpy(persons[j].name,p5->name);
 strcpy(persons[j].addr,p5->addr);
 strcpy(persons[j].phnum,p5->phnum);
strcpy(persons[j].email,p5->email);
 fwrite(&persons[j],sizeof(struct persons),1,fp);
 }
}


 main()
{ int n;
creat();
 do
    {printf("\n\t***********************************************\n");
    printf("\n\n\t*************��ӭʹ��!***************\n");
    printf("\n\t**********************************************\n");
 printf("\n\n\t\t*****����������ѡ��*****\n");
 printf("\n\t\t1.���һ���˵���Ϣ");
 printf("\n\t\t2.��ʾ�����˵���Ϣ");
 printf("\n\t\t3.ɾ��һ���˵���Ϣ");
 printf("\n\t\t4.����һ���˵���Ϣ");
 
 printf("\n\t\t5.�޸�һ���˵���Ϣ");
 printf("\n\t\t6.���沢�˳�");
 printf("\n\n\n");
 printf("\t********�������ѡ��:********\n");

 scanf("%d",&n);

  switch(n)
       { case 1:  Add();
            break;
      case 2:  List();        
            break;
          case 3:  Delete();
            break;
          case 4:  Find();
            break;
          case 5:  Alter();
            break;
	  case 6:  exit(0);
            break;
          case 7:  creat();
            fclose(fp);
         
    default:
     printf("\n\t********************************************\n"); 
     printf("\n\t             ���ѡ��Ӧ���� 1-6!!!              \n"); 
     printf("\n\t********************************************\n"); 
     break; 
 } 
     }while(1); 
     } 
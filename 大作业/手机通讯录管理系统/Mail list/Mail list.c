#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
struct person
{
 char name[15]; 
 char tel[15]; 
 char kind[5];
 char Email[15];
}msg[15];

void name();
void printf_back();
int load();
void add();
void browse();
void del();
void search() ;
void main();
void menu();

void printf_back()
{
    menu();
    printf("\n\n�ɹ�^_^\n\n");
    getchar();
    menu();
}

int load()     
{
    FILE *fp;
    int i=0,t,k;
    if((fp=fopen("person.txt","r"))==NULL)
	{printf("\n���ܴ򿪴��ļ�\n");
	}
    for(k=0;k<15;k++)
	{t=fscanf(fp,"%s %s %s %s",msg[k].name,msg[k].tel,msg[k].kind,msg[k].Email);
    if(t<4) break;
    i=i+1;
	}
    return(i);
	fclose(fp);
}
void add()
{ 
    int n,j,t,w1,w;
    FILE *fp;
    char name[10],kind[10],Email[20];
    char tel[11];
    if((fp=fopen("person.txt","a"))==NULL)
	{printf("\n���ܴ򿪴��ļ�\n");
	}
	printf("������������˵���Ϣ?");
    scanf("%d",&t);
    n=load();
	for(j=0;j<t;j++)
	{  
	printf("\n\n���:");
    printf("%d",n+1);
	printf("\n\n��������ϵ�˵�����:");
	scanf("%s",name);
    for(w=0;w<n;w++)if(strcmp(msg[w].name,name)==0)
	{printf("\n     ��Ϣ�Ѵ���!");
	fclose(fp);
    getchar();
    printf_back();}
	printf("\n\n��������ϵ�˵ĵ绰:");
	scanf("%s",tel);
	printf("\n\n���������:");
    scanf("%s",kind);
	printf("\n\n��������ϵ�˵ĵ����ʼ�:");
	scanf("%s",Email);
    strcpy(msg[n].name,name);
	strcpy(msg[n].tel,tel);
	strcpy(msg[n].kind,kind);
	strcpy(msg[n].Email,Email);
	fprintf(fp,"%s %s %s %s\n",msg[n].name,msg[n].tel,msg[n].kind,msg[n].Email);
	n=n+1;
	if(n>15) printf("�ռ�����");}
      printf("\n�������������?1).�� 2).�� �ص����˵�:[]\b\b");
scanf("%d",&w1);
if(w1==1)
add();
else 
{fclose(fp);
    getchar();
    printf_back();}
}
void browse()
{   int t=-1;
    int i,n,j,c,w1;
	char name[10];
    FILE *fp;
	n=load();
	printf("\n\n����Ҫ�޸��˵�����:\n");
    scanf("%s",name);
    if((fp=fopen("person.txt","r+"))==NULL)
	{
	printf("\n\n���ܴ�!\n\n");exit(0);
	}
    for(j=0;j<n;j++)
    if(strcmp(name,msg[j].name)==0)
	{t=j;break;}
	if(t==-1) printf("\n\n�����ֲ�����!\n");
	else {for(j=0;j<n;j++)
    if(strcmp(name,msg[j].name)==0)
	{ 
	do
	{
	puts("\n����������=>\n\n  1). ���� 2).�绰: 3).����: 4).�����ʼ�:");
	printf("������ѡ��?:[ ]\b\b  ");
	scanf("%d",&c);
	if(c>4||c<1)
	{
	puts("\nѡ�����!");
	getchar();
	}
	}while(c>8||c<1);break;
	}
    do
	{
    switch(c)
	{
	case 1:printf("����:");scanf("%s",msg[j].name);break;
	case 2:printf("�绰:");scanf("%s",msg[j].tel);break;
    case 3:printf("����:");scanf("%s",msg[j].kind);break;
    case 4:printf("�����ʼ�:");scanf("%s",msg[j].Email);break;
	}
	}while(c<1||c>4);
    printf("\n    �޸ĳɹ�!\n");
	for(i=0;i<n;i++)
    fprintf(fp,"%s %s %s %s\n",msg[i].name,msg[i].tel,msg[i].kind,msg[i].Email);
	}
	  printf("\n��������޸���?1).�� 2).�� �ص����˵�:[]\b\b");
scanf("%d",&w1);
if(w1==1)
browse();
else {fclose(fp);
    getchar();
    printf_back();}
}
void del()     
{   int i,j,n,w1;
    FILE *fp;
    char name[10];
    n=load();
    printf("\n\n����������ɾ�����˵�����:");            
    scanf("%s",name);
    if((fp=fopen("person.txt","r"))==NULL)
	{
    printf("\n\n���ܴ򿪴��ļ���\n\n");
    exit(0);
	}
    for(j=0;j<n;j++) {if(strcmp(msg[j].name,name)==0) {printf("\n    ɾ���ɹ�!\n");break;}} 
    if((fp=fopen("person.txt","w"))==NULL)
	{
    printf("\n\n���ܴ򿪴��ļ���\n\n");
    exit(0);
	}
    for(i=0;i<n;i++) {if(i!=j){
	strcpy(msg[i].name,msg[i].name);
	strcpy(msg[i].tel,msg[i].tel);
	strcpy(msg[n].kind,msg[i].kind);
	strcpy(msg[n].Email,msg[i].Email);
	fprintf(fp,"%s %s %s %s\n",msg[i].name,msg[i].tel,msg[i].kind,msg[i].Email);}}
     printf("\n�������ɾ����?1).�� 2).�� �ص����˵�:[]\b\b");
scanf("%d",&w1);
if(w1==1)
del();
else 
{fclose(fp);
    getchar();
    printf_back();} 
}
void search()
{   FILE *fp;
    int n,j,w1;
    int k=-1;
    char kind[20];
    n=load();
    if((fp=fopen("person.txt","r"))==NULL)
    {
    printf("\n\n���ܴ򿪴��ļ���\n\n");
    }
    printf("\n\n��ѡ������:\n �칫\n ����\n ����\n\n��ѡ�����:");
    scanf("%s",kind);
    for(j=0;j<n;j++)
    {if(strcmp(kind,msg[j].kind)==0)  
	{k=j;
	printf("\n%s  %s  %s  %s\n",msg[j].name,msg[j].tel,msg[j].kind,msg[j].Email);
	}}
    if(k==-1)                      
	{
    printf("\n\n������!");
    }
     printf("\n��������鿴��?1).�� 2).�� �ص����˵�[]:\b\b");
scanf("%d",&w1);
if(w1==1)
search();
else 
{fclose(fp);
    getchar();
    printf_back();}
} 
void name()
{   FILE *fp;
    int t=20,j,n,w1;
    char nme[10]; 
    n=load();
    if((fp=fopen("person.txt","r"))==NULL)
    {
    printf("\n\n���ܴ򿪴��ļ���\n\n");
    }
    printf("��������Ҫ��ѯ���˵�����:");
    scanf("%s",nme);
    for(j=0;j<n;j++)
	if(strcmp(nme,msg[j].name)==0)
	{t=j;
	 printf("\n����  �绰  ����  �����ʼ�\n");
	printf("\n%s  %s  %s  %s\n",msg[j].name,msg[j].tel,msg[j].kind,msg[j].Email);
	}
    if(t==20) printf("���޴���!");
      printf("\n��������鿴��?1).�� 2).�� �ص����˵�:[]\b\b");
scanf("%d",&w1);
if(w1==1)
 name();
else {fclose(fp);
    getchar();
    printf_back();}
}
void menu()
{
   int n,w1;
   do
   {
    puts("\n\t\t**********�˵�**********\n\n");
    puts("\t\t\t1.ɾ��");
    puts("\t\t\t2.�޸�");
    puts("\t\t\t3.�����鿴");
    puts("\t\t\t4.�������鿴");
	puts("\t\t\t5.����");
    puts("\t\t\t6.�˳�");
    puts("\n\n\t\t**********************\n");
    printf("��ѡ������(1-5):[]\b\b");
    scanf("%d",&n);
    if(n<1||n>6)
    {
    w1=1;
	getchar();
    }
    else w1=0;
   }
    while(w1==1);

   switch(n)
   {
   case 1:del();break;
   case 2:browse();break;
   case 3:search();break;
   case 4:name();break;
   case 5:add();break;
   case 6:exit(0);
   }
}

void main()
{
    menu();
}

#include<stdio.h>
struct 
{
char name[8];
char num[10];
char sex[10];
char age[10];
char record[10];
char position[15];
char wanges[10];
char tel[15];
char addr[50];
}one;                                    
                
FILE *fp;               

                               
void output();                              
void search();                              
void append();                              
void modify();                              
void delete();                              
void nameway();
void xueliway();
void numway();
void main()                                 
{
int m;


while(1)
{   printf("\n\n\n\t\t    ______________________________________\n");
	printf("\t\t    ��ӭ�����й����ʴ�ѧ(�人)ְ����Ϣϵͳ\n");
    printf("\t\t    ����ߣ����� ѧ��20131004385\n");
	printf("\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
	printf("\n\t\t\t\t��ӣ��밴1");
    printf("\n\t\t\t\t���ң��밴2");
    printf("\n\t\t\t\t�޸ģ��밴3");
    printf("\n\t\t\t\tɾ�����밴4");
    printf("\n\t\t\t\t������밴5");

printf("\n\t\t\t\t�˳����밴0\n");                  
scanf("%d",&m);
if(m>=0&&m<=5)
{
switch(m)
{
case 1: append();
break;
case 2: search();
break;
case 3: modify();
break;
case 4: delete();
break;
case 5: output();
break;

case 0: exit();
}
printf("\n\n������ϣ����ٴ�ѡ��");
}
else
printf("\n\nѡ��������ٴ�ѡ��");
}
}

void output()                            
{
if((fp=fopen("worker.xls","r"))==NULL)       
{
printf("\n���ܴ򿪸��ļ���");
exit();
}
printf("\n\n%20s\n","ְ����Ϣ����ϵͳ");
while(!feof(fp))
{
fscanf(fp,"%s%s%s%s%s%s%s%s%s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
printf("%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
}
fclose(fp);
}

void append()                          
{
if((fp=fopen("worker.xls","a"))==NULL)     
{
printf("\n���ܴ򿪸��ļ���");
exit();
}
printf("\n���������ְ����Ϣ(������ְ���š��Ա����䡢ѧ����ְλ�����ʡ��绰����ַ)\n");
scanf("%s%s%s%s%s%s%s%s%s",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
fprintf(fp,"%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
fclose(fp);                      
}


void search()                    
{
	int l;
printf("\t\t\t\t���������Ұ�:1��\n");
printf("\t\t\t\t��ѧ�����Ұ�:2��\n");
printf("\t\t\t\t��ְ���Ų鰴:3��\n");

 scanf("%d",&l);
if(l>0&&l<4)
{switch(l)
{
case 1:nameway();
break;
case 2:xueliway();
break;
case 3:numway();
break;
}
  printf("\n\n�������!!!");
}
else printf("\t\t\t\t��������!!!");
}

void nameway()
{
int k=0;
char nam[8];
printf("\n��������Ҫ���ҵ�ְ������:");
scanf("%s",nam);

if((fp=fopen("worker.xls","rb"))==NULL)        
{
printf("\n���ܴ��ļ���");
exit();
}
while(!feof(fp))
{
fscanf(fp,"%s%s%s%s%s%s%s%s%s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
if(strcmp(nam,one.name)==0)
{
printf("\n\n�Ѳ鵽����¼Ϊ��");
printf("\n%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
k=1;
}
}
if(k==0)
printf("\n\n�Բ��𣬲��޴��ˣ���");
fclose(fp);
}

void xueliway()
{int j=0;
char xueli[10];
printf("\t\t\t\t������Ҫ��ѯ��ѧ��\n");
scanf("%s",xueli);
if((fp=fopen("worker.xls","rb"))==NULL)        
{
printf("\n���ܴ��ļ���");
exit();
}
while(!feof(fp))
{
fscanf(fp,"%s%s%s%s%s%s%s%s%s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
if(strcmp(xueli,one.record)==0)
{
printf("\n\n�Ѳ鵽����¼Ϊ��");
printf("\n%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
j=1;
}
}
if(j==0)
printf("\n\n�Բ��𣬲��޴��ˣ���");
fclose(fp);
}

void numway()
{
	int i=0;
	char numb[10];
printf("\t\t\t\t������Ҫ��ѯ�Ĺ���\n");
scanf("%s",numb);
if((fp=fopen("worker.xls","rb"))==NULL)        
{
printf("\n���ܴ��ļ���");
exit();
}
while(!feof(fp))
{
fscanf(fp,"%s%s%s%s%s%s%s%s%s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
if(!strcmp(numb,one.num))
{
printf("\n\n�Ѳ鵽����¼Ϊ��");
printf("\n%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
i=1;
}
}
if(!i)
printf("\n\n�Բ��𣬲��޴��ˣ���");
fclose(fp);
}

void modify()                          
{
int m,k=0;
long a;
char namekey[8];
printf("\n��������Ҫ�޸ĵ�ְ��������:");
scanf("%s",namekey);

if((fp=fopen("worker.xls","r+"))==NULL)      
{
printf("\n���ܴ򿪸��ļ���");
exit();
}
while(!feof(fp))
{
a=ftell(fp);                     
fscanf(fp,"%s%s%s%s%s%s%s%s%s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
if(!strcmp(namekey,one.name))
{
k=1;
break;
}
}
if(k)
{
printf("\n�Ѳ鵽����¼Ϊ��");
printf("\n%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
printf("\n��������Ϣ(����������ְ���š��Ա����䡢ѧ����ְλ�����ʡ��绰����ַ��˳������)��");
scanf("%s%s%s%s%s%s%s%s%s",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
fseek(fp,a,0);
fprintf(fp,"%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
}
else
printf("\n�Բ��𣬲��޴���,�޷������޸ġ�");
fclose(fp);                            
}

void delete()                          
{
int m,k=0;
long a,b;
char namekey[8], valid[4];
printf("\n��������Ҫɾ����ְ������:");
scanf("%s",namekey);
if((fp=fopen("worker.xls","r+"))==NULL)     
{
printf("\n���ܴ򿪸��ļ���");
exit();
}
while(!feof(fp))
{
a=ftell(fp);               
fscanf(fp,"%s%s%s%s%s%s%s%s%s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
if(strcmp(namekey,one.name)==0)
{
k=1;
break;
}
}
if(k==1)
{
printf("\n�Ѳ鵽����¼Ϊ");
printf("\n%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
printf("\nȷʵҪɾ��,��1����ɾ������0��");
scanf("%d",&m);
if(m==1)
{
fseek(fp,a,0);
fprintf(fp,"%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n" "","","","","","","","","");
}
}
else
printf("\n�Բ��𣬲��޴��ˡ�");
fclose(fp);       
                
}


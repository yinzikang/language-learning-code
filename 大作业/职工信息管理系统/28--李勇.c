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
	printf("\t\t    欢迎进入中国地质大学(武汉)职工信息系统\n");
    printf("\t\t    设计者：李勇 学号20131004385\n");
	printf("\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"); 
	printf("\n\t\t\t\t添加，请按1");
    printf("\n\t\t\t\t查找，请按2");
    printf("\n\t\t\t\t修改，请按3");
    printf("\n\t\t\t\t删除，请按4");
    printf("\n\t\t\t\t输出，请按5");

printf("\n\t\t\t\t退出，请按0\n");                  
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
printf("\n\n操作完毕，请再次选择！");
}
else
printf("\n\n选择错误，请再次选择！");
}
}

void output()                            
{
if((fp=fopen("worker.xls","r"))==NULL)       
{
printf("\n不能打开该文件！");
exit();
}
printf("\n\n%20s\n","职工信息管理系统");
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
printf("\n不能打开该文件！");
exit();
}
printf("\n请输入添加职工信息(姓名、职工号、性别、年龄、学历、职位、工资、电话、地址)\n");
scanf("%s%s%s%s%s%s%s%s%s",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
fprintf(fp,"%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
fclose(fp);                      
}


void search()                    
{
	int l;
printf("\t\t\t\t＊姓名查找按:1＊\n");
printf("\t\t\t\t＊学历查找按:2＊\n");
printf("\t\t\t\t＊职工号查按:3＊\n");

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
  printf("\n\n操作完毕!!!");
}
else printf("\t\t\t\t输入有误!!!");
}

void nameway()
{
int k=0;
char nam[8];
printf("\n请输入您要查找的职工姓名:");
scanf("%s",nam);

if((fp=fopen("worker.xls","rb"))==NULL)        
{
printf("\n不能打开文件！");
exit();
}
while(!feof(fp))
{
fscanf(fp,"%s%s%s%s%s%s%s%s%s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
if(strcmp(nam,one.name)==0)
{
printf("\n\n已查到，记录为：");
printf("\n%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
k=1;
}
}
if(k==0)
printf("\n\n对不起，查无此人！。");
fclose(fp);
}

void xueliway()
{int j=0;
char xueli[10];
printf("\t\t\t\t输入你要查询的学历\n");
scanf("%s",xueli);
if((fp=fopen("worker.xls","rb"))==NULL)        
{
printf("\n不能打开文件！");
exit();
}
while(!feof(fp))
{
fscanf(fp,"%s%s%s%s%s%s%s%s%s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
if(strcmp(xueli,one.record)==0)
{
printf("\n\n已查到，记录为：");
printf("\n%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
j=1;
}
}
if(j==0)
printf("\n\n对不起，查无此人！。");
fclose(fp);
}

void numway()
{
	int i=0;
	char numb[10];
printf("\t\t\t\t输入你要查询的共号\n");
scanf("%s",numb);
if((fp=fopen("worker.xls","rb"))==NULL)        
{
printf("\n不能打开文件！");
exit();
}
while(!feof(fp))
{
fscanf(fp,"%s%s%s%s%s%s%s%s%s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
if(!strcmp(numb,one.num))
{
printf("\n\n已查到，记录为：");
printf("\n%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
i=1;
}
}
if(!i)
printf("\n\n对不起，查无此人！。");
fclose(fp);
}

void modify()                          
{
int m,k=0;
long a;
char namekey[8];
printf("\n请输入您要修改的职工的姓名:");
scanf("%s",namekey);

if((fp=fopen("worker.xls","r+"))==NULL)      
{
printf("\n不能打开该文件！");
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
printf("\n已查到，记录为：");
printf("\n%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
printf("\n请输入信息(按照姓名、职工号、性别、年龄、学历、职位、工资、电话、地址的顺序输入)：");
scanf("%s%s%s%s%s%s%s%s%s",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
fseek(fp,a,0);
fprintf(fp,"%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
}
else
printf("\n对不起，查无此人,无法进行修改。");
fclose(fp);                            
}

void delete()                          
{
int m,k=0;
long a,b;
char namekey[8], valid[4];
printf("\n请输入您要删除的职工姓名:");
scanf("%s",namekey);
if((fp=fopen("worker.xls","r+"))==NULL)     
{
printf("\n不能打开该文件！");
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
printf("\n已查到，记录为");
printf("\n%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
printf("\n确实要删除,按1；不删除，按0：");
scanf("%d",&m);
if(m==1)
{
fseek(fp,a,0);
fprintf(fp,"%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n" "","","","","","","","","");
}
}
else
printf("\n对不起，查无此人。");
fclose(fp);       
                
}


#define N 100
#include<stdio.h>
 struct worker
   {
   char num[11];
   char name[10];
   char sex[2];
   char age[3];
   char zhiwu[15];
   char zhicheng[15];
   char zhengzhi[15];
   char xueli[15];
   char renzhisj[8];
   char laiyansj[8];
   char leibie[15];
  }wk[N],s,h;


 menu()       
{
int n,w1;
do
{
printf("\n\t\t\t菜单\n");
printf("\t\t0\t新建数据\n\n");
printf("\t\t1\t删除人员\n\n");
printf("\t\t2\t添加人员\n\n");
printf("\t\t3\t通过编号查找\n\n");
printf("\t\t4\t通过姓名查找\n\n");
printf("\t\t5\t浏览全部\n\n");
printf("\t\t6\t修改数据\n\n");
printf("\t\t7\t排序\n\n");
printf("\t\t8\t统计\n\n");
printf("\t\t9\t退出\n\n");
printf("\t请选择并输入一个数字 ");
scanf("%d",&n);
if(n<0||n>8)
{
  w1=1;
  getchar();
}
  else w1=0;
}
while(w1==1);
switch(n)
{
case 0:build();break;
case 1:del();break;
case 2:add();break;
case 3:snum();break;
case 4:sname();break;
case 5:browse();break;
case 6:modify();break;
case 7:order();break;
case 8:data();break;
case 9:exit(0);
default:{printf("输入错误!!请输入一个属于0~8的数字");menu();}
}
}



build()       
{int i,m,k,p;
FILE *fp;
if((fp=fopen("worker00.txt","w"))==NULL)
{printf("can not build file\n");
printf_back();}
printf("你想添加多少工作人员(0-%d)?:",N);
scanf("%d",&m);
k=m;
for(i=0;i<k;i++)
{printf("\n输入地 %d个\n",i+1);
input(i);
}

for(p=0;p<=i;p++)
if((fprintf(fp,"%s\t%s\t%1s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",wk[p].num,wk[p].name,wk[p].sex,wk[p].age,wk[p].zhiwu,wk[p]. zhicheng,wk[p].zhengzhi,wk[p].xueli,wk[p].renzhisj,wk[p].laiyansj,wk[p].leibie))!=1)
printf("无法写入\n\n");
fclose(fp);
printf_back();
}


 add()                       
{int i,m,n,k,p;
FILE *fp;
n=load();
if(n==-1)
menu();
printf("你想添加多少人员(0-%d)?:",N-n);
scanf("%d",&m);
k=m+n;
for(i=n+1;i<=k;i++)
{printf("\n输入第%d个\n",i-n+1);
input(i);
}
if((fp=fopen("worker00.txt","a+"))==NULL)
{printf("无法打开文件\n");
	  printf_back();}
for(p=0;p<k;p++)
fprintf(fp,"%s\t%s\t%1s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",wk[p].num,wk[p].name,wk[p].sex,wk[p].age,wk[p].zhiwu,wk[p]. zhicheng,wk[p].zhengzhi,wk[p].xueli,wk[p].renzhisj,wk[p].laiyansj,wk[p].leibie);
fclose(fp);
printf_back();
}

input(int i)                            
{
input_num(i,i-1);
printf("\n请输入名字:\t");
scanf("%s",wk[i].name);

printf("\n请输入年龄:\t");
scanf("%s",wk[i].age);

printf("\n请输入性别[M为男，W为女，请大写]:\t");
scanf("%1s",wk[i].sex);

printf("\n请输入职务:\t");
scanf("%s",wk[i].zhiwu);

printf("\n请输入职称:\t");
scanf("%s",wk[i].zhicheng);

printf("\n请输入政治面貌:\t");
scanf("%s",wk[i].zhengzhi);

printf("\n请输入学历:\t");
scanf("%s",wk[i].xueli);

printf("\n请输入任职时间:\t");
scanf("%s",wk[i].renzhisj);

printf("\n请输入来院时间:\t");
scanf("%s",wk[i].laiyansj);

printf("\n请输入类别:\t");
scanf("%s",wk[i].leibie);
}

load()                                  
{FILE *fp;
int i;
if((fp=fopen("worker00.txt","r"))==NULL)
{printf("无法打开文件\n");
return NULL;}
else
{for(i=0;!feof(fp);i++)
fscanf(fp,"%s\t%s\t%1s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",wk[i].num,wk[i].name,wk[i].sex,wk[i].age,wk[i].zhiwu,wk[i]. zhicheng,wk[i].zhengzhi,wk[i].xueli,wk[i].renzhisj,wk[i].laiyansj,wk[i].leibie);
return(i-1);}
}



input_num(int i,int n)                     
{
    int j,k,w1;
    do
  {
            w1=0;
          printf("请输入编号:");
          scanf("%s",wk[i].num);
          for(j=0;wk[i].num[j]!='\0';j++)
               {
                      if((wk[i].num[j]<'0')||(wk[i].num[j]>'9'))
                     {printf("输入错误！请输入(0-9).请重新输入\n\n");
                          w1=1;break;
                     }
               }
    if(w1!=1)
      for(k=0;k<n;k++)
                   {
    if(k!=i&&strcmp(wk[k].num,wk[i].num)==0)
                        {
                           printf("记录已删除.请重新输入!\n\n");
                            w1=1;break;
                        }
                   }
   }
     while(w1==1);
}



printf_back()                
{int w;
printf("\n\n\tsuccessful.\n\n");
printf("你想做什么?\n\n\t\t1\t浏览全部\n\n\t\t2\t返回\n\n\t\t");
scanf("%d",&w);
if(w==1)
browse();
else menu();
}



browse()   
{int i,j,n;
 n=load();
 printf_face();
for(i=0;i<=n;i++)
  {
 if((i!=0)&&(i%10==0))
  {printf("\n\n选择并修改No.\n任意键继续...");
getch();
puts("\n\n");
}
  printf_one(i);
}
printf("\t有 %d 条记录.\n",n+1);
printf("任意键继续...");
getch();
menu();
}

printf_face()                        
{
printf("编号\t姓名\t性别\t年龄\t职务\t职称\t政治\t学历\t任职时间\t来院时间\t类别\n");
}


printf_one(int i)                        
{
printf("%s\t%s\t%1s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",wk[i].num,wk[i].name,wk[i].sex,wk[i].age,wk[i].zhiwu,wk[i].zhicheng,wk[i].zhengzhi,wk[i].xueli,wk[i].renzhisj,wk[i].laiyansj,wk[i].leibie);
}


save(int n)    
{
FILE *fp;
int i;
if((fp=fopen("worker00.txt","w+"))==NULL)
{printf("\n\t\t无法打开文件\n");
return NULL;}
for(i=0;i<n;i++);
   if(wk[i].num!=0)
 if(fprintf(fp,"%s\t%s\t%1s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",wk[i].num,wk[i].name,wk[i].sex,wk[i].age,wk[i].zhiwu,wk[i]. zhicheng,wk[i].zhengzhi,wk[i].xueli,wk[i].renzhisj,wk[i].laiyansj,wk[i].leibie)!=1)
printf("\n文件写入错误\n");
fclose(fp);
}

modify()          
{
int i,n,k,p,w0=1,w1,w2=0;
FILE *fp;
n=load();
do
{k=-1;
printf_face();
for(i=0;i<=n;i++)
  {
 if((i!=0)&&(i%10==0))
  {printf("\n\n请输入要修改的编号No.\n任意键继续...");
getch();
puts("\n\n");
}
  printf_one(i);
}
do
{
printf("\n\n输入要修改的编号NO.\n\t\tNO.");
scanf("%s",s.num);
for(i=0;i<n;i++)
  if(strcmp(s.num,wk[i].num)==0);
  {k=i;
   s=wk[i];
  }
if(k==-1)
   printf("\n\n无记录，请继续");
}
  while(k==-1);
printf_face();
printf_one(k);
w1=modify_data(k);
   if(w1==1)
           {printf("\nsuccessful!!\n\n你想修改其他吗?\n\n\t\t1\t是\n\n\t\t2\t不并保存\n\t");
           scanf("%d",&w0);
           w2=1;
   }
    else
           {w0=0;
               if(w2==1)
	   wk[k]=s;}
	   wk[k]=s;
               if(w0!=1&&w2==1)
 {  fp=fopen("worker00.txt","w");
    {for(p=0;p<=n;p++)
     fprintf(fp,"%s\t%s\t%1s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",wk[p].num,wk[p].name,wk[p].sex,wk[p].age,wk[p].zhiwu,wk[p]. zhicheng,wk[p].zhengzhi,wk[p].xueli,wk[p].renzhisj,wk[p].laiyansj,wk[p].leibie);}
     fclose(fp);}
   }
while(w0==1);
menu();
}

modify_data(int i)     
{int c,w1;
do
{printf("\nmodify by =>\n\n\t\t1\tNO.\n\t\t2\t姓名\n\t\t3\t性别\n\t\t4\t年龄\n\t\t5\t职务\n\t\t6\t职称\n\t\t7\t政治面貌\n\t\t8\t学历\n\t\t9\t任职时间\n\t\t10\t来院时间\n\t\t11\t人员类别\n\n\t\t\t");
scanf("%d",&c);
if(c>11||c<1)
printf("选择错误，请重新选择");
getchar();
}
while(c>11||c<1);
do
{switch(c)
{case 1:printf("旧编号是 %s,",wk[i].num);input_num(i,i-1);break;
case 2:printf("旧名字是 %s,输入新名字:",wk[i].name);scanf("%s",wk[i].name);break;
case 3:printf("旧性别是%s,输入新性别:",wk[i].sex);scanf("%1s",wk[i].sex);break;
case 4:printf("旧年龄是 %s,输入新年龄:",wk[i].age);scanf("%s",wk[i].age);break;
case 5:printf("旧职务是 %s,输入新职务:",wk[i].zhiwu);scanf("%s",wk[i].zhiwu);break;
case 6:printf("旧职称是 %s,输入新职称:",wk[i].zhicheng);scanf("%s",wk[i].zhicheng);break;
case 7:printf("旧政治面貌是 %s,输入新政治面貌:",wk[i].zhengzhi);scanf("%s",wk[i].zhengzhi);break;
case 8:printf("旧学历是 %s,输入新学历:",wk[i].xueli);scanf("%s",wk[i].xueli);break;
case 9:printf("旧任职时间是 %s,输入新任职时间:",wk[i].renzhisj);scanf("%s",wk[i].renzhisj);break;
case 10:printf("旧来院时间是 %s,输入新来院时间:",wk[i].laiyansj);scanf("%s",wk[i].laiyansj);break;
case 11:printf("旧类别是 %s,输入新类别:",wk[i].leibie);scanf("%s",wk[i].leibie);break;
}
printf("now:\n\n");
printf_face();
printf_one(i);
printf("\n确定?\n\n\t\t1\t确定\n\t\t2\t不，重新修改\n\t\t3\t返回不修改\n\t\t\t");
scanf("%d",&w1);
}
while(w1==2);
return(w1);
}


sname()                         
{
int i,n,k,p,w1=1,w2,w3,w4;
n=load();
do
                     {do
      {  k=-1;
   printf("\n\n输入你想搜索的名字!\n\t\t");
  scanf("%s",s.name);
for(i=0;i<n;i++)
if(strcmp(s.name,wk[i].name)==0)
         {  k=i;
  printf_one(k);break;
         }
if(k==-1)
              {
printf("\n\n无记录请继续");
printf("\n\n继续?\n\t\t1\t继续\n\t\t2\t返回菜单\n\t\t");
scanf("%d",&w1);
if(w1==1)
{sname();break;}
if(w1==2) {menu();break;}
              }
      }
    while(k==-1&&w1==1);
w4=0;w3=0;
if(k!=-1);
  printf("\n\n你要做什么?\n\t\t1\t搜索其他\n\t\t2\t修改\n\t\t3\t删除\n\t\t4\t返回菜单\n\t\t[  ]\b\b");
  scanf("%d",&w2);
 switch(w2)
   {
case 1:sname();break;
case 2:w3=modify_data(k);break;
case 3:{printf("\n确定?\n\t\t1\t是\n\t\t2\t否并返回\n\t\t");
    scanf("%d",&w4);
     if(w4==1)
    for(p=i;p<n;p++)
   wk[p]=wk[p+1];
    break;}
case 4:menu();break;
   }
if(w3==1||w4==1)
      {save(n);
printf("\n\n\t\t成功!!\n");
printf("\n\n你要做什么??\n\t\t1\t搜索其他\n\t\t2\t返回\n\t\t");
scanf("%d",&w2);
      }
                      }
while(w2==1);
menu();
}

snum()                         
{FILE *fp;
int i,n,k,p,w1=1,w2,w3,w4;
n=load();
do
                     {do
      {  k=-1;
   printf("\n\n输入你想要搜索的号码\n\t\t");
  scanf("%s",s.num);
for(i=0;i<=n;i++)
if(strcmp(s.num,wk[i].num)==0)
         {  k=i;
  printf_one(k);break;
         }
if(k==-1)
              {
printf("\n\nNO exist!please");
printf("\n\n继续?\n\t\t1\t继续\n\t\t2\t不并返回菜单\n\t\t");
scanf("%d",&w1);
if(w1==1)
{snum();
break;}
if(w1==2) menu();break;
              }
      }
    while(k==-1&&w1==1);
w4=0;w3=0;
if(k!=-1);
  printf("\n\n你想做什么?\n\t\t1\t搜索其他\n\t\t2\t修改\n\t\t3\t删除\n\t\t4\t返回菜单\n\t\t");
  scanf("%d",&w2);
 switch(w2)
   {
case 1:snum();break;
case 2:w3=modify_data(k);break;
case 3:{printf("\n确定?\n\t\t1\t确定\n\t\t2\t不并返回\n\t\t");
    scanf("%d",&w4);
     if(w4==1)
    for(p=i;p<=n;p++)
   wk[p]=wk[p+1];
    break;}
case 4:menu();break;
   }
if(w3==1||w4==1)
      {fp=fopen("worker00.txt","w");
for(p=0;p<=n;p++)
     fprintf(fp,"%s\t%s\t%1s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",wk[p].num,wk[p].name,wk[p].sex,wk[p].age,wk[p].zhiwu,wk[p]. zhicheng,wk[p].zhengzhi,wk[p].xueli,wk[p].renzhisj,wk[p].laiyansj,wk[p].leibie);
     fclose(fp);}
printf("\n\n\t\t成功!!\n");
printf("\n\n你想要做什么?\n\t\t1\t搜索其他\n\t\t2\t返回\n\t\t");
scanf("%d",&w2);
      }

while(w2==1);
menu();
}


order() 
{
int i,j,k,n,p,m;
FILE *fp;
n=load();
printf("你想如何排序w?\n\t\t1\t年龄\n\t\t2\t来院时间\n\n");
scanf("%d",&p);
if(p==1)
     {for(i=0;i<=n-1;i++)
		{for(j=i+1;j<=n;j++)
           {if(strcmp(wk[i].age,wk[j].age)<0)
              {s=wk[i];
              wk[i]=wk[j];
               wk[j]=s;
              }
           }
        }
     }
if(p==2)
    {for(i=0;i<=n-1;i++)
	   {for(j=i+1;j<=n;j++)
          {if(strcmp(wk[i].laiyansj,wk[j].laiyansj)<0)
             {s=wk[i];
              wk[i]=wk[j];
			  wk[j]=s;
              }
           }
        }
     }
{fp=fopen("worker00.txt","w+");
for(m=0;m<=n;m++)
   {if(fprintf(fp,"%s\t%s\t%1s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",wk[m].num,wk[m].name,wk[m].sex,wk[m].age,wk[m].zhiwu,wk[m]. zhicheng,wk[m].zhengzhi,wk[m].xueli,wk[m].renzhisj,wk[m].laiyansj,wk[m].leibie)==NULL)
{printf("无法打开文件,请按任意键继续......");getchar();menu();}
}
     fclose(fp);}
printf("\n\n");
printf_back();
}


del()
{
char c;
int i,j,n,k,m,w0=1,w1=0,w2=0;
FILE *fpt;
n=load();
do
{k=-1;
printf_face();
for(i=0;i<=n;i++)
  {
 if((i!=0)&&(i%10==0))
  {printf("\n\n请输入你要删除的编号NO.\n任意键继续...");
getch();
printf("\n\n");
}
  printf_one(i);
}
do
    {
printf("\n\n请输入你要删除的编号NO.!\n\t\tNO.");
scanf("%s",s.num);
for(i=0;i<=n;i++)
  if(strcmp(s.num,wk[i].num)==0);
        {k=i;
          s=wk[i];
        }
if(k==-1)
   printf("\n\n已删除，请继续");
    }
  while(k==-1);
printf_face();
printf_one(k);
printf("是否删除（y是/n否） \t");
	scanf("%1s",&c);
	  if(c=='y')
         {
           for(j=i;j<=n;j++)
           wk[j]=wk[j+1];
           w1=1;
          }
      else menu();
    if(w1==1)
           {printf("\n成功!!\n\n你想删除其他吗?\n\n\t\t1\t是\n\n\t\t2\t不并保存\n\t");
           scanf("%d",&w0);
           w2=1;
           }

               if(w0!=1&&w2==1)
        {fpt=fopen("worker00.txt","w");
     for(m=0;m<n;m++)
fprintf(fpt,"%s\t%s\t%1s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",wk[m].num,wk[m].name,wk[m].sex,wk[m].age,wk[m].zhiwu,wk[m]. zhicheng,wk[m].zhengzhi,wk[m].xueli,wk[m].renzhisj,wk[m].laiyansj,wk[m].leibie);
fclose(fpt);
}
    }
       while(w0==1);
menu();
}


data()
{int p;
printf("what kind do you want to data?\n\t\t1\t在职人数\n\t\t2\t在党人数\n\t\t3\t女职工人数\n\t\t4\t高学历人数\n\t\t5\t退出\n\n\t\t");
scanf("%d",&p);

   switch(p)
                {
case 1:numduty();break;
case 2:numpm();break;
case 3:numwm();break;
case 4:hiedcation();break;
case 5:menu();break;
dafault:printf("数字必须在1和4之间,请重新选择!"); data();
                }
}

numduty()
{int i,j,p,k=0;
int n;
n=load();
for(i=0;i<=n;i++)
if(strcmp(wk[i].leibie,"zaizhi")==0)
{
printf_one(i);k++;}
printf("在职人数 %d",k);
}


numpm()
{int i,j,p,k=0;
int n;
n=load();
for(i=0;i<=n;i++)
if(strcmp(wk[i].zhengzhi,"dangyuan")==0)
{k++;
printf_one(i);}
printf("党员人数 %d",k);
}



numwm()
{int i,j,p,k=0;
int n;
n=load();
for(i=0;i<=n;i++)
if(strcmp(wk[i].sex,'w')==0)
{k++;
printf_one(i);}
printf("女职工人数 %d",k);
}

hiedcation()
{int i,p,k=0;
int n;
n=load();
for(i=0;i<=n;i++)
if(strcmp(wk[i].xueli,"xueshi")==0||strcmp(wk[i].xueli,"professor")==0||strcmp(wk[i].xueli,"shuoshi")==0||strcmp(wk[i].xueli,"benke")==0)
{k++;
printf_one(i);}
printf("高学历人数 is %d",k);
}




main() {menu();}

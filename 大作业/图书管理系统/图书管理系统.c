#include<stdio.h> 
#include<string.h> 
#include<conio.h> 
#include<stdlib.h> 
#include<ctype.h> 
#define STACK_INIT_SIZE 10 
#define OK 1 
#define TRUE 1 
#define ERROR 0

/*定义学生类型，用于存放借出的书籍*/ 
struct student { 
int carnum; 
char lendbook[10]; 
}student[1000];

 /*定义书的类型*/ 
struct book
{ 
int booknum; 
char bookname[20]; 
float bookprice;
char bookcreat[20]; 
int turefalse; /*用于借书和还书模块判断一本书是否借出的条件*/ 
}book[1000];

/*借书卡的数据类型*/ 
struct car 
{ 
int carnum; 
char sex[5];
char studentname[20]; 
int studentclass; 
}car[1000];
//////////////////////////////////查询图书信息模块//////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//////(1)按书名查找
findbook()
{ 
FILE *fp; 
char bookname[10]; 
int i; 
fp=fopen("book.txt","r"); 
printf("请输入你要查找的书名:\n"); 
scanf("%s",bookname); 
for(i=0;fread(&book[i],sizeof(struct book),1,fp)!=0;i++) 
{ 
   if(strcmp(bookname,book[i].bookname)==0) 
   { 
    if(book[i].turefalse==1) 
     
    {
	printf(" 书号      书名      作者 \n %d      %s     %s \n",book[i].booknum,book[i].bookname,book[i].bookcreat);
	printf("此书现在无人借阅\n按任意键返回\n"); } 
    else {printf("这本书已经有人借出\n");fclose(fp);return 0;} 
    fclose(fp); 
    return 0; 
   } 
} 
printf("没有你要查询的书籍!\n"); 
fclose(fp); 
return 0; 
}
//////////(2)按作者查找
findbook1()
{ 
FILE *fp; 
char bookcreat[10]; 
int i; 
fp=fopen("book.txt","r"); 
printf("请输入你要查找的作者名:\n"); 
scanf("%s",bookcreat); 
for(i=0;fread(&book[i],sizeof(struct book),1,fp)!=0;i++) 
{ 
   if(strcmp(bookcreat,book[i].bookcreat)==0) 
   { 
    if(book[i].turefalse==1) 
    { 
     printf(" 书号  书名  作者 \n %d    %s    %s \n",book[i].booknum,book[i].bookname,book[i].bookcreat); 
    printf("此书现在无人借阅\n按任意键返回\n");
	} 
    else {printf("这本书已经有人借出!\n");
	fclose(fp);
	return 0;
	} 
    fclose(fp); 
    return 0; 
   } 
} 
printf("没有你要查询的书籍\n"); 
fclose(fp); 
return 0; 
}
chabook()/////查找图书主模块 
{ 
char ch5; 
do 
{ 
printf("◎◎◎欢迎进入图书查询系统◎◎◎\n"); 
printf(" 1: 按书名查找 \n"); 
printf(" 2: 按作者查找 \n"); 
printf(" 0: 返回 \n"); 
printf("请输入0━2:\n"); 
ch5=getch(); 
switch(ch5) 
   { 
    case '1':findbook();getch();break; 
    case '2':findbook1();getch();break; 
    case '0':break; 
    default:printf("无此操作!\n");getch();break; 
   } 
}while(ch5!='0');
return 0; 
}
/////////////////////////////////////////////////////////////////
//////////借书与还书模块
/////(1).借书模块
lendbook() 
{ 
FILE *fp,*fp2; 
int i,n; 
int carnum; 
system("cls");
printf("\t\t◎◎◎欢迎进入借书系统◎◎◎\n\n");
printf("请输入借书人的:\n卡号:\n"); 
scanf("%d",&carnum); 
fp=fopen("car.txt","r"); 
for(i=0;fread(&car[i],sizeof(struct car),1,fp)!=0;i++) 
{ 
   if(car[i].carnum==carnum) 
   { 
    n=i; 
    fclose(fp); 
    printf("书名:\n"); 
    scanf("%s",student[n].lendbook); 
    fp=fopen("book.txt","r"); 
    for(i=0;fread(&book[i],sizeof(struct book),1,fp)!=0;i++) 
    { 
     if(strcmp(book[i].bookname,student[n].lendbook)==0) 
     { 
      if(book[i].turefalse==0) {printf("对不起，此书有人借出，请借其他书\n");fclose(fp);getch();return 0;} 
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
      printf("借书完毕，按任意键返回...\n"); 
      getch(); 
      return 0; 
     } 
    } 
    printf("不存在这样的书，任意键返回...\n"); 
    fclose(fp); 
    getch(); 
    return 0; 
   } 
} 
printf("你的卡号不存在，请申请新卡,按任意键返回...\n"); 
fclose(fp); 
getch(); 
return 0;}
///////(2).还书函数
huanbook() 
{ 
FILE *fp,*fp2; /*定义两个文件指针，fp2用于修改数据时设立临时文件用，防止数据遭破坏*/ 
int i,n; 
int carnum; 
char lendbook[10]; 
system("cls");
printf("\t\t◎◎◎欢迎进入还书界面◎◎◎");
printf("\n请你输入你的\n卡号:\n"); 
scanf("%d",&carnum); 
fp=fopen("car.txt","r"); /*读取卡号记录*/ 
for(i=0;fread(&car[i],sizeof(struct car),1,fp)!=0;i++) /*for循环判断卡号是否存在*/ 
{ 
   if(car[i].carnum==carnum) /*卡号存在，进入下一循环*/ 
   { 
    n=i; 
    fclose(fp); 
    printf("请输入你要还的书的名字:\n"); 
    scanf("%s",lendbook); 
    fp=fopen("record.txt","r"); 
    for(i=0;fread(&student[i],sizeof(struct student),1,fp)!=0;i++) /*判断是否借阅了输入的书*/ 
    { 
     if(strcmp(student[i].lendbook,lendbook)==0) /*借阅了该书，进入下一循环，否则出错显示*/ 
     { 
      fclose(fp); 
      fp=fopen("record.txt","r"); 
      fp2=fopen("bookl.txt","w"); 
      for(i=0;fread(&student[i],sizeof(struct student),1,fp)!=0;i++) 
      { 
       if(strcmp(student[i].lendbook,lendbook)==0) 
       { 
        continue; /*删除还掉的书的借书记录*/ 
       } 
       fwrite(&student[i],sizeof(struct student),1,fp2); /*写入原来没还的书的记录*/ 
      } 
      fclose(fp); 
      fclose(fp2); 
      fp=fopen("record.txt","w"); 
      fp2=fopen("bookl.txt","r"); 
      for(i=0;fread(&student[i],sizeof(struct student),1,fp2)!=0;i++) 
       { 
        fwrite(&student[i],sizeof(struct student),1,fp); /*将借书记录信息写回*/ 
       } 
      fclose(fp); 
      fclose(fp2); 
      fopen("bookl.txt","w"); /*清临时文件的记录*/ 
      fclose(fp2); 
      fp=fopen("book.txt","r"); 
      fp2=fopen("bookl.txt","w"); 
      for(i=0;fread(&book[i],sizeof(struct book),1,fp)!=0;i++) /*将书的记录写入临时文件，防止因为修改信息破坏以前的记录*/ 
      { 
       if(i==n) 
       { 
        book[i].turefalse=1; 
        fwrite(&book[i],sizeof(struct book),1,fp2); /*将还的书的原来状态设为无人借阅的*/ 
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
       fwrite(&book[i],sizeof(struct book),1,fp); /*将临时文件写回*/ 
      } 
      fclose(fp); 
      fclose(fp2); 
      fopen("bookl.txt","w"); /*清临时文件*/ 
      fclose(fp2); 
      printf("还书完毕，按任意键返回...\n"); 
      getch(); 
      return 1; 
     } 
    } 
    printf("你没有借这样的书，任意键返回...\n"); /*出错提示*/ 
    fclose(fp); 
    getch(); 
    return 0; 
   } 
} 
printf("没这样的卡，和管理员联系,按任意键返回...\n"); /*出错提示*/ 
fclose(fp); 
getch(); 
return 0;}
////////(3).借书统计
lendcount() 
{ 
FILE *fp; 
int i,n=0; 
fp=fopen("record.txt","r"); 
if((fp=fopen("record.txt","r"))==0)
{printf("文件中没有数据!\n");
printf("按任意键返回...\n"); 
getch();
return(0);
}
for(i=0;fread(&student[i],sizeof(struct student),1,fp)!=0;i++) 
{ 
   printf("卡号      借出的书籍     \n"); 
   printf("%d       %s \n",student[i].carnum,student[i].lendbook); 
   n=n+1; 
} 
fclose(fp); 
printf("目前共有%d本书借出\n",n); 
printf("按任意键...\n"); 
getch();
return n; 
}
//////////////////////////////////会员卡管理模块/////
//////////(1).增加会员卡
addcar() 
{ 
FILE *fp; 
int i=0; 
fp=fopen("car.txt","a+"); 
printf("卡号:\n"); 
scanf("%d",&car[i].carnum); 
printf("性别:\n");
scanf("%s",car[i].sex);
printf("姓名:\n"); 
scanf("%s",car[i].studentname); 
printf("班级:\n"); 
scanf("%d",&car[i].studentclass); 
fwrite(&car[i],sizeof(struct car),1,fp); 
fclose(fp); 
printf("输入完毕，任意键返回...\n"); 
getch(); 
}
//////////(2).删除会员卡
delcar() 
{ 
FILE *fp,*fp2; 
int i; 
int carnum; 
char choice; 
fp=fopen("car.txt","r"); 
fp2=fopen("bookl.txt","w"); 
printf("要删除的卡号(不存在则不作改动):\n"); 
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
printf("确认删除?(Y/N)!\n"); 
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
   printf("操作超成功!\n按任意键返回...\n"); 
   getch(); 
   return 0; 
} 
else 
{ 
   printf("操作已取消!\n按任意键返回...\n"); 
   getch(); 
   return 0; 
} 
}
//////(3).会员卡统计
carcount() 
{ 
FILE *fp; 
int i,n=0; 
fp=fopen("car.txt","r"); 
for(i=0;fread(&car[i],sizeof(struct car),1,fp)!=0;i++) 
{ 
   printf("第%d张卡 \n",i+1); 
   printf("卡号   性别        姓名  班级   \n"); 
   printf("  %d    %5s    %10s   %3d \n\n",car[i].carnum,car[i].sex,car[i].studentname,car[i].studentclass); 
   n=n+1; 
} 
fclose(fp); 
printf("目前共有%d个会员。\n",n); 
printf("按任意键返回...\n"); 
getch(); 
}
////////////////////////////////////////////////////////
/////////////////图书管理模块///////////////////////////
//////////(1).增加图书信息
addbook() 
{ 
FILE *fp; 
int i=0; 
char choice='y'; 
fp=fopen("book.txt","a+"); 
while(choice=='y'||choice=='Y') 
{ system("color 6e"); 
   printf("书号:\n");
   scanf("%d",&book[i].booknum); 
   printf("书名:\n"); 
   scanf("%s",book[i].bookname); 
   printf("作者:\n"); 
   scanf("%s",book[i].bookcreat); 
   printf("单价:\n");
   scanf("%f",&book[i].bookprice);
   printf("请你设定书的状态(1在架/0不在):\n");  
   scanf("%d",&book[i].turefalse); 
   fwrite(&book[i],sizeof(struct book),1,fp); 
   printf("是否要输入下本书(y/n)\n"); 
   scanf("%s",&choice); 
} 
fclose(fp); 
}
/////////////(2).删除图书信息 
delbook() 
{ 
FILE *fp,*fp2; 
int i; 
char bookname[10],choice; 
fp=fopen("book.txt","r"); 
fp2=fopen("bookl.txt","w"); 
printf("书名:\n"); 
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
printf("确认删除(y/n)?\n"); 
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
   printf("按任意键返回...\n"); 
   getch(); 
   return 0; 
} 
else 
{ 
   printf("按任意键返回...\n"); 
   getch(); 
   return 0; 
} 
}
/////////////(3)修改图书
changebook() 
{ 
FILE *fp,*fp2; 
char bookname[10],choice; 
int i; 
fp=fopen("book.txt","r"); 
fp2=fopen("bookl.txt","w"); 
printf("书名:\n"); 
scanf("%s",bookname); 
for(i=0;fread(&book[i],sizeof(struct book),1,fp)!=0;i++) 
{ 
   if(strcmp(book[i].bookname,bookname)==0) 
   { system("color 5e");
    printf("你所要修改的书的资料如下，请选择你要修改的内容:\n"); 
    printf("序号       书名      作者 \n"); 
    printf("%d   %s  %s\n",book[i].booknum,book[i].bookname,book[i].bookcreat); 
	printf("1: 修改书号:\n"); 
    printf("2: 修改书名:\n"); 
    printf("3: 修改作者:\n"); 
	printf("4: 修改单价:");
    printf("请输入1━4:"); 
     choice=getch(); 
    switch(choice) 
    { 
     case '1': 
     { 
      printf("新的书号:\n"); 
      scanf("%d",&book[i].booknum); 
      fwrite(&book[i],sizeof(struct book),1,fp2); 
     }break; 
     case '2': 
     { 
      printf("新的书名:\n"); 
      scanf("%s",book[i].bookname); 
      fwrite(&book[i],sizeof(struct book),1,fp2); 
     }break; 
     case '3': 
     { 
      printf("新的作者:\n"); 
      scanf("%s",book[i].bookcreat); 
      fwrite(&book[i],sizeof(struct book),1,fp2); 
     }break; 
	 case '4':
	{
		printf("新的单价:");
		scanf("%f",book[i].bookprice);
        fwrite(&book[i],sizeof(struct book),1,fp2);
	}
     default:printf("没有这样的操作!");break; 
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
printf("按任意键返回...\n"); 
getchar(); 
return 0; 
} 
////////////(4).图书统计
bookcount() 
{ 
FILE *fp; 
int i,n=0; 
fp=fopen("book.txt","r"); 
for(i=0;fread(&book[i],sizeof(struct book),1,fp)!=0;i++) 
{ 
   if(book[i].booknum!=0&&strlen(book[i].bookname)!=0&&strlen(book[i].bookcreat)!=0) 
   { 
    printf("第%d本书\n序号           书名               作者       单价    状态 \n",i+1); 
    printf(" %d       %10s    ",book[i].booknum,book[i].bookname); 
	printf("%15s      %4.2f    %d(1在/0不在)\n",book[i].bookcreat,book[i].bookprice,book[i].turefalse);
	n=n+1; 
   } 
} 
fclose(fp); 
printf("目前共有%d本书.\n",n); 
printf("按任意键返回...\n"); 
}
//////////////////////结束界面函数
end()
{   system("cls");
	printf("\t\t┏┳━━━━━━━━━━━━┳┓\n");
	printf("\t\t┣╋━━━━━━━━━━━━╋┫\n");
	printf("\t\t┃┃ 谢谢使用本系统 , 再见! ┃┃\n");
      printf("\t\t┣╋━━━━━━━━━━━━╋┫\n");
      printf("\t\t┗┻━━━━━━━━━━━━┻┛\n");	
}/////////////////////////////////////////////////////////////
////////////////////主函数///////////////////////////
main() 
{ 
char ch1,ch2,ch4; 
system("color 2e");
do
{  system("cls");
   printf("\t\t┏┳━━━━━━━━━━━━┳┓\n");
   printf("\t\t┣╋━━━━━━━━━━━━╋┫\n");
   printf("\t\t┃┃  欢迎进入图书管理系统  ┃┃\n");
   printf("\t\t┣╋━━━━━━━━━━━━╋┫\n");
   printf("\t\t┗┻━━━━━━━━━━━━┻┛\n");
   printf(" 请选择:\n"); 
   printf(" 1:查阅图书 \n"); 
   printf(" 2:借阅图书 \n"); 
   printf(" 3:管理系统 \n"); 
   printf(" 4:还书 \n"); 
   printf(" 0:退出 \n"); 
   printf("请输入0━4:\n"); 
   ch1=getch(); 
   switch(ch1) 
   { 
    case '1':chabook();break; 
    case '2':lendbook();;break; 
    case '3':{ 
       do 
       { system("color 4e");
	    system("cls");
        printf("\t\t●●●欢迎进入管理系统●●●\n"); 
        printf(" 1:增加图书 \n"); 
        printf(" 2:删除图书 \n"); 
        printf(" 3:修改图书 \n"); 
        printf(" 4:图书统计 \n"); 
    
        printf(" 5:会员管理系统 \n"); 
        printf(" 0:返回 \n"); 
        printf("请输入0━5:\n"); 
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
            printf("\t\t◎◎◎欢迎进入学生管理系统◎◎◎\n"); 
            printf(" 1: 申请新卡 \n"); 
            printf(" 2: 删除卡号 \n"); 
            printf(" 3: 借书统计 \n"); 
            printf(" 4: 卡号统计 \n"); 
            printf(" 0: 返回 \n"); 
            printf("请输入0━4:\n"); 
             ch4=getch(); 
            switch(ch4) 
             { 
              case '1':addcar();break; 
              case '2':delcar();break; 
              case '3':lendcount();break; 
              case '4':carcount();break; 
              case '0':break; 
              default:printf("无此操作!\n");getch();break; 
             } 
            }while(ch4!='0');}break; 
            case '0':break; 
            default:printf("无此操作!\n");getch();break; 
           } 
        }
			 while(ch2!='0');}break; 
        case '4':huanbook();break; 
        case '0':break; 
        default:printf("无此操作!\n");getch();break; 
   } 
}while(ch1!='0'); 
}
 

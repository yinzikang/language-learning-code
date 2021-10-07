#include<stdio.h>              //头文件
#include<string.h>
#include<stdlib.h>
#define L 30                  //宏定义
#define Q 200
struct book                   //定义一个book类结构体。
{
	char no[L];
	char name[L];
	char author[L];
	char fenlei[L];
	char puttime[L];
	char putfrom[L];
	char price[L];
};



//函数声明                                //函数声明
void menu();
int bookluru(struct book*p,int n);                                    
void bookliulan(struct book*p,int n);                                        
void bookchaxun(struct book*p,int n);      
void bookxiugai(struct book*p,int n);      
int bookzhengjia(struct book*p,int n);
int bookshanchu(struct book*p,int n);                                        
void bookpaixu(struct book*p,int n);        
void DLsearch(struct book*p,int n);       
void AUsearch(struct book*p,int n);
int bookzairu(struct book*p,int n);
void goout();
int bookbaocun(struct book*p,int n);

       
void main()                                //主函数
{
	char slect,yn;
	struct book record[Q];                 //定义book类结构体变量存放图书信息共200条
	int total=0,flag;
total=bookzairu(record,Q);              //从文件读取图书信息，不超过200条
	do
	{
		menu();                            //显示菜单
		printf("请服务项编号：");
		slect=getchar();
		getchar();

		switch(slect)
		{
        case'0': goout();break;
		case'1': total=bookluru(record,total);break;   //函数调用
		case'2': bookliulan(record,total);break;
		case'3': bookchaxun(record,total);break;
		case'4': bookxiugai(record,total);break;
		case'5': total=bookzhengjia(record,total);break;
		case'6': total=bookshanchu(record,total);break;
		case'7': bookpaixu(record,total);break;
		case'8': flag=bookbaocun(record,total);
			if("flag==1")     
				printf("图书信息保存成功！\n");
			else
				printf("图书信息保存失败！\n");
			break;
		default:continue;
		}
	if(slect=='0') break;
		printf("\n还要继续选择吗？（Y/N）");      //提示是否结束
		do
		{
			yn=getchar();
			getchar();
			if (yn=='Y'||yn=='y')
				break;
			else if (yn=='N'||yn=='n')
				break;
			else
		    	printf("非法选项！\n还要继续选择吗？（Y/N）");			
		}
		while(1);
	}
	while(yn!='N'&&yn!='n');
}


//图书管理系统主菜单.
void menu()
{
	system("cls");
    printf("\n\n");
    printf("请选择服务项目编号（0--8）\n");
    printf("******************************************************************\n");
    printf("§********************欢迎使用图书信息管理系统******************  §\n");
    printf("§**************************************************************  §\n");
    printf("§§                                                            §§\n");
    printf("§§                                                            §§\n");
    printf("§§                                                            §§\n");
    printf("§§                    * 1 . 图书信息录入.                     §§\n");
    printf("§§                    * 2 . 图书信息浏览.                     §§\n"); 
    printf("§§                    * 3 . 图书信息查寻.                     §§\n");
    printf("§§                    * 4 . 图书信息修改.                     §§\n");
    printf("§§                    * 5 . 图书信息增加.                     §§\n");
    printf("§§                    * 6 . 图书信息删除.                     §§\n");
    printf("§§                    * 7 . 图书信息排序.                     §§\n");
    printf("§§                    * 8 . 图书信息保存.                     §§\n");
    printf("§§                    * 0 . 退出图书管理系统.                 §§\n");
    printf("§§                                                            §§\n");
    printf("§§                                                            §§\n");
    printf("§§                                                            §§\n");
    printf("******************************************************************\n");
    printf("\n");
}



int bookluru(struct book *p,int n)//录入图书信息.
{
	int i=0;
	int m;
	printf("\n添加前的图书信息记录共有%d个：\n",n);        //显示原有的图书信息
	printf("\n %9s%9s%9s%9s%9s%9s%9s\n","登录号","书名","作者名","分类号","出版单位","出版时间","价格");
	i=0;
	while((i<n)&&(strcmp(p->no,"")!=0))        //输入的登录号不为空时，输出图书信息
	{
	printf("%9s%9s%9s%9s%9s%9s%9s\n",p->no,p->name,p->author,p->fenlei,p->puttime,p->putfrom,p->price);//信息输出
		i++;
		p++;
	}
	printf("\n请输入要录入的图书数目X（0<X<%d）: ",200-n);  //设置图书信息存储最大值
	scanf("%d",&m);
	i=0;
	while(i<m)
	{
		printf("\n");
		printf("请输入第%d本图书的信息：\n",i+1);
		printf("登录号: ");
		do
		{
		   gets(p->no);     //输入登录号，再输入其他信息
		}
		while(strcmp(p->no,"")==0);
		printf("书名为:");
        gets(p->name);
        printf("作者名为:");
        gets(p->author);
        printf("分类号为:");
        gets(p->fenlei);
        printf("出版时间为:");
        gets(p->puttime);
        printf("出版单位为:");
        gets(p->putfrom);
    printf("价格为:");
        gets(p->price);
		p++;
		i++;
	}
	return m+n;
}


void bookliulan(struct book*p,int n)//图书信息浏览.
{
	int i=0;
	printf("\n %9s%9s%9s%9s%9s%9s%9s\n","登录号","书名","作者名","分类号","出版单位","出版时间","价格");
	while(i<n)                                            //输出原有图书信息
	{
	printf("%9s%9s%9s%9s%9s%9s%9s\n",p->no,p->name,p->author,p->fenlei,p->puttime,p->putfrom,p->price);
		p++;
		i++;
	}
}


void bookchaxun(struct book*p,int n)//图书信息查寻.
{
	char c;
	bookliulan(p ,n);
	do
	{
		printf("\n请问按登录号查询（D），还是按作者名查询（A）？");  //选择查询方式
		c=getchar();
		getchar();
		if(c=='D'||c=='d')
		{
			DLsearch(p,n);
			break;
	}
		else if(c=='A'||c=='a')
		{
			AUsearch(p,n);
			break;
		}
		else
		{
			printf("\n输入的为非法字符！\n");
			continue;
		}
	}
	while(c!='D'||c!='d'||c!='A'||c!='a');
}


void DLsearch(struct book*p,int n)//按登录号查询.
{
	int i,x=0;
	char DL[L];
	printf("\n请输入要查询图书的登录号：");
	gets(DL);
	for(i=0;i<n;i++)
		if(strcmp(DL,p[i].no)==0)     //输入登录号，如果在系统中找到则输出图书信息
		{
		printf("\n %9s%9s%9s%9s%9s%9s%9s\n","登录号","书名","作者名","分类号","出版单位","出版时间","价格");
printf("\n%10s%10s%10s%10s%10s%10s%10s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price);
		x=1;
		break;
		}
		if(x==0)
		printf("\n对不起，图书系统中没有包含此书的信息！\n");
}


void AUsearch(struct book*p,int n)//按作者名查询.
{
	int i,x=0;
	char AU[20];
	printf("\n请输入要查询图书的作者姓名：");
	gets(AU);
	for(i=0;i<n;i++)
	   if(strcmp(AU,p[i].author)==0)  //输入作者姓名，如果在系统中找到则输出图书信息
		{
	     printf("\n %9s%9s%9s%9s%9s%9s%9s\n","登录号","书名","作者名","分类号","出版单位","出版时间","价格");
	printf("\n%10s%10s%10s%10s%10s%10s%10s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price);
			x=1;
		}
		if(x==0)
		printf("\n对不起，图书系统中没有包含此书的信息！\n");  //提示信息
}


void bookxiugai(struct book*p,int n)//图书信息修改.
{
	int i,k=0;
	char no[L];
	bookliulan(p,n);
	printf("\n请输入要修改图书的登录号：");
	gets(no);
	for(i=0;i<n;i++,p++)      
	{
		if(strcmp(no,p->no)!=0) continue;     //输入的登录号不匹配，结束本次循环
		else
		{
			printf("\n请输入正确的图书登录号：");
			gets(p->no);	
			printf("\n请输入正确的图书书名:");
            gets(p->name);
            printf("\n请输入正确的图书作者名:");
            gets(p->author);
            printf("\n请输入正确的图书分类号:");
            gets(p->fenlei);
            printf("\n请输入正确的图书出版时间:");
            gets(p->puttime);
            printf("\n请输入正确的图书出版单位:");
            gets(p->putfrom);
            printf("\n请输入正确的图书价格:");
            gets(p->price);
			printf("\n修改图书图书信息完成！！");
			k=1;
		}
	}
	if(k==0)
		printf("\n对不起，图书系统中没有包含此书的信息！\n");
}


int bookzhengjia(struct book *p,int n)//图书信息增加.
{
	int i=0;
	char c;
	struct book t;
	printf("\n添加前图书信息的记录为：\n");
    bookliulan(p ,n);//显示添加前图书信息的记录
	do
	{
		printf("请输入新图书信息的登录号:");
	gets(t.no);       
		printf("\n请输入新图书信息的书名为:");
        gets(t.name);
        printf("\n请输入新图书信息的作者名为:");
        gets(t.author);
        printf("\n请输入新图书信息的分类号为:");
        gets(t.fenlei);
        printf("\n请输入新图书信息的出版时间为:");
        gets(t.puttime);
        printf("\n请输入新图书信息的出版单位为:");
        gets(t.putfrom);
        printf("\n请输入新图书信息的价格为:");
        gets(t.price);
		for(i=0;i<n;i++)		if(strcmp(t.no,(p+i)->no)==0||strcmp(t.author,(p+i)->author)==0||strcmp(t.fenlei,(p+i)->fenlei)==0)
			{
				printf("登录号、作者名和分类号重复，要重新输入吗（Y/N）？");
				c=getchar();
				putchar('\n');
				break;
			}
			if(i==n)
			{
				*(p+i)=t;  
	printf("\n添加后图书的信息记录为：\n");   //显示添加后图书的信息记录
	printf("\n %9s%9s%9s%9s%9s%9s%9s\n","登录号","书名","作者名","分类号","出版单位","出版时间","价格");
	for(i=0;i<n+1;i++)
	printf("\n%9s%9s%9s%9s%9s%9s%9s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price);
			break;
			}
	}
	while(c=='y'||c=='Y');
	return n+1;
}


int bookshanchu(struct book *p,int n)//图书信息删除.

{
	int i,x,y=0;
	char name[20],no[20];
	printf("\n删除前图书的信息记录为：\n");
	printf("\n %9s%9s%9s%9s%9s%9s%9s\n","登录号","书名","作者名","分类号","出版单位","出版时间","价格");        //显示删除前图书的信息记录
	for(i=0;i<n;i++)		printf("\n%9s%9s%9s%9s%9s%9s%9s\n",(p+i)->no,(p+i)->name,(p+i)->author,(p+i)->fenlei,(p+i)->putfrom,(p+i)->puttime,p[i].price);
	printf("\n请输入要删除图书的登陆号：");
	gets(no);
	for(x=0;x<n;x++)
	{
		if(strcmp(no,p[x].no)!=0)    ////输入的登录号不匹配，结束本次循环
			continue;
		if(x<n)
		{
			for(i=x;i<n;i++)         //后一个图书信息对前一个图书信息覆盖删除
			{
			   strcpy(p[i].no,p[i+1].no);
               strcpy(p[i].author,p[i+1].author);
               strcpy(p[i].name,p[i+1].name);
               strcpy(p[i].fenlei,p[i+1].fenlei);
               strcpy(p[i].price,p[i+1].price);
			   strcpy(p[i].putfrom,p[i+1].putfrom);
			   strcpy(p[i].puttime,p[i+1].puttime);
			}
			printf("图书信息删除后的记录：\n");
	printf("\n %9s%9s%9s%9s%9s%9s%9s\n","登录号","书名","作者名","分类号","出版单位","出版时间","价格");     //显示图书信息删除后的记录
	for(i=0;i<n-1;i++)		printf("\n%9s%9s%9s%9s%9s%9s%9s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price);
			y=1;
		}
		else
			printf("\n对不起，图书系统中没有包含此书的信息！\n");
		return n-y;
	}
}


//对图书信息排序.
void bookpaixu(struct book*p,int n)
{
	int j,i,k;
	char c1;
	struct book temp;
	printf("\n排序前图书的信息记录为：\n");
	printf("\n %9s%9s%9s%9s%9s%9s%9s\n","登录号","书名","作者名","分类号","出版单位","出版时间","价格");
	for(i=0;i<n;i++)
	printf("\n%10s%10s%10s%10s%10s%10s%10s\n",(p+i)->no,(p+i)->name,(p+i)->author,(p+i)->fenlei,(p+i)->putfrom,(p+i)->puttime,p[i].price);
	printf("\n按登录号排序（D），还是按作者名排序（A）？");      //选择排序的方式
	c1=getchar();
	getchar();
	if(c1=='d'||c1=='D')                //选择登录号由小到大排序
	{
		for(i=0;i<n-1;i++)                        
		{
			k=i;
			for(j=i+1;j<n;j++)
				if(strcmp(p[k].no,p[j].no)>0)     //使用选择法进行排序
					k=j;
				if(k!=i)    //如果最小熟不熟默认的p[i]，再交换，
				{
					temp=p[k];
					p[k]=p[i];
					p[i]=temp;
				}
		}
		printf("\n排序后图书的信息记录为：\n");            //输出排序后图书的信息
	printf("\n %9s%9s%9s%9s%9s%9s%9s\n","登录号","书名","作者名","分类号","出版单位","出版时间","价格");
	for(i=0;i<n;i++)		printf("\n%10s%10s%10s%10s%10s%10s%10s\n",(p+i)->no,(p+i)->name,(p+i)->author,(p+i)->fenlei,(p+i)->putfrom,(p+i)->puttime,p[i].price);
	}
	else if(c1=='a'||c1=='A')   //选择作者名由小到大排序
	{
		for(i=0;i<n-1;i++)
		{
	k=i;
			for(j=i+1;j<n;j++)
				if(strcmp(p[k].author,p[j].author)>0)
					k=j;
				if(k!=i)        //使用选择法进行排序
				{
					temp=p[k];
					p[k]=p[i];
					p[i]=temp;
				}
		}
		printf("\n排序后图书的信息记录为：\n");
		printf("\n %9s%9s%9s%9s%9s%9s%9s\n","登录号","书名","作者名","分类号","出版单位","出版时间","价格");        //输出排序后图书的信息
		for(i=0;i<n;i++)
	printf("\n%10s%10s%10s%10s%10s%10s%10s\n",(p+i)->no,(p+i)->name,(p+i)->author,(p+i)->fenlei,(p+i)->putfrom,(p+i)->puttime,p[i].price);
	}
	else
		printf("\n您输入的为非法字符！\n");
}


//图书信息文件存储.
int bookzairu(struct book*p,int n)  
{
	FILE *fp;               //定义FILE类型文件指针变量
	int i,all=0;
	char bookfile[200]="book.txt";
	fp=fopen("book.txt","r+");       //以只读方式打开
	if(fp==NULL)
	{
		printf("\n***打开%s失败！！***",bookfile);

		return 0;
	}
	fscanf(fp,"%d\n",&all);  //从文件指针指向的文本文件中按指定格式逐个输入信息到指定变量  
	if(all>200)                    //读取记录总数
	{
		printf("文件记录太多，不能读取！");
		return 0;
	}
	for(i=0;i<all;i++)       //图书信息按指定格式输入
	{	fscanf(fp,"%s %s %s %s %s %s %s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price);
	}
	fclose(fp);     //关闭文件
	return all;
}


//图书信息文件保存.
int bookbaocun(struct book*p,int n)
{
	FILE *fp;                        //定义FILE类型文件指针变量
	int i,all=0;
	char bookfile[30]="book.txt";
	fp=fopen(bookfile,"w");       //以只写方式打开
	if(fp==NULL)                    //
	{
		printf("\n***打开%s失败！！***",bookfile);   
		return 0;
	}
	fprintf(fp,"%d\n",n);         //将数据指定格式字符串输出到文件指针所指向的文本文件。
	for(i=0;i<n;i++)            //图书信息按指定格式输出
	{
	fprintf(fp,"%s %s %s %s %s %s %s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price);
	}
	fclose(fp);       //关闭文件
	return 1;
}


//图书管理系统退出
void goout()
{
printf("\n请按Enter键退出图书信息管理系统!\n");

}
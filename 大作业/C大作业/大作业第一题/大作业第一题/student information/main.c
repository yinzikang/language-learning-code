#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define q 1000//宏定义，设置学生数为30人
typedef struct tagSTUDENT//定义结构体类型
{
	int no;//学号
	char name[21];//姓名
	int Chinese;//语文成绩
	int math;//数学成绩
	int English;//英语作业
	int sum;//三科成绩之和
} Book;
void add(Book A[],int N)//结构体的地址
{
	int i,j,t;
	char M[21];
	for(i=0;i<N-1;i++)//总分降序排序，冒泡排序
	for(j=0;j<N-1-i;j++)
{
	if(A[j].sum<A[j+1].sum)
	{
		t=A[j].sum,A[j].sum=A[j+1].sum,A[j+1].sum=t;
		t=A[j].no,A[j].no=A[j+1].no,A[j+1].no=t;
		t=A[j].Chinese,A[j].Chinese=A[j+1].Chinese,A[j+1].Chinese=t;
		t=A[j].math,A[j].math=A[j+1].math,A[j+1].math=t;
		t=A[j].English,A[j].English=A[j+1].English,A[j+1].English=t;
		strcpy(M,A[j].name),strcpy(A[j].name,A[j+1].name),strcpy(A[j+1].name,M);
	}}

}
void Chinese_down(Book A[],int N)//结构体地址
{
	int i,j,t;
	char M[21];
	for(i=0;i<N-1;i++)//
	for(j=0;j<N-1-i;j++)
{
	if(A[j].Chinese<A[j+1].Chinese)//语文成绩排序，冒泡排序
	{
		t=A[j].Chinese,A[j].Chinese=A[j+1].Chinese,A[j+1].Chinese=t;
		strcpy(M,A[j].name),strcpy(A[j].name,A[j+1].name),strcpy(A[j+1].name,M);
	}}
}
void math_down(Book A[],int N)//结构体地址
{

	int i,j,t;
	char M[21];
	for(i=0;i<N-1;i++)//数学成绩降序排序，冒泡排序
	for(j=0;j<N-1-i;j++)
{
	if(A[j].math<A[j+1].math)
	{
		t=A[j].math,A[j].math=A[j+1].math,A[j+1].math=t;
		strcpy(M,A[j].name),strcpy(A[j].name,A[j+1].name),strcpy(A[j+1].name,M);
	}}

}
void English_down(Book A[],int N)//结构体地址
{


	int i,j,t;
	char M[21];
	for(i=0;i<N-1;i++)//英语成绩降序排序，冒泡排序
	for(j=0;j<N-1-i;j++)
{
	if(A[j].English<A[j+1].English)
	{
		t=A[j].English,A[j].English=A[j+1].English,A[j+1].English=t;
		strcpy(M,A[j].name),strcpy(A[j].name,A[j+1].name),strcpy(A[j+1].name,M);
	}}
}
int chazhao(Book A[],int N)
{
	int k,i,str1;
	printf("输入学号\n");//输入要查找学生的学号
		scanf("%d",&str1);k=66;
		printf("查找结果\n");//输出查找结果
		for(i=0;i<N;i++)
		if(str1==A[i].no) k=i;
         if(k==66) printf("输入错误");
		else
		{
			printf("正确\n");
			printf("%d %s %d %d %d %d\n",A[k].no,A[k].name,A[k].Chinese,A[k].math,A[k].English,A[k].sum);}
			printf("\n");
			return k;
}
int main()
{  printf("\n");
	printf("\n");
	printf("------------------------------------班号 09051601 学号 2016302201 姓名 王萌---------------------------------------------\n ");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
  FILE *fp;//定义文件指针
Book  A[q],*fppp;
 fppp=&A;//定义指针，指向结构体
 int str1;
	int i,j,k=0,N;
	printf("输入学生人数:");//输入学生数据，存储在结构体中
	scanf("%d",&N);
	printf("输入学生信息:");
	for(i=0;i<N;i++)
		scanf("%d%s%d%d%d",&A[i].no,A[i].name,&A[i].Chinese,&A[i].math,&A[i].English);//输入学号，姓名，语文，数学，英语
		for(i=0;i<N;i++,fppp++)//使用指针，进行各科成绩+运算，赋值在A[].sum
		fppp->sum=fppp->Chinese+fppp->math+fppp->English;
		printf("请进行功能选择:\n");
		printf("总分排名:1\n");
		printf("语文成绩排名:2\n");
		printf("数学成绩排名:3\n");
		printf("英语成绩排名:4\n");
		printf("查找已有学生成绩:5\n");
		printf("退出:0\n");
		scanf("%d",&i);
		for(;;)
		{if(i==0) break;

		else switch(i)
		{
			case 1 :{
				 add(A,N);printf("排名 学号 姓名 语文 数学 英语 总分\n");//将提示信息输出在显示屏上
				 for(i=0,j=1;i<N;i++,j++)
	printf("%02d  %d  %s  %d  %d  %d  %d\n",j,A[i].no,A[i].name,A[i].Chinese,A[i].math,A[i].English,A[i].sum);//将排序后的学生信息输出在显示屏上
	printf("请进行功能选择:");scanf("%d",&i);
	break;}
			case 2 :{
				Chinese_down(A,N);
				printf("语文排名\n");//将提示信息“语文排名”输出在显示屏上
					for(i=0,j=1;i<N;i++,j++)
                    printf("%02d  %s   %d\n",j,A[i].name,A[i].Chinese);//将排序后的学生姓名，语文成绩输出在显示屏上内
                    printf("请进行功能选择:");scanf("%d",&i);
				break;}
			case 3 :{math_down(A,N);
			printf("数学排名\n");
			for(i=0,j=1;i<N;i++,j++)
	printf("%02d  %s   %d\n",j,A[i].name,A[i].math);
	printf("请进行功能选择:");scanf("%d",&i);
			break;}
			case 4 :{English_down(A,N);
			printf("英语排名\n");
		  for(i=0,j=1;i<N;i++,j++)
	printf("%02d  %s   %d\n",j,A[i].name,A[i].English);//将排序后的学生姓名，英语成绩输出在显示屏上内
	printf("请进行功能选择:");scanf("%d",&i);
			break;}
			case 5 :{k=chazhao(A,N);
			printf("请进行功能选择:");scanf("%d",&i);
			break;}
		}}
		add(A,N);//进行总分降序排序
	fp=fopen("A0.TXT","w+");//打开文件A0.TXT
	if(fp==NULL) return -1;
		fprintf(fp,"排名 学号 姓名 语文 数学 英语 总分\n");//将提示信息输出在文件内
		//printf("排名 学号 姓名 语文 数学 英语 总分\n");//将提示信息输出在显示屏上
		fclose(fp);//关闭文件
	fp=fopen("A0.TXT","a");//打开文件
	if(fp==NULL) return -1;
	for(i=0,j=1;i<N;i++,j++)
		{fprintf(fp,"%02d  %d  %s  %d  %d  %d  %d\n",j,A[i].no,A[i].name,A[i].Chinese,A[i].math,A[i].English,A[i].sum);}//将排序后的学生信息输出在文件内
		//printf("%02d  %d  %s  %d  %d  %d  %d\n",j,A[i].no,A[i].name,A[i].Chinese,A[i].math,A[i].English,A[i].sum);}//将排序后的学生信息输出在显示屏上
		fprintf(fp,"语文排名\n");//将提示信息“语文排名”输出在文件内
		//printf("语文排名\n");//将提示信息“语文排名”输出在显示屏上
		fclose(fp);
		Chinese_down(A,N);//语文成绩降序排序
		fp=fopen("A0.TXT","a");
	if(fp==NULL) return -1;
	for(i=0,j=1;i<N;i++,j++)
		{fprintf(fp,"%02d  %s   %d\n",j,A[i].name,A[i].Chinese);}//将排序后的学生姓名，语文成绩输出在文件内
		//printf("%02d  %s   %d\n",j,A[i].name,A[i].Chinese);}//将排序后的学生姓名，语文成绩输出在显示屏上内
		fprintf(fp,"数学排名\n");
		//printf("数学排名\n");
		fclose(fp);
		math_down(A,N);//数学成绩降序排序
		fp=fopen("A0.TXT","a");
	if(fp==NULL) return -1;
	for(i=0,j=1;i<N;i++,j++)
		{fprintf(fp,"%02d  %s   %d\n",j,A[i].name,A[i].math);}//将排序后的学生姓名，数学成绩输出在文件内
      // printf("%02d  %s   %d\n",j,A[i].name,A[i].math);}//将排序后的学生姓名，数学成绩输出在显示屏上内
		//printf("英语排名\n");
		fprintf(fp,"英语排名\n");
		fclose(fp);
		English_down(A,N);//英语成绩降序排序
		fp=fopen("A0.TXT","a");
	if(fp==NULL) return -1;
	for(i=0,j=1;i<N;i++,j++)
		{fprintf(fp,"%02d  %s   %d\n",j,A[i].name,A[i].English);}////将排序后的学生姓名，英语成绩输出在文件内
		//printf("%02d  %s   %d\n",j,A[i].name,A[i].English);}//将排序后的学生姓名，英语成绩输出在显示屏上内
		fprintf(fp,"查找结果\n");
		fclose(fp);
			fp=fopen("A0.TXT","a");
	if(fp==NULL) return -1;
		fprintf(fp,"%d %s %d %d %d %d\n",A[k].no,A[k].name,A[k].Chinese,A[k].math,A[k].English,A[k].sum);//输出查找学生的信息
		fclose(fp);
    return 0;
}

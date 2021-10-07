#include <stdio.h> 
#include <conio.h> 
#include <string.h> 
#include <windows.h> 
#define TRUE 1

void read();      
void write();     
void find();      
void modify();   
void add();       
void del();       
void rank();            
struct xueshengchengji 
{
	char name[10]; 
	char xuehao[10]; 
	float cyuyan; 
	float math; 
	float english; 
	float average; 
};

struct xueshengchengji chengji[100],*p=chengji; 
int n = -1; 
void main() {
	
	char ch;
	read(); 
	while(TRUE) {
		system("cls"); 
		printf("\t\t请选择（1-7）:\n");
		printf("\t\t======================================================\n"); printf("\t\t\t 1.查询学生成绩记录\n");
		printf("\t\t\t 2.修改学生成绩记录\n");
		printf("\t\t\t 3.添加学生成绩记录\n");
		printf("\t\t\t 4.删除学生成绩记录\n");
		printf("\t\t\t 5.保存学生成绩记录\n");
		printf("\t\t\t 6.成绩排序\n");
		printf("\t\t\t 7.退出\n");
		printf("\t\t======================================================\n"); printf("\n\t\t");
		ch=getch();
		switch(ch) {
		case '1':
			find();
			break; 
		case '2':
			modify();
			break;
		case '3':
			add();
			break; 
		case '4':
			del();
			break; 
		case '5':
			write();
			break; 
		case '6':
			rank();
			break; 
		case '7':
			
			return; 
		default:
			printf("\t\t \n");
			getch();
		}
	}
	return;
}

void read()
{
	FILE * file; 
	if((file=fopen("cj.dat","rb"))==NULL)
		 {
		printf("\n\n\t 学生成绩数据文件无法打开，或为空！");
	printf("\n\n\t 按任意键进入主菜单.......");
	getch();
	return;
	}
	else 
	{
		n++; 
		while(fread(&chengji[n],sizeof(chengji[n]),1,file) == 1)
			n++;
		fclose(file); 
		printf("\n\n\t学生成绩数据读取完毕\n",n);
		n--; 
	}
}

void write()
{
	FILE *file; 
	if(n == -1) 
	{
		
		printf(" 没有数据可存！按任意键返回主菜单 \n");
		getch();
		return;
	}
	if((file=fopen("cj.dat","wb"))!=NULL)
		
	{
		fwrite(&chengji[0],sizeof(chengji[0]),n+1,file); 
		fclose(file); 
		printf("\n\n\t\t%d条学生记录保存完毕！\n",n+1);
	}
	else 
		printf("\t\t无法打开学生成绩数据文件！\n");
	printf("\n\t\t按任意键返回主菜单...... ");
	getch();
}

void find()
{
	char xuehao[10]; 
	int i; 
	if(n==-1) 
	{
		printf("\n\n\t\t当前还没有学生成绩，按任意键返回主菜单......");
		getch();
		return;
	}
	printf("\t请输入学生学号:"); 
	gets(xuehao); 
	for(i=0;i<=n;i++) 
	{
		if(strcmp(chengji[i].xuehao,xuehao)==0) 
		{
			printf("\n 该学生成绩情况如下:");
			printf("\n===================\n\n");
			printf("   学号 姓名");
			printf("    英语     C语言    高等数学 平均成绩\n"); printf("%6s%6s",chengji[i].xuehao,chengji[i].name);
			printf("%9.2f%9.2f%9.2f%9.2f",chengji[i].cyuyan,chengji[i].math,chengji[i].english,chengji[i].average);
			printf("\n 按任意键返回主菜单......");
			getch();
			break;
		}
	}
	if(i==n+1)
	{
		printf("\n\t\t您所输入的学生学号有误或不存在!");
		printf("按任意键返回主菜单......");
		getch();
		return;
	}
}
void list()
{
	int i;
	system("cls");
	printf("\n\n\t\t\t 全体学生成绩情况如下\n");
	printf("\t\t\t===========================\n\n");
	printf("学号    姓名 ");
	printf("英语    C语言  高等数学   平均成绩");
	for(i=0;i<=n;i++)
	{
		printf("%6s%6s%9s",chengji[i].xuehao,chengji[i].name,chengji[i].average);
		printf("%9.2f%9.2f%9.2f",chengji[i].english,chengji[i].math); }
}
void modify ( )
{
	char xuehao[10]; 
	int i; 
	if (n==-1) 
	{
		printf("\n\n\t\t当前还没有学生成绩记录，按任意键返回主菜单......");
		
		getch( );
		return;
	}
	printf("\t请输入学生学号:"); 
	gets(xuehao); 
	for (i=0;i<=n;i++) 
	{
		if(strcmp(chengji[i].xuehao,xuehao)==0) 
		{
			
			printf("\n\t\t\t 该学生成绩情况如下: ");
			printf("\n\t\t\t===================\n\n");
			printf("   学号 姓名");
			printf("    英语     C语言    高等数学 平均成绩\n"); printf("%6s%6s",chengji[i].xuehao,chengji[i].name);
			printf("%9.2f%9.2f%9.2f%9.2f",chengji[i].cyuyan,chengji[i].math,chengji[i].english,chengji[i].average);
			printf("\n\t\t 请输入该学生新的英语成绩: ");
			scanf ("%f",&chengji[i].cyuyan);
			printf("\n\t\t 请输入该学生新的C语言成绩: ");
			scanf ("%f",&chengji[i].math);
			printf("\n\t\t 请输入该学生新的高等数学成绩: ");
			scanf ("%f",&chengji[i].english);
			chengji[i].average=(chengji[i].cyuyan+chengji[i].math+chengji[i].english)/3; 
			printf("\n\t\t\t 该学生成绩是: %f",chengji[i].average);
			printf("\n\n\t\t 该学生成绩数据修改成功! 按任意键返回主菜单......");
			getch();
			return ;
		}
	}
	printf("\n\t\t 您所输入的学生学号有误或不存在! ");
	
	printf("按任意键返回主菜单......");
	getch();
	return;
}

void add()
{
	printf ("\t请输入学生学号：");
	fflush(stdin); 
	gets(chengji[++n].xuehao);
	printf("\t\t\t\t请输入学生姓名：");
	gets(chengji[n].name);
	printf("\t\t\t\t请输入该学生的英语成绩：");
	scanf("%f",&chengji[n].cyuyan);
	printf("\t\t\t\t请输入该学生的C语言成绩：");
	scanf("%f",&chengji[n].math);
	printf("\t\t\t\t请输入该学生的高等数学成绩：");
	scanf("%f",&chengji[n].english);
	chengji[n].average=(chengji[n].cyuyan+chengji[n].math+chengji[n].english)/3; /*输出内容*/
	printf("\n\t\t\t\t该学生成绩为:%f",chengji[n].average);
	printf("\n\n\t\t\t\t按任意键返回......");
	getch();
}
void del()
{
	char xuehao[10]; 
	int i,j; 
	char d; 
	printf("\t请输入待删除学生学号：");
	gets(xuehao);
	for(i=0;i<=n;i++)  {
		if(strcmp(chengji[i].xuehao,xuehao)==0) 
		{
			printf("\n\t\t你确认要删除%s号学生成绩信息么(y/n)?",chengji[i].xuehao );
			
			d=getche();
			if(d=='y'||d=='Y') 
			{
				if(i==n) 
					n--;
				else 
				{
					for(j=i;j<=n;j++) 
					{
						strcpy(chengji[j].xuehao,chengji[j+1].xuehao); strcpy(chengji[j].name,chengji[j+1].name);
						chengji[j].english=chengji[j+1].english;
						chengji[j].math=chengji[j+1].math;
						chengji[j].cyuyan=chengji[j+1].cyuyan;
					}
					n--;
				}
				printf("\n\n\t\t该学生记录成功删除，按任意键返回主菜单......"); getch();
				break;
			}
			else 
			{
				printf("\n\n\t\t你选择了不删除该学生记录，按任意键返回主菜单......");
				getch();
				return;
			}
		}
	}
	if(i == n+1)  {
		printf("\n\t\t本班级无此学号，按任意键返回主菜单......");
		getch();
	}
}

void rank()
{
	
	int i,j; 
	printf("\t按平均成绩排序如下\n");
	for (i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if (chengji[i].average>chengji [j].average)
			{*p=chengji[j];chengji[j]=chengji[i];chengji[i]=*p;}
			printf("%-6s%-6s","学号","姓名");
			printf("%-12s%-6s%12s%-9s\n","    英语"," C语言","高等数学","平均成绩"); 
			for(i=0;i<=n;i++)
			{
				printf("%-6s%-6s",chengji[i].xuehao,chengji[i].name);
				printf("%9.2f%9.2f%9.2f%9.2f\n",chengji[i].cyuyan,chengji[i].math,chengji[i].english,chengji[i].average);
			}
			printf("\n\n\t\t\t\t按任意键返回......");
			getch();
}
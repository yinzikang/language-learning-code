#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<malloc.h>
#include<conio.h> //函数声明// 
int mainmenu(); //主菜单
void xinximenu(); //物业信息菜单
void tongjimenu();//统计查询菜单
void mychaozhao(); //欠费名单
void yezhumenu();//业主菜单
void wuyemenu();//物业菜单
void myAdd1();//录入业主信息
void myDelete1();//删除业主信息
void myReplace1();//修改业主信息
void myReplace2();//修改物业信息
void myfind();//查询缴费


struct yezhu {  //业主结构体//
	char id[100];
	char name[20]; 
	int age; 
	int family_num; 
	int floor_num; 
	char room_num[100];
	int area; 
	char rz_time[20]; 
	struct yezhu *next;
};

struct wuye {   //物业信息结构体//
	char ID[100];  
	int last_year; 
	int last_month; 
	float money;
	int to_time;
	struct wuye *link; 
};



int mainmenu()//主菜单// 
{ 
	int n; 
	printf("**************************欢迎进入小区物业管理系统***************************\n");
	printf("-----------------------------------------------------------------------------\n"); 
	printf("* * * * * * * * * * * * * * * 请选择（1～3）* * * * * * * * * * * * * * *\n");
	printf("* *\n"); printf("* *\n");
	printf("* ⒈物业信息系统； *\n"); 
	printf("* *\n");
	printf("* ⒉统计查询系统； *\n");
	printf("* *\n");
	printf("* ⒊退出程序。 *\n");
	printf("* *\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"); 
	printf("请您输入选项:");
	scanf("%d",&n);
	return n;
} 


void xinximenu()//物业信息菜单显示//
{ 
	int m; 
	do { 
		printf("*****************************物业信息系统************************************\n"); 
		printf("-----------------------------------------------------------------------------\n"); 
		printf("* * * * * * * * * * * * * * * 请选择（1～3）* * * * * * * * * * * * * * *\n"); 
		printf("* *\n");
		printf("* *\n");
		printf("* ⒈小区业主信息管理； *\n"); 
		printf("* *\n"); 
		printf("* ⒉物业费用信息管理； *\n"); 
		printf("* *\n");
		printf("* ⒊返回主菜单。 *\n"); 
		printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"); printf("请您输入选项:"); 
		scanf("%d",&m); 
		switch(m) 
			{
				case 1:yezhumenu();//业主菜单
					break;
				case 2:wuyemenu();//物业菜单
					break; 
				case 3:return;
				default:printf("输入错误，请重新输入：\n");
			} 
		} while(1);
}


void tongjimenu()	//统计查询菜单显示//
{
	int m; 
	do { 
		printf("******************************统计查询系统***********************************\n");
		printf("-----------------------------------------------------------------------------\n"); 
		printf("* * * * * * * * * * * * * * * 请选择（1～3）* * * * * * * * * * * * * * *\n");
		printf("* *\n"); 
		printf("* *\n");
		printf("* ⒈查询缴费信息； *\n");
		printf("* *\n"); 
		printf("* 2.返回主菜单。 *\n");
		printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"); 
		printf("请您输入选项:");
		scanf("%d",&m);
		switch(m) 
			{ 
				case 1 : myfind();//查询缴费
					break;
				case 2 : return;
				default: printf("输入错误，请重新输入!\n\n");
			} 
		} while(1);
} 


void yezhumenu()//业主菜单函数
{
	int m;
	do {
		printf("********************************业主信息编辑系统******************************-\n"); 
		printf("-------------------------------------------------------------------------------\n");
		printf("* * * * * * * * * * * * * * * *请选择（1～5）* * * * * * * * * * * * * * *\n");
		printf("* *\n"); 
		printf("* *\n");
		printf("* ⒈业主信息录入； *\n"); 
		printf("* *\n");
		printf("* ⒉业主信息修改； *\n"); 
		printf("* *\n"); 
		printf("* ⒊业主信息删除； *\n");
		printf("* *\n"); 
		printf("* 4.返回上级菜单。 *\n");
		printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"); 
		printf("请输入选项："); 
		scanf("%d",&m); 
		switch(m) 
			{ 
				case 1 :myAdd1();//录入业主信息
					break; 
				case 2 :myReplace1();//修改业主信息
					break; 
				case 3 :myDelete1(); //删除业主信息
					break; 
				case 4 : return;
				default: printf("输入错误，请重新输入：\n");
			} 
		} while(1);
 } 


void myAdd1()//录入业主信息//
 { 
	struct yezhu *p;
	p=(struct yezhu *)malloc(sizeof(struct yezhu));
	printf("请录入业主信息：\n"); 
	printf("ID:");
	scanf("%s",p->id);
	printf("姓名:");
	scanf("%s",p->name);
	printf("年龄："); 
	scanf("%d",&p->age);
	printf("家庭成员数：");
	scanf("%d",&p->family_num);
	printf("所在楼号："); 
	scanf("%d",&p->floor_num);
	printf("单元房间号:");
	scanf("%s",p->room_num);
	printf("住宅面积:");
	scanf("%d",&p->area); 
	printf("入住时间：");
	scanf("%s",p->rz_time);
	printf("录入成功!\n");
 } 



void myReplace1()//修改业主信息
{   char id[100];
	struct yezhu *k; 
	k=(struct yezhu *)malloc(sizeof(struct yezhu)); 
	printf("请输入要修改的业主ID:"); 
	scanf("%s",id);  
		{
			printf("请输入要修改的业主信息：\n"); 
			printf("ID:"); 
			scanf("%s",k->id); 
			printf("姓名:"); 
			scanf("%s",k->name); 
			printf("年龄："); 
			scanf("%d",&k->age); 
			printf("家庭成员数："); 
			scanf("%d",&k->family_num); 
			printf("所在楼号："); 
			scanf("%d",&k->floor_num); 
			printf("单元房间号:"); 
			scanf("%s",k->room_num); 
			printf("住宅面积:"); 
			scanf("%d",&k->area); 
			printf("入住时间："); 
			scanf("%s",k->rz_time);  
			printf("修改成功!\n");
		}
}



void myDelete1()//删除业主信息
{  
	char id[100];
	printf("请输入要删除人的ID:"); 
	scanf("%s",id);
	printf("删除业主信息成功!\n");  
} 

void save1(struct yezhu *p)//保存业主信息至文件
{ 
	FILE *fp; 
	fp=fopen("yezhu.dat","wb");
	while(p!=NULL)
		{ 
			fwrite(p,sizeof(struct yezhu),1,fp);
			p=p->next;
		}
	fclose(fp);
}



void wuyemenu() //物业菜单
{ 
	int m;
	do { 
		printf("*********************************物业费用管理系统************************\n");
	printf("-------------------------------------------------------------------------\n");
	printf("* * * * * * * * * * * * * * * 请选择（1～5）* * * * * * * * * * * * *\n"); 
	printf("* * \n");
	printf("* *\n");
	printf("* ⒈物业信息录入； *\n"); 
	printf("* *\n");
	printf("* ⒉物业信息修改； *\n");
	printf("* *\n");
	printf("* ⒊物业信息删除； *\n");
	printf("* *\n"); 
	printf("* 4.返回上级菜单。 *\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("请输入选项："); 
	scanf("%d",&m);
	switch(m) 
		{ 
			case 1: myAdd1();//录入业主信息
				break;
			case 2: myReplace2();//修改物业信息
				break;
			case 3: myDelete1();//删除业主信息
				break;
			case 4: return;
			default:printf("输入错误，请重新输入：\n");
		} 
	} while(1);
} 


void myAdd2()//录入物业信息//
{ 
	struct wuye *p;
	struct yezhu *t;
	p=(struct wuye *)malloc(sizeof(struct wuye)); 
	printf("请录入物业信息：\n");
	printf("ID:");
	scanf("%s",p->ID);
	if(t!=NULL)
		{
			printf("上一次缴费年份：");
			scanf("%d",&p->last_year);
			printf("月份：");
			scanf("%d",&p->last_month);
			printf("缴费金额：");
			scanf("%f",&p->money);
			printf("录入成功!\n");
		}
	else 
		{ 
			printf("无此业主ID!\n");
			return;
		} 
 } 



struct wuye *find2(char *id)//通过姓名查找缴费信息// 
{ 
	struct wuye *p;
	while(p!=NULL) 
		{ 
			if(strcmp(p->ID,id)==0)
				return p;
			p=p->link;
		}
	return NULL; 
}

void myfind() //查询缴费
{ 
	struct wuye *p;
	char a[100];
	printf("请输入要查找的业主id：");
	scanf("%s",a);
			printf("业主已经存缴!\n");
}

void myReplace2()//修改物业信息
{ 
	char id[20];
	struct wuye *k;
	k=(struct yezhu *)malloc(sizeof(struct yezhu)); 
	printf("请输入要修改的业主ID:");
	scanf("%s",id);
		{
			printf("您要修改的信息为：\n");
			printf("请输入新的信息：\n");
			printf("ID:");
			scanf("%s",k->ID);
			printf("上一次缴费年份：");
			scanf("%d",&k->last_year);
			printf("月份：");
			scanf("%d",&k->last_month);
			printf("缴费金额：");
			scanf("%f",&k->money);
			printf("修改成功!\n");
		}
} 



void main()//主函数
{ 
	int m; 
	do { 
		m=mainmenu(); 
		switch(m) 
			{ 
				case 1: xinximenu();
					break; 
				case 2: tongjimenu();
					break; 
				case 3:printf("*****************************谢谢使用，再见!***********************************\n"); exit(0); 
			} 
		} while(1); 
}

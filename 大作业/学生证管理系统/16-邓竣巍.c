#include<stdio.h>
#include<string.h>

struct student
   {long int classNo;
	char name[20];
	int Sex;
	char ID[20];
	long int birth;};
int n;
int load(struct student stud[]);
int choice();
void Input(struct student stud[]);
void One(struct student stud[]);
void Class(struct student stud[]);
void Revise(struct student stud[]);
void Delete(struct student stud[]);
void Count(struct student stud[]);
void menu();

void main()
{menu();}

void menu()
{	struct student stud[1000];
	int c;
	do	{c=choice();
		switch(c) 
			{case 1:Input(stud);break;
			 case 2:One(stud);break;
			 case 3:Class(stud);break;
			 case 4:Revise(stud);break;
			 case 5:Delete(stud);break;
			 case 6:Count(stud);break;}
		}while(c);
}
int load(struct student stud[])
{
	FILE *fp;
	int t=0,i,j;
	fp=fopen("stud_list.txt","r");
    for(i=0;i<1000;i++)
	{j=fscanf(fp,"%ld %s %d %s %ld",&stud[i].classNo,
		stud[i].name,&stud[i].Sex,stud[i].ID,&stud[i].birth);
	  if(j!=5) break;
      t=t+1;}return(t);fclose(fp);
	}
	
int choice()
{  int c;
      do{printf("\t\t***********欢迎进入学生证管理系统*************\n\n");
		printf("\t\t**1. 学生信息录入.**********\n");
		printf("\t\t**2. 按单个学生查询信息.****\n");
		printf("\t\t**3. 按班级查询信息.********\n");
		printf("\t\t**4. 按学号修改信息.********\n");
		printf("\t\t**5. 按学号删除信息.********\n");
		printf("\t\t**6. 统计.******************\n");
		printf("\t\t请选择您所需的功能代号.按 enter 键继续.\n\n");
		scanf("%d",&c);}
      while(c<1||c>6);
      return c;
}


void Input(struct student stud[])			/*录入学生信息*/
{	FILE *fp;
    int i,t;               
    n=load(stud);
	if((fp=fopen("stud_list.txt","a"))==NULL)
       {printf("不能打开文件\n");
		exit(0);}
    printf("\t请输入您要录入的学生人数.\n");
    scanf("%d",&t);
    for(i=n;i<(n+t);i++)
	{printf("\n\t请输入学生班级序号. 按 enter 键继续.\n");
	scanf("%ld",&stud[i].classNo);
	printf("\t请输入学生姓名.按 enter 键继续.\n");
	scanf("%s",&stud[i].name);
	printf("\t请输入学生性别: 0代表男，1代表女 \n\t."); 
	scanf("%d",&stud[i].Sex);
	printf("\t请输入学生出生年月. 按 enter 键继续.\n");
	scanf("%ld",&stud[i].birth);
	printf("\t请输入学生学号. 按 enter 键继续.\n\t学号为11位.");
	scanf("%s",&stud[i].ID);
	printf("\t保存成功!\n");
    fprintf(fp,"%ld %s %d %s %ld\n",stud[i].classNo,
		stud[i].name,stud[i].Sex,stud[i].ID,stud[i].birth);
	}

    fclose(fp);
}


void One(struct student stud[])					/* 查询某人的学生证信息*/
{	FILE *fp;	
	int i;
	char a[20];
	printf("\t请输入要查询的学生学号, 按 enter 键继续.\n");
	scanf("%s",a);
	
   
	fp=fopen("stud_list.txt","r");
    n=load(stud);
    for(i=0;i<n;i++)	
	{fscanf(fp,"%s%d%ld%s%ld",stud[i].name,&stud[i].Sex,
		&stud[i].classNo,stud[i].ID,&stud[i].birth);}

	for(i=0;i<n;i++)
	{if(strcmp(a,stud[i].ID)==0)
		{printf("\t\t学号: %s\n",stud[i].ID);
		printf("\t\t姓名: %s\n",stud[i].name);
		if(stud[i].Sex==0)printf("\t\t性别: M.\n");
		if(stud[i].Sex==1)printf("\t\t性别: F.\n");
		printf("\t\t出生日期: %ld\n",stud[i].birth);
		printf("\t\t班级序号: %ld\n",stud[i].classNo);
		fclose(fp);
		return;}
      if (i==n)
			printf("未找到此学生信息.");
	}
	fclose(fp);
}


void Class(struct student stud[])				/*显示某班的学生证信息*/
{	FILE *fp;
	int i,count=0;	long int a;

	printf(" 请输入您要查询的班号, 按 enter 键继续.\n");
	scanf("%ld",&a);
    n=load(stud);
	fp=fopen("stud_list.txt","r");
	
	for(i=0;i<n;i++)
	{	if(a==stud[i].classNo)
		{printf("\t\t\t\t=%d=\n",i+1);
		printf("\t班级序号: %ld\n",stud[i].classNo);
		printf("\t学号: %s\n",stud[i].ID);
		printf("\t姓名: %s\n",stud[i].name);
		if(stud[i].Sex==0)printf("\t性别: M.\n");
		if(stud[i].Sex==1)printf("\t性别: F.\n");
		printf("\t出生日期: %ld\n\n",stud[i].birth);
		count++;}
	}		
	printf("\t此班有 %d 名学生 %ld.\n\n",count,a);
	fclose(fp);
}

void Revise(struct student stud[])			/*修改某人的学生证信息*/
   {FILE *fp;
    int i,a;	struct student t;
     n=load(stud);
	printf("\tP请输入您要修改的学生学号, 按 enter 键继续.\n");
    scanf("%s",&a);

	fp=fopen("stud_list.txt","r");
    for(i=0;i<=n;i++)
	{fscanf(fp,"%s%d%ld%s%ld",stud[i].name,stud[i].Sex,
		stud[i].classNo,stud[i].ID,stud[i].birth);}

	{printf("\t班级序号: ");
	scanf("%ld",&t.classNo);
	printf("\t姓名: ");
	scanf("%s",t.name);
	printf("\t性别: ");
	scanf("%d",&t.Sex);
	printf("\t出生日期: ");
	scanf("%ld",&t.birth);
	printf("\n信息已被修改\n");}

      for(i=0;i<n;i++)
       {if(strcmp(a,stud[i].ID)==0)
          {strcpy(stud[i].name,t.name);
           stud[i].Sex=t.Sex;
           stud[i].birth=t.birth;
           stud[i].classNo=t.classNo;}
       return;} 
  fclose(fp);
}
     
 
void Delete(struct student stud[])			/*删除某人的学生证信息*/
	{int i,a,b;FILE *fp;
     n=load(stud);
	printf("\t请输入您要删除的学生学号, 按 enter 键继续.\n");
	scanf("%s",&a);

	fp=fopen("stud_list.txt","w");

	for(i=0;i<n;i++)
	{fscanf(fp,"%s%d%ld%s%ld",stud[i].name,stud[i].Sex,
		stud[i].classNo,stud[i].ID,stud[i].birth);}

	for(i=0;i<n;i++)	{if(strcmp(a,stud[i].ID)==0)	b=i;}
    fclose(fp);

	fp=fopen("stud_list.txt","w");
	for(i=0;i<n;i++)
	{if(i!=b)
    fwrite(&stud[i],sizeof(struct student),1,fp);}
	fclose(fp);

	printf("\t\t信息已被删除.");
 
} 

void Count(struct student stud[])			/*统计功能*/
{	int a;
	void MF(),Cla(),Y();
      do
		{printf("\t\t1. 统计男女生人数.\n" );
		printf("\t\t2. 统计某班人数.\n");
		printf("\t\t3. 统计某年出生的学生人数.\n");
		printf("\t\t4. 返回.\n\n");
		printf("\t请选择您所需的功能号.\n\t按 enter 键继续.\n\n");
		scanf("%d",&a);}
      while(a<1||a>5);

	  switch(a)
		{case 1:MF(stud);break;
		case 2:Cla(stud);break;
		case 3:Y(stud);break;
		case 4:break;}
}

void MF(struct student stud[])			/*统计男女生人数*/
{	FILE *fp;int count=0,i;
 n=load(stud);
	fp=fopen("stud_list.txt","r");
	for(i=0;i<n;i++)
	{fscanf(fp,"%s%d%ld%s%ld",stud[i].name,stud[i].Sex,
		stud[i].classNo,stud[i].ID,stud[i].birth);}

	for(i=0;i<n;i++)	{if(!stud[i].Sex)	count++;}
	fclose(fp);
	printf("有 %d 名男生和 %d 名女生.",count,n-count);
}

void Cla(struct student stud[])			/*统计某班的人数*/
{	int i,a,count=0;FILE *fp;
	printf("\t请输入您要统计的班号. 按 enter 键继续.\n");
	scanf("%ld",&a);
 n=load(stud);
	fp=fopen("stud_list.txt","r");
	for(i=0;i<n;i++)
	{fscanf(fp,"%s%d%ld%s%ld",stud[i].name,stud[i].Sex,
		stud[i].classNo,stud[i].ID,stud[i].birth);}

	for(i=0;i<n;i++)	{if(a==stud[i].classNo/100)	count++;}
	fclose(fp);

	switch(count)
	{case 0:printf("此班没有学生.\n\n");break;
	case 1:printf("此班有一名学生.\n\n");break;
	default:printf("此班有 %d 名学生.\n\n",count);break;}
}


void Y(struct student stud[])			/*统计某年出生的人数*/
{	int i,a,count=0;FILE *fp;
	 n=load(stud);
printf("\t请输入您要统计的年份. 按 enter 键继续.\n");
	scanf("%d",&a);
	fp=fopen("stud_list.txt","r");
	for(i=0;i<n;i++)
	{fscanf(fp,"%s%d%ld%s%ld",stud[i].name,stud[i].Sex,
		stud[i].classNo,stud[i].ID,stud[i].birth);}
	for(i=0;i<n;i++)	{if(a==stud[i].birth/10000)		count++;}
	fclose(fp);

	switch(count)
	{case 0:printf("此年没有学生出生 %d.\n\n",a);
	case 1:printf("此年有一名学生出生 %d.\n\n",a);
	default:printf("此年有 %d 名学生出生 %d.\n\n",count,a);}
}
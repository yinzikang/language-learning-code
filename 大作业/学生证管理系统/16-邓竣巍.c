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
      do{printf("\t\t***********��ӭ����ѧ��֤����ϵͳ*************\n\n");
		printf("\t\t**1. ѧ����Ϣ¼��.**********\n");
		printf("\t\t**2. ������ѧ����ѯ��Ϣ.****\n");
		printf("\t\t**3. ���༶��ѯ��Ϣ.********\n");
		printf("\t\t**4. ��ѧ���޸���Ϣ.********\n");
		printf("\t\t**5. ��ѧ��ɾ����Ϣ.********\n");
		printf("\t\t**6. ͳ��.******************\n");
		printf("\t\t��ѡ��������Ĺ��ܴ���.�� enter ������.\n\n");
		scanf("%d",&c);}
      while(c<1||c>6);
      return c;
}


void Input(struct student stud[])			/*¼��ѧ����Ϣ*/
{	FILE *fp;
    int i,t;               
    n=load(stud);
	if((fp=fopen("stud_list.txt","a"))==NULL)
       {printf("���ܴ��ļ�\n");
		exit(0);}
    printf("\t��������Ҫ¼���ѧ������.\n");
    scanf("%d",&t);
    for(i=n;i<(n+t);i++)
	{printf("\n\t������ѧ���༶���. �� enter ������.\n");
	scanf("%ld",&stud[i].classNo);
	printf("\t������ѧ������.�� enter ������.\n");
	scanf("%s",&stud[i].name);
	printf("\t������ѧ���Ա�: 0�����У�1����Ů \n\t."); 
	scanf("%d",&stud[i].Sex);
	printf("\t������ѧ����������. �� enter ������.\n");
	scanf("%ld",&stud[i].birth);
	printf("\t������ѧ��ѧ��. �� enter ������.\n\tѧ��Ϊ11λ.");
	scanf("%s",&stud[i].ID);
	printf("\t����ɹ�!\n");
    fprintf(fp,"%ld %s %d %s %ld\n",stud[i].classNo,
		stud[i].name,stud[i].Sex,stud[i].ID,stud[i].birth);
	}

    fclose(fp);
}


void One(struct student stud[])					/* ��ѯĳ�˵�ѧ��֤��Ϣ*/
{	FILE *fp;	
	int i;
	char a[20];
	printf("\t������Ҫ��ѯ��ѧ��ѧ��, �� enter ������.\n");
	scanf("%s",a);
	
   
	fp=fopen("stud_list.txt","r");
    n=load(stud);
    for(i=0;i<n;i++)	
	{fscanf(fp,"%s%d%ld%s%ld",stud[i].name,&stud[i].Sex,
		&stud[i].classNo,stud[i].ID,&stud[i].birth);}

	for(i=0;i<n;i++)
	{if(strcmp(a,stud[i].ID)==0)
		{printf("\t\tѧ��: %s\n",stud[i].ID);
		printf("\t\t����: %s\n",stud[i].name);
		if(stud[i].Sex==0)printf("\t\t�Ա�: M.\n");
		if(stud[i].Sex==1)printf("\t\t�Ա�: F.\n");
		printf("\t\t��������: %ld\n",stud[i].birth);
		printf("\t\t�༶���: %ld\n",stud[i].classNo);
		fclose(fp);
		return;}
      if (i==n)
			printf("δ�ҵ���ѧ����Ϣ.");
	}
	fclose(fp);
}


void Class(struct student stud[])				/*��ʾĳ���ѧ��֤��Ϣ*/
{	FILE *fp;
	int i,count=0;	long int a;

	printf(" ��������Ҫ��ѯ�İ��, �� enter ������.\n");
	scanf("%ld",&a);
    n=load(stud);
	fp=fopen("stud_list.txt","r");
	
	for(i=0;i<n;i++)
	{	if(a==stud[i].classNo)
		{printf("\t\t\t\t=%d=\n",i+1);
		printf("\t�༶���: %ld\n",stud[i].classNo);
		printf("\tѧ��: %s\n",stud[i].ID);
		printf("\t����: %s\n",stud[i].name);
		if(stud[i].Sex==0)printf("\t�Ա�: M.\n");
		if(stud[i].Sex==1)printf("\t�Ա�: F.\n");
		printf("\t��������: %ld\n\n",stud[i].birth);
		count++;}
	}		
	printf("\t�˰��� %d ��ѧ�� %ld.\n\n",count,a);
	fclose(fp);
}

void Revise(struct student stud[])			/*�޸�ĳ�˵�ѧ��֤��Ϣ*/
   {FILE *fp;
    int i,a;	struct student t;
     n=load(stud);
	printf("\tP��������Ҫ�޸ĵ�ѧ��ѧ��, �� enter ������.\n");
    scanf("%s",&a);

	fp=fopen("stud_list.txt","r");
    for(i=0;i<=n;i++)
	{fscanf(fp,"%s%d%ld%s%ld",stud[i].name,stud[i].Sex,
		stud[i].classNo,stud[i].ID,stud[i].birth);}

	{printf("\t�༶���: ");
	scanf("%ld",&t.classNo);
	printf("\t����: ");
	scanf("%s",t.name);
	printf("\t�Ա�: ");
	scanf("%d",&t.Sex);
	printf("\t��������: ");
	scanf("%ld",&t.birth);
	printf("\n��Ϣ�ѱ��޸�\n");}

      for(i=0;i<n;i++)
       {if(strcmp(a,stud[i].ID)==0)
          {strcpy(stud[i].name,t.name);
           stud[i].Sex=t.Sex;
           stud[i].birth=t.birth;
           stud[i].classNo=t.classNo;}
       return;} 
  fclose(fp);
}
     
 
void Delete(struct student stud[])			/*ɾ��ĳ�˵�ѧ��֤��Ϣ*/
	{int i,a,b;FILE *fp;
     n=load(stud);
	printf("\t��������Ҫɾ����ѧ��ѧ��, �� enter ������.\n");
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

	printf("\t\t��Ϣ�ѱ�ɾ��.");
 
} 

void Count(struct student stud[])			/*ͳ�ƹ���*/
{	int a;
	void MF(),Cla(),Y();
      do
		{printf("\t\t1. ͳ����Ů������.\n" );
		printf("\t\t2. ͳ��ĳ������.\n");
		printf("\t\t3. ͳ��ĳ�������ѧ������.\n");
		printf("\t\t4. ����.\n\n");
		printf("\t��ѡ��������Ĺ��ܺ�.\n\t�� enter ������.\n\n");
		scanf("%d",&a);}
      while(a<1||a>5);

	  switch(a)
		{case 1:MF(stud);break;
		case 2:Cla(stud);break;
		case 3:Y(stud);break;
		case 4:break;}
}

void MF(struct student stud[])			/*ͳ����Ů������*/
{	FILE *fp;int count=0,i;
 n=load(stud);
	fp=fopen("stud_list.txt","r");
	for(i=0;i<n;i++)
	{fscanf(fp,"%s%d%ld%s%ld",stud[i].name,stud[i].Sex,
		stud[i].classNo,stud[i].ID,stud[i].birth);}

	for(i=0;i<n;i++)	{if(!stud[i].Sex)	count++;}
	fclose(fp);
	printf("�� %d �������� %d ��Ů��.",count,n-count);
}

void Cla(struct student stud[])			/*ͳ��ĳ�������*/
{	int i,a,count=0;FILE *fp;
	printf("\t��������Ҫͳ�Ƶİ��. �� enter ������.\n");
	scanf("%ld",&a);
 n=load(stud);
	fp=fopen("stud_list.txt","r");
	for(i=0;i<n;i++)
	{fscanf(fp,"%s%d%ld%s%ld",stud[i].name,stud[i].Sex,
		stud[i].classNo,stud[i].ID,stud[i].birth);}

	for(i=0;i<n;i++)	{if(a==stud[i].classNo/100)	count++;}
	fclose(fp);

	switch(count)
	{case 0:printf("�˰�û��ѧ��.\n\n");break;
	case 1:printf("�˰���һ��ѧ��.\n\n");break;
	default:printf("�˰��� %d ��ѧ��.\n\n",count);break;}
}


void Y(struct student stud[])			/*ͳ��ĳ�����������*/
{	int i,a,count=0;FILE *fp;
	 n=load(stud);
printf("\t��������Ҫͳ�Ƶ����. �� enter ������.\n");
	scanf("%d",&a);
	fp=fopen("stud_list.txt","r");
	for(i=0;i<n;i++)
	{fscanf(fp,"%s%d%ld%s%ld",stud[i].name,stud[i].Sex,
		stud[i].classNo,stud[i].ID,stud[i].birth);}
	for(i=0;i<n;i++)	{if(a==stud[i].birth/10000)		count++;}
	fclose(fp);

	switch(count)
	{case 0:printf("����û��ѧ������ %d.\n\n",a);
	case 1:printf("������һ��ѧ������ %d.\n\n",a);
	default:printf("������ %d ��ѧ������ %d.\n\n",count,a);}
}
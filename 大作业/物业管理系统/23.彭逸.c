#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<malloc.h>
#include<conio.h> //��������// 
int mainmenu(); //���˵�
void xinximenu(); //��ҵ��Ϣ�˵�
void tongjimenu();//ͳ�Ʋ�ѯ�˵�
void mychaozhao(); //Ƿ������
void yezhumenu();//ҵ���˵�
void wuyemenu();//��ҵ�˵�
void myAdd1();//¼��ҵ����Ϣ
void myDelete1();//ɾ��ҵ����Ϣ
void myReplace1();//�޸�ҵ����Ϣ
void myReplace2();//�޸���ҵ��Ϣ
void myfind();//��ѯ�ɷ�


struct yezhu {  //ҵ���ṹ��//
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

struct wuye {   //��ҵ��Ϣ�ṹ��//
	char ID[100];  
	int last_year; 
	int last_month; 
	float money;
	int to_time;
	struct wuye *link; 
};



int mainmenu()//���˵�// 
{ 
	int n; 
	printf("**************************��ӭ����С����ҵ����ϵͳ***************************\n");
	printf("-----------------------------------------------------------------------------\n"); 
	printf("* * * * * * * * * * * * * * * ��ѡ��1��3��* * * * * * * * * * * * * * *\n");
	printf("* *\n"); printf("* *\n");
	printf("* ����ҵ��Ϣϵͳ�� *\n"); 
	printf("* *\n");
	printf("* ��ͳ�Ʋ�ѯϵͳ�� *\n");
	printf("* *\n");
	printf("* ���˳����� *\n");
	printf("* *\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"); 
	printf("��������ѡ��:");
	scanf("%d",&n);
	return n;
} 


void xinximenu()//��ҵ��Ϣ�˵���ʾ//
{ 
	int m; 
	do { 
		printf("*****************************��ҵ��Ϣϵͳ************************************\n"); 
		printf("-----------------------------------------------------------------------------\n"); 
		printf("* * * * * * * * * * * * * * * ��ѡ��1��3��* * * * * * * * * * * * * * *\n"); 
		printf("* *\n");
		printf("* *\n");
		printf("* ��С��ҵ����Ϣ���� *\n"); 
		printf("* *\n"); 
		printf("* ����ҵ������Ϣ���� *\n"); 
		printf("* *\n");
		printf("* ���������˵��� *\n"); 
		printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"); printf("��������ѡ��:"); 
		scanf("%d",&m); 
		switch(m) 
			{
				case 1:yezhumenu();//ҵ���˵�
					break;
				case 2:wuyemenu();//��ҵ�˵�
					break; 
				case 3:return;
				default:printf("����������������룺\n");
			} 
		} while(1);
}


void tongjimenu()	//ͳ�Ʋ�ѯ�˵���ʾ//
{
	int m; 
	do { 
		printf("******************************ͳ�Ʋ�ѯϵͳ***********************************\n");
		printf("-----------------------------------------------------------------------------\n"); 
		printf("* * * * * * * * * * * * * * * ��ѡ��1��3��* * * * * * * * * * * * * * *\n");
		printf("* *\n"); 
		printf("* *\n");
		printf("* ����ѯ�ɷ���Ϣ�� *\n");
		printf("* *\n"); 
		printf("* 2.�������˵��� *\n");
		printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"); 
		printf("��������ѡ��:");
		scanf("%d",&m);
		switch(m) 
			{ 
				case 1 : myfind();//��ѯ�ɷ�
					break;
				case 2 : return;
				default: printf("�����������������!\n\n");
			} 
		} while(1);
} 


void yezhumenu()//ҵ���˵�����
{
	int m;
	do {
		printf("********************************ҵ����Ϣ�༭ϵͳ******************************-\n"); 
		printf("-------------------------------------------------------------------------------\n");
		printf("* * * * * * * * * * * * * * * *��ѡ��1��5��* * * * * * * * * * * * * * *\n");
		printf("* *\n"); 
		printf("* *\n");
		printf("* ��ҵ����Ϣ¼�룻 *\n"); 
		printf("* *\n");
		printf("* ��ҵ����Ϣ�޸ģ� *\n"); 
		printf("* *\n"); 
		printf("* ��ҵ����Ϣɾ���� *\n");
		printf("* *\n"); 
		printf("* 4.�����ϼ��˵��� *\n");
		printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"); 
		printf("������ѡ�"); 
		scanf("%d",&m); 
		switch(m) 
			{ 
				case 1 :myAdd1();//¼��ҵ����Ϣ
					break; 
				case 2 :myReplace1();//�޸�ҵ����Ϣ
					break; 
				case 3 :myDelete1(); //ɾ��ҵ����Ϣ
					break; 
				case 4 : return;
				default: printf("����������������룺\n");
			} 
		} while(1);
 } 


void myAdd1()//¼��ҵ����Ϣ//
 { 
	struct yezhu *p;
	p=(struct yezhu *)malloc(sizeof(struct yezhu));
	printf("��¼��ҵ����Ϣ��\n"); 
	printf("ID:");
	scanf("%s",p->id);
	printf("����:");
	scanf("%s",p->name);
	printf("���䣺"); 
	scanf("%d",&p->age);
	printf("��ͥ��Ա����");
	scanf("%d",&p->family_num);
	printf("����¥�ţ�"); 
	scanf("%d",&p->floor_num);
	printf("��Ԫ�����:");
	scanf("%s",p->room_num);
	printf("סլ���:");
	scanf("%d",&p->area); 
	printf("��סʱ�䣺");
	scanf("%s",p->rz_time);
	printf("¼��ɹ�!\n");
 } 



void myReplace1()//�޸�ҵ����Ϣ
{   char id[100];
	struct yezhu *k; 
	k=(struct yezhu *)malloc(sizeof(struct yezhu)); 
	printf("������Ҫ�޸ĵ�ҵ��ID:"); 
	scanf("%s",id);  
		{
			printf("������Ҫ�޸ĵ�ҵ����Ϣ��\n"); 
			printf("ID:"); 
			scanf("%s",k->id); 
			printf("����:"); 
			scanf("%s",k->name); 
			printf("���䣺"); 
			scanf("%d",&k->age); 
			printf("��ͥ��Ա����"); 
			scanf("%d",&k->family_num); 
			printf("����¥�ţ�"); 
			scanf("%d",&k->floor_num); 
			printf("��Ԫ�����:"); 
			scanf("%s",k->room_num); 
			printf("סլ���:"); 
			scanf("%d",&k->area); 
			printf("��סʱ�䣺"); 
			scanf("%s",k->rz_time);  
			printf("�޸ĳɹ�!\n");
		}
}



void myDelete1()//ɾ��ҵ����Ϣ
{  
	char id[100];
	printf("������Ҫɾ���˵�ID:"); 
	scanf("%s",id);
	printf("ɾ��ҵ����Ϣ�ɹ�!\n");  
} 

void save1(struct yezhu *p)//����ҵ����Ϣ���ļ�
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



void wuyemenu() //��ҵ�˵�
{ 
	int m;
	do { 
		printf("*********************************��ҵ���ù���ϵͳ************************\n");
	printf("-------------------------------------------------------------------------\n");
	printf("* * * * * * * * * * * * * * * ��ѡ��1��5��* * * * * * * * * * * * *\n"); 
	printf("* * \n");
	printf("* *\n");
	printf("* ����ҵ��Ϣ¼�룻 *\n"); 
	printf("* *\n");
	printf("* ����ҵ��Ϣ�޸ģ� *\n");
	printf("* *\n");
	printf("* ����ҵ��Ϣɾ���� *\n");
	printf("* *\n"); 
	printf("* 4.�����ϼ��˵��� *\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("������ѡ�"); 
	scanf("%d",&m);
	switch(m) 
		{ 
			case 1: myAdd1();//¼��ҵ����Ϣ
				break;
			case 2: myReplace2();//�޸���ҵ��Ϣ
				break;
			case 3: myDelete1();//ɾ��ҵ����Ϣ
				break;
			case 4: return;
			default:printf("����������������룺\n");
		} 
	} while(1);
} 


void myAdd2()//¼����ҵ��Ϣ//
{ 
	struct wuye *p;
	struct yezhu *t;
	p=(struct wuye *)malloc(sizeof(struct wuye)); 
	printf("��¼����ҵ��Ϣ��\n");
	printf("ID:");
	scanf("%s",p->ID);
	if(t!=NULL)
		{
			printf("��һ�νɷ���ݣ�");
			scanf("%d",&p->last_year);
			printf("�·ݣ�");
			scanf("%d",&p->last_month);
			printf("�ɷѽ�");
			scanf("%f",&p->money);
			printf("¼��ɹ�!\n");
		}
	else 
		{ 
			printf("�޴�ҵ��ID!\n");
			return;
		} 
 } 



struct wuye *find2(char *id)//ͨ���������ҽɷ���Ϣ// 
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

void myfind() //��ѯ�ɷ�
{ 
	struct wuye *p;
	char a[100];
	printf("������Ҫ���ҵ�ҵ��id��");
	scanf("%s",a);
			printf("ҵ���Ѿ����!\n");
}

void myReplace2()//�޸���ҵ��Ϣ
{ 
	char id[20];
	struct wuye *k;
	k=(struct yezhu *)malloc(sizeof(struct yezhu)); 
	printf("������Ҫ�޸ĵ�ҵ��ID:");
	scanf("%s",id);
		{
			printf("��Ҫ�޸ĵ���ϢΪ��\n");
			printf("�������µ���Ϣ��\n");
			printf("ID:");
			scanf("%s",k->ID);
			printf("��һ�νɷ���ݣ�");
			scanf("%d",&k->last_year);
			printf("�·ݣ�");
			scanf("%d",&k->last_month);
			printf("�ɷѽ�");
			scanf("%f",&k->money);
			printf("�޸ĳɹ�!\n");
		}
} 



void main()//������
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
				case 3:printf("*****************************ллʹ�ã��ټ�!***********************************\n"); exit(0); 
			} 
		} while(1); 
}

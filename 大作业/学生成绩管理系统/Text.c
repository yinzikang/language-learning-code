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
		printf("\t\t��ѡ��1-7��:\n");
		printf("\t\t======================================================\n"); printf("\t\t\t 1.��ѯѧ���ɼ���¼\n");
		printf("\t\t\t 2.�޸�ѧ���ɼ���¼\n");
		printf("\t\t\t 3.���ѧ���ɼ���¼\n");
		printf("\t\t\t 4.ɾ��ѧ���ɼ���¼\n");
		printf("\t\t\t 5.����ѧ���ɼ���¼\n");
		printf("\t\t\t 6.�ɼ�����\n");
		printf("\t\t\t 7.�˳�\n");
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
		printf("\n\n\t ѧ���ɼ������ļ��޷��򿪣���Ϊ�գ�");
	printf("\n\n\t ��������������˵�.......");
	getch();
	return;
	}
	else 
	{
		n++; 
		while(fread(&chengji[n],sizeof(chengji[n]),1,file) == 1)
			n++;
		fclose(file); 
		printf("\n\n\tѧ���ɼ����ݶ�ȡ���\n",n);
		n--; 
	}
}

void write()
{
	FILE *file; 
	if(n == -1) 
	{
		
		printf(" û�����ݿɴ棡��������������˵� \n");
		getch();
		return;
	}
	if((file=fopen("cj.dat","wb"))!=NULL)
		
	{
		fwrite(&chengji[0],sizeof(chengji[0]),n+1,file); 
		fclose(file); 
		printf("\n\n\t\t%d��ѧ����¼������ϣ�\n",n+1);
	}
	else 
		printf("\t\t�޷���ѧ���ɼ������ļ���\n");
	printf("\n\t\t��������������˵�...... ");
	getch();
}

void find()
{
	char xuehao[10]; 
	int i; 
	if(n==-1) 
	{
		printf("\n\n\t\t��ǰ��û��ѧ���ɼ�����������������˵�......");
		getch();
		return;
	}
	printf("\t������ѧ��ѧ��:"); 
	gets(xuehao); 
	for(i=0;i<=n;i++) 
	{
		if(strcmp(chengji[i].xuehao,xuehao)==0) 
		{
			printf("\n ��ѧ���ɼ��������:");
			printf("\n===================\n\n");
			printf("   ѧ�� ����");
			printf("    Ӣ��     C����    �ߵ���ѧ ƽ���ɼ�\n"); printf("%6s%6s",chengji[i].xuehao,chengji[i].name);
			printf("%9.2f%9.2f%9.2f%9.2f",chengji[i].cyuyan,chengji[i].math,chengji[i].english,chengji[i].average);
			printf("\n ��������������˵�......");
			getch();
			break;
		}
	}
	if(i==n+1)
	{
		printf("\n\t\t���������ѧ��ѧ������򲻴���!");
		printf("��������������˵�......");
		getch();
		return;
	}
}
void list()
{
	int i;
	system("cls");
	printf("\n\n\t\t\t ȫ��ѧ���ɼ��������\n");
	printf("\t\t\t===========================\n\n");
	printf("ѧ��    ���� ");
	printf("Ӣ��    C����  �ߵ���ѧ   ƽ���ɼ�");
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
		printf("\n\n\t\t��ǰ��û��ѧ���ɼ���¼����������������˵�......");
		
		getch( );
		return;
	}
	printf("\t������ѧ��ѧ��:"); 
	gets(xuehao); 
	for (i=0;i<=n;i++) 
	{
		if(strcmp(chengji[i].xuehao,xuehao)==0) 
		{
			
			printf("\n\t\t\t ��ѧ���ɼ��������: ");
			printf("\n\t\t\t===================\n\n");
			printf("   ѧ�� ����");
			printf("    Ӣ��     C����    �ߵ���ѧ ƽ���ɼ�\n"); printf("%6s%6s",chengji[i].xuehao,chengji[i].name);
			printf("%9.2f%9.2f%9.2f%9.2f",chengji[i].cyuyan,chengji[i].math,chengji[i].english,chengji[i].average);
			printf("\n\t\t �������ѧ���µ�Ӣ��ɼ�: ");
			scanf ("%f",&chengji[i].cyuyan);
			printf("\n\t\t �������ѧ���µ�C���Գɼ�: ");
			scanf ("%f",&chengji[i].math);
			printf("\n\t\t �������ѧ���µĸߵ���ѧ�ɼ�: ");
			scanf ("%f",&chengji[i].english);
			chengji[i].average=(chengji[i].cyuyan+chengji[i].math+chengji[i].english)/3; 
			printf("\n\t\t\t ��ѧ���ɼ���: %f",chengji[i].average);
			printf("\n\n\t\t ��ѧ���ɼ������޸ĳɹ�! ��������������˵�......");
			getch();
			return ;
		}
	}
	printf("\n\t\t ���������ѧ��ѧ������򲻴���! ");
	
	printf("��������������˵�......");
	getch();
	return;
}

void add()
{
	printf ("\t������ѧ��ѧ�ţ�");
	fflush(stdin); 
	gets(chengji[++n].xuehao);
	printf("\t\t\t\t������ѧ��������");
	gets(chengji[n].name);
	printf("\t\t\t\t�������ѧ����Ӣ��ɼ���");
	scanf("%f",&chengji[n].cyuyan);
	printf("\t\t\t\t�������ѧ����C���Գɼ���");
	scanf("%f",&chengji[n].math);
	printf("\t\t\t\t�������ѧ���ĸߵ���ѧ�ɼ���");
	scanf("%f",&chengji[n].english);
	chengji[n].average=(chengji[n].cyuyan+chengji[n].math+chengji[n].english)/3; /*�������*/
	printf("\n\t\t\t\t��ѧ���ɼ�Ϊ:%f",chengji[n].average);
	printf("\n\n\t\t\t\t�����������......");
	getch();
}
void del()
{
	char xuehao[10]; 
	int i,j; 
	char d; 
	printf("\t�������ɾ��ѧ��ѧ�ţ�");
	gets(xuehao);
	for(i=0;i<=n;i++)  {
		if(strcmp(chengji[i].xuehao,xuehao)==0) 
		{
			printf("\n\t\t��ȷ��Ҫɾ��%s��ѧ���ɼ���Ϣô(y/n)?",chengji[i].xuehao );
			
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
				printf("\n\n\t\t��ѧ����¼�ɹ�ɾ������������������˵�......"); getch();
				break;
			}
			else 
			{
				printf("\n\n\t\t��ѡ���˲�ɾ����ѧ����¼����������������˵�......");
				getch();
				return;
			}
		}
	}
	if(i == n+1)  {
		printf("\n\t\t���༶�޴�ѧ�ţ���������������˵�......");
		getch();
	}
}

void rank()
{
	
	int i,j; 
	printf("\t��ƽ���ɼ���������\n");
	for (i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if (chengji[i].average>chengji [j].average)
			{*p=chengji[j];chengji[j]=chengji[i];chengji[i]=*p;}
			printf("%-6s%-6s","ѧ��","����");
			printf("%-12s%-6s%12s%-9s\n","    Ӣ��"," C����","�ߵ���ѧ","ƽ���ɼ�"); 
			for(i=0;i<=n;i++)
			{
				printf("%-6s%-6s",chengji[i].xuehao,chengji[i].name);
				printf("%9.2f%9.2f%9.2f%9.2f\n",chengji[i].cyuyan,chengji[i].math,chengji[i].english,chengji[i].average);
			}
			printf("\n\n\t\t\t\t�����������......");
			getch();
}
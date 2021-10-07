#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include"malloc.h"
void prin1();
void choose();
typedef struct subjects
{
	 int num;                 //�γ̱��//
	 char name[20];           //�γ�����//
	 char kind[10];           //�γ�����//
	 int stime;               //��ѧʱ//
	 int ttime;               //�ڿ�ѧʱ//
	 int etime;               //ʵ����ϻ�ѧʱ//
	 int score;               //ѧ��//
	 int term;                //����ѧ��//
	 struct subjects *next;
}SUB;

SUB *head=NULL;

SUB *create_form()          //�������� //
{
	 SUB *head,*tail,*p;
	 int num,stime,ttime;
	 int etime,score,term;
	 char name[20],kind[10];
	 int size=sizeof(SUB);
	 head=tail=NULL;
	 printf("����ѡ�޿γ���Ϣ:\n");
	 scanf("%d%s%s%d%d%d%d%d",&num,name,kind,&stime,&ttime,&etime,&score,&term);
	while(num!=0)
	{
		  p=(SUB *)malloc(size);
		  p->num=num;
		  strcpy(p->name,name);
		  strcpy(p->kind,kind);
		  p->stime=stime;
		  p->ttime=ttime;
		  p->etime=etime;
		  p->score=score;
		  p->term=term;
		 if(head==NULL)
			 head=p;
		 else
			 tail->next=p;
		 tail=p;
		 scanf("%d%s%s%d%d%d%d%d",&num,name,kind,&stime,&ttime,&etime,&score,&term);
	 }
	 tail->next=NULL;
	 return head;
}



void savefile()         //�����ļ� //
{
	 SUB *p;
	 FILE *fp;
	 fp=fopen("2.txt","w");
	 if(fp==NULL)exit(0);
	 printf("�γ̱��  �γ�����  �γ�����  ��ѧʱ  �ڿ�ѧʱ  ʵ����ϻ�ѧʱ  ѧ��  ����ѧ��\n");
	 for(p=head;p;p=p->next)
		fprintf(fp,"%5d%12s%9s%9d%9d%11d%11d%7d\n",p->num,p->name,p->kind,p->stime,p->ttime,p->etime,p->score,p->term);
	 fclose(fp);
	 printf("���������Ϣ�ѷ���'2.txt'�ļ���\n");
	 system("pause");
}

void savefile1()         //�����ļ� //
{
	SUB *p;

	FILE *fp;
	fp=fopen("3.txt","w");
	 if(fp==NULL)exit(0);
	 for(p=head;p;p=p->next)
		fprintf(fp,"%5d%12s%9s%9d%9d%11d%11d%7d\n",p->num,p->name,p->kind,p->stime,p->ttime,p->etime,p->score,p->term);
	 fclose(fp);
	 printf("���������Ϣ�ѷ���'3.txt'�ļ���\n");
	 system("pause"); 
} 


void readfile()                    //�Ķ��ļ� //
{
	void *myInsert(SUB*);
	SUB *newSub;     //�¿γ�//
    int num,stime,ttime,etime;
    int score,term;
    char c,name[20],kind[10],fname[20];
	FILE *fp;
	fp=fopen("2.txt","r");
    while(!feof(fp))
    {
    	newSub=(SUB*)malloc(sizeof(SUB));
		fscanf(fp,"%d%s%s%d%d%d%d%d\n",&newSub->num,newSub->name,newSub->kind,&newSub->stime,&newSub->ttime,&newSub->etime,&newSub->score,&newSub->term);
		myInsert(newSub);
    }
    fclose(fp);
}


void prin()   //������пγ�//
{
	SUB *ptr;
	head=NULL;
	readfile();
	if(head==NULL)
	{
		printf("\n\n\t*********NO RECORDS!************\n");
		return;
	}
	printf("�γ̱��  �γ�����  �γ�����  ��ѧʱ  �ڿ�ѧʱ  ʵ�����ϻ�ѧʱ  ѧ��  ����ѧ��\n");
	for(ptr=head;ptr;ptr=ptr->next)
		{
			printf("%5d%12s%9s%9d%9d%11d%11d%7d\n",ptr->num,ptr->name,ptr->kind,ptr->stime,ptr->ttime,ptr->etime,ptr->score,ptr->term);
		}
	system("pause");
}

void prin1()   //�������ѡ�޿γ�//
{
	SUB *ptr;	
	FILE *fp;
	if((fp=fopen("3.txt","r"))==NULL)
	{
	printf("Cannot open file.\n");
	choose();
	}
	printf("�γ̱��  �γ�����  �γ�����  ��ѧʱ  �ڿ�ѧʱ  ʵ�����ϻ�ѧʱ  ѧ��  ����ѧ��\n");
	while(!feof(fp))
	{
		ptr=(SUB*)malloc(sizeof(SUB));
		fscanf(fp,"%d%s%s%d%d%d%d%d\n",&ptr->num,ptr->name,ptr->kind,&ptr->stime,&ptr->ttime,&ptr->etime,&ptr->score,&ptr->term);
		printf("%5d%12s%9s%9d%9d%11d%11d%7d\n",ptr->num,ptr->name,ptr->kind,ptr->stime,ptr->ttime,ptr->etime,ptr->score,ptr->term);
	}
	system("pause");
}

void *myInsert(SUB *subj)  //����������//  
{
	 SUB *ptr,*ptr2;
	 ptr=subj;
 		if(head==NULL)
 		{
 			head=ptr;
 			head->next=NULL;
 		}
 		else
 		{
 			for(ptr2=head;ptr2;ptr2=ptr2->next)
				if(ptr2->next==NULL)
 				{
 					ptr2->next=subj;
 					subj->next=NULL;
 					break;
 				}
 		}
		return head;
}


void *insert()//����γ���Ϣ //
{
	 SUB *ptr,*subj;
	 int size=sizeof(SUB);
	 char ch,ch1;
	 while(ch!='0')
		{
			  subj=(SUB *)malloc(size);
			  ptr=subj;
			  printf("����Ҫ����Ŀγ���Ϣ:\n");
			  printf("\n\t\t������γ̱��:");scanf("%d",&subj->num);   
			  printf("\n\t\t������γ�����:");scanf("%s",&subj->name);  
			  printf("\n\t\t������γ�����:");scanf("%s",&subj->kind);  
			  printf("\n\t\t��������ѧʱ:");scanf("%d",&subj->stime);
			  printf("\n\t\t�������ڿ�ѧʱ:");scanf("%d",&subj->ttime);
			  printf("\n\t\t������ʵ�����ϻ�ѧʱ:");scanf("%d",&subj->etime);
			  printf("\n\t\t������ѧ��:");scanf("%d",&subj->score);
			  printf("\n\t\t�����뿪��ѧ��:");scanf("%d",&subj->term);
			  myInsert(subj);
			printf("\n������,����Ϣ�����ļ���\n");
			printf("\n���������밴�س�\n");
			printf("\n������ӿγ̰� 0: [ ]\b\b");
			ch1=getchar();                      //���س�������CH1,����subj->term���������Ļس����ḳ��CH,�����CH1���
			ch=getchar();
		}
	 return head;
}



void *del()  //ɾ���γ�//
{
	SUB *p1,*p2;
	char ch,ch1;
	int num;
	while(ch!='0')
	{
		printf("������Ҫɾ���Ŀγ̱��:[    ]\b\b\b\b\b");
		scanf("%d",&num);
		if(head->num==num)
		{
			p2=head;
			head=head->next;
			free(p2);
		}
		if(head==NULL)
			return NULL;
		p1=head;
		p2=head->next;
		while(p2)
		{
			if(p2->num==num)
			{
				p1->next=p2->next;
				free(p2);
			}
			else 
				p1=p2;
			p2=p1->next;
		}
		printf("\n����ɾ���밴�س�\n");
		printf("\n����ɾ���γ̰� 0: [ ]\b\b");
		ch1=getchar();                       //���س�������CH1,����num�����������Ļس����ḳ��CH,�����CH1���//
		ch=getchar();
		printf("\nɾ�����,����Ϣ�����ļ���\n");
		system("pause"); 
	}
	return head;
	system("pause");
}


void choose()//ѡ�¿γ�--ѧ��ѡ�κ���//
{
	SUB *p,*q;
	int a[5];
	int num,total=0,i=0,j;
	printf("����Ҫѡ�޵Ŀγ̵ı��,���֮���Կո�ֿ�\n");
	scanf("%d",&num);
	printf("���ȷ��������Ҫѡ�޵Ŀγ̵ı��,������0: [ ]\b\b");
	while(num!=0)
	{
		for(p=head;p;p=p->next)
		if(p->num==num)
		{
			total=total+p->score;
			a[i]=num;
			i++;
		}
		scanf("%d",&num);
	}
	if(total<60)
	{ 
		printf("ѡ����ѧ��Ϊ%d,δ�ﵽ60,ѡ��ʧ��!\n",total);
		system("pause");
	}
	else
	{
		
		FILE *fp;
		fp=fopen("3.txt","w");
		//	fprintf(fp,"�γ̱��  �γ�����  �γ�����  ��ѧʱ  �ڿ�ѧʱ  ʵ�����ϻ�ѧʱ  ѧ��  ����ѧ��\n");//
		for(j=0;j<i;j++)
		for(q=head;q;q=q->next)
			if(q->num==a[j])
			fprintf(fp,"%5d%12s%9s%9d%9d%11d%11d%7d\n",q->num,q->name,q->kind,q->stime,q->ttime,q->etime,q->score,q->term);
		fclose(fp);
		printf("\t\t\n*****ѡ�޳ɹ�!****\n");
		printf("\n��ѡ�޵Ŀγ���ѧ��Ϊ%d,�γ̷ֱ�Ϊ:\n",total);
		printf("\n�γ̱��  �γ�����  �γ�����  ��ѧʱ  �ڿ�ѧʱ  ʵ�����ϻ�ѧʱ  ѧ��  ����ѧ��\n");
		for(j=0;j<i;j++)
		for(q=head;q;q=q->next)
			if(q->num==a[j])
				printf("%5d%12s%9s%9d%9d%11d%11d%7d\n",q->num,q->name,q->kind,q->stime,q->ttime,q->etime,q->score,q->term);
		printf("\n������Ϣȫ��������'3.txt'��\n");
	}
	system("pause");
}


void search()                        //�γ���Ϣ��ѯ//
{
   int a,num;
   int t=1;
   char type[10],min[10];
   SUB *ptr;
    L1:system("cls");
	printf("\n\n\t\t**********��ѡ���ѯ��ʽ*************\n");
   printf("\n\t\t\t1---���γ����Ʋ���\n");
   printf("\n\t\t\t2---���γ����ʲ���\n");
   printf("\n\t\t\t3---��ѧ�ֲ���\n");
   printf("\n\t\t\t4---�˳�����\n");
   printf("\n\n\t\t**************************************\n");
   printf("\n\nChiose your number(1-4):[ ]\b\b");
   scanf("%d",&a);
   switch(a)
   {
		case 1:printf("������Ҫ���ҵĿγ̵�����:");
			scanf("%s",min);
			printf("�γ̱��  �γ�����  �γ�����  ��ѧʱ  �ڿ�ѧʱ  ʵ�����ϻ�ѧʱ  ѧ��  ����ѧ��\n");
			for(ptr=head;ptr;ptr=ptr->next)
				if(strcmp(min,ptr->name)==0)
				{
					 printf("%5d%12s%9s%9d%9d%11d%11d%7d\n",ptr->num,ptr->name,ptr->kind,ptr->stime,ptr->ttime,ptr->etime,ptr->score,ptr->term);
					 t=0;
				}
			if(t) 
				printf("\t\nδ�ҵ�!\n");
			t=1;
			system("pause");
			goto L1;
				
	   case 2:printf("������Ҫ���ҵĿγ̵�����:");
		   scanf("%s",type);
		   printf("�γ̱��  �γ�����  �γ�����  ��ѧʱ  �ڿ�ѧʱ  ʵ�����ϻ�ѧʱ  ѧ��  ����ѧ��\n");
		   for(ptr=head;ptr;ptr=ptr->next)
			   if(strcmp(type,ptr->kind)==0)
				{
					 printf("%5d%12s%9s%9d%9d%11d%11d%7d\n",ptr->num,ptr->name,ptr->kind,ptr->stime,ptr->ttime,ptr->etime,ptr->score,ptr->term);
					 t=0;
				}
			if(t) 
				printf("\t\nδ�ҵ�!\n");
			t=1;
			system("pause");
			goto L1;
  
	  case 3:printf("����Ҫ���ҵĿγ̵�ѧ��:");
		   scanf("%d",&num);
		   printf("�γ̱��  �γ�����  �γ�����  ��ѧʱ  �ڿ�ѧʱ  ʵ�����ϻ�ѧʱ  ѧ��  ����ѧ��\n");
		   for(ptr=head;ptr;ptr=ptr->next)
			   if(ptr->score==num)
				{
					 printf("%5d%12s%9s%9d%9d%11d%11d%7d\n",ptr->num,ptr->name,ptr->kind,ptr->stime,ptr->ttime,ptr->etime,ptr->score,ptr->term);
					 t=0;
				}
			if(t) 
				printf("\n\tδ�ҵ�!\n");
			t=1;
			system("pause");
			goto L1;
			
		case 4:break;
	}
}

 
void Mangers()
{
   int n,w=1,flag=0,i=3;
   char s[8];
   char password[7]="1";
   do
     {
        printf("\n\nEnter password:");
        scanf("%s",s);
        if(!strcmp(s,password))              //��������ƥ����֤//
         {
             flag=1;
           	break;
          }
       else
        {
          printf("\n\nError! You only have %d times! Enter again:\n",i-1);
          i--;
        } 
     }
	while(i>0);
   if(!flag)
      {
      	printf("you have Enter 3 times!");       //�������볬����3�Σ���???//
        exit(0);                                //�Զ��˳�//
      }
    do
      {
		system("cls");
    	puts("\n\n\t\t*********************����Ա�˵�***********************\n\n");
        puts("\t\t\t\t1---����γ�\n");
		puts("\t\t\t\t2---��ѯ�γ�\n");
        puts("\t\t\t\t3---��ӿγ�\n");
        puts("\t\t\t\t4---ɾ���γ�\n");
		puts("\t\t\t\t5---�������˵�");
		puts("\n\n\t\t******************************************************\n");
        printf("Chiose your number(1-5):[ ]\b\b");
        scanf("%d",&n);
       switch(n)
        {
     	  case 1:prin();break;
		  case 2:search();break;
     	  case 3:insert();savefile();break;
     	  case 4:del();savefile();break;
		  case 5:return;
		  default:;
        } 
      }
      while(w==1);
}


void Students()
{
	int n,w=1;
   do
    {
		system("cls");
    	puts("\n\n\t\t*********************ѧ���˵�***********************\n\n");
        puts("\t\t\t\t1---������пγ�\n");
		puts("\t\t\t\t2---��ѯ�γ���Ϣ\n");
        puts("\t\t\t\t3---ѡ��ѡ�޿γ�\n");
        puts("\t\t\t\t4---�����ѡ�޵Ŀγ�\n");
        puts("\t\t\t\t5---ɾ����ѡ�γ�\n");
		puts("\t\t\t\t6---�������˵�");
        puts("\n\n\t\t****************************************************\n");
        printf("Chiose your number(1-6):[ ]\b\b");
        scanf("%d",&n);
        switch(n)
        {
     	  case 1:prin();break;
		  case 2:search();break;
     	  case 3:choose();break;
    	  case 4:prin1();break;
     	  case 5:del();savefile1();break;
		  case 6:return;
		  default:;
        } 
      }
      while(w==1);
}


int  main()
{
	int n,w=1;
	do
    {
		system("cls");
		puts("\n\n\t\t*********************MENU***********************\n\n");
        puts("\t\t\t\t1.�Թ���Ա��ݵ�¼(password 1)\n");
        puts("\t\t\t\t2.��ѧ����ݵ�¼\n");
		puts("\t\t\t\t3.�˳�");
        puts("\n\n\t\t************************************************\n");
        printf("Chiose your number(1-3):[ ]\b\b");
        scanf("%d",&n);
		switch(n)
		{
		case 1:Mangers() ;break;
		case 2:Students();break;
		case 3:w=0;break;
		default:;
		}
    }
    while(w==1);
    return 0;
}

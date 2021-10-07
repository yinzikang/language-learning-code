#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
void menu();
void add();
void modify();
void stat();
void search();
int load();
struct equipment
    {
    char num[10];            /*�豸���*/
    char kind[10];        /*�豸����*/
    char name[20];        /*�豸����*/
    char money[10];           /*�豸�۸�*/
    char brithday[10]; /*�豸��������*/
    char bf[10];          /*�Ƿ񱨷�*/
    char badday[10];   /*��������*/
    }eup[N],temp;

/* ����������ģ�� */
void menu()
{
    int n;
    puts("\t\t************************MENU*************************\n\n");
    puts("\t\t\t\t 1.���ʵ���豸");
    puts("\t\t\t\t 2.�޸�");
    puts("\t\t\t\t 3.ͳ��");
    puts("\t\t\t\t 4.����");
    puts("\t\t\t\t 5.�˳�");
    puts("\n\n\t\t**********************************************************\n");
    printf("������(1-5):[ ]\b\b");
    scanf("%d",&n);
    switch(n)
    {
        case 1:add();break;
        case 2:modify();break;
        case 3:stat();break;
        case 4:search();break;
        case 5:exit(0);
        default:menu();
    }
}

void main()/*������*/
{
    menu();
    getch();
}

/* ׷��ģ�� */
void add()
{
    int i;
    FILE *fp;
    //fp=fopen("eup.txt","r");
    if((fp=fopen("eup.txt","a"))==NULL)
    {
        printf("���ܴ��ļ�\n"); 
    }
    printf("\n����:���  ���� ���� �۸� ��������(��.��.��)  ����  ��������(��.��.��)\n");
    scanf("%s",temp.num);
    scanf("%s",temp.kind);
    scanf("%s",temp.name);
    scanf("%s",temp.money);
    scanf("%s",temp.brithday);
    scanf("%s",temp.bf);
    scanf("%s",temp.badday);
    fprintf(fp,"\n%2s\t%s\t%14s    %4s   %9s   %s   %9s",temp.num,temp.kind,temp.name,temp.money,temp.brithday,temp.bf,temp.badday);
    fclose(fp);
    printf("\n\n\t�ɹ����.^_^\n\n");
    printf("\n*******************************************************************************\n");
    printf("������Ҫ��ʲô?\n\n");
    printf("\t1.�������\t2.�������˵�\t3.�˳�\n");
    printf("\n*******************************************************************************\n");
    printf("\n\n������(1-3):");
    scanf("%d",&i);
    if(i==1)
    {
        add();
    }
    if(i==2)
    {   
        menu();
    }
    if(i==3)
    {
        exit(0);
    }
}

/* �޸�ģ�� */
void modify()
{
    FILE *fp;
    int n,k=0,b,c,i,e;
    char a[10];
    n=load();
    printf("\n���    ����		  ����  �۸�(Ԫ)  ��������  ����  ��������\n");
	for(i=0;i<n;i++)
    {
        printf("%2s\t%s\t%14s    %4s   %9s   %s   %9s\n",eup[i].num,eup[i].kind,eup[i].name,eup[i].money,eup[i].brithday,eup[i].bf,eup[i].badday);
    }
    printf("\n��������Ҫ�޸ĵ��豸���!\n\n�豸���:");
    scanf("%s",a);
    for(i=0;i<n;i++)
    if(strcmp(a,eup[i].num)==0)         /*����Ҫ�޸ĵ��豸��Ϣ*/
    {
        k=1;
        c=i;
        break;
    }
    if(k==0)
    {
        printf("\n\n�Բ����Ҳ������豸!");
        printf("\t1).�ٴβ���    2).�������˵�   []\b\b");
        scanf("%d",&b);
        if(b==1){modify();}
        if(b==2){menu();}
    }
    if(k==1)
    {
        printf("\n�ɹ��ҵ��豸!\n");
        printf("\n�������µ���Ϣ:\n");
        printf("\n���  ����  ����  �۸�  ��������  ����  ��������\n");
        scanf("%s",eup[c].num);
        scanf("%s",eup[c].kind);
        scanf("%s",eup[c].name);
        scanf("%s",eup[c].money);
        scanf("%s",eup[c].brithday);
        scanf("%s",eup[c].bf);
        scanf("%s",eup[c].badday);
    }
    fp=fopen("eup.txt","w");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",eup[i].num,eup[i].kind,eup[i].name,eup[i].money,eup[i].brithday,eup[i].bf,eup[i].badday);
    }
    fclose(fp);
    printf("\n\n\t�޸ĳɹ�.^_^\n\n");
    printf("\n*******************************************************************************\n");
    printf("������Ҫ��ʲô?\n\n");
    printf("\t1.�����޸�\t2.�������˵�\t3.�˳�\n");
    printf("\n*******************************************************************************\n");
    printf("\n\n������(1-3):");
    scanf("%d",&e);
    if(e==1)
    {
        modify();
    }
    if(e==2)
    {   
        menu();
    }
    if(e==3)
    {
        exit(0);
    }
}

/* ����ͳ��ģ�� */
void stat()
{
    int n,i;
    FILE *fp;
    fp=fopen("eup.txt","r");
    if((fp=fopen("eup.txt","r"))==NULL)
    {
        printf("cannot open file\n"); 
    }
    printf("\n���    ����		  ����  �۸�(Ԫ)  ��������  ����  ��������\n");
	while(!feof(fp))
    {   
        fscanf(fp,"\n%s%s%s%s%s%s%s",temp.num,temp.kind,temp.name,temp.money,temp.brithday,temp.bf,temp.badday);
        printf("\n%2s\t%s\t%14s    %4s   %9s   %s   %9s",temp.num,temp.kind,temp.name,temp.money,temp.brithday,temp.bf,temp.badday);
    }
    fclose(fp);
    menu();
}
/* ����ģ�� */
void search()
{
    int i,n,k=-1,w1,w2,w3;
    char c[10];
    n=load();
    printf("\n\n ����һ��:\n\n1).�豸��� 2).����  3).����  4).��������   [ ]\b\b");
    scanf("%d",&w3);
    switch(w3)
    {
        case 1:
        {
            printf("\n\n����Ҫ���ҵ��豸���! ���:");
            scanf("%s",c);
            printf("\n���    ����		  ����  �۸�(Ԫ)  ��������  ����  ��������\n");
			for(i=0;i<n;i++)
            if(strcmp(c,eup[i].num)==0)
            { 
                k=i;
                printf("%2s\t%s\t%14s    %4s   %9s   %s   %9s\n",eup[i].num,eup[i].kind,eup[i].name,eup[i].money,eup[i].brithday,eup[i].bf,eup[i].badday);
            }
            if (k!=-1)
            printf("\n\n������Ҫ��.");
            if (k==-1)
            printf("�Բ����Ҳ����豸!\n");
            printf("\n\t1).�ٴ�Ѱ��       2).�������˵�  [ ]\b\b");
            scanf("%d",&w2);
            if(w2==2)  menu();
            if(w2==1) search();
        }break;
        case 2:
        {
            printf("\n\n����Ҫ���ҵ�����! ����:");
            scanf("%s",c);
            printf("\n���    ����		  ����  �۸�(Ԫ)  ��������  ����  ��������\n");
			for(i=0;i<n;i++)
            if(strcmp(c,eup[i].kind)==0)
            { 
                k=i;
                printf("%2s\t%s\t%14s    %4s   %9s   %s   %9s\n",eup[i].num,eup[i].kind,eup[i].name,eup[i].money,eup[i].brithday,eup[i].bf,eup[i].badday);
            }
            if (k!=-1)
            printf("\n\n������Ҫ��.^_^.");
            if (k==-1)
            printf("�Բ����Ҳ����豸!\n");
            printf("\n\t1).�ٴβ���       2).�������˵�  [ ]\b\b");
            scanf("%d",&w2);
            if(w2==2)  menu();
            if(w2==1) search();
        }break;
        case 3:
        {
            printf("\n\n����Ҫ���ҵ��豸����! ����:");
            scanf("%s",c);
            printf("\n���    ����		  ����  �۸�(Ԫ)  ��������  ����  ��������\n");
			for(i=0;i<n;i++)
            if(strcmp(c,eup[i].name)==0)
            { 
                k=i;
				printf("%2s\t%s\t%14s    %4s   %9s   %s   %9s\n",eup[i].num,eup[i].kind,eup[i].name,eup[i].money,eup[i].brithday,eup[i].bf,eup[i].badday);
            }
            if (k!=-1)
            printf("\n\n������Ҫ��.^_^.");
            if (k==-1)
            printf("�Բ����Ҳ������豸!\n");
            printf("\n\t1).�ٴβ���       2).�������˵�  [ ]\b\b");
            scanf("%d",&w2);
            if(w2==2)  menu();
            if(w2==1) search();
        }break;
        case 4:
        {
            printf("\n\n����Ҫ���ҵ��豸�Ĺ�������! ��������(��.��.��):");
            scanf("%s",c);
            printf("\n���    ����		  ����  �۸�(Ԫ)  ��������  ����  ��������\n");
			for(i=0;i<n;i++)
            if(strcmp(c,eup[i].brithday)==0)
            { 
                k=i;
                printf("%2s\t%s\t%14s    %4s   %9s   %s   %9s\n",eup[i].num,eup[i].kind,eup[i].name,eup[i].money,eup[i].brithday,eup[i].bf,eup[i].badday);
            }
            if (k!=-1)
            printf("\n\n������Ҫ��.^_^.");
            if (k==-1)
            printf("�Բ����Ҳ����豸!\n");
            printf("\n\t1).�ٴβ���       2).�������˵�  [ ]\b\b");
            scanf("%d",&w2);
            if(w2==2)  menu();
            if(w2==1) search();
        }

    }
}
int load()
{
    FILE *fp;
    int i;
    if((fp=fopen("eup.txt","r"))==NULL)
    {
        printf("\n���ܴ��ļ�\n");
        return NULL;
    }
    for(i=0;!feof(fp);i++)
    fscanf(fp,"%s %s %s %s %s %s %s\n",eup[i].num,eup[i].kind,eup[i].name,eup[i].money,eup[i].brithday,eup[i].bf,eup[i].badday);
    fclose(fp);
    return(i);
}

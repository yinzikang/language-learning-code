#include<stdio.h>              //ͷ�ļ�
#include<string.h>
#include<stdlib.h>
#define L 30                  //�궨��
#define Q 200
struct book                   //����һ��book��ṹ�塣
{
	char no[L];
	char name[L];
	char author[L];
	char fenlei[L];
	char puttime[L];
	char putfrom[L];
	char price[L];
};



//��������                                //��������
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

       
void main()                                //������
{
	char slect,yn;
	struct book record[Q];                 //����book��ṹ��������ͼ����Ϣ��200��
	int total=0,flag;
total=bookzairu(record,Q);              //���ļ���ȡͼ����Ϣ��������200��
	do
	{
		menu();                            //��ʾ�˵�
		printf("��������ţ�");
		slect=getchar();
		getchar();

		switch(slect)
		{
        case'0': goout();break;
		case'1': total=bookluru(record,total);break;   //��������
		case'2': bookliulan(record,total);break;
		case'3': bookchaxun(record,total);break;
		case'4': bookxiugai(record,total);break;
		case'5': total=bookzhengjia(record,total);break;
		case'6': total=bookshanchu(record,total);break;
		case'7': bookpaixu(record,total);break;
		case'8': flag=bookbaocun(record,total);
			if("flag==1")     
				printf("ͼ����Ϣ����ɹ���\n");
			else
				printf("ͼ����Ϣ����ʧ�ܣ�\n");
			break;
		default:continue;
		}
	if(slect=='0') break;
		printf("\n��Ҫ����ѡ���𣿣�Y/N��");      //��ʾ�Ƿ����
		do
		{
			yn=getchar();
			getchar();
			if (yn=='Y'||yn=='y')
				break;
			else if (yn=='N'||yn=='n')
				break;
			else
		    	printf("�Ƿ�ѡ�\n��Ҫ����ѡ���𣿣�Y/N��");			
		}
		while(1);
	}
	while(yn!='N'&&yn!='n');
}


//ͼ�����ϵͳ���˵�.
void menu()
{
	system("cls");
    printf("\n\n");
    printf("��ѡ�������Ŀ��ţ�0--8��\n");
    printf("******************************************************************\n");
    printf("��********************��ӭʹ��ͼ����Ϣ����ϵͳ******************  ��\n");
    printf("��**************************************************************  ��\n");
    printf("���                                                            ���\n");
    printf("���                                                            ���\n");
    printf("���                                                            ���\n");
    printf("���                    * 1 . ͼ����Ϣ¼��.                     ���\n");
    printf("���                    * 2 . ͼ����Ϣ���.                     ���\n"); 
    printf("���                    * 3 . ͼ����Ϣ��Ѱ.                     ���\n");
    printf("���                    * 4 . ͼ����Ϣ�޸�.                     ���\n");
    printf("���                    * 5 . ͼ����Ϣ����.                     ���\n");
    printf("���                    * 6 . ͼ����Ϣɾ��.                     ���\n");
    printf("���                    * 7 . ͼ����Ϣ����.                     ���\n");
    printf("���                    * 8 . ͼ����Ϣ����.                     ���\n");
    printf("���                    * 0 . �˳�ͼ�����ϵͳ.                 ���\n");
    printf("���                                                            ���\n");
    printf("���                                                            ���\n");
    printf("���                                                            ���\n");
    printf("******************************************************************\n");
    printf("\n");
}



int bookluru(struct book *p,int n)//¼��ͼ����Ϣ.
{
	int i=0;
	int m;
	printf("\n���ǰ��ͼ����Ϣ��¼����%d����\n",n);        //��ʾԭ�е�ͼ����Ϣ
	printf("\n %9s%9s%9s%9s%9s%9s%9s\n","��¼��","����","������","�����","���浥λ","����ʱ��","�۸�");
	i=0;
	while((i<n)&&(strcmp(p->no,"")!=0))        //����ĵ�¼�Ų�Ϊ��ʱ�����ͼ����Ϣ
	{
	printf("%9s%9s%9s%9s%9s%9s%9s\n",p->no,p->name,p->author,p->fenlei,p->puttime,p->putfrom,p->price);//��Ϣ���
		i++;
		p++;
	}
	printf("\n������Ҫ¼���ͼ����ĿX��0<X<%d��: ",200-n);  //����ͼ����Ϣ�洢���ֵ
	scanf("%d",&m);
	i=0;
	while(i<m)
	{
		printf("\n");
		printf("�������%d��ͼ�����Ϣ��\n",i+1);
		printf("��¼��: ");
		do
		{
		   gets(p->no);     //�����¼�ţ�������������Ϣ
		}
		while(strcmp(p->no,"")==0);
		printf("����Ϊ:");
        gets(p->name);
        printf("������Ϊ:");
        gets(p->author);
        printf("�����Ϊ:");
        gets(p->fenlei);
        printf("����ʱ��Ϊ:");
        gets(p->puttime);
        printf("���浥λΪ:");
        gets(p->putfrom);
    printf("�۸�Ϊ:");
        gets(p->price);
		p++;
		i++;
	}
	return m+n;
}


void bookliulan(struct book*p,int n)//ͼ����Ϣ���.
{
	int i=0;
	printf("\n %9s%9s%9s%9s%9s%9s%9s\n","��¼��","����","������","�����","���浥λ","����ʱ��","�۸�");
	while(i<n)                                            //���ԭ��ͼ����Ϣ
	{
	printf("%9s%9s%9s%9s%9s%9s%9s\n",p->no,p->name,p->author,p->fenlei,p->puttime,p->putfrom,p->price);
		p++;
		i++;
	}
}


void bookchaxun(struct book*p,int n)//ͼ����Ϣ��Ѱ.
{
	char c;
	bookliulan(p ,n);
	do
	{
		printf("\n���ʰ���¼�Ų�ѯ��D�������ǰ���������ѯ��A����");  //ѡ���ѯ��ʽ
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
			printf("\n�����Ϊ�Ƿ��ַ���\n");
			continue;
		}
	}
	while(c!='D'||c!='d'||c!='A'||c!='a');
}


void DLsearch(struct book*p,int n)//����¼�Ų�ѯ.
{
	int i,x=0;
	char DL[L];
	printf("\n������Ҫ��ѯͼ��ĵ�¼�ţ�");
	gets(DL);
	for(i=0;i<n;i++)
		if(strcmp(DL,p[i].no)==0)     //�����¼�ţ������ϵͳ���ҵ������ͼ����Ϣ
		{
		printf("\n %9s%9s%9s%9s%9s%9s%9s\n","��¼��","����","������","�����","���浥λ","����ʱ��","�۸�");
printf("\n%10s%10s%10s%10s%10s%10s%10s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price);
		x=1;
		break;
		}
		if(x==0)
		printf("\n�Բ���ͼ��ϵͳ��û�а����������Ϣ��\n");
}


void AUsearch(struct book*p,int n)//����������ѯ.
{
	int i,x=0;
	char AU[20];
	printf("\n������Ҫ��ѯͼ�������������");
	gets(AU);
	for(i=0;i<n;i++)
	   if(strcmp(AU,p[i].author)==0)  //�������������������ϵͳ���ҵ������ͼ����Ϣ
		{
	     printf("\n %9s%9s%9s%9s%9s%9s%9s\n","��¼��","����","������","�����","���浥λ","����ʱ��","�۸�");
	printf("\n%10s%10s%10s%10s%10s%10s%10s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price);
			x=1;
		}
		if(x==0)
		printf("\n�Բ���ͼ��ϵͳ��û�а����������Ϣ��\n");  //��ʾ��Ϣ
}


void bookxiugai(struct book*p,int n)//ͼ����Ϣ�޸�.
{
	int i,k=0;
	char no[L];
	bookliulan(p,n);
	printf("\n������Ҫ�޸�ͼ��ĵ�¼�ţ�");
	gets(no);
	for(i=0;i<n;i++,p++)      
	{
		if(strcmp(no,p->no)!=0) continue;     //����ĵ�¼�Ų�ƥ�䣬��������ѭ��
		else
		{
			printf("\n��������ȷ��ͼ���¼�ţ�");
			gets(p->no);	
			printf("\n��������ȷ��ͼ������:");
            gets(p->name);
            printf("\n��������ȷ��ͼ��������:");
            gets(p->author);
            printf("\n��������ȷ��ͼ������:");
            gets(p->fenlei);
            printf("\n��������ȷ��ͼ�����ʱ��:");
            gets(p->puttime);
            printf("\n��������ȷ��ͼ����浥λ:");
            gets(p->putfrom);
            printf("\n��������ȷ��ͼ��۸�:");
            gets(p->price);
			printf("\n�޸�ͼ��ͼ����Ϣ��ɣ���");
			k=1;
		}
	}
	if(k==0)
		printf("\n�Բ���ͼ��ϵͳ��û�а����������Ϣ��\n");
}


int bookzhengjia(struct book *p,int n)//ͼ����Ϣ����.
{
	int i=0;
	char c;
	struct book t;
	printf("\n���ǰͼ����Ϣ�ļ�¼Ϊ��\n");
    bookliulan(p ,n);//��ʾ���ǰͼ����Ϣ�ļ�¼
	do
	{
		printf("��������ͼ����Ϣ�ĵ�¼��:");
	gets(t.no);       
		printf("\n��������ͼ����Ϣ������Ϊ:");
        gets(t.name);
        printf("\n��������ͼ����Ϣ��������Ϊ:");
        gets(t.author);
        printf("\n��������ͼ����Ϣ�ķ����Ϊ:");
        gets(t.fenlei);
        printf("\n��������ͼ����Ϣ�ĳ���ʱ��Ϊ:");
        gets(t.puttime);
        printf("\n��������ͼ����Ϣ�ĳ��浥λΪ:");
        gets(t.putfrom);
        printf("\n��������ͼ����Ϣ�ļ۸�Ϊ:");
        gets(t.price);
		for(i=0;i<n;i++)		if(strcmp(t.no,(p+i)->no)==0||strcmp(t.author,(p+i)->author)==0||strcmp(t.fenlei,(p+i)->fenlei)==0)
			{
				printf("��¼�š��������ͷ�����ظ���Ҫ����������Y/N����");
				c=getchar();
				putchar('\n');
				break;
			}
			if(i==n)
			{
				*(p+i)=t;  
	printf("\n��Ӻ�ͼ�����Ϣ��¼Ϊ��\n");   //��ʾ��Ӻ�ͼ�����Ϣ��¼
	printf("\n %9s%9s%9s%9s%9s%9s%9s\n","��¼��","����","������","�����","���浥λ","����ʱ��","�۸�");
	for(i=0;i<n+1;i++)
	printf("\n%9s%9s%9s%9s%9s%9s%9s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price);
			break;
			}
	}
	while(c=='y'||c=='Y');
	return n+1;
}


int bookshanchu(struct book *p,int n)//ͼ����Ϣɾ��.

{
	int i,x,y=0;
	char name[20],no[20];
	printf("\nɾ��ǰͼ�����Ϣ��¼Ϊ��\n");
	printf("\n %9s%9s%9s%9s%9s%9s%9s\n","��¼��","����","������","�����","���浥λ","����ʱ��","�۸�");        //��ʾɾ��ǰͼ�����Ϣ��¼
	for(i=0;i<n;i++)		printf("\n%9s%9s%9s%9s%9s%9s%9s\n",(p+i)->no,(p+i)->name,(p+i)->author,(p+i)->fenlei,(p+i)->putfrom,(p+i)->puttime,p[i].price);
	printf("\n������Ҫɾ��ͼ��ĵ�½�ţ�");
	gets(no);
	for(x=0;x<n;x++)
	{
		if(strcmp(no,p[x].no)!=0)    ////����ĵ�¼�Ų�ƥ�䣬��������ѭ��
			continue;
		if(x<n)
		{
			for(i=x;i<n;i++)         //��һ��ͼ����Ϣ��ǰһ��ͼ����Ϣ����ɾ��
			{
			   strcpy(p[i].no,p[i+1].no);
               strcpy(p[i].author,p[i+1].author);
               strcpy(p[i].name,p[i+1].name);
               strcpy(p[i].fenlei,p[i+1].fenlei);
               strcpy(p[i].price,p[i+1].price);
			   strcpy(p[i].putfrom,p[i+1].putfrom);
			   strcpy(p[i].puttime,p[i+1].puttime);
			}
			printf("ͼ����Ϣɾ����ļ�¼��\n");
	printf("\n %9s%9s%9s%9s%9s%9s%9s\n","��¼��","����","������","�����","���浥λ","����ʱ��","�۸�");     //��ʾͼ����Ϣɾ����ļ�¼
	for(i=0;i<n-1;i++)		printf("\n%9s%9s%9s%9s%9s%9s%9s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price);
			y=1;
		}
		else
			printf("\n�Բ���ͼ��ϵͳ��û�а����������Ϣ��\n");
		return n-y;
	}
}


//��ͼ����Ϣ����.
void bookpaixu(struct book*p,int n)
{
	int j,i,k;
	char c1;
	struct book temp;
	printf("\n����ǰͼ�����Ϣ��¼Ϊ��\n");
	printf("\n %9s%9s%9s%9s%9s%9s%9s\n","��¼��","����","������","�����","���浥λ","����ʱ��","�۸�");
	for(i=0;i<n;i++)
	printf("\n%10s%10s%10s%10s%10s%10s%10s\n",(p+i)->no,(p+i)->name,(p+i)->author,(p+i)->fenlei,(p+i)->putfrom,(p+i)->puttime,p[i].price);
	printf("\n����¼������D�������ǰ�����������A����");      //ѡ������ķ�ʽ
	c1=getchar();
	getchar();
	if(c1=='d'||c1=='D')                //ѡ���¼����С��������
	{
		for(i=0;i<n-1;i++)                        
		{
			k=i;
			for(j=i+1;j<n;j++)
				if(strcmp(p[k].no,p[j].no)>0)     //ʹ��ѡ�񷨽�������
					k=j;
				if(k!=i)    //�����С�첻��Ĭ�ϵ�p[i]���ٽ�����
				{
					temp=p[k];
					p[k]=p[i];
					p[i]=temp;
				}
		}
		printf("\n�����ͼ�����Ϣ��¼Ϊ��\n");            //��������ͼ�����Ϣ
	printf("\n %9s%9s%9s%9s%9s%9s%9s\n","��¼��","����","������","�����","���浥λ","����ʱ��","�۸�");
	for(i=0;i<n;i++)		printf("\n%10s%10s%10s%10s%10s%10s%10s\n",(p+i)->no,(p+i)->name,(p+i)->author,(p+i)->fenlei,(p+i)->putfrom,(p+i)->puttime,p[i].price);
	}
	else if(c1=='a'||c1=='A')   //ѡ����������С��������
	{
		for(i=0;i<n-1;i++)
		{
	k=i;
			for(j=i+1;j<n;j++)
				if(strcmp(p[k].author,p[j].author)>0)
					k=j;
				if(k!=i)        //ʹ��ѡ�񷨽�������
				{
					temp=p[k];
					p[k]=p[i];
					p[i]=temp;
				}
		}
		printf("\n�����ͼ�����Ϣ��¼Ϊ��\n");
		printf("\n %9s%9s%9s%9s%9s%9s%9s\n","��¼��","����","������","�����","���浥λ","����ʱ��","�۸�");        //��������ͼ�����Ϣ
		for(i=0;i<n;i++)
	printf("\n%10s%10s%10s%10s%10s%10s%10s\n",(p+i)->no,(p+i)->name,(p+i)->author,(p+i)->fenlei,(p+i)->putfrom,(p+i)->puttime,p[i].price);
	}
	else
		printf("\n�������Ϊ�Ƿ��ַ���\n");
}


//ͼ����Ϣ�ļ��洢.
int bookzairu(struct book*p,int n)  
{
	FILE *fp;               //����FILE�����ļ�ָ�����
	int i,all=0;
	char bookfile[200]="book.txt";
	fp=fopen("book.txt","r+");       //��ֻ����ʽ��
	if(fp==NULL)
	{
		printf("\n***��%sʧ�ܣ���***",bookfile);

		return 0;
	}
	fscanf(fp,"%d\n",&all);  //���ļ�ָ��ָ����ı��ļ��а�ָ����ʽ���������Ϣ��ָ������  
	if(all>200)                    //��ȡ��¼����
	{
		printf("�ļ���¼̫�࣬���ܶ�ȡ��");
		return 0;
	}
	for(i=0;i<all;i++)       //ͼ����Ϣ��ָ����ʽ����
	{	fscanf(fp,"%s %s %s %s %s %s %s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price);
	}
	fclose(fp);     //�ر��ļ�
	return all;
}


//ͼ����Ϣ�ļ�����.
int bookbaocun(struct book*p,int n)
{
	FILE *fp;                        //����FILE�����ļ�ָ�����
	int i,all=0;
	char bookfile[30]="book.txt";
	fp=fopen(bookfile,"w");       //��ֻд��ʽ��
	if(fp==NULL)                    //
	{
		printf("\n***��%sʧ�ܣ���***",bookfile);   
		return 0;
	}
	fprintf(fp,"%d\n",n);         //������ָ����ʽ�ַ���������ļ�ָ����ָ����ı��ļ���
	for(i=0;i<n;i++)            //ͼ����Ϣ��ָ����ʽ���
	{
	fprintf(fp,"%s %s %s %s %s %s %s\n",p[i].no,p[i].name,p[i].author,p[i].fenlei,p[i].putfrom,p[i].puttime,p[i].price);
	}
	fclose(fp);       //�ر��ļ�
	return 1;
}


//ͼ�����ϵͳ�˳�
void goout()
{
printf("\n�밴Enter���˳�ͼ����Ϣ����ϵͳ!\n");

}
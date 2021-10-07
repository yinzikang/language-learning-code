#include<stdio.h> 
#include<math.h> 
#include<string.h> 
struct building 
{ 
 char name[20];
 char num[20];
 char city[20]; 
}; 
struct peijian 
{ 
 char p_name[20];
 char p_num[20];
 char p_colour[20];
 char p_weight[20];
 char p_area[20]; 
}; 
struct business 
{ 
 char b_name[20]; 
 char b_num[20]; 
 char b_state[20];
 char b_city[20]; 
}; 
struct total 
{ 
 char b_num[20];
 char p_num[20];
 char num[20]; 
 char num2[20]; 
}; 
int exit();
void add();
void add1(); 
void add2(); 
void add3(); 
void add4();
void modify(); 
void modify1(); 
void modify2(); 
void modify3(); 
void modify4(); 
void del();
void del1(); 
void del2(); 
void del3(); 
void del4(); 
void seek();
void seek1(); 
void seek2(); 
char flag='y'; 
int n; 

void add()
{
printf("1.���ӽ���������Ϣ\n2.���������Ϣ\n3.������������Ϣ\n4.����������-���-����������Ϣ\n");
scanf("%d",&n);  
if(n==1)  
add1(); 
else if(n==2)  
 add2(); 
else if(n==3)  
 add3();  
else if(n==4)  
 add4();  
}
void add1()  
{  
char flag='y';  
struct building build;  
FILE *fp;  
if((fp=fopen("D:\\file1.txt","a+"))==NULL)  
{  
 exit(0);  
 }  
while(flag=='y')  
{  
printf("�����뽨����������:");  
scanf("%s",build.name);  
printf("�����뽨�����ر��:");  
scanf("%s",build.num);  
printf("�����빤�����ڳ���:");  
scanf("%s",build.city); 
 fwrite(&build,sizeof(struct building),1,fp);  
printf("�Ƿ����y/n:\n");  
scanf(" %c",&flag);  
}  
fclose(fp);  
} 

void add2()  
{  
char flag='y';  
struct peijian pj;  
FILE *fp;  
if((fp=fopen("D:\\file2.txt","a+"))==NULL)  
{  
 exit(0);  
 }  
while(flag=='y')  
{  
printf("�������������:");  
scanf("%s",pj.p_name);  
printf("������������:");  
scanf("%s",pj.p_num);  
printf("�����������ɫ:");  
scanf("%s",pj.p_colour); 
printf("�������������:");  
scanf("%s",pj.p_weight); 
printf("�������������:");  
scanf("%s",pj.p_area); 
 fwrite(&pj,sizeof(struct peijian),1,fp);  
printf("�Ƿ����y/n:\n");  
scanf(" %c",&flag);  
}  
fclose(fp);  
} 

void add3()  
{  
char flag='y';  
struct business bus;  
FILE *fp;  
if((fp=fopen("D:\\file3.txt","a+"))==NULL)  
{  
 exit(0);  
 }  
while(flag=='y')  
{  
printf("����������������:");  
scanf("%s",bus.b_name);  
printf("�����������̱��:");  
scanf("%s",bus.b_num);  
printf("������������״̬:");  
scanf("%s",bus.b_state); 
printf("���������������ڳ���:");  
scanf("%s",bus.b_city); 
 fwrite(&bus,sizeof(struct business),1,fp);  
printf("�Ƿ����y/n:\n");  
scanf(" %c",&flag);  
}  
fclose(fp);  
} 

void add4()  
{  
char flag='y';  
struct total bpb;  
FILE *fp;  
if((fp=fopen("D:\\file4.txt","a+"))==NULL)  
{  
 exit(0);  
 }  
while(flag=='y')  
{  
printf("�����������̺���:");  
scanf("%s",bpb.b_num);  
printf("������������:");  
scanf("%s",bpb.b_num);  
printf("�����뽨�����ر��:");  
scanf("%s",bpb.num); 
printf("������������Ϊ�����ṩ�������:");  
scanf("%s",bpb.num2); 
 fwrite(&bpb,sizeof(struct total),1,fp);  
printf("�Ƿ����y/n:\n");  
scanf(" %c",&flag);  
}  
fclose(fp);  
} 
void modify()
{
printf("1.�޸Ľ���������Ϣ\n2.�޸������Ϣ\n3.�޸���������Ϣ\n4.�޸�������-���-����������Ϣ\n");
scanf("%d",&n);  
if(n==1)  
modify1(); 
else if(n==2)  
modify2(); 
else if(n==3)  
modify3();  
else if(n==4)  
modify4(); 
}
void modify1()  
{  
FILE *fp;  
struct building build;  
char flag='y',modify;  
char name[20];  
if((fp=fopen("D:\\file1.txt","r+"))==NULL)  
printf("\n\tThe system can't open the file!!");  
while(flag=='y')  
{  

printf("��������Ҫ�޸ĵĽ�����������:");  
scanf("%s",name);  
modify='n';  
rewind(fp);  

while((fread(&build,sizeof(build),1,fp))==1&&modify=='n')  
{  
if(strcmp(name,build.name)==0)  
{  
modify='y';  
break;  
}  
}  
if(modify=='y')  
{  

 printf("������������:%s\n",build.name);  
printf("�������ر��:%s\n",build.num);  
printf("�����������ڳ���:%s\n",build.city); 
 printf("�����뽨����������:");  
scanf("%s",build.name);  
printf("�����뽨�����ر��:");  
scanf("%s",build.num);  
printf("�����뽨���������ڳ���:");  
scanf("%s",build.city); 

fseek(fp,-(long)(sizeof(struct building)),1);  
fwrite(&build,sizeof(build),1,fp);  

}  
printf("�Ƿ����:"); 
scanf(" %c",&flag);  
}  
fclose(fp); 
} 

void modify2()  
{  
FILE *fp;  
struct peijian pj;  
char flag='y',modify;  
char name[20];  
if((fp=fopen("D:\\file2.txt","r+"))==NULL)  
printf("\n\tThe system can't open the file!!");  
while(flag=='y')  
{  

printf("��������Ҫ�޸ĵ��������:");  
scanf("%s",name);  
modify='n';  
rewind(fp);  

while((fread(&pj,sizeof(pj),1,fp))==1&&modify=='n')  
{  
if(strcmp(pj.p_name,name)==0)  
{  
modify='y';  
break;  
}  
}  
if(modify=='y')  
{  

 printf("�������:%s\n",pj.p_name);  
printf("������:%s\n",pj.p_num); 
printf("�����ɫ:%s\n",pj.p_colour); 
printf("�������:%s\n",pj.p_weight);  
printf("�������:%s\n",pj.p_area); 
 printf("�������������:");  
scanf("%s",pj.p_name);  
printf("������������:");  
scanf("%s",pj.p_name); 
printf("�����������ɫ:");  
scanf("%s",pj.p_colour); 
printf("�������������:");  
scanf("%s",pj.p_weight);  
printf("�������������:");  
scanf("%s",pj.p_name); 

fseek(fp,-(long)(sizeof(struct peijian)),1); 
fwrite(&pj,sizeof(pj),1,fp);  

}  
printf("�Ƿ����:"); 
scanf(" %c",&flag);  
}  
fclose(fp); 
} 

void modify3()  
{  
FILE *fp;  
struct business bus;  
char flag='y',modify;  
char name[20];  
if((fp=fopen("D:\\file3.txt","r"))==NULL)  
printf("\n\tThe system can't open the file!!");  
while(flag=='y')  
{  

printf("��������Ҫ�޸ĵ�����������");  
scanf("%s",name);  
modify='n';  
rewind(fp);  

while((fread(&bus,sizeof(bus),1,fp))==1&&modify=='n')  
{  
if(strcmp(bus.b_name,name)==0)  
{  
modify='y';  
break;  
}  
}  
if(modify=='y')  
{  

 printf("����������:%s\n",bus.b_name);  
printf("�����̱��:%s\n",bus.b_name);  
printf("������״̬:%s\n",bus.b_state); 
printf("���ڳ���:%s\n",bus.b_city); 
 printf("����������:");  
scanf("%s",bus.b_name);  
printf("��������:");  
scanf("%s",bus.b_num);  
printf("������״̬:");  
scanf("%s",bus.b_state); 
printf("���������ڳ�����:"); 
scanf("%s",bus.b_city);  

fseek(fp,-(long)(sizeof(struct business)),1);
fwrite(&bus,sizeof(bus),1,fp);  

}  
printf("�Ƿ����:");
scanf(" %c",&flag);  
}  
fclose(fp); 
}  

void modify4()
{  
FILE *fp;  
struct total bpb;  
char flag='y',modify;  
char num[20];  
if((fp=fopen("D:\\file4.txt","r+"))==NULL)  
printf("\n\tThe system can't open the file!!");  
while(flag=='y')  
{  
printf("��������Ҫ�޸ĵĶ�Ӧ���������̱��:");  
scanf("%s",num);  
modify='n';  
rewind(fp);  

while((fread(&bpb,sizeof(bpb),1,fp))==1&&modify=='n')  
{  
if(strcmp(num,bpb.b_num)==0)  
{  
modify='y';  
break;  
}  
}  
if(modify=='y')  
{  

 printf("�����̱��:%s\n",bpb.b_num);  
printf("������:%s\n",bpb.p_num);  
printf("�������ر��:%s\n",bpb.num); 
printf("�ṩ�������:%s\n",bpb.num2); 
 printf("�����������̱��:");  
scanf("%s",bpb.b_num);  
printf("������������:");  
scanf("%s",bpb.p_num);  
printf("�����뽨�����ر��:");  
scanf("%s",bpb.num); 
printf("�������ṩ�������:"); 
scanf("%s",bpb.num2);  

fseek(fp,-(long)(sizeof(struct total)),1);  
fwrite(&bpb,sizeof(bpb),1,fp);  

}  
printf("�Ƿ����:");
scanf(" %c",&flag);  
}  
fclose(fp); 
} 
void del()
{
printf("1.ɾ������������Ϣ\n2.ɾ�������Ϣ\n3.ɾ����������Ϣ\n4.ɾ��������-���-����������Ϣ\n");
scanf("%d",&n);  
if(n==1)  
del1(); 
else if(n==2)  
del2(); 
else if(n==3)  
del3();  
else if(n==4)  
del4(); 
}
void del1()  
{  
struct building build;  
FILE *fp;  
  
char flag='y';  
char modify='n';  
char mc[30];  
char n;  
if((fp=fopen("D:\\file1.txt","r+"))==NULL)  
 printf("���ļ�����"); 
while(flag=='y')  
{  
printf("�����빤����:");  
 scanf("%s",mc);  
 rewind(fp);  
while((fread(&build,sizeof(build),1,fp))==1&&modify=='n')  
{  
if(strcmp(mc,build.name)==0)  
{  
modify='y';  
break;  
}  
}  
if(modify=='y')  
{  
 printf("������������:%s\n",build.name);  
 printf("�������ر��:%s\n",build.num);  
 printf("�����������ڳ���:%s\n",build.city); 
 printf("�Ƿ�ȷ��ɾ��y/n:");  
scanf("%c",&n);  
if(n=='y')  
strcpy(build.name,"");  
strcpy(build.num,"");  
strcpy(build.city,"");  
fseek(fp,-(long)(sizeof(struct building)),1);  
 fwrite(&build,sizeof(build),1,fp);  
printf("ɾ���ɹ�\n");  
}  
printf("�Ƿ����ɾ��y/n:\n");  
scanf(" %c",&flag);  
}  
fclose(fp);  
} 

void del2()  
{  
struct peijian pj;  
FILE *fp;  
 
char flag='y';  
char modify='n';  
char mc[30];  
char n;  
if((fp=fopen("D:\\file2.txt","r+"))==NULL)  
 printf("���ļ�����");  
while(flag=='y')  
{  
printf("�������������:");  
 scanf("%s",mc);  
 rewind(fp);  
while((fread(&pj,sizeof(pj),1,fp))==1&&modify=='n')  
{  
if(strcmp(mc,pj.p_name)==0)  
{  
modify='y';  
break;  
}  
}  
if(modify=='y')  
{  
 printf("����:%s\n",pj.p_name);  
 printf("���:%s\n",pj.p_num); 
 printf("��ɫ:%s\n",pj.p_colour); 
 printf("����:%s\n",pj.p_weight); 
 printf("����:%s\n",pj.p_area); 
 printf("�Ƿ�ȷ��ɾ��y/n:");  
scanf("%c",&n);  
if(n=='y')  
strcpy(pj.p_name,"");  
strcpy(pj.p_num,""); 
strcpy(pj.p_colour,""); 
strcpy(pj.p_weight,"");  
strcpy(pj.p_area,"");  
fseek(fp,-(long)(sizeof(struct peijian)),1);  
 fwrite(&pj,sizeof(pj),1,fp);  
printf("ɾ���ɹ�\n");  
}  
printf("�Ƿ����ɾ��y/n:\n");  
scanf(" %c",&flag);  
}  
fclose(fp);  
} 

void del3()  
{  
struct business bus;  
FILE *fp;  
 
char flag='y';  
char modify='n';  
char mc[30];  
char n;  
if((fp=fopen("D:\\file3.txt","r+"))==NULL)  
 printf("���ļ�����");  
while(flag=='y')  
{  
printf("����������������:");  
 scanf("%s",mc);  
 rewind(fp);  
while((fread(&bus,sizeof(bus),1,fp))==1&&modify=='n')  
{  
if(strcmp(mc,bus.b_name)==0)  
{  
modify='y';  
break;  
}  
}  
if(modify=='y')  
{  
 printf("����������:%s\n",bus.b_name);  
 printf("�����̱��:%s\n",bus.b_num); 
 printf("������״̬:%s\n",bus.b_state); 
 printf("���������ڳ���:%s\n",bus.b_city); 
 printf("�Ƿ�ȷ��ɾ��y/n:");  
scanf("%c",&n);  
if(n=='y')  
strcpy(bus.b_name,"");  
strcpy(bus.b_num,""); 
strcpy(bus.b_state,"");  
strcpy(bus.b_city,"");  
fseek(fp,-(long)(sizeof(struct business)),1);  
 fwrite(&bus,sizeof(bus),1,fp);  
printf("ɾ���ɹ�\n");  
}  
printf("�Ƿ����ɾ��y/n:\n");  
scanf(" %c",&flag);  
}  
fclose(fp);  
} 


void del4()  
{  
struct total bpb;  
FILE *fp;  
 
char flag='y';  
char modify='n';  
char bh[30];  
char n;  
if((fp=fopen("D:\\file4.txt","r+"))==NULL)  
 printf("���ļ�����");  
while(flag=='y')  
{  
printf("�����������̱��:");  
 scanf("%s",bh);  
 rewind(fp);  
while((fread(&bpb,sizeof(bpb),1,fp))==1&&modify=='n')  
{  
if(strcmp(bh,bpb.b_num)==0)  
{  
modify='y';  
break;  
}  
}  
if(modify=='y')  
{  
 printf("�����̱��:%s\n",bpb.b_num);  
 printf("������:%s\n",bpb.p_num); 
 printf("�������ر��:%s\n",bpb.num); 
 printf("�ṩ�������:%s\n",bpb.num2); 
 printf("�Ƿ�ȷ��ɾ��y/n:");  
scanf("%c",&n);  
if(n=='y')  
strcpy(bpb.b_num,"");  
strcpy(bpb.p_num,""); 
strcpy(bpb.num,"");  
strcpy(bpb.num2,"");  
fseek(fp,-(long)(sizeof(struct total)),1);  
 fwrite(&bpb,sizeof(bpb),1,fp);  
printf("ɾ���ɹ�\n");  
}  
printf("�Ƿ����ɾ��y/n:\n");  
scanf(" %c",&flag);  
}  
fclose(fp);  
} 
void seek()
{
printf("1.��ѯ�빩Ӧ�����ڳ�����ͬ�����-��Ӧ�̼�¼��\n2.��ѯ�빩Ӧ�����ڳ�����ͬ����Ŀ-��Ӧ�̼�¼��\n");  
scanf("%d",&n);  
if(n==1)  
seek1(); 
else if(n==2)  
seek2(); 
}
void seek1() 
{ 
FILE *fp1,*fp2; 
struct peijian pj; 
struct business bus; 
char flag='y',seek; 
if((fp1=fopen("D:\\file2.txt","r+"))==NULL||(fp2=fopen("D:\\file3.txt","r+"))==NULL) 
printf("\n\tThe system can't open the files!!");  
while (flag=='y') 
{ 
seek='n'; 
rewind(fp1); 
rewind(fp2); 

while ((fread(&pj,sizeof(pj),1,fp1))==1&&(fread(&bus,sizeof(bus),1,fp2))==1&&seek=='n') 
{ 
if(strcmp(pj.p_area,bus.b_city)==0) 
{seek='y'; 
break; 
} 
} 
if(seek='y') 
{ 
printf("�������:%s\n",pj.p_name);  
printf("������:%s\n",pj.p_num); 
printf("�����ɫ:%s\n",pj.p_colour); 
printf("�������:%s\n",pj.p_weight);  
printf("�������:%s\n",pj.p_area);  
printf("����:%s\n",bus.b_name);  
printf("���:%s\n",bus.b_num); 
printf("״̬:%s\n",bus.b_state); 
printf("���������ڳ���:%s\n",bus.b_city); 
} 
printf("�Ƿ����:");  
scanf(" %c",&flag);  
}  
fclose(fp1);  
fclose(fp2);
} 

void seek2() 
{ 
FILE *fp1,*fp2; 
struct building build; 
struct business bus; 
char flag='y',seek; 
if((fp1=fopen("D:\\file1.txt","r+"))==NULL||(fp2=fopen("D:\\file3.txt","r+"))==NULL) 
printf("\n\tThe system can't open the files!!");  
while (flag='y') 
{ 
seek='n'; 
rewind(fp1); 
rewind(fp2); 

while ((fread(&build,sizeof(build),1,fp1))==1&&(fread(&bus,sizeof(bus),1,fp2))==1&&seek=='n') 
{ 
if(strcmp(build.city,bus.b_city)==0) 
{seek='y'; 
break; 
} 
} 
if(seek='y') 
{ 
printf("������������:%s\n",build.name);  
printf("�������ر��:%s\n",build.num);  
printf("�����������ڳ���:%s\n",&build.city); 
printf("����:%s\n",bus.b_name);  
printf("���:%s\n",bus.b_num); 
printf("״̬:%s\n",bus.b_state); 
printf("���������ڳ���:%s\n",bus.b_city); 
} 
printf("�Ƿ����:"); 
scanf(" %c",&flag);  
}  
fclose(fp1); 
fclose(fp2); 
} 
  

void main() 
{ printf("/**********************��ӭʹ�ú����εĽ���������Ϣ����ϵͳ*******************/\n"); 
while(n!=5) 
{ 

printf("1.������Ϣ\n2.ɾ����Ϣ\n3.�޸���Ϣ\n4.��ѯ\n5.�˳�\n");  
scanf("%d",&n);  
if(n==1)  
add(); 
else if(n==2)  
del(); 
else if(n==3)  
modify();  
else if(n==4)  
seek();  
}  
}

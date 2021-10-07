#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct subjects   //struct�Ƕ���һ���ṹ�壬���԰����������͵���Ϣ 
{
 int num;
 char name[20];
 char kind[10];
 int stime;
 int ttime;
 int etime;
 int score;
 int term;
 struct subjects *next;     //����ṹ������Ƕ����һ���ṹ�壬������һ������ָ����һ����Ա 
}SUB;
 
SUB *create_form()    //¼��
{
 SUB *head,*tail,*p;
 int num,stime,ttime;
 int etime,score,term;
 char name[20],kind[10];
 int size=sizeof(SUB);
 head=tail=NULL;
 printf("����ѡ�޿γ���Ϣ:\n");
 scanf("%d %s %s %d %d %d %d %d",&num,&name,&kind,&stime,&ttime,&etime,&score,&term);
 while(num!=0){
  p=(SUB *)malloc(size);
  p->num=num;  //�ȼ��ڣ�*p).num,��ʾpָ��Ľṹ���е�num��Ա 
  strcpy(p->name,name);
  strcpy(p->kind,kind);
  p->stime=stime;
  p->ttime=ttime;
  p->etime=etime;
  p->score=score;
  p->term=term;
 if(head==NULL)  //NULL�൱�ڿգ�ѭ������ 
  head=p;
 else
  tail->next=p;
 tail=p;
 scanf("%d %s %s %d %d %d %d %d",&num,&name,&kind,&stime,&ttime,&etime,&score,&term);
 }
 tail->next=NULL;
 return head;
}
 
void savefile(SUB *head)    //����
{
 SUB *p;
 FILE *fp;
 fp=fopen("subjects.txt","w");
 fprintf(fp,"�γ̱��  �γ�����  �γ�����  ��ѧʱ  �ڿ�ѧʱ  ʵ����ϻ�ѧʱ  ѧ��  ����ѧ��\n");
 for(p=head;p;p=p->next)
  fprintf(fp,"%5d%12s%9s%9d%9d%11d%11d%7d\n",p->num,p->name,p->kind,p->stime,p->ttime,p->etime,p->score,p->term);
 fclose(fp);
}
 
void savefileadd(SUB *head)  //���
{
 SUB *p;
 FILE *fp;
 fp=fopen("subjectsadd.txt","w");
 fprintf(fp,"�γ̱��  �γ�����  �γ�����  ��ѧʱ  �ڿ�ѧʱ  ʵ����ϻ�ѧʱ  ѧ��  ����ѧ��\n");
 for(p=head;p;p=p->next)
  fprintf(fp,"%5d%12s%9s%9d%9d%11d%11d%7d\n",p->num,p->name,p->kind,p->stime,p->ttime,p->etime,p->score,p->term);
 fclose(fp);
}
 
void savefiledel(SUB *head)  
{
 SUB *p;
 FILE *fp;
 fp=fopen("subjectsdel.txt","w");
 fprintf(fp,"�γ̱��  �γ�����  �γ�����  ��ѧʱ  �ڿ�ѧʱ  ʵ����ϻ�ѧʱ  ѧ��  ����ѧ��\n");
 for(p=head;p;p=p->next)
  fprintf(fp,"%5d%12s%9s%9d%9d%11d%11d%7d\n",p->num,p->name,p->kind,p->stime,p->ttime,p->etime,p->score,p->term);
 fclose(fp);
}
 
void prin(SUB *head)
{
 SUB *ptr;
 if(head==NULL){
  printf("û�д��ſγ̼�¼!\n");
  return;
 }
 printf("�γ̱��  �γ�����  �γ�����  ��ѧʱ  �ڿ�ѧʱ  ʵ�����ϻ�ѧʱ  ѧ��  ����ѧ��\n");
 for(ptr=head;ptr;ptr=ptr->next)
  printf("%5d%12s%9s%9d%9d%11d%11d%7d\n",ptr->num,ptr->name,ptr->kind,ptr->stime,ptr->ttime,ptr->etime,ptr->score,ptr->term);
}

void search(SUB *head)  //��ѯ
{
 int a,num;
 int t=1;
 char type[10];
 char ch='a',ch1;
 SUB *ptr;
 
 while(ch!=' '){
  printf("��Ҫ���γ����ʲ���������1����Ҫ��ѧ�ֲ���������2:\n");
  scanf("%d",&a);
  switch(a){
  case 1:printf("������Ҫ���ҵĿγ̵�����:\n");
   scanf("%s",type);
   printf("�γ̱��  �γ�����  �γ�����  ��ѧʱ  �ڿ�ѧʱ  ʵ�����ϻ�ѧʱ  ѧ��  ����ѧ��\n");
   for(ptr=head;ptr;ptr=ptr->next)
    if(strcmp(type,ptr->kind)==0){
     printf("%5d%12s%9s%9d%9d%11d%11d%7d\n",ptr->num,ptr->name,ptr->kind,ptr->stime,ptr->ttime,ptr->etime,ptr->score,ptr->term);
           t=0;
    }
    if(t) printf("δ�ҵ�!\n");
    t=1;
   break;
  case 2:printf("����Ҫ���ҵĿγ̵�ѧ��\n");
   scanf("%d",&num);
   printf("�γ̱��  �γ�����  �γ�����  ��ѧʱ  �ڿ�ѧʱ  ʵ�����ϻ�ѧʱ  ѧ��  ����ѧ��\n");
   for(ptr=head;ptr;ptr=ptr->next)
    if(ptr->score==num){
     printf("%5d%12s%9s%9d%9d%11d%11d%7d\n",ptr->num,ptr->name,ptr->kind,ptr->stime,ptr->ttime,ptr->etime,ptr->score,ptr->term);
                    t=0;
    }
    if(t) printf("δ�ҵ�!\n");
    t=1;
  
 }
 printf("���������밴�س����������밴�ո��:\n");
 ch1=getchar();                              //���س�������CH1������CASE�����������Ļس����ḳ��CH�������CH1���
 ch=getchar();
 }
}
 

SUB *insert(SUB *head)   //����
{
 SUB *ptr,*ptr2,*subj;
 int size=sizeof(SUB);
 char ch='a',ch1;
 while(ch!=' '){
      subj=(SUB *)malloc(size);
      ptr=subj;
      printf("����Ҫ����Ŀγ���Ϣ:\n");
      scanf("%d%s%s%d%d%d%d%d",&subj->num,subj->name,subj->kind,&subj->stime,&subj->ttime,&subj->etime,&subj->score,&subj->term);
       if(head==NULL){
         head=ptr;
         head->next=NULL;
    }
       else{
          for(ptr2=head;ptr2;ptr2=ptr2->next)
             if(ptr2->next==NULL){
             ptr2->next=subj;
             subj->next=NULL;
             break;
       }
    }
    printf("���������밴�س��������밴�ո�:\n");
    ch1=getchar();                      //���س�������CH1������subj->term���������Ļس����ḳ��CH�������CH1���
    ch=getchar();
    }
 return head;
}
  
 
 
 

SUB *del(SUB *head)   //ɾ��
{
 SUB *p1,*p2;
 char ch='a',ch1;
 int num;
 while(ch!=' '){
  printf("������Ҫɾ���Ŀγ̱��:\n");
     scanf("%d",&num);
     if(head->num==num){
      p2=head;
      head=head->next;
      free(p2);
  }
     if(head==NULL)
      return NULL;
     p1=head;
     p2=head->next;
     while(p2){
    if(p2->num==num){
       p1->next=p2->next;
       free(p2);
    }
     else p1=p2;
     p2=p1->next;
  }
  printf("����ɾ���밴�س��������밴�ո�:\n");
  ch1=getchar();                       //���س�������CH1������num�����������Ļس����ḳ��CH�������CH1���
  ch=getchar();
 }
 return head;
}
 
void choose(SUB *head)
{
 SUB *p,*q;
 int a[5];
 int num,total=0,i=0,j;
 printf("����Ҫѡ�޵Ŀγ̵ı�ţ����֮���Կո�ֿ����������0����\n");
 scanf("%d",&num);
 while(num!=0){
  for(p=head;p;p=p->next)
   if(p->num==num){
    total=total+p->score;
    a[i]=num;
    i++;
   }
   scanf("%d",&num);
 }
 if(total<60) printf("ѡ����ѧ��δ�ﵽ60,ѡ��ʧ��!\n");
 else {
  printf("ѡ�޳ɹ�!\n");
  printf("��ѡ�޵Ŀγ�Ϊ:\n");
 for(j=0;j<i;j++)  

    for(q=head;q;q=q->next)
    if(q->num==a[j])
     printf("%s  ",q->name);
 printf("\n");
printf("***********************************\n");
printf("  ��ԴѧԺʯ�Ͷ��������� \n");
printf("***********************************\n");
   
    }
}
 

void main()
{
 SUB *head=create_form();
 savefile(head);
 prin(head);
 search(head);
 head=insert(head);                        //ע��˴��ı�Ҫ�ԣ�����insert�ĵķ���ֵ���¸���head!
 savefileadd(head);
 printf("�޸ĺ����ϢΪ:\n");
 prin(head);
 head=del(head);                           //ע��˴��ı�Ҫ�ԣ�����del�ĵķ���ֵ���¸���head!
 savefiledel(head);
 printf("�޸ĺ�Ŀγ���ϢΪ:\n");
 prin(head);
 choose(head);

}



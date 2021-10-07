#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct subjects   //struct是定义一个结构体，可以包含各种类型的信息 
{
 int num;
 char name[20];
 char kind[10];
 int stime;
 int ttime;
 int etime;
 int score;
 int term;
 struct subjects *next;     //这个结构体中又嵌套了一个结构体，建立了一个链表，指向下一个成员 
}SUB;
 
SUB *create_form()    //录入
{
 SUB *head,*tail,*p;
 int num,stime,ttime;
 int etime,score,term;
 char name[20],kind[10];
 int size=sizeof(SUB);
 head=tail=NULL;
 printf("输入选修课程信息:\n");
 scanf("%d %s %s %d %d %d %d %d",&num,&name,&kind,&stime,&ttime,&etime,&score,&term);
 while(num!=0){
  p=(SUB *)malloc(size);
  p->num=num;  //等价于（*p).num,表示p指向的结构体中的num成员 
  strcpy(p->name,name);
  strcpy(p->kind,kind);
  p->stime=stime;
  p->ttime=ttime;
  p->etime=etime;
  p->score=score;
  p->term=term;
 if(head==NULL)  //NULL相当于空，循环截至 
  head=p;
 else
  tail->next=p;
 tail=p;
 scanf("%d %s %s %d %d %d %d %d",&num,&name,&kind,&stime,&ttime,&etime,&score,&term);
 }
 tail->next=NULL;
 return head;
}
 
void savefile(SUB *head)    //保存
{
 SUB *p;
 FILE *fp;
 fp=fopen("subjects.txt","w");
 fprintf(fp,"课程编号  课程名称  课程性质  总学时  授课学时  实验或上机学时  学分  开课学期\n");
 for(p=head;p;p=p->next)
  fprintf(fp,"%5d%12s%9s%9d%9d%11d%11d%7d\n",p->num,p->name,p->kind,p->stime,p->ttime,p->etime,p->score,p->term);
 fclose(fp);
}
 
void savefileadd(SUB *head)  //添加
{
 SUB *p;
 FILE *fp;
 fp=fopen("subjectsadd.txt","w");
 fprintf(fp,"课程编号  课程名称  课程性质  总学时  授课学时  实验或上机学时  学分  开课学期\n");
 for(p=head;p;p=p->next)
  fprintf(fp,"%5d%12s%9s%9d%9d%11d%11d%7d\n",p->num,p->name,p->kind,p->stime,p->ttime,p->etime,p->score,p->term);
 fclose(fp);
}
 
void savefiledel(SUB *head)  
{
 SUB *p;
 FILE *fp;
 fp=fopen("subjectsdel.txt","w");
 fprintf(fp,"课程编号  课程名称  课程性质  总学时  授课学时  实验或上机学时  学分  开课学期\n");
 for(p=head;p;p=p->next)
  fprintf(fp,"%5d%12s%9s%9d%9d%11d%11d%7d\n",p->num,p->name,p->kind,p->stime,p->ttime,p->etime,p->score,p->term);
 fclose(fp);
}
 
void prin(SUB *head)
{
 SUB *ptr;
 if(head==NULL){
  printf("没有此门课程记录!\n");
  return;
 }
 printf("课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期\n");
 for(ptr=head;ptr;ptr=ptr->next)
  printf("%5d%12s%9s%9d%9d%11d%11d%7d\n",ptr->num,ptr->name,ptr->kind,ptr->stime,ptr->ttime,ptr->etime,ptr->score,ptr->term);
}

void search(SUB *head)  //查询
{
 int a,num;
 int t=1;
 char type[10];
 char ch='a',ch1;
 SUB *ptr;
 
 while(ch!=' '){
  printf("若要按课程性质查找请输入1，若要按学分查找请输入2:\n");
  scanf("%d",&a);
  switch(a){
  case 1:printf("请输入要查找的课程的性质:\n");
   scanf("%s",type);
   printf("课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期\n");
   for(ptr=head;ptr;ptr=ptr->next)
    if(strcmp(type,ptr->kind)==0){
     printf("%5d%12s%9s%9d%9d%11d%11d%7d\n",ptr->num,ptr->name,ptr->kind,ptr->stime,ptr->ttime,ptr->etime,ptr->score,ptr->term);
           t=0;
    }
    if(t) printf("未找到!\n");
    t=1;
   break;
  case 2:printf("输入要查找的课程的学分\n");
   scanf("%d",&num);
   printf("课程编号  课程名称  课程性质  总学时  授课学时  实践或上机学时  学分  开课学期\n");
   for(ptr=head;ptr;ptr=ptr->next)
    if(ptr->score==num){
     printf("%5d%12s%9s%9d%9d%11d%11d%7d\n",ptr->num,ptr->name,ptr->kind,ptr->stime,ptr->ttime,ptr->etime,ptr->score,ptr->term);
                    t=0;
    }
    if(t) printf("未找到!\n");
    t=1;
  
 }
 printf("继续查找请按回车键，结束请按空格键:\n");
 ch1=getchar();                              //将回车键赋给CH1，否则CASE里面最后输入的回车键会赋给CH，因此用CH1填补。
 ch=getchar();
 }
}
 

SUB *insert(SUB *head)   //插入
{
 SUB *ptr,*ptr2,*subj;
 int size=sizeof(SUB);
 char ch='a',ch1;
 while(ch!=' '){
      subj=(SUB *)malloc(size);
      ptr=subj;
      printf("输入要插入的课程信息:\n");
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
    printf("继续插入请按回车，结束请按空格:\n");
    ch1=getchar();                      //将回车键赋给CH1，否则subj->term输完后输入的回车键会赋给CH，因此用CH1填补。
    ch=getchar();
    }
 return head;
}
  
 
 
 

SUB *del(SUB *head)   //删除
{
 SUB *p1,*p2;
 char ch='a',ch1;
 int num;
 while(ch!=' '){
  printf("输入想要删除的课程编号:\n");
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
  printf("继续删除请按回车，结束请按空格:\n");
  ch1=getchar();                       //将回车键赋给CH1，否则num输完后再输入的回车键会赋给CH，因此用CH1填补。
  ch=getchar();
 }
 return head;
}
 
void choose(SUB *head)
{
 SUB *p,*q;
 int a[5];
 int num,total=0,i=0,j;
 printf("输入要选修的课程的编号，编号之间以空格分开，输完后以0结束\n");
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
 if(total<60) printf("选修总学分未达到60,选修失败!\n");
 else {
  printf("选修成功!\n");
  printf("您选修的课程为:\n");
 for(j=0;j<i;j++)  

    for(q=head;q;q=q->next)
    if(q->num==a[j])
     printf("%s  ",q->name);
 printf("\n");
printf("***********************************\n");
printf("  资源学院石油二班严礼宇 \n");
printf("***********************************\n");
   
    }
}
 

void main()
{
 SUB *head=create_form();
 savefile(head);
 prin(head);
 search(head);
 head=insert(head);                        //注意此处的必要性，函数insert的的返回值重新赋给head!
 savefileadd(head);
 printf("修改后的信息为:\n");
 prin(head);
 head=del(head);                           //注意此处的必要性，函数del的的返回值重新赋给head!
 savefiledel(head);
 printf("修改后的课程信息为:\n");
 prin(head);
 choose(head);

}



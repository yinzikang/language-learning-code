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
printf("1.增加建筑工地信息\n2.增加配件信息\n3.增加销售商信息\n4.增加销售商-配件-建筑工地信息\n");
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
printf("请输入建筑工地名称:");  
scanf("%s",build.name);  
printf("请输入建筑工地编号:");  
scanf("%s",build.num);  
printf("请输入工地所在城市:");  
scanf("%s",build.city); 
 fwrite(&build,sizeof(struct building),1,fp);  
printf("是否继续y/n:\n");  
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
printf("请输入配件名称:");  
scanf("%s",pj.p_name);  
printf("请输入配件编号:");  
scanf("%s",pj.p_num);  
printf("请输入配件颜色:");  
scanf("%s",pj.p_colour); 
printf("请输入配件重量:");  
scanf("%s",pj.p_weight); 
printf("请输入配件产地:");  
scanf("%s",pj.p_area); 
 fwrite(&pj,sizeof(struct peijian),1,fp);  
printf("是否继续y/n:\n");  
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
printf("请输入销售商名称:");  
scanf("%s",bus.b_name);  
printf("请输入销售商编号:");  
scanf("%s",bus.b_num);  
printf("请输入销售商状态:");  
scanf("%s",bus.b_state); 
printf("请输入销售商所在城市:");  
scanf("%s",bus.b_city); 
 fwrite(&bus,sizeof(struct business),1,fp);  
printf("是否继续y/n:\n");  
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
printf("请输入销售商号码:");  
scanf("%s",bpb.b_num);  
printf("请输入配件编号:");  
scanf("%s",bpb.b_num);  
printf("请输入建筑工地编号:");  
scanf("%s",bpb.num); 
printf("请输入销售商为工地提供配件数量:");  
scanf("%s",bpb.num2); 
 fwrite(&bpb,sizeof(struct total),1,fp);  
printf("是否继续y/n:\n");  
scanf(" %c",&flag);  
}  
fclose(fp);  
} 
void modify()
{
printf("1.修改建筑工地信息\n2.修改配件信息\n3.修改销售商信息\n4.修改销售商-配件-建筑工地信息\n");
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

printf("请输入您要修改的建筑工地名称:");  
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

 printf("建筑工地名称:%s\n",build.name);  
printf("建筑工地编号:%s\n",build.num);  
printf("建筑工地所在城市:%s\n",build.city); 
 printf("请输入建筑工地名称:");  
scanf("%s",build.name);  
printf("请输入建筑工地编号:");  
scanf("%s",build.num);  
printf("请输入建筑工地所在城市:");  
scanf("%s",build.city); 

fseek(fp,-(long)(sizeof(struct building)),1);  
fwrite(&build,sizeof(build),1,fp);  

}  
printf("是否继续:"); 
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

printf("请输入您要修改的配件名称:");  
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

 printf("配件名称:%s\n",pj.p_name);  
printf("配件编号:%s\n",pj.p_num); 
printf("配件颜色:%s\n",pj.p_colour); 
printf("配件重量:%s\n",pj.p_weight);  
printf("配件产地:%s\n",pj.p_area); 
 printf("请输入配件名称:");  
scanf("%s",pj.p_name);  
printf("请输入配件编号:");  
scanf("%s",pj.p_name); 
printf("请输入配件颜色:");  
scanf("%s",pj.p_colour); 
printf("请输入配件重量:");  
scanf("%s",pj.p_weight);  
printf("请输入配件产地:");  
scanf("%s",pj.p_name); 

fseek(fp,-(long)(sizeof(struct peijian)),1); 
fwrite(&pj,sizeof(pj),1,fp);  

}  
printf("是否继续:"); 
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

printf("请输入您要修改的销售商名称");  
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

 printf("销售商名称:%s\n",bus.b_name);  
printf("销售商编号:%s\n",bus.b_name);  
printf("销售商状态:%s\n",bus.b_state); 
printf("所在城市:%s\n",bus.b_city); 
 printf("请输入名称:");  
scanf("%s",bus.b_name);  
printf("请输入编号:");  
scanf("%s",bus.b_num);  
printf("请输入状态:");  
scanf("%s",bus.b_state); 
printf("请输入所在城市名:"); 
scanf("%s",bus.b_city);  

fseek(fp,-(long)(sizeof(struct business)),1);
fwrite(&bus,sizeof(bus),1,fp);  

}  
printf("是否继续:");
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
printf("请输入您要修改的对应对中销售商编号:");  
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

 printf("销售商编号:%s\n",bpb.b_num);  
printf("配件编号:%s\n",bpb.p_num);  
printf("建筑工地编号:%s\n",bpb.num); 
printf("提供配件数量:%s\n",bpb.num2); 
 printf("请输入销售商编号:");  
scanf("%s",bpb.b_num);  
printf("请输入配件编号:");  
scanf("%s",bpb.p_num);  
printf("请输入建筑工地编号:");  
scanf("%s",bpb.num); 
printf("请输入提供配件数量:"); 
scanf("%s",bpb.num2);  

fseek(fp,-(long)(sizeof(struct total)),1);  
fwrite(&bpb,sizeof(bpb),1,fp);  

}  
printf("是否继续:");
scanf(" %c",&flag);  
}  
fclose(fp); 
} 
void del()
{
printf("1.删除建筑工地信息\n2.删除配件信息\n3.删除销售商信息\n4.删除销售商-配件-建筑工地信息\n");
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
 printf("打开文件出错"); 
while(flag=='y')  
{  
printf("请输入工地名:");  
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
 printf("建筑工地名称:%s\n",build.name);  
 printf("建筑工地编号:%s\n",build.num);  
 printf("建筑工地所在城市:%s\n",build.city); 
 printf("是否确定删除y/n:");  
scanf("%c",&n);  
if(n=='y')  
strcpy(build.name,"");  
strcpy(build.num,"");  
strcpy(build.city,"");  
fseek(fp,-(long)(sizeof(struct building)),1);  
 fwrite(&build,sizeof(build),1,fp);  
printf("删除成功\n");  
}  
printf("是否继续删除y/n:\n");  
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
 printf("打开文件出错");  
while(flag=='y')  
{  
printf("请输入配件名称:");  
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
 printf("名称:%s\n",pj.p_name);  
 printf("编号:%s\n",pj.p_num); 
 printf("颜色:%s\n",pj.p_colour); 
 printf("重量:%s\n",pj.p_weight); 
 printf("产地:%s\n",pj.p_area); 
 printf("是否确定删除y/n:");  
scanf("%c",&n);  
if(n=='y')  
strcpy(pj.p_name,"");  
strcpy(pj.p_num,""); 
strcpy(pj.p_colour,""); 
strcpy(pj.p_weight,"");  
strcpy(pj.p_area,"");  
fseek(fp,-(long)(sizeof(struct peijian)),1);  
 fwrite(&pj,sizeof(pj),1,fp);  
printf("删除成功\n");  
}  
printf("是否继续删除y/n:\n");  
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
 printf("打开文件出错");  
while(flag=='y')  
{  
printf("请输入销售商名称:");  
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
 printf("销售商名称:%s\n",bus.b_name);  
 printf("销售商编号:%s\n",bus.b_num); 
 printf("销售商状态:%s\n",bus.b_state); 
 printf("销售商所在城市:%s\n",bus.b_city); 
 printf("是否确定删除y/n:");  
scanf("%c",&n);  
if(n=='y')  
strcpy(bus.b_name,"");  
strcpy(bus.b_num,""); 
strcpy(bus.b_state,"");  
strcpy(bus.b_city,"");  
fseek(fp,-(long)(sizeof(struct business)),1);  
 fwrite(&bus,sizeof(bus),1,fp);  
printf("删除成功\n");  
}  
printf("是否继续删除y/n:\n");  
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
 printf("打开文件出错");  
while(flag=='y')  
{  
printf("请输入销售商编号:");  
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
 printf("销售商编号:%s\n",bpb.b_num);  
 printf("配件编号:%s\n",bpb.p_num); 
 printf("建筑工地编号:%s\n",bpb.num); 
 printf("提供配件数量:%s\n",bpb.num2); 
 printf("是否确定删除y/n:");  
scanf("%c",&n);  
if(n=='y')  
strcpy(bpb.b_num,"");  
strcpy(bpb.p_num,""); 
strcpy(bpb.num,"");  
strcpy(bpb.num2,"");  
fseek(fp,-(long)(sizeof(struct total)),1);  
 fwrite(&bpb,sizeof(bpb),1,fp);  
printf("删除成功\n");  
}  
printf("是否继续删除y/n:\n");  
scanf(" %c",&flag);  
}  
fclose(fp);  
} 
void seek()
{
printf("1.查询与供应商所在城市相同的零件-供应商记录对\n2.查询与供应商所在城市相同的项目-供应商记录对\n");  
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
printf("配件名称:%s\n",pj.p_name);  
printf("配件编号:%s\n",pj.p_num); 
printf("配件颜色:%s\n",pj.p_colour); 
printf("配件重量:%s\n",pj.p_weight);  
printf("配件产地:%s\n",pj.p_area);  
printf("名称:%s\n",bus.b_name);  
printf("编号:%s\n",bus.b_num); 
printf("状态:%s\n",bus.b_state); 
printf("销售商所在城市:%s\n",bus.b_city); 
} 
printf("是否继续:");  
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
printf("建筑工地名称:%s\n",build.name);  
printf("建筑工地编号:%s\n",build.num);  
printf("建筑工地所在城市:%s\n",&build.city); 
printf("名称:%s\n",bus.b_name);  
printf("编号:%s\n",bus.b_num); 
printf("状态:%s\n",bus.b_state); 
printf("销售商所在城市:%s\n",bus.b_city); 
} 
printf("是否继续:"); 
scanf(" %c",&flag);  
}  
fclose(fp1); 
fclose(fp2); 
} 
  

void main() 
{ printf("/**********************欢迎使用何雨涛的建筑工地信息管理系统*******************/\n"); 
while(n!=5) 
{ 

printf("1.增加信息\n2.删除信息\n3.修改信息\n4.查询\n5.退出\n");  
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

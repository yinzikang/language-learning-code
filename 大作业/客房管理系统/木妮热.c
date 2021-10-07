#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct client
{
	char name[20];
	char sex[5];
	int age;
	char ID_card[20];
	int year;
	int month;
	int date;
};
struct hotel
{
	 int room_ID;
	 long int tel;
	 int price;
	 int sign;
	 struct client client_list;
}room[2000];
int a=016,b=017;
void return_confirm(void)
{ 
	printf("\n按任意键返回……\n");
    getchar();
}

void main()
{
	void menu();
	
	menu();
}
void menu ()             
{
	void regist();
	void stati();
	void search();
	void modify();
	void fexit();
	int i;
	printf("\n\t\t%c %c %c %c %c %c %c %c 欢迎进入客房管理系统 %c %c %c %c %c %c %c %c\n\n\n",b,a,b,a,b,a,b,a,b,a,b,a,b,a,b,a);
    printf("\t*********************************************************************\n\n");
	printf("\t\t\t\t (1).登记  \n");
    printf("\t\t\t\t (2).统计  \n");
    printf("\t\t\t\t (3).查询  \n");
    printf("\t\t\t\t (4).修改  \n");
    printf("\t\t\t\t (5).退出  \n");
    printf("\n\t**********************************************************************\n");
	printf("Choice your number(1-5): [ ]\b\b");
	scanf("%d",&i);
	while (i<1||i>5)
	{
		printf("选择错误，请重新选择(1-5): [ ]\b\b");
		scanf("%d",&i);
	}
	switch(i)
	{
	case 1:regist();break;
    case 2:stati();break;
    case 3:search();break;
    case 4:modify();break;
    case 5:fexit();break;
	}
}
void regist()                           
{   
    void printf_one(int i);   
    void save(int n);   
    void printf_back();   
    int load();   
    void printf_face();   
    int i,n,c,w; 
    n=load();   
    do   
    {   
        for(i=0;i<n;i++)   
		{      
           if(room[i].sign==1)    
		   {   
                printf("\nroom[%d] has been full\n",room[i].room_ID); 
				printf("Do you want to back?\n\n  1).Yes\t\t2).No: [ ]\b\b");   
                scanf("%d",&w);   
                if(w==1) 
                menu();
		   }   
           else    
		   {   
               printf("\nregister new record\n");   
               printf("\nRoom[%d] is empty",room[i].room_ID);   
               printf("\nplease enter Room[%d]'s information",room[i].room_ID);   
               printf("\nplease enter customer's Name :");   
               scanf("%10s",&room[i].client_list.name);   
               printf("\nplease enter Sex :");
			   scanf("%3s",&room[i].client_list.sex);
			   printf("\nplease enter Age :");
               scanf("%3d",&room [i].client_list.age);   
               printf("\nplease enter customer's ID_card :");   
               scanf("%s",&room[i].client_list.ID_card);   
               printf("\nplease enter year and month and date(如:2012-2-17) :");  
               scanf("%d-%d-%d",&room [i].client_list.year,&room[i].client_list.month,&room [i].client_list.date);   
               room[i].sign=1;                     
               printf_one(i);   
               printf("\n\nAre you sure?\n\n1.sure\t  2.cancle and again\t3.Back without save : [ ]\b\b");   
               scanf("%d",&c);   
               if(c==1)   
			   {  				      
                   printf_back();   
			   }   
               else if(c!=2)  menu();   
		   }   
		}   
    }
	while(c==2);
	return_confirm();
} 
int load()   
{   
     FILE *fp;   
     int i;   
     if((fp=fopen("Hotel.txt","w+"))==NULL)   
     {   
         printf("\nCannot open file\n");     
     }   
     for(i=0;!feof(fp);i++)   
     fscanf(fp,"\n%s%s%ld%d%s%d%d%s%d%d%d\n",&room [i].room_ID,&room[i].tel,&room[i].price,&room[i].sign,&room[i].client_list.name,&room [i].client_list.sex,&room[i].client_list.age,&room [i].client_list.ID_card,&room[i].client_list.year,&room [i].client_list.month,&room[i].client_list.date);   
     fclose(fp);   
     return(i);   
}
void printf_one(int i)   
{   
    printf("\n\n房间号\t    房间电话\t    房间价格\t  是否入住(0未住/1已住)");
	printf("\n  %d\t\t%ld\t\t%d\t\t%d",room[i].room_ID,room[i].tel,room [i].price,room[i].sign);  
	printf("\n\n顾客姓名\t顾客性别\t顾客年龄\t身份证号\t入住时间");
    printf("\n %s\t\t  %s\t\t   %d\t\t  %s\t\t %d-%d-%d\n",room[i].client_list.name,room [i].client_list.sex,room[i].client_list.age,room[i].client_list.ID_card,room[i].client_list.year,room [i].client_list.month,room[i].client_list.date);      
}
void save(int n)   
{   
    FILE *fp;   
    int i;   
    if((fp=fopen("Hotel.txt","w+ "))==NULL)   
    {   
        printf("\nCan not open file\n");            
    }   
    for(i=0;i<n;i++)   
    fprintf(fp,"%d\t%ld\t%d\t%d\t%s\t%d\t%s\t%s\t%d-%d-%d\n",room[i].room_ID,room[i].tel,room[i].price,room[i].sign,room[i].client_list.name,room[i].client_list.sex,room[i].client_list.age,room[i].client_list.ID_card,room[i].client_list.year,room[i].client_list.month,room[i].client_list.date);   
    fclose(fp);   
}
void printf_face()   
{   
    printf("\nroom_ID tel price sign");   
    printf("\nname sex age ID_card");   
    printf("\nyear month date");   
}   
void printf_back()  
{   
    int w;   
    printf("\n\n\t\tSuccessful.^-^\n\n");   
    printf("Do you want to back?\n\n  1).Yes\t\t2).No: [ ]\b\b");   
    scanf("%d",&w);   
    if(w==1) 
    menu(); 
}
void stati()                     
{   
    void time_stati();   
    void room_ID_stati();   
    void price_stati();   
    int c;   
    do   
    {   
        printf("\n\nstatistic by =>\n\n1).Time\t\t2).Room_ID\t\t3) Price");   
        printf("\nWhich you need<1-3>?:[ ]\b\b");   
        scanf("%d",&c);   
        if(c>3||c<1)   
        {   
            puts("\nChoice errror!Please again!");   
            getchar();   
        }   
    }while(c>3||c<1);   
    switch(c)   
    {   
        case 1:time_stati();break;   
        case 2:room_ID_stati();break;   
        case 3:price_stati();break;   
    } 
   return_confirm();	
} 
void time_stati()                   
{   
    int n,i,k=0,w,w0=1,w2=0;   
    struct hotel s;   
    n=load();   
    do   
    {   
        do   
		{   
            w=-1;   
            printf("\nplease enter the time that you want to statistic.\n");   
            printf("\nplease enter the year: ");   
            scanf("%d",&s.client_list.year);   
            printf("\nplease enter the month: ");   
            scanf("%d",&s.client_list.month);   
            printf("\nplease enter the date: ");   
            scanf("%d",&s.client_list.date);   
            for(i=0,k=0;i<n;i++)   
            if(s.client_list.year==room [i].client_list.year&&s.client_list.month==room [i].client_list.month&&s.client_list.date==room[i].client_list.date)   
			{   
                w=i;   
                printf_face();   
                printf_one(i);   
                k++;   
			}   
            printf("\nThere are %d recorders this day!",k);   
            if(w==-1)   
			{                    
               printf("\n\nDo you want to retry another?\n\n1).Yes\t\t2).No and back\t\t3).Back to menu  [ ]\b\b");   
               scanf("%d",&w0);    
               if(w0==2)  stati();   
               else if(w0!=1)  menu();   
			}   
            else   
			{  
			   printf("\n\tSuccessful!^_^ ^_^.\nEnter another time?\n\n1).Yes \t\t2).Back to menu\t[ ]\b\b");   
               scanf("%d",&w2);   
              if(w2!=1)  menu();   
			}   
		}
		while(w==-1&&w0==1);   
    }
	while(w2==1);   
}   
void room_ID_stati()                         
{   
    int n,i,k=0,w,w0=1,w2=0;   
    struct hotel s;   
    n=load();   
    do   
    {   
        do   
		{   
            w=-1;   
            printf("\nplease enter the room_ID that you want to statistic.\n");   
            scanf("%s",&s.room_ID);   
            for(i=0,k=0;i<n;i++)   
            if(s.room_ID==room[i].room_ID) 
			{   
                w=i;   
                printf_face();   
                printf_one(i);   
                k++;   
			}   
            printf("\nThere are %d recorders  in this Room!",k);   
            if(w==-1)   
			{                      
                 printf("\nDo you want to retry another?\n\n1).Yes\t\t2).No and back\t\t3).Back to menu  [ ]\b\b");   
                 scanf("%d",&w0);    
                 if(w0==2)  stati();   
                 else if(w0!=1)  menu();   
			}   
            else   
			{  
				printf("\nSuccessful!  ^_^ ^_^.\nEnter another Room_ID?\n\n1).Yes \t\t2).Back to menu\t[ ]\b\b");   
                scanf("%d",&w2);   
                if(w2!=1)  menu();   
			}   
		}
		while(w==-1&&w0==1);   
    }
	while(w2==1);   
} 
void price_stati()                     
{   
    int n,i,k=0,w,w0=1,w2=0;   
    struct hotel s;   
    n=load();   
    do   
    {   
       do   
	   {   
           w=-1;   
           printf("\nplease enter the room's price that you want to statistic.\n");   
           scanf("%d",&s.price);   
           for(i=0,k=0;i<n;i++)   
           if(s.price==room[i].price)   
		   {   
               w=i;   
               printf_face();   
               printf_one(i);   
               k++;   
		   }   
           printf("\nThere are %d recorders at this price!",k);   
           if(w==-1)   
		   {                    
               printf("\nDo you want to retry another?\n\n1).Yes\t\t2).No and back\t\t3).Back to menu  [ ]\b\b");   
               scanf("%d",&w0);    
               if(w0==2)  stati();   
               else if(w0!=1)  menu();   
		   }   
           else   
		   {  
			   printf("\nSuccessful!.\nEnter another Room'price?\n\n1).Yes\t\t2).Back to menu\t[ ]\b\b");   
               scanf("%d",&w2);   
               if(w2!=1)  menu();   
		   }   
	   }
	   while(w==-1&&w0==1);   
    }
	while(w2==1);   
}
void search()                    
{   
       
    int i,n,k,w1=1,w2,w3;   
    struct hotel s;   
    n=load();   
    do   
    {   
        w2=-1;   
        do
		{   
            k=-1;   
            printf("\n\nEnter ID_card that you want to search! ID_card:");   
            scanf("%s",&s.client_list.ID_card);   
            for(i=0;i<n;i++)   
            if(strcmp(s.client_list.ID_card,room[i].client_list.ID_card)==0)   
            {   
                k=i;   
                w2=1;   
                printf_one(k);   
                break;   
            }   
            if(k==-1)   
            {   
                printf("\n\nNo fexit!Please.");   
                printf("\n\nAre you again ?\n1).again\t\t2).No and back  [ ]\b\b");   
                scanf("%d",&w1);   
                if(w1!=1)  menu();   
            }   
		}
		while(k==-1&&w1==1);          
        if(w2==1)   
		{   
             printf("\n\nSuccessful.^_^.\n");   
             printf("\nWhat do you want to do?\n1).Search another\t\t2).Back to menu  [ ]\b\b");   
             scanf("%d",&w3);   
             if(w3!=1)  menu();   
		}   
    }
	while(w3==1);   
}
void modify()  
{   
    int modify_date(int i,int k);   
    struct hotel s;   
    int i,n,k,w0=1,w1,w2=0;   
    n=load();   
    do   
    {   
        k=-1;             
        for(i=0;i<n;i++)   
        {   
            if((i!=0)&&(i%4)==0)   
            {   
                printf("\n\nRemember room_ID that you need to modify! Pass any key to continue ...");   
                getchar();   
                puts("\n\n");   
            }   
            printf_one(i);   
		}   
        do   
		{   
            printf("\n\nEnter room_ID that you want to modify! room_ID:");   
            scanf("%d",s.room_ID);   
            for(i=0;i<n;i++)   
            if(s.room_ID==room[i].room_ID)   
            {   
                k=i;   
                s=room[i];   
            }   
            if(k==-1)  printf("\n\nNo exist! Please again");   
		}
		while(k==-1);   
        printf_face();   
        printf_one(k);   
        w1=modify_date(k,n);   
        if(w1==1)   
		{   
            printf("\n\nSuccessful ^_^ ^_^.\nAre you modify another?\n\n\t1).Yes \t2).Back with save\t[ ]\b\b");   
            scanf("%d",&w0);   
            w2=1;   
		}   
        else    
		{   
            w0=0;   
            if(w2==1)   
            room[i]=s;   
		}   
        if(w0!=1&&w2==1)   
        save(n);   
	}
	while(w0==1);   
    menu();   
}  
int modify_date(int i,int k)   
{   
    int c,w1;   
    do   
    {   
        puts("\n\nmodify by =>\n\n\t1).name \t2).sex \t3).age\n \t4).ID_card \t5).time \t6).All information \t7).Cancle and back");   
        printf("Which you need?:[ ]\b\b");   
        scanf("%d",&c);   
        if(c>7||c<1)   
        {   
            puts("\nChoice errror!Please again!");   
            getchar();   
        }   
	}
    while(c>7||c<1);     
    do   
    {   
        switch(c)   
        {   
        case 1:printf("\nPlease enter new Name: ");
			   scanf("% s",&room[i].client_list.name);break;   
        case 2:printf("\nPlease enter new Sex:");
			   scanf("%s",&room[i].client_list.sex);break;   
        case 3:printf("\nPlease enter new Age:");
			   scanf("%d",&room[i].client_list.age);break;   
        case 4:printf("Please enter new ID_card:");
		       scanf("%s",&room[i].client_list.ID_card);break;      
        case 5:printf("Please enter new year month date(如2012-2-17):");
			   scanf("%d-%d-%d",&room[i].client_list.year,&room[i].client_list.month,&room [i].client_list.date);break;   
        case 6:printf("Please enter new All information:");   
               puts("\nplease enter customer's new Name\n");   
               scanf("%s",&room[i].client_list.name);   
               printf("\nplease enter new sex and age\n");   
               scanf("%3d %3d",&room[i].client_list.sex,&room [i].client_list.age);   
               puts("\nplease enter new customer's ID_card\n");   
               scanf("%20s",&room[i].client_list.ID_card);   
               printf("\nplease enter new year and month and date(如2012-2-17):\n");   
               scanf("%d-%d-%d",&room [i].client_list.year,&room[i].client_list.month, &room[i].client_list.date);break;   
        case 7:menu();  
               puts("\nNow ,please ensure the information you entered.");   
               printf_face();   
               printf_one(i);   
               printf("\nAre you sure?\n\n\t1).Sure \t2).No and remodify \t3).Back without save in this time [ ]\b\b");   
               scanf("%d",&w1);  
	   }

	}
	while(w1==2);   
    return(w1);
}
void fexit()
{
	printf("\n\n\t\t\t感谢使用本系统！\n");
	printf("\t\t\t\t谢谢！\n");
}
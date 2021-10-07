#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

//说明：这个程序中的管理员，店长，销售员密码都是6位的。 
// 管理员默认用户名是admin,密码是123456。 


////////////////////////////////////////////////////////////////////////////////
///////////////////////////////结构体定义///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

typedef struct admin           //定义管理员结构体
{
    char name[20];
    char pass[20];
}ADMIN;



typedef struct                // 定义商品结构体 
{
    char name[30];
    int now;
    int total; 
    int flag;
}DRESS;

typedef struct              //定义用户结构体 
{
    int flag; 
    int type;
	char username[20];
	char pass[20];
	DRESS mdb[100];
}USER; 


USER usertemp;
int usernum=0;   //记录销售员的数量 

////////////////////////////////////////////////////////////////////////////////
///////////////////////////////服装的模块///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int adddress(DRESS *dress)
{
    char name[20];
    int total;
    int i;
    
    system("cls");
    printf("  /======================================================================/\n");
    printf("  /======================服装销售系统系统商品添加=====================＝=/\n");
    printf("  /======================================================================/\n\n\n\n");
    printf("         请输入商品的名称：");
    scanf("%s",&name);
    printf("\n         请输入入库的商品的数量：") ;
    scanf("%d",&total);
    
    printf("\n\n\n          商品信息输入完毕！\n\n\n");
    
    
    for(i=0;i<500;i++)
    {
        if(dress[i].flag==0)
        {
            strcpy(dress[i].name,name);
            dress[i].total=total;
            dress[i].now=total;
            dress[i].flag=1;
            system("pause");
            return 1;
        }
        
    }
    
    return 0;

} 
//============================================================================
int deldress(DRESS *dress)
{
    char name[20];
    //int total;
    int i;
    
    system("cls");
    printf("  /======================================================================/\n");
    printf("  /======================服装销售系统系统商品删除=====================＝=/\n");
    printf("  /======================================================================/\n\n\n\n");
    printf("         请输入需要删除的商品的名称：");
    scanf("%s",&name);

    
    for(i=0;i<250;i++)
    {
        if(strcmp(dress[i].name,name)==0)
        {
            printf("\n\n\n             商品删除完毕！\n\n\n");
            dress[i].flag=0;
            system("pause");
            return 1;
        }
        
    }
    
    printf("\n\n\n             商品删除出现错误，请查正商品名称！\n\n\n"); 
    system("pause");
    return 0;

} 
//============================================================================
int finddress(DRESS *dress)
{
    char name[20];
//    int total;
    int i;
    
    system("cls");
    printf("  /======================================================================/\n");
    printf("  /======================服装销售系统系统商品查找====================＝=/\n");
    printf("  /=====================================================================/\n\n\n\n");
    printf("         请输入需要查找的商品的名称：");
    scanf("%s",&name);

    
    for(i=0;i<250;i++)
    {
        if(strcmp(dress[i].name,name)==0)
        if(dress[i].flag==1)
        {
            printf("\n\n\n 商品查找完毕：\n          商品名称：   %s ,现存量：  %d,总库存：  %d\n",name,dress[i].now,dress[i].total);
            system("pause");
            return 1;
        }
        
    }
    
    printf("\n\n\n             商品查找出现错误，请查正商品名称！\n\n\n"); 
    system("pause");
    return 0;

} 

//============================================================================
void dressall(DRESS *dress)
{
     int i;
     system("cls");
     printf("  /======================================================================/\n");
     printf("  /======================服装销售系统系统查看商品=====================＝=/\n");
     printf("  /======================================================================/\n\n\n\n");
     
     for(i=0;i<500;i++)
     {
         if(dress[i].flag==1)
         printf("   商品的名称为：  %s ,商品的总量为：  %d ,商品的现存量   %d \n",dress[i].name,dress[i].total,dress[i].now);
     }
   system("pause");
}


////////////////////////////////////////////////////////////////////////////////
///////////////////////////////管理员模块///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void adminIntiate(ADMIN *adm)   //管理员密码用户名初始化 
{
     strcpy(adm->name,"admin");
     strcpy(adm->pass,"123456");
}
//=======================================================================
void userIntiate(USER *use)   //销售员密码用户名初始化 
{
	int j;
	for(j=0; j<200; j++)
	{
		 int i;
		 use[j].flag=0;
		 use[j].type=-1;
		 for(i=0;i<100;i++)
		 {
			  use[j].mdb[i].flag=0;
		 }
	}
}
//========================================================================
void dressIntiate(DRESS *dress)   //商品初始化 
{
	for(int i=0; i<500; i++)
	{
		dress[i].flag=0;
	}
}
//========================================================================
int regnew(USER *use)
{
    char name[21];
    char pass[7]={0};
	int chose;
	
	int i;
	int type;

   while(1)
	{
        system("cls");
        printf("  /======================================================================/\n");
		printf("  /======================服装销售系统系统用户注册=====================＝=/\n");
		printf("  /======================================================================/\n\n\n\n");
    

		
		printf("                           用户名：");
        scanf("%s",&name);
        printf("                           密  码：");

		for(i=0;i<6;i++)
		{
            pass[i]=getch();
            printf("*");
         }
         
        printf("\n\n                       请输入用户的类型：0，销售员 1，店长 ");
		scanf("%d",&type);

        while(1)
        {
           printf("\n\n               用户注册信息入完毕，是否确认?  1,确认 0，重新输入\n"); 
           scanf("%d",&chose);
           if(chose!=1&&chose!=0)
           {
                 printf("               你的输入有误，请重新的输入！\n");
                 continue;
           }
           
        if(chose==1)
        {
          for(i=0;i<usernum+1;i++)
          if(use[i].flag==0)
          {
              printf("                    注册成功！请继续使用！ \n");

              strcpy(use[i].username,name);
              strcpy(use[i].pass,pass);
              usernum++;
              use[i].flag=1;
              use[i].type=type;
              return 1;
           }
        }
        else break;
       } 
     }
} 

//==============================================================================
int deluser(USER *use)
{
    int i;
    char name[20];
    printf("  /======================================================================/\n");
    printf("  /======================服装销售系统用户删除============================/\n");
    printf("  /======================================================================/\n\n\n\n");
    
    printf("    请输入你想要删除的用户的用户名："); 
    scanf("%s",name);
    for(i=0;i<200;i++)
    {
          if(strcmp(use[i].username,name)==0)
          {
              printf("\n\n\n    用户  %s 删除成功！\n\n\n\n",name);
              strcpy(use[i].username,"unknown");
              use[i].flag=-1;
              return 1;
          }
    }
    printf("    用户  %s 不存在！请查正在次操作！\n\n\n\n",name);
    return 0;
}
//=============================================================================
int useall(USER *use)
{
    int i;
    system("cls");
    printf("  /======================================================================/\n");
    printf("  /======================服装销售系统用户查看＝＝＝======================/\n");
    printf("  /======================================================================/\n\n\n\n");
    printf("   销售人员：\n");
    for(i=0;i<200;i++)
    {
        if(use[i].type==0)
        {   
            
            if(use[i].flag==1)
            printf("              用户姓名：    %s 用户密码：   %s \n",use[i].username,use[i].pass);
        }
    }
    printf("   店长：\n");
    for(i=0;i<200;i++)
    {
        
        if(use[i].type==1)
        {   
            
            if(use[i].flag==1)
            printf("              用户姓名：    %s 用户密码：   %s \n",use[i].username,use[i].pass);
        }
    }
	return 0;
}
//=============================================================================
int adminload(ADMIN *adm)
{
    char name[21];
    char pass[7]={0};
	int chose,chose2;
	
	int i;
    while(1)
	{
        system("cls");
        printf("  /======================================================================/\n");
		printf("  /======================服装销售系统管理员登陆======================＝＝/\n");
		printf("  /======================================================================/\n\n\n\n");

		printf("                           管理员账号：");
        scanf("%s",&name);
        printf("                           密      码：");
		
		for(i=0;i<6;i++)
		{
            pass[i]=getch();
            printf("*");
         }

        while(1)
        {
           printf("\n\n               用户登陆信息输入完毕，是否确认?  1,确认 0，重新输入\n"); 
           scanf("%d",&chose);
           if(chose!=1&&chose!=0)
           {
                 printf("                  你的输入有误，请重新的输入！\n");
                 continue;
           }
           if(chose==1)
           {
                    if(strcmp(adm->name,name)==0)
                       if(strcmp(adm->pass,pass)==0)
                         {
                            printf("                         登陆成功！请继续使用！ \n");
                            strcpy(usertemp.username,name);
                            return 1;
                         }
          
                printf("                 输入的用户名或者密码有误！1,重新登陆 2，退出登陆！\n");
                scanf("%d",&chose2);
                if(chose2==1)
                {
                      system("cls");
                      break;
                }
                else 
                {
                     system("cls");
                     return 0;
                }
           } 
           if(chose==0) break;
         }
          
   } 
}
//=============================================================================
int adminpass(ADMIN *adm)
{
     int i;
     char pass[20]={0};
     char pass2[20]={0};
     
     while(1)
     {
           system("cls");
           printf("  /======================================================================/\n");
           printf("  /======================服装销售系统管理员密码修改＝＝＝================/\n");
           printf("  /======================================================================/\n\n\n\n");
           printf("   请输入新的管理员密码：");
          
           for(i=0;i<6;i++)
          {
              pass[i]=getch();
              printf("*");
          }
          
          
           printf("\n\n\n   请再次输入新的管理员密码：");
           for(i=0;i<6;i++)
           {
               pass2[i]=getch();
               printf("*");
           } 
           
           if(strcmp(pass,pass2)!=0)
           {
               printf("\n\n        两次输入的新的密码不一样，请重新的输入！\n\n\n");
               system("pause");
           }
           else
           {
               printf("\n        密码修改成功！下一次管理员登陆请使用新的密码！\n\n\n");
               strcpy(adm->pass,pass);
               system("pause");
               return 1;
           }
     } 
    
    
    
    
}
//=============================================================================
int adminout()
{
     int chose;
      
     while(1)
     {
        system("cls");
        printf("  /======================================================================/\n");
        printf("  /======================服装销售系统管理员注销＝＝＝============＝＝====/\n");
        printf("  /======================================================================/\n\n\n\n");
        printf("                  你确定要注销吗？ 1，注销  0，取消\n\n");
        scanf("%d",&chose);
     
        if(chose!=0&&chose!=1)
        {
              printf("                 你的选项出现了错误，请重新的输入！\n\n\n");
              system("pause");
              continue;
        }
        if(chose==1)
        {
              printf("                     管理员账户注销完毕！！ \n\n\n\n");    
              system("pause");   
              return 1;
        }
        else return 0;

     }
      
}
//=============================================================================
int out()
{
     int chose;
     
     system("cls");
     printf("  /======================================================================/\n");
	 printf("  /==========================服装管理系统首界面＝＝＝＝==================/\n");
	 printf("  /======================================================================/\n\n\n");
		
	 printf("         真的要退出系统吗？退出后信息会全部的丢失！！1，退出 0，取消");
	 
	 scanf("%d",&chose);
	 if(chose==1)exit(0);
	 else return 1;
} 
//=============================================================================
int adminmenu(ADMIN *adm,USER *use,DRESS *dress)
{
     int chose1;
     while(1)
	{
        system("cls");
        printf("  /======================================================================/\n");
		printf("  /======================服装销售系统管理员菜单=================＝＝=====/\n");
		printf("  /======================================================================/\n\n");
        
        printf("\n                                                  在线用户：   %s\n\n",usertemp.username);
        printf("                           //====＝==用户功能菜单=====//\n");
        printf("                           //                         //\n");
	    printf("                           //        1，添加用户      //\n");
  	    printf("                           //        2，删除用户      //\n");
	    printf("                           //        3，统计用户      //\n");
	    printf("                           //        4，添加商品      //\n");
	    printf("                           //        5，删除商品      //\n");
	    printf("                           //        6，查找商品      //\n");
	    printf("                           //        7，商品统计      //\n");
	    printf("                           //        8，修改密码      //\n");
	    printf("                           //        9，注销账户      //\n");
	    printf("                           //        0，退出系统      //\n");
	    printf("                           //=========================//\n");
	    printf("\n  /=============================请选择服务的种类========================/\n");

        scanf("%d",&chose1);
        if(chose1<0||chose1>9)
        {
               printf("                  你的输入有误，请重新的输入！\n");
               system("pause"); 
               continue;
        }
        
        switch(chose1)
		{
		case 1:
			{
				system("cls");
				regnew(use);
				system("pause");
				break;
			}
		case 2:
			{
				system("cls");
				deluser(use);
				system("pause");
				break;
			}
		case 3:
			{
				system("cls");
				useall(use);
				system("pause");
				break;
			}
		case 4:
			{
				system("cls");
				adddress(dress);
                system("pause");				
				break;
			}
		case 5:
			{
				system("cls");
				deldress(dress);			
				break;
			}
		case 6:
			{
				system("cls");
				finddress(dress);				
				break;
			}

		case 7:
			{
				system("cls");
				dressall(dress);
                system("pause");			
				break;
			}
		case 8:
			{
				system("cls");
				if(adminpass(adm)==1) continue;				
				break;
			}
		case 9:
			{
				system("cls");
				if(adminout()==1) return 3;	
				
			}

		case 0:
			{
				system("cls");
                if(out()==1) continue;			
				break;
			}
		default: continue; 
			
		}
        
   }   //while函数循环结束 
}



////////////////////////////////////////////////////////////////////////////////
///////////////////////////////销售人员模块///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int userload(USER *use)
{
    char name[21];
    char pass[7]={0};
	int chose,chose2;
	
	int i;
   while(1)
	{
        system("cls");
        printf("  /======================================================================/\n");
		printf("  /======================服装管理系统销售人员登陆＝======================/\n");
		printf("  /======================================================================/\n\n\n\n");

		printf("                           用户名：");
        scanf("%s",&name);
        printf("                           密  码：");
		
		for(i=0;i<6;i++)
		{
            pass[i]=getch();
            printf("*");
         }

        while(1)
        {
           printf("\n\n               用户登陆信息输入完毕，是否确认?  1,确认 0，重新输入\n"); 
           scanf("%d",&chose);
           if(chose!=1&&chose!=0)
           {
                 printf("                  你的输入有误，请重新的输入！\n");
                 continue;
           }
           if(chose==1)
           {
                for(i=0;i<200;i++)
                
                {
                   if(use[i].type==0)
                    if(strcmp(use[i].username,name)==0)
                       if(strcmp(use[i].pass,pass)==0)
                         {
                            printf("                         登陆成功！请继续使用！ \n");
                            strcpy(usertemp.username,name);
                            return 1;
                         }
                }
                printf("                 输入的用户名或者密码有误！1,重新登陆 2，退出登陆！\n");
                scanf("%d",&chose2);
                if(chose2==1)
                {
                      system("cls");
                      break;
                }
                else 
                {
                     system("cls");
                     return 0;
                }
           } 
           if(chose==0) break;
         }
          
   } 
} 
//=============================================================================
int userout()
{
     int chose;
      
     while(1)
     {
        system("cls");
        printf("  /======================================================================/\n");
        printf("  /======================服装销售系统销售员注销＝＝＝============＝＝====/\n");
        printf("  /======================================================================/\n\n");
        printf("\n                                                  在线用户： %s\n\n",usertemp.username);

        printf("                  你确定要注销吗？ 1，注销  0，取消\n\n");
        scanf("%d",&chose);
     
        if(chose!=0&&chose!=1)
        {
              printf("                 你的选项出现了错误，请重新的输入！\n\n\n");
              system("pause");
              continue;
        }
        if(chose==1)
        {
              printf("                     销售员账户注销完毕！！ \n\n\n\n"); 
              strcpy(usertemp.username,"unknown");   
 //             system("pause");   
              return 1;
        }
        else return 0;

     }
      
}
//=============================================================================
int sold(USER *use,DRESS *dress)
{
     char name[20];
     int num;
     int i;
     int j;
     int k;
     system("cls");
     printf("  /======================================================================/\n");
     printf("  /======================服装销售系统销售人员菜单=================＝＝===/\n");
     printf("  /======================================================================/\n\n");
        
     printf("\n                                                  在线用户： %s\n\n",usertemp.username);
     
     printf("     请输入要出售的商品的名称：");
     scanf("%s",&name);
     printf("\n     请输入出售的数量：");
     scanf("%d",&num);
     
     for(k=0;k<200;k++)
     {
       if(strcmp(use[k].username,usertemp.username)==0)
        for(i=0;i<500;i++)
       {
         if(strcmp(dress[i].name,name)==0)
         {
              if(dress[i].now<num) break;
              dress[i].now=dress[i].now-num;
              printf("\n\n\n         商品 %s已经销售出了 %d件\n",name,num);
              for(j=0;j<100;j++)
              {
                 if(use[k].mdb[j].flag==0)
                  {
                         strcpy(use[k].mdb[j].name,name);
                         use[k].mdb[j].flag=1;
                         use[k].mdb[j].total=num;
                         return 1;
                  }
              }
             
         }
        }
     }
      
     printf("              商品出售出现错误！！请重新操作！\n\n\n");
     return 0;
}
//=============================================================================
void mounth(USER *use)
{
     
     int i;
     int j;
     char name[20];
     strcpy(name,usertemp.username);
     
     
     system("cls");
     printf("  /======================================================================/\n");
     printf("  /======================服装销售系统销售人员销售记录====================/\n");
     printf("  /======================================================================/\n\n");
        
     printf("\n                                                  在线用户： %s\n\n",usertemp.username);
     

     
     for(i=0;i<100;i++)
     {
        if(strcmp(use[i].username,name)==0)
        {
                                           
             for(j=0;j<100;j++)
             {
                 if(use[i].mdb[j].flag==1)
                 printf("     商品名称：   %s ,出售数量  ： %d\n",use[i].mdb[j].name,use[i].mdb[j].total);
                 
            }
        }
     }
}



//=============================================================================

int usermenu(USER *use,DRESS *dress)
{
    //int i;
    int chose1;
    
    while(1)
	{
        system("cls");
        printf("  /======================================================================/\n");
		printf("  /======================服装销售系统销售人员菜单=================＝＝===/\n");
		printf("  /======================================================================/\n\n");
        
        printf("\n                                                  在线用户： %s\n\n",usertemp.username);
        printf("                           //====＝==用户功能菜单=====//\n");
        printf("                           //                         //\n");
	    printf("                           //        1，商品浏览      //\n");
  	    printf("                           //        2，商品查找      //\n");
	    printf("                           //        3，出售商品      //\n");
	    printf("                           //        4，销售记录      //\n");
	    printf("                           //        5，用户注销      //\n");
	    printf("                           //                         //\n");
	    printf("                           //                         //\n");
	    printf("                           //=========================//\n");
	    printf("\n  /=============================请选择服务的种类========================/\n");

        scanf("%d",&chose1);
        if(chose1<0||chose1>9)
        {
               printf("                  你的输入有误，请重新的输入！\n");
               system("pause"); 
               continue;
        }
        
        switch(chose1)
		{
		case 1:
			{
				system("cls");
				dressall(dress);
				break;
			}
		case 2:
			{
				system("cls");
				finddress(dress);
				break;
			}
		case 3:
			{
				system("cls");
				sold(use,dress);
				system("pause");
				break;
			}
		case 4:
			{
				system("cls");
				mounth(use);
                system("pause");				
				break;
			}
		case 5:
			{
				system("cls");
				if(userout()==1) return 3;				
				break;
			}

	
		default: continue; 
			
		}
        
   }   //while函数循环结束 
    
}


////////////////////////////////////////////////////////////////////////////////
/////////////////////////////店长    模块///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
int monpass(USER *use)
{
     int i;
     char pass[20]={0};
     char pass2[20]={0};
     
     while(1)
     {
           system("cls");
           printf("  /======================================================================/\n");
           printf("  /======================服装销售系统店长密码修改＝＝＝=========＝=======/\n");
           printf("  /======================================================================/\n\n\n\n");
           printf("   请输入新的密码：");
          
           for(i=0;i<6;i++)
          {
              pass[i]=getch();
              printf("*");
          }
          
          
           printf("\n\n\n   请再次输入新的密码：");
           for(i=0;i<6;i++)
           {
               pass2[i]=getch();
               printf("*");
           } 
           
           if(strcmp(pass,pass2)!=0)
           {
               printf("\n\n        两次输入的新的密码不一样，请重新的输入！\n\n\n");
               system("pause");
           }
           else
           {
               printf("\n        密码修改成功！下一次登陆请使用新的密码！\n\n\n");
               for(i=0;i<200;i++)
               {
                     if(strcmp(use[i].username,usertemp.username)==0)
                     {
                        strcpy(use[i].pass,pass);
                        system("pause");
                     }
               
               }
               return 1;
           }
     } 
}
//===============================================================================
void monsee(USER *use)
{
     
     int i;
     int j;
    // char name[20];
   
     system("cls");
     printf("  /======================================================================/\n");
     printf("  /======================服装销售系统全体销售记录===＝＝=================/\n");
     printf("  /======================================================================/\n\n");
        
     printf("\n                                                  在线用户： %s\n\n",usertemp.username);
     
     for(i=0;i<100;i++)
     {
        if(use[i].flag==1&&use[i].type==0)
        {
             printf("销售员姓名：   %s\n",use[i].username);
             for(j=0;j<100;j++)
             {
                  if(use[i].mdb[j].flag==1)
                  printf("     商品名称：   %s ,出售数量  ： %d\n",use[i].mdb[j].name,use[i].mdb[j].total);
             }
        }
     }
}


//==============================================================================================
int monload(USER *use)
{
    char name[21];
    char pass[7]={0};
	int chose,chose2;
	
	int i;
   while(1)
	{
        system("cls");
        printf("  /======================================================================/\n");
		printf("  /======================服装管理系统店长登陆============================/\n");
		printf("  /======================================================================/\n\n\n\n");

		printf("                           用户名：");
        scanf("%s",&name);
        printf("                           密  码：");
		
		for(i=0;i<6;i++)
		{
            pass[i]=getch();
            printf("*");
         }

        while(1)
        {
           printf("\n\n               用户登陆信息输入完毕，是否确认?  1,确认 0，重新输入\n"); 
           scanf("%d",&chose);
           if(chose!=1&&chose!=0)
           {
                 printf("                  你的输入有误，请重新的输入！\n");
                 continue;
           }
           if(chose==1)
           {
                for(i=0;i<200;i++)
                
                {
                   if(use[i].type==1)
                    if(strcmp(use[i].username,name)==0)
                       if(strcmp(use[i].pass,pass)==0)
                         {
                            printf("                         登陆成功！请继续使用！ \n");
                            strcpy(usertemp.username,name);
                            return 1;
                         }
                }
                printf("                 输入的用户名或者密码有误！1,重新登陆 2，退出登陆！\n");
                scanf("%d",&chose2);
                if(chose2==1)
                {
                      system("cls");
                      break;
                }
                else 
                {
                     system("cls");
                     return 0;
                }
           } 
           if(chose==0) break;
         }
          
   } 
} 
//=============================================================================
int monout()
{
     int chose;
      
     while(1)
     {
        system("cls");
        printf("  /======================================================================/\n");
        printf("  /======================服装销售系统店长注销====================＝＝====/\n");
        printf("  /======================================================================/\n\n");
        printf("\n                                                  在线用户： %s\n\n",usertemp.username);

        printf("                  你确定要注销吗？ 1，注销  0，取消\n\n");
        scanf("%d",&chose);
     
        if(chose!=0&&chose!=1)
        {
              printf("                 你的选项出现了错误，请重新的输入！\n\n\n");
              system("pause");
              continue;
        }
        if(chose==1)
        {
              printf("                     店长账户注销完毕！！ \n\n\n\n"); 
              strcpy(usertemp.username,"unknown");   
              return 1;
        }
        else return 0;

     }
      
}
//=============================================================================
int fix(DRESS *dress)
{
     char name[20],name2[20];
     int total;
     int now; 
     
     int i;
     
     system("cls");
     printf("  /======================================================================/\n");
	 printf("  /======================服装销售系统修改商品信息========================/\n");
	 printf("  /======================================================================/\n\n");
        
     printf("\n                                                  在线用户： %s\n\n",usertemp.username);


     printf("       请输入需要修改信息的商品的名称：");
     scanf("%s",&name) ;
     
     for(i=0;i<500;i++)
     {
         if(strcmp(dress[i].name,name)==0)
         {
              printf("商品信息：\n        名称：  %s,现存： %d,总共： %d\n",dress[i].name,dress[i].now,dress[i].total);
              printf("\n\n           请输入修改以后的商品的名称：");
              scanf("%s",&name2);
              printf("\n\n           请输入修改以后的商品的现存：");
              scanf("%d",&now);
              printf("\n\n           请输入修改以后的商品的总共：");
              scanf("%d",&total);
              strcpy(dress[i].name,name2);
              dress[i].now=now;
              dress[i].total=total;
              printf("\n\n");
              printf("修改以后的商品信息：\n        名称：  %s,现存： %d,总共： %d\n",dress[i].name,dress[i].now,dress[i].total);
              
              return 1; 
         }
     }
     printf("       修改信息失败！请查正以后重新的操作！！\n\n\n");
     return 0;
     
}
//=============================================================================
int monmenu(USER *use,DRESS *dress)
{
    //int i;
    int chose1;
    
    while(1)
	{
        system("cls");
        printf("  /======================================================================/\n");
		printf("  /======================服装销售系统店长菜单============================/\n");
		printf("  /======================================================================/\n\n");
        
        printf("\n                                                  在线用户： %s\n\n",usertemp.username);
        printf("                           //====＝==用户功能菜单=====//\n");
        printf("                           //                         //\n");
	    printf("                           //        1，商品浏览      //\n");
  	    printf("                           //        2，商品查找      //\n");
	    printf("                           //        3，销售员业绩    //\n");
	    printf("                           //        4，商品信息修改  //\n");
	    printf("                           //        5，密码修改      //\n");
	    printf("                           //        6，用户注销      //\n");
	    printf("                           //                         //\n");
	    printf("                           //=========================//\n");
	    printf("\n  /=============================请选择服务的种类========================/\n");

        scanf("%d",&chose1);
        if(chose1<1||chose1>8)
        {
               printf("                  你的输入有误，请重新的输入！\n");
               system("pause"); 
               continue;
        }
        
        switch(chose1)
		{
		case 1:
			{
				system("cls");
				dressall(dress);
				break;
			}
		case 2:
			{
				system("cls");
				finddress(dress);
				break;
			}
		case 3:
			{
				system("cls");
				monsee(use);
				system("pause");
				break;
			}
		case 4:
			{
				system("cls");
			    fix(dress);
                system("pause");				
				break;
			}

		
		case 5:
			{
				system("cls");
				monpass(use);				
				break;
			}
		case 6:
			{
				system("cls");
				if(monout()==1) return 3;				
				break;
			}
			
	
		default: continue; 
			
		}
        
   }   //while函数循环结束 
    
}

 
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////主要菜单函数模块/////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

//=============================================================================
int first(USER *use,ADMIN *adm,DRESS *dress)

{
    int chose;
    int temp,temp2;

	while(1)
	{
        
	    system("cls");
		printf("  /======================================================================/\n");
		printf("  /==========================服装管理系统首界面＝＝＝＝==================/\n");
		printf("  /======================================================================/\n\n\n");
		
		printf("                           //=========功能菜单========//\n");
		printf("                           //                         //\n");
		printf("                           //                         //\n");
		printf("                           //      1，销售员登陆      //\n");
		printf("                           //      2，店长登陆        //\n");
		printf("                           //      3，管理员登陆      //\n");
		printf("                           //                         //\n");
		printf("                           //=========================//\n");
		printf("\n  /=============================请选择服务的种类========================/\n");
		
		scanf("%d",&chose);
		
		if(chose<1||chose>5) 
		{
			printf("              你的选择出现错误！按任意键重新的进入选择菜单！\n");
			system("pause");
			continue;
		}
		
		
		switch(chose)
		{
		case 1:
			{
				system("cls");
				if(userload(use)==1)
                {
                   usermenu(use,dress);
                }
				system("pause");

				break;
			}
		case 2:
			{
				system("cls");
				if(monload(use)==1)
                {
                   monmenu(use,dress);
                }
				break;
			}
		case 3:
			{
				system("cls");
				temp=adminload(adm);
				
				if(temp==1)
				{
                      system("pause");
                      temp2=adminmenu(adm,use,dress);
                      return 3;
                }
                system("pause");
				continue;
			}

		default: exit(0);
			
		}
	}//while()
}


////////////////////////////////////////////////////////////////////////////////
///////////////////////////////主要函数模块/////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////// 

int main()
{
    USER *use;
    use=(USER *)malloc(200*sizeof(USER));
    userIntiate(use); 
    ADMIN *adm;
    adm=(ADMIN *)malloc(sizeof(ADMIN));
    adminIntiate(adm);
    DRESS *dress;
    dress=(DRESS *)malloc(500*sizeof(DRESS));
    dressIntiate(dress); 
	while(1)
	{
       if(first(use,adm,dress)==3)  continue;
    }
	return 0;
}



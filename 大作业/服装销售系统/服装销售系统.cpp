#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

//˵������������еĹ���Ա���곤������Ա���붼��6λ�ġ� 
// ����ԱĬ���û�����admin,������123456�� 


////////////////////////////////////////////////////////////////////////////////
///////////////////////////////�ṹ�嶨��///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

typedef struct admin           //�������Ա�ṹ��
{
    char name[20];
    char pass[20];
}ADMIN;



typedef struct                // ������Ʒ�ṹ�� 
{
    char name[30];
    int now;
    int total; 
    int flag;
}DRESS;

typedef struct              //�����û��ṹ�� 
{
    int flag; 
    int type;
	char username[20];
	char pass[20];
	DRESS mdb[100];
}USER; 


USER usertemp;
int usernum=0;   //��¼����Ա������ 

////////////////////////////////////////////////////////////////////////////////
///////////////////////////////��װ��ģ��///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int adddress(DRESS *dress)
{
    char name[20];
    int total;
    int i;
    
    system("cls");
    printf("  /======================================================================/\n");
    printf("  /======================��װ����ϵͳϵͳ��Ʒ���=====================��=/\n");
    printf("  /======================================================================/\n\n\n\n");
    printf("         ��������Ʒ�����ƣ�");
    scanf("%s",&name);
    printf("\n         ������������Ʒ��������") ;
    scanf("%d",&total);
    
    printf("\n\n\n          ��Ʒ��Ϣ������ϣ�\n\n\n");
    
    
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
    printf("  /======================��װ����ϵͳϵͳ��Ʒɾ��=====================��=/\n");
    printf("  /======================================================================/\n\n\n\n");
    printf("         ��������Ҫɾ������Ʒ�����ƣ�");
    scanf("%s",&name);

    
    for(i=0;i<250;i++)
    {
        if(strcmp(dress[i].name,name)==0)
        {
            printf("\n\n\n             ��Ʒɾ����ϣ�\n\n\n");
            dress[i].flag=0;
            system("pause");
            return 1;
        }
        
    }
    
    printf("\n\n\n             ��Ʒɾ�����ִ����������Ʒ���ƣ�\n\n\n"); 
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
    printf("  /======================��װ����ϵͳϵͳ��Ʒ����====================��=/\n");
    printf("  /=====================================================================/\n\n\n\n");
    printf("         ��������Ҫ���ҵ���Ʒ�����ƣ�");
    scanf("%s",&name);

    
    for(i=0;i<250;i++)
    {
        if(strcmp(dress[i].name,name)==0)
        if(dress[i].flag==1)
        {
            printf("\n\n\n ��Ʒ������ϣ�\n          ��Ʒ���ƣ�   %s ,�ִ�����  %d,�ܿ�棺  %d\n",name,dress[i].now,dress[i].total);
            system("pause");
            return 1;
        }
        
    }
    
    printf("\n\n\n             ��Ʒ���ҳ��ִ����������Ʒ���ƣ�\n\n\n"); 
    system("pause");
    return 0;

} 

//============================================================================
void dressall(DRESS *dress)
{
     int i;
     system("cls");
     printf("  /======================================================================/\n");
     printf("  /======================��װ����ϵͳϵͳ�鿴��Ʒ=====================��=/\n");
     printf("  /======================================================================/\n\n\n\n");
     
     for(i=0;i<500;i++)
     {
         if(dress[i].flag==1)
         printf("   ��Ʒ������Ϊ��  %s ,��Ʒ������Ϊ��  %d ,��Ʒ���ִ���   %d \n",dress[i].name,dress[i].total,dress[i].now);
     }
   system("pause");
}


////////////////////////////////////////////////////////////////////////////////
///////////////////////////////����Աģ��///////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void adminIntiate(ADMIN *adm)   //����Ա�����û�����ʼ�� 
{
     strcpy(adm->name,"admin");
     strcpy(adm->pass,"123456");
}
//=======================================================================
void userIntiate(USER *use)   //����Ա�����û�����ʼ�� 
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
void dressIntiate(DRESS *dress)   //��Ʒ��ʼ�� 
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
		printf("  /======================��װ����ϵͳϵͳ�û�ע��=====================��=/\n");
		printf("  /======================================================================/\n\n\n\n");
    

		
		printf("                           �û�����");
        scanf("%s",&name);
        printf("                           ��  �룺");

		for(i=0;i<6;i++)
		{
            pass[i]=getch();
            printf("*");
         }
         
        printf("\n\n                       �������û������ͣ�0������Ա 1���곤 ");
		scanf("%d",&type);

        while(1)
        {
           printf("\n\n               �û�ע����Ϣ����ϣ��Ƿ�ȷ��?  1,ȷ�� 0����������\n"); 
           scanf("%d",&chose);
           if(chose!=1&&chose!=0)
           {
                 printf("               ����������������µ����룡\n");
                 continue;
           }
           
        if(chose==1)
        {
          for(i=0;i<usernum+1;i++)
          if(use[i].flag==0)
          {
              printf("                    ע��ɹ��������ʹ�ã� \n");

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
    printf("  /======================��װ����ϵͳ�û�ɾ��============================/\n");
    printf("  /======================================================================/\n\n\n\n");
    
    printf("    ����������Ҫɾ�����û����û�����"); 
    scanf("%s",name);
    for(i=0;i<200;i++)
    {
          if(strcmp(use[i].username,name)==0)
          {
              printf("\n\n\n    �û�  %s ɾ���ɹ���\n\n\n\n",name);
              strcpy(use[i].username,"unknown");
              use[i].flag=-1;
              return 1;
          }
    }
    printf("    �û�  %s �����ڣ�������ڴβ�����\n\n\n\n",name);
    return 0;
}
//=============================================================================
int useall(USER *use)
{
    int i;
    system("cls");
    printf("  /======================================================================/\n");
    printf("  /======================��װ����ϵͳ�û��鿴������======================/\n");
    printf("  /======================================================================/\n\n\n\n");
    printf("   ������Ա��\n");
    for(i=0;i<200;i++)
    {
        if(use[i].type==0)
        {   
            
            if(use[i].flag==1)
            printf("              �û�������    %s �û����룺   %s \n",use[i].username,use[i].pass);
        }
    }
    printf("   �곤��\n");
    for(i=0;i<200;i++)
    {
        
        if(use[i].type==1)
        {   
            
            if(use[i].flag==1)
            printf("              �û�������    %s �û����룺   %s \n",use[i].username,use[i].pass);
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
		printf("  /======================��װ����ϵͳ����Ա��½======================����/\n");
		printf("  /======================================================================/\n\n\n\n");

		printf("                           ����Ա�˺ţ�");
        scanf("%s",&name);
        printf("                           ��      �룺");
		
		for(i=0;i<6;i++)
		{
            pass[i]=getch();
            printf("*");
         }

        while(1)
        {
           printf("\n\n               �û���½��Ϣ������ϣ��Ƿ�ȷ��?  1,ȷ�� 0����������\n"); 
           scanf("%d",&chose);
           if(chose!=1&&chose!=0)
           {
                 printf("                  ����������������µ����룡\n");
                 continue;
           }
           if(chose==1)
           {
                    if(strcmp(adm->name,name)==0)
                       if(strcmp(adm->pass,pass)==0)
                         {
                            printf("                         ��½�ɹ��������ʹ�ã� \n");
                            strcpy(usertemp.username,name);
                            return 1;
                         }
          
                printf("                 ������û���������������1,���µ�½ 2���˳���½��\n");
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
           printf("  /======================��װ����ϵͳ����Ա�����޸ģ�����================/\n");
           printf("  /======================================================================/\n\n\n\n");
           printf("   �������µĹ���Ա���룺");
          
           for(i=0;i<6;i++)
          {
              pass[i]=getch();
              printf("*");
          }
          
          
           printf("\n\n\n   ���ٴ������µĹ���Ա���룺");
           for(i=0;i<6;i++)
           {
               pass2[i]=getch();
               printf("*");
           } 
           
           if(strcmp(pass,pass2)!=0)
           {
               printf("\n\n        ����������µ����벻һ���������µ����룡\n\n\n");
               system("pause");
           }
           else
           {
               printf("\n        �����޸ĳɹ�����һ�ι���Ա��½��ʹ���µ����룡\n\n\n");
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
        printf("  /======================��װ����ϵͳ����Աע��������============����====/\n");
        printf("  /======================================================================/\n\n\n\n");
        printf("                  ��ȷ��Ҫע���� 1��ע��  0��ȡ��\n\n");
        scanf("%d",&chose);
     
        if(chose!=0&&chose!=1)
        {
              printf("                 ���ѡ������˴��������µ����룡\n\n\n");
              system("pause");
              continue;
        }
        if(chose==1)
        {
              printf("                     ����Ա�˻�ע����ϣ��� \n\n\n\n");    
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
	 printf("  /==========================��װ����ϵͳ�׽��棽������==================/\n");
	 printf("  /======================================================================/\n\n\n");
		
	 printf("         ���Ҫ�˳�ϵͳ���˳�����Ϣ��ȫ���Ķ�ʧ����1���˳� 0��ȡ��");
	 
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
		printf("  /======================��װ����ϵͳ����Ա�˵�=================����=====/\n");
		printf("  /======================================================================/\n\n");
        
        printf("\n                                                  �����û���   %s\n\n",usertemp.username);
        printf("                           //====��==�û����ܲ˵�=====//\n");
        printf("                           //                         //\n");
	    printf("                           //        1������û�      //\n");
  	    printf("                           //        2��ɾ���û�      //\n");
	    printf("                           //        3��ͳ���û�      //\n");
	    printf("                           //        4�������Ʒ      //\n");
	    printf("                           //        5��ɾ����Ʒ      //\n");
	    printf("                           //        6��������Ʒ      //\n");
	    printf("                           //        7����Ʒͳ��      //\n");
	    printf("                           //        8���޸�����      //\n");
	    printf("                           //        9��ע���˻�      //\n");
	    printf("                           //        0���˳�ϵͳ      //\n");
	    printf("                           //=========================//\n");
	    printf("\n  /=============================��ѡ����������========================/\n");

        scanf("%d",&chose1);
        if(chose1<0||chose1>9)
        {
               printf("                  ����������������µ����룡\n");
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
        
   }   //while����ѭ������ 
}



////////////////////////////////////////////////////////////////////////////////
///////////////////////////////������Աģ��///////////////////////////////////////
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
		printf("  /======================��װ����ϵͳ������Ա��½��======================/\n");
		printf("  /======================================================================/\n\n\n\n");

		printf("                           �û�����");
        scanf("%s",&name);
        printf("                           ��  �룺");
		
		for(i=0;i<6;i++)
		{
            pass[i]=getch();
            printf("*");
         }

        while(1)
        {
           printf("\n\n               �û���½��Ϣ������ϣ��Ƿ�ȷ��?  1,ȷ�� 0����������\n"); 
           scanf("%d",&chose);
           if(chose!=1&&chose!=0)
           {
                 printf("                  ����������������µ����룡\n");
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
                            printf("                         ��½�ɹ��������ʹ�ã� \n");
                            strcpy(usertemp.username,name);
                            return 1;
                         }
                }
                printf("                 ������û���������������1,���µ�½ 2���˳���½��\n");
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
        printf("  /======================��װ����ϵͳ����Աע��������============����====/\n");
        printf("  /======================================================================/\n\n");
        printf("\n                                                  �����û��� %s\n\n",usertemp.username);

        printf("                  ��ȷ��Ҫע���� 1��ע��  0��ȡ��\n\n");
        scanf("%d",&chose);
     
        if(chose!=0&&chose!=1)
        {
              printf("                 ���ѡ������˴��������µ����룡\n\n\n");
              system("pause");
              continue;
        }
        if(chose==1)
        {
              printf("                     ����Ա�˻�ע����ϣ��� \n\n\n\n"); 
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
     printf("  /======================��װ����ϵͳ������Ա�˵�=================����===/\n");
     printf("  /======================================================================/\n\n");
        
     printf("\n                                                  �����û��� %s\n\n",usertemp.username);
     
     printf("     ������Ҫ���۵���Ʒ�����ƣ�");
     scanf("%s",&name);
     printf("\n     ��������۵�������");
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
              printf("\n\n\n         ��Ʒ %s�Ѿ����۳��� %d��\n",name,num);
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
      
     printf("              ��Ʒ���۳��ִ��󣡣������²�����\n\n\n");
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
     printf("  /======================��װ����ϵͳ������Ա���ۼ�¼====================/\n");
     printf("  /======================================================================/\n\n");
        
     printf("\n                                                  �����û��� %s\n\n",usertemp.username);
     

     
     for(i=0;i<100;i++)
     {
        if(strcmp(use[i].username,name)==0)
        {
                                           
             for(j=0;j<100;j++)
             {
                 if(use[i].mdb[j].flag==1)
                 printf("     ��Ʒ���ƣ�   %s ,��������  �� %d\n",use[i].mdb[j].name,use[i].mdb[j].total);
                 
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
		printf("  /======================��װ����ϵͳ������Ա�˵�=================����===/\n");
		printf("  /======================================================================/\n\n");
        
        printf("\n                                                  �����û��� %s\n\n",usertemp.username);
        printf("                           //====��==�û����ܲ˵�=====//\n");
        printf("                           //                         //\n");
	    printf("                           //        1����Ʒ���      //\n");
  	    printf("                           //        2����Ʒ����      //\n");
	    printf("                           //        3��������Ʒ      //\n");
	    printf("                           //        4�����ۼ�¼      //\n");
	    printf("                           //        5���û�ע��      //\n");
	    printf("                           //                         //\n");
	    printf("                           //                         //\n");
	    printf("                           //=========================//\n");
	    printf("\n  /=============================��ѡ����������========================/\n");

        scanf("%d",&chose1);
        if(chose1<0||chose1>9)
        {
               printf("                  ����������������µ����룡\n");
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
        
   }   //while����ѭ������ 
    
}


////////////////////////////////////////////////////////////////////////////////
/////////////////////////////�곤    ģ��///////////////////////////////////////
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
           printf("  /======================��װ����ϵͳ�곤�����޸ģ�����=========��=======/\n");
           printf("  /======================================================================/\n\n\n\n");
           printf("   �������µ����룺");
          
           for(i=0;i<6;i++)
          {
              pass[i]=getch();
              printf("*");
          }
          
          
           printf("\n\n\n   ���ٴ������µ����룺");
           for(i=0;i<6;i++)
           {
               pass2[i]=getch();
               printf("*");
           } 
           
           if(strcmp(pass,pass2)!=0)
           {
               printf("\n\n        ����������µ����벻һ���������µ����룡\n\n\n");
               system("pause");
           }
           else
           {
               printf("\n        �����޸ĳɹ�����һ�ε�½��ʹ���µ����룡\n\n\n");
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
     printf("  /======================��װ����ϵͳȫ�����ۼ�¼===����=================/\n");
     printf("  /======================================================================/\n\n");
        
     printf("\n                                                  �����û��� %s\n\n",usertemp.username);
     
     for(i=0;i<100;i++)
     {
        if(use[i].flag==1&&use[i].type==0)
        {
             printf("����Ա������   %s\n",use[i].username);
             for(j=0;j<100;j++)
             {
                  if(use[i].mdb[j].flag==1)
                  printf("     ��Ʒ���ƣ�   %s ,��������  �� %d\n",use[i].mdb[j].name,use[i].mdb[j].total);
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
		printf("  /======================��װ����ϵͳ�곤��½============================/\n");
		printf("  /======================================================================/\n\n\n\n");

		printf("                           �û�����");
        scanf("%s",&name);
        printf("                           ��  �룺");
		
		for(i=0;i<6;i++)
		{
            pass[i]=getch();
            printf("*");
         }

        while(1)
        {
           printf("\n\n               �û���½��Ϣ������ϣ��Ƿ�ȷ��?  1,ȷ�� 0����������\n"); 
           scanf("%d",&chose);
           if(chose!=1&&chose!=0)
           {
                 printf("                  ����������������µ����룡\n");
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
                            printf("                         ��½�ɹ��������ʹ�ã� \n");
                            strcpy(usertemp.username,name);
                            return 1;
                         }
                }
                printf("                 ������û���������������1,���µ�½ 2���˳���½��\n");
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
        printf("  /======================��װ����ϵͳ�곤ע��====================����====/\n");
        printf("  /======================================================================/\n\n");
        printf("\n                                                  �����û��� %s\n\n",usertemp.username);

        printf("                  ��ȷ��Ҫע���� 1��ע��  0��ȡ��\n\n");
        scanf("%d",&chose);
     
        if(chose!=0&&chose!=1)
        {
              printf("                 ���ѡ������˴��������µ����룡\n\n\n");
              system("pause");
              continue;
        }
        if(chose==1)
        {
              printf("                     �곤�˻�ע����ϣ��� \n\n\n\n"); 
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
	 printf("  /======================��װ����ϵͳ�޸���Ʒ��Ϣ========================/\n");
	 printf("  /======================================================================/\n\n");
        
     printf("\n                                                  �����û��� %s\n\n",usertemp.username);


     printf("       ��������Ҫ�޸���Ϣ����Ʒ�����ƣ�");
     scanf("%s",&name) ;
     
     for(i=0;i<500;i++)
     {
         if(strcmp(dress[i].name,name)==0)
         {
              printf("��Ʒ��Ϣ��\n        ���ƣ�  %s,�ִ棺 %d,�ܹ��� %d\n",dress[i].name,dress[i].now,dress[i].total);
              printf("\n\n           �������޸��Ժ����Ʒ�����ƣ�");
              scanf("%s",&name2);
              printf("\n\n           �������޸��Ժ����Ʒ���ִ棺");
              scanf("%d",&now);
              printf("\n\n           �������޸��Ժ����Ʒ���ܹ���");
              scanf("%d",&total);
              strcpy(dress[i].name,name2);
              dress[i].now=now;
              dress[i].total=total;
              printf("\n\n");
              printf("�޸��Ժ����Ʒ��Ϣ��\n        ���ƣ�  %s,�ִ棺 %d,�ܹ��� %d\n",dress[i].name,dress[i].now,dress[i].total);
              
              return 1; 
         }
     }
     printf("       �޸���Ϣʧ�ܣ�������Ժ����µĲ�������\n\n\n");
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
		printf("  /======================��װ����ϵͳ�곤�˵�============================/\n");
		printf("  /======================================================================/\n\n");
        
        printf("\n                                                  �����û��� %s\n\n",usertemp.username);
        printf("                           //====��==�û����ܲ˵�=====//\n");
        printf("                           //                         //\n");
	    printf("                           //        1����Ʒ���      //\n");
  	    printf("                           //        2����Ʒ����      //\n");
	    printf("                           //        3������Աҵ��    //\n");
	    printf("                           //        4����Ʒ��Ϣ�޸�  //\n");
	    printf("                           //        5�������޸�      //\n");
	    printf("                           //        6���û�ע��      //\n");
	    printf("                           //                         //\n");
	    printf("                           //=========================//\n");
	    printf("\n  /=============================��ѡ����������========================/\n");

        scanf("%d",&chose1);
        if(chose1<1||chose1>8)
        {
               printf("                  ����������������µ����룡\n");
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
        
   }   //while����ѭ������ 
    
}

 
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////��Ҫ�˵�����ģ��/////////////////////////////////////
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
		printf("  /==========================��װ����ϵͳ�׽��棽������==================/\n");
		printf("  /======================================================================/\n\n\n");
		
		printf("                           //=========���ܲ˵�========//\n");
		printf("                           //                         //\n");
		printf("                           //                         //\n");
		printf("                           //      1������Ա��½      //\n");
		printf("                           //      2���곤��½        //\n");
		printf("                           //      3������Ա��½      //\n");
		printf("                           //                         //\n");
		printf("                           //=========================//\n");
		printf("\n  /=============================��ѡ����������========================/\n");
		
		scanf("%d",&chose);
		
		if(chose<1||chose>5) 
		{
			printf("              ���ѡ����ִ��󣡰���������µĽ���ѡ��˵���\n");
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
///////////////////////////////��Ҫ����ģ��/////////////////////////////////////
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



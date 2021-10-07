#include <stdio.h>
void save(int);
void name(int);
void printf_data(int);
void printf_back();
void printf_onedata(int);

struct user
  {
    int num;
    char name[10];
    float money;
    int score;
   }user[30];


void menu()
{
int n,w1;
do
         {
           void new_card();
           void use_card();
           void conduct();
           void transaction();
           void form();
           puts("\n\t\t*********************MENU*********************\n\n");
           puts("\t\t\t\t 1.New card");
           puts("\t\t\t\t 2.Use card");
           puts("\t\t\t\t 3.Account conduct");
           puts("\t\t\t\t 4.Transaction");
           puts("\t\t\t\t 5.Report form");
           puts("\t\t\t\t 6.Exit");
           puts("\n\n\t\t***********************************************\n");
           printf("Choice your number(1-6):[ ]\b\b");
           scanf("%d",&n);
           if(n<1||n>6)                 
            {
              w1=1;
              getchar();
            }
              else w1=0;
          }while(w1==1);
            
          switch(n)
           {case 1:new_card();break;
            case 2:use_card();break;
            case 3:conduct();break;
            case 4:transaction();break;
            case 5:form();break;
            case 6:exit(0);
          }
        }
main()
     {menu();
 }

void new_card() /*制卡模式*/   
      {  int n,i;
         n=load_user();
         user[n+1].num=n+1;               
         strcpy(user[n+1].name,"NO");         
         user[n+1].money=0;user[n+1].score=0;  
     save(n+1);
         printf_onedata(n+1);
         menu();
}

void use_card() /*发卡模式*/
     {  int n,c,b=0,i,k=-1;
        n=load_user();
        printf("How many new cards do you want ?   [ ]\b\b");
        scanf("%d",&c); 
        for(i=0;i<n+1;i++)  
          if(strcmp(user[i].name,"NO")==0)
{ k=i; b+=1;
if(b>=c){printf("\nThere is a new card!\n");name(i);}  
            else
             menu();
           }
       if(k==-1)
       {printf("\nthere is no new card!\n");menu();}
     }
 
void conduct()/*管理模块*/
         {  int n,w1;
            do
             {
               void browse_data();
               int search_data();
               puts("\n\t\t*********************MENU*********************\n\n");
               puts("\t\t\t\t 1.Browse all");
               puts("\t\t\t\t 2.Search");
               puts("\t\t\t\t 3.Back");
               puts("\n\n\t\t**********************************************\n");
               printf("Choice your number(1-3):[ ]\b\b");
               scanf("%d",&n);
               if(n<1||n>3)
                 {
	               w1=1;
	               getchar();
                  }
	           else w1=0;
             }while(w1==1);
           switch(n)
           { case 1:browse_data();break;
            case 2:search_data();break;
            case 3:menu();break;
           }
        }

      void browse_data()/*浏览模块*/     
         {  int n;
           n=load_user();
           printf_data(n);
           printf_back();
         }

void search()/*查找模块*/    
         { int i,n,k,w1,w2,w3;
           struct user u;
           n=load_user();
           do
            {
	          do
	            {  k=-1;
	               printf("\n\nEnter number that you want to search!  NO:");
	               scanf("%d",&u.num);  
	                for(i=0;i<n;i++)    
	                 if(u.num==user[i].num)
	                  { k=i; printf_onedata(k);}
	                 if(k==-1)
	                  { printf("\n\nNo exist!please");
	                    printf("\n\nAre you again?\n\t1>.again   2>.No and back  [ ]\b\b");
	                    scanf("%d",&w1);
	                 if(w1==2){menu();break;}
	                  }
	            }while(k==-1&&w1==1);
printf("\n\nwhat do you want to do?\n\t1>.Search another       2>.Back menu  [ ]\b\b")  ;
		 scanf("%d",&w2);
}while(w2==1);
	     conduct();
}

void transaction()/*交易模块*/  
       {  int i,w2;
	void printf_face(int i);
          i=search_data();
          if(i!=-1)printf_face(i);  
       }
      void printf_face(int i)   
      {  int w2;
      void common(int);
      void financial(int);
	    printf("\n\n What do you want to do?\n\t1>.common transaction  2>.financial transaction  3>.back  [ ]\b\b");
scanf("%d",&w2);
switch(w2)
	      {  case 1: common(i);break;
		 case 2: financial(i);break;
	         case 3:menu();break;
	       }
     }
      void common(int i)/*普通交易模块*/   
       {  int n;
	  float w;

	      load_user();
	      printf("Imput how much:  [ ] \b\b");
	      scanf("%d",&w);   
	      if(user[i].money>=w)
	       { printf("\nIt is allowed!\n");
	         user[i].money-=w;
	         save(i);
	        }
	      else printf("\nInput Error!\n");
	      printf_face(i);
       }
 
      void financial(int i)/*金融交易模块*/  
       {  int n;
	  float w;

	      load_user();
	      printf("Imput how much:  [ ] \b\b");  
	      scanf("%d",&w);
	      if(user[i].money>=w)
	       {printf("\nIt is allowed!\n");
	        user[i].money-=w;
	        user[i].score=w;
	        save(i);
	       }
	     else printf("\nInput Error!\n");
	     printf_face(i);  
      }

void form()/*报表模式*/ 
       {  int w;
	      printf("\nDo you want to see the form?\n\t1>.YES  2>.NO and Back  [ ]\b\b");
	      scanf("%d",&w);
	      switch(w)
	       { case 1: search_data();menu();  
	         case 2: menu();break;      
}
	     getch();
       }

int load_user()/*公共函数*/  
   {  FILE *fp;  int i;
         if((fp=fopen("USER.txt","r"))==NULL)   
          { printf("\nCannot open file\n");
	       exit(0);
	       }
        for(i=0;!feof(fp);i++)
        fscanf(fp,"%d %s %f %d\n",&user[i].num,user[i].name,&user[i].money,&user[i].score);
       fclose(fp);
       return(i); 
}

        void save(int n)   
      {
	FILE *fp;
          if((fp=fopen("USER.txt","a"))==NULL)  
	       {printf("\nCannot open file\n");
	        exit(0);}
           fprintf(fp,"%d   %s   %d   %d\n",user[n].num,user[n].name,user[n].money,user[n].score);
             fclose(fp);
         }

        void name(int i)  
          {  char c[10];
int b, j;
            float a;
             printf("Input the name:   \b\b");
             scanf("%s",c);      
             strcpy(user[i].name,c);  
             printf("Input the num and score:  \b\b");
            scanf("%d,%d",&a,&b);
            user[i].money=a;
            user[i].score=b;
            printf_onedata(i);
            save(i);        
}

        void printf_data(int m)
         {  int j,n;
            n=load_user();
            for(j=0;j<m;j++)
             { if((j!=0)&&(j%10==0))
              { printf("\nPass any key to continue...\n");
	           getch();
	           puts("\n\n");
              }
	          printf_onedata(j);  
            }
	       printf("\nThere are  %d record.\n",n);
	       printf("\n Pass any key to back ...");
	       getch();
	       menu();
         }

       void printf_back()     
        {  int k,w;
            printf("\n\n\t Successful.^_^.\n\n");
            printf("What do you want to do?\n\n\t1>Exit.\t2>.Back:  [ ]\b\b");
            scanf("%d",&w);
	        if(w==1)exit(0);
	        else conduct();
         }

       void printf_onedata(int j)   
           { printf("\nuser_num  user_name  user_money  user_score\n");
             printf("%2d     %4s     %8f     %8d\n ",user[j].num,user[j].name,user[j].money,user[j].score);
          }

int search_data()   
          { int i,n,k,w1=1,w2,w3,w4;
	        struct user u;
	        n=load_user();
	        do
	         {  k=-1;
	            printf("\n\nEnter number that you want to search!  NO:");
	            scanf("%d",&u.num);
	            for(i=0;i<n;i++)     
	             if(u.num==user[i].num)
	              { k=i;  printf_onedata(k);break;
	              }
	            if(k==-1)
	            { printf("\n\nNo exist!please");
	              printf("\n\nAre you again?\n\t1>.again   2>.No and back  []\b\b");
	              scanf("%d",&w1);
	             if(w1==2){menu();break;}
	            }
	         }while(k==-1&&w1==1);
	      return(k);
}
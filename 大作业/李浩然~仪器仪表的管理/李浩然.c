#define N 50
#include <stdio.h>
#include <stdlib.h>

struct machine
{
 char name[5];
 char number[5];
 char buy_time[5];
 char borrowin_time[5];
 char borrowout_time[5];
 char return_time[5];
 char repair_time[5];
 char sta[5];
 char time[5];
}mac[N];

main()
{menu();
}

menu()
 {
  int n,w;
  do
  {
   puts("\t\t**************MENU********************\n\n");
   puts("\t\t\t\t 1.enter");
   puts("\t\t\t\t 2.modify");
   puts("\t\t\t\t 3.search");
   puts("\t\t\t\t 4.delete");
   puts("\t\t\t\t 5.exit");
   puts("\n\n\t\t ******************************************\n");
   printf("Choice your number(1-5):[ ]\b\b");
   scanf("%d",&n);
   if(n<1||n>5)
   {w=1;
    getchar();
    }
    else w=0;
   }
   while(w==1);
   switch(n)
   {
    case 1:enter();break;
    case 2:modify();break;
    case 3:search();break;
    case 4:delete();break;
    case 5:exit(0);
   }
  }

enter()
{ int i,n;
  printf("How many machines do you want to enter(0-%d)?:",N-1);
  scanf("%d",&n);
  printf("\nEnter data now\n");
  printf("\nname number buy_time borrowin_time borrowout_time return_time repair_time state\n");
  for(i=0;i<n;i++)
     {
       input(i);
     }
  if(i!=0)save(n);
  printf_back();
}

input(int i)
{
  printf("name:");
  scanf("%s",mac[i].name);
  num_input(i,i);
  printf("buy_time:");
  scanf("%s",mac[i].buy_time);
  printf("borrowin_time:");
  scanf("%s",mac[i].borrowin_time);
  printf("borrowout_time:");
  scanf("%s",mac[i].borrowout_time);
  printf("return_time:");
  scanf("%s",mac[i].return_time);
  printf("repair_time:");
  scanf("%s",mac[i].repair_time);
  printf("state:");
  scanf("%s",mac[i].sta);
}

num_input(int i,int n)
{ int j,k,w1;
  do
    { w1=0;
      printf("number:\n");
      scanf("%s",mac[i].number);
      for(j=0;mac[i].number[j]!='\0';j++)
	 if(mac[i].number[j]<'0'||mac[i].number[j]>'9')
	   { puts("Input error!Only be made up of(0-9).Please reinput!\n");
	     w1=1;break;
	   }
      if(w1!=1)
	for(k=0;k<n;k++)
	   if(k!=i&&strcmp(mac[k].number,mac[i].number)==0)
	     {puts("This record is exist.Please reinput!\n");
	      w1=1;break;
	     }
    }
  while(w1==1);
}
save(int n)
{ FILE *fp;
  int i;
  if((fp=fopen("data.txt","wb"))==NULL)
     { printf("\nCannot open file\n");
       return NULL;
     }
  for(i=0;i<n;i++)
    if(mac[i].number!=0)
      if(fwrite(&mac[i],sizeof(struct machine),1,fp)!=1)
	printf("file write error!\n");
  fclose(fp);
}

printf_back()
{ int k,w;
  printf("\n\nSuccessful.^_^\n\n");
  printf("What do you want to do?\n\n\t1).Back\t2).Exit:[]\b\b");
  scanf("%d",&w);
  if(w==1)menu();
  else exit(0);
}

modify()
{ struct machine m;
  FILE *fp;
  int i,n,k,w0=1,w1,w2=0;
  n=load();
  do
  {
    k=-1;
    printf_face();
    for(i=0;i<n;i++)
       {if((i!=0)&&(i%10==0))
          {printf("\n\npass any key to continue...");
           getch();
           puts("\n\n");
           }
        printf_one(i);
       }

    do
      { printf("\nplease enter machine number:");
	scanf("%s",m.number);
        for(i=0;i<n;i++)
	   if(strcmp(m.number,mac[i].number)==0)
	     { k=i;
	       m=mac[i];
	      }
	if(k==-1)printf("\n\nNO exist!Try again");
       } while(k==-1);
     printf_face();
     printf_one(k);
     w1=modify_data(k);
     if(w1==1)
       { printf("\nSuccessful^_^.\n\nAre you modify another?\n\n\t1).Yes  2).Back with save\t[]\b\b");
	 scanf("%d",&w0);
	 w2=1;
	}
      else
	 { w0=0;
	   if(w2==1)
	   mac[k]=m;
	 }
     if(w0!=1&&w2==1)
       save(n);
 }
 while(w0==1);
 printf_back();
}


printf_face()
{printf("\n\tname number buy_time borrowin_time borrowout_time return_time repair_time state\n");
}


printf_one(int i)
{
 printf("%s   %s   %s   %s   %s   %s    %s   %s\n",mac[i].name,mac[i].number,mac[i].buy_time,mac[i].borrowin_time,mac[i].borrowout_time,mac[i].return_time,mac[i].repair_time,mac[i].sta);

}


modify_data(int i)
{ int c,w;
   do
     {puts("\n modify by=>\n\n  1). borrowout_time  2).return_time  3).repair_time  4).state");
      printf("Which you need?:[]\b\b");
      scanf("%d",&c);
      if(c>4||c<1)
	{ puts("\nChoice error!Again!\n");
	  getchar();
	}
     }while(c>4||c<1);
   do
     { switch(c)
	  { case 1:printf("enter borrowout time:");scanf("%s",mac[i].borrowout_time);break;
	    case 2:printf("enter return time:");scanf("%s",mac[i].return_time);break;
	    case 3:printf("enter repair time:");scanf("%s",mac[i].repair_time);break;
	    case 4:printf("enter  state:");scanf("%s",mac[i].sta);break;
	  }
	puts("\nNow:\n");
	printf_face();
	printf_one(i);
	printf("\nAre you sure?\n\n\t1).Sure  2).No and remodify  3).Back without save in this time  []\b\b");
	scanf("%d",&w);
     }  while(w==2);
     return(w);
}

int load()
{FILE *fp;
 int i;
 if((fp=fopen("data.txt","rb"))==NULL)
   {printf("\nCannot open file\n");
   }
  for(i=0;!feof(fp);i++)
   fread(&mac[i],sizeof(struct machine),1,fp);
   fclose(fp);
   return(i);
}

int search()
{ int m;
  puts("\t\t*********************************\n\n");
  puts("\t\t\t\t 1.common_search");
  puts("\t\t\t\t 2.point_search");
  puts("\t\t\t\t 3.exit");
  puts("\n\n\t\t ***************************\n");
  printf("Please choice your number(1-3):[ ]\b\b");
  scanf("%d",&m);
  switch(m)
  {case 1:common_search();break;
   case 2:point_search();break;
   case 3:exit(0);
   }
}


int common_search()
{ int i,n,k,w1=1,w2,w3,w4;
  struct machine m;
  n=load();
  printf("Search the machine by name  or number?1-name,2-number:");
  scanf("%d",&i);
  if(i==1)
   {do
      {
        do
         { k=-1;
           printf("\n\nEnter the machine name that you want to search!   name:");
           scanf("%s",m.name);
           printf_face();
           for(i=0;i<n;i++)
           if(strcmp(m.name,mac[i].name)==0)
             { k=i;
	       printf_one(k);
             }
           if(k==-1)
             { printf("\n\nNO exist! please");
               printf("\n\nAre you again?\n\t1).again   2).NO and back  []\b\b");               scanf("%d",&w1);
               while(w1==1)  menu();
             }
         }
          while(k==-1&&w1==1);
         w4=0;w3=0;
        if(k!=-1)
          {printf("\n\nWhat do you want to do?\n\t1).Search another  2).Modify  3).Delete  4).Back menu  []\b\b");
           scanf("%d",&w2);
           switch(w2)
	      {case 2:w3=modify_data(k);break;
	       case 3:{printf("\nAre you sure?\n\t1).Sure   2).No and back  []\b\b");
	       scanf("%d",&w4);
	      }
	    }
        if(w3==1||w4==1)
	  {save(n);
	   printf("\n\nSuccessful.^_^.");
	   printf("\n\nWhat do you want to do?\n\t1).Search another   2).Back   []\b\b");
	   scanf("%d",&w2);
	  }
	}
       }
      while(w2==1);
  }
   if(i==2)
     {
       do
         {
          do
            { k=-1;
              printf("\n\nEnter the machine number that you want to search!   number:");
              scanf("%s",m.number);
              printf_face();
              for(i=0;i<n;i++)
              if(strcmp(m.number,mac[i].number)==0)
                { k=i;
	          printf_one(k);
                }
               if(k==-1)
                 { printf("\n\nNO exist! please");
                   printf("\n\nAre you again?\n\t1).again   2).NO and back  []\b\b");                   scanf("%d",&w1);
                   while(w1==1)  menu();
                  }
             }
          while(k==-1&&w1==1);
          w4=0;w3=0;
          if(k!=-1)
            { printf("\n\nWhat do you want to do?\n\t1).Search another  2).Modify  3).Delete  4).Back menu  []\b\b");
              scanf("%d",&w2);
              switch(w2)
	          { case 2:w3=modify_data(k);break;
	            case 3:{printf("\nAre you sure?\n\t1).Sure   2).No and back  []\b\b");
	            scanf("%d",&w4);
	           }
	    }
          if(w3==1||w4==1)
	    { save(n);
	      printf("\n\nSuccessful.^_^.");
	      printf("\n\nWhat do you want to do?\n\t1).Search another   2).Back   []\b\b");
	      scanf("%d",&w2);
	    }
	  }
         }
        while(w2==1);
      }
  menu();
}


int point_search()
{ int i,n,k,w1=1,w2,w3,w4;
  struct machine m;
  n=load();
  printf("Press 1-borrowin_time 2-borrowout_time or 3-return_time");
  scanf("%d",&i);
  if(i==1)
   {do
      {
        do
         { k=-1;
           printf("\n\nEnter the machine borrowin time that you want to search!   borrowin time:");
           scanf("%s",m.time);
           printf_face();
           for(i=0;i<n;i++)
           if(strcmp(m.time,mac[i].borrowin_time)==0)
             { k=i;
	       printf_one(k);
             }
           if(k==-1)
             { printf("\n\nNO exist! please");
               printf("\n\nAre you again?\n\t1).again   2).NO and back  []\b\b");               scanf("%d",&w1);
               while(w1==1)  menu();
             }
         }
          while(k==-1&&w1==1);
         w4=0;w3=0;
        if(k!=-1)
          {printf("\n\nWhat do you want to do?\n\t1).Search another  2).Modify  3).Delete  4).Back menu  []\b\b");
           scanf("%d",&w2);
           switch(w2)
	      {case 2:w3=modify_data(k);break;
	       case 3:{printf("\nAre you sure?\n\t1).Sure   2).No and back  []\b\b");
	       scanf("%d",&w4);
	      }
	    }
        if(w3==1||w4==1)
	  {save(n);
	   printf("\n\nSuccessful.^_^.");
	   printf("\n\nWhat do you want to do?\n\t1).Search another   2).Back   []\b\b");
	   scanf("%d",&w2);
	  }
	}
       }
      while(w2==1);
  }
   if(i==2)
     {
       do
         {
          do
            { k=-1;
              printf("\n\nEnter borrowout time:");
              scanf("%s",m.time);
              printf_face();
              for(i=0;i<n;i++)
              if(strcmp(m.time,mac[i].borrowout_time)==0)
                { k=i;
	          printf_one(k);
                }
               if(k==-1)
                 { printf("\n\nNO exist! please");
                   printf("\n\nAre you again?\n\t1).again   2).NO and back  []\b\b");                   scanf("%d",&w1);
                   while(w1==1)  menu();
                  }
             }
          while(k==-1&&w1==1);
          w4=0;w3=0;
          if(k!=-1)
            { printf("\n\nWhat do you want to do?\n\t1).Search another  2).Modify  3).Delete  4).Back menu  []\b\b");
              scanf("%d",&w2);
              switch(w2)
	          { case 2:w3=modify_data(k);break;
	            case 3:{printf("\nAre you sure?\n\t1).Sure   2).No and back  []\b\b");
	            scanf("%d",&w4);
	           }
	    }
          if(w3==1||w4==1)
	    { save(n);
	      printf("\n\nSuccessful.^_^.");
	      printf("\n\nWhat do you want to do?\n\t1).Search another   2).Back   []\b\b");
	      scanf("%d",&w2);
	    }
	  }
         }
        while(w2==1);
      }
 if(i==3)
     {
       do
         {
          do
            { k=-1;
              printf("\n\nEnter return time:");
              scanf("%s",m.time);
              printf_face();
              for(i=0;i<n;i++)
              if(strcmp(m.time,mac[i].return_time)==0)
                { k=i;
	          printf_one(k);
                }
               if(k==-1)
                 { printf("\n\nNO exist! please");
                   printf("\n\nAre you again?\n\t1).again   2).NO and back  []\b\b");                   scanf("%d",&w1);
                   while(w1==1)  menu();
                  }
             }
          while(k==-1&&w1==1);
          w4=0;w3=0;
          if(k!=-1)
            { printf("\n\nWhat do you want to do?\n\t1).Search another  2).Modify  3).Delete  4).Back menu  []\b\b");
              scanf("%d",&w2);
              switch(w2)
	          { case 2:w3=modify_data(k);break;
	            case 3:{printf("\nAre you sure?\n\t1).Sure   2).No and back  []\b\b");
	            scanf("%d",&w4);
	           }
	    }
          if(w3==1||w4==1)
	    { save(n);
	      printf("\n\nSuccessful.^_^.");
	      printf("\n\nWhat do you want to do?\n\t1).Search another   2).Back   []\b\b");
	      scanf("%d",&w2);
	    }
	  }
         }
        while(w2==1);
      }
  menu();
}


delete()
{ struct machine m;
  FILE *fp;
  int i,n,k,w0=1,w1,w2=0;
  n=load();
  do
  {
    k=-1;
    printf_face();
    for(i=0;i<n;i++)
       {if((i!=0)&&(i%10==0))
          {printf("\n\npass any key to continue...");
           getch();
           puts("\n\n");
           }
        printf_one(i);
       }

    do
      { printf("\nplease enter machine number you want to delete:");
	scanf("%s",m.number);
        for(i=0;i<n;i++)
	   if(strcmp(m.number,mac[i].number)==0)
	     { k=i;
	       m=mac[i];
	      }
	if(k==-1)printf("\n\nNO exist!Try again");
       } while(k==-1);
     printf_face();
     printf_one(k);
     printf("\nAre you sure?\n\n\t1).Sure 2).Back without save in this time  []\b\b");
     scanf("%d",&w1);
     if(w1==1)
       { /*mac[k].number=0;*/
	 printf("\nSuccessful^_^.\n\nAre you delete another?\n\n\t1).Yes  2).Back with save\t[]\b\b");
	 scanf("%d",&w0);
	 w2=1;
	}
      else
	 { w0=0;
	   if(w2==1)
	   mac[k]=m;
	 }
     if(w0!=1&&w2==1)
       save(n);
 }
 while(w0==1);
 printf_back();
}


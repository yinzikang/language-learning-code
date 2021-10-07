#include<stdio.h> 
#include<stdlib.h> 
#define MAX 2 /*车库容量*/ 
#define price 0.2 /*每车每分钟费用*/ 
  struct Car      /* 车的信息*/ 
{
	int carNO;//车牌号
   int  floor;	//层号
   int  position;	//车位号
   int  time;	//停车时间
}car[12];
  
int main() 
{ 
	int i,j,k;
	int carNUM;
	float fee;/*计算停车费用*/
	    char a;
    FILE *fp;
    int park[2][6]={1001,1002,1003,1004,0,0,0,0,0,0,0,0}; /*停车场状态 若为0表示车位空，否则值为carNO*/
    /* 初始化已停车的信息-------------------------------------------*/
	car[0].carNO = 1001; 
    car[0].floor = 1;
    car[0].position = 1;
    car[0].time = 20;
	car[1].carNO = 1002;
	car[1].floor = 1;
	car[1].position = 2;
	car[1].time = 15;
	car[2].carNO = 1003;
	car[2].floor = 1;
	car[2].position = 3;
	car[2].time = 10;
	car[3].carNO = 1004;
	car[3].floor = 1;
	car[3].position = 4;
	car[3].time = 5;

	if((fp=fopen("car.dat.txt","w")) ==NULL)
	{
		fprintf(stderr,"error opening file\n");
		exit(1);
	}
    for (i = 0; i<4;++i)
		fprintf(fp,"car[%d].carNO = %d\n car[%d].floor = %d\n car[%d].position = %d\n car[%d].time = %d\n",i,car[i].carNO,i,car[i].floor ,i,car[i].position,i,car[i].time);
	fclose(fp);
	printf("\n");
	/*初始化完毕－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－*/
    for(; ;)
	{  
     puts("\t\t*********欢迎来到车辆管理系统********\t\t");
		puts("\t\t****************MENU*****************");
		puts("\t\t\t\t 1.停车"); /*停车*/
		puts("\t\t\t\t 2.取车"); /*取车*/
		puts("\t\t\t\t 3.浏览"); /*浏览车辆信息*/
		puts("\t\t\t\t 4.退出"); /*退出*/
		puts("\t\t ************************************");
      scanf("  %c", &a);
      if(a== '1')
	  {
       printf(" 请输入车牌号: " ); 
       scanf(" %d",&car[i].carNO);
       for (j = 0; j<2;++j)
	   {
	     for (k = 0; k<6;++k)
		 {
			 if(park[j][k] ==0)
			 {park[j][k] = car[i].carNO; break;}
		 }
         if(park[j][k] == car[i].carNO)
			 break;
	   }
       	car[i].floor = j+1;
	    car[i].position = k+1;
    	car[i].time = 5;
        for (j = 0; j<i;++j)  /*将在此前的所有车的停车时间加5*/
        car[j].time += 5;
    	if((fp=fopen("car.dat.txt","w")) ==NULL)/*将所有停车信息刷新后写出到car.dat*/
		{
	    	fprintf(stderr,"error opening file\n");
	    	exit(1);
		}
        for (j = 0; j<i+1;++j)
       fprintf(fp,"car[%d].carNO = %d\n car[%d].floor = %d\n car[%d].position = %d\n car[%d].time = %d\n",j,car[j].carNO,j,car[j].floor ,j,car[j].position,j,car[j].time);
	   fclose(fp);
       printf("\n");
	   printf(" 停车操作完成\n " );
       printf(" -----------------------------------------------------------------\n " );
	   ++i;
	  }
     else  if(a== '2')
	   {
	   printf(" 请输入要离开车的车牌号: " ); 
	    scanf(" %d",&carNUM);
        for (j = 0; j<i;++j)
		{
			if(carNUM == car[j].carNO)
			{
                fee = (float)car[j].time/5*0.2;
				printf(" 车牌号为%d的停车费为：  " ,carNUM);
				printf("%f\n",fee);
				printf(" -----------------------------------------------------------------\n " );
                park[j/6][j%6] = 0;
    	if((fp=fopen("car.dat.txt","w")) ==NULL)/*将所有停车信息刷新后写出到car.dat*/
		{
	    	fprintf(stderr,"error opening file\n");
	    	exit(1);
		}
        for (k = 0; k<j;++k)
       fprintf(fp,"car[%d].carNO = %d\n car[%d].floor = %d\n car[%d].position = %d\n car[%d].time = %d\n",k,car[k].carNO,k,car[k].floor ,k,car[k].position,k,car[k].time);
        for (++k; k<i;++k)
       fprintf(fp,"car[%d].carNO = %d\n car[%d].floor = %d\n car[%d].position = %d\n car[%d].time = %d\n",k,car[k].carNO,k,car[k].floor ,k,car[k].position,k,car[k].time);
	   fclose(fp);
       printf("\n");
				break;
			}

		}
         if(j == i)
	    	printf(" 没有此号码或者输入错误！\n" );
         else continue;
		 printf(" -----------------------------------------------------------------\n " );
	   }
      else if(a== '3')
	   {
				printf(" 停车场所有车辆信息如下： \n ");
				printf(" 车牌号 层号 车位号 停车时间\n ");
				for (j = 0; j<2;++j)
				{
	               for (k = 0; k<6;++k)
				   {
			        if(park[j][k] !=0)
	printf("%d     %d    %d     %d \n ",car[j*6+k].carNO,car[j*6+k].floor,car[j*6+k].position,car[j*6+k].time);
					else continue;
				   }
				}
    	if((fp=fopen("car.dat.txt","w")) ==NULL)/*将所有停车信息刷新后写出到car.dat*/
		{
	 	fprintf(stderr,"error opening file\n");
	    	exit(1);
		}
       printf(" -----------------------------------------------------------------\n " );
	   }
      else if(a=='4')
	   {
     
          printf(" press any key to continue... " );
           break;
     
	   }
	   else 
	   {
        printf(" input error! please input again！\n" );
        printf(" -----------------------------------------------------------------\n " );
	   } 
	}
}
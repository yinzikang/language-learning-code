#include<stdio.h> 
#include<stdlib.h> 
#define MAX 2 /*��������*/ 
#define price 0.2 /*ÿ��ÿ���ӷ���*/ 
  struct Car      /* ������Ϣ*/ 
{
	int carNO;//���ƺ�
   int  floor;	//���
   int  position;	//��λ��
   int  time;	//ͣ��ʱ��
}car[12];
  
int main() 
{ 
	int i,j,k;
	int carNUM;
	float fee;/*����ͣ������*/
	    char a;
    FILE *fp;
    int park[2][6]={1001,1002,1003,1004,0,0,0,0,0,0,0,0}; /*ͣ����״̬ ��Ϊ0��ʾ��λ�գ�����ֵΪcarNO*/
    /* ��ʼ����ͣ������Ϣ-------------------------------------------*/
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
	/*��ʼ����ϣ�����������������������������������������������������������������*/
    for(; ;)
	{  
     puts("\t\t*********��ӭ������������ϵͳ********\t\t");
		puts("\t\t****************MENU*****************");
		puts("\t\t\t\t 1.ͣ��"); /*ͣ��*/
		puts("\t\t\t\t 2.ȡ��"); /*ȡ��*/
		puts("\t\t\t\t 3.���"); /*���������Ϣ*/
		puts("\t\t\t\t 4.�˳�"); /*�˳�*/
		puts("\t\t ************************************");
      scanf("  %c", &a);
      if(a== '1')
	  {
       printf(" �����복�ƺ�: " ); 
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
        for (j = 0; j<i;++j)  /*���ڴ�ǰ�����г���ͣ��ʱ���5*/
        car[j].time += 5;
    	if((fp=fopen("car.dat.txt","w")) ==NULL)/*������ͣ����Ϣˢ�º�д����car.dat*/
		{
	    	fprintf(stderr,"error opening file\n");
	    	exit(1);
		}
        for (j = 0; j<i+1;++j)
       fprintf(fp,"car[%d].carNO = %d\n car[%d].floor = %d\n car[%d].position = %d\n car[%d].time = %d\n",j,car[j].carNO,j,car[j].floor ,j,car[j].position,j,car[j].time);
	   fclose(fp);
       printf("\n");
	   printf(" ͣ���������\n " );
       printf(" -----------------------------------------------------------------\n " );
	   ++i;
	  }
     else  if(a== '2')
	   {
	   printf(" ������Ҫ�뿪���ĳ��ƺ�: " ); 
	    scanf(" %d",&carNUM);
        for (j = 0; j<i;++j)
		{
			if(carNUM == car[j].carNO)
			{
                fee = (float)car[j].time/5*0.2;
				printf(" ���ƺ�Ϊ%d��ͣ����Ϊ��  " ,carNUM);
				printf("%f\n",fee);
				printf(" -----------------------------------------------------------------\n " );
                park[j/6][j%6] = 0;
    	if((fp=fopen("car.dat.txt","w")) ==NULL)/*������ͣ����Ϣˢ�º�д����car.dat*/
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
	    	printf(" û�д˺�������������\n" );
         else continue;
		 printf(" -----------------------------------------------------------------\n " );
	   }
      else if(a== '3')
	   {
				printf(" ͣ�������г�����Ϣ���£� \n ");
				printf(" ���ƺ� ��� ��λ�� ͣ��ʱ��\n ");
				for (j = 0; j<2;++j)
				{
	               for (k = 0; k<6;++k)
				   {
			        if(park[j][k] !=0)
	printf("%d     %d    %d     %d \n ",car[j*6+k].carNO,car[j*6+k].floor,car[j*6+k].position,car[j*6+k].time);
					else continue;
				   }
				}
    	if((fp=fopen("car.dat.txt","w")) ==NULL)/*������ͣ����Ϣˢ�º�д����car.dat*/
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
        printf(" input error! please input again��\n" );
        printf(" -----------------------------------------------------------------\n " );
	   } 
	}
}
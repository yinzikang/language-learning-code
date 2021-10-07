#include<stdio.h>
#include<math.h>
void   main()     
{     
	void impartial(float a[],float aver);
	float sco[10],max,min,sum,aver,w; 
    int i;
    max=0;       
    min=100;        
    sum=0;       
    w=0; 
    for(i=1;i<=11;i++)     
	{     
		if(i==11) break;
		printf("Input  the score of judger %d =",i);     
        scanf("%f",&sco[i-1]);
		if(sco[i-1]>100)
		{
			w=1;
			break;
		}
        sum+=sco[i-1];
	    if(sco[i-1]>max) max=sco[i-1];
	    if(sco[i-1]<min) min=sco[i-1];
	 }
	 aver=(sum-max-min)/8;
	 if(i<11&&w==1) 
	 {
		 printf("\nSorry, the score is wrong! Please enter again!\n");
		 main();
	 }
	 else
	 {
	 printf ("the max score:%f and the min score:%f is cancled\n",max,min);
	 printf ("average score=%f\n",aver);
	 impartial(sco,aver);
	 }
}


void impartial(float a[],float aver)
{
	int j,m,n;
	float mx,mn,y;
	mx=0;
	mn=100;
	m=0;
	n=0;
	for(j=0;j<10;j++)
	{
		y=fabs(aver-a[j]);
	    if (y>mx) {mx=y;m=j+1;};
	    if (y<mn) {mn=y;n=j+1;};
	}
	printf("the most impartial judger is the judger %d and the most partial one is the judger %d\n",n,m);
}






#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct msg{
	char name[20];
	char sex[10];
	char dialnumber[11];
    int  count;
    float price;
    float money;
    char date[20];
	char readeraddr[50];
}msgnode;

void Start(){
	printf("****************************************************************************\n");
	printf("******                                                                ******\n");
	printf("******                                                                ******\n");
	printf("******          Welcome to the magazine order   system !~_~           ******\n");
	printf("******                                                                ******\n");
	printf("****************************************************************************\n");
}

void TextOut(){
	printf("\t\twanna check message,press------------------0.\n\n");
    printf("\t\twanna ADD a new reader,press---------------1.\n\n");
	printf("\t\twanna update the message table,press-------2.\n\n");
	printf("\t\twanna output all the message ,press--------3.\n\n");
	printf("\t\twanna display readers this month. ,press---4.\n\n");
	printf("\t\twanna exit,press---------------------------5.\n\n");
}

int CheckDateMon(char * date){
    char chdate[3];
    chdate[0]=date[5];
    chdate[1]=date[6];
    chdate[2]='\0';
    return atoi(chdate);
}

int CheckDateDay(char * date){
	char chdate[3];
	chdate[0]=date[8];
	chdate[1]=date[9];
    chdate[2]='\0';
    return atoi(chdate);
}

int AddReader(){
	FILE *fp;
    msgnode  ad;
    if((fp=fopen("MSG.txt","at"))==NULL){
		printf("Cannot open the file or Cannot find the file.please check out .\n");
        getch();
        return 0;
	}
	printf("input start. ^_^ \n");
    printf("please input the name: ^_^ \n");
    scanf("%s",ad.name);
	printf("please input the sex[male/female]: ^_^ \n");
    scanf("%s",ad.sex);
	printf("please input the dialnumber: ^_^ \n");
    scanf("%s",ad.dialnumber);
    printf("please input the count: ^_^ \n");
    scanf("%d",&ad.count);
    printf("please input the price: ^_^ \n");
    scanf("%f",&ad.price);
    printf("please input the date: ^_^ \n");
    scanf("%s",ad.date);
    while(ad.date[4]!='.'|| ad.date[7]!='.'|| strlen(ad.date)!=10
         ||CheckDateMon(ad.date)>=13||CheckDateDay(ad.date)>=32){
		printf("the format is not right or the date is not existed.\n ");
        printf("You should input the date like this 'YYYY.MM.DD'\n");
		printf("please input the date again: ^_^ \n");
        scanf("%s",ad.date);
	}
	printf("please input the address of reader: ^_^ \n");
    scanf("%s",ad.readeraddr);
    fprintf(fp,"%15s %8s %13s %7d %7.2f %10.2f %13s %-50s\n"
		,ad.name,ad.sex,ad.dialnumber,ad.count,ad.price,ad.count*ad.price,ad.date,ad.readeraddr);
    fclose(fp);
    return 1;
}

int UpdateMsg(char *currdate){
	msgnode currnode,movenode ;
    int i=0,j=0;
    FILE *fp;
    if((fp=fopen("MSG.txt","rt+"))==NULL){
		printf("%s \n","Cannot open the file or Cannot find the file.please check out .");
        return 0;
	}
	i=ftell(fp);
    fscanf(fp,"%s%s%s%d%f%f%s%s"
	       ,currnode.name,currnode.sex,currnode.dialnumber
	,&currnode.count,&currnode.price,&currnode.money,currnode.date,currnode.readeraddr);
    j=ftell(fp);
	j=j-i;
	rewind(fp);
	while(!feof(fp)){
		fscanf(fp,"%s%s%s%d%f%f%s%s"
	       ,currnode.name,currnode.sex,currnode.dialnumber
			  ,&currnode.count,&currnode.price,&currnode.money,currnode.date,currnode.readeraddr);
		if(feof(fp))
			break;
		if(strcmp(currdate,currnode.date)>0){
                fseek(fp,-j,1);
                fprintf(fp,"%15s %8s %13s %7d %7.2f %10.2f %13s %-50s"
		            ,"NULL","NULL","NULL",0
					,0.0,0.0,"9999.99.99","NULL");
                fseek(fp,2L,1);
		} 
	}
    return 1;
}

int OutputAll(){
	FILE *fp;
    msgnode  oa;
    int allcount=0;
    float allmoney=0;
    if((fp=fopen("MSG.txt","rt"))==NULL){
		printf("Cannot open the file or Cannot find the file.please check out .\n");
        getch();
		return 0;
	}
    printf("%15s %8s %13s %7s  %7s  %10s  %13s %-50s\n"
		,"readername ","readsex ","number "
		,"count ","price ","moneysum ","date ","readeraddress");
    while(!feof(fp)){
		fscanf(fp,"%s%s%s%d%f%f%s%s"
			,oa.name,oa.sex,oa.dialnumber,&oa.count
			,&oa.price,&oa.money,oa.date,oa.readeraddr);
		if(feof(fp))
			break;
        allcount+=oa.count;
        allmoney+=oa.money;
		if(strcmp(oa.sex,"NULL"))
        printf("%15s %8s %13s %7d %7.2f %10.2f %13s %-50s\n"
			,oa.name,oa.sex,oa.dialnumber,oa.count,oa.price,oa.money, oa.date,oa.readeraddr);
	}
    printf("%15s %8s %13s %7d %7.2f %10.2f %13s %-50s\n"
		,"heji","--","-----------",allcount,"----",allmoney,"2007.09.04","----");
	return 1;
}



int CheckReader(char *name){
	FILE *fp;
    int i,j;
    char ch;
    msgnode cr;
    if((fp=fopen("MSG.txt","rt"))==NULL){
		printf("Cannot open the file or Cannot find the file.please check out .");
		getch();
        return 0;
	}
	i=ftell(fp);
    fscanf(fp,"%s%s%s%d%f%f%s%s"
			,cr.name,cr.sex,cr.dialnumber,&cr.count,&cr.price,&cr.money,cr.date,cr.readeraddr);
    j=ftell(fp);
    rewind(fp);
    j=j-i;
	while(!feof(fp)){
		fscanf(fp,"%s%s%s%d%f%f%s%s"		,cr.name,cr.sex,cr.dialnumber,&cr.count,&cr.price,&cr.money,cr.date,cr.readeraddr);
	    i=ftell(fp);
		if(!strcmp(cr.name,name)){
			printf("The reader you are checking is existed in the list.\n");
				fseek(fp,-j,1);
			    fscanf(fp,"%s%s%s%d%f%f%s%s"
			         ,cr.name,cr.sex,cr.dialnumber,&cr.count
					 ,&cr.price,&cr.money,cr.date,cr.readeraddr);
				if(feof(fp))
					break;
			    printf("%15s %8s %13s %7d  %7f  %10f  %13s %-50s\n"
                                 ,cr.name,cr.sex,cr.dialnumber,cr.count
                                      ,cr.price,cr.money,cr.date,cr.readeraddr);
				return 1;
			
		}
	}
}

int DisplayReader(char *date){
	FILE *fp;
    int i,j;
    msgnode cr;
    if((fp=fopen("MSG.txt","rt"))==NULL){
		printf("Cannot open the file or Cannot find the file.please check out .");
		getch();
        return 0;
	}
	while(!feof(fp)){
		fscanf(fp,"%s%s%s%d%f%f%s%s"
			,cr.name,cr.sex,cr.dialnumber,&cr.count,&cr.price,&cr.money,cr.date,cr.readeraddr);
		if(feof(fp))
			break;
		if(!strcmp("9999.99.99",cr.date))
			continue;
		if(strcmp(date,cr.date)<0 ){
			    printf("%15s %8s %13s %7d  %7f  %10f  %13s %-50s\n"
                                 ,cr.name,cr.sex,cr.dialnumber,cr.count
                                      ,cr.price,cr.money,cr.date,cr.readeraddr);			
		}
	}
	return 1;
}

main(){
    char str[30];
	int ch;
	Start();
	TextOut();
	scanf("%d",&ch);
	while(ch!=5){
		if(ch==0){
			printf("Please input the name you wanna index: ^_^\n");
			scanf("%s",str);
			if(CheckReader(str))
				printf("You have successfully index the reader!\n");
            TextOut();
			scanf("%d",&ch);
			continue ;
        }
		if(ch==1){
			if(AddReader())
				printf("You have successfully add a reader!\n");
			TextOut();
			scanf("%d",&ch);
			continue ;
		}
		if(ch==2){
			printf("Please input the current date: ^_^\n");
			scanf("%s",str);
            if(UpdateMsg(str))
				printf("You have successfully update the list!\n");
			TextOut();
			scanf("%d",&ch);
			continue ;
		}
		if(ch==3){
            if(OutputAll())
				printf("You have successfully output the list!\n");
			TextOut();
			scanf("%d",&ch);
			continue ;
		}
		if(ch==4){
			printf("Please input the month you wanna display: ^_^\n");
			scanf("%s",str);
			if(DisplayReader(str))
				printf("You have successfully all the readers this month!\n");
			TextOut();
			scanf("%d",&ch);
			continue ;
		}
		else return;
	}
}

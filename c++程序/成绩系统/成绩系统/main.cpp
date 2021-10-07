#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <Windows.h>

using namespace std;

struct STU
{
    int num ;  //学号
    char name [1000] ; //不超过1000人
    char sex ;  //M为男生；F为女生
    double score [3] ;  //依次输入数学，语文，英语成绩
    double average ;   //计算平均分
}*pstu;
int stdnt_num = 0;  //学生数

void function_1();  //添加功能
void function_2();  //浏览功能
void function_3();  //删除功能
void function_4();  //查找功能
void function_5();  //排序功能
void function_6();  //统计功能
void function_7();  //保存功能
void function_8();  //加载功能
int alloc(struct STU* &pstu,int n,int newElemCount = 1);
bool input(STU* pStuNew);
void list(struct STU*pstu,int n);
int getIndex(struct STU*pstu,int n,int m);
void del(struct STU*pstu,int n,int iDel);

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
    int choice;

    cout<<"Welcome to the student grades management system!"<<endl;

    while(1)
    {
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        cout<<"\t\thomepage"<<endl;
        cout<<"\t====================="<<endl;
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);

        cout<<"Numbers correspond to functions as follows:"<<endl;
        cout<<"\t1.add\t\t5.sort"<<endl;
        cout<<"\t2.view\t\t6.statistics"<<endl;
        cout<<"\t3.delete\t7.save"<<endl;
        cout<<"\t4.find\t\t8.load"<<endl;
        cout<<"\totherwise,exit"<<endl;

        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        cout<<"\t====================="<<endl;
        cout<<"please elect:";
        cin>>choice;
        cout<<"\n";
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);

        switch(choice)
        {
            case 1:function_1();break;
            case 2:function_2();break;
            case 3:function_3();break;
            case 4:function_4();break;
            case 5:function_5();break;
            case 6:function_6();break;
            case 7:function_7();break;
            case 8:function_8();break;
            default:cout<<"Thank you, goodbye!"<<endl;
        }
        if(choice < 1 || choice > 8) break;
    }
    delete [] pstu;
    return 0;
}

void function_1()       //添加功能
{
    stdnt_num = alloc(pstu, stdnt_num);
    if(stdnt_num == 0)
    {
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout<<"Extending zone failed!"<<endl;
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
    }
    else
    {
        if(input(pstu + stdnt_num - 1))
        {
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            cout<<"\nAdding succeed! now "<<stdnt_num<<" students in all."<<endl;
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
        }
        else
        {
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
            cout<<"Adding failed!"<<endl;
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
        }
    }
}

void function_2()       //浏览功能
{
    list(pstu,stdnt_num);
}

void function_3()       //删除功能
{
    int index,a;

    if(pstu == 0)
    {
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout<<"No student available!"<<endl;
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
    }
    else
    {
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        cout<<"Please input the ID of the student you want to delete:";
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
        cin.clear();
        cin.ignore(1024,'\n');
        cin>>a;
        cout<<"\n";
        index = getIndex(pstu,stdnt_num,a);
        if(index < 0)
        {
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
            cout<<"Target does not exist!"<<endl;
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
        }
        else
        {
            del(pstu,stdnt_num,index);
            stdnt_num --;
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            cout<<"Delete succeed! Now "<<stdnt_num<<" students in all"<<endl;
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
        }
    }
}

void function_4()       //查找功能
{
    int index,a,i;

    if(pstu == 0)
    {
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout<<"No student available!"<<endl;
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
    }
    else
    {
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        cout<<"Please input the ID of the student you want to find:";
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
        cin.clear();
        cin.ignore(1024,'\n');
        cin>>a;
        cout<<"\n";
        index = getIndex(pstu,stdnt_num,a);
        if(index < 0)
        {
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
            cout<<"Target does not exist!"<<endl;
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
        }
        else
        {
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            cout<<"Student found!"<<endl;
            cout<<"Student ID\tName\tSex\tMath\tChinese\tEnglish\tAverage"<<endl;
            cout<<pstu[index].num<<"\t";
            cout<<pstu[index].name<<"\t";
            cout<<pstu[index].sex<<"\t";
            for (i = 0;i < 3;i ++)
                cout<<pstu[index].score[i]<<"\t";
            cout<<setprecision(4)<<pstu[index].average<<endl;
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
        }
    }
}

void function_5()       //排序功能
{
    int n,i,j,k;
    struct STU t;

    if(pstu == 0)
    {
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout<<"No student available!"<<endl;
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
    }
    else
    {
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        cout<<"\n1.sort by ID\t2.sort by name\t3.sort by average grade\n";
        cout<<"Please elect:";
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
        cin>>n;
        switch(n)
        {
            case 1:
                for(i = 0;i < stdnt_num - 1;i ++)
                {
                    k = i;
                    for(j = i + 1;j < stdnt_num;j ++)
                        if(pstu[j].num < pstu[j+1].num)
                            k = j;
                    if(i != k)
                    {
                        t = pstu[i];
                        pstu[i] = pstu[k];
                        pstu[k] = t;
                    }
                }
                break;
            case 2:
                for(i = 0;i < stdnt_num - 1;i ++)
                {
                    k = i;
                    for(j = i + 1;j < stdnt_num;j ++)
                        if(strcmp(pstu[j].name,pstu[j+1].name) < 0)
                            k = j;
                    if(i != k)
                    {
                        t = pstu[i];
                        pstu[i] = pstu[k];
                        pstu[k] = t;
                    }
                }
                break;
            case 3:
                for(i = 0;i < stdnt_num - 1;i ++)
                {
                    k = i;
                    for(j = i + 1;j < stdnt_num;j ++)
                        if(pstu[j].average < pstu[j+1].average)
                            k = j;
                    if(i != k)
                    {
                        t = pstu[i];
                        pstu[i] = pstu[k];
                        pstu[k] = t;
                    }
                }
                break;
            default : cout<<"false input!"<<endl;
        }
        for (i = 0;i < n;i ++)
        {
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            cout<<pstu[i].num<<"\t";
            cout<<pstu[i].name<<"\t";
            cout<<pstu[i].sex<<"\t";
            for (j = 0;j < 3;j ++)
                cout<<pstu[i].score[j]<<"\t";
            cout<<setprecision(4)<<pstu[i].average<<endl;
            SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
        }
    }
}

void function_6()       //统计功能
{
    int over60 = 0,over90 = 0,max = 0,min = 100,i = 0;
    char a;

    if(pstu == 0)
    {
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout<<"No student available!"<<endl;
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
    }
    else
    {
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        cout<<"Please input the subject name:(M for math,C for Chinese and E for English):";
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
        cin>>a;
        switch(a)
        {
            case 'M':
                for(i = 0;i < stdnt_num;i ++)
                {
                    if(pstu[i].score[0] >= 60) over60 ++;
                    if(pstu[i].score[0] >= 90) over90 ++;
                    ave += (pstu[i].average / stdnt_num);
                    if(pstu[i].score[0] > max)  max = pstu[i].score[0];
                    if(pstu[i].score[0] < min)  min = pstu[i].score[0];
                }
                break;
            case 'C':
                for(i = 0;i < stdnt_num;i ++)
                {
                    if(pstu[i].score[1] >= 60) over60 ++;
                    if(pstu[i].score[1] >= 90) over90 ++;
                    ave += (pstu[i].score[1] / stdnt_num);
                    if(pstu[i].score[1] > max)  max = pstu[i].score[1];
                    if(pstu[i].score[1] < min)  min = pstu[i].score[1];
                }
                break;
            case 'E':
                for(i = 0;i < stdnt_num;i ++)
                {
                    if(pstu[i].score[2] >= 60) over60 ++;
                    if(pstu[i].score[2] >= 90) over90 ++;
                    ave += (pstu[i].score[2] / stdnt_num);
                    if(pstu[i].score[2] > max)  max = pstu[i].score[2];
                    if(pstu[i].score[2] < min)  min = pstu[i].score[2];
                }
                break;
            default : cout<<"\nfalse input!"<<endl;
        }
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        cout<<"\n>=60:"<<over60<<"\t>=90:"<<over90<<"\tmax:"<<max<<"\tmin:"<<min<<"\taverage:"<<ave<<endl;
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
    }
}

void function_7()       //保存功能
{

}

void function_8()       //加载功能
{

}

bool input(STU * pStuNew)
{
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    cout<<"Please input student's information";
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);

    cin.clear();
    cin.ignore(1024,'\n');
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    cout<<"\nStudent ID:";
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
    cin>>pStuNew->num;

    cin.clear();
    cin.ignore(1024,'\n');
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    cout<<"Name:";
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
    cin>>pStuNew->name;

    cin.clear();
    cin.ignore(1024,'\n');
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    cout<<"Sex(M/F):";
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
    cin>>pStuNew->sex;
    if(pStuNew->sex >= 'a' && pStuNew->sex <= 'z')
        pStuNew->sex -= 32;

    int i;
    for(i = 0;i < 3;i ++)
    {
        cin.clear();
        cin.ignore(1024,'\n');
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        switch(i)
        {
            case 0:cout<<"Math:";break;
            case 1:cout<<"Chinese:";break;
            case 2:cout<<"English:";break;
        }
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
        cin>>pStuNew->score[i];
    }

    double sum = 0;
    for (i = 0;i < 3;i ++)
        sum = sum + pStuNew->score[i];
    pStuNew->average = sum / 3;
    return true;
}

int alloc(struct STU * &pstu,int n,int newElemCount)
{
    struct STU *pbuff = 0;
    int i;

    pbuff = new struct STU [n + newElemCount];

    if(pbuff == 0)
        return 0;

    if(pstu != 0)
    {
        for (i = 0;i < n;i ++)
        pbuff[i] = pstu[i];         //结构体复制
    }
    delete[] pstu;
    pstu = pbuff;
    return n + newElemCount;
}

void list(struct STU *pstu, int n)
{
    int i,j;
    if(pstu == 0)
    {
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
        cout<<"No student available!"<<endl;
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
    }
    else
    {
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        cout<<"Student ID\tName\tSex\tMath\tChinese\tEnglish\tAverage"<<endl;
        for (i = 0;i < n;i ++)
        {
            cout<<pstu[i].num<<"\t";
            cout<<pstu[i].name<<"\t";
            cout<<pstu[i].sex<<"\t";
            for (j = 0;j < 3;j ++)
                cout<<pstu[i].score[j]<<"\t";
            cout<<setprecision(4)<<pstu[i].average<<endl;
        }
        cout<<"Now "<<n<<" students in all."<<endl;
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
    }
}

int getIndex(struct STU*pstu,int n,int m)
{
    int i;
	for(i = 0;i < n;i ++)
		if(pstu[i].num == m) return i;
	return -1;
}

void del(struct STU*pstu,int n,int iDel)
{
    int i;
	for (i = iDel;i < n-1;i ++)
		pstu[i] = pstu[i + 1];
}

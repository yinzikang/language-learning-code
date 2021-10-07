#include <iostream>
#include <cmath>
using namespace std;

double GetNum()
{
    double num;
    cout<<"请输入一条边的长度"<<endl;
	cin>>num;
	while(num <= 0)
	{
        cout<<"你的输入有误，请重新输入"<<endl;
        cin>>num;
	}
	return num;
}

double g(double a,double b,double c)
{
    double p,area;
	p=(a+b+c)/2;
	area=sqrt(p*(p-a)*(p-b)*(p-c));
	return area;
}

double f(double a,double b,double c)
{
    if(((a+b)>c)&&((a+c)>b)&&((b+c)>a))
	cout<<"这三条边可以构成三角形且三角形的面积为："<<g(a,b,c)<<endl;
	else cout<<"这三条边不能构成三角形"<<endl;
	return 0;
}

int main()
{	double a,b,c;
	a=GetNum();
	b=GetNum();
	c=GetNum();
	f(a,b,c);
	return 0;
}


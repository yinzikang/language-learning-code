#include <iostream>
#include <cmath>
using namespace std;

double GetNum()
{
    double num;
    cout<<"������һ���ߵĳ���"<<endl;
	cin>>num;
	while(num <= 0)
	{
        cout<<"���������������������"<<endl;
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
	cout<<"�������߿��Թ����������������ε����Ϊ��"<<g(a,b,c)<<endl;
	else cout<<"�������߲��ܹ���������"<<endl;
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


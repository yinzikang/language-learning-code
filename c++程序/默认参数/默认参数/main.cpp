#include <iostream>
using namespace std;
int cheng(int a=1,int b=1,int c=1,int d=1, int e=1)
{
    return a*b*c*d*e;
}
int main()
{
    cout<<cheng(10)<<endl;
    cout<<cheng(10,10)<<endl;
    cout<<cheng(10,10,10)<<endl;
    cout<<cheng(10,10,10,10)<<endl;
    cout<<cheng(10,10,10,10,10)<<endl;
    return 0;
}

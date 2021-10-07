#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    bool v;
    int a,m,n;
    double x,y,z,p,f;
    float f1;
    cin >>boolalpha>>v;
    cin >>oct>>a >>hex>>m >>dec>>n;
    cin >>p>>f>>f1>>x>>y>>z;
    cout<<v<<'\t'<<boolalpha<<v<<'\t'<<noboolalpha<<v<<endl;
    cout<<a<<'\t'<<p<<endl<<a*p<<endl;
    cout<<hex<<m<<'\t'<<oct<<m<<'\t'<<dec<<m<<endl;
    cout<<showbase<<hex<<m<<'\t'<<y<<'\t'<<dec<<m<<endl;
    cout.precision(5);cout<<x<<'\t'<<y<<'\t'<<z<<endl;
    cout<<fixed<<x<<'\t'<<y<<'\t'<<z<<endl;
    cout<<scientific<<x<<'\t'<<y<<'\t'<<z<<endl;
    cout<<left<<setw(6)<<n<<'\t'<<internal<<setw(6)<<n<<'\t';
    cout.width(6);cout<<right<<n<<setfill('0')<<endl;
    cout<<setw(10)<<77<<'\t'<<setfill('x')<<setw(10)<<77<<endl;
    cout<<setprecision(5)<<f1<<'\t'<<setprecision(9)<<f1<<endl;
    cout<<fixed<<setprecision(5)<<f<<'\t'<<setprecision(9)<<f<<endl;
    cout<<scientific<<setprecision(5)<<f<<'\t'<<setprecision(9)<<f<<endl;
    cout<<setiosflags(ios_base::floatfield|ios_base::showpoint);
    cout<<setprecision(0)<<f<<'\t'<<setprecision(9)<<f<<endl;
    cout<<showpos<<1<<'\t'<<0<<'\t'<<-1<<endl;
    cout<<noshowpos<<1<<'\t'<<0<<'\t'<<-1<<endl;
    return 0;
}

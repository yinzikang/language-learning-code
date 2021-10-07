#include <iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main()
{
    int a,b,c,d,l;
    string str;
    cin>>str;
    char *p,*q = &str[0];
    a = atof(q);
    p = q + str.find_first_of("/",0) + 1;
    b = atof(p);
    if(str.find("+",0) >= 0)
    {
        p = q + str.find("+",0) + 1;
        c = atof(p);
        p = q + str.find_last_of("/",0) + 1;
        d = atof(p);
    }
    else
    {
        p = q + str.find("-",0) + 1;
        c = atof(p);
        p = q + str.find_last_of("/",0) + 1;
        d = atof(p);
    }
    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
    return 0;
}

#include <iostream>
#include<string>
using namespace std;
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    str1.erase(str1.find(str2,0),str2.size());
    cout<<str1<<endl;
    return 0;
}

#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    cout<<n<<'*'<<n<<'*'<<n<<'=';
    for(i = 1;i < n;i ++)
        cout<<n*n-n-1+2*i<<'+';
    cout<<n*n+n-1;
    return 0;
}

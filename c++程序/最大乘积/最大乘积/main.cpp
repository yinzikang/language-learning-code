#include <iostream>
using namespace std;
int main()
{
    int i,j,k,sum;
    cin>>i>>j>>k;
    for(sum = 10;;sum ++)
        if((sum%3==i)&&(sum%5==j)&&(sum%7==k))
        {
            cout<<sum<<endl;
            break;
        }
    return 0;
}

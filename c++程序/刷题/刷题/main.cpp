#include <iostream>
using namespace std;
int judge(int i,int j)
{
    int p,q,a[10];
    for(p = 0;p < 5;p ++)
    {
        a[p] = i % 10;
        i /= 10;
    }
    for(p = 5;p < 10;p ++)
    {
        a[p] = j % 10;
        j /= 10;
    }
    for(p = 0;p < 9;p ++)
        for(q = p + 1;q < 10;q ++)
            if(a[p] == a[q]) return 0;
    return 1;
}
int main()
{
    int n,i,j;
    cin>>n;
    for(i = 01251;i<=49382;i ++)
    {
        j = n * i;
        if(j <= 98765)
            if(judge(i,j))
                cout<<j<<'/'<<i<<'='<<n<<endl;
    }
    return 0;
}

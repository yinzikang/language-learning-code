#include <iostream>
#define N 10
using namespace std;
int main()
{
    int a[N],i,j,k,t;
    for(i = 0;i < N;i ++)
        cin>>a[i];

    /*√∞≈›≈≈–Ú*/
    for(j = 0;j < N - 1 - j;j ++)
        for(i = 0;i < N - 1 - j;i ++)
            if(a[i]>a[i + 1])
            {
                t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
            }
    for(i = 0;i < N;i ++)
        cout<<a[i];

    /*—°‘Ò≈≈–Ú*/
    for(i = 0;i < n - 1;i ++)
    {
        k = i;
        for(j = i + 1;j < n;j ++)
            if(a[j] < a[k])
                k = j;
        if(i != k)
        {
            t = a[i];
            a[i] = a[k];
            a[k] = t;
        }
    }
}

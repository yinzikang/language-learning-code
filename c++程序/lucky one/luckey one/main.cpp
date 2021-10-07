#include <iostream>
using namespace std;
int main()
{
    int n,x,kill[20];
    cin>>n>>x;
    int i = 0,j = 0,sum = 0,kids = n,live[n];
    for(i = 0;i < 20;i ++)
        cin>>kill[i];
    for(i = 0;i < n;i ++)
        live[i] = 1;
    while(kids > x)
    {
        for(i = 0;i < n;i ++)
        {
            sum += live[i];
            if(sum == kill[j])
            {
                sum = 0;
                live[i] = 0;
                kids --;
            }
        }
        j ++;
    }
    for(i = 0;i < n;i ++)
        if(live[i])
            cout<<i+1<<' ';
    return 0;
}

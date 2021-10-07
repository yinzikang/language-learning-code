#include <iostream>
#include <iomanip>
using namespace std;
int play()
{
    cout<<"这还差不多"<<endl;
    int i,j,num;
    for(i = 2,num = 0;num < 100;i ++)
    {
        for(j = 2;j <= i;j ++)
            if(!(i%j)) break;
        if(i == j)
        {
            num ++;
            cout<<"第"<<setw(3)<<num<<"个素数为"<<setw(3)<<i<<",邹豪坤这个傻逼"<<endl;
        }
    }
    return 1;
}
int main()
{
    int m;
    string q[5] = {"你的名字","尹子康是不是比你帅（ 是 或 否）","尹子康是不是比你拽（ 是 或 否）","你是不是该请客（ 是 或 否）","你是不是该谈恋爱（ 是 或 否）"};
    string a[5] = {"邹豪坤","是","是","是","是"};
    string str;
    for(m = 0;m < 5;)
    {
        cout<<q[m]<<endl;
        cin>>str;
        if(str == a[m])
            m ++;
        else cout<<"那我不告诉你了"<<endl;
    }
    if(play()) cout<<"知道就好"<<endl;
    return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;
int play()
{
    cout<<"�⻹���"<<endl;
    int i,j,num;
    for(i = 2,num = 0;num < 100;i ++)
    {
        for(j = 2;j <= i;j ++)
            if(!(i%j)) break;
        if(i == j)
        {
            num ++;
            cout<<"��"<<setw(3)<<num<<"������Ϊ"<<setw(3)<<i<<",�޺������ɵ��"<<endl;
        }
    }
    return 1;
}
int main()
{
    int m;
    string q[5] = {"�������","���ӿ��ǲ��Ǳ���˧�� �� �� ��","���ӿ��ǲ��Ǳ���ק�� �� �� ��","���ǲ��Ǹ���ͣ� �� �� ��","���ǲ��Ǹ�̸������ �� �� ��"};
    string a[5] = {"�޺���","��","��","��","��"};
    string str;
    for(m = 0;m < 5;)
    {
        cout<<q[m]<<endl;
        cin>>str;
        if(str == a[m])
            m ++;
        else cout<<"���Ҳ���������"<<endl;
    }
    if(play()) cout<<"֪���ͺ�"<<endl;
    return 0;
}

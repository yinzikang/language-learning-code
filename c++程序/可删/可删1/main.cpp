#include <iostream>
using namespace std;
int main()
{	int a[7]={35,68,65,54,35,98,25},i;
	for(i=0;i<=6;i++)
		if(a[i]==98) break;
		if(i>=7) cout<<"没找到98"<<endl;
		else cout<<"找到了98，下标为"<<i<<endl;
    return 0;
}

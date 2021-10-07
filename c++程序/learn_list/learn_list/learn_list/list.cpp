#include "list.h"
#include "iostream"
using namespace std;
int main()
{
	List<int> a;
	int b = 1;
	int c = 2;
	ListNode<int>* p_b = a.insertAsFirst(b);
	a.insertBefore(p_b, c);
	cout << a.size();

}
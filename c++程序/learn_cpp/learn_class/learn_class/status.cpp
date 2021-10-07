#include "iostream"
#include "status.h"
using namespace std;
int main()
{
	value x = {1,1,1};
	double y = 1;
	status aaaaaa(x, x, x, y);
	aaaaaa.show();
}
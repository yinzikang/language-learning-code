#include "matrix.h"
using namespace std;

int main()
{
	matrix<double> a(5);
	matrix<double> b = a.inv(a);
	b.show();
}

#include <iostream>
using namespace std;
#include "Product.h"
#include "Store.h"
#include "Mall.h"
int main()
{
	Mall& mall = Mall::getInstance();
	mall.Menu();
	return 0;
}
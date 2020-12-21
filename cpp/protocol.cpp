#include <iostream>
#include "protocol.h"

using namespace std;

protocol::protocol(void)
{
	printf("%s creat\n",__FUNCTION__);
}
protocol::~protocol(void)
{
	printf("%s delete\n",__FUNCTION__);
}

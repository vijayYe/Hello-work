#include <iostream>
#include "device.h"

using namespace std;

int device::objCnt = 0;
device::device(void)
{
	piDevNum = new int;
	printf("device creat:%d\n",objCnt++);
}
device::~device(void)
{
	delete piDevNum;
	printf("device deleted:%d\n",objCnt--);
}
device::device(uint8_t u8Type):u8DevType(u8Type)
{
	piDevNum = new int;
	printf("device creat by devType params:%d\n",objCnt++);
}
device::device(const device &obj)
{
	piDevNum = new int;
	*piDevNum = *obj.piDevNum;
	u8DevType = obj.u8DevType;
	printf("device creat by obj:%d\n",objCnt++);
}
#if 0
void device::setDevType(uint8_t u8Type)
{
	this->u8DevType = u8Type;
	//cout << "set devType: " << this->u8DevType << "," << u8Type << endl;
	printf("set devType:%d,%d\n",this->u8DevType, u8Type);
}
#endif



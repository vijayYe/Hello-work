
#ifndef __DEVICE_H__
#define __DEVICE_H__

#include "protocol.h"

class device
{
public:
	static int objCnt;
	device();
	~device();
	device(uint8_t u8Type);
	device(const device &obj);  //拷贝构造函数,生成新得对象调用，函数形参也调用。
	inline void setDevType(uint8_t u8Type) {u8DevType = u8Type;}

	device operator+(const device& obj)//运算符+重载
	{
		device dev;
		dev.u8DevType = this->u8DevType + obj.u8DevType;
		return dev;
	}
	friend void printfDevType(const device &obj); //友元函数

protected:
	uint8_t u8DevType;
	std::string strDevDid;
private:
	int *piDevNum;

};



#endif

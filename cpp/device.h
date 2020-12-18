
#ifndef __DEVICE_H__
#define __DEVICE_H__

class device
{
public:
	static int objCnt;
	device();
	~device();
	device(uint8_t u8Type);
	device(const device &obj);  //拷贝构造函数,生成新得对象调用，函数形参也调用。
	inline void setDevType(uint8_t u8Type) {u8DevType = u8Type;}

	friend void printfDevType(const device &obj); //友元函数

protected:
	uint8_t u8DevType;
	std::string strDevDid;
private:
	int *piDevNum;

};



#endif


#ifndef __SWITICH_DEVICE_H__
#define __SWITCH_DEVICE_H__

#include "device.h"
#include "protocol.h"

class switchDev:public device, public protocol
{
public:
	switchDev();
	~switchDev();
protected:
private:
};



#endif

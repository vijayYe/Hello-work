#include <iostream>
#include <vector>
#include "device.h"
using namespace std;

inline double division(int a, int b)
{
	cout << "double division(int a, int b)" << "," << a << "," << b << endl;
	if(b == 0) throw "division by zero condition!";
	return (a/b);
}

double division(double a=6.0, double b=2.0)
{
	cout << "double division(double a, double b)" << "," << a << "," << b << endl;
	if(b == 0) throw "division by zero condition!";
	return (a/b);
}

void printfDevType(const device &obj)
{
	//cout << "friend printf deviceType: " << obj.u8DevType << endl; 
	printf("friend printf device type:%d\n",obj.u8DevType);
}

int main(int argc, char *argv[])
{
	std::cout << "hello word" << std::endl;
#if 0
	int a = 0, b = 0;
	while(b < 100 && std::cin >> b){
		b += a;
	}
	std::cout << "a:" << a << "\nb:" << b << std::endl;
#endif
#if 0
	string strHello = "hello world";
	std::cout << strHello << std::endl;
	string in_str;
	while(std::cin >> in_str && in_str != "quit"){
		std::cout << in_str << ", size" << in_str.size() << std::endl;
	};
	for(auto c : strHello){
		for(auto &c : strHello){
			std::cout << c << std::endl;
			if(c == ' ') c = '>';
		}
	std::cout << strHello << std::endl;
#endif
#if 0
	vector<int> v_i;
	for(int i = 0; i < 50; i++)
		v_i.push_back(i);
	auto v_i_size = v_i.size();
	printf("v_i:empty:%d, size:%lu :", v_i.empty(), v_i_size);
	for(int i = 0; i < v_i.size(); i++)
		printf("%d ",v_i[i]);
	printf("\n");

	string strValue;
	vector<string> v_str;
	while(std::cin>>strValue && "quit" != strValue){
		v_str.push_back(strValue);
	}
	printf("empty:%d, size:%lu :", v_str.empty(), v_str.size());
	//for(vector<string>::iterator iter = v_str.begin(); iter != v_str.end(); ++iter)
	for(auto iter : v_str)
		//printf("%s\n", iter.c_str());	
		std::cout << iter << std::endl;
#endif
#if 0
	try{
		double a = division(10,0);
	}catch(const char* msg){
		//cerr << msg << endl;
		cout << msg << endl;
	}
	int *a;
	try{
		a = new int[32];
	}catch(bad_alloc){
		cout << "new error" <<endl;
	}
#endif
#if 0
	double d1,d2;
	double x1=10.0,y1=2.0;
	int x2=20,y2=4;
	d1 = division(x1,y1);
	cout << d1 << endl;
	d1 = division(x2,y2);
	cout << d1 << endl;
	d1 = division();
	cout << d1 << endl;
	d1 = division(13.4);
	printf("%f\n",d1);
#endif
#if 0
	device dev1;
	dev1.setDevType((uint8_t)10);
	device dev2 = dev1;
	device dev3 = device(20);
	printfDevType(dev1);
	printfDevType(dev2);
	printfDevType(dev3);
#endif
#if 1

#endif
	return 0;
}

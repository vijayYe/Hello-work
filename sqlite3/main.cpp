#include <iostream>
#include <vector>
#include <thread>
#include <unistd.h>

#include "dev_sqlite.h"

using namespace std;

string strTemp;
void threadTask( void )
{
	int t = 0;
	string strTask = strTemp;
	while(1){
		printf("%s, %d\n",strTask.c_str(), t++);
		usleep(1000*1000);
	}
}

int main(int argc, char *argv[])
{
	cout << "hello sqlite" << endl;
	devSqlite devSql;

	strTemp = "s1:";
	thread th1(threadTask);
	 th1.detach();
	usleep(5000*1000);
	strTemp = "s2:";
	thread th2(threadTask);
	 th2.detach();
	while(1){
		usleep(10000*1000);
	}
	return 0; 
}




#include <iostream>
#include <vector>
#include <thread>
#include <unistd.h>

#include "dev_sqlite.h"

using namespace std;

void threadTask( devSqlite *obj )
{
	int t = 0;
	while(1){
		obj->sqliteCommitLoop();
		usleep(5000*1000);
	}
}

int main(int argc, char *argv[])
{
	cout << "hello sqlite" << endl;
	devSqlite devSql = devSqlite("my.db");
	//devSqlite devSq2;
	
	thread th1(threadTask, &devSql);
	th1.detach();

	//devSq2.sqliteOpen("my2.db");
	//thread th2(threadTask, &devSq2);
	//th2.detach();

	int cnt = 0;
	while(1){
		cnt++;
		if(cnt > 5){
			devSql.sqliteInsert();
			cnt = 0;
		}
		usleep(1000*1000);
	}
	return 0; 
}




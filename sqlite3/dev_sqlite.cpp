#include <iostream>
#include "dev_sqlite.h"
#include "sqlite3.h"


#define DEV_SQL_ADDR		"./device.db"

class devSqliteImpl{
	public:
		sqlite3 *ppdb;
		pthread_t sThreadId;
};



devSqlite::devSqlite( void ) : pImpl(new devSqliteImpl)
{
    int ret = sqlite3_open("my.db", &pImpl->ppdb);
    if(ret != SQLITE_OK){
        printf("open fail");
    }
}

devSqlite::~devSqlite( void )
{	
	sqlite3_close(pImpl->ppdb);
	delete pImpl;
}



#include <iostream>
#include "dev_sqlite.h"
#include "sqlite3.h"
#include <sys/time.h>
#include <string.h>

using namespace std;

#define DEV_SQL_ADDR		"./device.db"
#define SQL_CMD_LOG(s)    	printf("SQLITE CMD: %s\n",s);
#define SQL_COMMIT_TIMEOUT_S 		10
#define DEV_CREAT_TABLE_SQI_CMD  	"create table if not exists dev_list ("\
									"did char(32) primary key,"\
									"manu_name varchar(8))"


struct sqliteTableType{
	const char *dbName;
	const char *sqlCmd;
};


const struct sqliteTableType sqlTableType[] = {
	{"device.db", 	DEV_CREAT_TABLE_SQI_CMD},
	{"my.db", 	DEV_CREAT_TABLE_SQI_CMD},
};

uint32_t utltGetCurrentUTCs( void )
{
	struct timeval tv;  
 	gettimeofday(&tv, NULL);
 	uint32_t u32Time = (uint32_t)(tv.tv_sec);
 	return u32Time;
}



class devSqliteImpl{
public:
	sqlite3 *ppdb = NULL;
	uint32_t time;
	sqliteStatus sqlCreatTable(const char *tableAddr)
	{
		int len = strlen(tableAddr);
		const char *tableName = tableAddr;
		for(int i = len-1; i >= 0; i--){
			if(tableAddr[i] == '/'){
				tableName = &tableAddr[i+1];
				break;
			}
		}
		for(int i = 0; i < sizeof(sqlTableType)/sizeof(struct sqliteTableType); i++){
			if(strncmp(sqlTableType[i].dbName, tableName, strlen(sqlTableType[i].dbName)) == 0) {			
				SQL_CMD_LOG(sqlTableType[i].sqlCmd);
				char *errmsg = NULL;
				int ret = sqlite3_exec(ppdb, sqlTableType[i].sqlCmd, NULL, NULL, &errmsg);
				if(ret != SQLITE_OK){
					printf("creat table:%s\n",errmsg);
					sqlite3_free(errmsg);
					return E_SQLITE_STATUS_ERROR_CREAT_TABLE;
				}
				return E_SQLITE_STATUS_SUCCESS;
			}
		}
		return E_SQLITE_STATUS_ERROR_CREAT_TABLE;
	}
};


devSqlite::devSqlite(   void ) : pImpl(new devSqliteImpl)
{
}

devSqlite::devSqlite( const char *pcAddr ) : pImpl(new devSqliteImpl)
{
    int ret = sqlite3_open(pcAddr, &pImpl->ppdb);
    if(ret != SQLITE_OK){
        printf("open sql db fail");
    }else{
		printf("open sql db:%s\n",pcAddr);
		pImpl->sqlCreatTable(pcAddr);
		pImpl->time = utltGetCurrentUTCs();
	}
}

devSqlite::~devSqlite( void )
{	
	sqlite3_close(pImpl->ppdb);
	delete pImpl;
}

sqliteStatus devSqlite::sqliteOpen(const char *pcAddr)
{
	if(NULL != pImpl->ppdb) return E_SQLITE_STATUS_HAD_DB;
	int ret = sqlite3_open(pcAddr, &pImpl->ppdb);
    if(ret != SQLITE_OK){
        printf("open sql db fail");
    }else{
		printf("open sql db:%s\n",pcAddr);
		pImpl->sqlCreatTable(pcAddr);
		pImpl->time = utltGetCurrentUTCs();
    }
    return E_SQLITE_STATUS_SUCCESS;
}

void devSqlite::sqliteInsert( void )
{
	sqlite3_exec(pImpl->ppdb, "begin",NULL,NULL,NULL);
	const char* insert_sql = "insert into dev_list values('zb.001531.01','JM');";
	SQL_CMD_LOG(insert_sql);
	char *errmsg = NULL;
	int ret = sqlite3_exec(pImpl->ppdb, insert_sql, NULL, NULL, &errmsg);
    if(ret != SQLITE_OK){
        printf("%s\n",errmsg);
    }
    sqlite3_free(errmsg);
}


void devSqlite::sqliteCommitLoop( void )
{	
	uint32_t now = utltGetCurrentUTCs();
	uint32_t diffTime = now - pImpl->time;
	printf("time:%u\n",diffTime);
	if(0 != pImpl->time &&  diffTime > SQL_COMMIT_TIMEOUT_S){
		pImpl->time = now;
		const char *addr  = sqlite3_db_filename(pImpl->ppdb, NULL);
		cout << "db addr:" << addr << endl;

		sqlite3_exec(pImpl->ppdb, "commit",NULL,NULL,NULL);
	}
}




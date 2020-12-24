#ifndef __DEV_SQLITE_H__
#define __DEV_SQLITE_H__

typedef enum{

	E_SQLITE_STATUS_SUCCESS,
	E_SQLITE_STATUS_NOT_OPEN_DB,
	E_SQLITE_STATUS_HAD_DB,
	E_SQLITE_STATUS_ERROR_CREAT_TABLE,
	
}sqliteStatus;

class devSqliteImpl;
class devSqlite
{
private:
	devSqliteImpl *pImpl;

public:
	devSqlite();
	~devSqlite();
	devSqlite(const char *pcAddr);
	sqliteStatus sqliteOpen(const char *pcAddr);
	void sqliteInsert( void );
	void sqliteCommitLoop( void );
};


#endif


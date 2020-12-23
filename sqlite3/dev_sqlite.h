#ifndef __DEV_SQLITE_H__
#define __DEV_SQLITE_H__


class devSqliteImpl;

class devSqlite
{
public:
	devSqlite();
	~devSqlite();
private:
	devSqliteImpl *pImpl;
};


#endif


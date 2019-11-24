#include<stdio.h>
#include<sqlite3.h>

int main(int argc,char * argv[]){
	const char *sql_create_table = "select * from test";
	
	char *errno = NULL;
	int ret = 0;
	char **pazResult;
	int pnRow,pnColumn;

	sqlite3 *db = 0;
	ret = sqlite3_open("./sqlite3-demo.db",&db);
	if(ret != SQLITE_OK){
		printf("error: %s\n",sqlite3_errmsg(db));
		return 1;
	}
	printf("Open database\n");

	ret = sqlite3_exec(db,sql_create_table,NULL,NULL,&errno);
	if(ret != SQLITE_OK){
		printf("error: %s\n",sqlite3_errmsg(db));
		return 1;
	}

	sqlite3_get_table(db,sql_create_table,&pazResult,&pnRow,&pnColumn,&errno);
	printf("row is: %d\tcolumn is: %d\n",pnRow,pnColumn);
	printf("syllable name:\t\tsyllable value:\n");
	printf("%s\t\t%13s\n======================================\n",pazResult[2],pazResult[3]); 
	sqlite3_free(errno);
	sqlite3_close(db);
	printf("\nclose the database\n");
	return (0);
}

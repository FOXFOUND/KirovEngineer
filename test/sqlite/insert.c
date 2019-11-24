#include<sqlite3.h>
#include<glib.h>

int main(int argc,char * argv[]){
	sqlite3 *db;
	gchar *sql;
	gchar *sql_error;
	
	if(sqlite3_open("sqlite3-demo.db",&db)){g_error("sqlite3_demo.db opened failed");return(-1);}
	else{
		g_message("sqlite3_demo.db opened");
	}
	sql = g_strconcat("insert into ","test values ","(","null,","'zhangzetian'",");",NULL);
	g_print("sql is: %s\n",sql);
	if(sqlite3_exec(db,sql,NULL,NULL,&sql_error) != SQLITE_OK){
		g_error("sqlite insert failed: %s\n",sql_error);
	}else{
		g_message("insert succeed\n");
	}
	sqlite3_close(db);
	return (0);
}

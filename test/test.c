#include<glib.h>

int main(int argc,char * argv[]){
	gchar *value = "zhang";
	value = g_strconcat(value," ze tian",NULL);

	g_printf("%s\n",value);
	return (0);
}

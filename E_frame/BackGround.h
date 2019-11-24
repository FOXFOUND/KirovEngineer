#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

/*
 * Date:22:22:07 CST 2016
 * function:run in background 
 */

GtkStatusIcon *SYSTEMTRAYSHOW(){
	GtkStatusIcon *system_tray_pointer;
	system_tray_pointer = gtk_status_icon_new();
	return system_tray_pointer;
}


#endif

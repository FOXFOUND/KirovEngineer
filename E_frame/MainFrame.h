/*
 *	this file is login.h
 */

#ifndef _MAINFRAME_H_
#define _MAINFRAME_H_

void MAINFRAME(){
	GtkWidget *window;
	GtkWidget *vbox;
	GtkWidget *frame1,*frame2;
	GtkWidget *label;
	GtkWidget *hpaned;	
	GtkWidget *image;
	//GtkStatusIcon *systemtray;

	//systemtray = SYSTEMTRAYSHOW();
	window = WindowStatement(window,440,700,"title");
	frame1 = AddFrame("frameleft",int_operator,(gpointer)"left");
	frame2 = AddFrame("frameright",int_operator,(gpointer)"right");
	hpaned = AddhorizontalPane(hpaned,frame1,frame2);
	vbox = AddVerticalBox(frame1,10,10);
	LocalImageLoad(vbox,"E_img/test.jpg");
	AddLabel(vbox,"label",FALSE,FALSE,1);
	AddLabel(vbox,"label",FALSE,FALSE,1);
		
	E_CONTAINER_ADD(frame1,vbox);
	E_CONTAINER_ADD(window,hpaned);

	WindowShow(window);
	GetEnv("engineer_gtkpath");
}
#endif

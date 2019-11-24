/*
 *	this file is PublicTools.c file
 *	It can save our time
 */

#ifndef _PUBLICTOOLS_H_
#define _PUBLICTOOLS_H_

GtkWidget* int_operator(gpointer message) {g_print("this is int_operator()\nthe pointer value is: %s\n",(gchar *)message);}

void ConsoleMessageShow(char *value){
	g_message("value is: %s\n",value);
}

GtkWidget* WindowStatement(GtkWidget *window,int height,int width,const gchar *title){
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window,width,height);
	gtk_window_set_title((GtkWindow *)window,(const gchar *)title);
	g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),
				NULL);
	return window;
}

void WindowShow(GtkWidget *window){
	gtk_widget_show_all(window);
	gtk_main();
}

GtkWidget *AddLabel(GtkWidget *parentbox,const gchar* label_value,gboolean E_expand,gboolean E_fill,guint E_padding){
	//this function's parentbox must be GtkBox ,and GtkBox is used mainly in ENGINEER
	gtk_box_pack_start(GTK_BOX(parentbox),gtk_label_new(label_value),E_expand,E_fill,E_padding);
}

GtkWidget *AddFrame(const gchar *frametitle,GtkWidget* E_extension(),gpointer message){
	GtkWidget *frame;frame = gtk_frame_new(frametitle);
	E_extension(message);
	return frame;	
}

GtkWidget *AddVerticalBox(GtkWidget *parentwidget,gint value_spacing,guint parent_with_childbox_width){
	GtkWidget *vbox;
	vbox = gtk_vbox_new(FALSE,value_spacing);
	gtk_container_set_border_width(GTK_CONTAINER(vbox),parent_with_childbox_width);	
	return vbox;	
}

void E_CONTAINER_ADD(GtkWidget *parent_container,GtkWidget *child_container){
	gtk_container_add(GTK_CONTAINER(parent_container),child_container);
}

GtkWidget *AddVerticalPane(GtkWidget *parent_vpaned,GtkWidget *child_frame_up,GtkWidget *child_frame_down){
	parent_vpaned = gtk_vpaned_new();
	gtk_paned_pack1(GTK_PANED(parent_vpaned),child_frame_up,TRUE,FALSE);
	gtk_paned_pack2(GTK_PANED(parent_vpaned),child_frame_down,TRUE,FALSE);
	return parent_vpaned;	
}

GtkWidget *AddhorizontalPane(GtkWidget *parent_hpaned,GtkWidget *child_frame_left,GtkWidget *child_frame_right){
	parent_hpaned = gtk_hpaned_new();
	gtk_paned_pack1(GTK_PANED(parent_hpaned),child_frame_left,TRUE,FALSE);
	gtk_paned_pack2(GTK_PANED(parent_hpaned),child_frame_right,TRUE,FALSE);
	return parent_hpaned;	
}

void LocalImageLoad(GtkWidget *parentbox,const gchar *img_src){
	GtkWidget *image;
	image = gtk_image_new_from_file((char *)img_src);
	gtk_box_pack_start(GTK_BOX(parentbox),image,FALSE,FALSE,1);
}

void GetEnv(const gchar *pathvar){
	g_print("the path is: %s\n",g_getenv(pathvar));
}

#endif

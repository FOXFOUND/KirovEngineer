#include "ENGINEER.h"

#include"E_frame/PublicTools.h"
#include"E_frame/BackGround.h"

void MAINFRAME(){
	GtkWidget *window;
	GtkWidget *vbox;
	GtkWidget *frame1,*frame2;
	GtkWidget *label;
	GtkWidget *hpaned;	
	GtkWidget *image;
	// GtkStatusIcon *systemtray;

	// systemtray = SYSTEMTRAYSHOW();
	window = WindowStatement(window,440,700,"title");
	frame1 = AddFrame("frameleft",int_operator,(gpointer)"left");
	frame2 = AddFrame("frameright",int_operator,(gpointer)"right");
	hpaned = AddhorizontalPane(hpaned,frame1,frame2);
	vbox = AddVerticalBox(frame1,10,10);
	LocalImageLoad(vbox,"E_img/IBM.png");
	AddLabel(vbox,"label",FALSE,FALSE,1);
	AddLabel(vbox,"label",FALSE,FALSE,1);
		
	E_CONTAINER_ADD(frame1,vbox);
	E_CONTAINER_ADD(window,hpaned);

	WindowShow(window);
	GetEnv("engineer_gtkpath");
}

/* This function rotates the position of the tabs */
static void rotate_book( GtkButton   *button,
                         GtkNotebook *notebook )
{
    gtk_notebook_set_tab_pos (notebook, (notebook->tab_pos + 1) % 4);
}

/* Add/Remove the page tabs and the borders */
static void tabsborder_book( GtkButton   *button,
                             GtkNotebook *notebook )
{
    gint tval = FALSE;
    gint bval = FALSE;
    if (notebook->show_tabs == 0)
	    tval = TRUE; 
    if (notebook->show_border == 0)
	    bval = TRUE;
    
    gtk_notebook_set_show_tabs (notebook, tval);
    gtk_notebook_set_show_border (notebook, bval);
}

/* Remove a page from the notebook */
static void remove_book( GtkButton   *button,
                         GtkNotebook *notebook )
{
    gint page;
    
    page = gtk_notebook_get_current_page (notebook);
    gtk_notebook_remove_page (notebook, page);
    /* Need to refresh the widget -- 
     This forces the widget to redraw itself. */
    gtk_widget_queue_draw (GTK_WIDGET (notebook));
}

static gboolean delete( GtkWidget *widget,
                        GtkWidget *event,
                        gpointer   data )
{
    gtk_main_quit ();
    return FALSE;
}

void NOTEBOOK(){
    GtkWidget *window = WindowStatement(window,440,700,"NoteBook");

    GtkWidget *frame;
    GtkWidget *label;
    
    char bufferf[32];
    char bufferl[32];
    int i;

    GtkWidget *table = gtk_table_new (3, 6, FALSE);
    gtk_container_add (GTK_CONTAINER (window), table);

    GtkWidget *notebook = gtk_notebook_new ();
    gtk_notebook_set_tab_pos (GTK_NOTEBOOK (notebook), GTK_POS_LEFT);
    gtk_table_attach_defaults (GTK_TABLE (table), notebook, 0, 6, 0, 1);
    gtk_widget_show (notebook);

    /* Let's append a bunch of pages to the notebook */
    for (i = 0; i < 5; i++) {
        sprintf(bufferf, "Append Frame %d", i + 1);
	    sprintf(bufferl, "Page %d", i + 1);
	
	    frame = gtk_frame_new (bufferf);
	    gtk_container_set_border_width (GTK_CONTAINER (frame), 10);
	    gtk_widget_set_size_request (frame, 100, 75);
	    gtk_widget_show (frame);
	
	    label = gtk_label_new (bufferf);
	    gtk_container_add (GTK_CONTAINER (frame), label);
	    gtk_widget_show (label);
	
	    label = gtk_label_new (bufferl);
	    gtk_notebook_append_page (GTK_NOTEBOOK (notebook), frame, label);
    }
    gtk_notebook_set_current_page (GTK_NOTEBOOK (notebook), 1);

    gtk_widget_show (table);
	WindowShow(window);
}

// void NOTEBOOK(){
//     GtkWidget *window;
	
// 	window = WindowStatement(window,440,700,"NoteBook");
//     GtkWidget *button;
//     GtkWidget *table;
//     GtkWidget *notebook;
//     GtkWidget *frame;
//     GtkWidget *label;
//     GtkWidget *checkbutton;
//     int i;
//     char bufferf[32];
//     char bufferl[32];

//     table = gtk_table_new (3, 6, FALSE);
//     gtk_container_add (GTK_CONTAINER (window), table);
    
//     /* Create a new notebook, place the position of the tabs */
//     notebook = gtk_notebook_new ();
    // gtk_notebook_set_tab_pos (GTK_NOTEBOOK (notebook), GTK_POS_LEFT);
//     gtk_table_attach_defaults (GTK_TABLE (table), notebook, 0, 6, 0, 1);
//     gtk_widget_show (notebook);
    
//     /* Let's append a bunch of pages to the notebook */
//     for (i = 0; i < 5; i++) {
// 	sprintf(bufferf, "Append Frame %d", i + 1);
// 	sprintf(bufferl, "Page %d", i + 1);
	
// 	frame = gtk_frame_new (bufferf);
// 	gtk_container_set_border_width (GTK_CONTAINER (frame), 10);
// 	gtk_widget_set_size_request (frame, 100, 75);
// 	gtk_widget_show (frame);
	
// 	label = gtk_label_new (bufferf);
// 	gtk_container_add (GTK_CONTAINER (frame), label);
// 	gtk_widget_show (label);
	
// 	label = gtk_label_new (bufferl);
// 	gtk_notebook_append_page (GTK_NOTEBOOK (notebook), frame, label);
//     }
      
//     /* Now let's add a page to a specific spot */
//     checkbutton = gtk_check_button_new_with_label ("Check me please!");
//     gtk_widget_set_size_request (checkbutton, 100, 75);
//     gtk_widget_show (checkbutton);
   
//     label = gtk_label_new ("Add page");
//     gtk_notebook_insert_page (GTK_NOTEBOOK (notebook), checkbutton, label, 2);
    
//     /* Now finally let's prepend pages to the notebook */
//     for (i = 0; i < 5; i++) {
// 	sprintf (bufferf, "Prepend Frame %d", i + 1);
// 	sprintf (bufferl, "PPage %d", i + 1);
	
// 	frame = gtk_frame_new (bufferf);
// 	gtk_container_set_border_width (GTK_CONTAINER (frame), 10);
// 	gtk_widget_set_size_request (frame, 100, 75);
// 	gtk_widget_show (frame);
	
// 	label = gtk_label_new (bufferf);
// 	gtk_container_add (GTK_CONTAINER (frame), label);
// 	gtk_widget_show (label);
	
// 	label = gtk_label_new (bufferl);
// 	gtk_notebook_prepend_page (GTK_NOTEBOOK (notebook), frame, label);
//     }
    
//     /* Set what page to start at (page 4) */
//     gtk_notebook_set_current_page (GTK_NOTEBOOK (notebook), 3);

//     /* Create a bunch of buttons */
//     button = gtk_button_new_with_label ("close");
//     g_signal_connect_swapped (button, "clicked",
// 			      G_CALLBACK (delete), NULL);
//     gtk_table_attach_defaults (GTK_TABLE (table), button, 0, 1, 1, 2);
//     gtk_widget_show (button);
    
//     button = gtk_button_new_with_label ("next page");
//     g_signal_connect_swapped (button, "clicked",
// 			      G_CALLBACK (gtk_notebook_next_page),
// 			      notebook);
//     gtk_table_attach_defaults (GTK_TABLE (table), button, 1, 2, 1, 2);
//     gtk_widget_show (button);
    
//     button = gtk_button_new_with_label ("prev page");
//     g_signal_connect_swapped (button, "clicked",
// 			      G_CALLBACK (gtk_notebook_prev_page),
// 			      notebook);
//     gtk_table_attach_defaults (GTK_TABLE (table), button, 2, 3, 1, 2);
//     gtk_widget_show (button);
    
//     button = gtk_button_new_with_label ("tab position");
//     g_signal_connect (button, "clicked",
//                       G_CALLBACK (rotate_book),
// 	              notebook);
//     gtk_table_attach_defaults (GTK_TABLE (table), button, 3, 4, 1, 2);
//     gtk_widget_show (button);
    
//     button = gtk_button_new_with_label ("tabs/border on/off");
//     g_signal_connect (button, "clicked",
//                       G_CALLBACK (tabsborder_book),
//                       notebook);
//     gtk_table_attach_defaults (GTK_TABLE (table), button, 4, 5, 1, 2);
//     gtk_widget_show (button);
    
//     button = gtk_button_new_with_label ("remove page");
//     g_signal_connect (button, "clicked",
//                       G_CALLBACK (remove_book),
//                       notebook);
//     gtk_table_attach_defaults (GTK_TABLE (table), button, 5, 6, 1, 2);
//     gtk_widget_show (button);
    
//     gtk_widget_show (table);

// 	WindowShow(window);
// 	GetEnv("engineer_gtkpath");
// }
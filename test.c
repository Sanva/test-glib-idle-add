#include <gtk/gtk.h>

gboolean idle(gpointer data)
{
	g_print ("Idle!\n");
	
	return 0;
}

static void callback( GtkWidget *widget,
                      gpointer   data )
{   
    g_idle_add (idle, NULL);
}

int main(int argc, char *argv[]) {
	GtkWidget *window;
	GtkWidget *button;
	
	gtk_init(&argc, &argv);
	
	button = gtk_button_new_with_label("Test");
	g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (callback), NULL);
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "GTK+ Test Application");
	gtk_window_resize(GTK_WINDOW(window), 400, 250);
	
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	
	gtk_container_add(GTK_CONTAINER(window), button);
	gtk_widget_show_all(window);
	
	gtk_main();
	
	return 0;
}

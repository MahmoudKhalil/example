#include "example_app.h"
#include "example_app_window.h"

struct _ExampleAppWindow
{
    GtkApplicationWindow parent;
    
    GtkStack *stack;
};

G_DEFINE_TYPE (ExampleAppWindow, example_app_window, GTK_TYPE_APPLICATION_WINDOW)

static void
example_app_window_init (ExampleAppWindow *instance)
{
    gtk_widget_init_template (GTK_WIDGET (instance));
}

static void
example_app_window_class_init (ExampleAppWindowClass *klass)
{
    gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (klass), "/org/gtk/example_app/window.ui");
    
    gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS (klass), ExampleAppWindow, stack);
}

ExampleAppWindow *
example_app_window_new (ExampleApp *app)
{
    return g_object_new (EXAMPLE_TYPE_APP_WINDOW, "application", app, NULL);
}

void
example_app_window_open (ExampleAppWindow *self, GFile *file)
{
    gchar *basename;
    GtkWidget *scrolled, *view;
    gchar *contents;
    gsize length;
    
    basename = g_file_get_basename (file);
    g_print ("Basename is %s\n", basename);
    
    scrolled = gtk_scrolled_window_new (NULL, NULL);
    gtk_widget_show (scrolled);
    gtk_widget_set_hexpand (scrolled, TRUE);
    gtk_widget_set_vexpand (scrolled, TRUE);
    view = gtk_text_view_new ();
    gtk_text_view_set_editable (GTK_TEXT_VIEW (view), FALSE);
    gtk_text_view_set_cursor_visible (GTK_TEXT_VIEW (view), FALSE);
    gtk_widget_show (view);
    
    gtk_container_add (GTK_CONTAINER (scrolled), view);
    gtk_stack_add_titled (self->stack, scrolled, basename, basename);
    
    if (g_file_load_contents (file, NULL, &contents, &length, NULL, NULL))
    {
        GtkTextBuffer *buffer;
        
        buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));
        gtk_text_buffer_set_text (buffer, contents, length);
        
        g_free (contents);
    }
    
    g_free (basename);
}

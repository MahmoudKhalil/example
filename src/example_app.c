#include "example_app.h"
#include "example_app_window.h"

struct _ExampleApp
{
    GtkApplication parent;
};

G_DEFINE_TYPE (ExampleApp, example_app, GTK_TYPE_APPLICATION)

static void
example_app_activate (GApplication *app)
{
    ExampleAppWindow *win;
    
    win = example_app_window_new (EXAMPLE_APP (app));
    gtk_window_present (GTK_WINDOW (win));
}

static void
example_app_open (GApplication *app, GFile **files, gint n_files, const gchar *hine)
{
    GList *windows;
    ExampleAppWindow *win;
    
    windows = gtk_application_get_windows (GTK_APPLICATION (app));
    
    if (windows)
        win = EXAMPLE_APP_WINDOW (windows->data);
    else
        win = example_app_window_new (EXAMPLE_APP (app));

    for (int i = 0; i < n_files; i++)
        example_app_window_open (win, files[i]);

    gtk_window_present (GTK_WINDOW (win));
}

static void
example_app_init (ExampleApp *instance)
{
}

static void
example_app_class_init (ExampleAppClass *klass)
{
    G_APPLICATION_CLASS (klass)->activate = example_app_activate;
    G_APPLICATION_CLASS (klass)->open = example_app_open;
}

ExampleApp *
example_app_new (void)
{
    return g_object_new (EXAMPLE_TYPE_APP, "application-id", "org.gtk.example_app", "flags", G_APPLICATION_HANDLES_OPEN, NULL);
}


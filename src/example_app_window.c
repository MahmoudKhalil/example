#include "example_app.h"
#include "example_app_window.h"

struct _ExampleAppWindow
{
    GtkApplicationWindow parent;
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
}

ExampleAppWindow *
example_app_window_new (ExampleApp *app)
{
    return g_object_new (EXAMPLE_TYPE_APP_WINDOW, "application", app, NULL);
}

void
example_app_window_open (ExampleAppWindow *self, GFile *file)
{
}

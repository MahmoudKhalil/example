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
}

static void
example_app_window_class_init (ExampleAppWindowClass *klass)
{
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

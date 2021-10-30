#include <gtk/gtk.h>
#include <math.h>
#include "./view-manager.h"
#include "./action-manager.h"
#include "./expo-manager.h"
#include "../data/models/vowel-list.h"

gchar *colors[] = {
    "AliceBlue",
    "blueviolet",
    "aquamarine1",
    "CadetBlue",
    "chartreuse",
    "chocolate",
    "yellow3",
    "CornflowerBlue",
    "cornsilk",
    "crimson",
    "violetred4",
    "cyan4",
    "DarkBlue",
    "DarkCyan",
    "palevioletred2",
    "DarkGoldenrod1",
    "DarkGray",
    "seagreen",
    "DarkGrey",
    "orange2",
    "DarkMagenta",
    "DarkOliveGreen",
    "DarkOliveGreen1",
    "DarkOrange1",
    "DarkOrchid1",
    "midnightblue",
    "DarkOrchid3",
    "DarkOrchid4",
    "DarkRed",
    "DarkSalmon",
    "DarkSeaGreen",
    "DarkSlateGray2",
    "DarkTurquoise",
    "DarkViolet",
    "DeepPink",
    "DeepSkyBlue",
    "DimGray",
    "DimGrey",
    "DodgerBlue",
    "firebrick",
    "FloralWhite",
    "ForestGreen",
    "fuchsia",
    "gainsboro",
    "GhostWhite"};

gchar *algorithms[] = {"FCFS", "Priority", "Round Robin", "Lottery", "STRN"};

int generate_random(int l, int r)
{
    return (rand() % (r - l + 1) + l);
}

static gboolean handler_bar_1_update(GtkProgressBar *widg)
{
    const float progress = 0;
    static int actual = 0;
    static int max = 0;
    static int flag = 0;
    if (GTK_IS_PROGRESS_BAR(widg) && get_scheduler_count() == FCFS)
    {
        int tmp = get_count();
        if (tmp == 0 && flag == 0)
        {
            flag = 1;
        }
        else if (actual <= tmp)
        {
            float delta = get_progress_1();
            flag = 1;
            char *text;
            text = g_strdup_printf("%i/%i", actual, tmp);
            gtk_progress_bar_set_pulse_step(widg, delta);
            gtk_progress_bar_set_text(widg, text);
            gtk_progress_bar_pulse(widg);
            g_free(text);
            actual++;
        }
    }
    return TRUE;
}

static gboolean handler_bar_2_update(GtkProgressBar *widg)
{
    const float progress = 0;
    static int actual = 0;
    static int max = 0;
    static int flag = 0;
    if (GTK_IS_PROGRESS_BAR(widg) && get_scheduler_count() == PRIORITY)
    {
        int tmp = get_count();
        if (tmp == 0 && flag == 0)
        {
            flag = 1;
        }
        else if (actual <= tmp)
        {
            float delta = get_progress_2();
            flag = 1;
            char *text;
            text = g_strdup_printf("%i/%i", actual, tmp);
            gtk_progress_bar_set_pulse_step(widg, delta);
            gtk_progress_bar_set_text(widg, text);
            gtk_progress_bar_pulse(widg);
            g_free(text);
            actual++;
        }
    }
    return TRUE;
}

static gboolean handler_bar_3_update(GtkProgressBar *widg)
{
    const float progress = 0;
    static int actual = 0;
    static int max = 0;
    static int flag = 0;
    if (GTK_IS_PROGRESS_BAR(widg) && get_scheduler_count() == RR)
    {
        int tmp = get_count();
        if (tmp == 0 && flag == 0)
        {
            flag = 1;
        }
        else if (actual <= tmp)
        {
            float delta = get_progress_3();
            flag = 1;
            char *text;
            text = g_strdup_printf("%i/%i", actual, tmp);
            gtk_progress_bar_set_pulse_step(widg, delta);
            gtk_progress_bar_set_text(widg, text);
            gtk_progress_bar_pulse(widg);
            g_free(text);
            actual++;
        }
    }
    return TRUE;
}

static gboolean handler_bar_4_update(GtkProgressBar *widg)
{
    const float progress = 0;
    static int actual = 0;
    static int max = 0;
    static int flag = 0;
    if (GTK_IS_PROGRESS_BAR(widg) && get_scheduler_count() == LOTTERY)
    {
        int tmp = get_count();
        if (tmp == 0 && flag == 0)
        {
            flag = 1;
        }
        else if (actual <= tmp)
        {
            float delta = get_progress_4();
            flag = 1;
            char *text;
            text = g_strdup_printf("%i/%i", actual, tmp);
            gtk_progress_bar_set_pulse_step(widg, delta);
            gtk_progress_bar_set_text(widg, text);
            gtk_progress_bar_pulse(widg);
            g_free(text);
            actual++;
        }
    }
    return TRUE;
}

static gboolean handler_bar_5_update(GtkProgressBar *widg)
{
    const float progress = 0;
    static int actual = 0;
    static int max = 0;
    static int flag = 0;
    if (GTK_IS_PROGRESS_BAR(widg) && get_scheduler_count() == SRTN)
    {
        int tmp = get_count();
        if (tmp == 0 && flag == 0)
        {
            flag = 1;
        }
        else if (actual <= tmp)
        {
            float delta = get_progress_5();
            flag = 1;
            char *text;
            text = g_strdup_printf("%i/%i", actual, tmp);
            gtk_progress_bar_set_pulse_step(widg, delta);
            gtk_progress_bar_set_text(widg, text);
            gtk_progress_bar_pulse(widg);
            g_free(text);
            actual++;
        }
    }
    return TRUE;
}

static gboolean refresher_queue_flow(GtkFlowBox *flowbox)
{
    static int actual = 0;

    int tmp = get_count();
    int dif = tmp - actual;
    if (dif > 0)
    {
        for (int j = 0; j < dif; j++)
        {

            int rad = generate_random(0, 42);
            gtk_flow_box_insert(flowbox, color_swatch_new(colors[rad]), -1);

            actual++;
        }
    }
    return TRUE;
}

static gboolean refresher_time_flow(GtkFlowBox *flowbox)
{
    static int count_now = 0;
    static schedule_e sched_now = 0;
    int sched_tmp = get_scheduler_count();
    g_print("NOW %i\n", sched_now);
    g_print("TMP %i\n", sched_tmp);
    if (sched_tmp != sched_now)
    {
        int count_tmp = get_count();
        const int ghost = 43;
        gtk_flow_box_set_max_children_per_line(flowbox, count_tmp);
        for (int j = 0; j < 100; j++)
        {
            int rad = 43;
            gtk_flow_box_insert(flowbox, color_swatch_new(colors[ghost]), -1);
        }
        sched_now++;
    }
}

gboolean refresher_label_algo(gpointer ptr)
{
    int s_count = (int)get_scheduler_count();
    GtkLabel *label_algo = (GtkLabel *)ptr;
    g_return_val_if_fail(GTK_IS_LABEL(label_algo), FALSE);
    gtk_label_set_label(ptr, algorithms[s_count]);
    if (s_count > 5)
    {
        s_count = 0;
    }
    return TRUE;
}

gboolean refresher_label_count(gpointer ptr)
{
    GtkLabel *label_count = (GtkLabel *)ptr;
    g_return_val_if_fail(GTK_IS_LABEL(label_count), FALSE);
    char *text = g_strdup_printf("%i", get_count());
    gtk_label_set_label(ptr, text);
    g_free(text);
    return TRUE;
}

static void handler_btn_next()
{
    action_next_queue();
}

static void handler_btn_clear()
{
    action_clear_queue();
}

void count(gpointer pointer)
{
    GtkFlowBox *fbx_queue = (GtkFlowBox *)pointer;
    if (GTK_IS_FLOW_BOX(fbx_queue))
    {
        g_print("Test");
        test_color(pointer);
    }
}

void start_gui()
{
    widgets widg;
    GtkBuilder *builder;
    GObject *window;
    GError *error = NULL;

    builder = gtk_builder_new_from_file(BUILD_PATH);

    // Instance Widgets
    widg.bar_prog_1 = GTK_PROGRESS_BAR(gtk_builder_get_object(builder, BAR_PROG_1));
    widg.bar_prog_2 = GTK_PROGRESS_BAR(gtk_builder_get_object(builder, BAR_PROG_2));
    widg.bar_prog_3 = GTK_PROGRESS_BAR(gtk_builder_get_object(builder, BAR_PROG_3));
    widg.bar_prog_4 = GTK_PROGRESS_BAR(gtk_builder_get_object(builder, BAR_PROG_4));
    widg.bar_prog_5 = GTK_PROGRESS_BAR(gtk_builder_get_object(builder, BAR_PROG_5));
    widg.btn_runn = GTK_BUTTON(gtk_builder_get_object(builder, BTN_RUNN));
    widg.btn_clear = GTK_BUTTON(gtk_builder_get_object(builder, BTN_CLEAR));
    widg.lbl_algo_key = GTK_LABEL(gtk_builder_get_object(builder, LBL_ALGO));
    widg.lbl_count_key = GTK_LABEL(gtk_builder_get_object(builder, LBL_COUNT));
    widg.fbx_queue = GTK_FLOW_BOX(gtk_builder_get_object(builder, FBX_QUEUE));
    widg.fbx_time = GTK_FLOW_BOX(gtk_builder_get_object(builder, FBX_TIME));

    // Connect Signals
    g_signal_connect(widg.btn_runn, "clicked", G_CALLBACK(handler_btn_next), NULL);
    g_signal_connect(widg.btn_clear, "clicked", G_CALLBACK(handler_btn_clear), NULL);

    // Start Refreshers
    gdk_threads_add_timeout(SLEEP_BAR, G_SOURCE_FUNC(handler_bar_1_update), (gpointer)widg.bar_prog_1);
    gdk_threads_add_timeout(SLEEP_BAR, G_SOURCE_FUNC(handler_bar_2_update), (gpointer)widg.bar_prog_2);
    gdk_threads_add_timeout(SLEEP_BAR, G_SOURCE_FUNC(handler_bar_3_update), (gpointer)widg.bar_prog_3);
    gdk_threads_add_timeout(SLEEP_BAR, G_SOURCE_FUNC(handler_bar_4_update), (gpointer)widg.bar_prog_4);
    gdk_threads_add_timeout(SLEEP_BAR, G_SOURCE_FUNC(handler_bar_5_update), (gpointer)widg.bar_prog_5);
    gdk_threads_add_timeout(SLEEP_BAR, G_SOURCE_FUNC(refresher_label_algo), (gpointer)widg.lbl_algo_key);
    gdk_threads_add_timeout(SLEEP_BAR, G_SOURCE_FUNC(refresher_label_count), (gpointer)widg.lbl_count_key);

    // Experimental
    gdk_threads_add_timeout(SLEEP_BAR, G_SOURCE_FUNC(refresher_queue_flow), widg.fbx_queue);
    g_object_unref(G_OBJECT(builder));
}

void test_color(GtkFlowBox *flowbox)
{

    g_print("%i\n", 12);
    for (int j = 0; j <= 50; j++)
        // gtk_flow_box_insert(flowbox, color_swatch_new(colors[i]), -1);
        gtk_container_add(GTK_CONTAINER(flowbox), color_swatch_new(colors[j]));
}

static gboolean
draw_color(GtkWidget *drawingarea,
           cairo_t *cr,
           const char *color_name)
{
    GdkRGBA rgba;

    if (gdk_rgba_parse(&rgba, color_name))
    {
        gdk_cairo_set_source_rgba(cr, &rgba);
        cairo_paint(cr);
    }

    return FALSE;
}

static GtkWidget *
color_swatch_new(const gchar *color)
{
    GtkWidget *button, *area;

    button = gtk_button_new();
    area = gtk_drawing_area_new();
    g_signal_connect(area, "draw", G_CALLBACK(draw_color), (gpointer)color);
    gtk_widget_set_size_request(area, 24, 24);
    gtk_container_add(GTK_CONTAINER(button), area);
    gtk_widget_show_all(button);

    return button;
}

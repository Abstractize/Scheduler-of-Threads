#include <gtk/gtk.h>
#include "./view-manager.h"

static void handler_btn_next()
{
    g_print("Provoco la burbuja\n");
}

static void handler_btn_clear()
{
    g_print("Me voy como si nada\n");
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
    //gtk_builder_connect_signals(builder, &widg);

    // Connect Signals
    g_signal_connect(widg.btn_runn, "clicked", G_CALLBACK(handler_btn_next), NULL);
    //g_signal_connect(widg.btn_clear, "clicked", G_CALLBACK(handler_btn_clear), NULL);
    //gtk_progress_bar_pulse(widg.bar_prog_1);
    // Start Refreshers
    gdk_threads_add_timeout(1000, &handler_bar_update, &widg);

    g_object_unref(G_OBJECT(builder));
}

static void handler_bar_update(widgets *widg)
{
    gtk_progress_bar_pulse(widg->bar_prog_1);
}

void test_color(GtkFlowBox *flowbox)
{
    gint i;
    const gchar *colors[] = {
        "AliceBlue",
        "AntiqueWhite",
        "AntiqueWhite1",
        "AntiqueWhite2",
        "AntiqueWhite3",
        "AntiqueWhite4",
        "aqua",
        "aquamarine",
        "aquamarine1",
        "aquamarine2",
        "aquamarine3",
        "aquamarine4",
        "azure",
        "azure1",
        "azure2",
        "azure3",
        "azure4",
        "beige",
        "bisque",
        "bisque1",
        "bisque2",
        "bisque3",
        "bisque4",
        "black",
        "BlanchedAlmond",
        "blue",
        "blue1",
        "blue2",
        "blue3",
        "blue4",
        "BlueViolet",
        "brown",
        "brown1",
        "brown2",
        "brown3",
        "brown4",
        "burlywood",
        "burlywood1",
        "burlywood2",
        "burlywood3",
        "burlywood4",
        "CadetBlue",
        "CadetBlue1",
        "CadetBlue2",
        "CadetBlue3",
        "CadetBlue4",
        "chartreuse",
        "chartreuse1",
        "chartreuse2",
        "chartreuse3",
        "chartreuse4",
        "chocolate",
        "chocolate1",
        "chocolate2",
        "chocolate3",
        "chocolate4",
        "coral",
        "coral1",
        "coral2",
        "coral3",
        "coral4",
        "CornflowerBlue",
        "cornsilk",
        "cornsilk1",
        "cornsilk2",
        "cornsilk3",
        "cornsilk4",
        "crimson",
        "cyan",
        "cyan1",
        "cyan2",
        "cyan3",
        "cyan4",
        "DarkBlue",
        "DarkCyan",
        "DarkGoldenrod",
        "DarkGoldenrod1",
        "DarkGoldenrod2",
        "DarkGoldenrod3",
        "DarkGoldenrod4",
        "DarkGray",
        "DarkGreen",
        "DarkGrey",
        "DarkKhaki",
        "DarkMagenta",
        "DarkOliveGreen",
        "DarkOliveGreen1",
        "DarkOliveGreen2",
        "DarkOliveGreen3",
        "DarkOliveGreen4",
        "DarkOrange",
        "DarkOrange1",
        "DarkOrange2",
        "DarkOrange3",
        "DarkOrange4",
        "DarkOrchid",
        "DarkOrchid1",
        "DarkOrchid2",
        "DarkOrchid3",
        "DarkOrchid4",
        "DarkRed",
        "DarkSalmon",
        "DarkSeaGreen",
        "DarkSeaGreen1",
        "DarkSeaGreen2",
        "DarkSeaGreen3",
        "DarkSeaGreen4",
        "DarkSlateBlue",
        "DarkSlateGray",
        "DarkSlateGray1",
        "DarkSlateGray2",
        "DarkSlateGray3",
        "DarkSlateGray4",
        "DarkSlateGrey",
        "DarkTurquoise",
        "DarkViolet",
        "DeepPink",
        "DeepPink1",
        "DeepPink2",
        "DeepPink3",
        "DeepPink4",
        "DeepSkyBlue",
        "DeepSkyBlue1",
        "DeepSkyBlue2",
        "DeepSkyBlue3",
        "DeepSkyBlue4",
        "DimGray",
        "DimGrey",
        "DodgerBlue",
        "DodgerBlue1",
        "DodgerBlue2",
        "DodgerBlue3",
        "DodgerBlue4",
        "firebrick",
        "firebrick1",
        "firebrick2",
        "firebrick3",
        "firebrick4",
        "FloralWhite",
        "ForestGreen",
        "fuchsia",
        "gainsboro",
        "GhostWhite",
        "gold",
        "gold1",
        "gold2",
        "gold3",
        "gold4",
        "goldenrod",
        "goldenrod1",
        "goldenrod2",
        "goldenrod3",
        "goldenrod4",
        "gray",
        "gray0",
        "gray1",
        "gray10",
        "gray100",
        "gray11",
        "gray12",
        "gray13",
        "gray14",
        "gray15",
        "gray16",
        "gray17",
        "gray18",
        "gray19",
        "gray2",
        "gray20",
        "gray21",
        "gray22",
        "gray23",
        "gray24",
        "gray25",
        "gray26",
        "gray27",
        "gray28",
        "gray29",
        "gray3",
        "gray30",
        "gray31",
        "gray32",
        "gray33",
        "gray34",
        "gray35",
        "gray36",
        "gray37",
        "gray38",
        "gray39",
        "gray4",
        "gray40",
        "gray41",
        "gray42",
        "gray43",
        "gray44",
        "gray45",
        "gray46",
        "gray47",
        "gray48",
        "gray49",
        "gray5",
        "gray50",
        "gray51",
        "gray52",
        "gray53",
        "gray54",
        "gray55",
        "gray56",
        "gray57",
        "gray58",
        "gray59",
        "gray6",
        "gray60",
        "gray61",
        "gray62",
        "gray63",
        "gray64",
        "gray65",
        "gray66",
        "gray67",
        "gray68",
        "gray69",
        "gray7",
        "gray70",
        "gray71",
        "gray72",
        "gray73",
        "gray74",
        "gray75",
        "gray76",
        "gray77",
        "gray78",
        "gray79",
        "gray8",
        "gray80",
        "gray81",
        "gray82",
        "gray83",
        "gray84",
        "gray85",
        "gray86",
        "gray87",
        "gray88",
        "gray89",
        "gray9",
        "gray90",
        "gray91",
        "gray92",
        "gray93",
        "gray94",
        "gray95",
        "gray96",
        "gray97",
        "gray98",
        "gray99",
        "green",
        "green1",
        "green2",
        "green3",
        "green4",
        "GreenYellow",
        "grey",
        "grey0",
        "grey1",
        "grey10",
        "grey100",
        "grey11",
        "grey12",
        "grey13",
        "grey14",
        "grey15",
        "grey16",
        "grey17",
        "grey18",
        "grey19",
        "grey2",
        "grey20",
        "grey21",
        "grey22",
        "grey23",
        "grey24",
        "grey25",
        "grey26",
        "grey27",
        "grey28",
        "grey29",
        "grey3",
        "grey30",
        "grey31",
        "grey32",
        "grey33",
        "grey34",
        "grey35",
        "grey36",
        "grey37",
        "grey38",
        "grey39",
        "grey4",
        "grey40",
        "grey41",
        "grey42",
        "grey43",
        "grey44",
        "grey45",
        "grey46",
        "grey47",
        "grey48",
        "grey49",
        "grey5",
        "grey50",
        "grey51",
        "grey52",
        "grey53",
        "grey54",
        "grey55",
        "grey56",
        "grey57",
        "grey58",
        "grey59",
        "grey6",
        "grey60",
        "grey61",
        "grey62",
        "grey63",
        "grey64"};

    for (i = 0; colors[i]; i++)
        gtk_container_add(GTK_CONTAINER(flowbox), color_swatch_new(colors[i]));
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


#include <gtk/gtk.h>

#ifndef VIEW_MANAGER_HEADER_H
#define VIEW_MANAGER_HEADER_H

#define BUILD_PATH "builderx.ui"

#define FBX_QUEUE "fbx_queue"
#define FBX_TIME "fbx_time"
#define BAR_PROG_1 "bar_prog_1"
#define BAR_PROG_2 "bar_prog_2"
#define BAR_PROG_3 "bar_prog_3"
#define BAR_PROG_4 "bar_prog_4"
#define BAR_PROG_5 "bar_prog_5"
#define BTN_RUNN "btn_runn"
#define BTN_CLEAR "btn_clear"
#define LBL_ALGO "lbl_algo"
#define LBL_COUNT "lbl_count"

struct window
{
    GtkProgressBar *bar_prog_1;
    GtkProgressBar *bar_prog_2;
    GtkProgressBar *bar_prog_3;
    GtkProgressBar *bar_prog_4;
    GtkProgressBar *bar_prog_5;
    GtkButton *btn_runn;
    GtkButton *btn_clear;
    GtkLabel *lbl_algo_key;
    GtkLabel *lbl_count_key;
    GtkFlowBox *fbx_queue;
    GtkFlowBox *fbx_time;
};
typedef struct window widgets;

void start_gui();

static void handler_btn_next();

static void handler_btn_clear();

static void handler_bar_update(widgets *widg);

void test_color(GtkFlowBox *flowbox);

static GtkWidget *
color_swatch_new(const gchar *color);

static gboolean
draw_color(GtkWidget *drawingarea,
           cairo_t *cr,
           const char *color_name);

#endif

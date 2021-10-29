#include <gtk/gtk.h>
#include "./action-manager.h"
#include "./expo-manager.h"
#include "../data/models/vowel-list.h"

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
#define LBL_ALGO "lbl_algo_key"
#define LBL_COUNT "lbl_count_key"
#define LIMIT 100
#define QUEUE 100
#define TIMEL 200
#define SLEEP_BAR 500

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

struct information
{
    int counter;
    int current_index;
    double progress_1;
    double progress_2;
    double progress_3;
    double progress_4;
    double progress_5;
    int queue[QUEUE];
    int timel[TIMEL];
};
typedef struct information data;

void count();

void start_gui();

static void handler_btn_next();

static void handler_btn_clear();

void handler_bar_1_update(gpointer pointer);

void handler_bar_2_update(gpointer pointer);

void handler_bar_3_update(gpointer pointer);

void handler_bar_4_update(gpointer pointer);

void handler_bar_5_update(gpointer pointer);

gboolean refresher_label_algo(gpointer ptr);

gboolean refresher_label_count(gpointer ptr);

void test_color(GtkFlowBox *flowbox);

static GtkWidget *
color_swatch_new(const gchar *color);

static gboolean
draw_color(GtkWidget *drawingarea,
           cairo_t *cr,
           const char *color_name);

#endif

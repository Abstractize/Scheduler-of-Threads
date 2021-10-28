/**
 * @file main.c
 * @brief Scheduler of threads server program. Receives payloads and Schedules threads
 * @author Arturo Mora
 *
 * @date 10/21/2021
 */

#include <stdio.h>
#include <yder.h>
#include <jansson.h>
#include <ulfius.h>
#include <gtk/gtk.h>
#include "./api/routes/routes.h"
#include "./managers/scheduler-manager.h"
#include "./managers/view-manager.h"
#include "./managers/listener-manager.h"

#define PORT 5000
#define QUANTUM 1
#define FLAG_GUI "-nel"
#define FLAG_QUA "-q"

int main(int argc, char *argv[])
{
	char str[500];
	int quantum;

	if (argc < 3) // no quantum were passed
	{
		quantum = QUANTUM;
	}
	else
	{
		quantum = atoi(argv[2]);
	}

	if (strcmp(FLAG_GUI, argv[3]) == 0) // no gui mode
	{
		pthread_t t0;
		if (pthread_create(&t0, NULL, &start_listener, NULL) == -1)
		{
			printf("[!] Cannot create thread\n");
		}
	}
	else
	{
		GtkBuilder *builder;
		GObject *window;
		GtkProgressBar *bar_prog_1, *bar_prog_2, *bar_prog_3, *bar_prog_4, *bar_prog_5;
		GtkFlowBox *fbx_queue, *fbx_time;
		GError *error = NULL;

		pthread_t t0;
		if (pthread_create(&t0, NULL, &start_listener, NULL) == -1)
		{
			printf("[!] Cannot create thread\n");
		}
		gtk_init(&argc, &argv);
		/* Construct a GtkBuilder instance and load our UI description */
		// gtk_progress_bar_set_fraction(bar_prog_3, 0.9);
		builder = gtk_builder_new_from_file("builderx.ui");
		bar_prog_1 = GTK_PROGRESS_BAR(gtk_builder_get_object(builder, BAR_PROG_1));
		bar_prog_2 = GTK_PROGRESS_BAR(gtk_builder_get_object(builder, BAR_PROG_2));
		bar_prog_3 = GTK_PROGRESS_BAR(gtk_builder_get_object(builder, BAR_PROG_3));
		bar_prog_4 = GTK_PROGRESS_BAR(gtk_builder_get_object(builder, BAR_PROG_4));
		bar_prog_5 = GTK_PROGRESS_BAR(gtk_builder_get_object(builder, BAR_PROG_5));
		fbx_queue = GTK_FLOW_BOX(gtk_builder_get_object(builder, FBX_QUEUE));
		fbx_time = GTK_FLOW_BOX(gtk_builder_get_object(builder, FBX_TIME));
		test_color(fbx_queue);
		test_color(fbx_time);
	}

	// Run GTK
	gtk_main();
	return 0;
}
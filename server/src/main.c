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
#include "./managers/action-manager.h"
#include "./managers/expo-manager.h"
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

		pthread_t t0;
		if (pthread_create(&t0, NULL, &start_listener, NULL) == -1)
		{
			printf("[!] Cannot create thread\n");
		}

		gtk_init(&argc, &argv);
		/* Construct a GtkBuilder instance and load our UI description */
		start_gui();
	}

	// Run GTK
	gtk_main();
	return 0;
}
/**
 * @file main.c
 * @brief Scheduler of threads server program. Receives payloads and Schedules threads
 * @author Arturo Mora
 *
 * @date 10/21/2021
 */

#include <stdio.h>
#include <stdlib.h>
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
#include "./data/accessors/quantum-accessor.h"

#include "./data/models/quantum.h"

#define PORT 5000
#define QUANTUM 1
#define FLAG_GUI "-nel"
#define FLAG_QUA "-q"

int main(int argc, char *argv[])
{
	char str[500];

	if (argc < 3) // no quantum were passed
	{
		set_quantum(QUANTUM);
	}
	else
	{
		int value = atoi(argv[2]);
		set_quantum(value);
		
	}
	
	const int new_value = get_quantum();
	//printf("%i\n", new_value);

	if (argc > 3 && strcmp(FLAG_GUI, argv[3]) == 0) // no gui mode
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
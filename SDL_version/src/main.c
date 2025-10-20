#include "monitor/monitor.h"
#include "monitor/display_core.h"
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[], char **envp)
{
	if (monitor_init())	printf("ERROR\n");
	clear_screen(false);
	print_m("HELLO WORLD.");
	char buffer[256] = {'\0'};
	for (int i = 0; i < 58; i++)
	{
		Printf(buffer, "%d\n", i);
	}
	Printf(buffer, "hello.");
	sleep(1);
	monitor_destroy();
	return 0;
}

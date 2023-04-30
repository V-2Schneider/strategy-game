#ifndef LOGGER_FILE
#define LOGGER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEVERITY_INFO 1
#define SEVERITY_DEBUG 2
#define SEVERITY_ERROR 3
/*
struct Logger {
	int global_severity;
	void (*log_message)(Logger *);
};
*/
void log_message(char* message, int severity, int global_severity);


#endif

#ifndef LOGGER_FILE
#define LOGGER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define SEVERITY_INFO 1
#define SEVERITY_DEBUG 2
#define SEVERITY_ERROR 3

#define GLOBAL_SEVERITY 1
/*
struct Logger {
	int global_severity;
	void (*log_message)(Logger *);
};
*/
void log_message(char* message, int severity);

//struct Logger set_up_logging(int global_severity);
#endif

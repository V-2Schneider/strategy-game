#include "logger.h"



void log_message(char* message, int severity, int global_severity){
	if (global_severity < severity){
		return;
	}

	time_t t = time(NULL);
    	struct tm *time_struct = localtime(&t);
    	char s[64];
    	size_t ret = strftime(s, sizeof(s), "%c", time_struct);

	FILE *fptr;

	fptr = fopen("./game.log", "a");
	fprintf(fptr,"[%s][pid:%d]:%s\n",s, getpid(), message);
	fclose(fptr);
}



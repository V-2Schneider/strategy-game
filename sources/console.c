#include "console.h"


void writeToConsole(char message[], bool waitForInput){
	printf("%s\n", message);
	if (waitForInput)
	{
		printf("Press enter to continue.\n");
		while( getchar() != '\n' );
	}
}

void writeToConsoleBasic(char message[]){
	writeToConsole(message, false);
}

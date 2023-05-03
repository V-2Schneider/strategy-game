#include "console.h"


void WriteToConsole(char message[], bool waitForInput)
{
	printf("%s\n", message);
	if (waitForInput)
	{
		printf("Press enter to continue.\n");
		while( getchar() != '\n' );
	}
}

void WriteToConsoleBasic(char message[])
{
	WriteToConsole(message, false);
}

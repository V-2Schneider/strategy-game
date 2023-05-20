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

void ReadMessageFromFile(char messageID[], char **buffer){
	FILE *messages;
	messages = fopen("../messages.txt", "r");

	while(fgets(*buffer, BUFFER_LENGTH, messages)){
		if (strncmp(messageID, *buffer, MESSAGE_ID_LENGTH) == 0){
			*buffer+=MESSAGE_ID_LENGTH;
			break;
		}
	}
	
}

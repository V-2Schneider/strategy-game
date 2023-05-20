#ifndef CONSOLE_FILE
#define CONSOLE_FILE

#include <stdio.h> 
#include <stdbool.h>
#include <string.h>

#define MESSAGE_ID_LENGTH 5
#define BUFFER_LENGTH 100

void WriteToConsole(char message[], bool waitForInput);

void WriteToConsoleBasic(char message[]);

void ReadMessageFromFile(char messageID[], char **buffer);
#endif

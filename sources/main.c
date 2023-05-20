#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "resources.h"
#include "logger.h"
#include "console.h"

void MainLoop()
{

	int fd[2], nbytes;
	pipe(fd);
	char buffer[80];
	if (fork() == 0) // this is a child process that sets up production of materials
	{
		close(fd[0]);
		LogMessage("This is the child process", SEVERITY_INFO);
		SetAllResources();
		sleep(10);
		exit(0);
		
	} else 
	{
		close(fd[1]);
		printf("\n");
		LogMessage("This is the parent process", SEVERITY_INFO);
		WriteToConsole("Test message", true);
		while(true){
			// do nothing right now
		}
	}
}

int main(int argc, char* argv[])
{
	char buffer[BUFFER_LENGTH];	
	ReadMessageFromFile("00000", &buffer);
	//WriteToConsoleBasic(buffer);
	MainLoop();

	return 0;
}

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "resources.h"
#include "logger.h"


void forkExample()
{

	int fd[2], nbytes;
	pipe(fd);
	char buffer[80];
	int currentRateWood = 10;
	//struct Logger logger;
	int global_severity = 1;
	if (fork() == 0)
	{
		close(fd[0]);
		log_message("This is the child process", SEVERITY_INFO);
		struct Resource wood;
		strcpy(wood.resourceName, "wood");
		wood.resourceRate = 5;
		produceAndSaveResource(&wood);
		struct Resource stone;
		strcpy(stone.resourceName, "stone");
		stone.resourceRate = 1;
		produceAndSaveResource(&stone);
		struct Resource wheat;
		strcpy(wheat.resourceName, "wheat");
		wheat.resourceRate = 7;
		produceAndSaveResource(&wheat);
		sleep(10);
		exit(0);
		
	} else 
	{
		close(fd[1]);
		printf("\n");
		log_message("This is the parent process", SEVERITY_INFO);
		while(true){
			// do nothing right now
		}
	}
}

int main(int argc, char* argv[])
{

	forkExample();

	return 0;
}

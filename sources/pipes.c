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
	char string[]= "kraaa!\n";
	char buffer[80];
	int currentRateWood = 10;
	//struct Logger logger;
	int global_severity = 1;
	if (fork() == 0)
	{
		close(fd[0]);
		printf("Oy, this is the mining process!\n");
		log_message("Everything is alright", SEVERITY_INFO, global_severity);
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
		write(fd[1], string, (strlen(string)+1));
		exit(0);
		
	} else 
	{
		close(fd[1]);
		printf("This is the parent process\n");
		log_message("Everything is alright in the parent process too", SEVERITY_INFO, global_severity);
		nbytes = read(fd[0], buffer, sizeof(buffer));
		printf("Read string %s", buffer);
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

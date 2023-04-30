#include "resources.h"


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void produceResource(int resourceRate, int fd_resource_write)
{
	while(true)
	{
		sleep(10);
		int resource = resourceRate * NORMAL_RATE;
		char resource_str[20];
		sprintf(resource_str, "%d", resource);
		write(fd_resource_write, resource_str, (sizeof(resource_str) + 1)); 
	}
}

void produceAndSaveResource(struct Resource *resource)
{
	
	char resources[80];
	int fd_resource[2];
	pipe(fd_resource);
	if (fork() == 0)
	{
		close(fd_resource[0]);
		produceResource(resource->resourceRate, fd_resource[1]);
	} else {
		close(fd_resource[1]);
		if (fork() == 0)
		{

			while(true){
				char buffer_resource[80];
				read(fd_resource[0], buffer_resource, sizeof(buffer_resource));
				printf("We have produced %s %s.\n", buffer_resource, resource->resourceName);
			}
		} 
		
	}
}

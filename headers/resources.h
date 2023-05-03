#ifndef RESOURCES_FILE
#define RESOURCES_FILE


#define NORMAL_RATE 10;

struct Resource 
{
	int resourceRate;
	char resourceName[20];
	int resourceAmount;
};


void ProduceResource(int resourceRate, int fd_resource_write);

void ProduceAndSaveResource(struct Resource *resource);

void SetAllResources();

#endif

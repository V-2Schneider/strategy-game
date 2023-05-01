#ifndef RESOURCES_FILE
#define RESOURCES_FILE


#define NORMAL_RATE 10;

struct Resource {
	int resourceRate;
	char resourceName[20];
	int resourceAmount;
};


void produceResource(int resourceRate, int fd_resource_write);

void produceAndSaveResource(struct Resource *resource);

void setAllResources();

#endif

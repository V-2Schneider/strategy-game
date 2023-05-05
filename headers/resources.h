#ifndef RESOURCES_FILE
#define RESOURCES_FILE


#define NORMAL_RATE 10;
typedef char RES_NAME[20];

struct Resource 
{
	int resourceRate;
	RES_NAME resourceName;
	int resourceAmount;
};


void ProduceResource(int resourceRate, int fd_resource_write);

void ProduceAndSaveResource(struct Resource *resource);

void SetAllResources();

#endif

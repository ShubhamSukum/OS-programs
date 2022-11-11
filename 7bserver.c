#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#include<string.h>
#include<stdlib.h>

int main()
{
	key_t key=ftok(".",38);
	printf("Key: -%d\n",key);
	
	int shmid=shmget(key,1024,0666|IPC_CREAT);
	printf("ID:%d\n",shmid);
	
	char *str=(char *)shmat(shmid,NULL,0);
	printf("Enter the data you want to share from server to client: -\n");
	fgets(str,1024,stdin);
	printf("\nShared Data: -%s",str);
	
	shmdt(str);
	return 0;
}

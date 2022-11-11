#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>

#include<stdlib.h>
#include<string.h>

int main()
{
	key_t key=ftok(".",38);
	printf("key: -%d",key);
	
	int shmid=shmget(key,1024,0666|IPC_CREAT);
	printf("\nID: -%d\n",shmid);
	
	char *str=shmat(shmid,NULL,0);
	printf("Data recieved from Server: -%s\n",str);
	
	shmdt(str);	// de takun
	
	shmctl(shmid,IPC_RMID,NULL);	// destory shared memory
	return 0;
}

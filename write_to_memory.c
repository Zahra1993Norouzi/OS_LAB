#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <stdlib.h>

int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    char *str = (char*) shmat(shmid, NULL, 0); 
    strcpy(str, "Hello, this is shared memory!");  

    printf("Data written to memory: %s\n", str);

    shmdt(str);  
    return 0;
}

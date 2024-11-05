#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    key_t key = ftok("shmfile", 65);  
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);  

    if (shmid == -1) {
        perror("Error creating shared memory segment");
        exit(1);
    }

    printf("Shared memory segment created with ID: %d\n", shmid);
    return 0;
}
